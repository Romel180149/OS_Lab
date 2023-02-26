#include<stdio.h>
int main()
{
int i, n, timeSlice, j, sum = 0, completed = 0, processID[10], burstTime[10], remainingTime[10];
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter the time slice: ");
scanf("%d", &timeSlice);
for(i = 0; i < n; i++)
{
printf("Enter the burst time for process %d: ", i+1);
scanf("%d", &burstTime[i]);
processID[i] = i+1;
remainingTime[i] = burstTime[i];
}
i = 0;
while(completed != n)
{
if(remainingTime[i] <= timeSlice && remainingTime[i] > 0)
{
sum += remainingTime[i];
remainingTime[i] = 0;
completed++;
printf("Process %d completed in %d seconds.\n", processID[i], sum);
}
else if(remainingTime[i] > 0)
{
remainingTime[i] -= timeSlice;
sum += timeSlice;
}
if(i == n-1)
i = 0;
else if(processID[i+1] <= n)
i++;
}
return 0;
}
