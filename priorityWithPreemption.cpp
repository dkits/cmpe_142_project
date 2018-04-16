/*
 * priorityWithPreemption.cpp
 *
 *  Created on: Apr 14, 2018
 *      Author: dan95
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

class Proc {

public:
//Process is 150 for all values
    int *arrivalTime, *burstTime, *process, *waitTime, *turnaroundTime, *priority;
    int runNumber, n, avgWaitTime, avgTurnaroundTime;

    void inputValues(int value);

    void prioritySort();



    void calcAvgWaitTime();

    void calcAvgTurnaroundTime();


    void outputProcess(int runNumber);

};

int main()
{
    Proc PE;

    PE.inputValues(50);
    PE.prioritySort();
    PE.calcAvgWaitTime();
    PE.calcAvgTurnaroundTime();
    PE.outputProcess(1);




//    PE.avgWaitTime = PE.calcAvgWaitTime(int waitTime, int burstTime, int n);
//    PE.avgTurnaroundTime = PE.calcAvgTurnaroundTime(int turnaroundTime, int burstTime, int waitTime, int n);
//    PE.outputProcess(int n, int runNumber, int avgWaitTime, int avgTurnaroundTime);

    return 0;
}

void Proc::inputValues(int value){

    n = value;
    process = new int[n];
    burstTime = new int[n];
    priority = new int[n];
    arrivalTime = new int[n];
    waitTime = new int[n];
    turnaroundTime = new int[n];

    cout << "Enter seed Value:" << endl;
    cin >> runNumber;
    srand(runNumber);
    for(int i=0;i<n;i++)
    {

        //Burst Time
        burstTime[i] = rand() % 100 + 1;
        //Priority
        priority[i] = rand() % 10 + 1;
        //Arrival Time
        arrivalTime[i] = rand() % 1000 + 1;

        process[i]=i+1;           //process number

    }

}

void Proc::prioritySort() {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arrivalTime[j] < arrivalTime[pos])
                pos = j;
        }

        temp = arrivalTime[i];
        arrivalTime[i] = arrivalTime[pos];
        arrivalTime[pos] = temp;

        temp = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = temp;

        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;

        cout<<"Process: "<<process[i]<<" BT: "<<burstTime[i]<<" Pr: "<<priority[i]<<" AT: "<<arrivalTime[i]<<endl;
    }
}




void Proc::calcAvgWaitTime(){
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

    avgWaitTime = sum / n;

}

void Proc::calcAvgTurnaroundTime() {
    int avg = 0;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitTime[i];     //calculate turnaround time
        sum += turnaroundTime[i];
    }

    avgTurnaroundTime = sum / n;     //average turnaround time

}

void Proc::outputProcess(int runNumber){
    cout << "\nN\t	Run number\t    Avg. waiting time\t	Avg. turnaround time" << endl;
    /*for (int i = 0; i < n; i++)*/{
    	cout << n << "\t" << runNumber << "\t" << avgWaitTime << "\t"<< avgTurnaroundTime;
    }
}

