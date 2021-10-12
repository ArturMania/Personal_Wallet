#include "AuxillaryMethodes.h"

string AuxillaryMethodes::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxillaryMethodes::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss>>numberInt;
    return numberInt;
}

string AuxillaryMethodes::loadLine() {
    cin.sync();
    string input = "";
    getline(cin, input);
    return input;
}

char AuxillaryMethodes::loadChar() {
    cin.sync();
    char character;
    cin>>character;
    return character;
}

int AuxillaryMethodes::loadNumber() {
    cin.sync();
    int number;
    cin>>number;
    return number;
}

string AuxillaryMethodes::changeFirstLetterToCapitalRestToSmall(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

