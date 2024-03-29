#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

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
sys_shutdown(void)
{
  outw(0xB004, 0x0|0x2000);
  outw(0x604, 0x0|0x2000);
  return 0;
}

int
sys_shutdown2(char * msg)
{
  int len = argstr(0, &msg);
  if(len < 0)
  {
    return 1;
  }
  cprintf("%s\n", msg);
  outw(0xB004, 0x0|0x2000);
  outw(0x604, 0x0|0x2000);
  return 0;
}

int
sys_exit2(int status)
{
  if (argint(0, &status) < 0)
    return -1;

  cprintf("Exiting with status %d\n", status);  
  exit();
  return 0;
}

int
sys_smile(int num)
{
  if (argint(0, &num) < 0)
    return -1;

  for (int i = 0; i < num; i++)
  {
    cprintf("smile %d: (◕ ‿ ◕)\n", i + 1); 
  }
  return 0;
}

int 
sys_uptime2(int format)
{
  int i;
  if(argint(0, &i) < 0){
    return -1;
  }

  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);

  switch(i){
    case 1:
      return xticks;
    case 2:
      return xticks/100; //seconds
    case 3:
      return xticks/6000; //minutes
    default:
      return -1;
  }

  
}
