# Dine-In Digital - Restaurant Ordering System

A C++ console application that simulates a digital ordering system for restaurants, enabling waiters to take customer orders, manage bills, and save order records.

## About This Project

This project was completed as part of Seneca College's OOP244 (Object-Oriented Programming) course. It demonstrates proficiency in C++ programming concepts including inheritance, polymorphism, dynamic memory management, and object-oriented design principles.

**Note:** All code in this repository is my own work or derived from content taught in class. This README was created with assistance from Claude Sonnet 4.5.

---

## Features

- Interactive menu-driven interface for waiters
- Order management for food and drinks with customizable options
- Automatic bill generation with tax calculation
- Bill persistence (saves completed orders to files)
- Foolproof input validation
- Dynamic memory management
- Support for different portion sizes (child/adult for food, S/M/L/XL for drinks)
- Custom order instructions

---

## Technical Highlights

### Object-Oriented Design

- **Inheritance hierarchy**: Abstract `Billable` base class with `Food` and `Drink` derived classes
- **Polymorphism**: Virtual functions and operator overloading
- **Encapsulation**: Proper use of private/protected/public access modifiers
- **Composition**: `Menu` class owns `MenuItem` objects

### C++ Concepts Demonstrated

- Dynamic memory allocation and the Rule of Three
- Abstract base classes and pure virtual functions
- Operator overloading (+, +=, <<, type conversion)
- File I/O (reading CSV data, writing bills)
- Safe empty state implementation
- Input validation and error handling

---

## Project Structure

### Core Modules

**Utils**

- Utility functions for dynamic memory allocation
- Foolproof input handling (integer validation, range checking)
- Helper functions to prevent code duplication

**Menu & MenuItem**

- `MenuItem`: Represents individual menu items with formatting and display capabilities
- `Menu`: Manages collections of menu items and provides user selection interface
- Demonstrates composition pattern

**Billable (Abstract Base Class)**

- Foundation for all billable items (food and drinks)
- Defines common interfaces through pure virtual functions
- Implements shared pricing and display functionality

**Food**

- Inherits from Billable
- Supports portion sizes: Child and Adult
- Allows custom order instructions
- Dynamic pricing based on portion

**Drink**

- Inherits from Billable
- Supports sizes: Small, Medium, Large, Extra Large
- Dynamic pricing based on size

**Ordering**

- Manages the complete ordering process
- Loads food and drink data from CSV files
- Handles order taking and bill generation
- Saves completed bills to individual files

**Main**

- Initializes the application
- Provides interactive waiter interface
- Coordinates menu navigation and order processing

---

## How to Build and Run

### Prerequisites

- C++ compiler with C++11 support (g++ recommended)
- Standard C++ libraries

### Compilation

Compile all source files using:

```bash
g++ -Wall -std=c++11 -g -o restaurant *.cpp
```

### Running the Application

```bash
./restaurant
```

### Data Files

The application requires two CSV data files:

- `drinks.csv` - Contains available drinks and prices
- `foods.csv` - Contains available food items and prices

Format: `item_name,price`

---

## Usage Example

```text
Seneca Restaurant
 1- Order
 2- Print Bill
 3- Start a New Bill
 4- List Foods
 5- List Drinks
 0- End Program
> 1

   Order Menu
    1- Food
    2- Drink
    0- Back to main menu
   > 1

      Food Menu
       1- Steak
       2- Pasta
       3- Burger
       0- Back to Order
      > 1

         Food Size Selection
            1- Adult
            2- Child
            0- Back
         > 1

         Special instructions
         > Well done

[Bill generated with tax calculation and saved to file upon completion]
```

---

## Development Approach

This project was built incrementally through five milestones:

1. **Milestone 1**: MenuItem class - Menu item representation and display
2. **Milestone 2**: Menu class - Interactive menu system with input validation
3. **Milestone 3**: Billable hierarchy - Abstract base class with Food and Drink derived classes
4. **Milestone 4**: Ordering module - Order management and bill generation
5. **Milestone 5**: Complete application - Full integration with foolproof input handling

---

## Key Implementation Details

### Constants

- `MaximumNumberOfMenuItems`: Maximum menu items (20)
- `MaximumNumberOfBillItems`: Maximum items per bill
- `Tax`: Tax rate for bill calculations

### Memory Management

- Follows the Rule of Three for classes with dynamic memory
- Proper cleanup in destructors to prevent memory leaks
- Safe empty state implementation for error handling

### Input Validation

The application includes robust input validation:

- Handles empty input
- Validates integer input
- Checks for trailing characters
- Enforces range constraints
- Provides clear error messages

### Bill Generation

- Unique bill numbers with sequential numbering
- Automatic tax calculation
- Bills saved to individual files (`bill_001.txt`, `bill_002.txt`, etc.)
- Formatted output with item details and totals

---

## Learning Outcomes

Through this project, I gained experience in:

- Designing and implementing class hierarchies
- Working with abstract base classes and pure virtual functions
- Managing dynamic memory in C++
- Implementing operator overloading for intuitive interfaces
- Handling file I/O operations
- Creating robust input validation systems
- Building modular, maintainable code
- Following object-oriented programming principles

---

## Course Information

**Course**: OOP244 - Introduction to Object-Oriented Programming
**Institution:** Seneca Polytechnic
**Semester:** Winter 2026
**Language**: C++11

---

## License

This project is an academic assignment and is provided for educational and portfolio purposes only.
