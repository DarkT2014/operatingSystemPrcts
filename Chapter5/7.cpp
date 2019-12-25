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

    }else{
        cout << "I am parent" << endl;

    }
}
