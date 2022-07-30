#include<iostream>
#include "../AirportManagementSystem/Dependencies/Time.cpp"
#include "Airport.cpp"
using namespace std;

class Flight{
    Time departure,arrival;
    Airport ArrivalAirport,DepartureAirport;
    public:
    int number;    
    double nominalPrice;
    

    double getAirportFees(){
        return nominalPrice;        //placeholder
    }

    void setTime(Time Arrival,Time Departure){
        departure=Departure;
        arrival=arrival;
    }

    Airport getArrivalAirport(){
        return ArrivalAirport;
    }

    Airport getDepartureAirport(){
        return DepartureAirport;
    }

};