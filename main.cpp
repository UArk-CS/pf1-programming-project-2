#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string getUserInput() {

    cout << "\n** Please type your selection as seen above **" << endl;

    string userInput;
    cout << "> ";
    getline(cin, userInput);

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

    return userInput;

}

int main() {

    // Map for the wand word choices (in Sickles)
    map<string, int> wandWoodChoices = {
            {"BLACK WALNUT", 10},
            {"EBONY", 17},
            {"REDWOOD", 25}
    };

    // Map for the wind Court choices (in Sickles)
    map<string, int> wandCoreChoices = {
            {"DRAGON HEARTSTRING", 15},
            {"PHOENIX FEATHER", 20},
            {"BASILISK HORN", 30}
    };

    cout << "Welcome to Lord Benz's Ultimate Wizarding Shop" << endl;
    cout << "Let us see if we can find the wand for you."  << endl;
    cout << "\t** 29 knuts = 1 sickle **" << endl;
    cout << "\t** 17 sickles = 1 galleon **" << endl;
    cout << "\nSelect one of our fine woods for your wand:" << endl;
    cout << "\t BLACK WALNUT - A sleek dark finish meant for only those with good instinct - 10 sickles/inch" << endl;
    cout << "\t EBONY - A jet-black wand with a high reputation perfect for those into combative magic - 17 sickles/inch" << endl;
    cout << "\t REDWOOD - A very rare wood that is known to bring good luck to its owner - 25 sickles/inch" << endl;

    string usersWoodChoice = getUserInput();
    cout << usersWoodChoice << endl;

    return 0;

}