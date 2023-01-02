#include <unistd.h>
#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include "../include/lib/windowService.hpp"
#include "../include/lib/keyboardService.hpp"

#define TETRIS_BOARD_WIDTH 10
#define TETRIS_BOARD_HEIGHT 16
#define FPS 60

#define EMPTY 0
#define BLOCK_FILLED 1


int main()
{
    const double frameTime = 1 / (double)FPS * 1e3; // ms

    Model tetrisModel(TETRIS_BOARD_HEIGHT, std::vector<int>(TETRIS_BOARD_WIDTH, 1));
    KeyboardService keyboardService = KeyboardService();
    WindowService windowService = WindowService(TETRIS_BOARD_WIDTH, TETRIS_BOARD_HEIGHT);

    windowService.registerStyle(EMPTY, "");
    windowService.registerStyle(BLOCK_FILLED, "█");


    std::thread t1(&KeyboardService::run, keyboardService);

    for (;;)
    {
        std::queue<char> keys = keyboardService.getKeys();
        // for (int key : keys)
        // {
        //     tetrisGameService.accpet(key, model);
        // }
        if (!keys.empty())
        {
            tetrisModel[3][3] = keys.front() - 'A';
            std::cout << keys.front() - 'A' << " ";
        }
        windowService.draw(&tetrisModel);
        usleep(frameTime * 1e3); // us
    }

    t1.join();
}