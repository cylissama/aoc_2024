#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_LINES 100
#define MAX_TOKEN_LEN 12

bool is_valid(char str[], int size) {
    // check if 4th char is a '('
    // followed by 1-3 numbers
    // then a ','
    // then 1=3 numbers
    // then a ')'


    // printf("\n");
    // for (int i=0; i<size;i++) {
    //     printf("%c",str[i]);
    // }
    return true;
}

int main(void) {

    FILE *input = fopen("input.txt", "r");
    if(input == NULL) {
        printf("ERROR OPENING FILE");
        return EXIT_FAILURE;
    }

    char line[MAX_LINES];
    int sum = 0;

    while(fgets(line, sizeof(line), input)) {
        for (int i=0; line[i] != '\0'; i++) {
            if (line[i] == 'm') {
                printf("\n");
                char cur_str[MAX_TOKEN_LEN];
                int k = 0;
                bool valid = false;
                for (int j=i; j<MAX_TOKEN_LEN + i && line[j] != '\0';j++) {
                    cur_str[k++] = line[j];
                    valid = is_valid(cur_str, MAX_TOKEN_LEN);
                    printf("%c",line[j]);
                }
            }
        }
    }

    return 0;
}