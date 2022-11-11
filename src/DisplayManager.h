#include "ThreadInterface.h"
#include "Singleton.h"

class DisplayManager : public Singleton<DisplayManager>, public ThreadInterface
{
    friend class Singleton<DisplayManager>;

public:
    bool init(void);
    void shutdown() override;

protected:
    void run(void);

private:
    DisplayManager();
    ~DisplayManager();
};
