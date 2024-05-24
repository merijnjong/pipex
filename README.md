# pipex
Write a program in C that mimics the usage of UNIX mechanisms with system calls only.
Program name | pipex |
|:--- |:---
Turn in files | [Makefile](https://github.com/merijnjong/pipex/blob/main/Makefile), [pipex.h](https://github.com/merijnjong/pipex/blob/main/pipex.h), [pipex.c](https://github.com/merijnjong/pipex/blob/main/pipex.c), [pipex_utils.c](https://github.com/merijnjong/pipex/blob/main/pipex_utils.c) |
Makefile | NAME, all, clean, fclean, re |
Arguments | file1 cmd1 cmd2 file2 |
External functions | • open, close, read, write, malloc, free, perror, strerror, access, dup, dup2,<br />&nbsp; &nbsp; execve, exit, fork, pipe, unlink, wait, waitpid<br />• ft_printf and any equivalent YOU coded |
Libft authorized | Yes |

### Instructions
Your program will be executed as follows:<br />
&nbsp;&nbsp;&nbsp;&nbsp;./pipex file1 cmd1 cmd2 file2<br />

It must take 4 arguments:<br />
* file1 and file2 are file names.
* cmd1 and cmd2 are shell commands with their parameters.

### Examples

### Requirements
Your project must comply with the following rules:
* You have to turn in a Makefile which will compile your source files. It must not
relink.
* You have to handle errors thoroughly. In no way your program should quit unexpectedly<br />(segmentation fault, bus error, double free, and so forth).
* Your program mustn’t have memory leaks.
* If you have any doubt, handle the errors like the shell command:<br />
&nbsp;&nbsp;&nbsp;&nbsp;< file1 cmd1 | cmd2 > file2
