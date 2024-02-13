# CS350-Project-1
github link: <https://github.com/ashaikh45/CS350-Project-1>

## GAMEPLAN
add references to these files:

* `syscall.c` - contains an array of funciton pointers
  * add pointer to the function

* `syscall.h`

* `sysfile.c`

* `sysproc.c` - all system call functions are definded
  * put function definiton

* `usys.S`

* `user.h` - allows user to work with syscalls

* `makefile` - add commands on line 163 `UPROGS`


## Build and run xv6
The following provides instructions on how to build and run xv6 using either a CS machine or
your own computer.

**Using a CS machine**

1. Log into a CS machine (i.e., a local machine or a remote cluster machine).
2. Download and SCP the baseline xv6 code.
3. Compile and run xv6:
   `$ make qemu-nox`
4. after the compiling the kernel source and generating the root file system, the Makefile will
   start a QEMU VM to run the xv6 kernel image just compiled (you can read the Makefile for
   more details). Then you will see the following output (disregard the warning message(s)),
   indicating you have successfully compiled and run the xv6 system.

   ```
   xv6...
   cpu0: starting 0
   sb: size 1000 nblocks 941 ninodes 200 nlog 30 logstart 2 inodestart 32 bmap start 58
   init: starting sh
   ```

**Troubleshooting**: if you see the following error message

```
make: execvp: ./sign.pl: Permission denied
```

Solve it by running the following command:
`chmod ugo+x ./sign.pl`
Then
```
make clean
make qemu-nox
```

## git commands

### to make a new git branch:
`git checkout -b "name of new branch`

### pushing changes
`git add .`
`git commit -m ""short description of changes .`
`git push`



## Shutdown commands and sys calls (60pt)
The original xv6 system doesnt have a “shutdown” command to properly turn off the machine.
In this part, you are going to add a “shutdown” command to shut down the machine and four
other system calls.

1. **`shutdown `command and the system call**
   The first command you need complete is named `shutdown`, which simply shuts down the machine. In the baseline code, the file `shutdown.c` provides the implementation of this command. What you need to do is to complete the corresponding system call and its user space wrapper routine.

2. **`shutdown2`**
   **The first command you may complete is named `shutdown2`, which prints a shutdown message provided by the user within the system call implementation before shutting down the machine. In the baseline code, the file `shutdown2. c` provides the implementation of this command. What you need to do is to complete the corresponding system call and its user space wrapper routine.
   
3. **`exit2`**
   The second command you may complete is named `exit2`, which behaves like the `exit()` system call and voluntarily exits a running process. `exit2` takes an integer exit status argument and prints that status within the system call implementation before exiting. In the baseline code, the file `exit2.c` provides the implementation of this command. What you need to do is to complete the corresponding system call and its user space wrapper routine.

4. **`mkdir2`**
   The third command you may complete is named `mkdir2`, which behaves like the mkdir system call which creates a new directory in your file system. `mkdir2` takes two directory names as arguments and creates both directories in your file system. In the baseline code, the file `mkdir2.c` provides the implementation of this command. What you need to do is to complete the corresponding system call and its user space wrapper routine.

5. **`uptime2`**
   The fourth command you may complete is named “uptime2”, which behaves like the uptime system call which returns the amount of ticks (100ths of a second) your system has been turned on. uptime2 provides takes an integer argument which changes the format of the return value in kernel space. `uptime2(1)` returns uptime in ticks, `uptime2(2)` returns uptime in seconds, and `uptime2(3)` returns uptime in minutes. In the baseline code, the file `uptime2.c` provides the implementation of this command. What you need to do is to complete the corresponding system call and its user space wrapper routine.

6. **Additional system calls**
   Operating systems developers regularly update their operating systems with new features, which may include new system calls. Your group will add N additional system calls to xv6 where N == GroupSize. Each group member is responsible for one system call, and can be helped by other gropu members. 5 example system calls are documented below. Select N of these 5, without repetition.

7. **Custom System Call (5 extra credit points)**
   If you would like, one group member can complete a custom system call. This system call can be based on an existing system call, or entirely of your own invention. Your custom system call MUST take at least one argument of any type and use that argument in its functionality. To gain credit for this system call, you must implement it and add its user space wrapper for its command similar to the code provided for each of the previous five system calls in this assignment. Please document the purpose, functionality, and usage of this system call in a PROJ1.txt file included with your code.


### Requirements and hints
* Your implementation should not change the code in `shutdown.c` or other user space wrappers rather than commenting out the `STUB FUNCS` macro definition to remove the stub function. Failure to follow this requirement will lead to zero points for each pertinent part of the assignment.

* To shut down the xv6 virtual machine in your system call, you only need two lines of code:
```C
outw(0xB004, 0x0|0x2000);
outw(0x604, 0x0|0x2000);
```
* Reading and understanding how the existing user commands and the associated system calls are implemented will be helpful. For example, you can look at how the cat user command is implemented. The cat user command is implemented in `cat.c`, in which the system call `open()` is called. The actual work of the `open()` system call is done in the `sys open()` function defined in `sysfile.c`.

* Understanding the mechanism is important. Pay attention to all the related files, which include assembly files (relax, the related assembly file is very easy to read). You may be requested to explain how things work in xv6 in exams.
