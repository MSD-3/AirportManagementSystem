#include <iostream>
using namespace std;
#define extraLuggageRate 50.00
#define priorityBoardingCharge 200
class Passenger{
    string passengerName,insurance;
    double weight_of_luggage,extraFare;
    protected:
    bool extraLuggage,priorityBoarding,priorityHike=false;
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
            extraFare+=priorityBoardingCharge;
            priorityHike=true;
        }
        if(!priorityBoarding && priorityHike){
            cout<<"\nOnce Booked as priority boarding it cannot be changed!\nSorry for the inconvenience caused\n";
        }
        
        if(extraweight>0)
            extraFare+=extraweight*extraLuggageRate;
        
    }

    public:
    Passenger(){
        
    }
    Passenger(string name,string company,double luggageWeight,bool priority){     //parameterised constructor for passenger object and simultaneously calling constructor of Order
        passengerName=name;
        insurance=company;
        weight_of_luggage=luggageWeight;
        priorityBoarding=priority;
        //priorityCheck();        //calling priorityCheck to modify fare if required
        extraLuggageCheck();    //calling extraLuggage check to modify fare if required
    }

    void edit(){            //public function to select the 
        int ch=0;
        cout<<"\nWhat do you want to edit? ";
        cout<<"\n1.Passenger Name\n2NodeInsurance\n3.Weight of luggage\n4.Priority Boarding\n";
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
                    //priorityCheck();
                    break;

            default:cout<<"\n\nWrong Choice Entered!\n";
                    break;
        }
    }
    void display(){
        cout<<"\nPassenger Name : "<<passengerName;
        cout<<"\nInsurance Information : "<<insurance;
        cout<<"\nLuggage Weight : "<<weight_of_luggage;
        cout<<"\nPriority Boarding : "<<(priorityBoarding?"Yes":"No");
    }

    void Delete(){              //deleting Passenger Object
        delete this;
    }

    bool operator==(const Passenger& rhs) const {   //operator overloading for logical equals to compare two Passenger Type object
        return passengerName == rhs.passengerName and weight_of_luggage == rhs.weight_of_luggage;
    }

    double getExtraFare(){
        return extraFare;
    }
};