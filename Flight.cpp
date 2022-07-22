#include<iostream>
#include"Time.cpp"
using namespace std;

class Flight{
    int number;
    Time departure,arrival;
    double nominalPrice;
    public:

    double getAirportFees(){
        return nominalPrice;        //placeholder
    }
};