#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char** argv)
{

    pid_t pid_min, pid_sum;
    int pipe_min[2], pipe_sum[2];

    if (pipe(pipe_min) == -1 || pipe(pipe_sum) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_min = fork();
    if (pid_min < 0)
    {
        printf("fork error\n");
        exit(EXIT_FAILURE);
    }
    if (pid_min == 0) // child process for finding the min
    {
        close(pipe_min[0]); // close read end

        // run a program /home/sipakhti/OS/LinkedList.c using exec

        int min = atoi(argv[1]);
        for (int i = 2; i < argc; i++)
        {
            if (atoi(argv[i]) < min)
            {
                min = atoi(argv[i]);
            }
        }

        write(pipe_min[1], &min, sizeof(int));
        close(pipe_min[1]);
        exit(0);
    }
    else 
    {
        pid_sum = fork();
        if (pid_sum < 0)
        {
            printf("fork error\n");
            exit(EXIT_FAILURE);
        }
        if (pid_sum == 0) // child process for finding the sum
        {
            close(pipe_sum[0]); // close read end

            int sum = 0;
            for (int i = 1; i < argc; i++)
            {
                sum += atoi(argv[i]);
            }

            write(pipe_sum[1], &sum, sizeof(int));
            close(pipe_sum[1]);
            exit(0);
        }
        else
        {
            close(pipe_min[1]); // close write end
            close(pipe_sum[1]); // close write end

            int min, sum;
            read(pipe_min[0], &min, sizeof(int));
            read(pipe_sum[0], &sum, sizeof(int));

            printf("min = %d, sum = %d\n", min, sum);
        }
    }
}