
#include "UserTable.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	UserTable u("users.txt");
	
	ofstream out("test.txt");

	cout << u.find(21330) << endl;
	cout << u.find(21331) << endl;
	cout << u.find("Jens Holmgren") << endl;

	cout << "testFindNbr: " << testFindNbr(u) << endl;

	u.addUser(User(1234, "Wille"));
	cout << u.find("Wille") << endl;
	u.print(out);
	
	return 0;
}

//What is the result of the program? What did you expect?
	//Prints out "(-1) Not Found" for all cases
	//Expected to return true (find elements)

//Call to function "printed(outstream s)" and see what is printed.
	//A empty list is printed

// How many users are now in the table ? How many did you expect ?
	//Expected it to print out the user we just added

//Find and fix the mistake that you identified in the previous task
	//AddUser inc nbrofusers int n fel

//Check if searching for a card number works
	//does not work

//Fix error in function find(std::string name)
	//fixat, den kolla endast första usern i listan.. 


