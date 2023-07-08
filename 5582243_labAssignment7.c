#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Variables
    int numOfInputs;
    int i;
    int j;
    int temp;
    int index = 0;

    // Numbers Input File Form
    FILE* inFile = fopen("testInput.txt","r");
    fscanf(inFile, " %d\n", &numOfInputs);

    int numArray[numOfInputs];
    int oldNumArray[numOfInputs];

    for (i = 0; i < numOfInputs; i++)
    {
        fscanf(inFile, " %d", &oldNumArray[i]);
    }

    // Copy Array
    for (i = 0; i < numOfInputs; i++)
    {
        numArray[i] = oldNumArray[i];
    }
    
    // Bubble Sort
    for (i = 0; i < numOfInputs - 1; i++)
    {
        for (j = 0; j < numOfInputs - i - 1; j++)
        {
            if (numArray[j] > numArray[j+1])
            {
                temp = numArray[j+1];
                numArray[j+1] = numArray[j];
                numArray[j] = temp;
                index++;
            }
        }
    }

    // Print Statment
    // Old, unsorted list
    printf("For the array of numbers: ");
    for (i = 0; i < numOfInputs; i++) 
    {
        printf("%d, ", oldNumArray[i]);
    }
    printf("%d swap(s) occurred to sort the list.\n", index);

    // New, sorted list
    printf("The new array of numbers looks like: ");
    for (i = 0; i < numOfInputs; i++) 
    {
        printf("%d", numArray[i]);
        if (i == numOfInputs - 1)
        {
            printf(".");
        } else
        {
        printf(", ");
        }
    }
}