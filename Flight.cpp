#include<iostream>
#include "../AirportManagementSystem/Dependencies/Time.cpp"
using namespace std;

class Flight{
    public:
    int number;
    Time departure,arrival;
    double nominalPrice;
    

    double getAirportFees(){
        return nominalPrice;        //placeholder
    }
};

int main(){
    Flight f1;
    f1.departure.setDate();
}