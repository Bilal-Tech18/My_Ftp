# MyFTP
MyFTP is a custom implementation of an FTP server developed in C. The goal of this project was to recreate basic FTP functionalities, following the FTP protocol standards.

![ftp-port-number](https://github.com/user-attachments/assets/7c0d2d2c-6e95-4f5a-9bfb-2574b4f3a15f)

## Author

- [Bilal-Tech18](https://github.com/Bilal-Tech18)

## Features

- Supports basic FTP commands:
  - **USER**: Specify the username
  - **PASS**: Provide the password
  - **PWD**: Print the current working directory
  - **CWD**: Change the current working directory
  - **CDUP**: Move to the parent directory
  - **QUIT**: Close the connection
  - **NOOP**: Test the connection (no operation)
  - **LIST**: List files and directories
  - **HELP**: Display available commands
- Error handling for invalid commands or connection issues
- Socket-based server communication
- Command parsing and response generation
- Modular and maintainable codebase

## Compilation

To compile the project, run the following command in the root directory:

```make```

## Execution

To execute the project, run:

```./myftp <port>```

### Example

```./myftp 8080```
