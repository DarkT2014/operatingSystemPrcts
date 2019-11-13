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
        // cout << "Hi, I am a child." << endl;
        // cout << "file in child is " << f << endl;
        char c[1024] = "child";
        write(f,c,5);


        // int sz = read(f,c,10);
        // read(sz,c,10);
        cout << "c in child is:" << c << endl;
        // cout << "x in child is " << x << endl;
    }else {
        // int wc = wait(NULL);
        // cout << "file in parent is " << f << endl;
        // printf("Hi, I am parent of %d (wc : %d)(pid:%d)\n", rc, (int) getpid());
        // x = 66;
        // cout << "x in parent is " << x << endl;
        
        char c[1024] = "paren";
        write(f,c,5);

        // int sz = read(f,c,10);
        // read(sz,c,10);
        
        

        // x = 6;
        cout << "c in parent is:" << c << endl;
    }
    return 0;
}