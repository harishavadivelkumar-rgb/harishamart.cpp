# HarishaMart — C++ Marketplace MVP

This is a starter MVP: C++20 + Drogon HTTP backend, SQLite database, and HTML/CSS/JS frontend.
It is a one-day starting point, **not** the complete 19-page capstone specification. It currently demonstrates product listing and adding products. Authentication, cart, checkout/orders, seller/admin roles, reviews, chatbot, automated tests and deployment must be added before claiming the full PDF requirements are complete.

## Requirements
- VS Code
- Git
- C++ compiler (GCC 12+ / Clang 15+)
- CMake 3.25+
- vcpkg
- Internet for first dependency installation

## Run (Linux / Ubuntu / WSL)
1. Install compiler tools: `sudo apt update && sudo apt install build-essential cmake git curl zip unzip tar pkg-config`
2. Install vcpkg using the official instructions: https://github.com/microsoft/vcpkg
3. From this project folder:
   `cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`
4. Build: `cmake --build build`
5. Run: `./build/HarishaMart`
6. Open `http://localhost:8080`

Replace `/path/to/vcpkg` with your actual vcpkg folder path. On Windows, use a Developer PowerShell/terminal with a working C++ toolchain and follow the official vcpkg setup.

## API
- `GET /api/v1/health`
- `GET /api/v1/products`
- `POST /api/v1/products` with JSON `{ "name":"Notebook", "description":"A5 ruled", "price":45.00, "stock":20, "category":"Stationery" }`

The database file `harishamart.db` is created in the project directory and persists between runs.
