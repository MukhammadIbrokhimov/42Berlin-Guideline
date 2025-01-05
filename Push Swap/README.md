# Push_swap

The **Push_swap** project is a sorting algorithm challenge that utilizes two stacks (A and B) and a limited set of operations to sort a list of integers. This project is designed to enhance algorithmic thinking, problem-solving, and efficiency optimization skills.

---

## Table of Contents
- [Overview](#overview)
- [Objective](#objective)
- [Allowed Operations](#allowed-operations)
- [Project Structure](#project-structure)
- [Algorithm Strategies](#algorithm-strategies)
- [How to Use](#how-to-use)
- [Testing and Evaluation](#testing-and-evaluation)
- [Resources](#resources)

---

## Overview
The **Push_swap** project involves sorting integers in ascending order using two stacks (`stack A` and `stack B`) and a predefined set of operations. The challenge is to create an efficient program that minimizes the number of operations required.

---

## Objective
- Sort the integers in `stack A` in ascending order.
- Use as few operations as possible.
- Handle edge cases such as:
  - Already sorted stacks.
  - Reverse-sorted stacks.
  - Stacks with only a few elements (e.g., 3 or 5).

---

## Allowed Operations
The program can manipulate stacks using the following commands:

| Command | Description |
|---------|-------------|
| `sa`    | Swap the first two elements of stack A. |
| `sb`    | Swap the first two elements of stack B. |
| `ss`    | Perform `sa` and `sb` simultaneously. |
| `pa`    | Push the top element of stack B onto stack A. |
| `pb`    | Push the top element of stack A onto stack B. |
| `ra`    | Rotate stack A (shift all elements up, moving the first element to the last position). |
| `rb`    | Rotate stack B. |
| `rr`    | Perform `ra` and `rb` simultaneously. |
| `rra`   | Reverse rotate stack A (shift all elements down, moving the last element to the first position). |
| `rrb`   | Reverse rotate stack B. |
| `rrr`   | Perform `rra` and `rrb` simultaneously. |

---

## Project Structure
1. **Input Handling**:
   - The program accepts a list of integers as input.
   - It validates the input to ensure no duplicates and that all values are integers.

2. **Sorting Logic**:
   - The sorting algorithm operates using only the allowed stack operations.

3. **Output**:
   - The program outputs a sequence of operations to sort the stack.

4. **Error Handling**:
   - Handles invalid inputs gracefully.

---

## Algorithm Strategies
Here are some common approaches to solving the **Push_swap** problem:

1. **Small Stacks (e.g., 3 or 5 elements):**
   - Hardcode the sorting logic for these cases since they can be solved with very few operations.

2. **Larger Stacks (e.g., 100 or 500 elements):**
   - Use efficient algorithms like:
     - **Divide and Conquer:** Divide the stack into smaller parts and sort them individually.
     - **Radix Sort:** Particularly effective for large stacks.
     # here was used Radix Sort
     - **Quick Sort-inspired approach:** Partition the stack based on pivots.

---

## How to Use
### Compilation
Run the following command to compile the program:
```bash
make
```
This generates the `push_swap` executable.

```bash
make checker
```
This generates the `checker` executable for bonus part.

```bash
make all
```
This generates the `checker && push_swap` all projects at once.

### Usage
To run the program, use:
```bash
./push_swap [list_of_integers]
```
Example:
```bash
./push_swap 3 2 5 1 4
```

This outputs the sequence of operations required to sort the input stack.

To run the program and checker, use:
```bash
ARG="list of integers"; ./push_swap $ARG | ./checker $ARG
```
Example:
```bash
ARG="34 35 554 3"; ./push_swap $ARG | ./checker $ARG
```
This outputs the result of operations required to sort the input stack.
```bash
ARG="34 35 554 3"; ./push_swap $ARG | ./checker $ARG
OK
KO
```

---

## Testing and Evaluation
### Checker Program
To verify your output, use the provided `checker` program:
```bash
./push_swap [list_of_integers] | ./checker [list_of_integers]
```
If your operations are correct, `checker` will output `OK`. Otherwise, it will output `KO`.

### Performance
Your program will be evaluated on:
- Correctness: Does it sort the stack correctly?
- Efficiency: How many operations are required?

### Benchmarks
| Stack Size | Expected Number of Operations |
|------------|-------------------------------|
| 3          | 3                             |
| 5          | ~12                           |
| 100        | ~700                          |
| 500        | ~5500                         |

---

## Resources
- [42 Docs on Push_swap](https://projects.intra.42.fr/projects/push_swap)
- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

---

## Author
Mukhammad Ibrokhimov
This project was completed as part of the curriculum at [42 School / Your Institution].
