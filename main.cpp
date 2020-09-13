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
    cout << endl;

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

    cout << "Select one of our powerful wand cores:" << endl;
    cout << "\t DRAGON HEARTSTRING - While it can be temperamental, this core is the most powerful and can learn the quickest - 15 sickles" << endl;
    cout << "\t PHOENIX FEATHER - The rarest core there is. It can be tricky to bond with, but it is also the most capable across all magic types - 20 sickles" << endl;
    cout << "\t BASILISK HORN - Only one wand is known to have this core, you could be the second - 30 sickles" << endl;
    string usersCoreChoice = getUserInput();

    cout << "Choose a wand length between 8 and 15 inches (whole numbers only):" << endl;
    int wandLength = stoi(getUserInput());

    cout << usersWoodChoice << " " << usersCoreChoice << " " << wandLength;

    return 0;

}