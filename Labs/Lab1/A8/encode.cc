#include <iostream>
#include <fstream>
#include <iomanip>
#include "coding.h"
#include <string>
using namespace std;

void encode_file(string filename)
{
    ifstream in("./" + filename + ".txt");
  
    char c;
    ofstream out("./" + filename+"_ENC" + ".txt");
  
    if (in.is_open() && out.is_open()){

    while ((c = in.get()) != EOF) {
        out.put(encode(c));
    }
    }
    in.close();
    out.close();
  
}

int main()
{
    string readfile;
    cout << "Enter filename: ";
    cin >> readfile;

    encode_file(readfile);

    return 0;
}
