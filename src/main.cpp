#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
using namespace std;

void set_cursor_click(int x, int y)
{
    SetCursorPos(x, y);
    Sleep(100);
    INPUT input[2];
    input[0].type = MOUSE_EVENT;
    input[0].ki.dwFlags = MOUSEEVENTF_LEFTDOWN;
    input[1].type = MOUSE_EVENT;
    input[1].ki.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(2, input, sizeof(INPUT));
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
    INPUT input[2];
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = key;
    input[0].ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = key;
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(2, input, sizeof(INPUT));
}

void fill_niu()
{
    int niu[6] = {0x34, 0x37, 0x38, 0x35, 0x39, 0x32};
    for (int i = 0; i < 6; i++)
    {
        send_key(niu[i]);
        Sleep(100);
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
    for (int i = 0; i < 8; i++)
    {
        send_key(firstname[i]);
        Sleep(300);
    }
    uppering_word('R');
    int lastname[4] = {0x49, 0x5A, 0x51, 0x49};
    for (int i = 0; i < 4; i++)
    {
        send_key(lastname[i]);
        Sleep(300);
    }
}

void maximize_window()
{
    keybd_event(VK_LWIN, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(VK_UP, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
}

void take_screenschot()
{
    keybd_event(VK_LWIN, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(VK_SHIFT, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(0x53, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
}

void ctrl_save()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = 0x53;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = 0x53;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}
void fill_image_name()
{
    uppering_word('P');
    Sleep(100);
    send_key(0x31);
    Sleep(100);
    send_key(0x33);
}
int main()
{
    // system("start https://zoom.us/j/93843429498?pwd=VVR4UjlGejQwWkNhVFNVZ1FKb0ZUUT09");
    // Sleep(7000);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x0D);
    // Sleep(15000);
    // send_key(0x09);
    // Sleep(500);
    // send_key(0x09);
    // Sleep(500);
    // send_key(0x09);
    // Sleep(500);
    // send_key(0x0D);
    // Sleep(500);
    // maximize_window();
    // SetCursorPos(400, 100);
    // mouse_event(MOUSEEVENTF_LEFTDOWN, 400, 100, 0, 0);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x0D);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x0D);
    // Sleep(100);
    // take_screenschot();
    // while(1){
    //     if(GetKeyState(0x0D) & 0x8000){
    //         break;
    //     }
    // }
    // Sleep(1000);
    // set_cursor_click(1200,570);
    // while (1)
    // {
    //     if (GetKeyState(0x0D) & 0x8000)
    //     {
    //         break;
    //     }
    // }
    // send_key(0x09);
    // send_key(0x09);
    // send_key(0x09);
    // send_key(0x09);
    // send_key(0x0D);
    // while(1){
    //     if(GetKeyState(0x08)){
    //         break;
    //     }
    // }
    // fill_image_name();
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x09);
    // Sleep(100);
    // send_key(0x0D);
    system("start https://forms.gle/L93FWKwDZjcDiBGs5");
    Sleep(7000);
    set_cursor_click(300,300);
    send_key(0x09);
    Sleep(100);
    send_key(0x09);
    Sleep(100);
    send_key(0x09);
    Sleep(1000);
    fill_niu();
    send_key(0x09);
    fill_name();
    send_key(0x09);
    for (int i = 0; i < 13; i++)
    {
        send_key(0x28);
    }
    send_key(0x09);
    send_key(0x09);
    return 0;
}