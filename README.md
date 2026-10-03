# Data Structures Lab

A collection of lab assignments, programming tasks, and practical implementations for the **Data Structures** course in the **BS Data Science** program at **Air University, Islamabad, Pakistan**.

All implementations in this repository are written in **C++** as part of my university coursework and practical lab work.

---

## About

This repository contains programming tasks completed during Data Structures lab sessions. It focuses on implementing fundamental data structures and applying them to practical programming problems.

The repository currently covers:

* Arrays
* Multidimensional arrays
* Searching
* Singly linked lists
* Doubly linked lists
* Pointers and dynamic memory
* Practical data-structure-based applications

Each lab is organized into a separate directory, with individual `.cpp` source files for each task.

---

## Repository Structure

```text
data_structure_lab/
│
├── Lab_02_array/
│   ├── Task_01.cpp
│   ├── Task_02.1.cpp
│   ├── Task_03.1.cpp
│   └── ...
│
├── Lab_03/
│   ├── Task1_StudentMarks.cpp
│   ├── Task2_ParkingManagement.cpp
│   ├── Task3_MatrixOutput.cpp
│   ├── Task4_HospitalBedManagement.cpp
│   ├── Task5_ComputerLabManagement.cpp
│   └── Task6_3DArraySearch.cpp
│
├── Lab_04_LinkList/
│   ├── Task1_Student_Registration.cpp
│   ├── Task2_Hospital_Patient_Queue.cpp
│   └── Task3_Online_Shopping_Cart.cpp
│
├── Lab_05_Doubly_LinkedList/
│   ├── Task1_Browser_History.cpp
│   ├── Task2_Image_Gallery.cpp
│   ├── Task3_Game_Player_Turns.cpp
│   └── Task4_Music_Playlist.cpp
│
└── README.md
```

> **Note:** The repository structure may be updated as new Data Structures lab assignments are completed.

---

## Labs Overview

### Lab 02 — Arrays

This lab focuses on fundamental operations and problem-solving using arrays.

Topics include:

* Array traversal
* Insertion
* Deletion
* Updating elements
* Searching
* Basic array manipulation

---

### Lab 03 — Multidimensional Arrays & Applications

This lab applies arrays and multidimensional arrays to practical programming scenarios.

Tasks include:

* Student Marks Management
* Parking Management
* Matrix Output
* Hospital Bed Management
* Computer Lab Management
* 3D Array Searching

These tasks demonstrate how arrays can be used to represent and process structured data.

---

### Lab 04 — Singly Linked Lists

This lab introduces dynamic data structures using singly linked lists.

Tasks include:

* Student Registration System
* Hospital Patient Queue
* Online Shopping Cart

Concepts practiced include:

* Nodes
* Pointers
* `head` pointer
* Dynamic memory allocation
* Node insertion
* Traversal
* Searching
* Deletion
* Memory deallocation

---

### Lab 05 — Doubly Linked Lists

This lab introduces doubly linked lists, where each node maintains links to both the previous and next nodes.

Tasks include:

* Browser History
* Image Gallery
* Game Player Turns
* Music Playlist

Concepts practiced include:

* Doubly linked-list nodes
* `prev` and `next` pointers
* Forward traversal
* Backward traversal
* Insertion
* Deletion
* Dynamic memory allocation
* Practical applications of doubly linked lists

---

## Concepts Practiced

### Arrays

* Array declaration and initialization
* Traversal
* Insertion
* Deletion
* Updating
* Searching
* Processing array elements

### Multidimensional Arrays

* 2D arrays
* 3D arrays
* Matrix operations
* Searching multidimensional data
* Representing structured information

### Searching

* Searching for elements in arrays
* Searching through structured data
* Applying searching techniques to practical problems

### Singly Linked Lists

* Nodes
* Pointers
* `head`
* `next`
* Dynamic memory allocation
* Insertion
* Traversal
* Searching
* Deletion
* Destructors and memory cleanup

### Doubly Linked Lists

* Nodes with `prev` and `next`
* Forward traversal
* Backward traversal
* Insertion
* Deletion
* Dynamic memory management
* Real-world applications

### C++ Programming

