/*
 * priorityWithPreemption.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: dan95
 */

#include <iostream>
#include <stdlib.h>
using namespace std;


struct process
{
      int process_name;
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status;
        int limit;
    void runNumberTester(int runNum, int processAmt);
}process_queue[150];

void process::runNumberTester(int runNum, int processAmt) {

    int i, time = 0, burst_time = 0, largest;
    int c;
    float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
    limit = processAmt;
    srand(runNum);

    //Input values
    for (i = 0, c = 1; i < limit; i++, c++){
        process_queue[i].process_name = c;
        process_queue[i].arrival_time = rand() % 1000 + 1;
        //Burst Time
        process_queue[i].burst_time = rand() % 100 + 1;
        //Priority
        process_queue[i].priority = rand() % 10 + 1;
        //Process Number
        process_queue[i].status = 0;
        burst_time = burst_time + process_queue[i].burst_time;
    }

    //Sort by arrival time
    struct process temp;
    int k, j;
    for(k = 0; k < limit - 1; k++)
    {
        for(j = i + 1; j < limit; j++)
        {
            if(process_queue[k].arrival_time > process_queue[j].arrival_time)
            {
                temp = process_queue[k];
                process_queue[k] = process_queue[j];
                process_queue[j] = temp;
            }
        }
    }

    //Preemptive priority sort
    process_queue[processAmt -1].priority = -9999;

    for(time = process_queue[0].arrival_time; time < burst_time;)
    {
        largest = processAmt -1;
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
    }

    //Calculations of averages
    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;
    cout<<limit<<"\t\t"<<runNum<<"\t\t    "<< average_waiting_time << "\t\t\t"<< average_turnaround_time << endl;
}

int main()
{
    process Proc;
    cout << "N\t	Run number\t    Avg. waiting time\t	Avg. turnaround time" << endl;

    Proc.runNumberTester(1, 50);
    Proc.runNumberTester(2, 50);
    Proc.runNumberTester(3, 50);
    Proc.runNumberTester(4, 50);
    Proc.runNumberTester(5, 50);
    Proc.runNumberTester(1, 100);
    Proc.runNumberTester(2, 100);
    Proc.runNumberTester(3, 100);
    Proc.runNumberTester(4, 100);
    Proc.runNumberTester(5, 100);
    Proc.runNumberTester(1, 150);
    Proc.runNumberTester(2, 150);
    Proc.runNumberTester(3, 150);
    Proc.runNumberTester(4, 150);
    Proc.runNumberTester(5, 150);

    return 0;
}
