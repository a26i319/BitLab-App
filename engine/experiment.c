#include <stdio.h>
#include <stdint.h>

int main (void){
    uint8_t number=255;
    printf("Before: %d\n ", (int)number);
    number++;
    printf("After: %d\n", (int)number);
    return 0;
}
    
