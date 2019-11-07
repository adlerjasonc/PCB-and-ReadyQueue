#include "PCB.h"
#include "ReadyQueue.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>



void main()
{
  // Example: PID 1, total run time 10
  
 PCB a;
 initProcessValues(&a, 1, 30);
 PCB b;
 initProcessValues(&b, 2, 20);
 PCB c;
 initProcessValues(&c, 3, 10);

  

  // initialize readyQueue insert PCB
  ReadyQueue Q;

  // Initialize to empty
  empty(&Q);

  insert(&Q, &a);
  insert(&Q, &b);
  insert(&Q, &c);

  printf("Is Q empty %d\n", isEmpty(&Q));
  printf("Is Q full %d\n", isFull(&Q));
  printf("Size of Q %d\n", size(&Q));


  //more unit testing
  printProcesses(&Q);

  //loop fcfs
  while(!isEmpty(Q)) {
     printProcesses(&Q);
     runFCFS(&Q);
    }
  
  

//return 0;


}