#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "tri.h"
using namespace std;

vector<string> getTrigrams(string word)
{
	cout << "Calculating trigrams.." << endl;

	vector<string> tri;
	for (int i = 0; i < nbrOfTrigrams(word); i++) {
		tri.push_back(word.substr(i, 3));
	}
	sort(tri.begin(), tri.end());
	return tri;
}

int nbrOfTrigrams(string word)
{
	int n = word.size() - 2;
	if (n < 0) { return 0; }
	return n;
}

void proc(string word, ofstream& out)
{
	cout << "Processing words.." << endl;

	int n = nbrOfTrigrams(word);
	out << word + " ";
	out << n;
	vector<string> tri = getTrigrams(word);
	for (string t : tri) {
		out << " " + t;
	}
	out << "\n";
}
