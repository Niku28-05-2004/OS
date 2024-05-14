
//child process
//write a c program to create a child process
#include <stdio.h>
#include <sys/types.h>
#include<unistd.h>

int main() 
{
    fork();
    printf("Hello world");

    return 0;
}