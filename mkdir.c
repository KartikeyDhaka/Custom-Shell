#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void Directory(char file[1000])
{
    int check;
    struct stat st = {0};
    if (stat(file, &st) == -1) 
    {
        check = mkdir(file, 0700); //creates a new, empty directory with name file
    }
    if (check == -1)
    {
        perror(file);
    }
}

void DirectoryV(char file[1000])
{
    int check;
    struct stat st = {0};
    if (stat(file, &st) == -1) 
    {
        check = mkdir(file, 0700);
    }
    if (check == -1)
    {
        perror(file);
    }
    else
    {
        printf("Created a directory - '%s'\n", file);
    }
}

int main(int argc, char *argv[])
{
    char command[100] = "";
    int value;
    char type[10] = "";
    char *pointer = strtok(argv[1], " ");
    strcpy(command, pointer);
    pointer = strtok(NULL, " ");
    if (pointer[0] == '-')
    {
        strcpy(type, pointer);
        pointer = strtok(NULL, " ");
    }
    while (pointer != NULL)
    {
        char file[1000] = "";
        strcpy(file, pointer);
        value = strcmp(type, "");
        if (value == 0)
        {
            Directory(file);
        }
        else
        {
            if (type[1] == 'v')
            {
                DirectoryV(file);
            }
            else
            {
                printf("You have entered wrong command - %s\n", type);
                return 1;
            }
        }
        pointer = strtok(NULL, " ");
    }
    return 0;
}