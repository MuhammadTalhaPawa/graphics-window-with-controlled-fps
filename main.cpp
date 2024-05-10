#include <graphics.h>
#include <iostream>
#include <ctime>

using namespace std;

const int FPS = 60;

void setup()
{
}

void update(double delta_time)
{
}

void show()
{
}

void debug()
{
}

int main()
{
    initwindow(800, 600);

    double delta_time = 0;
    double frame_time = 1000 / FPS;
    double update_time = 0;

    setup();

    clock_t start_time_frame, start_time_update, now_time, end_time;
    start_time_frame = clock();
    start_time_update = clock();
    now_time = clock();
    end_time = clock();

    while (!ismouseclick(WM_CLOSE)) // Continue until close button is pressed
    {
        debug();
        now_time = clock();

        if (now_time - start_time_update > update_time)
        {
            delta_time = now_time - start_time_update;
            update(delta_time);
            start_time_update = now_time;
        }

        if (now_time - start_time_frame > frame_time)
        {
            cleardevice();
            show();
            start_time_frame = now_time;
        }

        end_time = clock();
    }

    getchar();
    closegraph();
    return 0;
}
