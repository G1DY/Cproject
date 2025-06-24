# Cproject

This C program checks whether a substring within a larger character buffer has balanced parentheses. It includes strict error checking to validate pointers, buffer sizes, and string termination before performing any logic.

## Project Structure

```
├── checkparenthesesbalance.c // Main logic and error checking functions
├── testcheckparenthesesbal.c // (Optional) Separate test driver, if used
├── README.md // Project overview and usage instructions
```

## Features

- Validates:
  - Null pointers
  - Buffer sizes
  - Null-terminated strings
  - Substring range correctness
- Checks if the given substring contains **balanced parentheses**
- Reports detailed input errors with descriptive messages

## Run

```bash
gcc checkparenthesesbalance.c -o check
./check
```
