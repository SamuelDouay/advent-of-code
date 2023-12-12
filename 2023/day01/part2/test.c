// Online C compiler to run C program online
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

char match_substr(char *subbuff) {
  if (strcmp(subbuff, "one") == 0) {
    return '1';
  }
  if (strcmp(subbuff, "two") == 0) {
    return '2';
  }
  if (strcmp(subbuff, "three") == 0) {
    return '3';
  }
  if (strcmp(subbuff, "four") == 0) {
    return '4';
  }
  if (strcmp(subbuff, "five") == 0) {
    return '5';
  }
  if (strcmp(subbuff, "six") == 0) {
    return '6';
  }
  if (strcmp(subbuff, "seven") == 0) {
    return '7';
  }
  if (strcmp(subbuff, "eight") == 0) {
    return '8';
  }
  if (strcmp(subbuff, "nine") == 0) {
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

char * transformLetterToDigit(char * line) {
  int i = 0;
  int j = 0;
  char res[20] = "";
  char *test;

  while(line[i] != '\0') {
    int j = i + 1;
    char world[10];
    while(line[j] != '\0') {
      strncpy(world, line + i, j);
      char number = match_substr(world);
      if (number != '0') {
        i = j;
        j = i + 1;
        printf("res=%s\n", res);
        strcat(res, &number);
      }
      j++;
    }
    i++;
  }
  return "test";
}

int main() {    
    int nb1 = lineRead("a1b2c3d4e5f");
    int nb2 = lineRead("treb7uchet");
    printf("Step 1 - nb1 : %d, nb2 : %d\n", nb1, nb2);
    
    int l1 = lineRead("two1nine");
    printf("Step 2 - l1 : %d\n", l1);

    char *st1 = transformLetterToDigit("two1nine");
    printf("Step 2 - st1 : %d\n", lineRead(st1));
    return 0;
}