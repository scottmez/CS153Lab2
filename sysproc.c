#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stdio.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}


int 
sys_add(void)
{
  int a = 2;
  int b = 2020;
  return a+b;
}


int
sys_exitS(void)
{
  int status;
  if(argint(0, &status) < 0){
    return -1;
  }
  exitS(status);

  return 0; //not reached
}

int 
sys_waitS(void) {                    
  int *status;

  if (argptr(0, (void*)&status, sizeof(*status)) < 0){
    return -1;
  }
  return waitS(status);
}

//Part c
int 
sys_waitpid(void){
  int pid;
  int* status;
  int options = 0;

  if (argint(0, &pid) < 0){
    return -1;
  }
  if (argptr(1, (void*)&status, sizeof(*status)) < 0){
    return -1;
  }
  return waitpid(pid, status, options);
}

//Part e
int
sys_debug(void) 
{
   debug();
   return 0;
}

int 
sys_set_prior(void)
{
   int prior_lvl;

  if (argint(0,&prior_lvl) < 0){
    return -1;
  }
  return set_prior(prior_lvl);
}

int
sys_tw_time(void)
{
  tw_time();
  return 0;
}

int
sys_getprior(void)
{
  return myproc()->priority;
}

int 
sys_donate_prior(void)
{
   int prior_donated;

  if (argint(0,&prior_donated) < 0){
    return -1;
  }
  return donate_prior(prior_donated);
}

