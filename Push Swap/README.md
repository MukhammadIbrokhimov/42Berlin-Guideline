# Push Swap  

## Overview  
The **Push Swap** project is part of the 42 School curriculum and focuses on sorting integers using two stacks (`A` and `B`) and a limited set of operations. The challenge is to design an efficient algorithm that sorts the stack with the minimum number of moves, showcasing your algorithmic thinking and optimization skills.  

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
- [Author](#author)  

---

## Objective  
- Sort the integers in `stack A` in ascending order.  
- Minimize the number of operations.  
- Handle edge cases, including:  
  - Already sorted stacks.  
  - Reverse-sorted stacks.  
  - Stacks with only a few elements (e.g., 3 or 5).  

---

## Allowed Operations  

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

### Input Handling  
- Validates input to ensure no duplicates and all values are integers.  

### Sorting Logic  
- Implements sorting using only the allowed operations.  

### Output  
- Outputs a sequence of operations required to sort the stack.  

### Error Handling  
- Gracefully manages invalid inputs.  

---

## Algorithm Strategies  

### Small Stacks (e.g., 3 or 5 elements)  
- Uses hardcoded logic for optimal sorting with minimal moves.  

### Larger Stacks (e.g., 100 or 500 elements)  
- Implements **Radix Sort**, which is efficient for large data sets:  
  1. Process each bit of the binary representation.  
  2. Push or rotate elements based on the current bit.  
  3. Reassemble the sorted stack.  

---

## How to Use  

### Compilation  
Run the following commands to compile the program:  
```bash  
make            # Builds push_swap executable  
make checker    # Builds checker executable (bonus)  
make all        # Builds both push_swap and checker  
```

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
