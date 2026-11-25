#include <stdio.h>

int count_binary_digits(const char *s){
    int count= 0;
    while (*s != '\0'){
        if (*s == '0' || *s == '1'){
            count++;

        }
        s++;
    }
    return count;
}
int main(void){
    char text[16];
    printf("Enter a binary string (up to 15 characters): ");
    if (scanf("%15s", text) == 1) {
        printf("Binary digits: %d\n", count_binary_digits(text));
    }

    return 0;
}
int validate_binary(const char *text)
{
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] != '0' && text[i] != '1') {
            return 0;
        }
    }

    return 1;
}