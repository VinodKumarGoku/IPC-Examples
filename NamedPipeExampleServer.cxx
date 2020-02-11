/* ############ Named Pipe Server #########################
Brief: This program is the server side implementation
(both process client and server runs on same machine)
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
    int fd; 
  
    // FIFO file path 
    char  myfifo[] = "FIFOCHANNEL"; 
    string s[] = {"1","2","3","4","5","6"};
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    mkfifo(myfifo, 0666); 
  
    char arr1[80], arr2[80]; 
    fd = open(myfifo, O_RDWR);
    for(int i =0;i<6;i++) 
    {  
        // Take an input arr2ing from user. 
        // 80 is maximum length 
        //fgets(arr2, 80, stdin); 
  
        // Write the input arr2ing on FIFO 
        // and close it 
        //arr2 = string(i);
        write(fd, s[i].c_str(), 80); 
        sleep(1);
    }
    return 0; 
} 
