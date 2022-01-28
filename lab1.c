#include "types.h"
#include "stat.h"
#include "user.h"

#include "stddef.h"
// #include "sys/wait.h"


int exit_test(void);
int waitpid_test(void);

int main(int argc, char *argv[]){
	switch(*argv[1]){
		default: 
			printf(1,"\nUnknow Option\nInput: \'lab1 (test number 1-3)\'\n\n");
			break;
		case '1':
			printf(1, "\nTesting exitS(status) for Part a.\n");
			exit_test();
			break;
		case '2':
			printf(1,"\nSecond test\n");
			break;
		case '3':
			printf(1,"\nTesting waitpid(pid,status,options) for Part c.\n");
			waitpid_test();
			break;
		case '4':
			printf(1,"\nTesting Bonus for Part e.\n");

			break;
	}
	exitS(0);
	return 0;
}

int exit_test(void){
	int pid;
	pid = fork();
	if (pid == 0){
		printf(1,"Hello from the child proccess. PID: %d\n", getpid());
		exitS(0);
	}
	else if (pid > 0){
		//parent process
	}
	else {
		printf(1,"Error with fork()\n");
		exitS(-1);
	}
	pid= waitS(NULL);
	printf(1, "Child has terminated \n");
	return 0;
}

int waitpid_test(void){
	int return_pid, local_status;
	int pid[2] = {0,0};

	//char *argv[3] = {"./echo", "\"ECHO TEST\"", NULL};

	printf(1,"\n Hello from the Parent proccess. My PID is: %d\n", getpid());

	pid[0] = fork();

	if (pid[0] > 0){
		pid[1] = fork();
	}
	else if (pid[0] == 0){
		printf(1,"\n This is the child, PID#: %d and I will exit with status %d\n", getpid(), getpid() + 4);
		exitS(getpid() + 4);
	}
	else {
	 	printf(1,"Error with fork()\n");
	 	exitS(-1);	 
	}

	if (pid[1] > 0){
		//parent process
	}
	else if (pid[1] == 0){
		printf(1,"\n This is the child, PID#: %d and I will exit with status %d\n", getpid(), getpid() + 4);
		exitS(getpid() + 4);
	}
	else {
	 	printf(1,"Error with fork()\n");
	 	exitS(-1);	 
	}

	sleep(5);
	printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid[1]);
    return_pid = waitpid(pid[1], &local_status, 0);
	printf(1, "\n This is the parent: Child# %d has exited with status %d\n",return_pid, local_status);

	sleep(5);
	printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid[0]);
    return_pid = waitpid(pid[0], &local_status, 0);
	printf(1, "\n This is the parent: Child# %d has exited with status %d\n",return_pid, local_status);
	
	
	// if (pid[0] > 0){
	// 	printf(1,"Hello from the Parent proccess. PID: %d\n", getpid());
	// 	pid[1] = waitpid(pid[1], &status2, 0);
	// 	// if (WIFEXITED(status)){
	// 	// 	printf(1,"Child ( %d ) terminated normally\n", pid); 
	// 	// }
	// 	// else if (WIFSIGNALED(status)){
	// 	// 	printf(1,"Child ( %d ) terminated by signal\n", pid); 
	// 	// }
	// 	printf(1,"Child ( %d ) terminated normally\n", pid[1]); 
	// 	printf(1,"Child ( %d ) terminated normally\n", pid[0]); 
	// }
	// else if (pid[1] == 0){
	// 	printf(1,"Hello from the child2 proccess. PID: %d\n", getpid());
	// 	sleep(20);
	// 	exec(argv[0], argv);
	// 	exitS(1);

	// }
	// else if (pid[0] == 0){
	// 	printf(1,"Hello from the child1 proccess. PID: %d\n", getpid());
	// 	exec(argv[0], argv);
	// 	exitS(1);
	// }

	// else{
	// 	printf(1,"Error with fork()\n");
	// 	exitS(-1);
	// }
	return 0;
}