#include <stdio.h>

int main() {
    char c;

    printf("Enter an alphabet: ");
    scanf("%c", &c);

    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c=='U')
        printf("%c is vowel",c);
    else
     printf("%c is constant",c);
     return 0;
}

