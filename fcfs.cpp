#include<iostream>
using namespace std;

int main()
{
    int n, i;
    float at[20], bt[20], wt[20], tat[20], avwt = 0, avtat = 0;
    cout<<"Enter the number of processes: ";
    cin>>n;

    // Input arrival time and burst time for each process
    for(i = 0; i < n; i++)
    {
        cout<<"Enter arrival time and burst time for process "<<i+1<<": ";
        cin>>at[i]>>bt[i];
    }

    // Calculate waiting time and turnaround time for each process
    wt[0] = 0;  // Waiting time for first process is always 0
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    // Calculate average waiting time and average turnaround time
    for(i = 0; i < n; i++)
    {
        avwt += wt[i];
        avtat += tat[i];
    }
    avwt /= n;
    avtat /= n;

    // Output results
    cout<<"Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(i = 0; i < n; i++)
    {
        cout<<i+1<<"\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<"Average waiting time: "<<avwt<<endl;
    cout<<"Average turnaround time: "<<avtat<<endl;

    return 0;
}
