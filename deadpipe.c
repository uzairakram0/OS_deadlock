//pipe to self read deadlock
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define size 100
#define READ 0
#define WRITE 1
#define SET 2

//MAIN//
int main(){
	int fd[SET];		//pipe file descriptor set
	char message[size];	//message container to read into
	pipe(fd);		//create unneamed pipe
	printf("begin reading\n");
	/*deadlock state*/
	int byteread = read(fd[READ], message, size);
	close(fd[READ]), close(fd[WRITE]); //CLOSE PIPE
	printf("%s\n", message);//print message red
	printf("end read(will never reach here)\n");
	exit(0);
}//END MAIN
