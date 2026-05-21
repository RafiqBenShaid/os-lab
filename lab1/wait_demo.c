#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Child Process Running\n");

        sleep(3);

        printf("Child Process Finished\n");
    }
    else
    {
        printf("Parent Waiting...\n");

        wait(NULL);

        printf("Parent Resumed After Child Completion\n");
    }

    return 0;
}
