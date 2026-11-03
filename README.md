# cc-103-eatery-system

A console-based Point of Sale (POS) and CRUD ordering system built in **C++** as part of an academic data structures project.

## Features
* **Create Orders:** Select from a preset menu, input quantities, and auto-calculate totals.
* **File Handling:** Persists order records dynamically using local text-based file streams (`orderlist.txt`).
* **Custom String Formatting:** Automatically sanitizes and formats inputs (e.g., replacing spaces with underscores for file structure stability).

## Technologies Used
* C++ (Standard Template Library, File Streams, Vectors, Structs)

## How to Run
1. Make sure you have a C++ compiler installed (like MinGW/GCC or Dev-C++).
2. Compile the source code file:
   ```bash
   g++ casestudy103.cxx -o cc-103-eatery-system
