#include <iostream>
#include <unistd.h>
#include <fcntl.h>


using namespace std;

int main() {
    cout << "Hello World" << endl;
    int x = 0;
    x = 10;
    
    int rc = fork();
    if(rc < 0) {
        cout << "Error fork failed" << endl;
        exit(1);
    }else if (rc == 0){
        cout << "I am child" << endl;
        // char args[2];
        const char* exePath = "/bin/";

        char * argv[] = {"ls","-alh", "~", nullptr };
        cout << "test -----" << endl;
        // args[0] = "-alh";
        // args[1] = "/";
        execv(exePath, argv);

    }else {
        cout << "I am parent" << endl;
        
    }
    return 0;
}