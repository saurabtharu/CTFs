/*

This challenge is required to run with zero environment variable


*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void pwncollege(){

    char *command[] = {"/challenge/embryoio_level35",0};
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


/*
gcc  my_script.c

env -i ./a.out


        here -i is used to run the executable without any environment variable
*/
