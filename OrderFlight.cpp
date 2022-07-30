#include "Order.cpp"
#include<list>
#include<iterator>
#define MaxPassenger 300
using namespace std;

class OrderFlight:public Order{
    static int passenger_no;
    public:
    OrderFlight(Passenger passenger):Order(passenger){

    }
    void addPassenger(){
        if(passenger_no<=MaxPassenger){
            passenger_no++;
        }
        else
            cout<<"\nSeats Full\n";
    }

    void removePassenger(){
        passenger_no--;
    }
};
int OrderFlight::passenger_no=0;