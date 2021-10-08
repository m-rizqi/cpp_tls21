#include <fstream>
#include <string>
#include <iostream>
using std::string;
using namespace std;
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
