#include "scheduler.h"

class SJF : public scheduler{
 public:
	int timeCost;
	
	SJF:public scheduler;
	~SJF:public scheduler;
	
	void setTimeCost(int);
	
	void ReadyToRun(Thread* thread);    
};
	
	
