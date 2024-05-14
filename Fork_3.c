#include <stdio.h>
#include <sys/types.h>

int main() 
{
    int p=fork();
    
    if(p<0)
    {
        printf("fork fail");
    }
    if(p==0)
    {
        printf("Hello world! from child process\n");
    }
    else
        printf("Hello world! from parent process\n");
    
    return 0;
}