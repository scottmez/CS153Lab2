#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char *argv[])
{
   set_prior(1); // set a priority value
   int i, k;
   const int loop = 1000;
   for (i = 0; i < loop; i++)
   {

       asm("nop"); //in order to prevent the compiler from optimizing the for loop 
       for (k = 0; k < loop; k++)
       {
           asm("nop");
       }
       printf(1, "program 1 finished loop %d\n", i);
   }
   exit();
}
