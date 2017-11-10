CC = g++
CCFLAGS = -std=c++11 -O3

all: test

send: send.cpp
	$(CC) $(CCFLAGS) send.cpp -DBOOST_LOG_DYN_LINK -lboost_system -lboost_thread-mt -o $@

clean: 
	rm -f send

.PHONY: all clean
