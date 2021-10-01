#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    system("start https://forms.gle/LQ5KL7XgZN7hrAKRA");

    std::chrono::seconds dura(10);
    std::this_thread::sleep_for(dura);

    INPUT input;
    WORD vkey = VK_DOWN; // see link below
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
    SendInput(1, &input, sizeof(INPUT));
    SendInput(1, &input, sizeof(INPUT));
    SendInput(1, &input, sizeof(INPUT));
    SendInput(1, &input, sizeof(INPUT));

    Sleep(3000);

    int x = 357, y = 650;
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);

    // while(1){

    //     char g = getch();
    //     int x, y;
    //     POINT xypos;

    //     if (g == 'S' || g == 's')
    //     {
    //         cout << "Enter new position" << endl;
    //         cin >> x >> y;
    //         SetCursorPos(x, y);
    //         mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    //     }
    //     else if (g == 'G' || g == 'g')
    //     {
    //         GetCursorPos(&xypos);
    //         cout << "x : " << xypos.x << "\ty : " << xypos.y << endl;
    //     }
    // }
    return 0;
}
