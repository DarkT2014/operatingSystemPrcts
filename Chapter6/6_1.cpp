#include <iostream>
#include <fcntl.h>
#include <sys/time.h>

using namespace std;

/*
    This script is to measure the cost of time of a system call.
*/


int main() {
    struct timeval a;
    struct timeval b;
    gettimeofday(&a, NULL);
    cout <<  a.tv_sec << "s, " << a.tv_usec <<"ms"<< endl;
    int f = open("./61.txt", O_RDONLY);
    gettimeofday(&b, NULL);
    cout <<  b.tv_sec << "s, " << b.tv_usec <<"ms"<< endl;


    cout  << b.tv_usec - a.tv_usec <<"ms" << endl;
}