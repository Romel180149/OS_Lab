#include <stdio.h>
int main()
{
    int blockSize[10], processSize[10], blockCount, processCount, i, j, allocation[10];

    for (i = 0; i < 10; i++)
        allocation[i] = -1;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &blockCount);
    printf("Enter the memory block sizes: ");
    for (i = 0; i < blockCount; i++)
        scanf("%d", &blockSize[i]);

    printf("\nEnter the number of processes: ");
    scanf("%d", &processCount);
    printf("Enter the process sizes: ");
    for (i = 0; i < processCount; i++)
        scanf("%d", &processSize[i]);

    for (i = 0; i < processCount; i++) 
    {
        for (j = 0; j < blockCount; j++) 
        {
            if (blockSize[j] >= processSize[i]) 
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < processCount; i++) 
    {
        printf("   %d\t\t    %d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
