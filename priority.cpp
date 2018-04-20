/*
 * priority.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: dan95
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

class Proc {
public:

	int arrivalTime, burstTime, priority, process, turnaroundTime, waitTime;
	int runNumber, n, completionTime, avgWaitTime, avgTurnaroundTime;
	bool isDone;

    void inputValues(int runNumber);
    void prioritySort(int value);
    void calcAvgWaitTime();
    void calcAvgTurnaroundTime();
    void outputProcess(int runNumber);
};

int main() {


	int n = 5, runNumber = 3;

	Proc PE[n];

	int totalBurstTime = 0, totalWaitTime = 0, totalTurnaroundTime = 0;
	int i, j, largest, avgWaitTime, avgTurnaroundTime;

	//totalBurstTime = PE.inputValues(runNumber);

	srand(runNumber);

	//Input values (SUCCESSFUL)
	for (i = 0; i < n; i++){
		PE[i].arrivalTime = rand() % 100 + 1;
		//Burst Time
        PE[i].burstTime = rand() % 100 + 1;
        //Priority
		PE[i].priority = rand() % 10 + 1;
		//Process Number
		PE[i].process = n+1;
		PE[i].isDone = false;
		totalBurstTime = totalBurstTime + PE[i].burstTime;

		cout<<"Arrival Time: "<<PE[i].arrivalTime<<" Burst time: "<<PE[i].burstTime
		    <<" Priority: "<<PE[i].priority<<endl;
	}

	//Sort arrival time of processes (SUCCESSFUL)
	cout << "Sorting arrival time..." << endl;
	Proc temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (PE[i].arrivalTime > PE[j].arrivalTime)
            {
            	temp = PE[i];
            	PE[i] = PE[j];
            	PE[j] = temp;
            }
        }
    }

    //Print out processes in order of arrival time (SUCCESSFUL)
    for (i = 0; i < n; i++){
    	cout << "Process " << i << " arrival time: " << PE[i].arrivalTime << endl;
    }

    cout << "Total burst time: " << totalBurstTime << endl;

    //Priority Sort (SUCCESSFUL?? No, this is only nonpreemptive priority)
    Proc temp2[n];
    temp2[n-1].priority = -9;
    for(i = 0; i < n; i++)
    {
    	cout << "Process: " << i << " ArrivalTime: " << PE[i].arrivalTime << " Priority: "<< PE[i].priority << endl;
    }

    for(int time = PE[0].arrivalTime; time < totalBurstTime;)
    {
    	largest = n - 1;

    	for(i = 0; i < n; i++)
    	{
    		if((PE[0].arrivalTime <= time && PE[0].isDone != true && PE[0].priority > temp2[largest].priority)
    				|| (PE[i].arrivalTime <= time && PE[i].isDone != true && PE[i].priority > PE[largest].priority))
    		{
    			largest = i;
    		}
    	}

    	cout << "Time " << time << endl;

    	time = time + PE[largest].burstTime;

    	cout << "Largest burst time " << PE[largest].burstTime << endl;

    	PE[largest].completionTime = time;

    	cout << "Completion time: " << PE[largest].completionTime <<
    			" Arrival time: " << PE[largest].arrivalTime <<
				" Burst time: " << PE[largest].burstTime << endl;

    	PE[largest].waitTime = PE[largest].completionTime - PE[largest].arrivalTime - PE[largest].burstTime;
        PE[largest].turnaroundTime = PE[largest].completionTime - PE[largest].arrivalTime;
        PE[largest].isDone = true;

        totalWaitTime = totalWaitTime + PE[largest].waitTime;
        totalTurnaroundTime = totalTurnaroundTime + PE[largest].turnaroundTime;

        cout << "Largest wait time " << PE[largest].waitTime << endl;
        cout << "Largest turnaround time " << PE[largest].turnaroundTime << endl;
        cout << "Total wait time " << totalWaitTime << endl;
        cout << "Total turnaround time " << totalTurnaroundTime << endl;
    }

    avgWaitTime = totalWaitTime / n;
    avgTurnaroundTime = totalTurnaroundTime / n;

    cout << "Average wait time " << avgWaitTime << endl;
    cout << "Average turnaround time " << avgTurnaroundTime << endl;

    cout << "\nN\t	Run number\t    Avg. waiting time\t	Avg. turnaround time" << endl;
    cout << n << "\t	" << runNumber << "\t\t    " << avgWaitTime << "\t\t\t	"<< avgTurnaroundTime;

	return 0;
}

void Proc::inputValues(int runNumber){

	/*
	Proc PE[n];
	int totalBurstTime;
	srand(runNumber);

		//Input values (SUCCESSFUL)
		for (int i = 0; i < n; i++){
			PE[i].arrivalTime = rand() % 1000 + 1;
			//Burst Time
	        PE[i].burstTime = rand() % 100 + 1;
	        //Priority
			PE[i].priority = rand() % 10 + 1;
			//Process Number
			PE[i].process = n+1;
			PE[i].isDone = false;
			totalBurstTime = totalBurstTime + PE[i].burstTime;

			cout<<"Arrival Time: "<<PE[i].arrivalTime<<" Burst time: "<<PE[i].burstTime
			    <<" Priority: "<<PE[i].priority<<endl;
		}

		return totalBurstTime;
	*/

}

void Proc::prioritySort(int value){



}

void Proc::calcAvgWaitTime(){



}

void Proc::calcAvgTurnaroundTime() {



}





