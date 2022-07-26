#include<iostream>
#include<string>
#include<regex>
#include<ctime>
#include "Passenger.cpp"
#define priorityBoardingCharge 300.00
#define extraLuggageRate 50.00

using namespace std;

class Order{
    string ordernumber,state,Time,Date;
    Passenger passengerInfo;
    static int orderNo;
    protected:
    double price;
    bool priorityHike=false;
    
    void generateTime(){        //function generating date and time
        time_t Time=time(0);
        tm *tmp=localtime(&Time);
        this->Time=to_string(tmp->tm_hour)+":"+to_string(tmp->tm_min)+":"+to_string(tmp->tm_sec)+" "+tmp->tm_zone;
        Date=to_string(tmp->tm_mday)+"/"+to_string(tmp->tm_mon)+"/"+to_string(tmp->tm_year+1900);
    }

    void generateOrderNumber(){      //function generating order id
        time_t Time=time(0);
        tm *tmp=localtime(&Time);
        ordernumber=tmp->tm_zone+to_string(tmp->tm_mday)+to_string(tmp->tm_mon)+to_string(tmp->tm_year+1900)+to_string(tmp->tm_hour)+to_string(tmp->tm_min)+to_string(tmp->tm_sec)+to_string(orderNo);
        orderNo++;     
    }

    public:
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

    double getPrice(){                  //piblic funtion to return the price of the ticket
        return price;
    }

};
int Order::orderNo=0;   //number of order counter
