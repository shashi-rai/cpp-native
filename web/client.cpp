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

#include "client.h"

namespace web {

const std::string Client::DEFAULT_HOST = "localhost";
const int Client::DEFAULT_PORT = 8000;

Client::Client() : host(DEFAULT_HOST), port(DEFAULT_PORT) {

}

Client::Client(int port) : host(DEFAULT_HOST), port(port) {

}

Client::Client(std::string host, int port) : host(host), port(port) {

}

Client::~Client() {

}

int Client::connectTo(const std::string& serverHost, int serverPort) {
    struct sockaddr_in serv_addr;
    int valread;

    const char *hello = "Hello from Bhojpur Client";
    char buffer[1024] = {0};

    // Create socket file descriptor
    server.setSocket(socket(AF_INET, SOCK_STREAM, 0));
    if (server.isError("Server socket creation failure")) {
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serverPort);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, serverHost.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cout << std::endl<< "Invalid address/ Address not supported" << std::endl << std::endl;
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(server.getSocket(), (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << std::endl
            << "Connection to " << serverHost.c_str() << ":" << serverPort
            << " failed" << std::endl << std::endl;
        exit(EXIT_FAILURE);
    }

    // Send data to the Server
    send(server.getSocket(), hello, strlen(hello), 0);
    std::cout << "Hello message sent" << std::endl;

    // Read data from the Server
    valread = read(server.getSocket(), buffer, 1024);
    std::cout << "Server: " << buffer << std::endl;

    // Close socket
    close(server.getSocket());

    return 0;
}

} // namespace web