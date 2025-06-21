# Contact Book
A simple terminal based contact book written entirely in C

# Features
- Adding a Contact
- Removing a Contact
- Finding a Contact
- Viewing all Contacts
- Deleting all Data

# Configuration
You have the full right to fully configure the code that I have created, however you will need to mess around with the source code
Easy configuration is located within the config.h header file.

The following configuration options are avaliable within the config.h header file:
- The location of the CSV file (the file with all the data)
- The maximum characters allowable within the name variables
- The maximum characters allowable within the phone number variables
- The maximum characters allowable within the email variables

**Changing the location of the CSV file will mean that the program will not read the data from the original file, ensure you migrate the data over**
CSV means comma seperated values btw.
The reason why I choose the length of each is documented within the config.h file.

# Requirements
- A C compiler (GCC, Clang, etc.)
- A terminal emulator with the ability to read input

# Installation
**Keep in mind you can choose if you want to use clang or gcc no matter the OS (gcc is recommended for linux and windows, clang is recommended for mac).**

Linux/Other Unix Related Systems:
```bash
    git clone https://github.com/connorakey/contactbook-c
    cd contactbook-c
    make
```

Windows:
```powershell
    git clone https://github.com/connorakey/contactbook-c
    cd contactbook-c
    gcc -o main main.c
```

MacOS:
```zsh
    git clone https://github.com/connorakey/contactbook-c
    cd contactbook-c
    make clang
```

# Created by Connor Akey
# Date: 21st of June 2025
