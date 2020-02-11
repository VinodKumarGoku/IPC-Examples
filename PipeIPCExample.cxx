/* ##################### Pipe Communication ####################
Brief: This program demostartes communication between 2 
process that are related. There exists a parent/child 
relationship between process.

A pipe is created and shared between 2 process.
1 process (parent) writes to the write end of the pipe
and the child process reads it via the read end

Always remember the read call is blocking call. A process
of thread is blocked until thier is any informaion/data
in the pipe to be read.

*/




#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include <iostream>

using namespace std;

void simplified_cout(string s)
{
    cout << s << endl;
}



int main()
{
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);

    string s[3] = {"Hello World","World Hello","Hellp OOrld"};

/*
    if(fork() == 0)
    {
        cout << "Child Process activated" << endl;
        char red[100];
        read(fd[0],red,11);
        cout << red << endl << endl; 
        read(fd[0],red,11);
        cout << red << endl << endl;
        read(fd[0],red,strlen(s[0].c_str()));
        cout << red << endl << endl; 
    }
    else 
    {
        cout << "Parent process activated" << endl;
        write(fd[1],s[0].c_str(),strlen(s[0].c_str()));
        write(fd[1],s[1].c_str(),strlen(s[1].c_str()));
        write(fd[1],s[2].c_str(),strlen(s[2].c_str()));
        
        wait(NULL);
        close(fd[0]);
        close(fd[1]);
    }
*/

    if(fork() == 0)
    {
        char simple_read[15];
        simplified_cout("Executing child process"); 
        for(int i =0;i<3;i++)
        {
            simplified_cout("Started reading in child process");
            read(fd1[0],simple_read,11);
            cout << "Read Successfully from Child " << simple_read << endl; 
        }
    }
    else
    {
        simplified_cout("Executing parent process");
        write(fd1[1],s[0].c_str(),strlen(s[0].c_str()));
        cout << "Sent from Parent " <<  s[0].c_str() << endl << endl;
        sleep(10);
        write(fd1[1],s[1].c_str(),strlen(s[1].c_str()));
        cout << "Sent from Parent " <<  s[1].c_str() << endl << endl;
        sleep(10);
        write(fd1[1],s[2].c_str(),strlen(s[2].c_str()));
        cout << "Sent from Parent " <<  s[2].c_str() << endl << endl;
        sleep(10);

        // Waiting for the child to terminate
        wait(NULL);
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
    }

}
