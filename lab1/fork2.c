#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("I am child. PID=%d Parent=%d\n",
                getpid(), getppid());
    }
    else if(pid > 0)
    {
        printf("I am parent. PID=%d Child=%d\n",
                getpid(), pid);
    }
    else
    {
        perror("fork failed");
    }

    return 0;
}
