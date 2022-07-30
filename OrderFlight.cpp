#include "Order.cpp"
#include<list>
#include<iterator>
using namespace std;

class OrderFlight:public Order{
    static int passenger_no;
    public:
    OrderFlight(){
        
    }
    OrderFlight(Passenger passenger):Order(passenger){

    }
    void addPassenger(){
            passenger_no++;
    }

    void removePassenger(){
        passenger_no--;
    }

    double getPrice(){
        return price;
    }

    int getPassengerNo(){
        return passenger_no;
    }
};
int OrderFlight::passenger_no=0;