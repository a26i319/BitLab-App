
/* 
    *Project:Bitlab AI
    *Version:0.0.1
    *Description:Main CLI application
*/

#include <stdio.h>
int main(void){
    int choice;
    // TODO1 : Display the menu and get user input
    printf("================================\n");
    printf("            BITLAB AI.          \n");
    printf("Digital Systems Learning Environment\n");
    printf("          Version: 0.0.1      \n");
    printf("================================\n");

    // TODO2 : Display the menu options
    printf("1. Number Systems\n");
    printf("2. Two's Complement\n");
    printf("3. Bitwise Operations\n");
    printf("4. Character Encoding\n");
    printf("5. Network Calculator\n");
    printf("6. About BitLab AI\n");
    printf("0. Exit\n");
    // TODO3 : Receive and validate user input
    if (scanf("%d", &choice) != 1 || choice < 0 || choice > 6) {
        printf("Invalid input. Please enter a number between 0 and 6.\n");
        return 1; // Terminate program with error
    }
    // TODO4 : Implement switch-case
    switch (choice) {
        case 1:
            printf("====Number Systems====\n");
            // Call function to display number systems
            break;
        case 2:
            printf("====Two's Complement====\n");
            // Call function to display two's complement
            break;
        case 3:
            printf("====Bitwise Operations====\n");
            // Call function to display bitwise operations
            break;
        case 4:
            printf("====Character Encoding====\n");
            // Call function to display character encoding
            break;
        case 5:
            printf("====Network Calculator====\n");
            // Call function to display network calculator
            break;
        case 6:
            printf("About this BitLab AI is a digital systems learning environment.\n");
            // Call function to display application information
            break;
        case 0:
            printf("Thank you for using BitLab AI!\n");
            break;
        default:
            printf("Invalid option. Please select from 1 to 6.\n");
    }
    return 0;
}