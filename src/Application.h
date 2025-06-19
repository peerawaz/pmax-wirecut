#pragma once
#include <windows.h>

class Application {
public:
    Application(HINSTANCE hInst);
    int Run();
private:
    HINSTANCE hInstance;
    HWND mainWindow;
    bool Initialize();
    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};
