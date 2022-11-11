#include <iostream>
#include <chrono>
#include "DisplayManager.h"

using namespace std;

DisplayManager::DisplayManager() : ThreadInterface()
{
    ThreadInterface::init("displayManager.th");
}

DisplayManager::~DisplayManager()
{
}

bool DisplayManager::init(void)
{
    cout << "Initializing DisplayManager thread..." << endl;
    return true;
}

void DisplayManager::shutdown()
{
    cout << "Shutting down DisplayManager thread..." << endl;
    ThreadInterface::shutdown();
}

void DisplayManager::run()
{
    cout << "Running DisplayManager thread..." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
}
