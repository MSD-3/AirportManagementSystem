
#include <iterator>
#include<list>
class Schedule{
    public:
    /* FlightList stores the list of objects of type flight for future reference  */
    list<Flight> FlightList;
    list<Flight>::iterator it;
    void addFlight(){           //adds new flight to the list
        Flight F;
        bool flag;
        do{
            flag=false;
            F.setNumber();
            for(it=FlightList.begin();it!=FlightList.end();it++)
                if(it->number==F.getFlightNumber()){                //check if flight number is already present in List of Flight
                    flag=true;
                    cout<<"\nFlight Already Exists in the Schedule!\n";
                }   
        }while(flag);           //
        F.addNew();
        FlightList.push_back(F);
    }

    void removeFlight(){                //removes Flight from FlightList
        int flightno;
        if(FlightList.empty()){
            cout<<"\nNo flight Scheduled\n\n";
            return;
        }
        display();
        cout<<"\nEnter Flight Number";
        cin>>flightno;
        Flight *F=searchFlight(flightno);
        if(F==nullptr){
            cout<<"\n\nFlight Not Found!\n\n";
            return;
        }
        FlightList.remove(*searchFlight(flightno));
    }

    Flight *searchFlight(int code){         //searches through FlightLest using Flight Code and returns Flight as a pointer variable . Returns nullptr if Flight is not present in list
        for(it=FlightList.begin();it!=FlightList.end();it++){
            if(it->number==code)
                return &(*it);
        }
        cout<<"\nFlight Not Found!";
        return nullptr;
    }

    void display(){             //displays Flight Info
        cout<<"\nFlight List\n";
        Airport airport;
        Time    t1me;
        cout<<"Flight Number\t\tDeparture Airport\t\t\tDeparture Time\t\t\tArrival Airport\t\t\t\tArrival Time\n";
            for(it=FlightList.begin();it!=FlightList.end();it++){       //traversing thorugh FlightList
                //Departure Airport
                cout<<it->getFlightNumber()<<"\t\t";                    
                airport=it->getDepartureAirport();                      
                airport.displayMenu();
                cout<<"\t\t";
                t1me=it->getDepartureTime();
                t1me.displaymenu(); 

                //Arrival Airport
                cout<<"\t\t";  
                airport=it->getArrivalAirport();
                airport.displayMenu();
                cout<<"\t\t";
                t1me=it->getArrivalTime();
                t1me.displaymenu();             
            }
        cout<<"\n\n";
    }
};