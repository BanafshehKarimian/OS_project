// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------
#include <iostream>
#include <unistd.h>

using namespace std;

//void funArray[10];


void SimpleThread1(int which)
{
    int num;
	sleep(2);
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", which, num);
        //currentThread->Yield();
    }
}
void
SimpleThread2(int which)
{
    int num;
    sleep(3);
    for (num = 0; num < 7; num++) {
	printf("*** thread %d looped %d times\n", which, num);
       // currentThread->Yield();
    }
}
void
SimpleThread3(int which)
{
    int num;
    sleep(1);
    for (num = 0; num < 7; num++) {
	printf("*** thread %d looped %d times\n", which, num);
       // currentThread->Yield();
    }
}
/*funArray[] = 
{
	SimpleThread1,
	SimpleThread2,
	SimpleThread3
}
*/
//////////////////////// producer -  concumer///////////////////////////

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

#include <queue>          // std::queue
#include "synch.h"





void ThreadTest1()
{
	Thread * t1[3];
	Thread *t2[3];
	
	
	for( int i=0 ;i<3 ;i++)
		{
		t1[i] = new Thread("1");
		t2[i] = new Thread("2");	
		}
		
	std::cout<<"threadtest1\n";
    DEBUG('t', "Entering ThreadTest1");
    //Thread *t1 = new Thread("1");
    //Thread *t2 = new Thread("2");
    
    
    

		
	t1[0]->RunToSetTime( SimpleThread1, 1);
	t1[1]->RunToSetTime( SimpleThread2, 2);
	t1[2]->RunToSetTime( SimpleThread3, 3);
	
	
	//set totalTime
	t2[0]->totalTime = t1[0]->totalTime;
	t2[1]->totalTime = t1[1]->totalTime;
	t2[2]->totalTime = t1[2]->totalTime;
	
	t2[0]->Fork( SimpleThread1, 1);
	t2[1]->Fork( SimpleThread2, 2);
	t2[2]->Fork( SimpleThread3, 3);
	
	
    
    
    //SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest()
{
	 
    switch (testnum) {
    case 1:
	ThreadTest1();
    break;
	default:
	printf("No test specified.\n");
	break;
    }
}

