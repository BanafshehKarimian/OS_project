#include "SJF.h"

SJF :: SJF()
{
}

SJF :: ~SJF()
{
}

void
SJF::ReadyToRun (Thread *thread)
{
    DEBUG('t', "Putting thread %s on ready list.\n", thread->getName());

    thread->setStatus(READY);
    readyList->SortedInsert((void *)thread, this->timeCost);
}

void SJF::setTimeCost(int t)
{
	timeCost = t;
}

