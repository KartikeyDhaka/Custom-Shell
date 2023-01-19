#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#define PATH_MAX 4096

char commands[8][10] = {"cd", "echo", "pwd", "ls", "cat", "date", "rm", "mkdir"};

static int counter = 0;
int nextLine;

void cdP(char **input_array)
{
    char newinput[1000];
    int value2;
    if (input_array[2] == NULL)
    {
        value2 = chdir(getenv("HOME")); //gets to HOME
        if (value2 == 0)
        {
            char cwd[200];
            char *cwd3 = getcwd(cwd, sizeof(cwd)); //getcwd() function copies an absolute pathname of the current working directory to the array pointed to by buf, which is of length size.
            printf("%s", cwd3);
        }
        else
        {
            perror("Error: ");            
        }
    }
    else
    {
        strcpy(newinput, input_array[2]);
        char *pt = strtok(newinput, "\n");
        char buf[PATH_MAX];
        char *res = realpath(pt, buf);
        if (res)
        {
            value2 = chdir(res); //Change to previous directory
            printf("Directory : %s\n", buf);
            printf("%s\n", res);
            if (value2 == 0)
            {
                char cwd5[200];
                char *cwd35 = getcwd(cwd5, sizeof(cwd5));
            }
            else
            {
                perror("Error: ");                
            }
        }
        else
        {
            perror("Path error:");            
        }
    }
}

void cdL(char **input_array)
{
    int value2;
    if (input_array[2] != NULL)
    {
        value2 = chdir(getenv("HOME"));
        if (value2 != 0)
        {
            char cwd[200];
            char *cwd3 = getcwd(cwd, sizeof(cwd));
            printf("%s", cwd3);
        }
        else
        {
            perror("Error: ");            
        }
    }
    else
    {
        char newinput[1000];
        strcpy(newinput, input_array[2]);
        char *pt = strtok(newinput, "\n");
        value2 = chdir(pt);
        if (value2 != 0)
        {
            char cwd[200];
            char *cwd3 = getcwd(cwd, sizeof(cwd));
            printf("%s", cwd3);
        }
        else
        {
            perror("-L Error: ");            
        }        
    }
}

void cd(char **input_array)
{
    int bits1;
    int bits2;
    int bits3;
    int bits4;
    int bits5;
    int bits6;
    int bits7;
    char newinput[1000];
    if (input_array[1] == NULL)
    {
        bits7 = 0;
    }
    else
    {
        strcpy(newinput, input_array[1]);
        //Defining commands of cd
        bits1 = strcmp(newinput, "~");
        bits2 = strcmp(newinput, "--");
        bits3 = strcmp(newinput, "-");
        bits4 = strcmp(newinput, "-P");
        bits5 = strcmp(newinput, "-L");
        bits6 = strcmp(newinput, "--help");        
    }
    if (bits3 == 0)
    {
        int flag3 = chdir("..");
        if (flag3 == 0)
        {
            char cwd2[200];
            char *cwd32 = getcwd(cwd2, sizeof(cwd2));
            printf("%s", cwd32);
        }
        else
        {
            perror("Error in command - ");
        }
    }
    else if (bits1 == 0 || bits2 == 0 || bits7 == 0)
    {
        int flaghome = chdir(getenv("HOME"));
        if (flaghome == 0)
        {
            char cwd[200];
            char *cwd3 = getcwd(cwd, sizeof(cwd));
            printf("%s", cwd3);
        }
        else
        {
            perror("Error in command - ");            
        }
    }

    else if (bits6 == 0)
    {
        printf("this command is used to change the directory to given input");
    }
    else if (bits4 == 0)
    {
        cdP(input_array);
    }
    else if (bits5 == 0)
    {
        cdL(input_array);
    }
    else
    {
        char *pt = strtok(newinput, "\n");
        int value = chdir(pt);
        if (value == 0)
        {
            char cwd[200];
            char *cwd3 = getcwd(cwd, sizeof(cwd));
            printf("%s", cwd3);
        }
        else
        {
            perror("Error: ");            
        }
    }
}

void echon(char **input_array, int size)
{
    for(int i = 2; i < size; i++)
    {
        if (input_array[i] != NULL)
        {
            printf("%s ", input_array[i]);
        }
    }
}

void echo(char **input_array, int size)
{
    int bits4 = INT_MAX;
    int bits5 = INT_MAX;
    char echo_input[10];
    if (input_array[1] == NULL)
    {
        return;
    }
    else
    {
        strcpy(echo_input, input_array[1]);
        bits4 = strcmp(echo_input, "-n");
        bits5 = strcmp(echo_input, "--help");
    }
    if (bits4 == 0)
    {
        nextLine = 1;
        echon(input_array, size);
    }
    else if (bits5 == 0)
    {
        printf("this command prints the input given after echo");
    }
    else
    {
        int i = 1;
        while (i < size)
        {
            if (input_array[i] != NULL)
            {
                printf("%s ", input_array[i]);
            }
            ++i;
        }
    }
}

