#include <string>
#include <vector>
#include "word.h"
#include <fstream>
#include <iostream>
#include <sstream>  

using namespace std;

Word::Word(const string& w, const vector<string>& t){
	vec = t;
	word = w;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	string tri;
	int n = 0;

	for (string tri : t) {
		for (string other_tri : vec) {
			int i = tri.compare(other_tri);
			if (i < 0) break;
			if (i == 0) n++;
		}
}

	return n;
}
