#include<iostream>
#include<string>
#include<regex>
#include<ctime>
#define priorityBoardingCharge 300.00
#define extraLuggageRate 50.00

using namespace std;

class Order{
    string ordernumber,state,Time,Date;
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
    Order(double price){             //parameterised constructor to create Order object          
        generateOrderNumber();
        generateTime();
        setState(0);
        this->price=price;
    }

    void display(){         //public display function to display order number
        cout<<"\nOrder Number : "<<ordernumber;
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

class Passenger:public Order{
    string passengerName,insurance;
    double weight_of_luggage;
    protected:
    bool extraLuggage,priorityBoarding;

    void extraLuggageCheck(){               //check for extra luggage and call modifyPrice
        if(weight_of_luggage>20.0){
            extraLuggage=true;
            modifyPrice(weight_of_luggage-20.0);
        }
    }

    void priorityCheck(){       //check priority and call modify price
        modifyPrice();
    }
    void modifyPrice(double extraweight=0.0){
        if(priorityBoarding && !priorityHike){          //when priority is selected
            price+=priorityBoardingCharge;
            priorityHike=true;
        }
        if(!priorityBoarding && priorityHike){
            cout<<"\nOnce Booked as priority boarding it cannot be changed!\nSorry for the inconvenience caused\n";
        }
        
        if(extraweight>0)
            price+=extraweight*extraLuggageRate;
        
    }
    public:
    Passenger(string name,string company,double luggageWeight,double price,bool priority):Order(price){     //parameterised constructor for passenger object and simultaneously calling constructor of Order
        passengerName=name;
        insurance=company;
        weight_of_luggage=luggageWeight;
        priorityBoarding=priority;
        priorityCheck();        //calling priorityCheck to modify fare if required
        extraLuggageCheck();    //calling extraLuggage check to modify fare if required
    }

    void edit(){            //public function to select the 
        int ch=0;
        cout<<"\nWhat do you want to edit? ";
        cout<<"\n1.Passenger Name\n2.Insurance\n3.Weight of luggage\n4.Priority Boarding\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        update(ch);
    }

    void update(int ch){
        switch(ch){
            case 1: cout<<"\nEnter name : ";
                    cin>>ws;
                    getline(cin,passengerName);
                    break;
            
            case 2: cout<<"\nEnter name and number of insurance company : ";
                    cin>>ws;
                    getline(cin,insurance);
                    break;

            case 3: cout<<"\nEnter weight of luggage : ";
                    cin>>weight_of_luggage;
                    void extraLuggageCheck();
                    break;

            case 4: cout<<"\nPress 1 for priority boarding.\nPress 2 for normal boarding.\n : ";
                    int temp;
                    cin>>temp;
                    if(temp==1)
                        priorityBoarding=true;
                    else if(temp==2)
                        priorityBoarding=false;
                    priorityCheck();
                    break;

            default:cout<<"\n\nWrong Choice Entered!\n";
                    break;
        }
    }
    void display(){
        Order::display();
        cout<<"\nPassenger Name : "<<passengerName;
        cout<<"\nDestination : "<<getState();
        cout<<"\nInsurance Information : "<<insurance;
        cout<<"\nLuggage Weight : "<<weight_of_luggage;
        cout<<"\nPriority Boarding : "<<(priorityHike?"Yes":"No");
        cout<<"\nFare : "<<getPrice()<<endl;
    }
};