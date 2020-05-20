#define MAXLINE 1000

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


using namespace std;

int main() {

    int fd[2];
    int n;

    char line[MAXLINE];

    if(pipe(fd) < 0) {
        cout << "pipe error" << endl;
    }

    int rc = fork();
    if(rc < 0){
        cout << "create child1 fail." << endl;
        exit(1);
    }else if (rc == 0) {
        //child 1 logic ,output
        close(fd[0]);// close read 
        write(fd[1], "hello world\n", 12);
        cout << "I am child1."  << endl;
        cout << "Maybe i cant know my pid from rc in my process. my return from fork is " << rc << endl;
        cout << "but i can know from getpid, my pid is " << getpid() << endl;
        cout << "---" <<endl;
    }else{//parent
        int rc2 = fork();
        if(rc2 < 0) {
            cout << "create child2 fail." << endl;
        }else if(rc2 == 0) {
            //child2 logic, load child1 output as input

            waitpid(rc, NULL, 0);//not necessary
            cout << "I am child2, I run after child1(pid:" << rc <<")." << endl;
            close(fd[1]);//close write
            n = read(fd[0], line, MAXLINE);//read str from child1 output as input
            cout << "now its time for child2 to print output from child1." << endl;
            write(STDOUT_FILENO, line, n);// write the str recieved from child1 on terminal
            cout <<"----" <<endl;


        }else{
            //parent 
            waitpid(rc2, NULL, 0);//not necessary
            cout << "I will do nothing until child2 "<< rc2 << " done." << endl;
        }
    }
    return 0;

}