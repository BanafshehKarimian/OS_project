#include "syscall.h"

int
main()
{
    int x;

       printf("befor fork\n");
    
    x = Fork();
    if (x == 0) {
       printf("child\n");
    }
    else {
       Printf("Parent after fork waiting for child: ");
       Join(x);
    }
    return 0;
}
