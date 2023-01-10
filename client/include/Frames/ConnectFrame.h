#pragma once

#include "ExecutableFrame.h"

class ConnectFrame : public Frame {
    private:
        
    public:
        ConnectFrame(StompCommand command, unordered_map<string, string> headers, string frameBody);
        static Frame* get(string host, string port, string username, string password);
};