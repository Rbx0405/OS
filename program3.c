#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid, mypid, myppid;
    
    mypid = getpid();
    printf("Before fork, process is %d\n", mypid);
    
    pid = fork();
    
    if (pid < 0) {
        perror("fork() failure");
        return 1;
    }
    
    if (pid == 0) {
        // Child process
        printf("This is child process.\n");
        mypid = getpid();
        myppid = getppid();
        printf("Process id is %d and ppid is %d\n", mypid, myppid);
    } else {
        // Parent process
        sleep(2);  // Give child process time to execute
        printf("This is parent process.\n");
        mypid = getpid();
        myppid = getppid();
        printf("Process id is %d and PPID is %d\n", mypid, myppid);
        printf("Newly created process id or child pid is %d\n", pid);
    }
    
    return 0;
}
 
