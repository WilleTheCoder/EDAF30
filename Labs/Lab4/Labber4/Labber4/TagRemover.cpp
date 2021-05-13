#include "TagRemover.h"
#include <sstream>

using namespace std;

string replacer(string& code)
{
    if (code.compare("&amp;") == 0)
        return "&";
    if (code.compare("&nbsp;") == 0)
        return "space ";
    if (code.compare("&lt;") == 0)
        return "<";
    if (code.compare("&gt;") == 0)
        return ">";
    return code;
}

TagRemover::TagRemover(istream& in) {
    string line;
    //read instream file append to [string text]
    while (getline(in, line)) {
        text.append(line);
        text.append("\n");
    }

    int start = text.find('<');
    int end = text.find('>');

    //Removes tags <...>
    while (end != -1) {      //no matches. return -1
        int tag_length = end - start + 1; //length word wanna erase

        text.erase(start, tag_length);
        start = text.find('<');
        end = text.find('>');
    }

    //Removes special characters &amp; etc
    auto s = text.find('&');
    while (s != -1) {
        auto end = text.find(';', s);
        int rep_length = end - s + 1; // rep_length
        auto rep = text.substr(s, rep_length); //find string to replace
        text.replace(s, rep_length, replacer(rep));
        s = text.find('&', s + 1);
    }

}

void TagRemover::print(ostream& out) {
    out << text << endl;
}