#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isDigit(char c)
{
  return c >= '0' && c <= '9';
}

int lineRead(char *line)
{
  int i = 0;
  bool found = false;
  int start = 0;
  int end = 0;
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

char match_substr(char *subbuff)
{
  if (strcmp(subbuff, "one") == 0)
  {
    return '1';
  }
  if (strcmp(subbuff, "two") == 0)
  {
    return '2';
  }
  if (strcmp(subbuff, "three") == 0)
  {
    return '3';
  }
  if (strcmp(subbuff, "four") == 0)
  {
    return '4';
  }
  if (strcmp(subbuff, "five") == 0)
  {
    return '5';
  }
  if (strcmp(subbuff, "six") == 0)
  {
    return '6';
  }
  if (strcmp(subbuff, "seven") == 0)
  {
    return '7';
  }
  if (strcmp(subbuff, "eight") == 0)
  {
    return '8';
  }
  if (strcmp(subbuff, "nine") == 0)
  {
    return '9';
  }
  return '0';
}

char *append(const char *orig, char c)
{
  size_t sz = strlen(orig);
  char *str = malloc(sz + 2);
  strcpy(str, orig);
  str[sz] = c;
  str[sz + 1] = '\0';
  return str;
}

char *substring(char *line, int begin, int end)
{
  int length = end - begin;

  // Dynamically allocate memory for the 'world' array
  char *world = (char *)malloc((size_t)length + 1);
  // Copy the substring manually
  for (int k = 0; k < length; k++)
  {
    world[k] = line[begin + k];
  }
  world[length] = '\0';

  return world;
}

char *transformLetterToDigit(char *line)
{
  int i = 0;
  char *test = (char *)malloc(1); // Allocate memory for an empty string
  test[0] = '\0';                 // Null-terminate the string

  while (line[i] != '\0')
  {
    int j = i + 1;
    do
    {
      char *world = substring(line, i, j + 1);
      char number = match_substr(world);
      if (number != '0')
      {
        i = j;
        j = i + 1;
        test = append(test, number);
      }

      if (isDigit(world[0]))
      {
        test = append(test, world[0]);
      }
      j++;
    } while (line[j] != '\0');
    i++;
  }
  return test;
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
    char *lineR = transformLetterToDigit(line);
    total += lineRead(lineR);
    free(lineR);
  }

  fclose(f);
  if (line)
    free(line);

  printf("Total : %d\n", total);
  return 0;
}
