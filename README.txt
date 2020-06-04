For question 1 I created 3 seperate deadlock programs:
deadlock.cpp - wait-for deadlock where each process is waiting on the other
deadpipe.c - a deadlock where the process is blocking to read.
deadsem.cpp - a deadlock where the process is waiting on a semaphore that only it holds.

Program name: deadlock.cpp
compile using: g++ -pthread deadlock.cpp -o deadlock
run: ./deadlock

Program name: deadpipe.c
compile using: gcc deadpipe.c -o deadpipe
run: ./deadpipe

Program name: deadsem.c
compile using: gcc -pthread deadsem.c -o deadsem
run: ./deadsem
