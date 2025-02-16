# Calculator Application using Qt and C++

This project is a simple calculator built with Qt Creator and C++.

## Features
- Basic arithmetic operations: Addition, Subtraction, Multiplication, Division
- Unary operations: Percentage, Plus/Minus
- Supports decimal numbers
- Clear button to reset the calculator

## Code Overview
- **digit_pressed()**: Handles digit button clicks and updates the display accordingly.
- **unary_operation_pressed()**: Handles operations like plus/minus and percentage.
- **binary_operation_pressed()**: Sets the first number and operation to be performed.
- **on_pushButton_equals_released()**: Executes the selected operation and displays the result.
- **on_pushButton_clear_released()**: Resets the calculator.

## How to Build
1. Open the project in Qt Creator.
2. Build and run the project.
