/*
============================================================================
Name : 08.c
Author : Rishabh Dewangan
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 28th Aug, 2025.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>    
#include <unistd.h>    
#include <stdio.h>    

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int sourceFD = open(argv[1], O_RDONLY);
    if (sourceFD == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1];
    int readByte;

    while ((readByte = read(sourceFD, buffer, 1)) > 0) {
        if (buffer[0] == '\n') {
            
            continue;
        }
        write(STDOUT_FILENO, buffer, readByte);
    }

    if (readByte == -1) {
        perror("Error reading file");
    }

    close(sourceFD);
    return 0;
}


