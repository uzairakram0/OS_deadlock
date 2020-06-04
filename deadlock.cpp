//Wait-for deadlock
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <thread>
#include <semaphore.h>

using namespace std;
//GLOBAL VARIABLES\\
//for output stream mutex
sem_t coutmutex;

//FUNCTION PROTOTYPES//
void sync_print(string str);

////////////////////MAIN///////////////////
int main(){
	//cout semaphore
	sem_init( &coutmutex, 0, 1 );
	
	//RESOURCE SEMAPHORES
	sem_t resourceA, resourceB;
	sem_init( &resourceA, 0, 1 );
	sem_init( &resourceB, 0, 1 );
	
	
	thread thread1{
		[&]() {
			while( 1 ){
				sem_wait( &resourceA );
					sync_print("proc1 capture resourceA");
				sem_wait( &resourceB );
					sync_print("proc1 capture resourceB");
				sem_post( &resourceB );
					sync_print("proc1 release resourceB");
				sem_post( &resourceA );
					sync_print("proc1 release resourceA");
			}//END of loop
		}//END of thread1 lambda
	};//END of thread1

	thread thread2{
		[&](){
			while( 1 ) {
				sem_wait( &resourceB );
					sync_print("proc2 capture resourceB");
				sem_wait( &resourceA );
					sync_print("proc2 capture resourceA");
				sem_post( &resourceA );
					sync_print("proc2 release resourceA");
				sem_post( &resourceB );
					sync_print("proc2 release resourceB");
			}//END of loop
		}//END of thread2 lambda
	};//END of thread2

	thread1.join();
	thread2.join();

	return 0;
}

void sync_print(string str){
	sem_wait( &coutmutex );
		cout << str << endl;
		cout.flush();
	sem_post( &coutmutex );
}
