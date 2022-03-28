/**
Copyright (c) 2019 Dan Orban
*/

#include <iostream>
#include <map>
#include "drone_app.h" 

using namespace csci3081;

int main(int argc, char**argv) {
    if (argc > 0) {
        int port = std::atoi(argv[1]);

        // Create a web sockets server at a specific port number
        WebServer<DroneApp> server(port, "web");
        while (true) {
            // Handle requests from clients
            server.service();
        }
    }
    else {
        std::cout << "Usage: ./drone_app 8081" << std::endl;
    }

    return 0;
}


