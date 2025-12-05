// Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "server.h"

namespace web {

const std::string Server::DEFAULT_HOST = "localhost";
const int Server::DEFAULT_PORT = 8000;

Server::Server() : host(DEFAULT_HOST), port(DEFAULT_PORT) {

}

Server::Server(int port) : host(DEFAULT_HOST), port(port) {

}

Server::Server(std::string host, int port) : host(host), port(port) {

}

Server::~Server() {

}

int Server::run() {
    struct sockaddr_in address;
    FileDescriptor consumer;;
    int opt = 1, addrlen = sizeof(address);

    char buffer[1024] = {0};
    const char *hello = "Hello from Bhojpur Server";

    // Create a server socket file descriptor
    provider.setSocket(socket(AF_INET, SOCK_STREAM, 0));
    if (provider.isError(-1, "Server socket creation failure")) {
        exit(EXIT_FAILURE);
    }

    // Attach socket to service port
	setsockopt(provider.getSocket(), SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all available network interfaces
    address.sin_port = htons(port);

    // Bind server socket to the specified IP address and port
    if (bind(provider.getSocket(), (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connection requests from the Clients
    if (listen(provider.getSocket(), 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept a new Client connection
    consumer.setSocket(accept(provider.getSocket(), (struct sockaddr *)&address, (socklen_t*) &addrlen));
    if (consumer.isError("accept")) {
        exit(EXIT_FAILURE);
    }

    // Read data from client
    read(consumer.getSocket(), buffer, 1024);
    std::cout << "Client: " << buffer << std::endl;

    // Send data to client
    send(consumer.getSocket(), hello, strlen(hello), 0);
    std::cout << "Hello message sent to Bhojpur Client" << std::endl;

    // Close sockets
    close(consumer.getSocket());
    close(provider.getSocket());

    return 0;
}

} // namespace web
