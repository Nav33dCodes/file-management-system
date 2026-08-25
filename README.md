# File Management System

A Windows command-line application written in C for everyday file-management tasks. It provides a simple, color-enabled menu for working with files and folders directly from the terminal.

> Academic project for **Programming Fundamentals**.

## Features

- **File operations:** create, read, append to, rename, copy, move, and delete files.
- **File information:** view file size and timestamps.
- **Directory tools:** list directory contents and search names by keyword.
- **CV generator:** create a plain-text CV from entered details.
- **XOR transformation:** apply or reverse an XOR transformation with a key.

## Screenshots

<!-- Add the original full-resolution images to docs/screenshots/ and uncomment these lines.
### Main menu
![Main menu](docs/screenshots/main-menu.png)

### File creation
![File created successfully](docs/screenshots/create-file-success.png)
-->

## Requirements

- Windows 10 or later
- A C compiler with Windows support, such as [MinGW-w64 GCC](https://www.mingw-w64.org/)
- A terminal with ANSI escape-sequence support (Windows Terminal is recommended)

## Build and run

From the project folder, run:

```powershell
New-Item -ItemType Directory -Force bin
gcc -Wall -Wextra -std=c11 src/main.c -o bin/file-management-system.exe
.\bin\file-management-system.exe
```

## How to use

1. Run the executable.
2. Enter the number for the feature you want to use.
3. Provide the requested file or directory path. Use `.` for the current directory.

> **Warning:** Some features can overwrite, move, or delete files. Test with copies of important files first.

## Project structure

```text
FILE-MANAGEMENT-SYSTEM/
├── src/
│   └── main.c                 # Application source code
├── docs/
│   └── PROJECT_STRUCTURE.md   # Project notes and conventions
├── bin/                       # Local build output (not committed)
├── .gitignore
├── LICENSE
└── README.md
```

For more detail, see [Project Structure](docs/PROJECT_STRUCTURE.md).

## Limitations

- This project is designed for Windows and uses the Windows API for directory operations.
- The XOR feature is a learning exercise—not secure encryption. Do not use it to protect confidential data.
- Automated tests have not yet been added.

## Academic details

| Item | Details |
| --- | --- |
| Course | Programming Fundamentals |
| Student | Naveed Ahmed (Roll No: 2024-uam-1844) |
| Instructor | Sir Nasir Siddiqui |
| Institution | MNS University of Agriculture, Multan |

## License

Released under the [MIT License](LICENSE).
