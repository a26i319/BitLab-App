
/* 
    *Project:Bitlab AI
    *Version:0.0.2
    *Description:Main CLI application
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 64


// prototype for the main function
double get_unit_factor(int unit);

double convert_storage(double value,int from_unit, int to_unit);

void storage_calculator(void);

int digit_value(char c);
int is_valid_number(const char *text, int base);
int string_length(const char *text);
int read_line(char *buffer, int capacity);
int parse_menu_choice(const char *text,
int minimum, int maximum);

void number_systems_menu(void);

int main(void){
    int choice;
    // display Application Header
    printf("================================\n");
    printf("            BITLAB AI.          \n");
    printf("Digital Systems Learning Environment\n");
    printf("          Version: 0.0.2      \n");
    printf("================================\n");

    // Display Menu Options
    printf("1. Number Systems\n");
    printf("2. Two's Complement\n");
    printf("3. Bitwise Operations\n");
    printf("4. Character Encoding\n");
    printf("5. Network Calculator\n");
    printf("6. About BitLab AI\n");
    printf("7. Storage Unit Converter\n");
    printf("0. Exit\n");
    printf("Select an option (0-7): ");
    // Receive and validate user input
    char buffer[BUFFER_SIZE];
    if (!read_line(buffer, BUFFER_SIZE) ||
        (choice = parse_menu_choice(buffer, 0, 7)) < 0) {
        printf("Invalid input. Please enter a number between 0 and 7.\n");
        return 1; // Terminate program with error
    }
    // Process selected option
    switch (choice) {
        case 1:
            number_systems_menu();
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
        case 7:
            storage_calculator();
            break;
        case 0:
            printf("Thank you for using BitLab AI!\n");
            break;
    }
    return 0;
}

double get_unit_factor(int unit)
{
    switch (unit) {
        case 1:
            return 1.0;        // Byte
        case 2:
            return 1000.0;     // Kilobyte
        case 3:
            return 1000000.0;  // Megabyte
        case 4:
            return 1000000000.0; // Gigabyte
        case 5:
            return 1000000000000.0; // Terabyte
    }

    return 0.0;
}

double convert_storage(double value,
int from_unit,int to_unit)
{
    if (!isfinite(value) || value < 0.0 ||
        value > 1000000000.0 ||
        from_unit < 1 || from_unit > 5 ||
        to_unit < 1 || to_unit > 5) {
        return 0.0;
    }

    double from_factor = get_unit_factor(from_unit);
    double to_factor = get_unit_factor(to_unit);
    double result = value * (from_factor / to_factor);

    return isfinite(result) ? result : 0.0;
}

void storage_calculator(void)
{
    double value, result;
    int from_unit, to_unit;
    const char *unit_names[] = {"", "B", "KB", "MB", "GB", "TB"};

    printf("================================\n");
    printf("     STORAGE UNIT CONVERTER\n");
    printf("================================\n");
    printf("1. B\n");
    printf("2. KB\n");
    printf("3. MB\n");
    printf("4. GB\n");
    printf("5. TB\n");
    printf("\n");
    printf("Enter storage value: ");
    if (scanf("%lf", &value) != 1) {
        printf("Invalid storage value.\n");
        return;
    }
    printf("Source unit: ");
    if (scanf("%d", &from_unit) != 1) {
        printf("Invalid source unit.\n");
        return;
    }
    printf("Target unit: ");
    if (scanf("%d", &to_unit) != 1) {
        printf("Invalid target unit.\n");
        return;
    }

    if (!isfinite(value)) {
        printf("Invalid storage value.\n");
        return;
    }
    if (value < 0.0) {
        printf("Storage value cannot be negative.\n");
        return;
    }
    if (value > 1000000000.0) {
        printf("Storage value cannot exceed 1000000000.\n");
        return;
    }
    if (from_unit < 1 || from_unit > 5) {
        printf("Invalid source unit. Choose a unit from 1 to 5.\n");
        return;
    }
    if (to_unit < 1 || to_unit > 5) {
        printf("Invalid target unit. Choose a unit from 1 to 5.\n");
        return;
    }

    result = convert_storage(value, from_unit, to_unit);

    printf("\n--------------------------------\n");
    printf("Result: %.12g %s = %.12g %s\n",
           value, unit_names[from_unit], result, unit_names[to_unit]);
    printf("--------------------------------\n");
}
/*
    Reject unsupported base
    Reject null pointer
    Reject empty string

    FOR each character until null terminator

        Convert character into digit value

        IF digit is negative
            RETURN invalid

        IF digit is greater than or equal to base
            RETURN invalid

    END FOR

    RETURN valid

END FUNCTION
*/

int digit_value(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return -1;
}

int is_valid_number(const char *text, int base)
{
    if (text == NULL || text[0] == '\0' ||
        (base != 2 && base != 8 && base != 10 && base != 16)) {
        return 0;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        int digit = digit_value(text[i]);
        if (digit < 0 || digit >= base) {
            return 0;
        }
    }
    return 1;
}
int string_length(const char *text)
{
    if (text == NULL) {
        return 0;
    }
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    return length;
}
int read_line(char *buffer, int capacity)
{
    if (buffer == NULL || capacity <= 0 || fgets(buffer, capacity, stdin) == NULL) {
        return 0;
    }

    for (int i = 0; i < capacity; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return 1;
        }
        if (buffer[i] == '\0') {
            break;
        }
    }

    int character = getchar();
    if (character == '\n' || character == EOF) {
        return 1;
    }

    while (character != '\n' && character != EOF) {
        character = getchar();
    }
    return 0;
}
int parse_menu_choice(
    const char *text,
    int minimum,
    int maximum
)
{
    if (text == NULL || text[0] == '\0' || minimum > maximum) {
        return -1;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] < '0' || text[i] > '9') {
            return -1;
        }
    }

    char *end;
    errno = 0;
    long choice = strtol(text, &end, 10);
    if (errno == ERANGE || *end != '\0' ||
        choice < minimum || choice > maximum) {
        return -1;
    }
    return (int)choice;
}
void number_systems_menu(void)
{
    char buffer[BUFFER_SIZE];
    int choice;
    int base;

    printf("================================\n");
    printf("       NUMBER SYSTEMS LAB\n");
    printf("================================\n");
    printf("1. Binary\n");
    printf("2. Octal\n");
    printf("3. Decimal\n");
    printf("4. Hexadecimal\n\n");
    printf("Select number system: ");

    if (!read_line(buffer, BUFFER_SIZE) ||
        (choice = parse_menu_choice(buffer, 1, 4)) < 0) {
        printf("Invalid selection. Please choose a number from 1 to 4.\n");
        return;
    }

    switch (choice) {
        case 1:
            base = 2;
            break;
        case 2:
            base = 8;
            break;
        case 3:
            base = 10;
            break;
        default:
            base = 16;
            break;
    }

    printf("Enter number: ");
    if (!read_line(buffer, BUFFER_SIZE)) {
        printf("Invalid number input.\n");
        return;
    }

    printf("\n--------------------------------\n");
    printf("Number: %s\n", buffer);
    printf("Base: %d\n", base);
    printf("Length: %d\n", string_length(buffer));
    printf("Status: %s\n",
           is_valid_number(buffer, base) ? "VALID" : "INVALID");
    printf("--------------------------------\n");
}