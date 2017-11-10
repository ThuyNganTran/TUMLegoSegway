//
//  receive.cpp
//  
//
//  Created by Dao Thuy Ngan Tran on 09.11.17.
//
//

#include "receive.hpp"
#include <stdio.h>
#include <iostream>
#include <tins/tins.h>
#include "boost/asio.hpp"
#inclue "boost/system.hpp"

using namespace Tins;
using namespace std;
using namespace boost::asio;

void handle_receive(  const boost::system::error_code& error, // Result of operation.
                    std::size_t bytes_transferred){
    cout << error;
}

int main(int arg, char** args){
    io_service io_service;
    ip::udp::endpoint local_endpoint_;
    local_endpoint_ =
    socket.open(ip::udp::v4());
    socket.async_receive_from(buffer(recv_buffer, 8), local_endpoint_, handle_receive);
}