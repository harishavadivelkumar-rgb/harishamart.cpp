const productsNode = document.querySelector("#products");
const statusNode = document.querySelector("#status");
const searchNode = document.querySelector("#search");
let products = [];

function safeText(value) {
  const span = document.createElement("span");
  span.textContent = String(value ?? "");
  return span.innerHTML;
}
function renderProducts() {
  const query = searchNode.value.trim().toLowerCase();
  const shown = products.filter(p =>
    `${p.name} ${p.category} ${p.description}`.toLowerCase().includes(query));
  productsNode.innerHTML = shown.length ? shown.map(p => `
    <article class="product">
      <div class="emoji">📦</div>
      <h3>${safeText(p.name)}</h3>
      <span class="pill">${safeText(p.category || "General")}</span>
      <p>${safeText(p.description || "No description yet.")}</p>
      <div class="price">₹${Number(p.price).toFixed(2)}</div>
      <small class="muted">Stock: ${Number(p.stock)}</small>
    </article>`).join("") : `<p class="muted">No products yet. Add your first product below.</p>`;
}
async function loadProducts() {
  try {
    const response = await fetch("/api/v1/products");
    if (!response.ok) throw new Error("Backend returned " + response.status);
    const result = await response.json();
    if (!result.success) throw new Error(result.error?.message || "Could not load products");
    products = result.data;
    statusNode.textContent = `${products.length} product(s) loaded from SQLite database.`;
    renderProducts();
  } catch (error) {
    statusNode.textContent = "Cannot connect to backend. Start HarishaMart from VS Code and refresh.";
    productsNode.innerHTML = "";
  }
}
searchNode.addEventListener("input", renderProducts);
document.querySelector("#product-form").addEventListener("submit", async event => {
  event.preventDefault();
  const form = new FormData(event.currentTarget);
  const payload = {
    name: form.get("name").trim(),
    price: Number(form.get("price")),
    stock: Number(form.get("stock")),
    category: form.get("category").trim() || "General",
    description: form.get("description").trim()
  };
  try {
    const response = await fetch("/api/v1/products", {
      method: "POST", headers: {"Content-Type":"application/json"},
      body: JSON.stringify(payload)
    });
    const result = await response.json();
    if (!response.ok || !result.success) throw new Error(result.error?.message || "Could not save product");
    event.currentTarget.reset();
    await loadProducts();
    statusNode.textContent = "Product saved successfully to the database.";
  } catch (error) {
    statusNode.textContent = error.message + " — check that the backend is running.";
  }
});
loadProducts();
