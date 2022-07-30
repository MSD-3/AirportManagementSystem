#include<iostream>
using namespace std;

//class for Airport information
class Airport{
    string name,location;
    int code;
    public:
    Airport(string name,int code,string location){      //parameterised constructor to create airport
        this->name=name;
        this->code=code;
        this->location=location;
    }
    //double getFeesPrice(Flight f){
    //    return f.getAirportFees();
   // }
};