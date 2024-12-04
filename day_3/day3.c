#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// tryed: 118914004, too low!
#define MAX_LINES 1000
#define MAX_TOKEN_LEN 12

bool is_valid(char str[], int size) {
    for (int i=0;i<size;i++) {
        printf("%c",str[i]);
    }
    if (str[3] != '('){
        return false;
    }
    if (str[size - 1] != ')')
    {
        return false;
    }
    switch (size) {
        case 7: // the 7th index mul(x,y)
            printf("\n7:  ");
            for (int i=0;i<size;i++) {
                printf("%c",str[i]);
            }
            return true;
            break;
        case 8: // the 8th index mul(xx,y) or mul(x,yy)
            printf("\n8: ");
            for (int i=0;i<size;i++) {
                printf("%c",str[i]);
            }
            return true;
            break;
        case 9: // the 9th index mul(xx,yy) or mul(xx,yy) or mul(xxx,y) or mul(x,yyy)
            printf("\n9: ");
            for (int i=0;i<size;i++) {
                printf("%c",str[i]);
            }
            return true;
            break;
        case 10: // the 10th index is mul(xxx,yy) or mul(xx,yyy)
            printf("\n10: ");
            for (int i=0;i<size;i++) {
                printf("%c",str[i]);
            }
            return true;
            break;
        case 11: // the 11th index is mul(xxx,yyy)
            printf("\n11: ");
            for (int i=0;i<size;i++) {
                printf("%c",str[i]);
            }
            return true;
            break;
        case 12: // the 12th index is mul(xxx,yyy)
            printf("\n12: ");
            for (int i=0;i<size;i++) {
                printf("%c",str[i]);
            }
            return true;
            break;
        default:
            printf("\nBAD STRING: ");
            for (int i=0;i<size;i++) {
                printf("%c",str[i]);
            }
            return false;
    }
    return true;
}

int mul_nums(char str[], int size) {
    int prod=1;
    //char trimmed[MAX_TOKEN_LEN];
    //remove the before ( and after )
    char *start = strchr(str, '(');  // Find the first '('
    char *end = strrchr(str, ')');  // Find the last ')'

    if (start && end && start < end) {
        *end = '\0';
        start++;
        //printf("Trimmed string: %c ", *start);
    }
    int count = 0;
    char num1[4] = {0};
    char num2[4] = {0};
    int flag = 1;
    while(*start != ')' && *start != '\0') {
        if (*start == ','){
            flag=2;
            start++;
            count=0;
            continue;
        }
        if (flag==1) {
            num1[count]=*start;
            //printf("%c-",num1[count]);
        } else if (flag==2) {
            num2[count]=*start;
            //printf("%c-",num2[count]);
        }
        //trimmed[count] = *start;
        start++;
        count++;
    }
    int i=0;
    while(num1[i]!='\0') {
        //printf("%c",num1[i]);
        i++;
    }
    //convert the strings to ints
    int n1 = atoi(num1);
    int n2 = atoi(num2);

    prod = n1 * n2;
    printf("\n%d * %d = %d",n1,n2,prod);
    return prod;
}

int main(void) {

    FILE *input = fopen("input.txt", "r");
    if(input == NULL) {
        printf("ERROR OPENING FILE");
        return EXIT_FAILURE;
    }

    char line[MAX_LINES];
    int sum = 0;
    int cur_str_size = 0;

    while(fgets(line, sizeof(line), input)) {
        for (int i=0; line[i] != '\0'; i++) { // i is char in line
            if (line[i] == 'm') {
                printf("\n%c -> %d",line[i], i);
                char cur_str[MAX_TOKEN_LEN];
                int k = 0;
                for (int j=i; j<MAX_TOKEN_LEN + i && line[j] != '\0';j++) { // j is where the m is
                    cur_str[k++] = line[j]; // k indexes cur_str
                    cur_str_size = k;
                    if (line[j]==')') { // checks for end of expression
                        printf("\n");
                        for(int i=0;i<cur_str_size;i++){
                            printf("%c",cur_str[i]);
                        }
                        printf("\n");
                        break;
                    }
                }
                if (is_valid(cur_str, k)) {
                    printf(" true ");
                    sum += mul_nums(cur_str, k);
                }
            }
        }
    }
    printf("\nSum = %d",sum);
    return 0;
}