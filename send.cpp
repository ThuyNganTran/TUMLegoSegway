//
//  test_pistorm.cpp
//  
//
//  Created by Dao Thuy Ngan Tran on 23.10.17.
//
//

#include <stdio.h>
#include <iostream>
#include <tins/tins.h>
#include "boost/array.hpp"
#include "boost/asio.hpp"

using namespace Tins;
using namespace std;
using namespace boost::asio;

void send_to(string message){
    
    io_service io_service;
    ip::udp::endpoint local_endpoint;
    
    local_endpoint = ip::udp::endpoint(ip::address::from_string("131.159.222.111"), 63160);
    
    ip::udp::socket socket(io_service);
    
    socket.connect(local_endpoint);
    
    boost::array<char, 128> buf;
    copy(message.begin(),message.end(),buf.begin());
    socket.send(buffer(buf, message.size()));
    socket.close();
}


int main(int arg, char** args){
    int count = 0;
    while(count < 5){
    send_to("Test" + to_string(count));
        sleep(1);
        count++;
    }
    return 0;
}
