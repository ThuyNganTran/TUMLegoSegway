#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace std;
using namespace ev3dev;

int main() {

    int delay = 2000000;

    while (true) {

        // show red, blue, green, white
        led::red_left.on();
        usleep (delay);
        
        led::red_left.off();
        led::blue_left.on();
        usleep (delay);

        led::blue_left.off();
        led::green_left.on();
        usleep (delay);

        led::green_left.on();
        led::red_left.on();
        usleep (delay);

        led::all_off();
        usleep (delay);

        // fade green
        for (float b = 0; b < 1; b += 0.001) {
            led::green_left.set_brightness_pct(b);
            usleep (delay / 500);
        }
        usleep (delay/4);
        for (float b = 1; b > 0; b -= 0.001) {
            led::green_left.set_brightness_pct(b);
            usleep (delay / 500);
        }
        led::all_off();
        usleep (delay*2);

    }
}

