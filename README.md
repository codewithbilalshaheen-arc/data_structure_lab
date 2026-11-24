# Data Structures Lab

A collection of lab assignments, programming tasks, and practical implementations for the **Data Structures** course in the **BS Data Science** program at **Air University, Islamabad, Pakistan**.

All implementations in this repository are written in **C++** as part of my university coursework and practical lab work.

---

## About

This repository contains programming tasks completed during Data Structures lab sessions. It focuses on implementing fundamental data structures and applying them to practical programming problems.

Each lab is organized into a separate directory, with individual `.cpp` source files for each task. New labs are added as the course progresses and follow the same structure.

---

## Repository Structure

```text
data_structure_lab/
|
|-- Lab_02_array/                 (Arrays - 20 task files)
|   |-- Task_01.cpp
|   |-- Task_02.1.cpp
|   |-- Task_1.2.cpp
|   `-- ...
|
|-- Lab_03/                       (Multidimensional Arrays)
|   |-- Task1_StudentMarks.cpp
|   |-- Task2_ParkingManagement.cpp
|   |-- Task3_MatrixOutput.cpp
|   |-- Task4_HospitalBedManagement.cpp
|   |-- Task5_ComputerLabManagement.cpp
|   `-- Task6_3DArraySearch.cpp
|
|-- Lab_04_LinkList/              (Singly Linked Lists)
|   |-- Task1_Student_Registration.cpp
|   |-- Task2_Hospital_Patient_Queue.cpp
|   `-- Task3_Online_Shopping_Cart.cpp
|
|-- Lab_05_Doubly_LinkedList/     (Doubly Linked Lists)
|   |-- Task_1_Browser_History.cpp
|   |-- Task _2_Image_Gallery.cpp
|   |-- Task _3_Game_Player_Turns.cpp
|   `-- Task _4_Music Playlist.cpp
|
|-- Lab_06_Stacks/                (Stacks)
|   |-- Task1_Browser_Back_History.cpp
|   |-- Task2_Undo_Text_Editor.cpp
|   |-- Task3_Hospital_Emergency_Requests.cpp
|   `-- Task4_Restaurant_Order_Processing.cpp
|
|-- Lab_07_queues/                (Queues)
|   |-- Task1_BankQueue.cpp
|   |-- Task2_PacketCircularQueue.cpp
|   |-- Task3_HospitalPriorityQueue.cpp
|   `-- Task4_TrainStationDeque.cpp
|
|-- Lab_08_Tree/                  (Trees - Part 1)
|   |-- task1_department_hierarchy.cpp
|   |-- task2_shopping_bfs.cpp
|   |-- task3_file_explorer_dfs.cpp
|   `-- task4_hospital_avl.cpp
|
|-- Lab_08_Trees/                 (Trees - Part 2)
|   |-- Task1_Staff_Management.cpp
|   `-- Task2_Hospital_Inventory.cpp
|
|-- Lab_09_Heap/                  (Heap and Heap Sort)
|   |-- Task1_StudentMeritRanking.cpp
|   |-- Task2_HospitalEmergency.cpp
|   |-- Task3_OrderHeapSort.cpp
|   `-- Task4_MedicineExpiry.cpp
|
|-- Assignment_01/                (Assignment)
|   |-- Q1_Flight_BST.cpp
|   `-- Q2_Emergency_AVL.cpp
|
|-- DS_Lab_Quiz_01/               (Lab Quiz)
|   |-- Q1_Ambulance_PriorityQueue.cpp
|   `-- Q2_AVL_Tree.cpp
|
|-- Data Structures practice/     (Extra practice programs)
|   |-- Diagonal_Matrix_to_1D.cpp
|   |-- Lower_Triangular_Matrix_to_1D.cpp
|   |-- Tri_Diagonal_Matrix_to_1D.cpp
|   |-- Sparse.cpp
|   `-- ...
|
`-- README.md
```

---

## Labs Overview

### Lab 02 - Arrays

This lab focuses on fundamental operations and problem-solving using arrays.

Topics include:

* Array traversal
* Insertion
* Deletion
* Updating elements
* Searching
* Basic array manipulation

---

### Lab 03 - Multidimensional Arrays & Applications

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

### Lab 04 - Singly Linked Lists

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

### Lab 05 - Doubly Linked Lists

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

### Lab 06 - Stacks

This lab introduces the stack data structure, which follows the **LIFO (Last In, First Out)** principle. All programs are written in C++ using OOP and cover both array-based and linked-list-based stacks.

Examples from the lab manual:

* Stack using an Array
* Stack using a Singly Linked List

Tasks include:

* Browser Back History (Array Stack)
* Undo Operation in a Text Editor (Array Stack)
* Hospital Patient Emergency Requests (Linked List Stack)
* Restaurant Order Processing (Linked List Stack)

Concepts practiced include:

* LIFO principle
* `push`, `pop`, `peek/top`, `display` and `isEmpty` operations
* Stack Overflow and Stack Underflow handling
* Displaying elements from TOP to bottom
* Fixed-size (array) vs. dynamic (linked list) implementation
* `top` index and `top` pointer
* Dynamic memory allocation and deallocation (`new` / `delete`)
* Destructors for freeing remaining nodes

---

### Lab 07 - Queues

This lab introduces the queue data structure, which follows the **FIFO (First In, First Out)** principle, along with its circular, priority and double-ended variants.

Tasks include:

* Bank Queue
* Packet Circular Queue
* Hospital Priority Queue
* Train Station Deque

Concepts practiced include:

* FIFO principle
* `enqueue`, `dequeue`, `front`, `display` and `isEmpty` operations
* Circular queue and wrap-around indexing
* Priority queue
* Double-ended queue (deque)
* Overflow and underflow handling

---

### Lab 08 - Trees

This lab introduces tree data structures and their traversal and balancing techniques. The work is split across two folders: `Lab_08_Tree` and `Lab_08_Trees`.

**`Lab_08_Tree`**

* Department Hierarchy
* Shopping (Breadth-First Search)
* File Explorer (Depth-First Search)
* Hospital AVL Tree

**`Lab_08_Trees`**

* Staff Management
* Hospital Inventory

Concepts practiced include:

* Tree nodes and pointers
* Tree hierarchy
* Breadth-First Search (BFS) / level-order traversal
* Depth-First Search (DFS)
* Binary Search Tree operations
* AVL Tree balancing and rotations

---

### Lab 09 - Heap and Heap Sort

This lab implements heaps using C++ classes, objects, binary tree nodes and pointers. Every task uses **Heapify Up** during insertion and **Heapify Down** during deletion.

Tasks include:

* University Student Merit Ranking (Max Heap)
* Hospital Emergency Management System (Max Heap)
* Online Shopping Order Sorting (Heap Sort)
* Hospital Medicine Expiry Management (Min Heap, `YYYYMMDD` dates)

Concepts practiced include:

* Complete binary tree built from linked nodes (`left`, `right`, `parent` pointers)
* Max Heap and Min Heap
* Heapify Up (insertion) and Heapify Down (deletion)
* Level Order Traversal using a queue
* Deleting the root (highest or lowest priority)
* Heap Sort using repeated root deletion
* Priority-based real-world applications

---

### Assignment 01

* Q1 - Flight management using a Binary Search Tree (BST)
* Q2 - Emergency management using an AVL Tree

---

### DS Lab Quiz 01

* Q1 - Ambulance Priority Queue
* Q2 - AVL Tree

---

### Data Structures Practice

Extra practice programs outside the weekly labs, including:

* Diagonal, lower triangular, upper triangular, symmetric and tri-diagonal matrix to 1D array mapping
* Row mapping and matrix to 1D conversion
* Sparse matrices (row-column-value and linked list representations)
* Linked list practice

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
* Special matrices and sparse matrices stored in compact 1D form

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

### Stacks

* LIFO (Last In, First Out) principle
* Stack using an array (`top` index)
* Stack using a singly linked list (`top` pointer)
* `push`, `pop`, `peek`, `display` and `isEmpty` operations
* Overflow and underflow conditions
* Memory cleanup when popping nodes and in destructors

### Queues

* FIFO (First In, First Out) principle
* Linear and circular queues
* Priority queues
* Double-ended queues (deque)
* `enqueue` and `dequeue` operations

### Trees

* Tree hierarchy and node relationships
* Binary Search Trees (BST)
* AVL Trees and rotations
* Breadth-First Search (BFS) and Depth-First Search (DFS)

### Heaps

* Max Heap and Min Heap
* Heapify Up and Heapify Down
* Level Order Traversal
* Heap Sort
* Priority-based processing

### C++ Programming

* Variables and data types
* Conditional statements
* Loops
* Functions
* Arrays
* Pointers
* Structures/classes where applicable
* Object-Oriented Programming (OOP)
* Dynamic memory allocation
* `new` and `delete`
* Problem-solving

---

## Practical Applications

The assignments demonstrate how data structures can be applied to practical scenarios, including:

* Student record management
* Student marks management
* Student merit ranking
* Hospital bed management
* Hospital patient management
* Hospital emergency handling and patient priority
* Hospital inventory and medicine expiry management
* Parking management
* Computer lab management
* Online shopping carts and order sorting
* Browser history and browser back button
* Image galleries
* Game player turns
* Music playlists
* Undo operations in a text editor
* Restaurant order processing
* Bank queue and network packet handling
* Train station management
* Department hierarchy and file explorer
* Flight and ambulance management

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

The same command pattern works for every lab:

```powershell
g++ <folder>/<file>.cpp -o task.exe
.\task.exe
```

### Examples

```powershell
# Lab 02 - Arrays
g++ Lab_02_array/Task_01.cpp -o task.exe
.\task.exe

