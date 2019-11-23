#ifndef FUNC_H_
#define FUNC_H_

#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <map>

using namespace std;

// class Func
// {
//     public:
//         Func();
//         string log_in(string uname, string pass);
//         void printInfo();
// };
class LogIn{
    public: 
        LogIn();
        string log_in(string uname, string pass);
        void printInfo();
};

class Subscribtion{
    public:
        map<string, string> subscribtion;
        Subscribtion();
        bool isSubscribed(string subscribe, string subscriber);
        void Subscribe(string subscribe, string subscriber);
        void Unsubscribe(string subscribe, string subscriber);
};

#endif