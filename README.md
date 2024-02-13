# CS350-Project-1

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
   make: execvp: ./sign.pl: Permission denied
   Solve it by running the following command:
   chmod ugo+x ./sign.pl
   Then
   make clean
   make qemu-nox
