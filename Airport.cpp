#include<iostream>
using namespace std;

//class for Airport information
class Airport{
    string name,location;
    int code;
    public:
    Airport(){

    }
    Airport(const Airport &obj){
        name=obj.name;
        location=obj.location;
        code=obj.code;
    }
    Airport(string name,int code,string location){      //parameterised constructor to create airport
        this->name=name;
        this->code=code;
        this->location=location;
    }
    void display(){
        cout<<"\nAirport Location : "<<location;
        cout<<"\nAirport Name : "<<name;
        cout<<"\nAirport Code : "<<code;
    }

    void displayMenu(){     //for display function of Schedule class
        cout<<location<<" : "<<name;
    }
};