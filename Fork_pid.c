#include <stdio.h>
#include <sys/types.h>

int main() 
{
    pid_t p=fork();
    
    if(p<0)
    {
        perror("fork fail");
    }
    if(p=0)
    {
        printf("Hello world!,process_id(pid)=%d\n",getpid());
    }
    else
        printf("Hello world!,process_id(pid)=%d\n",getpid());
    
    return 0;
}