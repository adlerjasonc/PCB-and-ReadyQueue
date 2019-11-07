#include "PCB.h"
#include <stdio.h>
#include <stddef.h>

// process - Pointer to a PCB
// post-condition: assigns all attributes to have value 0.
void initProcess(PCB* process){
  process->pid = 0;
  process->totalTime = 0;
  process->remainingTime = 0;

//WAS ON THE BOARD -- set each values to 0
void initProcessValues(PCB* process, int pid, int totalTime) { 
  process->pid = 0;
  process->totalTime = 0;
  process->remainingTime = totalTime;
}

// process - Pointer to a PCB
// runTime - Number of seconds to run this process on CPU
// post-condition: Decrease process remainingTime by 
// runTime only if runTime is >= remainingTime; else,
// decrease process remainingTime by remainingTime (zero it out),
// if remainingTime < runTime
int runProcess(PCB* process, int runTime)
{
  (*process).remainingTime -= runTime;
  process->remainingTime = process->remainingTime - runTime;
}


void printProcesses(PCB* process){
    printf("\nPID: %d\n",process->pid);
    printf("Total Time: %d\n",process->totalTime);
    printf("Remaining Time: %d\n",process->remainingTime);
}