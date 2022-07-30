#include<iostream>
#include<string>
#include<regex>
#include<ctime>
#include "Passenger.cpp"
#define priorityBoardingCharge 300.00
#define extraLuggageRate 50.00

using namespace std;

class Order{
    string ordernumber,state,OrderTime,Date;
    Passenger passengerInfo;
    static int orderNo;
    protected:
    double price;
    bool priorityHike=false;
    
    void generateTime(){        //function generating date and time
        time_t OrderTime=time(0);
        tm *tmp=localtime(&OrderTime);
        this->OrderTime=to_string(tmp->tm_hour)+":"+to_string(tmp->tm_min)+":"+to_string(tmp->tm_sec)+" "+tmp->tm_zone;
        Date=to_string(tmp->tm_mday)+"/"+to_string(tmp->tm_mon)+"/"+to_string(tmp->tm_year+1900);
    }

    void generateOrderNumber(){      //function generating order id
        time_t OrderTime=time(0);
        tm *tmp=localtime(&OrderTime);
        ordernumber=tmp->tm_zone+to_string(tmp->tm_mday)+to_string(tmp->tm_mon)+to_string(tmp->tm_year+1900)+to_string(tmp->tm_hour)+to_string(tmp->tm_min)+to_string(tmp->tm_sec)+to_string(orderNo);
        orderNo++;     
    }

    public:
    Order(){
        
    }
    Order(Passenger p){             //parameterised constructor to create Order object          
        generateOrderNumber();
        generateTime();
        setState(0);
        passengerInfo=p;
    }

    void display(){         //public display function to display order number
        cout<<"\nOrder Number : "<<ordernumber;
        passengerInfo.display();
    }

    void setState(int State){        //public function to set the state -1 for cancelled,0 for pending 1 for confirmed
        if(State==-1)
            state="Cancelled";
        else if(State==0)
            state="Pending";
        else if(State==1)
            state="Confirmed";
        else
            cout<<"Wrong State!";
    }

    string getState(){                  //public function to return state
        return state;
    }

    double getPrice(){                  //public funtion to return the price of the ticket
        return price;
    }

    void CancelOrder(){     //function for order cancellation
        setState(-1);       //setting state to cancelled
        display();
        passengerInfo.Delete();
    }

    Passenger getPassenger(){       //function to get Passenger Info
        return passengerInfo;
    }
};
int Order::orderNo=0;   //number of order counter
