# SmartIO.DSL

A lightweight C++ mini-DSL designed to make common input/output operations simpler and more beginner-friendly.
SmartIO does not change C++.
It reduces boilerplate and helps new programmers focus on understanding how programs work instead of fighting syntax.
---

## 💛 Author

**Created by Thayna Dias (me ;P).**

## ✨ Why SmartIO?

- Reduces repetitive `std::cout` and `std::cin` syntax;
- Makes code more readable;
- Beginner-friendly abstraction;
- Designed as a learning support tool.
---

## 📦 Installation
Clone the repository here: `git clone https://github.com/yourusername/SmartIO.DSL`

## 🚀 Core Functions

_input()_

Works similarly to Python’s input() function.
It can display a message and return the user’s input in a single line.
```cpp
string name = input("Enter your name: ");
```

_print()_

Simplifies the common pattern:
```cpp
std::cout << value << std::endl;
```

It also allows multiple values at once:
```cpp
print("Hello! My name is", name, "! Nice to meet you ;P");
```

## 📂 File Reading and Writing

SmartIO also includes simplified utilities for handling file operations, making it easier to read from and write to files without verbose syntax.
(More details coming soon.)
---
