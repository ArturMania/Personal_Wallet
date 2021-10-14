#include "UserManager.h"

void UserManager::userRegistration() {
    User user = newUserDataInput();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Your account has been created." << endl << endl;
    system("pause");
}

User UserManager::newUserDataInput() {

    User user;
    string login,password,name,surname;
    system("cls");

    user.setId(getNewUserId());
    cout << "Your login: ";
    cin>>login;
    user.setLogin(login);
    cout << "Password: ";
    cin>>password;
    user.setPassword(password);
    cout<<"Your Name: ";
    cin>>name;
    user.setName(name);
    cout<<"Your Surname: ";
    cin>>surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserId() {

    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}


int UserManager::userLogIn() {
    string login="", password="";
    system("cls");
    cout <<"Login: ";
    login = AuxillaryMethodes::loadLine();
    for(int i=0; i<users.size(); i++) {
        if (users[i].getLogin() == login) {

            cout << "Password: ";
            password = AuxillaryMethodes::loadLine();

            if (users[i].getPassword() == password) {
                cout << endl << "You have logged in" << endl << endl;
                system("pause");
                loggedUserId=users[i].getId();
                return loggedUserId;
            } else {
                cout<<"Wrong password!"<<endl;
                system ("pause");
                return 0;
            }
        } else {
            cout << "There is no such login/account!" << endl << endl;
            system("pause");
            return 0;
        }
    }
}

void UserManager::loggedUserPasswordChange() {
    string newPassword;
    int loggedUserId;
    loggedUserId=getIdOfLoggedInUser();
    cout << "New password: ";
    newPassword = AuxillaryMethodes::loadLine();
    fileWithUsers.passwordChange(loggedUserId,newPassword);
}

int UserManager::getIdOfLoggedInUser() {
    cout<<"User ID: "<<loggedUserId<<endl<<endl;
    return loggedUserId;
}

int UserManager::userLogout() {
    return loggedUserId=0;
}

bool UserManager::isUserLoggedIn() {
    loggedUserId=getIdOfLoggedInUser();
    if(loggedUserId>0)
        return true;
    else
        return false;
}
