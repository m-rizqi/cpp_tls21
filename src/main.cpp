#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

void set_cursor_click(int x, int y)
{
    SetCursorPos(x, y);
    Sleep(3000);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
}

void scroll(int n)
{
    INPUT input;
    WORD vkey = 0x28;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = 0;
    for (int i = 0; i < n; i++)
    {
        SendInput(1, &input, sizeof(INPUT));
    }
    Sleep(3000);
}

void get_coordinate()
{
    while (1)
    {

        char g = getch();
        int x, y;
        POINT xypos;

        if (g == 'S' || g == 's')
        {
            cout << "Enter new position" << endl;
            cin >> x >> y;
            SetCursorPos(x, y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        }
        else if (g == 'G' || g == 'g')
        {
            GetCursorPos(&xypos);
            cout << "x : " << xypos.x << "\ty : " << xypos.y << endl;
        }
    }
}

void send_key(int key)
{
    INPUT input;
    WORD vkey = key;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void fill_niu()
{
    int niu[6] = {0x34, 0x37, 0x38, 0x35, 0x39, 0x32};
    for (int i = 0; i < 6; i++)
    {
        send_key(niu[i]);
        Sleep(700);
    }
}

void uppering_word(char word)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = VK_SHIFT;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = word;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = word;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = VK_SHIFT;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void fill_name()
{
    uppering_word('M');
    int firstname[8] = {0x55, 0x48, 0x41, 0x4D, 0x4D, 0x41, 0x44, 0x20};
    for (int i = 0; i < sizeof(firstname); i++)
    {
        send_key(firstname[i]);
        Sleep(500);
    }
    uppering_word('R');
    int lastname[4] = {0x49, 0x5A, 0x51, 0x49};
    for (int i = 0; i < sizeof(firstname); i++)
    {
        send_key(lastname[i]);
        Sleep(500);
    }
}

int main()
{
    system("start https://forms.gle/LQ5KL7XgZN7hrAKRA");
    Sleep(7000);
    send_key(0x09);
    Sleep(500);
    send_key(0x09);
    Sleep(500);
    send_key(0x09);
    Sleep(1000);
    // set_cursor_click(357, 640);
    fill_niu();
    send_key(0x09);
    fill_name();
    return 0;
}