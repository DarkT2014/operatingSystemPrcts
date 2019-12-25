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
    int status = 0;
    /*
      pid<-1时，等待一个指定进程组中的任何子进程，这个 !进程组! 的ID等于pid的绝对值。
      pid=-1时，等待任何一个子进程退出，没有任何限制，此时waitpid和wait的作用一模一样。
      pid=0时，等待和该进程在同一个进程组中的任何子进程，如果某个子进程已经加入了别的进程组，waitpid不会对它做任何理睬。
      pid>0时，只等待进程ID等于pid的子进程，不管其它已经有多少子进程运行结束退出了，只要指定的子进程还没有结束，waitpid就会一直等下去。
    */
    int pid = 0;
    auto op = WNOHANG;
  /*
WNOHANG
  return immediately if no child has exited.

WUNTRACED
  also return if a child has stopped (but not traced via ptrace(2)). Status for traced children which have stopped is provided even if this option is not specified.

WCONTINUED (since Linux 2.6.10)
  also return if a stopped child has been resumed by delivery of SIGCONT.
(For Linux-only options, see below.)

-------------------------------------------------
  If status is not NULL, wait() and waitpid() store status information in the int to which it points. 
  This integer can be inspected with the following macros (which take the integer itself as an argument
  , not a pointer to it, as is done in wait() and waitpid()!):
-------------------------------------------------
WIFEXITED(status)
  returns true if the child terminated normally, that is, by calling exit(3) or _exit(2), or by returning from main().
WEXITSTATUS(status)
  returns the exit status of the child. This consists of the least significant 8 bits of the status argument that the child specified in a call to exit(3) or _exit(2) or as the argument for a return statement in main(). This macro should only be employed if WIFEXITED returned true.
WIFSIGNALED(status)
  returns true if the child process was terminated by a signal.
WTERMSIG(status)
  returns the number of the signal that caused the child process to terminate. This macro should only be employed if WIFSIGNALED returned true.
WCOREDUMP(status)
  returns true if the child produced a core dump. This macro should only be employed if WIFSIGNALED returned true. This macro is not specified in POSIX.1-2001 and is not available on some UNIX implementations (e.g., AIX, SunOS). Only use this enclosed in #ifdef WCOREDUMP ... #endif.
WIFSTOPPED(status)
  returns true if the child process was stopped by delivery of a signal; this is only possible if the call was done using WUNTRACED or when the child is being traced (see ptrace(2)).
WSTOPSIG(status)
  returns the number of the signal which caused the child to stop. This macro should only be employed if WIFSTOPPED returned true.
WIFCONTINUED(status)
  (since Linux 2.6.10) returns true if the child process was resumed by delivery of SIGCONT.
  */

    int wc = waitpid(pid, &status, op);
    //这个status在被waitpid调用后会发生变化，将status的值作为参数传入上面几个函数中可以对调用情况进行判断。

    printf("Hi, I am parent of %d (wc : %d)(pid:%d)\n", rc, wc, (int) getpid());
  }
  return 0;
}