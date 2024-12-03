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
            //printf("\n + FALSE\n");
            return false;
        }
    }
    //printf("\n+ TRUE\n");
    return true;
}

bool is_decreasing(int nums[], int size)
{  
    // start at 1, otherwise it will compare to 0 and return false 
    for (int i = 1; i < size; i++)
    {
        if (nums[i] >= nums[i-1])
        {
            //printf("\n- FALSE\n");
            return false;
        }
    }
    //printf("\n- TRUE \n");
    return true;
}

bool differs(int nums[], int size)
{
    for (int i = 0; i < size - 1; i++)
    { 
        int diff = (nums[i] - nums[i+1]);
        if (diff >= 4 || diff <= -4)
        {
            return true;
        }
    }
    return false;
}

int remove_level(int* nums, int* count, int index, bool* success)
{
    if (index < 0 || index >= *count) 
    {
        *success = false;
        return 0;
    }

    *success = true;
    int removedNumber = nums[index];

    for (int i = index; i < *count - 1; i++)
    {
        nums[i] = nums[i+1];
    }

    (*count)--;
    return removedNumber;
}

bool perform_checks(int numbers[], int count)
{
    bool is_safe = false;
    for (int i = 0; i<count;i++)
    {
        //printf("%d ", numbers[i]);
    }
    //printf("Count = %d", count);
    if (is_decreasing(numbers, count) & !differs(numbers, count))
    {
        //printf("safe\n");
        is_safe = true;
        return is_safe;
    }
    if(is_increasing(numbers, count) & !differs(numbers, count))
    {
        //printf("safe\n");
        is_safe = true;
        return is_safe;
    }
    //printf("The value of flag is: %s\n", is_safe ? "true" : "false");
    return is_safe;
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
    
    int count;

    while (fgets(line, sizeof(line), input))
    {
        // acts as numbers in array
        count = 0;

        char *token = strtok(line, " ");
        while (token != NULL)
        {
            numbers[count++] = atoi(token);
            token = strtok(NULL, " ");
        }
        //printf("\nCurrent set: ");
        for (int i = 0; i < count; i++)
        {
            //printf("%d ", numbers[i]);
        }
        //printf("\n");

        // do checks to see if safe
        if (perform_checks(numbers, count))
        {
            safes += 1;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                // print original array
                //printf("\nREFERENCE: ");
                for (int i = 0; i < count; i++) {
                    //printf("%d ", numbers[i]);
                }

                count += 1;
                bool success = false;
                int dummy[count];
                for (int i = 0; i < count; i++) {
                    dummy[i] = numbers[i];
                }
                //printf("count %d", count);
                
                int deleted = remove_level(dummy, &count, i, &success);

                //printf("count %d", count);

                //printf("\nDeleted: %d\n", deleted);
                for (int i = 0; i < count - 1; i++) {
                    //printf("%d ", dummy[i]);
                }
                //printf("\n");
                
                if (perform_checks(dummy, count - 1))
                {
                    safes += 1;
                    break;
                }
            }
        }
    }

    printf("\nSafes: %d\n", safes);

    fclose(input);

    return 0;
}