#include "date.h"
#include <iostream>
#include <sstream>

using namespace std;

template<typename T> //generic type definition<T>
string toString(T& t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

/*
int main() {
    double d = 1.234;
    Date today;
    string sd = toString<double>(d);
    string st = toString<Date>(today);
    cout << sd << endl;
    cout << st << endl;
}
*/
