#include<iostream>
using namespace std;

class Admin{            //admin class for login
/*
    ID stores the id for login
    password stores the password for login
*/
    private:
    string ID;
    string password;
    public:
    Admin(){        //default id password initialised
        ID="admin";         
        password="admin";
    }
    void setID(string id){          //id setter
        ID=id;
    }
    string getID(){                 //id getter
        return ID;
    }

    void setPassword(string pass){      //password setter
        password=pass;
    }

    string getPassword(){               //password getter
        return password;
    }
};