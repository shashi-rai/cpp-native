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

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "web/client.h"
#include "web/server.h"

void print_copyright() {
    std::cout << "Application Software" << std::endl;
    std::cout << "Copyright (c) 2018 by Bhojpur Consulting Private Limited, India" << std::endl;
    std::cout << "All rights reserved." << std::endl << std::endl;
}

void client_test() {
    web::Client client;
    client.connectTo("127.0.0.1", 8000);
}

void server_test() {
    web::Server server;
    server.run();
}

int main(int argc, char* argv[]) {
    bool verbose_mode = false;
    bool client_mode = false;
    bool server_mode = false;
    if (argc > 1) { // options exist, identify it
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "-v" || arg == "--verbose") {
                verbose_mode = true;
            } else if (arg == "-c" || arg == "--client") {
                client_mode = true;
            } else if (arg == "-s" || arg == "--server") {
                server_mode = true;
            }
        }
    } else {
        std::cout << "command-line arguments required" << std::endl;
    }

    if (verbose_mode) {
        print_copyright();
    } else if (client_mode) {
        client_test();
    } else if (server_mode) {
        server_test();
    }

    return 0;
}
