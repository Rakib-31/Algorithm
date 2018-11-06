#include<stdio.h>
#include<unistd.h>

int main(){

    //pstree -p command after run

    pid_t pid,cpid,ppid;

    pid = getpid();
    cpid = fork();

    if(cpid == 0){
        execl("I:\Documents\New folder\add","add",NULL);
    }

    else if(cpid > 0){
        cpid = fork();
        if(cpid == 0)
            execl("I:\Documents\New folder\sub","sub",NULL);
        else if(cpid > 0){
                while(1);
        }
    }

    return 0;
}


