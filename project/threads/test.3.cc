//     Round Robin scheduling 
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest3
//      Round Robin scheduling algorithm
//      Process  Burst Time  Priority  Arrival
//        P1        10          0	0
//        P2        29          0	0
//        P3        18          0	0
//        P4         7          0	0
//        P5        23          0	0
//----------------------------------------------------------------------

void ThreadTest3()
{
 
    int  numThreads = 5;
    int  startTime[] = {  0,  0,  0,  0,  0  };
    int  burstTime[] = { 10, 29,  18, 7,  23 };
    int   priority[] = {  0,  0,  0,  0,  0  };
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_RR);

    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

