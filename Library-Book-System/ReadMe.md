# Library Management System

## Overview
The **Library Management System** is a simple yet efficient system designed to manage books, members, and issued books in a library. This system allows users to add, search, issue, and return books while keeping track of library members and their borrowed books.

## Features
- **Book Management**: Add, search, and remove books from the library.
- **Member Management**: Register new members and maintain a list of active users.
- **Book Issuing & Returning**: Track books issued to members and manage their return process.
- **Efficient Record Keeping**: Maintain a record of all issued books and ensure easy retrieval of information.

## File Structure
- **`book.h`** – Defines the structure of books, including attributes like title, author, ISBN, and availability status.
- **`members.h`** – Contains member details such as name, membership ID, and issued book records.
- **`nameIssued.h`** – Keeps track of books that are currently issued, linking them to specific members.
- **`libraryBookSystem.cpp`** – The main file that integrates all components and manages the library system.

## Installation & Usage
1. **Clone the Repository**
   ```sh
   git clone https://github.com/your-repo/library-management-system.git
   cd library-management-system
   ```
2. **Compile the Program**
   ```sh
   g++ libraryBookSystem.cpp -o librarySystem
   ```
3. **Run the Program**
   ```sh
   ./librarySystem
   ```

## Future Enhancements
- Implement a **GUI version** for better user experience.
- Introduce a **database** to store book and member records permanently.
- Add **fine calculation** for overdue books.

## Contributions
Feel free to contribute to this project by submitting issues, suggesting improvements, or creating pull requests.

## Acknowledgments
This project was created as part of a learning initiative. Special thanks to my teacher for guidance and support!

---
🚀 **Happy Coding!**