void pwdP()
{
    char newarr[1000];
    char *cwd2 = getcwd(newarr, sizeof(newarr));
    printf("%s", cwd2);
}

void pwd(char **input_array)
{
    int newflag;
    char cwd_input[10];
    char arr[1000];
    int bits2 = INT_MAX;
    int bits3 = INT_MAX;

    if (input_array[1] != NULL)
    {
        strcpy(cwd_input, input_array[1]);
        newflag = 1;
    }

    char *cwd = getcwd(arr, sizeof(arr));
    if (cwd != NULL)
    {
        if (newflag != 1)
        {
            printf("%s", cwd);
        }
        else
        {
            bits2 = strcmp(cwd_input, "-P");
            bits3 = strcmp(cwd_input, "--help");
            if (bits3 == 0)
            {
                printf("this command prints the current working directory");
                exit;
            }
            else if (bits2 == 0)
            {
                pwdP();
            }            
        }
    }
    else
    {
        perror("Error: ");        
    }
}

int main()
{
    printf("Welcome User to Custom Shell SSJSS\n");
    printf("************************SSJSS SHELL STARTUP************************\n");
    char cwd[100];
    int start = 0;
    while(start < 1)
    {
        nextLine = 0;
        char command[1000];
        printf(">= ");
        scanf("%[^\n]%*c", command); //%*[^\n] scans everything until a newline as character, but doesn't scan in the newline.
        if (command[0] == 0)
        {
            printf("%s\n", "THERE WAS NO INPUT, THUS COULDN'T IMPLEMENT ANYTHING");
        }
        else
        {
            int size = 0;
            char func[10];
            int func_no;
            char new_command[1000];
            char **input_array = (char **)malloc(500 * sizeof(char *));
            strcpy(new_command, command);
            char *token = strtok(command, " ");
            while (token != NULL)
            {
                input_array[size] = (char *)malloc(500 * sizeof(char));
                strcpy(input_array[size], token);
                token = strtok(NULL, " ");
                size++;
            }
            for(int i = 0; i < 8; i++)
            {
                int ctr = 0;
                int flag = 0;
                while (commands[i][ctr] != '\0' && input_array[0][ctr] != '\0')
                {
                    if (commands[i][ctr] != input_array[0][ctr])
                    {
                        flag = 1;
                        break;
                    }
                    ctr++;
                }
                if (commands[i][ctr] != '\0' || input_array[0][ctr] != '\0')
                {
                    flag = 1;
                }
                if (flag != 1)
                {
                    func_no = i;
                    break;
                }
            }
            if (func_no == 0)
            {
                cd(input_array);
            }
            else if (func_no == 1)
            {
                echo(input_array, size);
            }
            else if (func_no == 2)
            {
                pwd(input_array);
            }
            else if (func_no == 3)
            {
                pid_t id;
                int stat;
                int value = (id = fork());
                if (value == 0)
                {
                    char *args[] = {"./ls", new_command, NULL};
                    execvp("./ls", args);
                    exit(0);
                }
                else
                {
                    pid_t time = wait(&stat);
                }
            }
            else if (func_no == 4)
            {
                pid_t id;
                int stat;
                int value = (id = fork());
                if (value == 0)
                {
                    char *args[] = {"./cat", new_command, NULL};
                    execvp("./cat", args);
                    exit(0);
                }
                else
                {
                    pid_t time = wait(&stat);
                }
            }
            else if (func_no == 5)
            {
                pid_t id;
                int stat;
                int value = (id = fork());
                if (value == 0)
                {
                    char *args[] = {"./date", new_command, NULL};
                    execvp("./date", args);
                    exit(0);
                }
                else
                {
                    pid_t time = wait(&stat);
                }
            }
            else if (func_no == 6)
            {
                pid_t id;
                int stat;
                int value = (id = fork());
                if (value == 0)
                {
                    char *args[] = {"./rm", new_command, NULL};
                    execvp("./rm", args);
                    exit(0);
                }
                else
                {
                    pid_t time = wait(&stat);
                }
            }
            else if (func_no == 7)
            {
                pid_t id;
                int stat;
                int value = (id = fork());
                if (value == 0)
                {
                    char *args[] = {"./mkdir", new_command, NULL};
                    execvp("./mkdir", args);
                    exit(0);
                }
                else
                {
                    pid_t time = wait(&stat);
                }
            }
            else
            {
                printf("Unrecognised Command: ");
            }
            if (nextLine == 0)
            {
                printf("\n");
            }
        }
    }
    return 0;
}