# Project Structure

```text
FILE MANAGEMENT SYSTEM/
├── bin/                  # Local compiled executables (not committed going forward)
├── docs/                 # Project documentation
├── src/                  # C source code
│   └── main.c            # Application entry point and file-operation features
├── .gitignore            # Files excluded from source control
├── LICENSE               # License terms
└── README.md             # Project overview and contributor guide
```

## Conventions

- Keep production C code in `src/`.
- Keep generated binaries in `bin/` and do not commit new build output.
- Add documentation, design notes, and screenshots to `docs/`.
- Add future automated tests under `tests/`, mirroring the source area they cover.