# Lab 06 - Stacks
g++ Lab_06_Stacks/Task1_Browser_Back_History.cpp -o task.exe
.\task.exe

# Lab 07 - Queues
g++ Lab_07_queues/Task1_BankQueue.cpp -o task.exe
.\task.exe

# Lab 08 - Trees
g++ Lab_08_Tree/task4_hospital_avl.cpp -o task.exe
.\task.exe

# Lab 09 - Heap
g++ Lab_09_Heap/Task1_StudentMeritRanking.cpp -o task.exe
.\task.exe
```

> Replace the folder and source filename with the `.cpp` file you want to compile and execute. If a path contains spaces (for example `Data Structures practice/` or `Task _4_Music Playlist.cpp`), wrap it in quotes.

---

## Compiling with a Specific C++ Standard

You can also specify a C++ standard when compiling:

```powershell
g++ -std=c++17 Lab_09_Heap/Task3_OrderHeapSort.cpp -o task.exe
.\task.exe
```

The same approach can be used for other lab files.

---

## Learning Objectives

The main objectives of this lab repository are to:

* Understand the fundamentals of data structures.
* Implement arrays and multidimensional arrays in C++.
* Understand and implement singly and doubly linked lists.
* Understand and implement stacks and queues using arrays and linked lists.
* Understand and implement trees, AVL trees and heaps.
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
