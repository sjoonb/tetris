#ifndef KEYBOARD_SERVICE_HPP
#define KEYBOARD_SERVICE_HPP

#include <unistd.h>
#include <termios.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <mutex>
#include "./common/sharedQueue.hpp"

class KeyboardService
{
public:
    KeyboardService();
    void *run();
    std::queue<char> getKeys();

private:
    SharedQueue<char> *q;
    char getInput();
};



#endif
