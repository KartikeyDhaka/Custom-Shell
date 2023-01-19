#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void Ls(char arg[1000])
{
    struct dirent **names;
    int n;
    if (strlen(arg) != 0)
    {
        n = scandir(arg, &names, NULL, alphasort);  //scans directory
    }
    else
    {
        n = scandir(".", &names, NULL, alphasort);        
    }
    int i = 0;
    if (n >= 0)
    {
        while (i < n)
        {
            if (names[i]->d_name[0] != '.')
            {
                printf("%s ", names[i]->d_name);
                free(names[i++]);  
            }
            else
            {
                free(names[i++]);
                continue;
            }                      
        }
        printf("\n");
        free(names);
    }
    else
    {
        perror("Scan directory: ");        
    }
}

void LsA(char arg[1000])
{
    struct dirent **names;
    int n;
    if (strlen(arg) != 0)
    {
        n = scandir(arg, &names, NULL, alphasort);
    }
    else
    {
        n = scandir(".", &names, NULL, alphasort);        
    }
    int i = 0;
    if (n >= 0)
    {        
        while (i < n)
        {
            printf("%s ", names[i]->d_name);
            free(names[i++]);
        }
        printf("\n");
        free(names);
    }
    else
    {
        perror("Scan directory: ");        
    }
}

int main(int argc, char *argv[])
{
    char command[100] = "";
    char type[10] = "";
    int value;
    char arg[1000] = "";
    if (argc > 1)
    {
        char *pointer = strtok(argv[1], " ");
        strcpy(command, pointer);
        pointer = strtok(NULL, " ");
        if (pointer != NULL)
        {
            if (pointer[0] != '-')
            {
                strcpy(arg, pointer);
            }
            else
            {
                strcpy(type, pointer);
                pointer = strtok(NULL, " ");
                if (pointer != NULL)
                {
                    strcpy(arg, pointer);
                }
            }
        }
    }
    value = strcmp(type, "");
    if (value == 0)
    {
        Ls(arg);
    }
    else if (type[1] == 'a')
    {
        LsA(arg);
    }
    else
    {
        printf("You have entered wrong command - %s\n", type);
        return 1;
    }
    return 0;
}