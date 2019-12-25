#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

int main(){
    int rc = fork();
    if(rc < 0) {
        cout << "call fail" << endl;

    }else if (rc == 0) {
        cout << "i am child " << endl;
        close(STDOUT_FILENO);
        printf("could this happen in child?");
    }else{
        cout << "I am parent" << endl;
        printf("Try this.");
        wait(NULL);
        printf("Could this happen in parent?");

    }
}
