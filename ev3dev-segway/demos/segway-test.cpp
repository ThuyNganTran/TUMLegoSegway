#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace std;
using namespace ev3dev;

int main() {
  bool up = false, down = false, left = false, right = false, enter = false, escape = false;

  // new stuff here
  printf("A: %s\n", OUTPUT_A);
  lego_port port( "pistorms:BAM1" );
  cout << "BAM1 modes: ";
  for (mode_type m : port.modes()) {        
      cout << m << " "; 
  }
  cout << endl;




  //medium_motor mA = medium_motor(OUTPUT_A);
  //cout << "m motor A connected: " << (mA.connected()) << endl;

  large_motor lA = large_motor(OUTPUT_A);
  cout << "l motor A connected: " << (lA.connected()) << endl;




  while (escape == 0) {
    up = button::up.pressed ();
    down = button::down.pressed ();
    left = button::left.pressed ();
    right = button::right.pressed ();
    enter = button::enter.pressed ();
    escape = button::back.pressed ();

    //printf ("up:%d down:%d left:%d right:%d enter:%d esc:%d banana! 42\n", up, down, left, right, enter, escape);
    usleep (100000);

    // new stuff here
    //cout << "motor connected: " << (m.connected()) << endl;
    cout << "motor position: " << (lA.position()) << endl;

  }
}

