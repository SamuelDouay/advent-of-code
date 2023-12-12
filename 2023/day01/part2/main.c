#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct Number Number;
struct Number
{
    char *string;
    int n;
};

Number n[] = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}};

int lineRead(char *line)
{
    int i = 0;
    bool found = false;
    int start;
    int end;

    while (i < sizeof n)
    {
        i++
    }

    return start * 10 + end;
}

int main()
{
    FILE *f;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    f = fopen("./exemple.txt", "r+");
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