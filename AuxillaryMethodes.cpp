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

string AuxillaryMethodes::convertFloatToString(float number){
    stringstream floatToString ;
    floatToString  << number;
    string numberStr = floatToString .str();
    return numberStr;
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

string AuxillaryMethodes::replaceCommaWithDot ( string numberAsString ) {

    for ( int i = 0; i < numberAsString.size(); i++ ) {
        if( numberAsString[i] == 44 )
            numberAsString[i] = 46;
    }
    return numberAsString;
}

//FW
