#include <iostream>
#include "String.h"

#include <string>

using namespace std;

int main()
{
    String test;
    String temp("temp ");
    String foo( temp );

    cout << foo << endl;

    const char *strptr = temp.cString();

    //test += temp;

    if( foo != temp )
    {
        cout << "ack" << endl;
    }
    else
    {
        cout << "sss" << endl;
    }

    //cout << (temp + test) << endl;

    //cout << test << endl;

    return 0;
}
