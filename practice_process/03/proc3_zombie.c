//子进程先于父进程退出
#include <stdio.h> 
#include <stdlib.h> 
int main() { 
    pid_t id = fork();
    if(id < 0){ 
        perror("fork"); 
        return 1; 
    } else if(id > 0){//parent 
        printf("parent[%d] is sleeping...\n", getpid());
        sleep(30); 
    }else{ 
        printf("child[%d] is begin Z...\n", getpid()); 
        sleep(5); 
        exit(EXIT_SUCCESS); 
    } 
    return 0; 
}