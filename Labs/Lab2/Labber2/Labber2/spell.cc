#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include "dictionary.h"
#include <fstream>

using namespace std;

void check_word(const string& word, const Dictionary& dict)
{
    if (dict.contains(word)) {
        cout << "Correct." << endl;
    } else {
        vector<string> suggestions = dict.get_suggestions(word);
        if (suggestions.empty()) {
            cout << "Wrong, no suggestions." << endl;
        } else {
            cout << "Wrong. Suggestions:" << endl;
            for (const auto& w : suggestions) {
                cout << "    " << w << endl;
            }
        }
    }
}

int ntrigrams(string text) {
    cout << "Processing number of trigrams.." << "\n";
    int size = text.size();
    int n = 0;
    if (size > 2) {
        n = size-2;
    }
    
    return n;
}

void trigram(ofstream &write,string text) {
    cout << "Processing trigram execussion.." << "\n";
    
    string wordexpr = text+" "+to_string(ntrigrams(text)) ;
    if (text.size()>2) {
        for (int i = 0; i <= text.size() - 3; i++) {
            wordexpr.append(" " + wordexpr.substr(i, 3));
        }
    }

    write << wordexpr<<"\n";
   
}

void preprocess() {
    cout << "Preprocessing.." << "\n";
    ifstream read("dict.txt");
    ofstream write("words.txt");
   
    string text;


    while (getline(read, text) && !text.empty()) {
        transform(text.begin(), text.end(), text.begin(), tolower); //converting to lowercase
        trigram(write,text);
  
    }

 
}



        
   
int main() {

	Dictionary dict;

    preprocess();


    return 0;
}



