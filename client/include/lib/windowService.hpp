#ifndef WINDOW_SERVICE_HPP
#define WINDOW_SERVICE_HPP

#include <ncurses.h>
#include <vector>
#include <iostream>
#include <map>

typedef std::vector<std::vector<int>> Model;

class WindowService
{
public:
    WindowService(int width, int height);
    ~WindowService();
    void draw(Model* board);
    void registerStyle(int key, const char* value);

private:
    WINDOW *win;
    std::map<int, const char*>* styleMap;
};


#endif
