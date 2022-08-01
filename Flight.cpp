#include<iostream>
#include "Airport.cpp"
#include "ScheduleFlight.cpp"
#include "../AirportManagementSystem/Dependencies/Time.cpp"
using namespace std;

class Flight:public ScheduleFlight{
    Time departure,arrival;
    Airport *ArrivalAirport,*DepartureAirport;
    public:
    int number;    
    double nominalPrice;
    void addNew(){
        string airportName,location;
        int code;
        cout<<"\n Enter Flight number : ";
        cin>>number;
        //departure airport details
        cout<<"\nEnter Departure location : ";
        cin>>ws;
        getline(cin,location);
        cout<<"\nEnter Name of Departure Airport : ";
        cin>>ws;
        getline(cin,airportName);
        cout<<"\nEnter Departure Airport Code : ";
        cin>>code;
        cout<<"\nSet Departure Date and Time: \n";
        departure.setDate();
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
        cout<<"\nSet Arrival Date and Time: ";
        departure.setDate();
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

    /*void setTime(Time Arrival,Time Departure){
        departure=Departure;
        arrival=Arrival;
    } */

    Airport getArrivalAirport(){    //returns ArrivalAirport object
        return *ArrivalAirport;
    }

    Airport getDepartureAirport(){  //returns DepartureAirport object
        return *DepartureAirport;
    }
    bool operator==(const Flight& rhs) const {  //operator overloading for logical equals to compare two Flight Type object
        return number == rhs.number;
    }
};
