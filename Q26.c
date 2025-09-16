/*
============================================================================
Name : Q26.c
Author : Rishabh Dewangan
Description :Write a program to execute an executable program.
             a. use some executable program
             b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 6th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main()
{  
    char* arg[] = {"cat", "file1.txt"};
    execv("/bin/cat", arg);
    return 0;
}
/*
Output:
Hello from file1.txt
*/
