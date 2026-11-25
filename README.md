# BitLab AI

BitLab AI is a command-line learning application for digital systems.

## Current version

v0.0.2

## Build and run

From the repository root, compile the C application and run it:

```sh
cc -std=c99 engine/main.c -lm -o bitlab-app
./bitlab-app
```

## Features

- **Number Systems Lab**: validate a number in binary, octal, decimal, or hexadecimal.
- **Storage Unit Converter**: convert between bytes, kilobytes, megabytes, gigabytes, and terabytes.
- **Input validation**: menu choices must be decimal digits within the displayed range.

### Number Systems Lab

Choose **1. Number Systems** from the main menu, then select a base:

| Selection | Number system | Base |
| --- | --- | ---: |
| 1 | Binary | 2 |
| 2 | Octal | 8 |
| 3 | Decimal | 10 |
| 4 | Hexadecimal | 16 |

Enter the number without a sign, prefix, or spaces. Hexadecimal digits may use
uppercase or lowercase letters (`A`–`F` / `a`–`f`). The result displays the
entered number, its base, its character length, and whether every character is
a valid digit for that base. For example, `101101` in binary is valid, while
`1021` in binary is invalid because `2` is not a binary digit.

## Development status

The Two's Complement, Bitwise Operations, Character Encoding, and Network
Calculator menu entries are placeholders. The About entry displays application
information.

Planned goals include a digital systems calculation engine, a desktop
application, interactive quizzes, and an AI study agent.
