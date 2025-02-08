# Exercise 02: The Job Of Your Dreams

## Description

In this exercise, you will recreate a missing `Account.cpp` file based on a provided `Account.hpp` header and a log file. The goal is to match the behavior described in the log file. This exercise will help you understand class implementation, constructors, destructors, and logging mechanisms in C++.

---

## Files Provided
- **Account.hpp**: The header file containing the class definition for `Account`.
- **tests.cpp**: A test file that uses the `Account` class.
- **log file**: A log file containing the expected output of the program.

## Files to Submit
- **Makefile**: The compilation rules for your program.
- **Account.cpp**: The implementation file for the `Account` class.
- **Account.hpp**: The provided header file (do not modify).
- **tests.cpp**: The provided test file (do not modify).

---

## Objective

Your task is to implement the missing `Account.cpp` file so that the program behaves as described in the log file. The log file contains the expected output, including timestamps and the order of constructor/destructor calls. Your implementation must match this behavior.

---

## Key Concepts to Implement

1. **Class Implementation**:
   - Implement the `Account` class as defined in `Account.hpp`.
   - Ensure that all member functions and constructors/destructors are correctly implemented.

2. **Logging**:
   - The program should log specific events (e.g., account creation, deposits, withdrawals) to the standard output.
   - The log format should match the one provided in the log file.

3. **Timestamps**:
   - The log file includes timestamps for each event. While your timestamps will differ (since they are generated at runtime), the order of events must match.

4. **Memory Management**:
   - Ensure proper memory management, especially when dealing with dynamic allocation (if any).

---

## How to Approach the Exercise

1. **Analyze the Log File**:
   - Carefully study the log file to understand the expected behavior of the program.
   - Note the order of constructor/destructor calls and the format of the log messages.

2. **Implement `Account.cpp`**:
   - Write the implementation for the `Account` class based on the provided `Account.hpp`.
   - Ensure that all member functions (e.g., `makeDeposit`, `makeWithdrawal`) are implemented correctly.

3. **Test Your Implementation**:
   - Compile the program using the provided `tests.cpp` file.
   - Compare the output of your program with the log file to ensure they match.

---

## How to Run the Program

### Step 1: Compile the Code
Save your `Account.cpp` implementation and compile the program using the following command:

```bash
c++ -Wall -Wextra -Werror -std=c++98 Account.cpp tests.cpp -o account
