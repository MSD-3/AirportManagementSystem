#include "Order.cpp"
#include<list>
#include<iterator>
using namespace std;

class OrderFlight:public Order{     //redundant
    static int passenger_no;        //stores the number of passengers in the order
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