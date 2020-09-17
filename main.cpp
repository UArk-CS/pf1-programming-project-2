#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// Galleon in terms of sickles
const int GALLEON = 17;

void woodMenuOutput() {

    cout << "Select one of our fine woods for your wand:" << endl;
    cout << "\tBLACK WALNUT\n\t\tA sleek dark finish meant for only those with good instinct\n\t\t10 sickles/inch" << endl;
    cout << "\tEBONY\n\t\tA jet-black wand with a high reputation perfect for those into combative magic\n\t\t17 sickles/inch" << endl;
    cout << "\tREDWOOD\n\t\tA very rare wood that is known to bring good luck to its owner\n\t\t25 sickles/inch" << endl;

}

void coreMenuOutput() {

    cout << "Select one of our powerful wand cores:" << endl;
    cout << "\tDRAGON HEARTSTRING\n\t\tWhile it can be temperamental, this core is the most powerful and can learn the quickest\n\t\t15 sickles/inch" << endl;
    cout << "\tPHOENIX FEATHER\n\t\tThe rarest core there is. It can be tricky to bond with, but it is also the most capable across all magic types\n\t\t20 sickles/inch" << endl;
    cout << "\tBASILISK HORN\n\t\tOnly one wand is known to have this core, you could be the second\n\t\t30 sickles/inch" << endl;

}

void wandLengthMenuOutput() {

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

bool validateUserInput(const string& userInput, map<string, int> validInput) {

   map<string, int>::iterator it;

   for(it = validInput.begin(); it != validInput.end(); ++it) {
       string validChoice = it->first;

       if(validChoice == userInput) {
           return true;
       }
   }

   return false;

}

void wandShopSimulation() {

    bool loopAgain = true;

    // Map for the wand word choices (in Sickles)
    map<string, int> wandWoodChoices;
    wandWoodChoices.insert(pair<string, int>("BLACK WALNUT",10));
    wandWoodChoices.insert(pair<string, int>("EBONY", 17));
    wandWoodChoices.insert(pair<string, int>("REDWOOD", 25));

    // Map for the wand core choices (in Sickles)
    map<string, int> wandCoreChoices;
    wandCoreChoices.insert(pair<string, int>("DRAGON HEARTSTRING",15));
    wandCoreChoices.insert(pair<string, int>("PHOENIX FEATHER", 20));
    wandCoreChoices.insert(pair<string, int>("BASILISK HORN", 30));

    // Map for the wand length choices
    map<string, int> wandLengthChoices;
    wandLengthChoices.insert(pair<string, int>("8", 8));
    wandLengthChoices.insert(pair<string, int>("9", 9));
    wandLengthChoices.insert(pair<string, int>("10", 10));
    wandLengthChoices.insert(pair<string, int>("11", 11));
    wandLengthChoices.insert(pair<string, int>("12", 12));
    wandLengthChoices.insert(pair<string, int>("13", 13));
    wandLengthChoices.insert(pair<string, int>("14", 14));
    wandLengthChoices.insert(pair<string, int>("15", 15));

    cout << "Welcome to Professor Worthington's Quality Wand Shop" << endl;
    cout << "Let us see if we can find the wand for you.\n"  << endl;

    woodMenuOutput();
    string usersWoodChoice = getUserInput();
    bool isValid = validateUserInput(usersWoodChoice, wandWoodChoices);
    while(loopAgain) {
        if(isValid) {
            loopAgain = false;
        } else {
            cout << "!!! Invalid input. Please try again with a valid answer. !!!\n" << endl;
            woodMenuOutput();
            usersWoodChoice = getUserInput();
            isValid = validateUserInput(usersWoodChoice, wandWoodChoices);
        }
    }

    loopAgain = true;
    coreMenuOutput();
    string usersCoreChoice = getUserInput();
    isValid = validateUserInput(usersCoreChoice, wandCoreChoices);
    while(loopAgain) {
        if(isValid) {
            loopAgain = false;
        } else {
            cout << "!!! Invalid input. Please try again with a valid answer. !!!\n" << endl;
            coreMenuOutput();
            usersCoreChoice = getUserInput();
            isValid = validateUserInput(usersCoreChoice, wandCoreChoices);
        }
    }

    loopAgain = true;
    wandLengthMenuOutput();
    string wandLength = getUserInput();
    isValid = validateUserInput(wandLength, wandLengthChoices);
    while(loopAgain) {
        if(isValid) {
            loopAgain = false;
        } else {
            cout << "!!! Invalid input. Please try again with a valid answer. !!!\n" << endl;
            wandLengthMenuOutput();
            wandLength = getUserInput();
            isValid = validateUserInput(wandLength, wandLengthChoices);
        }
    }

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
