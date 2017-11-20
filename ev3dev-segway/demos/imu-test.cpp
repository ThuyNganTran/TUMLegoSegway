#include <unistd.h>
#include <cstdio>
#include <iostream>

#include "../ev3dev.h"

using namespace std;
using namespace ev3dev;

int main( int argc, char* argv[] )
{
  lego_port imu_port( "pistorms:BAS2" );
  imu_port.set_mode( "i2c-thru" );
  i2c_sensor imu( "pistorms:BAS2:i2c17", { "ms-absolute-imu" } );

  printf( "%s\n", (imu.connected() ? "connected" : "not connected") );

  while( true )
  {
    int imuval = imu.value();
    printf( "imu: %d       \r", imuval );
    usleep( 10000 );
  }

  return 0;
}
