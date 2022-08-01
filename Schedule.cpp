#include "Flight.cpp"
#include <iterator>
#include<list>
class Schedule{
    public:
    list<Flight> FlightList;
    list<Flight>::iterator it;
    void addFlight(){
        Flight F;
        bool flag;
        do{
            flag=false;
            F.setNumber();
            for(it=FlightList.begin();it!=FlightList.end();it++)
                if(it->number==F.getFlightNumber()){
                    flag=true;
                    cout<<"\nFlight Already Exists in the Schedule!\n";
                }   
        }while(flag);
        F.addNew();
        FlightList.push_back(F);
    }

    void removeFlight(){
        int flightno;
        if(FlightList.empty()){
            cout<<"\nNo flight Scheduled\n\n";
            return;
        }
        display();
        cout<<"\nEnter Flight Number";
        cin>>flightno;
        FlightList.remove(*searchFlight(flightno));
    }

    Flight *searchFlight(int code){
        for(it=FlightList.begin();it!=FlightList.end();it++){
            if(it->number==code)
                return &(*it);
        }
        cout<<"\nFlight Not Found!";
        return nullptr;
    }

    void display(){
        cout<<"\nFlight List\n";
        Airport airport;
        Time    t1me;
        cout<<"Flight Number\t\tDeparture Airport\t\tDeparture Time\t\tArrival Airport\t\tArrival Time";
            for(it=FlightList.begin();it!=FlightList.end();it++){
                airport=it->getArrivalAirport();
                cout<<it->getFlightNumber()<<"\t\t";
                airport.displayMenu();
                cout<<"\t\t";
                t1me=it->getArrivalTime();
                t1me.displaymenu();
                airport=it->getDepartureAirport();
                cout<<"\t\t";
                airport.displayMenu();
                cout<<"\t\t";
                t1me=it->getDepartureTime();
                t1me.displaymenu();                
            }
        cout<<"\n\n";
    }
};