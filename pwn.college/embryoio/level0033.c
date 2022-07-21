/*
echo "hfhbnygi" > /tmp/hcnpmq

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void pwncollege(){

    char *command[] = {"/challenge/embryoio_level33",0};
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
