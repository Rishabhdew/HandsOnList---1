/*
============================================================================
Name : 07.c
Author : Rishabh Dewangan
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 27th Aug, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    char buffer[1024];
    ssize_t nread;

    int sourceFD = open(argv[1], O_RDONLY);
    if (sourceFD == -1) {
        perror("open(source)");
        return 1;
    }

    int destinationFD = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (destinationFD == -1) {
        perror("open(destination)");
        close(sourceFD);
        return 1;
    }

    while ((nread = read(sourceFD, buffer, sizeof(buffer))) > 0) {
        ssize_t written = 0;
        while (written < nread) {
            ssize_t w = write(destinationFD, buffer + written, nread - written);
            if (w == -1) {
                perror("write");
                close(sourceFD);
                close(destinationFD);
                return 1;
            }
            written += w;
        }
    }

    if (nread == -1) {
        perror("read");
    } else {
        printf("Successfully copied '%s' -> '%s'\n", argv[1], argv[2]);
    }

    close(sourceFD);
    close(destinationFD);
    return 0;
}
