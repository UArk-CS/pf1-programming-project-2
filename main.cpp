#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// Galleon in terms of sickles
const int GALLEON = 17;

void woodMenuOutput() {

    cout << "Select one of our fine woods for your wand:" << endl;
    cout << "\t BLACK WALNUT - A sleek dark finish meant for only those with good instinct - 10 sickles/inch" << endl;
    cout << "\t EBONY - A jet-black wand with a high reputation perfect for those into combative magic - 17 sickles/inch" << endl;
    cout << "\t REDWOOD - A very rare wood that is known to bring good luck to its owner - 25 sickles/inch" << endl;

}

void coreMenuOutput() {

    cout << "Select one of our powerful wand cores:" << endl;
    cout << "\t DRAGON HEARTSTRING - While it can be temperamental, this core is the most powerful and can learn the quickest - 15 sickles/inch" << endl;
    cout << "\t PHOENIX FEATHER - The rarest core there is. It can be tricky to bond with, but it is also the most capable across all magic types - 20 sickles/inch" << endl;
    cout << "\t BASILISK HORN - Only one wand is known to have this core, you could be the second - 30 sickles/inch" << endl;

}

void wandLengthOutput() {

    cout << "Now all that is left, what length would you like your wand? (between 8-15 inches)" << endl;
    cout << "!!! Whole numbers only. !!!" << endl;

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

void wandShopSimulation() {

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

    cout << "Welcome to Professor Worthington's Quality Wand Shop" << endl;
    cout << "Let us see if we can find the wand for you.\n"  << endl;

    woodMenuOutput();
    string usersWoodChoice;
    usersWoodChoice = validateUserInput(usersWoodChoice, wandWoodChoices, woodMenuOutput);

    coreMenuOutput();
    string usersCoreChoice;
    usersCoreChoice = validateUserInput(usersCoreChoice, wandCoreChoices, coreMenuOutput);

    wandLengthOutput();
    string wandLength;
    wandLength = validateUserInput(wandLength, wandLengthChoices, wandLengthOutput);

    int wandPrice = (wandWoodChoices.at(usersWoodChoice) + wandCoreChoices.at(usersCoreChoice)) * wandLengthChoices.at(wandLength);
    int wandPriceGalleons = wandPrice / GALLEON;
    int wandPriceSickles = wandPrice % GALLEON;

    cout << "Ahh yes, a " << wandLength << " inch " << usersWoodChoice << " wood wand with a " << usersCoreChoice << " core will be very powerful in the right hands." << endl;
    cout << "That's going to be " << wandPriceGalleons << " galleons & " << wandPriceSickles << " sickles (" << wandPrice << " sickles) youngin'." << endl;
    cout << "Thank you for your business! With great power comes great responsibility, so don't disappoint youngin'!" << endl;

}

int main() {

    wandShopSimulation();

    return 0;

}