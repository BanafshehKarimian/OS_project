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
#include "synch.h"
#include <queue>
#include <stdio.h>
#include <iostream>

int testnum = 1;
int n = 5;
/*
Semaphore mutex("mutex",1);
Semaphore full("full",5);
Semaphore empty("empty",0);
*/
//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------


void
Thread1(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", which, num);
//        currentThread->Yield();
    }
}

void
Thread2(int which)
{
    int num;
    
    for (num = 0; num < 50 ; num++) {
	printf("*** thread %d looped %d times\n", which, num);
 //       currentThread->Yield();
    }
}

void
Thread3(int which)
{
    int num;
    
    for (num = 0; num < 15; num++) {
	printf("*** thread %d looped %d times\n", which, num);
//        currentThread->Yield();
    }
}

void
Thread4(int which)
{
    int num;
    
    for (num = 0; num < 20; num++) {
	printf("*** thread %d looped %d times\n", which, num);
//        currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------


/*
std::queue<int> myqueue;


int i = 0;
void producer(int w){
	
	while(1){
		int number = 1;
		empty.P();
		mutex.P();
		if(i < n){
			myqueue.push(number);
			i++;
//			DEBUG('t', "produce \"%d\"\n", number);
			printf("producer\n");
		}
		mutex.V();
		full.V();
	}
	return;
}

void consumer(){
	int num;
	while(1){
		mutex.P();
		if(!myqueue.empty()){
			myqueue.pop();
			i--;
			printf("concumer\n");
//			DEBUG('+', "concumer");
		}
		mutex.V();
		empty.V();
	}
	return;
}
	*/

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

    Thread *t1 = new Thread("forked thread");
    Thread *t2 = new Thread("forked thread");
    Thread *t3 = new Thread("forked thread");
    Thread *t4 = new Thread("forked thread");
   
  /*  t1->runToSetTime(Thread1,1);
    t2->runToSetTime(Thread2,2);
    t3->runToSetTime(Thread3,3);
    t4->runToSetTime(Thread4,4);
*/
    t1->Fork(Thread1, 1);
    t2->Fork(Thread2, 2);
    t3->Fork(Thread3, 3);
    t4->Fork(Thread4,4);
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

