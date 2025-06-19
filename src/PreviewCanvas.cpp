#include "PreviewCanvas.h"
#include <gdiplus.h>
using namespace Gdiplus;

void PreviewCanvas::Initialize(HINSTANCE hInst, HWND parent) {
    GdiplusStartupInput input;
    GdiplusStartup(&gdiplusToken, &input, nullptr);
    RECT rc; GetClientRect(parent, &rc);
    hwndCanvas = CreateWindowEx(0, WC_STATIC, nullptr,
        WS_CHILD | WS_VISIBLE | SS_OWNERDRAW,
        0,0, rc.right, rc.bottom, parent, nullptr, hInst, nullptr);
}

void PreviewCanvas::Render(const Path& path) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwndCanvas, &ps);
    Graphics g(hdc);
    Pen pen(Color(255,0,0,0));
    for (auto const& segs : path.segments)
        for (auto const& s : segs)
            g.DrawLine(&pen, (REAL)s.first.x, (REAL)s.first.y,
                               (REAL)s.second.x,(REAL)s.second.y);
    EndPaint(hwndCanvas, &ps);
}
