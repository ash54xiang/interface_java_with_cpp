#include <thread>
#include <memory>
#include <string>

class ThreadInterface
{
private:
    std::thread *threadP;
    bool threadShutdown;
    std::string threadName;

public:
    ThreadInterface();
    virtual ~ThreadInterface();
    virtual void shutdown();
    bool isShutdown() const { return threadShutdown; }
    bool init(const char *threadName);
    virtual void run(void) = 0;
};
