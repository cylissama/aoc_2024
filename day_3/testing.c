#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_TOKEN_LEN 12

bool is_valid(char str[], int size) {
    if (str[3] != '(' || str[size - 1] != ')') {
        return false;
    }
    // Ensure size is valid
    if (size < 7 || size > 12) {
        return false;
    }
    return true;
}

int mul_nums(char str[], int size) {
    int prod = 1;
    char *start = strchr(str, '(');
    char *end = strrchr(str, ')');

    if (start && end && start < end) {
        *end = '\0'; // Null-terminate the string at ')'
        start++;     // Move pointer past '('
    }

    char num1[4] = {0};
    char num2[4] = {0};
    int count = 0;
    int flag = 1;

    while (*start != '\0') {
        if (*start == ',') {
            flag = 2;
            start++;
            count = 0;
            continue;
        }
        if (flag == 1 && count < sizeof(num1) - 1) {
            num1[count++] = *start;
        } else if (flag == 2 && count < sizeof(num2) - 1) {
            num2[count++] = *start;
        }
        start++;
    }

    int n1 = atoi(num1);
    int n2 = atoi(num2);
    prod = n1 * n2;

    return prod;
}

int main(void) {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("ERROR OPENING FILE");
        return EXIT_FAILURE;
    }

    char line[MAX_LINES];
    int sum = 0;

    while (fgets(line, sizeof(line), input)) {
        int i = 0;
        while (line[i] != '\0') {
            if (strncmp(&line[i], "mul(", 4) == 0) { // Check for "mul("
                char cur_str[MAX_TOKEN_LEN] = {0};
                int k = 0;
                int j = i;
                while (line[j] != '\0' && k < MAX_TOKEN_LEN) {
                    cur_str[k++] = line[j++];
                    if (line[j - 1] == ')') { // Stop at ')'
                        break;
                    }
                }
                cur_str[k] = '\0'; // Null-terminate the extracted expression
                if (is_valid(cur_str, k)) {
                    sum += mul_nums(cur_str, k);
                }
                i = j; // Move the outer loop index past the current "mul(...)"
            } else {
                i++; // Move to the next character
            }
        }
    }

    fclose(input);
    printf("\nSum = %d\n", sum);
    return 0;
}