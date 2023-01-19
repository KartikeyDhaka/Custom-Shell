#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sysexits.h>
#include <errno.h>

void Date(int a, int b)
{
    time_t timeinput = time(NULL);
    if (timeinput != -1)
    {
        struct tm *gettime;
        char ch1[a], ch2[a], ch3[b];
        gettime = localtime(&timeinput); //localtime function return the local time of the user i.e time present
        if (gettime != NULL)
        {
            strftime(ch1, a, "%a", gettime); //strftime() method returns a string representing date and time using date, time or datetime
            strftime(ch2, a, "%b", gettime);
            strftime(ch3, b, "%z", gettime);
            printf("%s %s %02d %02d:%02d:%02d %s %d\n", ch1, ch2, gettime->tm_mday, gettime->tm_hour, gettime->tm_min, gettime->tm_sec, ch3, gettime->tm_year + 1900);
        }
        else
        {
            perror("Error: ");
            return;
        }
    }
    else
    {
        perror("Error: ");
        return;
    }

}

void DateU(int a, int b)
{
    time_t timeinput = time(NULL);
    if (timeinput != -1)
    {
        struct tm *gettime;
        char ch1[a], ch2[a], ch3[b];
        gettime = gmtime(&timeinput);
        if (gettime != NULL)
        {
            strftime(ch1, a, "%a", gettime);
            strftime(ch2, a, "%b", gettime);
            strftime(ch3, b, "%z", gettime);
            printf("%s %s %02d %02d:%02d:%02d UTC %d\n", ch1, ch2, gettime->tm_mday, gettime->tm_hour, gettime->tm_min, gettime->tm_sec, gettime->tm_year + 1900);
        }
        else
        {
            perror("Error: ");
            return;
        }
    }
    else
    {
        perror("Error: ");
        return;
    }
}

int main(int argc, char *argv[])
{
    char type[10] = "";
    int value;
    char comnd[100] = "";
    char *pointer = strtok(argv[1], " ");
    strcpy(comnd, pointer);
    pointer = strtok(NULL, " ");
    if (pointer != NULL)
    {
        strcpy(type, pointer);
    }
    value = strcmp(type, "");
    if (value == 0) //Comparing type with empty string
    {
        Date(4, 6);
    }
    else if (type[1] == 'u')
    {
        DateU(4, 6);
    }
    else
    {
        printf("You have entered a wrong command - %s\n", type);
        return 1;
    }
    return 0;
}