#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[3];
    char c;

    s[1] = 'b';
    s[0] = 'a';
    s[2] = 'c';
    printf("%s", s);
    return (0);
}