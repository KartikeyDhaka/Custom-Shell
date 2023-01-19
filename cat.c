#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> //header file for file operations
#include <errno.h>

extern int errno;

void File(char nameoffile[1000])
{
    int file = open(nameoffile, O_RDONLY); //Reading the file
    if (file >= 0)
    {
        char ch;
        int sz;
        while ((sz = read(file, &ch, 1)))
        {
            if (sz >= 0)
            {
                size_t w = write(STDIN_FILENO, &ch, 1);
                if (w < 0 && errno != EINTR)
                {
                    perror("Write to output file");
                    return;
                }
            }
            else
            {
                perror("Reading");
                return;
            }    
        }
        if (close(file) < 0)
        {
            perror("Closing");
            return;
        }
    }
    else
    {
        perror("File not Present");
        return;
    }
    return;
}

int main(int argc, char *argv[])
{
    char nameoffile[1000] = "";
    char cmnd[100] = "";
    int value;
    char type[10] = "";
    char *pointer = strtok(argv[1], " "); //strtok() Splits string according to given delimiters and returns the next token.
    strcpy(cmnd, pointer); //strcpy() copies one string to another.
    pointer = strtok(NULL, " ");
    while (pointer != NULL)
    {
        strcpy(nameoffile, pointer);
        value = strcmp(type, "");
        if (value == 0) //Comparing type with empty string
        {
            File(nameoffile);
        }
        else
        {
            printf("You have entered wrong command - %s", type);
            return 0;
        }
        pointer = strtok(NULL, " ");
    }
    if (pointer[0] == '-')
    {
        strcpy(type, pointer);
        pointer = strtok(NULL, " ");
    }
    return 0;
}