#include <sstream>
#include <fstream>
#include "TagRemover.h"

using namespace std;

/*
int main() {

    ifstream file("tags.html");
    ofstream out("no_tags.html");

    if (file.is_open()) {
        cout << "Removing tags from file [tags.html].." << endl;
        TagRemover tagRemover(file);
        cout << "Writing results to [no_tags.html] .." << endl;
        tagRemover.print(out);
    }
    else {
        cout << "Error, couldnt find file\n";
    }
}
*/
