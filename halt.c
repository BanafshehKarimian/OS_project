/* halt.c
 *	Simple program to test whether running a user program works.
 *	
 *	Just do a "syscall" that shuts down the OS.
 *
 * 	NOTE: for some reason, user programs with global data structures 
 *	sometimes haven't worked in the Nachos environment.  So be careful
 *	out there!  One option is to allocate data structures as 
 * 	automatics within a procedure, but if you do this, you have to
 *	be careful to allocate a big enough stack to hold the automatics!
 */
#include "syscall.h"

void* p(int a){

	//printf("pid%d\n",a);

}
int main()
{
	int x = Fork(p);
	if (x == 0) {

		int x = Fork(p);
		//Exec("../test/sort.c");
	}
	else {
		Join(x);
		return;

	}
	//int y = Fork(p);
	//Exec("../test/sort.c");
	//printf("here\n");
   //Halt();
    /* not reached */
}