* Variables and data types
* Conditional statements
* Loops
* Functions
* Arrays
* Pointers
* Structures/classes where applicable
* Dynamic memory allocation
* `new` and `delete`
* Problem-solving

---

## Practical Applications

The assignments demonstrate how data structures can be applied to practical scenarios, including:

* Student record management
* Student marks management
* Hospital bed management
* Hospital patient management
* Parking management
* Computer lab management
* Online shopping carts
* Browser history
* Image galleries
* Game player turns
* Music playlists

These applications help connect theoretical data-structure concepts with real programming problems.

---

## How to Compile and Run

Each `.cpp` file contains an individual C++ program and can be compiled and executed independently.

### Prerequisites

Before running the programs, make sure you have:

* A C++ compiler such as **G++**
* Visual Studio Code or another C++ development environment
* Basic knowledge of using the terminal or PowerShell

---

## Compile and Run on Windows

### Lab 02

For example:

```powershell
g++ Lab_02_array/Task_01.cpp -o task01.exe
.\task01.exe
```

### Lab 03

For example:

```powershell
g++ Lab_03/Task1_StudentMarks.cpp -o task.exe
.\task.exe
```

### Lab 04 — Singly Linked List

For example:

```powershell
g++ Lab_04_LinkList/Task1_Student_Registration.cpp -o task.exe
.\task.exe
```

### Lab 05 — Doubly Linked List

For example:

```powershell
g++ Lab_05_Doubly_LinkedList/Task1_Browser_History.cpp -o task.exe
.\task.exe
```

> Replace the source filename with the `.cpp` file you want to compile and execute.

---

## Compiling with a Specific C++ Standard

You can also specify a C++ standard when compiling:

```powershell
g++ -std=c++17 Lab_04_LinkList/Task1_Student_Registration.cpp -o task.exe
.\task.exe
```

The same approach can be used for other lab files.

---

## Learning Objectives

The main objectives of this lab repository are to:

* Understand the fundamentals of data structures.
* Implement arrays and multidimensional arrays in C++.
* Understand and implement singly linked lists.
* Understand and implement doubly linked lists.
* Learn how pointers are used in dynamic data structures.
* Practice dynamic memory allocation and deallocation.
* Develop logical thinking and problem-solving skills.
* Apply data structures to practical, real-world scenarios.
* Strengthen C++ programming skills through hands-on laboratory work.
* Connect theoretical concepts with practical implementations.

---

## Technologies Used

* **Programming Language:** C++
* **Compiler:** G++ / GCC
* **Development Environment:** Visual Studio Code
* **Version Control:** Git
* **Repository Hosting:** GitHub

---

## Project Status

This repository is **actively maintained** as part of my ongoing Data Structures coursework.

| Lab    | Topic                                  | Status                  |
| ------ | -------------------------------------- | ----------------------- |
| Lab 02 | Arrays                                 | Completed / In Progress |
| Lab 03 | Multidimensional Arrays & Applications | Completed               |
| Lab 04 | Singly Linked Lists                    | Completed               |
| Lab 05 | Doubly Linked Lists                    | Completed / In Progress |

> The status may be updated as additional assignments are completed.

---

## Future Additions

As the Data Structures course progresses, this repository may include additional implementations covering topics such as:

* More linked-list operations
* Additional searching techniques
* Stacks
* Queues
* Trees
* Binary Search Trees
* Heaps
* Sorting algorithms
* Other data-structure-based applications

---

## Educational Purpose

This repository is maintained for **educational purposes** as part of my university coursework at Air University.

The programs are intended to demonstrate my learning and practical implementation of Data Structures concepts in C++.

---

## Author

**Muhammad Bilal**

BS Data Science
Air University, Islamabad, Pakistan

---

## Acknowledgment

This repository contains work completed as part of the **Data Structures laboratory coursework** at Air University.

It is intended to document my learning journey, practical implementations, and progress in understanding data structures and algorithms using C++.

---

## License

This project is intended primarily for **educational and academic purposes**.

If you use any part of this repository for learning, please use it responsibly and understand the implementation rather than submitting it directly as your own academic work.

---

**More lab assignments and implementations will be added as the course progresses.**