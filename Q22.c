/*
============================================================================
Name : Q22.c
Author : Rishabh Dewangan
Description : Open file, fork, then both parent and child write to the file.
Date: 5th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0777);

    pid_t pid = fork();

    char buf[64];
    int len = snprintf(buf, sizeof(buf), "written by process %d\n", (int)getpid());

    write(fd, buf, len);

    if (pid > 0) {
        wait(NULL);
    }

    close(fd);
    return 0;
}
