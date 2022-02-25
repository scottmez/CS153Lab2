#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){

    printf(1, "\n This program tests the correctness of your lab#2\n");
	
    int PScheduler(void);
    int aging(void);
    switch(*argv[1]){
		default: 
			printf(1,"\nUnknow Option\nInput: \'lab1 (test number 1-3)\'\n\n");
			break;
		case '1':
			printf(1, "\nTesting TA Test function.\n");
			PScheduler();
			break;
		case '2':
			printf(1,"\nTesting Aging\n");
            aging();
			break;
		case '3':
			printf(1,"\nTesting Scheduling Preformance (TurnAround Time and wait)\n");
			break;
	}
	exitS(0);



    
    exitS(0);
    return 0;
}
  
    
int PScheduler(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

    int pid;
    int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) system call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");

    set_prior(0);
    for (i = 0; i <  3; i++) {
        pid = fork();
        if (pid > 0 ) {
            continue;
        }
        else if ( pid == 0) {
            set_prior(30-10*i);	
            for (j=0;j<50000;j++) {
                for(k=0;k<1000;k++) {
                    asm("nop"); 
                }
            }
        printf(1, "\n child# %d with priority %d has finished! \n",getpid(),getprior());		
        exit();
        }
        else {
            printf(2," \n Error \n");

        }
    }

    if(pid > 0) {
        for (i = 0; i <  3; i++) {
            waitS(0);
        }
    printf(1,"\n if processes with highest priority finished first then its correct \n");
    }
    exit();		
    return 0;
}

    
int aging(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

    int pid;
    int j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) system call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");

    set_prior(10);

    pid = fork();

    if ( pid == 0) {
        set_prior(15);
        
        for (j=0;j<5;j++) {
            printf(1, "Child: %d Prio: %d\n",getpid(),get_prior_pid(pid));
            for(k=0;k<50000;k++) {
                asm("nop"); 
            }
        }
        printf(1, "\n child# %d with priority %d has finished! \n",getpid(),get_prior_pid(pid));		
        exit();
    }

    if(pid > 0) {
        for(k=0;k<5;k++) {
            printf(1, "Parent: %d Prio: %d\n",getpid(),get_prior_pid(pid));
            for(j=0;j<50000;j++) {
                asm("nop"); 
            }
        }
        printf(1, "\n parent# %d with priority %d has finished! \n",getpid(),get_prior_pid(pid));
        waitS(0);
    }
    
    exit();		
    return 0;
}