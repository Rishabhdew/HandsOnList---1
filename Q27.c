/*
============================================================================
Name : Q27.c
Author : Rishabh Dewangan
Description : Demonstrate various exec*() calls for "ls -Rl".
Date: 5th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
    char *path = "/bin/ls";

    /* a) execl */
    execl(path, "ls", "-Rl", NULL);

    /* b) execlp */
    execlp("ls", "ls", "-Rl", NULL);

    /* c) execle (pass envp) */
    execle(path, "ls", "-Rl", "27c_example/", NULL, envp);

    /* d) execv */
    {
        char *argvv[] = { "ls", "-Rl", NULL };
        execv(path, argvv);
    }

    /* e) execvp */
    {
        char *argvp[] = { "ls", "-Rl", NULL };
        execvp("ls", argvp);
    }

    perror("All exec attempts failed");
    return 1;
}
/*
total 247
drwxrwxrwx 1 rish rish   512 Sep  7 09:29 27c_example
-rwxrwxrwx 1 rish rish  1241 Sep  6 12:56 Q10.c
-rwxrwxrwx 1 rish rish   946 Sep  6 12:58 Q11.c
-rwxrwxrwx 1 rish rish    24 Sep  6 12:58 Q11sample.txt
-rwxrwxrwx 1 rish rish   968 Sep  6 13:00 Q12.c
-rwxrwxrwx 1 rish rish   944 Sep  6 13:00 Q13.c
-rwxrwxrwx 1 rish rish  1600 Sep  6 13:05 Q14.c
-rwxrwxrwx 1 rish rish  3796 Sep  6 16:26 Q15.c
-rwxrwxrwx 1 rish rish   927 Sep  6 13:10 Q16a.c
-rwxrwxrwx 1 rish rish   925 Sep  6 13:13 Q16b.c
-rwxrwxrwx 1 rish rish  1137 Sep  6 13:14 Q17a.c
-rwxrwxrwx 1 rish rish  1518 Sep  6 13:17 Q17b.c
-rwxrwxrwx 1 rish rish   974 Sep  6 13:19 Q18.c
-rwxrwxrwx 1 rish rish  1374 Sep  6 13:22 Q18a.c
-rwxrwxrwx 1 rish rish  1360 Sep  6 13:25 Q18b.c
-rwxrwxrwx 1 rish rish   773 Sep  6 13:27 Q19.c
-rwxrwxrwx 1 rish rish   826 Sep  6 18:28 Q1_a.c
-rwxrwxrwx 1 rish rish   738 Sep  6 19:47 Q1_b.c
-rwxrwxrwx 1 rish rish  1125 Sep  6 18:32 Q1_c.c
-rwxrwxrwx 1 rish rish   254 Sep  6 19:48 Q1_shell.sh
-rwxrwxrwx 1 rish rish   452 Sep  6 18:36 Q2.c
-rwxrwxrwx 1 rish rish   872 Sep  6 13:28 Q20.c
-rwxrwxrwx 1 rish rish   593 Sep  6 13:29 Q21.c
-rwxrwxrwx 1 rish rish   775 Sep  6 17:41 Q22.c
-rwxrwxrwx 1 rish rish   192 Sep  6 13:30 Q22Output.txt
-rwxrwxrwx 1 rish rish   780 Sep  6 13:32 Q23.c
-rwxrwxrwx 1 rish rish   729 Sep  6 13:33 Q24.c
-rwxrwxrwx 1 rish rish   599 Sep  6 13:34 Q25.c
-rwxrwxrwx 1 rish rish   620 Sep  6 13:36 Q26.c
-rwxrwxrwx 1 rish rish   878 Sep  7 09:28 Q27.c
-rwxrwxrwx 1 rish rish  1530 Sep  7 09:29 Q27_test.c
-rwxrwxrwx 1 rish rish  1075 Sep  6 19:06 Q28.c
-rwxrwxrwx 1 rish rish  2518 Sep  6 19:57 Q29.c
-rwxrwxrwx 1 rish rish 15784 Sep  7 06:50 Q2txt
-rwxrwxrwx 1 rish rish  1003 Sep  6 18:37 Q3.c
-rwxrwxrwx 1 rish rish 16048 Sep  7 06:56 Q3.out
-rwxrwxrwx 1 rish rish  1036 Sep  6 19:21 Q30.c
-rwxrwxrwx 1 rish rish   803 Sep  6 19:49 Q4.c
-rwxrwxrwx 1 rish rish 16040 Sep  7 07:01 Q4.out
-rwxrwxrwx 1 rish rish 16088 Sep  7 07:09 Q5
-rwxrwxrwx 1 rish rish   909 Sep  6 19:49 Q5.c
-rwxrwxrwx 1 rish rish     0 Sep  7 07:13 Q5.test1.txt
-rwxrwxrwx 1 rish rish     0 Sep  7 07:13 Q5.test2.txt
-rwxrwxrwx 1 rish rish     0 Sep  7 07:14 Q5.test3.txt
-rwxrwxrwx 1 rish rish     0 Sep  7 07:14 Q5.test4.txt
-rwxrwxrwx 1 rish rish     0 Sep  7 07:14 Q5.test5.txt
-rwxrwxrwx 1 rish rish 16096 Sep  7 07:19 Q6
-rwxrwxrwx 1 rish rish   719 Sep  6 19:51 Q6.c
-rwxrwxrwx 1 rish rish  1561 Sep  7 07:23 Q7.c
-rwxrwxrwx 1 rish rish    18 Sep  7 07:25 Q7.dest.txt
-rwxrwxrwx 1 rish rish 16288 Sep  7 07:25 Q7.out
-rwxrwxrwx 1 rish rish    18 Sep  7 07:25 Q7.source.txt
-rwxrwxrwx 1 rish rish 16264 Sep  7 07:30 Q8
-rwxrwxrwx 1 rish rish  1107 Sep  6 18:56 Q8.c
-rwxrwxrwx 1 rish rish    23 Sep  7 07:30 Q8_output.txt
-rwxrwxrwx 1 rish rish  1661 Sep  6 19:00 Q9.c
*/