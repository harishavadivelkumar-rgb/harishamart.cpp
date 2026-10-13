# HarishaMart --- Online Shopping Marketplace

**Live Website:**
https://harisha-mart-frontend--harishavadivelk.replit.app/

## 1. Project Overview

HarishaMart is an online shopping marketplace project designed to
provide a convenient interface for browsing products and exploring an
e-commerce shopping experience. This project is being developed as an
academic capstone project.

The live link above opens the deployed frontend. Backend services,
database persistence, and individual feature behaviour should be
verified separately before describing them as fully implemented.

## 2. Objectives

-   Provide a clear and user-friendly online shopping interface.
-   Organize product information for easy browsing.
-   Create a foundation for connecting the frontend to backend APIs.
-   Plan for persistent storage of product, user, cart, and order data.
-   Prepare the project for future testing, documentation, and
    deployment improvements.

## 3. Project Link

-   **Live Demo:**
    https://harisha-mart-frontend--harishavadivelk.replit.app/

## 4. Technology Stack

The live URL is a deployed frontend. Confirm the exact technologies in
the source code before final submission.

  -----------------------------------------------------------------------
  Layer                               Technology / Status
  ----------------------------------- -----------------------------------
  Frontend                            Verify from project source (HTML,
                                      CSS, JavaScript or framework)

  Backend                             Verify implementation and API
                                      endpoints

  Database                            Verify configured database and
                                      persistence

  Development environment             Visual Studio Code / Replit

  Version control                     Git and GitHub
  -----------------------------------------------------------------------

> **Important:** Do not list C++/Drogon, PostgreSQL, SQLite, or any
> other technology as implemented unless it is actually present and
> working in your submitted source code.

## 5. Main Functional Areas

The intended marketplace scope includes:

-   Product browsing and search
-   Product details
-   Shopping cart
-   User registration and login
-   Checkout with mock payment confirmation
-   Order history
-   Seller product management
-   Admin management
-   Product reviews and star ratings
-   Shopping FAQ chatbot for the final review

Mark each item as completed only after testing it in the deployed
application. If a feature is not yet implemented, list it under **Future
Enhancements** instead.

## 6. System Architecture

The planned full-stack architecture is:

1.  **Frontend:** Displays pages and collects user actions.
2.  **Backend API:** Validates requests and applies application rules.
3.  **Database:** Stores records persistently.
4.  **API integration:** The frontend sends HTTP requests to backend
    endpoints and displays the responses.

A live frontend URL alone does not prove that the backend and database
are connected. Verify the integration with real API requests and confirm
that records persist after restarting the application.

## 7. Database Design (Planned)

For the complete marketplace, the database may include these tables:

-   `users` --- account details and roles
-   `products` --- product information, seller, price, and stock
-   `cart_items` --- products added to a buyer's cart
-   `orders` --- order details and status
-   `order_items` --- products and quantities within an order
-   `reviews` --- ratings and comments

Use primary keys, foreign keys, unique email constraints, input
validation, and parameterized SQL queries. Store monetary amounts as
integer minor units rather than floating-point currency values.

## 8. Security Considerations

-   Never store plain-text passwords.
-   Hash passwords using a suitable password-hashing algorithm.
-   Validate all data on the server.
-   Use parameterized database queries.
-   Enforce role-based permissions for buyer, seller, and admin actions.
-   Keep API keys and database credentials out of frontend code and
    GitHub.
-   Use HTTPS for the deployed application.

## 9. Testing Checklist

Before final review, test and record the results:

-   [ ] Live website opens successfully.
-   [ ] Product listing and search work as expected.
-   [ ] Product data comes from the intended backend API.
-   [ ] Adding or changing data persists in the database.
-   [ ] Registration and login validation work, if implemented.
-   [ ] Cart totals and checkout flow work, if implemented.
-   [ ] Order history and role permissions work, if implemented.
-   [ ] Reviews and chatbot work, if implemented.
-   [ ] Invalid inputs show clear errors.
-   [ ] No secrets or credentials are committed to GitHub.

## 10. How to Run Locally

1.  Clone the GitHub repository.
2.  Open the project folder in Visual Studio Code.
3.  Read the installation instructions in the project files.
4.  Install the required runtime, dependencies, and database.
5.  Configure local environment variables using an example configuration
    file.
6.  Start the backend and frontend using the commands specified by the
    actual project.
7.  Open the local URL shown by the development server.
8.  Test the API and database connection.

> Add the exact install and run commands after confirming the
> repository's actual framework and scripts.

## 11. Deployment

**Live frontend:**
https://harisha-mart-frontend--harishavadivelk.replit.app/

The deployed site should be tested during the final review. Confirm that
the required backend endpoints are available, database data persists,
and the website works from a fresh browser session.

## 12. Future Enhancements

-   Complete and verify backend/database integration.
-   Implement secure user authentication and role permissions.
-   Complete cart, checkout, and order management.
-   Add seller and admin dashboards.
-   Add product reviews and ratings.
-   Integrate the shopping FAQ chatbot.
-   Add automated tests and continuous integration.
-   Improve accessibility, responsiveness, logging, and error handling.

## 13. Conclusion

HarishaMart is an e-commerce marketplace project intended to make online
product browsing and shopping more convenient. The live frontend
provides a demo entry point. The final submission should include the
verified source code, backend and database setup, test results, and an
accurate list of completed features.

------------------------------------------------------------------------

**Project Name:** HarishaMart\
**Project Type:** E-Commerce Marketplace\
**Live Demo:**
https://harisha-mart-frontend--harishavadivelk.replit.app/
