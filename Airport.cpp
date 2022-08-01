#include<iostream>
using namespace std;

//class for Airport information
class Airport{
    /*
        name stores the name of the airport
        location stores the palce the airport is located
    */
    string name,location;
    int code;
    public:
    Airport(){          //default constructor

    }
    Airport(const Airport &obj){                //copy constructor
        name=obj.name;
        location=obj.location;
        code=obj.code;
    }
    Airport(string name,int code,string location){      //parameterised constructor to create airport
        this->name=name;
        this->code=code;
        this->location=location;
    }
    void display(){             //display function for Airport
        cout<<"\nAirport Location : "<<location;
        cout<<"\nAirport Name : "<<name;
        cout<<"\nAirport Code : "<<code;
    }

    void displayMenu(){     //for display function of Schedule class
        cout<<location<<" : "<<name;
    }
};