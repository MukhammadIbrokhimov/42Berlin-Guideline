# Quick Sort Algorithm for Push Swap Project

## Overview

This Quick Sort algorithm is designed to solve the Push Swap problem, a project in the 42 curriculum. The algorithm efficiently sorts a stack of numbers using a series of operations (`sa`, `ra`, `rb`, `pa`, `pb`, etc.) while adhering to the constraints of the project. It operates recursively and leverages the concept of sorting in chunks to optimize the sorting process.

## Algorithm Description

### 1. Initial Setup: Mid-Value Calculation

The algorithm starts by calculating the mid-value of the current stack (`a`). If the mid-value happens to be the smallest negative number or the largest positive number in the stack, it is adjusted by selecting the next node above it (`(*a).prev`).

### 2. Pushing to Stack B

The algorithm proceeds by pushing nodes from stack `a` to stack `b` based on their value in relation to the mid-value:

- If the value of a node is less than the mid-value, it is pushed to `b`.
- If the value of a node is greater than the mid-value, the stack is rotated (`ra`), and the first greater value is saved in a temporary variable (`tmp`) to keep track of where to stop. This prevents looping over the list multiple times, as there are no duplicate values in the list.

### 3. Recursive Process for Reduced List

Once the greater number stored in `tmp` appears again, the algorithm stops rotating or pushing. At this point, the algorithm recursively sorts the list with a reduced size. This continues until only two nodes are left in the list, which are then sorted directly.

### 4. Pushing Back from Stack B to Stack A

Once the stack `a` is sorted, the algorithm begins pushing elements back from stack `b` to stack `a`. Rather than finding the mid-value of the entire stack, the mid-value is calculated only for the chunk that was last pushed to `b`. This chunk is handled first.

For each chunk:
1. The mid-value is calculated within the chunk.
2. Greater numbers are pushed from stack `b` to stack `a` while rotating `b` to only affect the current chunk.
3. The first smaller number is saved in a temporary variable (`tmp`) to track where to stop.
4. Once no greater numbers are left in the chunk, the mid-value is pushed first, followed by the smaller numbers.

### 5. Recursion and Final Sorting

This process continues recursively for each chunk until the entire stack is sorted in stack `a`. Throughout the sorting, the algorithm double-checks the order in `a` to ensure smooth progression. If necessary, the `sa` operation is used to swap two elements for better order.

### 6. Edge Case Handling

The algorithm has built-in handling for:
- **Single-element and two-element lists**: These are sorted directly without recursion.
- **Non-contiguous chunks**: The rotations are restricted to the boundaries of each chunk to ensure efficient sorting.

## Conclusion

This Quick Sort algorithm efficiently sorts a stack using a series of operations, adhering to the constraints of the Push Swap project. The recursive approach, combined with chunk-based sorting and careful tracking of values, ensures that the algorithm performs well even with large input sizes.

## Operations Used

- `sa`: Swap the first two elements of stack `a`.
- `ra`: Rotate stack `a` (move the top element to the bottom).
- `rb`: Rotate stack `b`.
- `pa`: Push the top element from stack `b` to stack `a`.
- `pb`: Push the top element from stack `a` to stack `b`.

## Future Improvements

- Consider optimizing recursion depth or implementing an iterative approach if the stack size grows too large.
- Further edge case handling for negative values and empty stacks can be implemented to increase robustness.
