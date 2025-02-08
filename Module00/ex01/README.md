
# Exercise 01: My Awesome PhoneBook

## Description

In this exercise, you will implement a simple phonebook application that allows users to add, search, and display contacts. The phonebook can store up to 8 contacts. If the user tries to add a 9th contact, the oldest one will be replaced by the new one. This exercise will help you practice **class design**, **encapsulation**, and **basic user input/output handling** in C++.

---

## Requirements

### Classes to Implement
1. **PhoneBook**:
   - Contains an array of `Contact` objects.
   - Can store a maximum of 8 contacts.
   - If a 9th contact is added, the oldest contact is replaced.
   - Provides functionality to add and search for contacts.

2. **Contact**:
   - Represents a single contact in the phonebook.
   - Contains the following fields:
     - First Name
     - Last Name
     - Nickname
     - Phone Number
     - Darkest Secret

### Commands
The program should accept the following commands:
1. **ADD**:
   - Prompts the user to input the contact's information (first name, last name, nickname, phone number, and darkest secret).
   - Saves the new contact to the phonebook.
   - If the phonebook is full (8 contacts), the oldest contact is replaced.

2. **SEARCH**:
   - Displays all saved contacts in a formatted table with 4 columns: Index, First Name, Last Name, and Nickname.
   - Each column should be 10 characters wide, right-aligned, and truncated with a dot (`.`) if the text exceeds the column width.
   - Prompts the user to enter the index of a contact to display its full details.

3. **EXIT**:
   - Exits the program.

---

## Files to Submit
- **Makefile**: The compilation rules for your program.
- **PhoneBook.cpp**: The implementation file for the `PhoneBook` class.
- **PhoneBook.hpp**: The header file for the `PhoneBook` class.
- **Contact.cpp**: The implementation file for the `Contact` class.
- **Contact.hpp**: The header file for the `Contact` class.
- **main.cpp**: The main program file.

---

## How to Implement

### Step 1: Design the Classes
- Define the `Contact` class with private attributes for the contact's fields and public methods to set and get these fields.
- Define the `PhoneBook` class with an array of `Contact` objects and methods to add and search for contacts.

### Step 2: Implement the Commands
- **ADD**:
  - Prompt the user to input each field of the contact.
  - Validate that no field is left empty.
  - Add the contact to the phonebook.

- **SEARCH**:
  - Display all contacts in a formatted table.
  - Prompt the user to enter an index and display the corresponding contact's details.

- **EXIT**:
  - Exit the program gracefully.

### Step 3: Handle Edge Cases
- Ensure the program handles invalid input (e.g., empty fields, invalid index during search).
- If the phonebook is full, replace the oldest contact when adding a new one.

---

## How to Run the Program

### Step 1: Compile the Code
Save your files and compile the program using the following command:

```bash
c++ -Wall -Wextra -Werror -std=c++98 main.cpp PhoneBook.cpp Contact.cpp -o phonebook
