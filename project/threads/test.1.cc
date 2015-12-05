//     Test Nonpreemptive Priority scheduling 
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest1
//      Nonpreemptive Priority scheduling algorithm
//      Order of arrival: All at same time 0
//      Process  Burst Time  Priority
//        P1         5          7
//        P2        19          5
//        P3        13          2
//        P4         7          8
//        P5        12          6
//----------------------------------------------------------------------

void ThreadTest1()
{
 
    int  numThreads = 5;
    int  startTime[] = {  0,  0,  0,  0,  0  };
    int  burstTime[] = {  5, 19,  13, 7, 12  };
    int   priority[] = {  7,  5,  2,  8,  6, };
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_PRIO_NP);

    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

