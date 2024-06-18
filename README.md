# Magic Square Generator

## Authors
- [@LuisDA39](https://github.com/LuisDA39)
- [@Nemesis1174](https://github.com/Nemesis1174)
- [@samir-bstb](https://github.com/samir-bstb)

This repository contains a C++ program that generates magic squares of odd sizes. Magic squares are matrices where the sum of numbers in each row, each column, and both diagonals are equal. The program offers different methods to fill the square based on user-selected options.

## Overview

A magic square is created using the following steps:
- **Input Size:** Specify an odd integer for the size of the magic square.
- **Select Method:**
  - 'c': Fill with consecutive numbers starting from 1.
  - 'p': Fill with consecutive even numbers starting from 2.
  - 'i': Fill with consecutive odd numbers starting from 1.
  - 'm': Fill with multiples of a user-provided integer.
  
## Features

- **Dynamic Input:** Allows the user to specify the size of the magic square (must be odd).
- **Menu-Driven Options:** Offers different methods to generate the magic square based on user preferences.
- **Validation:** Ensures the square size is odd before proceeding.
- **Output:** Displays the generated magic square and calculates sums of rows, columns, and diagonals to verify correctness.

## Usage

1. **Size Input:** Enter an odd integer for the size of the magic square.
2. **Method Selection:** Choose one of the methods ('c', 'p', 'i', 'm') to fill the square.
3. **Output:** Displays the magic square with sums of rows, columns, and diagonals.

## Implementation Details

- **Language:** C++
- **Requirements:** Standard C++ library
- **Limitation:** Works only with odd-sized magic squares.

## Getting Started

To run the program:
- Compile the source code (`main.cpp`) using a C++ compiler.
- Execute the compiled program.
- Follow the prompts to generate and display different types of magic squares.

## Example

For a square of size 3 (input):
```
Enter the square size:
3
------MENU-----
Option 'c' for consecutive numbers
Option 'p' for even numbers
Option 'i' for odd numbers
Option 'm' for multiples of x
Enter the option:
c

Magic Square 3x3:
8 1 6
3 5 7
4 9 2

Sum of the row 1: 15
Sum of the column 1: 15
Sum of the row 2: 15
Sum of the column 2: 15
Sum of the row 3: 15
Sum of the column 3: 15
Sum of the main diagonal: 15
Sum of the secondary diagonal: 15
'''
```
