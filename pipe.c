#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


#define READ 0
#define WRITE 1



int main(int argc, char** cmdLineArgs)
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
        close(pipe_min[READ]); // close read end

        // run a program /home/sipakhti/OS/LinkedList.c using exec

        int min = atoi(cmdLineArgs[1]);
        for (int i = 2; i < argc; i++)
        {
            if (atoi(cmdLineArgs[i]) < min)
            {
                min = atoi(cmdLineArgs[i]);
            }
        }

        write(pipe_min[WRITE], &min, sizeof(int));
        close(pipe_min[WRITE]);
        return min;
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
            close(pipe_sum[READ]); // close read end

            int sum = 0;
            for (int i = 1; i < argc; i++)
            {
                sum += atoi(cmdLineArgs[i]);
            }

            write(pipe_sum[WRITE], &sum, sizeof(int));
            close(pipe_sum[WRITE]);
            return sum;
        }
        else
        {
            close(pipe_min[WRITE]); // close write end
            close(pipe_sum[WRITE]); // close write end

            int min, sum;
            read(pipe_min[READ], &min, sizeof(int));
            read(pipe_sum[READ], &sum, sizeof(int));


            printf("MIN: %d\n", waitpid(pid_min, NULL, 0));
            printf("SUM: %d\n", waitpid(pid_sum, NULL, 0));

            printf("min = %d, sum = %d\n", min, sum);
        }
    }
}