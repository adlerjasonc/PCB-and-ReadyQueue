// readyQueue.c
// implementation of ReadyQ functions

#include "ReadyQueue.h"
#include "PCB.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define bool int



// Q - pointer to a ReadyQueue
// post-conditon: sets numProcesses = 0
void empty(ReadyQueue* Q)
{
  Q->numProcesses = 0;
}

// Q - pointer to a ReadyQueue
// returns true if queue is empty - contains no processes; else, false.
bool isEmpty(ReadyQueue* Q)
{
  return Q->numProcesses == 0;
}

// Q - pointer to a ReadyQueue
// returns true if queue is full - contains MAX_Q_LEN processes; else, false.
bool isFull(ReadyQueue* Q)
{
  return Q->numProcesses >= MAX_Q_LEN;
}

// Q - pointer to a ReadyQueue
// returns number of processes stored in the queue.
int size(ReadyQueue* Q)
{
  return Q->numProcesses;
}

// Q - pointer to a ReadyQueue
// process - pointer to a PCB assume has been initialized
// post-condition: if Q is not full, then insert process
// into next open processList array slot, increment
// numProcesses, and return true; else, return false.
// !! Copy data values from process into array owned by Q.
bool insert(ReadyQueue* Q, PCB* process)
{
  // if pointers are not NULL and Q is not full then...
  if (Q != NULL && process != NULL && !isFull(Q) )
  {
    // Know Q is not full
    // Copy values from given process into array slot's PCB
    Q->processList[Q->numProcesses] = *process;
    Q->numProcesses++;
    // Assume #define TRUE  1 has been done somewhere
    return TRUE;
  }
  else
    return FALSE;
}

// pre-condition: assume first PCB has completed
//                assume size of Q is > 1.
// post-condition: shift all other PCB one slot to left
//                 decrement numProcesses by 1.
void removeFrontPCB(ReadyQueue* Q)
{

  if(Q->numProcesses > 1)
  {
    // Loop to copy shift second element into first slot,
    // third element into second slot, ...
    for(int i = 0; i < (Q->numProcesses-1); i++)
       Q->processList[i] = Q->processList[i+1];
  }

  if(!isEmpty(Q))
    // decrement numProcesses by 1
    Q->numProcesses--;

}

// Q - pointer to a ReadyQueue
// post-condition: if Q is not empty, then call runProcess function
// on first PCB in the queue.  
// Run first process in Q to completion.  Shift all remaining
// PCBs one array slot forward so second is now first.
int runFCFS(ReadyQueue* Q)
{
   if(!isEmpty(Q))
   {
      // Get pointer to first process in Q
      PCB* process = &( Q->processList[0] );
		
			
      // FCFS - assume process runs to completion
      int timeRun = runProcess(process, process->remainingTime);

       // Print message indicating when a process runs
  printf("Completed PID %d\n", process->pid);
       // Example:
       // TIME 0   PID 1    RUNS FOR   2
			 // Use globalTime to show current time

      // If process has <= 0 remainingTime ten remove completed front of Q process and
		   // Print message if process completes
       // TIME 2   PID 1    COMPLETE
	return timeRun;
			
   }
}






