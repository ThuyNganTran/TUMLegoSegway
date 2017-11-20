~~ C++ cross compilation for raspberry + pistorms ~~

Details here:
	https://github.com/ddemidov/ev3dev-lang-cpp

Quick steps:
1. Edit source code, it is located in
	[...] ev3dev-segway/demos/segway-test.cpp

2. Cross compile the code from the following directory
	[...] ev3dev-segway/build
	use (some packages might be required)
	$ cmake .. -DEV3DEV_PLATFORM=PISTORMS
	$ make

3. Copy executable to the raspberry
	$ scp demos/segway-test robot@10.42.0.29:/home/robot/ev3dev-from-ubuntu/
