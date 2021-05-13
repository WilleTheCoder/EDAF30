#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;


int costofSub(char a, char b) {

}

int calc(string x, string y) {

    int sub = calc(x.substr(1), y.substr(1)) + costofSub(x[0], y[0]);
    int insert = calc(x, y.substr(1)) + 1;
    int deleter = calc(x.substr(1), y) + 1;

    return min(sub, insert, deleter);
}



int main() {
    string s1 = "Astronaut";
    string s2 = "Aisk";

    cout << calc(s1, s2);


   

    return 0;
}
