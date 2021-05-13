#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include "word.h"

using namespace std;

class Dictionary {
public:
	Dictionary();
	bool contains(const string& word) const;
	vector<string> get_suggestions(const string& word) const;
	void add_trigram_suggestions(vector<string> suggestions, string word) const;

private:
	unordered_set <string> wordSet;
	vector<Word> words[25];
};

#endif
