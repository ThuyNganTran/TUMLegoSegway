#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace std;
using namespace ev3dev;

int main() {
  bool up = false, down = false, left = false, right = false, enter = false, escape = false;

  // show all port modes for a motor (should be only "tacho-motor")
  printf("OUTPUT_A : %s\n", OUTPUT_A);
  lego_port port( "pistorms:BAM1" );
  cout << OUTPUT_A << " modes: ";
  for (mode_type m : port.modes()) {        
      cout << m << " "; 
  }
  cout << endl;

  // TODO:
  // connection to the motor fails, but
  // motor values are accessible with
  // $ cat /sys/class/tacho-motor/motor8/position
  // note: "motor8" can be something else

  port.set_mode( "tacho-motor" ); // doesn't change much

  large_motor lA = large_motor(OUTPUT_A);
  cout << "l motor A connected: " << (lA.connected()) << endl;
  //cout << "address: " << lA.address() << endl;

/*
  while (escape == 0) {
    up = button::up.pressed ();
    down = button::down.pressed ();
    left = button::left.pressed ();
    right = button::right.pressed ();
    enter = button::enter.pressed ();
    escape = button::back.pressed ();

    //printf ("up:%d down:%d left:%d right:%d enter:%d esc:%d \n", up, down, left, right, enter, escape);
    usleep (100000);
  }
*/
}

