//#include "OrderFlight.cpp"
#include <list>
#include<iterator>
using namespace std;
class ScheduleFlight{
    int capacity;
    list<Passenger> PassengerList;
    double currentPrice;
    public:
    ScheduleFlight(){
        cout<<"\nEnter Capacity of Flight : ";
        cin>>capacity;
    }
    void addPassenger(OrderFlight *order){
        if(PassengerList.size()<=capacity){
            order->setState(1);
            PassengerList.push_back(order->getPassenger());
        }
        else{
            cout<<"\n\nFlight is Full!\n\n";
            order->setState(-1);
        }
    }

    void removePassenger(OrderFlight order){
        bool exists=false;
    list<Passenger>::iterator it;
    for(it=PassengerList.begin();it!=PassengerList.end();it++)  //check if the passenger is in the flight or not
        if(*it==order.getPassenger()){
            exists=true;
            break;
        }
        if(exists){
            order.setState(-1);
            PassengerList.remove(order.getPassenger());
        }
        else
            cout<<"\nPassenger not present in flight";
    }

    int getCapacity(){
        return capacity;
    }
};