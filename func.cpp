
#include "func.h"

// Func::Func()
// {

// }

// string Func::log_in(string uname, string pass)
// {
//     string one_account;
//     ifstream info;
//     info.open("info.txt");
//     if (info.is_open()) 
//     {
//         while(info>>one_account)
//         {
//             return one_account + "\n";
//         }
//     }
// }

// void Func::printInfo()
// {
//     string one_account;
//     ifstream info;
//     info.open("info.txt");
//     if (info.is_open()) 
//     {
//         while(info>>one_account)
//         {
//             cout << one_account << endl;
//         }
//     }
// }
void printInfo()
{
    string one_account;
    ifstream info;
    info.open("info.txt");
    if (info.is_open()) 
    {
        while(info>>one_account)
        {
            cout << one_account << endl;
        }
    }
}

int main()
{
    printInfo();
    return 0;
}