**SIMPLE SHELL**

A simple **UNIX command line interpreter** that can handle basic **command execution**,
**environment variables**, **built-in commands**, and **logical operators**.
Usage

**To use the shell, simply run the executable simple_shell**.

The shell displays a **prompt** and waits for the user to type a command. A command
line always ends with a new line. The prompt is displayed again each time a
command has been executed. The command lines are simple, made only of one word.
No arguments will be passed to programs.

If an **executable** cannot be found, the shell prints an error message and displays
the prompt again. The shell **handles errors** and the **“end of file”** condition
**(Ctrl+D)**.

**Built-in Commands**

The shell implements the following built-in commands:

    **exit: exits the shell**
    **env: prints the current environment**
    **cd: changes the current directory of the process**
    **setenv: initializes a new environment variable or modifies an existing one**
    **unsetenv: removes an environment variable**
    **alias: defines or prints aliases for commands**

**Features**

    **Handles command lines with arguments**
    **Handles the PATH**
    **Does not fork if the command does not exist**
    **Handles the commands separator ;**
    **Handles the && and || logical operators**
    **Implements a custom getline function**
    **Handles variables replacement, including $? and $$**
    **Handles comments (#)**
    **Can take a file as a command line argument**

Authors

    Author 1. </Stephen kiai\>
    Author 2. </Francis Tawai\> 