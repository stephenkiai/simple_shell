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

    **exit: exits the shell (exit_builtin.c)**
    **env: prints the current environment**
    **cd: changes the current directory of the process (cd_builtin.c)**
    **setenv: initializ new env var or modifies existing 1 (setenv_builtin.c)**
    **unsetenv: removes an environment variable (unsetenv_builtin.c)**
    **alias: defines or prints aliases for commands (alias_builtin.c)**

**Features:**

    **Handles command lines with arguments**
    **Handles the PATH**
    **Does not fork if the command does not exist**
    **Handles the commands separator ;**
    **Handles the && and || logical operators**
    **Implements a custom getline function (my_getline.c)**
    **Handles variables replacement, including $? and $$**
    **Handles comments (#)**
    **Can take a file as a command line argument (file_input.c)**

**Additional Functions:**

    **panic: displays an error message and exits the program (panic.c)**
    **run_script: runs a script file (run_script.c)**
    **parse_line: parses a cmd line and returns array of tokens (parse_line.c)**
    **launch: launches an external command as a child process (launch.c)**
    **execute: executes a command line (execute.c)**
    **prompt: displays the shell prompt (prompt.c)**
    **read_line: reads a command line from input (read_line.c)**

**Authors**

    Author 1. </Stephen kiai\> -->https://github.com/stephenkiai
    Author 2. </Francis Tawai\> -->https://github.com/Twayfrancis