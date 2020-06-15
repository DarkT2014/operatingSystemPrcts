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
    cout <<  a.tv_sec << "s, " << a.tv_usec <<"us"<< endl;
    int f = open("./61.txt", O_RDONLY);
    gettimeofday(&b, NULL);
    cout <<  b.tv_sec << "s, " << b.tv_usec <<"us"<< endl;


    cout  << b.tv_usec - a.tv_usec <<"us" << endl;


    cout << "Now test the resolution of gettimeofday()." << endl;

    struct timeval t1, t2, t3, t4;
    gettimeofday(&t1, NULL);
    gettimeofday(&t2, NULL);
    gettimeofday(&t3, NULL);
    gettimeofday(&t4, NULL);

    cout <<  t1.tv_sec << "s, " << t1.tv_usec <<"us"<< endl;
    cout <<  t2.tv_sec << "s, " << t2.tv_usec <<"us"<< endl;
    cout <<  t3.tv_sec << "s, " << t3.tv_usec <<"us"<< endl;
    cout <<  t4.tv_sec << "s, " << t4.tv_usec <<"us"<< endl;

}