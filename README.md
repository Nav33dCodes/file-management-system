# FILE MANAGEMENT SYSTEM

A Windows terminal application, written in C, for common file-management tasks through a structured, color-enabled console interface.

> **Academic project:** First Semester — Programming Fundamentals

## What it does

- Creates, reads, writes, renames, moves, copies, and deletes files.
- Displays file metadata and directory contents.
- Searches a selected directory by filename keyword.
- Generates a plain-text CV.
- Applies a reversible XOR transformation to files using a user-provided key.

## Project layout

```text
src/     Application source code
docs/    Documentation and project notes
bin/     Local build output (ignored by Git)
```

For the full layout and repository conventions, see [Project Structure](docs/PROJECT_STRUCTURE.md).

## Requirements

- Windows 10 or later
- A C compiler with Windows SDK support, such as MinGW-w64 GCC
- A terminal that supports ANSI escape sequences (Windows Terminal is recommended)

## Build and run

From the repository root:

```powershell
New-Item -ItemType Directory -Force bin
gcc -Wall -Wextra -std=c11 src/main.c -o bin/file-management-system.exe
.\bin\file-management-system.exe
```

## Using the application

Run the program, select a menu item, and provide the requested file or directory path. Use `.` as the directory path when you want to work in the current folder.

Some actions change or remove files. Test with copies of important files before using the application on real work.

## Security note

The XOR feature is a learning exercise, not secure encryption. Do not use it to protect confidential, personal, or production data.

## Development standards

- Keep source code in `src/` and documentation in `docs/`.
- Prefer bounded input and output functions, such as `fgets` and `snprintf`.
- Compile with warnings enabled before submitting changes.
- Do not commit generated executables, object files, logs, or editor settings.

## Contributing

1. Create a branch using the organization’s naming convention.
2. Make focused changes and update documentation when behavior or usage changes.
3. Build the application locally with warnings enabled.
4. Open a pull request with a concise summary, test evidence, and any known limitations.

## GitHub Enterprise setup

When hosting this project on GitHub Enterprise, create the repository in the appropriate organization and use your organization’s repository URL:

```powershell
git clone https://<github-enterprise-host>/<organization>/file-management-system.git
```

Protect the default branch, require pull-request review where applicable, and enable the organization’s approved security scanning and code-ownership policies.

## Academic details

| Item | Details |
| --- | --- |
| Course | Programming Fundamentals |
| Student | Naveed Ahmed (Roll No: 2024-uam-1844) |
| Instructor | Sir Nasir Siddiqui |
| Institution | MNS University of Agriculture, Multan |

## License

See [LICENSE](LICENSE).
