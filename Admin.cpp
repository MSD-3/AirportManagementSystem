#include<iostream>
using namespace std;

class Admin{
    private:
    string ID;
    string password;
    public:
    Admin(){
        ID="admin";
        password="admin";
    }
    void setID(string id){
        ID=id;
    }
    string getID(){
        return ID;
    }

    void setPassword(string pass){
        password=pass;
    }

    string getPassword(){
        return password;
    }
};