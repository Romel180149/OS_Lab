#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,count=0,n,execution_time=0,temp,avg_wt=0;
     
    cout<<"Enter the number of process: ";
    cin>>n;
    int bt[n+1],at[n],p[n],pt[n+1],wt[n],completation_time[n],r_bt[n];

    cout<<"Enter the process sequence: ";
    for(i=0;i<n;i++)cin>>p[i];

    cout<<"Enter the priority: ";
    for(i=0;i<n;i++)cin>>pt[i];

    cout<<"Enter the arrival time: ";
    for(i=0;i<n;i++)cin>>at[i];

    cout<<"Enter the burst time: ";
    for(i=0;i<n;i++)
    {
        cin>>bt[i];
        r_bt[i]=bt[i];
    }

    temp=INT_MAX;
    for(i=0;i<n;i++)
    {
      if(at[i]<temp)
      temp=at[i];
    }

    cout<<"\nProcess     priority     arrival time     burst time       waiting time"<<endl;

    execution_time=temp;
    pt[n+1]=INT_MAX;

    while(count!=n)
    {
        j=n+1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=execution_time && bt[i]>0 && pt[i]<pt[j])
            {
                j=i;
            }
        }
       bt[j]--;
       execution_time++;
       if(bt[j]==0)
        {
          count++;
          completation_time[j]=execution_time;
          wt[j]=completation_time[j]-(r_bt[j]+at[j]);
          cout<<p[j]<<"\t\t"<<pt[j]<<"\t\t"<<at[j]<<"\t\t"<<r_bt[j]<<"\t\t"<<wt[j]<<endl;
          avg_wt+=wt[j];
        }
    }

   avg_wt/=n;
   cout<<"Average waiting time time : "<<avg_wt<<endl;
}