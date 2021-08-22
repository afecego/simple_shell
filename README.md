# 0x16. C - Simple Shell

***

## DESCRIPTION

This project challenged us to recreates our own shell

### Learning Objectives

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?

***

## REQUIREMENTS

### General

* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to

### Compilation

Your shell will be compiled this way:

~~~
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
~~~

### Output

* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

Example of error with sh:

~~~
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
~~~

Same error with your program hsh:

~~~
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
~~~

***

### Testing

Your shell should work like this in interactive mode:

~~~
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
~~~
But also in non interactive mode
~~~
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
~~~

***

### Tasks

#### 0. README, man, AUTHORS

* Write a README
* Write a man for your shell.
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

#### 1. Betty would be proud

* Write a beautiful code that passes the Betty checks

#### 2. Simple shell 0.1

* Write a UNIX command line interpreter

#### Simple shell 0.2

* Handle command lines with arguments

#### 4. Simple shell 0.3

* Handle the PATH
* fork must not be called if the command doesn’t exist

#### 5. Simple shell 0.4

* Implement the exit built-in, that exits the shell
* Usage: exit
* You don’t have to handle any argument to the built-in exit

#### 6. Simple shell 1.0

* Implement the env built-in, that prints the current environment

#### 7. What happens when you type `ls -l *.c` in the shell

* Check the post here: "link"