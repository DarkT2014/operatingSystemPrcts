#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

int main(){
  int rc = fork();
  if(rc < 0) {
    cout << "Fork Error" << endl;
    exit(1);
  }else if (rc == 0) {
    cout << "I am child." << endl;
    // int ww = wait(NULL);
    for(size_t i = 0; i < 10; ++i) {
      cout << "count " << i << endl;
    }
    // cout << "wait returns "<< ww << endl;
  }else {
    cout << "I am parent." << endl;
    int wc = wait(NULL);
    printf("Hi, I am parent of %d (wc : %d)(pid:%d)\n", rc, wc, (int) getpid());
  }
  return 0;
}