#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int rc = fork();
    if(rc) {//parent
        int rc2 = fork();
        if(rc2) {//parent

        }else{//child2

        }
    }else{//child1


    }
}