/* ############ Named Pipe client #########################
Brief: This program is the client side implementation
(both process client and client runs on same machine)
It creates a named pipe in the same directory
and infintely waits until end is recived by the client.

It uses the named pipe for only read purposes

*/

#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h>
#include <sys/stat.h> 
#include<string.h> 
#include<sys/wait.h> 
#include <iostream>
#include <fcntl.h>

using namespace std;

int main() 
{ 
    int fd1; 
  
    // FIFO file path 
    char myfifo[] = "FIFOCHANNEL"; 
  
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666); 
  
    char str1[80], str2[80]; 
    fd1 = open(myfifo,O_RDWR); 
    while (1) 
    { 
        // First open in read only and read 
        int value = read(fd1, str1, 80); 
        if(value == 0)continue;
        printf("Server Sent data: %s and length %d\n", str1, value);
        
    } 
    return 0; 
} 
