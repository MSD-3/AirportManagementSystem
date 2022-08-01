//#include "OrderFlight.cpp"
#include <list>
#include<iterator>
using namespace std;
class ScheduleFlight{
    /*Time scheduledData;
    int capacity;
    list<Passenger> PassengerList;
    double currentPrice;
    public:
    //Constructor
    ScheduleFlight(double currentPrice,int capacity){
        scheduledData.setDate();
        this->currentPrice=currentPrice;
        this->capacity=capacity;
    }

    void addPassenger(Order p){
        if(getPassengerNo()<=capacity){
            p.setState(1);
            PassengerList.push_back(p.getPassenger());
            OrderFlight::addPassenger();

        }
        else{
            cout<<"\nCapacity Full!";
            p.CancelOrder();
        }
    }

    void removePassenger(Order p){
        PassengerList.remove(p.getPassenger());
        OrderFlight::removePassenger();
        p.CancelOrder();
    }

    double getCurrentPrice(){
        return currentPrice;
    }*/

    int capacity;
    list<Passenger> PassengerList;
    double currentPrice;
    public:
    ScheduleFlight(){
        cout<<"\nEnter Capacity of Flight : ";
        cin>>capacity;
    }
    void addPassenger(Order order){
        order.setState(1);
        PassengerList.push_back(order.getPassenger());
    }

    void removePassenger(Order order){
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