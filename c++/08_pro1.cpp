#include <iostream>

using namespace std;

class GameWindow {
public:
    GameWindow();
    GameWindow(int, int);

    int GetW();
    int GetH();

    void ResizeWindow(int, int); 

private:
    int w;
    int h;
};

GameWindow::GameWindow() : w(800), h(600) {}
GameWindow::GameWindow(int w, int h)  {
    ResizeWindow(w, h);
}

int GameWindow::GetW() {return w;}
int GameWindow::GetH() {return h;}

void GameWindow::ResizeWindow(int w, int h) {
    if ( this->w < 800) this->w = 800;
    else this->w = w;
    if ( this->h < 600) this->h = 600;
    else this->h = h;
}

int main() {
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366,768);

    cout << mainWindow.GetW() << ", " << mainWindow.GetH() << endl;
}