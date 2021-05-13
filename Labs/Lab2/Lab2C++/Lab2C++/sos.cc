#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <fstream>
#include "sos.h"




vector<string> sos::trye(const string word, size_t n_tri)
{
    cout << "Processing trigram execussion.." << "\n";

    vector<string> v1;

    for (int i = 0; i <= word.size() - 3; i++) {
        v1.push_back(word.substr(i, 3));
    }
    sort(v1.begin(), v1.end());

    return v1;
}
