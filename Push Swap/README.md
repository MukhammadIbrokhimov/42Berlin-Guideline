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

# Sorting Algorithm with Radix Sort for Large Lists

This code implements a sorting algorithm for a singly-linked list (`t_list`) using different strategies based on the size of the list. Below is an explanation of the approach, focusing on the **Radix Sort** for lists with more than five elements.

---

## Overview of Sorting Logic

1. **List Size 3**:
   - Uses a hard-coded strategy (`sort_three`) to arrange the elements in ascending order with minimal operations. It applies specific swaps (`sa`), rotations (`ra`), or reverse rotations (`rra`) to achieve this.

2. **List Size 2**:
   - If the list is not already sorted, it swaps the two elements using the `sa` operation.

3. **List Size 4 or 5**:
   - Uses a helper function (`sort_five_or_four`) to:
     - Push the smallest element(s) to a secondary stack (`b`) using `push_minvalue`.
     - Sort the remaining three elements in the main stack (`a`) using `sort_three`.
     - Push the elements from stack `b` back to stack `a` in sorted order using `pa`.

4. **List Size > 5**:
   - Uses **Radix Sort**, a non-comparative sorting algorithm based on the binary representation of the numbers' indices.

---

## Radix Sort Explanation

Radix Sort processes the numbers bit by bit (from least significant bit to most significant bit) and uses two stacks (`a` and `b`) to organize the numbers based on their binary representation. Here’s a breakdown of the process:

### Preprocessing
1. **Index Assignment**:
   - Each element in the list is assigned an "index" based on its position in the sorted order of the list. For example:
     - Smallest number → Index 0
     - Second smallest number → Index 1
     - And so on...

2. **Calculate `max_bits`**:
   - This is the number of bits required to represent the highest index in binary. For example:
     - If the largest index is `7` (binary `111`), `max_bits = 3`.

---

### Sorting Steps

1. **Bit-wise Processing**:
   - Start with the least significant bit (LSB) and move towards the most significant bit (MSB).
   - For each bit position `i` (from 0 to `max_bits - 1`):
     - Iterate through all elements in stack `a`.
     - Check the value of the current bit (`i`) for the element at the top of the stack:
       - If the bit is `1`, perform a `rotate` operation (`ra`) to keep the element in stack `a`.
       - If the bit is `0`, perform a `push` operation (`pb`) to move the element to stack `b`.

2. **Reintegrate Elements**:
   - Once all elements are processed for a given bit, push all elements from stack `b` back to stack `a` using `pa`.

3. **Repeat for Next Bit**:
   - Increment the bit index (`i`) and repeat the process until all bits are processed.

---

### Key Points of Radix Sort
- The algorithm ensures that, after processing each bit, the elements are partially sorted according to the binary representation of their indices.
- By the time all bits are processed, the elements are fully sorted in ascending order.

---

## Why Radix Sort for > 5 Elements?

Radix Sort is efficient for small ranges of integers (or indices, in this case) because:
- It processes each bit independently, ensuring stable and predictable sorting.
- It avoids direct comparisons between elements, simplifying implementation for linked lists.

---

## Complexity Analysis

- **Time Complexity**: \(O(n \cdot \text{max\_bits})\), where:
  - \(n\) is the number of elements.
  - \(\text{max\_bits}\) is the number of bits needed to represent the largest index.
- **Space Complexity**: \(O(n)\) due to the use of an auxiliary stack (`b`).

---

## Example Walkthrough

Let’s say the list contains the elements `[4, 2, 7, 3, 1]`, and the indices after preprocessing are `[3, 1, 4, 2, 0]`.

### Step-by-step:

1. **For bit `0` (LSB)**:
   - Numbers with LSB = 0 → Push to stack `b`: `[2, 0]`.
   - Numbers with LSB = 1 → Remain in stack `a`: `[3, 1, 4]`.

2. **Push all from `b` back to `a`.

3. **For bit `1`**:
   - Numbers with the second bit = 0 → Push to `b`: `[0, 1]`.
   - Numbers with the second bit = 1 → Remain in `a`: `[2, 3, 4]`.

4. **Repeat for higher bits**.

By the end of processing all bits, the list is sorted.

---

## Why This Approach Works

Radix Sort ensures that elements are sorted by processing each bit in their binary representation. This approach is stable and efficient for linked lists when paired with auxiliary operations like `push`, `rotate`, and `reverse rotate`.



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
