#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main() {
    cout << "Hello World" << endl;
    int x = 0;
    x = 10;
    
    int f = open("./1.test" ,O_RDWR);
    int rc = fork();
    if(rc < 0) {
        cout << "Error fork failed" << endl;
        exit(1);
    }else if (rc == 0){
        cout << "hi" << endl;
    }else {
        usleep(500);      
        cout << "goodbye" << endl;
    }
    return 0;
}