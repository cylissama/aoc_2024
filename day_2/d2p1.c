#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define LINES 1000
#define NUMS_IN_LINE 8

bool is_increasing(int nums[], int size)
{  
    for (int i = 1; i < size; i++)
    {
        if (nums[i] <= nums[i-1])
        {
            printf("\n + FALSE\n");
            return false;
        }
    }
    printf("\n+ TRUE\n");
    return true;
}

bool is_decreasing(int nums[], int size)
{  
    // start at 1, otherwise it will compare to 0 and return false 
    for (int i = 1; i < size; i++)
    {
        //printf("\n [i]: %d [i-1]: %d\n", nums[i], nums[i-1]);
        if (nums[i] >= nums[i-1])
        {
            printf("\n- FALSE\n");
            return false;
        }
    }
    printf("\n- TRUE \n");
    return true;
}

bool differs(int nums[], int size)
{
    for (int i = 0; i < size - 1; i++)
    { 
        int diff = (nums[i] - nums[i+1]);
        //printf("\n %d, %d -> %d\n", nums[i], nums[i+1], diff);
        if (diff >= 4 || diff <= -4)
        {
            //printf("\n differs %d\n", diff);
            return true;
        }
    }
    //printf("\n nodiff \n");
    return false;
}

int main(void)
{  
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        perror("error opening");
        return EXIT_FAILURE;
    }

    char line[LINES];
    int numbers[NUMS_IN_LINE];
    int safes = 0;
    
    while (fgets(line, sizeof(line), input))
    {
        // acts as numbers in array
        int count = 0;

        char *token = strtok(line, " ");
        while (token != NULL)
        {
            numbers[count++] = atoi(token);
            token = strtok(NULL, " ");
        }
        printf("\nCurrent set: ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", numbers[i]);
        }
        printf("\n");
        if (is_decreasing(numbers, count) & !differs(numbers, count))
        {
            printf("safe\n");
            safes += 1;
        }
        if(is_increasing(numbers, count) & !differs(numbers, count))
        {
            printf("safe\n");
            safes += 1;
        }
    }

    printf("Safes: %d", safes);
    
    fclose(input);

    return 0;
}