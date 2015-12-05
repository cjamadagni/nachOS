//     Multilevel Queue scheduling 
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest4
//      Multilevel Queue scheduling algorithm
//      Process  Burst Time   Queue  Arrival
//        P1        10          3	0
//        P2        29          1	0
//        P3        18          2	0
//        P4         7          2	0
//        P5        23          1	0
//----------------------------------------------------------------------

void ThreadTest4()
{
 
    int  numThreads = 5;
    int  startTime[] = {  0,  0,  0,  0,  0  };
    int  burstTime[] = { 10, 29,  18, 7,  23 };
    int      queue[] = {  3,  1,  2,  2,  1  };
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = queue[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_MLQ);
    scheduler->SetNumOfQueues( 3 );

    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

