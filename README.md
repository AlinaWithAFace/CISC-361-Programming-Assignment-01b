# Programming Assignment 1b
## Unix System Calls

### Objective
The primary objective of this assignment is to practice coding with Unix system calls.

### Details
Write a program that takes two filenames on the command line as arguments and copies the first to the second by using **system calls** and no functions from the stdio library (stdio functions may be used to print messages to stdout or stderr for debugging and information purposes). If fewer than two or more than two arguments are given print a usage error message and exit. The program will copy the first file to the second (just like `cp(1)` does). The first argument (`argv[1]`) is the source file and the program should verify that it exists. If it does not exist, print an error message and exit. The second argument (`argv[2]`) is the destination file. If it does not exist, proceed to copying the file. If the destination file already exists, prompt to ask if it should be overwritten or not (like `cp -i` does) and do as the user instructs. Be sure your program works correctly for text and binary files of various sizes.

The system calls you must use for this program are `open(2)`, `read(2)`, `write(2)`, `close(2)`, `access(2)`, which are defined in `unistd.h`. 

Remember to read Section 2 man pages (`man -s 2`) of these system calls and always do error checking when using system calls. Test your program on text and binary files of various sizes.

To start, review the program (`apue.3e/intro/mycat.c`) in Fig. 1.4 of Stevens and Rago's Advanced Programming in the UNIX Environment (APUE) book to learn how to use system calls `read(2)` and `write(2)`. You may also review the program (`apue.3e/intro/ls1.c`) in APUE Fig. 1.3 to learn how to access command line arguments. Chapter 3 of APUE describes these system calls in details.

### Makefile and Submission Instructions
You should create a makefile so that when TA types `make mycp`, an executable named `mycp` is created.

You should tar up your source code and the makefile, and submit the tar file so that your program can be tested by TA. To do this, do the following.

 * In the current working directory, create a (sub-)directory named proj_1b to store all your programs and the makefile.

 * `tar cvf YourLastName_proj_1b.tar proj_1b`

To verify that your files are in the tar file, take a look at the table of contents of the tar file like:

 * `tar tvf YourLastName_proj_1b.tar`

### Use of strace

```
$> echo hello > foo 
$> cat foo 

$> strace -e trace=open,read,write,close cat foo
.......
open("foo", O_RDONLY|O_LARGEFILE) = 3  
read(3, "hello\n", 4096)          = 6  
write(1, "hello\n", 6)            = 6 
read(3, "", 4096)                 = 0 
close(3)                          = 0
.......
```