#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <mutex>

using namespace std;

mutex g_lock;

void proc_call(int decide)
{
    int local = 0, status;
    g_lock.lock();

    pid_t pr; /*идентификатор процесса*/
    pr = fork(); /*создание нового процесса*/
    if(pr == 0) /*успешное создание?*/
    {
		/*путь, указатели на аргументы, 0*/
        execl("secondary", " ", to_string(decide).c_str(), NULL);
    }
    g_lock.unlock();
	/*приостанавливаем работу до завершения процесса*/
    wait(&status);
}

int main(void)
{ 
    proc_call(1);
    proc_call(2);
    proc_call(3);

    exit(0);
}