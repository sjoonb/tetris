#include "../../include/lib/windowService.hpp"

WindowService::WindowService(int width, int height)
{
    styleMap = new std::map<int, const char *>();
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    win = newwin(height + 2, width + 2, 2, 10);
    refresh();
}
WindowService::~WindowService()
{
    endwin();
}
void WindowService::draw(Model *board)
{
    box(win, 0, 0);
    for (int row = 0; row < (int)(*board).size(); ++row)
    {
        for (int col = 0; col < (int)(*board)[row].size(); ++col)
        {
            int key = (*board)[row][col];
            const char *value = "";
            if (styleMap->find(key) != styleMap->end())
            {
                value = (*styleMap)[key];
            }
            mvwprintw(win, row + 1, col + 1, value);
        }
    }
    wrefresh(win);
}
void WindowService::registerStyle(int key, const char *value)
{
    (*styleMap)[key] = value;
}
