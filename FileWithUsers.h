#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "User.h"
#include "AuxillaryMethodes.h"
#include "Markup.h"

using namespace std;

class FileWithUsers {

    vector<User>users;
    const string FILE_WITH_USERS;
    string getNameOfFielWithUsers();

public:
    FileWithUsers(string nameOfFileWithUsers)
        :FILE_WITH_USERS(nameOfFileWithUsers) {
    };

    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void passwordChange(int loggedUSerId,string newPassword);

};
#endif

//FW
