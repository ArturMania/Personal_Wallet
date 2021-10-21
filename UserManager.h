#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {

    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User newUserDataInput();
    int getNewUserId();

public:
    UserManager(string nameOfFileWithUsers):fileWithUsers(nameOfFileWithUsers) {
        users = fileWithUsers.loadUsersFromFile();
        loggedUserId=0;
    };

    int userLogIn();
    int userLogout();
    int getIdOfLoggedInUser();
    void userRegistration();
    void loggedUserPasswordChange();
    bool isUserLoggedIn();

};
#endif

//FW
