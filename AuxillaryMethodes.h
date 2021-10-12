#ifndef AUXILLARYMETHODES_H
#define AUXILLARYMETHODES_H
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;


class AuxillaryMethodes {

public:

   static string convertIntToString(int number);
   static int convertStringToInt(string number);
   static string loadLine();
   static char loadChar();
   static int loadNumber();
   static string changeFirstLetterToCapitalRestToSmall(string text);
   static void changeFileName(string oldNAme,string newName);
   static void deleteFile(string fileName);

};
#endif
