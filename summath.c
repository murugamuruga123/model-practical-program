#include <stdio.h>
#include <math.h>

// Function to compute sum of digits for a 5-digit number
void sum_of_digits(int num, int *p_sum) {
    int sum = 0;
    int i;
	for ( i = 4; i >= 0; i--) {
        int divisor = (int)pow(10, i);
        int digit = num / divisor;
        sum += digit;
        num = num % divisor;
    }
    *p_sum = sum;
}

int main() {
    int num;
    int result;
    int status;

    while (1) {
        printf("Enter a 5-digit number: ");
        status = scanf("%d", &num);
        if (status != 1) {
            // input was not a valid integer
            printf("error: Invalid input! Please enter a 5-digit number.\n");
            // clear rest of line from input buffer
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            continue;
        }
        // Now check valid range
        if (num < 10000 || num > 99999) {
            printf("error: Invalid input! Please enter a 5-digit number.\n");
            // no need to clear buffer here because number was consumed
            continue;
        }
        // If we reach here, input is valid
        break;
    }

    sum_of_digits(num, &result);
    printf("Sum of digits: %d\n", result);

    return 0;
}
