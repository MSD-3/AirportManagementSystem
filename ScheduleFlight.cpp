#include "OrderFlight.cpp"
#include "../AirportManagementSystem/Dependencies/Time.cpp"
#include <list>
#include<iterator>
using namespace std;
class ScheduleFlight:public OrderFlight{
    Time scheduledData;
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
    }
};