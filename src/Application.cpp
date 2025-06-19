#include "Application.h"
#include "ImportManager.h"
#include "ParameterManager.h"
#include "PathGenerator.h"
#include "PreviewCanvas.h"
#include "ExportManager.h"
#include "resource.h"

Application::Application(HINSTANCE hInst)
    : hInstance(hInst), mainWindow(nullptr) {}

bool Application::Initialize() {
    WNDCLASS wc{};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("PmaXWireCutMain");
    RegisterClass(&wc);

    mainWindow = CreateWindowEx(
        0, wc.lpszClassName, TEXT("PmaX Wire Cut"),
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        1024, 768, nullptr, nullptr, hInstance, nullptr);
    if (!mainWindow) return false;
    ShowWindow(mainWindow, SW_SHOW);
    return true;
}

int Application::Run() {
    if (!Initialize()) return -1;
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK Application::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDM_IMPORT:
            DialogBoxParam(hwnd, MAKEINTRESOURCE(0), hwnd, ImportDlgProc, 0);
            break;
        case IDM_SETUP:
            DialogBoxParam(hwnd, MAKEINTRESOURCE(1), hwnd, SetupDlgProc, 0);
            break;
        case IDM_GENERATE:
            // Start generation
            break;
        case IDM_EXPORT:
            DialogBoxParam(hwnd, MAKEINTRESOURCE(2), hwnd, ExportDlgProc, 0);
            break;
        case IDM_EXIT:
            PostQuitMessage(0);
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
