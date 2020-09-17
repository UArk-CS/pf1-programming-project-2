#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

//Define constants
const int GALLEON = 17;
const string GRYFFINDOR = "Gryffindor";
const string HUFFLEPUFF = "Hufflepuff";
const string SLYTHERIN = "Slytherin";
const string RAVENCLAW = "Ravenclaw";

void woodMenuOutput() {

    // Stores output for the wand wood menu
    // In a function so it can be called again when validating user input rather than rewriting all the cout statements

    cout << "Select one of our fine woods for your wand:" << endl;
    cout << "\tBLACK WALNUT\n\t\tA sleek dark finish meant for only those with good instinct\n\t\t10 sickles/inch" << endl;
    cout << "\tEBONY\n\t\tA jet-black wand with a high reputation perfect for those into combative magic\n\t\t17 sickles/inch" << endl;
    cout << "\tREDWOOD\n\t\tA very rare wood that is known to bring good luck to its owner\n\t\t25 sickles/inch" << endl;

}

void coreMenuOutput() {

    // Stores the output for the wand core menu
    // In a function so it can be called again when validating user input rather than rewriting all the cout statements

    cout << "Select one of our powerful wand cores:" << endl;
    cout << "\tDRAGON HEARTSTRING\n\t\tWhile it can be temperamental, this core is the most powerful and can learn the quickest\n\t\t15 sickles/inch" << endl;
    cout << "\tPHOENIX FEATHER\n\t\tThe rarest core there is. It can be tricky to bond with, but it is also the most capable across all magic types\n\t\t20 sickles/inch" << endl;
    cout << "\tBASILISK HORN\n\t\tOnly one wand is known to have this core, you could be the second\n\t\t30 sickles/inch" << endl;

}

void wandLengthMenuOutput() {

    // Stores the output for the wand length menu
    // In a function so it can be called again when validating user input rather than rewriting all the cout statements

    cout << "Now all that is left, what length would you like your wand? (between 8-15 inches)" << endl;
    cout << "!!! Whole numbers only. !!!" << endl;

}

string getUserInput() {

    // Gets the user input and transforms the string to all uppercase to later compare when validating the input

    cout << "\n** Please type your selection as seen above **" << endl;

    string userInput;
    cout << "> ";
    getline(cin, userInput);
    cout << endl;

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

    return userInput;

}

bool validateUserInput(const string& userInput, map<string, int> validInput) {

    // Validates the user input by comparing their input to the choices predefined in the map

    // Creates an iterator for the map
    map<string, int>::iterator it;

    // Loops through the map using the iterator to see if the users input matches any valid input
    for(it = validInput.begin(); it != validInput.end(); ++it) {
        string validChoice = it->first;  // Looks at the key in the map, not the value

        if(validChoice == userInput) {
            return true;
        }
    }

    return false;

}

void wandShopSimulation() {

    // !! STORES THE CODE FOR ENTIRE WAND SHOP SIMULATION !!

    // while loop controller
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

    // Outputs the menu, gets users input, validates the input, then inside the while loop if validateUserInput()
    // returned true, the loop breaks and moves on. Otherwise, the program prompts the user that they entered
    // invalid input and reprints the menu, gets new data, and re-validates it. Continues until valid input.
    // Repeated for wood, core, and length of wand.
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

    // Calculates the wand price, then converts it to Galleons and Sickles
    int wandPrice = (wandWoodChoices.at(usersWoodChoice) + wandCoreChoices.at(usersCoreChoice)) * wandLengthChoices.at(wandLength);
    int wandPriceGalleons = wandPrice / GALLEON;
    int wandPriceSickles = wandPrice % GALLEON;

    // Outputs the users choices and the price of their wand
    cout << "Ahh yes, a " << wandLength << " inch " << usersWoodChoice << " wood wand with a " << usersCoreChoice << " core will be very powerful in the right hands." << endl;
    cout << "That's going to be " << wandPriceGalleons << " galleons & " << wandPriceSickles << " sickles (" << wandPrice << " sickles) youngin'." << endl;
    cout << "Thank you for your business! With great power comes great responsibility, so don't disappoint! Now off you go to Hogwarts!" << endl;

}

