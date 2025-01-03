# Quick Sort Algorithm for Push Swap Project

## Overview

This Quick Sort algorithm is designed to tackle the Push Swap problem, part of the 42 curriculum. The solution sorts a stack of numbers using a series of operations (`sa`, `ra`, `rb`, `pa`, `pb`, etc.) while adhering to the project's constraints. By leveraging recursive sorting and chunk-based optimization, the algorithm ensures efficient performance.

---

## Algorithm Description

### 1. Initial Setup: Median Calculation

The algorithm begins by calculating the median value of the current stack `a` using a custom `findMedian` function. This function determines the node closest to the median value, ensuring a more accurate splitting of the list. 

- **Median Node:** The `findMedian` function scans the linked list and calculates the median value of the nodes' contents. It returns the node with the value closest to this median.

### 2. Chunk-Based Splitting: Pushing to Stack `b`

Using the median node, the algorithm divides the stack into manageable chunks:

- **Step 1:** Push all nodes with values less than the median to stack `b`.
- **Chunk Tracking:** Each value pushed to `b` is associated with a chunk identifier, starting from `1`. This allows efficient tracking and recursion for subsequent processing.

When no further values are less than the median, the algorithm calls itself recursively, incrementing the chunk identifier (`chunk + 1`). This process continues until only three nodes remain in stack `a`.

### 3. Sorting the Remaining Three Values

Once the stack `a` is reduced to three nodes, a specialized `sortThree` function is called to sort them directly. This function ensures the remaining values are in ascending order.

### 4. Chunk Restoration: Pushing Back from `b` to `a`

After sorting stack `a`, the algorithm begins restoring values from `b` back to `a`:

- **Chunk Length Handling:** The algorithm calculates the length of the current chunk in `b`. If the length is `2` or `1`, the values are pushed directly back to `a`.
- **Splitting Large Chunks:** For chunks longer than `2`, the algorithm saves the address of the next chunk's first node to avoid data loss. 

#### Modified Median Logic for Chunk Restoration

While processing each chunk:

1. **Calculate Median:** Determine the median for the current chunk.
2. **Push Greater Values:** Move values greater than the median back to `a`.
3. **Track Boundaries:** Use the saved address to restrict operations to the current chunk.
4. **Final Restoration:** Push the remaining values back to `a` in ascending order.

### 5. Recursive Restoration and Final Sorting

This process is repeated recursively for each chunk until stack `b` is empty and stack `a` is fully sorted. At every stage, the algorithm ensures stack `a` remains in ascending order. If necessary, the `sa` operation is used to swap two elements for proper alignment.

---

## Edge Case Handling

The algorithm is designed to handle a variety of edge cases:

- **Single-element and Two-element Lists:** These are sorted directly without invoking recursion.
- **Non-contiguous Chunks:** Rotations are confined within the boundaries of each chunk to prevent disruption of other values.

---

## Advantages of the Updated Approach

### 1. Accurate Median Calculation
- The `findMedian` function ensures precise division of the stack, improving sorting efficiency.

### 2. Chunk-Based Tracking
- By associating each pushed value with a chunk identifier, the algorithm maintains clarity and organization throughout the sorting process.

### 3. Robust Handling of Large Chunks
- Saving the address of the next chunk prevents value loss and ensures seamless operations.

### 4. Optimized Recursion
- Recursive calls are restricted to manageable portions of the stack, minimizing overhead and improving performance.

---

## Visual Representation

```plaintext
Initial Stack (a):  [4, 2, 9, 1, 8, 6, 3]
Median (Step 1):     4
Push to b:           [2, 1, 3]
Sorted a:            [4, 6, 8, 9]
Push Back from b:    [1, 2, 3]
Final Stack (a):     [1, 2, 3, 4, 6, 8, 9]
```

---

## Usage Instructions

1. Implement the `findMedian` function to calculate the median node of a linked list.
2. Ensure proper chunk tracking by tagging each pushed value with a chunk identifier.
3. Use the `sortThree` function to handle small lists efficiently.
4. Test edge cases like single-node and two-node stacks for correctness.

With this refined Quick Sort algorithm, the Push Swap problem becomes more manageable and systematic.


``` mermaid
flowchart TD
    A[Start: Calculate Mid-Value] --> B{Mid-Value Valid?}
    B -- Yes --> C[Push Nodes to B Based on Mid-Value]
    B -- No --> D[Adjust Mid-Value to Next Node Above]
    D --> C
    C --> E{Greater Value in Stack A?}
    E -- Yes --> F[Rotate A and Save First Greater Value]
    E -- No --> G[Stop Rotating/ Pushing]
    G --> H[Recursively Sort Reduced List]
    H --> I{List Size == 2?}
    I -- Yes --> J[Sort Directly]
    I -- No --> H
    J --> K[Push Back From B to A]
    K --> L{Chunk Mid-Value Calculated?}
    L -- Yes --> M[Push Greater Numbers from B to A]
    M --> N[Rotate B to Isolate Chunk]
    N --> O{No Greater Numbers Left?}
    O -- Yes --> P[Push Mid-Value and Smaller Numbers to A]
    O -- No --> M
    P --> Q[Recursively Handle Remaining Chunks]
    Q --> R[Final Check: Correct Order in A?]
    R -- Yes --> S[Use SA to Adjust Order if Needed]
    S --> T[End: Sorted Stack in A]
```

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
