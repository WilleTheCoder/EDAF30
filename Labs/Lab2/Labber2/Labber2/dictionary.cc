#include <iostream>
#include "sos.h"
#include <fstream>
#include <string>
#include <vector>
#include "word.h"
#include <cctype>
#include "dictionary.h"
#include <sstream>


using namespace std;

Dictionary::Dictionary() {
	cout << "Inserting elements in set.. \n";
	ifstream read("test.txt");

	while (read) {
		string word;
		read >> word;
		int n_tris;
		read >> n_tris;
		vector<string> vec_tris;
		for (int i = 0; i < n_tris; i++) {
			string tri;
			read >> tri;
			vec_tris.push_back(tri);
		}
		if (word.size() < 26) {
			wordSet.insert(word);
			words[word.size()].push_back(Word(word, vec_tris));
		}
	}
	read.close();
}

bool Dictionary::contains(const string& word) const {
	return (wordSet.find(word) != wordSet.end());
}

void Dictionary::add_trigram_suggestions(vector<string> suggestions, string word) const {

	int n_tri = word.size() - 2;
	int size = word.size();

	vector<string> v = trye(word, n_tri);

	for (int i = word.size() - 1; i <= word.size() + 1; i++) {


		for (Word w : words[i]) {
		}
}
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	//	rank_suggestions(suggestions, word);
	//	trim_suggestions(suggestions);
	return suggestions;
}



