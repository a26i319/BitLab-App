
/* 
    *Project:Bitlab AI
    *Version:0.0.2
    *Description:Main CLI application
*/

#include <stdio.h>
#include <math.h>

// prototype for the main function
double get_unit_factor(int unit);

double convert_storage(double value,int from_unit, int to_unit);

void storage_calculator(void);

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
    if (scanf("%d", &choice) != 1 || choice < 0 || choice > 7) {
        printf("Invalid input. Please enter a number between 0 and 7.\n");
        return 1; // Terminate program with error
    }
    // Process selected option
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
