
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>

#include <iostream>
#include <string>


using namespace std;

/*
Note: review "The UNIX Operating System" slides (pg 135 in class slides).

Jobs of the OS:
  - Core:
    - multi-process.
    - multi-user.
    - file system.
  - Extended:
    - Networking, devices, drivers.
    - Graphical interface, windowing system.
    - Standard programs.
    - Common libraries.
    - Basic security.

System calls:
  - Special functions used to talk to the OS directly.
  - User program --> OS.
  - Includes read, write, open, close, exit, kill, exec, fork, chdir, chmod, chown, etc.
  - https://man7.org/linux/man-pages/man2/syscalls.2.html.

Signals:
  - Program interupts that let the OS manipulate the user program.
  - OS --> user program.
  - Includes SIGINT (ctrl-c), SIGSEGV (segmentation fault), SIGPIPE (tried IO with a broken socket or pipe), etc.
  - https://man7.org/linux/man-pages/man7/signal.7.html.

Processes:
  - The basic unit of program execution on the computer.
  - Managed by the OS.
  - Can contain many threads.
  - Usually has an exclusive pool of memory.
  - Associated with a process table (indexed by PID).
  - Use fork() to split processes.

Process table:
  - PID.
  - User ID.
  - Current directory.
  - Args.
  - Enviromental vars.
  - Open file descriptors (default: 0, 1, 2).
  - Other OS info, mem info, program info, etc.

File descriptors:
  - An integer associated with an object in the FS.
  - Used for almost all interaction with the rest of the system (in unix, everything is a file).
  - Supplied to system calls for IO.

Threads:
  - Lightweight process.
  - No entry in process table, no exclusive memory, no PID.
  - Needs "-lpthread" flag in compiler.
    - Example: "g++ -o main main.cc -lpthread".
*/


void forkExample()
{
    int x = 100;                                                                // Create a variable in memory.
    int result = fork();                                                        // Split off a new process.
    if(result == 0)                                                             // Child.
    {
        x = 50;                                                                 // Change x in child memory.
        cout << "Hello from the child process." << endl;
        cout << "My x value is " << x << "." << endl;
        exit(0);                                                                // End the child process.
    }
    else if(result < 0)
    {
        exit(1);
    }
    else                                                                        // Parent.
    {
        int returnStatus;
        waitpid(result, &returnStatus, 0);                                      // Wait for child proc to end. waitpid(pid_t pid, int * stat_loc, int options).
        cout << "Hello from the parent process." << endl;
        cout << "The child's PID was " << result << "." << endl;
        cout << "The child's return status was " << returnStatus << "." << endl;
        cout << "My x value is " << x << "." << endl;                           // X is unchanged in the parent.
    }
}



void fileExample()
{
    const char * s = "String to write.\n";
    size_t n = strlen(s);
    char buf [n + 1];

    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0755);
    write(fd, s, n);
    close(fd);

    fd = open("foo.txt", O_RDONLY | O_CREAT);
    buf[n] = '\0';
    read(fd, buf, n);
    close(fd);

    cout << buf << endl;
}



int globalT = 0;



void * threadHelper(void * arg)                                                 // Helper function as start point for threads.
{
    int * tid = (int *) arg;
    int localT = 0;

    globalT++;
    localT++;

    cout << "Thread ID: " << tid[0] << ", Global: " << globalT << ", Local: " << localT << "." << endl;
}



void threadExample()
{
    pthread_t tid;
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid, NULL, threadHelper, (void *) &tid);                 // Create and start a thread. Give it its own TID.
        pthread_join(tid, NULL);                                                // Wait for thread to finish.
    }
}



static volatile int flag = 1;



void intHandler(int dummy)
{
    flag = 0;
}



void signalExample()
{
    flag = 1;
    signal(SIGINT, intHandler);                                                 // Changes default signal handler to our custom one.
    cout << "The program is about to enter a trap." << endl;
    cout << "Ctrl-c has been reconfigured to break us out of the trap and not kill the whole program." << endl;
    while(flag);
    cout << "The program has escaped." << endl;
    signal(SIGINT, SIG_DFL);                                                    // Reset to default handler.
}



int main(int argc, char ** argv)
{
    cout << "File Example:" << endl;
    fileExample();
    cout << endl << endl;

    cout << "Fork Example:" << endl;
    forkExample();
    cout << endl << endl;

    cout << "Signal Example:" << endl;
    signalExample();
    cout << endl << endl;

    cout << "Thread Example:" << endl;
    threadExample();
    cout << endl << endl;
}

//==============================================================================
