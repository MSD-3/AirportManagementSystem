#include<iostream>
#include "../AirportManagementSystem/Dependencies/Time.cpp"
#include "Airport.cpp"
using namespace std;

class Flight{
    Time departure,arrival;
    Airport *ArrivalAirport,*DepartureAirport;
    public:
    int number;    
    double nominalPrice;

    void addNew(){
        string airportName,location;
        int code;
        //departure airport details
        cout<<"\nEnter Departure location : ";
        cin>>ws;
        getline(cin,location);
        cout<<"\nEnter Name of Departure Airport : ";
        cin>>ws;
        getline(cin,airportName);
        cout<<"\nEnter Departure Airport Code : ";
        cin>>code;
        DepartureAirport=new Airport(airportName,code,location);  //creating departure airport object
        //arrival airport details
        cout<<"\nEnter Arrival location : ";
        cin>>ws;
        getline(cin,location);
        cout<<"\nEnter Name of Arrival Airport : ";
        cin>>ws;
        getline(cin,airportName);
        cout<<"\nEnter Arrival Airport Code : ";
        cin>>code;
        ArrivalAirport=new Airport(airportName,code,location);  //creating arrival airport object
        do{
            cout<<"Enter Flight Fees : ";
            cin>>nominalPrice;
            if(nominalPrice<0)
                cout<<"\nFare cannot be negative.";
        }while(nominalPrice>0);
    }
    double getAirportFees(){
        return nominalPrice;        //placeholder
    }

    void setTime(Time Arrival,Time Departure){
        departure=Departure;
        arrival=arrival;
    }

    Airport getArrivalAirport(){    //returns ArrivalAirport object
        return *ArrivalAirport;
    }

    Airport getDepartureAirport(){  //returns DepartureAirport object
        return *DepartureAirport;
    }

};
