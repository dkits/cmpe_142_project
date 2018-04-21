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
	int status;
};



int main() {

	cout << "N\t	Run number\t    Avg. waiting time\t	Avg. turnaround time" << endl;

	for(int n = 50; n <= 150; n = n + 50){
		for(int runNumber = 1; runNumber < 6 ; runNumber++){

//			int n = 50, runNumber = 1;

			Proc PE[n];

			int totalBurstTime = 0, totalWaitTime = 0, totalTurnaroundTime = 0;
			int i, j, largest, avgWaitTime, avgTurnaroundTime;

			srand(runNumber);

			//Input values
			for (i = 0; i < n; i++){
				PE[i].arrivalTime = rand() % 1000 + 1;
				//Burst Time
				PE[i].burstTime = rand() % 100 + 1;
				//Priority
				PE[i].priority = rand() % 10 + 1;
				//Process Number
				PE[i].process = i+1;
				PE[i].status = 0;
				totalBurstTime = totalBurstTime + PE[i].burstTime;
			}

	//Sort arrival time of processes
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

    //Priority Sort
    PE[n].priority = -9999;

    for(int time = PE[0].arrivalTime; time < totalBurstTime;)
    {
    	largest = n;

    	for(i = 0; i < n; i++)
    	{
    	      if (PE[i].arrivalTime <= time && PE[i].status != 1 && PE[i].priority > PE[largest].priority)
    	      {
    	            largest = i;
    	      }
    	}

    	time = time + PE[largest].burstTime;
    	PE[largest].completionTime = time;
    	PE[largest].waitTime = PE[largest].completionTime - PE[largest].arrivalTime - PE[largest].burstTime;
        PE[largest].turnaroundTime = PE[largest].completionTime - PE[largest].arrivalTime;
        PE[largest].status = 1;

        totalWaitTime = totalWaitTime + PE[largest].waitTime;
        totalTurnaroundTime = totalTurnaroundTime + PE[largest].turnaroundTime;
    }

    avgWaitTime = totalWaitTime / n;
    avgTurnaroundTime = totalTurnaroundTime / n;

	cout<<n<<"\t\t"<<runNumber<<"\t\t    "<< avgWaitTime << "\t\t\t\t"<< avgTurnaroundTime << endl;
}
}


	return 0;
}


/*

#include <iostream>
#include <stdlib.h>
using namespace std;

struct process
{
      char process_name;
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status;
}process_queue[150];

int limit;

void Arrival_Time_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++)
      {
            for(j = i + 1; j < limit; j++)
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}

int main()
{
      int i, time = 0, burst_time = 0, largest;
      char c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;

//      cout << "N\t	Run number\t    Avg. waiting time\t	Avg. turnaround time" << endl;

//      for(int limit = 5; limit <= 15; limit = limit + 5){
//    	  for(int runNumber = 1; runNumber < 6 ; runNumber++){
//    		  srand(runNumber);

      cout << "\nEnter Total Number of Processes:\t" << endl;
      cin >> limit;
      srand(2);

      //Input values (SUCCESSFUL)
      for (i = 0, c = 'A'; i < limit; i++, c++){
    	  process_queue[i].arrival_time = rand() % 1000 + 1;
    	  //Burst Time
    	  process_queue[i].burst_time = rand() % 100 + 1;
    	  //Priority
    	  process_queue[i].priority = rand() % 10 + 1;
    	  //Process Number
    	  process_queue[i].process_name = c;
    	  process_queue[i].status = 0;
    	  burst_time = burst_time + process_queue[i].burst_time;

//   	  cout<<"Arrival Time: "<<process_queue[i].arrival_time<<" Burst time: "<<process_queue[i].burst_time
//   			  <<" Priority: "<<process_queue[i].priority<<endl;
      }

//      cout << "Total burst time: " << burst_time << endl;

      for(i = 0, c = 'A'; i < limit; i++, c++)
      {
            process_queue[i].process_name = c;
            cout << "\nEnter Details For Process["<<i<<"]: "<<process_queue[i].process_name<<endl;
            cout << "Enter Arrival Time:\t" << endl;
            cin >> process_queue[i].arrival_time;
            cout << "Enter Burst Time:\t" << endl;
            cin >> process_queue[i].burst_time;
            cout << "Enter Priority:\t" << endl;
            cin >> process_queue[i].priority;
            process_queue[i].status = 0;
            burst_time = burst_time + process_queue[i].burst_time;
      }
      */
/*
      Arrival_Time_Sorting();
      process_queue[150].priority = -9999;
//      cout << "\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time" << endl;
      // Code works until here

      for(time = process_queue[0].arrival_time; time < burst_time;)
      {
    	  largest = 150;
            for(i = 0; i < limit; i++)
            {
                  if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
                  {
                        largest = i;
                  }
            }
            time = time + process_queue[largest].burst_time;
            process_queue[largest].ct = time;
            process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arrival_time - process_queue[largest].burst_time;
            process_queue[largest].turnaround_time = process_queue[largest].ct - process_queue[largest].arrival_time;
            process_queue[largest].status = 1;
            wait_time = wait_time + process_queue[largest].waiting_time;
            turnaround_time = turnaround_time + process_queue[largest].turnaround_time;
//            cout<<"\nProcess name: "<<process_queue[largest].process_name
//            		<<"\t\t"<<process_queue[largest].arrival_time
//					<<"\t\t"<<process_queue[largest].burst_time
//					<<"\t\t"<<process_queue[largest].priority
//					<<"\t\t"<<process_queue[largest].waiting_time << endl;
      }

      average_waiting_time = wait_time / limit;
      average_turnaround_time = turnaround_time / limit;
      cout << average_waiting_time << endl;
      cout << average_turnaround_time << endl;

//		cout<<limit<<"\t\t"<<runNumber<<"\t\t    "
//		<< average_waiting_time << "\t\t\t\t"<< average_turnaround_time << endl;
//    	  }
//      }

      return 0;
}

*/
