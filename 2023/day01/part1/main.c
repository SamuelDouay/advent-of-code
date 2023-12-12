#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int lineRead(char *line)
{
    int i = 0;
    bool found = false;
    int start;
    int end;
    while (line[i] != '\0')
    {
        if (isDigit(line[i]))
        {
            if (!found)
            {
                start = line[i] - '0';
                found = true;
            }
            end = line[i] - '0';
        }
        i++;
    }
    return start * 10 + end;
}

int main()
{
    FILE *f;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    f = fopen("./input.txt", "r+");
    if (f == NULL)
        exit(EXIT_FAILURE);

    int total = 0;
    while ((read = getline(&line, &len, f)) != -1)
    {
        total += lineRead(line);
    }

    fclose(f);
    if (line)
        free(line);

    printf("Total : %d\n", total);
    return 0;
}