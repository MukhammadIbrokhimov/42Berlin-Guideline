# Exercise 00: Megaphone

## Description

This exercise is designed to help you get familiar with basic C++ syntax, command-line arguments, and string manipulation. The goal is to write a program called **Megaphone** that takes input from the command line and outputs it in uppercase. If no input is provided, the program should output a loud noise message.

---

## Code Explanation

Below is the provided code for the **Megaphone** program:

```cpp
#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
    using namespace std;

    // Check if there are command-line arguments
    if (argc != 1) {
        // Loop through each argument
        for (int i = 1; argv[i]; i++) {
            // Loop through each character in the argument
            for (int j = 0; argv[i][j]; j++) {
                // Convert the character to uppercase and print it
                cout << static_cast<char>(toupper(argv[i][j]));
            }
            // Print a space between arguments (if not the last one)
            if (argv[i + 1] != NULL)
                cout << ' ';
        }
        cout << endl; // End the line after printing all arguments
    } else {
        // If no arguments are provided, print the loud noise message
        string text = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        cout << text << endl;
    }
}
