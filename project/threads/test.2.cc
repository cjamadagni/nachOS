//     Test Preemptive Priority scheduling 
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest2
//      Preemptive Priority scheduling algorithm
//      Process  Burst Time  Priority  Arrival
//        P1         5          7	120
//        P2        19          5	  0
//        P3        13          2 	200
//        P4         7          8	180
//        P5        12          6	100
//----------------------------------------------------------------------

void ThreadTest2()
{
 
    int  numThreads = 5;
    int  startTime[] = {120,  0, 200, 180,100 };
    int  burstTime[] = {  5, 19,  13,   7, 12 };
    int   priority[] = {  7,  5,   2,   8,  6 };
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_PRIO_P);

    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

