# File Management System

A color-enabled Windows command-line application for common file-management tasks. Built in C as a **Programming Fundamentals** academic project, it provides a clear numbered menu for managing files and folders without leaving the terminal.

## What it can do

- Create, write to, and read text files.
- Copy, move, rename, and delete files from the Advanced File Operations menu.
- Display a file's size plus created, modified, and accessed timestamps.
- List folders and files in a directory, including file sizes.
- Search a directory for files or folders by name (case-insensitive).
- Generate a plain-text CV from details entered in the application.
- Transform files using a password-based XOR operation. Applying the same operation again reverses it.

## Screenshots

### Main menu
![Main menu](docs/screenshots/main-menu.png)

### File creation confirmation
![Successful file creation](docs/screenshots/create-file-success.png)

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
2. Choose an option from the numbered main menu.
3. Enter the requested file or directory path. Use `.` as the directory path to work in the current folder.
4. Follow the on-screen prompts; press Enter after an operation to return to the menu.

> **Caution:** Creating a file, copying a file, generating a CV, and using XOR with an existing destination path can overwrite its contents. Move and delete are also irreversible in this application. Use copies of important files while testing.

## Project structure

```text
FILE-MANAGEMENT-SYSTEM/
├── src/
│   └── main.c                 # Application source code
├── docs/
│   ├── PROJECT_STRUCTURE.md   # Project notes and conventions
│   └── screenshots/           # README screenshots
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
