# StringPlus

StringPlus is a custom C library that provides implementations of core string manipulation functions, along with additional utilities and unit tests.

The project focuses on low-level string processing, manual memory management, and careful handling of edge cases.

---

## 📌 About the Project

This library reimplements a subset of standard C string functions and extends them with additional functionality such as formatted input/output and advanced string processing helpers.

The goal of the project is to deepen understanding of:
- how strings work internally in C,
- pointer arithmetic and memory safety,
- writing maintainable and testable low-level code.

All functionality is validated with unit tests.

---

## ✨ Features

- Custom implementations of common string functions  
- Partial implementation of `sprintf` and `sscanf`
- Additional string utilities (case conversion, trimming, insertion)
- Careful dynamic memory management
- Unit tests for correctness and stability
- Clean and modular project structure

---

## 🛠 Technologies

- **C (C11)**
- **GCC**
- **Make**
- **Check** (unit testing)
- **gcov** (code coverage)

---

## 📂 Project Structure

```
src/        # Library source code
unit_test/ # Unit tests
```

---

## 🔧 Implemented Functionality

### Core string functions
Custom implementations of common string and memory functions, including:
- `strlen`, `strcpy`, `strncmp`, `strchr`, `strstr`
- `memcpy`, `memset`, `memcmp`, `memchr`
- Tokenization and search utilities

### Formatted I/O
Partial support for:
- `sprintf`
- `sscanf`

Supported format specifiers include characters, integers, floating-point values, strings, and pointers, along with common flags, width, precision, and length modifiers.

### Additional string utilities
Extra helper functions for advanced string processing:
- Convert strings to upper/lower case
- Insert substrings at a given position
- Trim characters from the beginning and end of a string

---

## 🧪 Testing

- Unit tests compare the custom implementation against standard C library behavior where applicable
- Tests are designed to cover edge cases and error handling
- Code coverage is measured using `gcov`

---

## 🎯 Project Goals

- Strengthen low-level C programming skills
- Practice safe and explicit memory management
- Understand standard library behavior by reimplementing it
- Write clean, readable, and testable C code

---

## 🚀 Build & Run

```bash
make
make test
```

---

## 📎 Notes

This project is intended for educational and demonstrational purposes and is suitable for showcasing low-level C programming skills in a portfolio.
