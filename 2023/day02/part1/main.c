#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char *substring(char *line, int begin, int end)
{
    int length = end - begin;
    char *world = (char *)malloc((size_t)length + 1);
    for (int k = 0; k < length; k++)
    {
        world[k] = line[begin + k];
    }
    world[length] = '\0';

    return world;
}

int numberGame(char *game)
{

    char *nb = strtok(game, " ");
    while (nb != NULL)
    {
        if (nb[0] != 'G')
        {
            return atoi(nb);
        }
        nb = strtok(NULL, " ");
    }

    return 0;
}

int checkGames(char *game)
{
    char *partie = strtok(game, ";");
    while (partie != NULL)
    {

        partie = strtok(NULL, ";");
    }

    return 0;
}

int lineRead(char *line)
{
    char *game = strtok(line, ":");
    int nbGame = 0;
    int isPossible = 0;
    while (game != NULL)
    {
        if (game[0] == 'G')
        {
            nbGame = numberGame(game);
        }
        else
        {
            isPossible = checkGames(game);
        }
        game = strtok(NULL, ":");
    }
    return nbGame;
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