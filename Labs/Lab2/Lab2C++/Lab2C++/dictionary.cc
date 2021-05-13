#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "word.h"
#include "dictionary.h"
#include <sstream>
#include <algorithm> 
#include "../../Labber2/Labber2/tri.h"


using namespace std;

Dictionary::Dictionary()
{
	ifstream read("words.txt");
	
	while (read){
		string word;
		read >> word;
		int n_tris;
		read >> n_tris;
		vector<string> tri_vec;
		for (int i = 0; i < n_tris; i++){
			string tri;
			read >> tri;
			tri_vec.push_back(tri);
		}
		if (word.size() < 25) {
			wordSet.insert(word); //add to dictionary
			words[word.size()].push_back(Word(word, tri_vec));
		}
	}
	read.close();

}

bool Dictionary::contains(const string& word) const {
	return (wordSet.find(word) != wordSet.end());
}

vector<string> Dictionary::add_trigram_suggestions(vector<string> suggestions, string word) const {

	int n_tri = nbrOfTrigrams(word);

	vector<string> v = getTrigrams(word);
	if (word.size() < 25) {
		for (int i = word.size() - 1; i <= word.size() + 1; i++) { //go from size() +-1

			for (Word w : words[i]) {

				if (w.get_matches(v) >= n_tri / 2) suggestions.push_back(w.get_word());
			}
		}
	}
	return suggestions;
}

vector<string> Dictionary::rank_suggestions(vector<string> suggestions, string word) const
{

	vector<pair<int, string>> pairs;

	for (string s : suggestions)
	{
		int d[26][26];

		for (size_t i = 0; i <= word.length(); i++)
			d[i][0] = i;
		for (size_t j = 0; j <= s.length(); j++)
			d[0][j] = j;

		for (size_t j = 1; j <= s.length(); j++)
		{
			for (size_t i = 1; i <= word.length(); i++)
			{
				int cost1 = s[j - 1] == word[i - 1] ? d[i - 1][j - 1] : d[i - 1][j - 1] + 1; 
				int cost2 = d[i - 1][j] + 1;	
				int cost3 = d[i][j - 1] + 1;
				d[i][j] = min({ cost1, cost2, cost3 });
			}
		}

		pairs.push_back(make_pair(d[word.length()][s.length()], s));
	}

	suggestions.clear();

	sort(pairs.begin(), pairs.end());

	for (size_t x = 0; x < pairs.size(); x++) { //first = cost / second = word
		suggestions.push_back(pairs[x].second);
	}

	return suggestions;
}

vector<string> Dictionary::trim_suggestions(vector<string> suggestions) const
{
	if((suggestions.size()>=5)) suggestions.erase(suggestions.begin() + 5, suggestions.end());

	return suggestions;
}



vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	suggestions = add_trigram_suggestions(suggestions, word);
	suggestions = rank_suggestions(suggestions, word);
	suggestions = trim_suggestions(suggestions);
	
	return suggestions;
}



