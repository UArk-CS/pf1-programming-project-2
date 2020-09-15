#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void woodMenuOutput() {

    cout << "Select one of our fine woods for your wand:" << endl;
    cout << "\t BLACK WALNUT - A sleek dark finish meant for only those with good instinct - 10 sickles/inch" << endl;
    cout << "\t EBONY - A jet-black wand with a high reputation perfect for those into combative magic - 17 sickles/inch" << endl;
    cout << "\t REDWOOD - A very rare wood that is known to bring good luck to its owner - 25 sickles/inch" << endl;

}

void coreMenuOutput() {

    cout << "Select one of our powerful wand cores:" << endl;
    cout << "\t DRAGON HEARTSTRING - While it can be temperamental, this core is the most powerful and can learn the quickest - 15 sickles" << endl;
    cout << "\t PHOENIX FEATHER - The rarest core there is. It can be tricky to bond with, but it is also the most capable across all magic types - 20 sickles" << endl;
    cout << "\t BASILISK HORN - Only one wand is known to have this core, you could be the second - 30 sickles" << endl;

}

void wandLengthOutput() {

    cout << "Now all that is left, what length would you like your wand? (between 8-15 inches)" << endl;

}

string getUserInput() {

    cout << "\n** Please type your selection as seen above **" << endl;

    string userInput;
    cout << "> ";
    getline(cin, userInput);
    cout << endl;

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

    return userInput;

}

string validateUserInput(string userInput, map<string, int> validChoices, void outputFunction()) {

    userInput = getUserInput();

    auto it = validChoices.begin();

    while(it != validChoices.end()) {
        string choice = it->first;

        if(choice == userInput) {
            return userInput;
        } else if(next(it) == validChoices.end()){
            cout << "!!! Invalid input. Please try again with a valid answer. !!!\n" << endl;
            outputFunction();
            userInput = getUserInput();
            it = validChoices.begin();
        } else if(choice != userInput) {
            it++;
        }
    }

}

int main() {

    // Map for the wand word choices (in Sickles)
    map<string, int> wandWoodChoices = {
            {"BLACK WALNUT", 10},
            {"EBONY", 17},
            {"REDWOOD", 25}
    };

    // Map for the wand core choices (in Sickles)
    map<string, int> wandCoreChoices = {
            {"DRAGON HEARTSTRING", 15},
            {"PHOENIX FEATHER", 20},
            {"BASILISK HORN", 30}
    };

    // Map for the wand length choices
    map<string, int> wandLengthChoices = {
            {"8", 8},
            {"9", 9},
            {"10", 10},
            {"11", 11},
            {"12", 12},
            {"13", 13},
            {"14", 14},
            {"15", 15}
    };

    cout << "Welcome to Lord Benz's Ultimate Wizarding Shop" << endl;
    cout << "Let us see if we can find the wand for you."  << endl;
    cout << "\t** 29 knuts = 1 sickle **" << endl;
    cout << "\t** 17 sickles = 1 galleon **" << endl;

    woodMenuOutput();
    string usersWoodChoice;
    usersWoodChoice = validateUserInput(usersWoodChoice, wandWoodChoices, woodMenuOutput);

    coreMenuOutput();
    string usersCoreChoice;
    usersCoreChoice = validateUserInput(usersCoreChoice, wandCoreChoices, coreMenuOutput);

    wandLengthOutput();
    string wandLength;
    wandLength = validateUserInput(wandLength, wandLengthChoices, wandLengthOutput);

    cout << usersWoodChoice << " " << usersCoreChoice << " " << wandLength;

    return 0;

}