#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){

    printf(1, "\n This program tests the correctness of your lab#2\n");
	
    int PScheduler(void);
    int aging(void);
    int performance(void);
    int performanceWithAging(void);
    int donation(void);
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
            performance();
			break;
        case '4':
			printf(1,"\nTesting Scheduling Preformance (TurnAround Time and wait) with Aging\n");
            performanceWithAging();
			break;
        case '5':
			printf(1,"\nTesting Priority Donation\n");
            donation();
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
        else if (pid == 0) {
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
    int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) system call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");

    set_aging(1); //turn on aging
    set_prior(0);
    for (i = 0; i <  3; i++) {
        pid = fork();
        set_aging(1); //turn on aging
        if (pid > 0 ) {
            continue;
        }
        else if (pid == 0) {
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

int performance(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

    int pid;
    int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) system call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");

    output_flag(1);
    set_prior(0);
    for (i = 0; i <  3; i++) {
        pid = fork();
        output_flag(1); //turn on outputFlag
        if (pid > 0 ) {
            continue;
        }
        else if (pid == 0) {
            set_prior(30-10*i);	
            for (j=0;j<50000;j++) {
                for(k=0;k<1000;k++) {
                    asm("nop"); 
                }
            }
        printf(1, "\n child# %d with priority %d has finished! \n",getpid(),getprior());
        tw_time();
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
    //tw_time();
    exit();		
    return 0;
}

int performanceWithAging(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

    int pid;
    int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) system call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");

    output_flag(1);
    set_aging(1); //turn on aging
    set_prior(0);
    for (i = 0; i <  3; i++) {
        pid = fork();
        set_aging(1); //turn on aging
        output_flag(1); //turn on outputFlag
        if (pid > 0 ) {
            continue;
        }
        else if (pid == 0) {
            set_prior(30-10*i);	
            for (j=0;j<50000;j++) {
                for(k=0;k<1000;k++) {
                    asm("nop"); 
                }
            }
        printf(1, "\n child# %d with priority %d has finished! \n",getpid(),getprior());
        tw_time();
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
    //tw_time();
    exit();		
    return 0;
}

int donation(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

    int pid;
    int i,j,k;
    int array[2] = {1, -20}; 
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) system call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");

    output_flag(1);
    set_prior(0);
    for (i = 0; i <  2; i++) {
        pid = fork();
        //donate(array[i]);
        output_flag(1); //turn on outputFlag
        if (pid > 0 ) {
            continue;
        }
        else if (pid == 0) {
            donate(array[i]);
            set_prior(30-10*i);	
            for (j=0;j<50000;j++) {
                for(k=0;k<1000;k++) {
                    asm("nop"); 
                }
            }
        printf(1, "\n child# %d with priority %d has finished! \n",getpid(),getprior());
        tw_time();
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
    //tw_time();
    exit();		
    return 0;
}