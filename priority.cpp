
#include <iostream>
#include <stdlib.h>
using namespace std;

struct process
{
      int process_name;
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
      int c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;

//      cout << "N\t	Run number\t    Avg. waiting time\t	Avg. turnaround time" << endl;

//      for(int n = 50; n <= 150; n = n + 50){
//    	  limit = n;
//    	  for(int runNumber = 1; runNumber < 6 ; runNumber++){

      cout << "\nEnter Total Number of Processes:\t" << endl;
      cin >> limit;
      srand(1);

      //Input values (SUCCESSFUL)
      for (i = 0, c = 1; i < limit; i++, c++){
    	  process_queue[i].arrival_time = rand() % 1000 + 1;
    	  //Burst Time
    	  process_queue[i].burst_time = rand() % 100 + 1;
    	  //Priority
    	  process_queue[i].priority = rand() % 10 + 1;
    	  //Process Number
    	  process_queue[i].process_name = c;
    	  process_queue[i].status = 0;
    	  burst_time = burst_time + process_queue[i].burst_time;

    	  // cout<<"Arrival Time: "<<process_queue[i].arrival_time<<" Burst time: "<<process_queue[i].burst_time
    			//   <<" Priority: "<<process_queue[i].priority<<endl;
      }

      cout << "Total burst time: " << burst_time << endl;
      /*
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
      Arrival_Time_Sorting();
      process_queue[150].priority = -9999;
      cout << "\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time" << endl;
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
            cout<<"\nProcess name: "<<process_queue[largest].process_name
            		<<"\t\t"<<process_queue[largest].arrival_time
					<<"\t\t"<<process_queue[largest].burst_time
					<<"\t\t"<<process_queue[largest].priority
					<<"\t\t"<<process_queue[largest].waiting_time;
      }

      average_waiting_time = wait_time / limit;
      average_turnaround_time = turnaround_time / limit;
      cout << "\n\nAverage waiting time:\t" << average_waiting_time << endl;
      cout << "Average Turnaround Time:\t" << average_turnaround_time << endl;
//    	  }
//      }

      return 0;
}
