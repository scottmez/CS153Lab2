#include "types.h"
#include "stat.h"
#include "user.h"
int exit_test(void);

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
			printf(1,"\nThird Test\n");

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