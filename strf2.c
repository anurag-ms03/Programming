#include <stdio.h>
#include <stdbool.h>

struct Process {                 //A structure is a user-defined data type it allows you to group together variables of different data types under a single name
    int processId;
    int burstTime;
    int remainingTime;    
    int arrivalTime;
    int completionTime;
    int responseTime;
    bool completed;
};

void calculateSRTFPreemptive(struct Process processes[], int n) {    //parameters are array of processes os struct Process type and number of processes
    int currentTime = 0;
    int completed = 0;

    while (completed != n) {     //until all processes are completed the loop executes
        int shortest = -1;
        int shortestTime = 1000000;        //shortest time is initialized to a large value , acting as a placeholder to ensure that the first eligible process found will have a shorter time
       
        for (int i = 0; i < n; i++) {     // iterates through all processes to find the process with the shortest remaining burst time that is eligible to run at the current time (currentTime).
            struct Process process = processes[i];
            if (process.remainingTime > 0 && process.arrivalTime <= currentTime && process.remainingTime < shortestTime) {  //checks if the process is eligible 1.the process should have some remaining burst time 2.process must have arrived 3.The remaining burst time of this process should be shorter than the previously found shortest time.
                shortest = i;    //holds the index of the shortest process
                shortestTime = process.remainingTime;     //holds the remaining burst time
            }
        }

        if (shortest == -1) {    //occurs when there is no eligible process at current time
            currentTime++;        //increments the currentTime
        } else {           //there is an eligible process
            struct Process *process = &processes[shortest];    //This line obtains a pointer to the selected process using the shortest index. The pointer process is used to manipulate the selected process's attributes.
            if (process->responseTime == -1) {   //if the condition is true it means the process has enterd the CPU for the first time
                process->responseTime = currentTime - process->arrivalTime;    //response time is calculated 
            }
            process->remainingTime--;    //The remaining time is decremented  as it got executed for one time unit
            process->completionTime++;   //The completion time of the selected process is incremented because it has been executed for one time unit
            currentTime++;       //overall time is incremented by 1 unit

            if (process->remainingTime == 0) { 
                process->completed = true;          //if remaining time is 0 it means the process is completed 
                process->completionTime = currentTime;  //the time of completion is noted
                completed++;   //number of process completed is incremented 
            }
        }
    }

    printf("Process\t\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int totalResponseTime = 0;

    for (int i = 0; i < n; i++) {     //iterates through all the processes 
        struct Process process = processes[i];
        int waitingTime = process.completionTime - process.burstTime - process.arrivalTime; //this is an alternate formula for waiting time
        int turnaroundTime = process.completionTime - process.arrivalTime;   //this is an alternate formula for turnaround time
        totalWaitingTime += waitingTime;             //calculating waiting time of all processes 
        totalTurnaroundTime += turnaroundTime;       //calculating turnaround time of all the processes
        totalResponseTime += process.responseTime;   //calculating total response
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process.processId, process.burstTime, process.arrivalTime,process.completionTime, waitingTime, turnaroundTime,process.responseTime);//waiting time and TAT is calculated 
    }

    double averageWaitingTime = (double) totalWaitingTime / n;
    double averageTurnaroundTime = (double) totalTurnaroundTime / n;
    double averageResponseTime = (double) totalResponseTime / n;
    printf("\nAverage Waiting Time: %lf\n", averageWaitingTime);
    printf("Average Turnaround Time: %lf\n", averageTurnaroundTime);
    printf("Average Response Time: %lf\n", averageResponseTime);
}

int main() {                             //main function
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];    // declares an array named processes of type struct Process of size n
    for (int i = 0; i < n; i++) {
        processes[i].processId = i + 1;            //giving ID to processes in numerical order starting from 1
        printf("Enter burst time for process %d: ", processes[i].processId);   //denoting the process through its id 
        scanf("%d", &processes[i].burstTime);    //enetering burst time
        printf("Enter arrival time for process %d: ", processes[i].processId);
        scanf("%d", &processes[i].arrivalTime);   //entering  arrival time of process
        processes[i].remainingTime = processes[i].burstTime; //remaing time is initialized with the burst time for each process
        processes[i].completionTime = 0;  //completion time is set to 0 for all procrsses
        processes[i].responseTime = -1;   //response time is initially set to -1
        processes[i].completed = false;    //completed is set to false
    }

    calculateSRTFPreemptive(processes, n);//the function is called by passing processes and n as parameters 
return 0;
}
