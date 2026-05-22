#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

int parse(char *line, char **argv)
{
    int argc = 0;

    char *tok =
        strtok(line, " \t\n");

    while(tok &&
          argc < MAX_ARGS - 1)
    {
        argv[argc++] = tok;

        tok = strtok(NULL,
                     " \t\n");
    }

    argv[argc] = NULL;

    return argc;
}

int main(void)
{
    char line[MAX_LINE];

    char *argv[MAX_ARGS];

    while(1)
    {
        printf("mysh> ");

        fflush(stdout);

        if(!fgets(line,
                  sizeof(line),
                  stdin))
        {
            break;
        }

        int argc =
            parse(line, argv);

        if(argc == 0)
        {
            continue;
        }

        if(strcmp(argv[0],
                  "exit") == 0)
        {
            break;
        }

        if(strcmp(argv[0],
                  "cd") == 0)
        {
            chdir(argv[1]);

            continue;
        }

        int background = 0;

        if(argc > 0 &&
           strcmp(argv[argc-1],
                  "&") == 0)
        {
            background = 1;

            argv[argc-1] = NULL;
        }

        pid_t pid = fork();

        if(pid == 0)
        {
	    for(int i = 0; argv[i] != NULL; i++)
{
    if(strcmp(argv[i], ">") == 0)
    {
        int fd = open(
            argv[i+1],
            O_WRONLY |
            O_CREAT |
            O_TRUNC,
            0644
        );

        dup2(fd,
             STDOUT_FILENO);

        close(fd);

        argv[i] = NULL;

        break;
    }
}
            execvp(argv[0], argv);

            perror("execvp");

            exit(1);
        }
        else if(pid > 0)
        {
            if(!background)
            {
                waitpid(pid,
                        NULL,
                        0);
            }
        }
        else
        {
            perror("fork");
        }
    }

    return 0;
}
