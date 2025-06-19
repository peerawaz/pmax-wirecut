#pragma once
#include <windows.h>
#include "Path.h"

class PreviewCanvas {
public:
    void Initialize(HINSTANCE hInst, HWND parent);
    void Render(const Path& path);
private:
    HWND hwndCanvas;
    ULONG_PTR gdiplusToken;
};
