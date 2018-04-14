/*
 * priorityWithPreemption.cpp
 *
 *  Created on: Apr 14, 2018
 *      Author: dan95
 */

#include <iostream>
using namespace std;

class Proc {
	public:
		int *burstTime, *process, *waitTime, *turnaroundTime, *priority;
};

int main()
{
    Proc PE;
	int i, j, n, pos, temp, avgWaitTime, avgTurnaroundTime;
//  int burstTime[20], process[20], waitTime[20], turnaroundTime[20], priority[20], i, j, n, total=0, pos, temp, avg_wt, avg_tat;
    cout<<"Enter Total Number of Process:";
    cin>>n;
    PE.process = new int[n];
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>burstTime[i];
        cout<<"Priority:";
        cin>>priority[i];
        process[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }

        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        temp=burstTime[i];
        burstTime[i]=burstTime[pos];
        burstTime[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }

    waitTime[0]=0;            //waiting time for first process is zero

/*
     //calculate waiting time
    for(i=1;i<n;i++)
    {
        waitTime[i]=0;
        for(j=0;j<i;j++)
            waitTime[i]+=burstTime[j];

        total+=waitTime[i];
    }

    avg_wt=total/n;      //average waiting time
    total=0;
*/

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turnaroundTime[i]=burstTime[i]+waitTime[i];     //calculate turnaround time
        total+=turnaroundTime[i];
        cout<<"\nP["<<process[i]<<"]\t\t  "<<burstTime[i]<<"\t\t    "<<waitTime[i]<<"\t\t\t"<<turnaroundTime[i];
    }

    avg_tat=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;

    return 0;
}

int calcAvgWaitTime(int waitTime, int n){
    int avg = 0;
	waitTime[0]=0;            //waiting time for first process is zero

    //calculate waiting time
    for(int i = 1; i < n; i++)
    {
        waitTime[i]=0;
        for(j=0;j<i;j++)
            waitTime[i]+=burstTime[j];

        total+=waitTime[i];
    }
    avg = sum / n;
    return avg;
}
