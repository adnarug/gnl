#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void adding_world(char **s);
void passing_string(char **s);


int main ()
{
    char *s;
    s = NULL;
    passing_string(&s);
    printf ("This is the string %s", s);
}

void passing_string(char **s)
{   
    *s = malloc (sizeof(char) *  7);
    strcpy(*s, "hello");
    adding_world(s);
}

void adding_world(char **s)
{
    strcpy(*s," world");
}