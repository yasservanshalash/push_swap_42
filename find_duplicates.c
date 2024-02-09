#include <stdio.h>
int duplicate_numbers(int *numbers, int size) {
    int i;
    int j;

    i = 0;
    while(i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (numbers[j] == numbers[i])
            {
                printf(" duplicate number found ");
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int main()
{
    int numbers[] = {1,2,3,4,5,6,7,8, 9, 1};
    int i = 0;
    duplicate_numbers(numbers, sizeof(numbers) / sizeof(numbers[0]));
    return 0;
}