void questionOneMenuOutput() {

    // Stores the output for the first question
    // In a function so it can be called again when validating user input rather than rewriting all the cout statements

    cout << "1. If you could make a potion that could guarantee you one thing, what would it be?" << endl;
    cout << "\tA. Love" << endl;
    cout << "\tB. Wisdom" << endl;

}

void questionTwoMenuOutput() {

    // Stores the output for the second question
    // In a function so it can be called again when validating user input rather than rewriting all the cout statements

    cout << "2. When I am dead, I want people to remember me as:" << endl;
    cout << "\tA. The Great" << endl;
    cout << "\tB. The Wise" << endl;

}

void questionThreeMenuOutput() {

    // Stores the output for the third question
    // In a function so it can be called again when validating user input rather than rewriting all the cout statements

    cout << "3. What would you least liked to be called?" << endl;
    cout << "\tA. Cowardly" << endl;
    cout << "\tB. Selfish" << endl;

}

void hogwartsSortingHatSimulation() {

    bool loopAgain = true;  // while loop controller
    string usersHouseAssignment;

    cout << "Welcome to Hogwarts young wizards and witches!" << endl;
    cout << "We will now begin the House Sorting ceremony to place you into your rightful house." << endl;
    cout << "Please answer the following questions with either A or B. Good luck!\n" << endl;

    // Outputs the question and answer choices, gets the users input, and then checks to see if the answer is valid
    // Repeated for question two and three
    questionOneMenuOutput();
    string questionOneAnswer = getUserInput();
    while(loopAgain) {
        if((questionOneAnswer == "A") || (questionOneAnswer == "B")) {
            loopAgain = false;
        } else {
            cout << "!!! Invalid input. Please try again with a valid answer. !!!\n" << endl;
            questionOneMenuOutput();
            questionOneAnswer = getUserInput();
        }
    }

    loopAgain = true;
    questionTwoMenuOutput();
    string questionTwoAnswer = getUserInput();
    while(loopAgain) {
        if((questionTwoAnswer == "A") || (questionTwoAnswer == "B")) {
            loopAgain = false;
        } else {
            cout << "!!! Invalid input. Please try again with a valid answer. !!!\n" << endl;
            questionTwoMenuOutput();
            questionTwoAnswer = getUserInput();
        }
    }

    loopAgain = true;
    questionThreeMenuOutput();
    string questionThreeAnswer = getUserInput();
    while(loopAgain) {
        if((questionThreeAnswer == "A") || (questionThreeAnswer == "B")) {
            loopAgain = false;
        } else {
            cout << "!!! Invalid input. Please try again with a valid answer. !!!\n" << endl;
            questionThreeMenuOutput();
            questionThreeAnswer = getUserInput();
        }
    }

    // Determines the users House based on the constraints listed in the PDF then assigns it to userHouseAssignment
    if(questionOneAnswer == "A") {
       if(questionThreeAnswer == "A") {
           usersHouseAssignment = GRYFFINDOR;
       } else if(questionThreeAnswer == "B") {
           usersHouseAssignment = HUFFLEPUFF;
       }
    } else if(questionOneAnswer == "B") {
        if(questionTwoAnswer == "A") {
            usersHouseAssignment = SLYTHERIN;
        } else if(questionTwoAnswer == "B") {
            usersHouseAssignment = RAVENCLAW;
        }
    }

    cout << "The sorting hat chose... " << usersHouseAssignment << "! You'll certainly fit in there!" << endl;
    cout << "Enjoy your stay at Hogwarts!" << endl;

}

int main() {

    // Calls the wand shop function and the sorting hat function
    wandShopSimulation();
    cout << endl;
    hogwartsSortingHatSimulation();

    return 0;

}
