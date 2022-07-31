#include "../AirportManagementSystem/Dependencies/Time.cpp"
#include "Flight.cpp"
#include <iterator>
#include<list>
class Schedule{
    public:
    list<Flight> FlightList;
    
    void addFlight(Flight F,Time Arrival,Time Departure){
        F.setTime(Arrival,Departure);
        FlightList.push_back(F);
    }
    void removeFlight(Flight F){
        FlightList.remove(F);
    }

    Flight searchFlight(int code){
    list<Flight>::iterator it;
        for(it=FlightList.begin();it!=FlightList.end();it++){
            if(it->number==code)
                return *it;
        }
        cout<<"\nFlight Not Found!";
    }
};