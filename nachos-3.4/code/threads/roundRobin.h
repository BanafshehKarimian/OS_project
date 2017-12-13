// scheduler.h
//	Data structures for the thread dispatcher and scheduler.
//	Primarily, the list of threads that are ready to run.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "scheduler.h"


// The following class defines the scheduler/dispatcher abstraction --
// the data structures and operations needed to keep track of which
// thread is running, and which threads are ready but not running.

class RoundRobin : Scheduler {
public:
    RoundRobin();			// Initialize list of ready threads
    ~RoundRobin();			// De-allocate ready list
    List* queue;
    void pushQueue(Thread* thread);
    void ReadyToRun(Thread* thread);	// Thread can be dispatched.
    Thread* FindNextToRun();		// Dequeue first thread on the ready
    // list, if any, and return thread.
};

#endif // SCHEDULER_H
