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

    int *arrivalTime, *burstTime, *process, *waitTime, *turnaroundTime, *priority, n, avgWaitTime, avgTurnaroundTime;

    int inputProcess();
    void prioritySort(int priority, int burstTime, int process);
    int calcAvgWaitTime(int waitTime, int burstTime, int n);
    int calcAvgTurnaroundTime(int turnaroundTime, int burstTime, int waitTime, int n);
    void outputProcess(int n, int runNumber, int avgWaitTime, int avgTurnaroundTime);

};

int main()
{
    Proc PE;

    PE.inputProcess();
    PE.prioritySort(int priority, int burstTime, int process);


    PE.avgWaitTime = PE.calcAvgWaitTime(int waitTime, int burstTime, int n);
    PE.avgTurnaroundTime = PE.calcAvgTurnaroundTime(int turnaroundTime, int burstTime, int waitTime, int n);
    PE.outputProcess();

    return 0;
}
int Proc::inputProcess(){
    int n;
    cout<<"Enter Total Number of Process:";
    cin>>n;
    process = new int[n];

    return n;
}

void Proc::prioritySort(int priority, int burstTime, int process){
	int temp=0;
	int n=0;
	for(int i=0;i<n;i++)
    {
        int pos=i;
        for(int j=i+1;j<n;j++)
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
}

int Proc::calcAvgWaitTime(int waitTime, int burstTime, int n){
    int avg = 0;
    int sum = 0;
	waitTime[0]=0;            //waiting time for first process is zero

    //calculate waiting time
    for(int i = 1; i < n; i++)
    {
        waitTime[i]=0;
        for(int j = 0; j < i; j++)
            waitTime[i] += burstTime[j];

        sum += waitTime[i];
    }

    avg = sum / n;

    return avg;
}

int Proc::calcAvgTurnaroundTime(int turnaroundTime, int burstTime, int waitTime, int n) {
    int avg = 0;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitTime[i];     //calculate turnaround time
        sum += turnaroundTime[i];
    }

    avg = sum / n;     //average turnaround time

	return avg;
}

void Proc::outputProcess(int n, int runNumber, int avgWaitTime, int avgTurnaroundTime){
    cout << "\nN\t	Run number\t    Avg. waiting time\t	Avg. turnaround time" << endl;
    for (int i = 0; i < 15; i++){
    	cout << n << "\t" << runNumber << "\t" << avgWaitTime << "\t"<< avgTurnaroundTime;
    }
}

