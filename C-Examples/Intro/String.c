// Simple string IO (array of char)
//   gcc -o string string.c

#include "stdio.h"
#include "string.h"

void readString(char *s) {

    printf("Enter a string: ");
    scanf("%s", s);

    printf("FOUND: %s\n",s);
}

int main() {
    char s[32];

    readString(s);

    printf("The string you entered is %s\n", s);

    return 0;
}
