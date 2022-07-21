/*

[TEST] My 'iypurm' environment variable should have a value of injynbnrmg! Let's check…

set environment variable 

`$ export iypurm=injynbnrmg`

then run the below code
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void pwncollege(){

    char *command[] = {"/challenge/embryoio_level32",0};
    char *bin_file = command[0];

    if(fork()==0){
	    execvp(bin_file,command);
    }
    else
	    wait(NULL);
}

int main() {
    pwncollege();
}
