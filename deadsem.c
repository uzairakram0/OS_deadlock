//semaphore self deadlock
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//SEMAPHORE
sem_t sem;

//MAIN//
int main(){
	sem_init(&sem, 0, 0);
	printf("dead semaphore\n");
	sem_wait( &sem );		//deadlock condition
	printf("After wait (will never reach here)");
	exit(0);
}//END MAIN
