//     Test SJF scheduling
//
#include "system.h"
#include "list.h"
#include "testcase.h"
#include<iostream>

//extern void TestScheduler( int );

//----------------------------------------------------------------------
// ThreadTest5
//      SJF algorithm
//      Order of arrival: A, B, C, D, E, F, G, H, I
//      Process  Burst Time  Arrival Time
//        TA         7		  0
//        TB         2		  0
//        TC         5		  0
//        TD        12	       	 70	
//        TE        15		 70
//        TF         1	         70
//        TG         2		400
//        TH         3		400
//        TI         8		400
//----------------------------------------------------------------------

void
ThreadTest5()
{
 
    int  numThreads;
    std::cout<<"Shortest Job First Scheduling.\n";
    std::cout<<"Input the number of threads to be scheduled.\n";
    std::cin>>numThreads;
    int  startTime[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };
    int  burstTime[50]; //= {   7,   2,   5,  12,  15,   1,   2,   3,   8 };
    int   priority[] = {   0,   0,   0,   0,   0,   0,   0,   0,   0 };

	int i;
	std::cout<<"Input burst times of "<<numThreads<<" threads.\n";
	for(i=0; i<numThreads;i++)
		std::cin>>burstTime[i];

    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, burstTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_SJF);

    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

