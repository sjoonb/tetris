#include <iostream>
#include <thread>
#include <cstdlib>
#include "../lib/keyboardService.cpp"

int main()
{
    KeyboardService keyboardService = KeyboardService();
    std::thread t1(&KeyboardService::run, keyboardService);

    for (;;)
    {
        std::queue<char> keys = keyboardService.getKeys();
        usleep(16 * 1e4); // us
    }

    t1.join();
}