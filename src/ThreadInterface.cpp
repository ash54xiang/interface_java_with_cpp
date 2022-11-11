#include <assert.h>
#include <pthread.h>
#include "ThreadInterface.h"

using namespace std;

ThreadInterface::ThreadInterface() : threadP(nullptr), threadShutdown(false), threadName("unknown.th")
{
}

ThreadInterface::~ThreadInterface()
{
    shutdown();
}

void runThread(ThreadInterface *pInst, const char *threadNameString)
{
    pthread_setname_np(pthread_self(), threadNameString);
    pInst->run();
}

bool ThreadInterface::init(const char *threadNameString)
{
    threadName = threadNameString;
    threadP = new thread(runThread, this, threadName.c_str());
    return threadP;
}

void ThreadInterface::shutdown(void)
{
    threadShutdown = true;
    if (threadP)
    {
        threadP->join();
        delete threadP;
        threadP = 0;
    }
}
