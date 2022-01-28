#include "types.h"
#include "stat.h"
#include "user.h"

#include "stddef.h"


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
	exit();
	return 0;
}

int exit_test(void){
	int pid;
	pid = fork();
	if (pid < 0){
		printf(1,"Error with fork()\n");
		exitS(-1);
	}
	else if (pid == 0){
		printf(1,"Hello from the child proccess. PID: %d\n", pid);
		exitS(0);
	}
	pid= wait();
	printf(1, "Child has terminated \n");
	return 0;
}

int waitpid_test(void){
	int pid, status;

	char *argv[3] = {"./echo", "\"ECHO TEST\"", NULL};

	printf(1,"Hello from the Parent proccess. PID: %d\n", getpid());

	pid = fork();
	if (pid < 0){
		printf(1,"Error iwth fork()\n");
		exitS(-1);
	}
	else if (pid == 0){
		printf(1,"Hello from the child proccess. PID: %d\n", getpid());
		exec(argv[0], argv);
		exitS(1);
	}
	else{
		printf(1,"Hello from the Parent proccess. PID: %d\n", getpid());
		waitpid(pid, &status, 0);
		// if (WIFEXITED(status)){
		// 	printf(1,"Child ( %d ) terminated normally\n", pid); 
		// }
		// else if (WIFSIGNALED(status)){
		// 	printf(1,"Child ( %d ) terminated by signal\n", pid); 
		// }
		printf(1,"Child ( %d ) terminated normally\n", pid); 

	}
	return 0;
}