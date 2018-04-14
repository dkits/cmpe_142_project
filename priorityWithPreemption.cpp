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

    int *arrivalTime, *burstTime, *process, *waitTime, *turnaroundTime, *priority, n, avgWaitTime, avgTurnaroundTime;

    int inputProcess();
<<<<<<< HEAD
    void prioritySort(int priority, int burstTime, int process, int n);
=======
<<<<<<< HEAD

=======
>>>>>>> 91b679a71ac977fc17e3d572bfe68dd88d887923
    void prioritySort(int priority, int burstTime, int process);
>>>>>>> bdab0a2757e5e348cd9a334f7e316a3b4d81745d
    int calcAvgWaitTime(int waitTime, int burstTime, int n);

    int calcAvgTurnaroundTime(int turnaroundTime, int burstTime, int waitTime, int n);
<<<<<<< HEAD

    void outputProcess(int n, int runNumber, int avgWaitTime, int avgTurnaroundTime);
=======
>>>>>>> 91b679a71ac977fc17e3d572bfe68dd88d887923
    void outputProcess(int n, int runNumber, int avgWaitTime, int avgTurnaroundTime);

};

int main()
{
    Proc PE;
<<<<<<< HEAD

    PE.inputProcess();

    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        PE.burstTime[i] = rand() % 100 + 1;
        cout<<"Priority:";
        PE.priority[i] = rand() % 10 + 1; ;
        PE.process[i]=i+1;           //contains process number
    }
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

=======

    PE.inputProcess();
    PE.prioritySort(int priority, int burstTime, int process, int n);


    PE.avgWaitTime = PE.calcAvgWaitTime(int waitTime, int burstTime, int n);
    PE.avgTurnaroundTime = PE.calcAvgTurnaroundTime(int turnaroundTime, int burstTime, int waitTime, int n);
    PE.outputProcess(int n, int runNumber, int avgWaitTime, int avgTurnaroundTime);

    return 0;
}

int Proc::inputProcess(){
    int n;
    cout<<"Enter Total Number of Process:";
    cin>>n;
    process = new int[n];

    return n;
}

<<<<<<< HEAD
void Proc::prioritySort(int priority, int burstTime, int process, int n){
=======
>>>>>>> 91b679a71ac977fc17e3d572bfe68dd88d887923
void Proc::prioritySort(int priority, int burstTime, int process){
>>>>>>> bdab0a2757e5e348cd9a334f7e316a3b4d81745d
	int temp=0;
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
<<<<<<< HEAD

/*
    waitTime[0]=0;            //waiting time for first process is zero


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

//    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";

/*
    for(i=0;i<n;i++)
    {
        turnaroundTime[i]=burstTime[i]+waitTime[i];     //calculate turnaround time
        total+=turnaroundTime[i];
        cout<<"\nP["<<process[i]<<"]\t\t  "<<burstTime[i]<<"\t\t    "<<waitTime[i]<<"\t\t\t"<<turnaroundTime[i];
    }

    avg_tat=total/n;     //average turnaround time
*/

    avgWaitTime = calcAvgWaitTime();
    avgTurnaroundTime = calcAvgTurnaroundTime();

/*
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
*/

    return 0;
}

    return n;
}


=======
}

>>>>>>> 91b679a71ac977fc17e3d572bfe68dd88d887923
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

