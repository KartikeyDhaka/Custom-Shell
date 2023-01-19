#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void R(char fileName[1000])
{
    int result = unlink(fileName);
    if (result != 0) //deletes file
    {
        perror(fileName);
    }
}

void RD(char fileName[1000])
{
    int result = rmdir(fileName);
    if (result != 0) //deletes directory
    {
        perror(fileName);
    }
}

void RV(char fileName[1000])
{
    int result = unlink(fileName);
    if (result != 0)
    {
        perror(fileName);
    }
    else
    {
        printf("Removed file '%s'successfully \n", fileName);        
    }
}

int main(int argc, char *argv[])
{
    char command[100] = "";
    char type[10] = "";
    int value;
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
        char fileName[1000] = "";
        strcpy(fileName, pointer);
        value = strcmp(type, "");
        if (value == 0)
        {
            R(fileName);
        }
        else if (value != 0 && type[1] == 'v')
        {
            RV(fileName);
        }
        else if (value != 0 && type[1] == 'd')
        {
            RD(fileName);
        }
        else
        {
            printf("You have entered wrong command - %s\n", type);
            return 0;
        }
        pointer = strtok(NULL, " ");
    }
    return 0;
}