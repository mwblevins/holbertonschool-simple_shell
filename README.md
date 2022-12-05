# <center> Rebuilding a Simple Shell Project for Holberton

## <center> Learning Objective

The goals/functionality/restrictions of this project for our *sh* (i.e. *hsh*) were as follows:
- Use the prototype: *int _printf(const char *format, ...);*
- Written in vi, vim, or emacs
- Have no memory leaks
- Must be betty compliant
- Equal output as `sh` (`/bin/sh`) as well as the exact same error output.
- With exception to printing an error, wherein the name of the program must be equivalent to `argv[0]`
- compiled with the following `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## <center>Fucntionality
The user should be able to utilize it in an interactive or non-interactive mode. Running *./hsh* in terminal will open a prompt that the user can call functions from. ie:

    ./hsh
    ($) cat "file"
    [prints contents of "file" to stdout]
    ($) exit
    

Either piping in commands or executing them with *./hsh* will executes the commands without opening the prompt and keeps you in your linux terminal. For example:

Both

    cat "file" | ./hsh

and

   `./hsh cat "file"` 

Will display the contents of "file" to stdout. 

## Authors and Contributors
Taylor Poczynek
Michael Blevins

