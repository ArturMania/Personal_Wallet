#include "FileWithUsers.h"

string FileWithUsers::getNameOfFielWithUsers() {
    return FILE_WITH_USERS;
}

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem("Users");
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",user.getId());
    xml.AddElem("Login",user.getLogin());
    xml.AddElem("Password",user.getPassword());
    xml.AddElem("Name",user.getName());
    xml.AddElem("Password",user.getPassword());

    xml.Save("users.xml");
    cout<<"Users has been added succesfuly to a File."<<endl;
    system("cls");
}

vector<User>FileWithUsers::loadUsersFromFile() {
    CMarkup xml;
    User user;
    vector<User>users;
    bool fileExists = xml.Load("Users.xml");
    if(fileExists) {
        xml.FindElem("Users");
        xml.IntoElem();
        while(xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(atoi(xml.GetData().c_str()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());
            users.push_back(user);

        }
    }
    return users;
}
