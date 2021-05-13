#include "date.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

using namespace std;

template <typename T>
T string_cast(string string){
    stringstream ss;
    ss << string;
    T t;
    ss >> t;
    if (ss.fail() || !ss.eof()){
        throw invalid_argument("Invalid syntax.");
    }
    return t;
}

int main(){
    try{
        int i = string_cast<int>("123");
        cout << i << endl;

        double d = string_cast<double>("12.34");
        cout << d << endl;
        Date date = string_cast<Date>("2015-01-10");
        cout << date << endl;

     //   Date datedummy = string_cast<Date>("fel");
     //   cout << datedummy << endl;

     //   double doubleDummy = string_cast<double>("waa");
     //   cout << doubleDummy << endl;

       int intDummy = string_cast<int>("123kalleanka");
        cout << intDummy << endl;
    }
    catch (invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
}

