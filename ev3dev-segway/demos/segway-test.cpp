#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "ev3dev.h"

using namespace std;
using namespace ev3dev;

int main() {


  motor lA(OUTPUT_A, "lego-nxt-motor");
  motor lB(OUTPUT_B, "lego-nxt-motor");
  cout << "motor A connected: " << (lA.connected()) << endl;
  cout << "motor B connected: " << (lB.connected()) << endl;

  lA.set_speed_sp(200);
  lB.set_speed_sp(400);

  lA.run_forever();
  lB.run_forever();

  for (int i = 0; i < 200; i++) {
    int posA = lA.position();
    int posB = lB.position();
    printf( "lA pos: %d, lB pos: %d       \r", posA, posB);
    usleep( 10000 );

  }

  lA.stop();
  lB.stop();

  cout << endl << "DONE" << endl;

}

