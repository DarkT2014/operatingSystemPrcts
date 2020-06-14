#include <iostream>
#include <fcntl.h>
#include <sys/time.h>

using namespace std;

/*
    This script is to measure the cost of time of a system call.
*/


int main() {
    cout << gettimeofday() << endl;
    int f = open("./61.txt", O_RDONLY);

}