# CS350 Project 1 custom system call - Abdulaziz Shaikh

NOTE: this file will look way better in vscode as a .md file but you can view it as a txt file if you want

## Responsibility breakdown:

* Abdulaziz - worked on `exit2()` and the custom syscall `smile()` (see below) and problem #2
* Brian - worked on `shutdown()` and `shutdown2()` and problem #1
* Jewel - worked on `mkdir2()` and problem #4
* Jimson - worked on `uptime2()` and problem #3

## `smile()` syscall

### `smile()` syscall purpose:

* the **smile** was implemented to have a syscall that can make use of writing to the terminal at any given time
* I also created it because I like ascii character art

### `smile()` functionality:

* the **smile** syscall takes a user input integer (greater than 0) and displays this many smiley faces to the console
* here is implementation of **smile** itself which is found in `smile.c`. You can see the user space accessing of the `smile` function and how it gets called with user input passed in

```c
void smile(int &num) {}
#endif
int main(int argc, char * argv[])
{
	if(argc != 2)
    {
        printf(1, "Please provide a positive integer argument as a number of smiley faces you want");
        exit();
    }

    int num = atoi(argv[1]);
    smile(num); 
    // return 0;
}
```

* here is the wrapper function found in `sysproc.c`. You can see here the actual processing of the user input, and the text that gets written to the console itself

```c
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
```

### `smile()` syscall usage:

To use **smile**:

1. make sure xv6 is currently running
2. type `smile(number)` where `number` is the number of smiley faces you want displayed on the console (must be > 0)
3. the output should look something like this:

```powershell
    init: starting sh   
    $ smile 3
    smile 1: (◕ ‿ ◕)
    smile 2: (◕ ‿ ◕)
    smile 3: (◕ ‿ ◕)
    pid 3 smile: trap 14 err 5 on cpu 0 eip 0xffffffff addr 0xffffffff--kill proc
    $ 
```

### `smile()` wrapper functions and file changes:

* syscall.h: `#define SYS_smile 26`
* user.h: `int smile(int num);`
* syscall.c: `extern int sys_smile(void);` and `[SYS_smile]   sys_smile,`
* sysproc.c: contains syscall impelmentation, see ***`smile()` functionality***
* smile.c: contains the userspace impelmentation, see ***`smile()` functionality***
