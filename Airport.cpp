//preprocessor directives
#include<iostream>
#include<list>
#include "Order.cpp"
#define maxTickets 5
using namespace std;

//Class Customer

/*class Order{
    string ordernumber,state,Time,Date;
    static int orderNo;
    protected:
    double price;
    bool priorityHike=false;
    //function generating date and time
    void generateTime(){
        time_t Time=time(0);
        tm *tmp=localtime(&Time);
        this->Time=to_string(tmp->tm_hour)+":"+to_string(tmp->tm_min)+":"+to_string(tmp->tm_sec)+" "+tmp->tm_zone;
        Date=to_string(tmp->tm_mday)+"/"+to_string(tmp->tm_mon)+"/"+to_string(tmp->tm_year+1900);
    }
    //function generating order id
    void generateOrderNumber(){
        time_t Time=time(0);
        tm *tmp=localtime(&Time);
        ordernumber=tmp->tm_zone+to_string(tmp->tm_mday)+to_string(tmp->tm_mon)+to_string(tmp->tm_year+1900)+to_string(tmp->tm_hour)+to_string(tmp->tm_min)+to_string(tmp->tm_sec)+to_string(orderNo);
        orderNo++;
        cout<<endl<<ordernumber<<endl;
    }

    public:
    Order(double price,string destination){                
        generateOrderNumber();
        generateTime();
        state=destination;
        this->price=price;
    }

    

    void setState(string state){        //function to set the state 
        this->state=state;
    }

    double getPrice(){
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
            price-=priorityBoardingCharge;
            priorityHike=false;
        }
        
        if(extraweight>0)
            price+=extraweight*extraLuggageRate;
        
    }
    public:
    Passenger(string name,string company,double luggageWeight,string destination,double price,bool priority):Order(price,destination){     //parameterised constructor for passenger information and Order
        passengerName=name;
        insurance=company;
        weight_of_luggage=luggageWeight;
        priorityBoarding=priority;
    }

    void edit(){
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

};*/

class Customer{
    string email,name,address,phone;
    list <Passenger> Orderlist;
    //function ot validate phone number
    void validatePhone(){
        const regex pattern("^[\\+]?[(]?[0-9]{3}[)]?[-\\s\\.]?[0-9]{3}[-\\s\\.]?[0-9]{4,6}$");
        if(!regex_match(phone, pattern)){
            cout<<"\nEnter proper Phone number!";
            cout<<"\nEnter phone : ";
            cin>>phone;
        }
        else
            return;
        validatePhone();
    }
    
    //function to validate email
    void validateEmail(){
        const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        if(!regex_match(email, pattern)){
            cout<<"\nEnter proper Email ID!";
            cout<<"\nEnter Email : ";
            cin>>email;
        }
        else
            return;
        validateEmail();
    }

    void addPassenger(){        //adds a new passenger to Orderlist
        string passengerName,insurance,destination;
        int temp;
        double price,weight_of_luggage;
        bool priorityBoarding=false;
        cout<<"\nEnter Passenger Name: ";
        cin>>ws;
        getline(cin,passengerName);

        cout<<"\nEnter name and number of insurance company : ";
        cin>>ws;
        getline(cin,insurance);
        cout<<"\nEnter weight of luggage : ";
        cin>>weight_of_luggage;
        cout<<"\nPress 1 for priority boarding.\nPress 2 for normal boarding.\n : ";
        cin>>temp;
        if(temp==1)
            priorityBoarding=true;
        else if(temp==2)
            priorityBoarding=false;
        cout<<"\nEnter destination: ";
        cin>>ws;
        getline(cin,destination);
        price=getPrice(destination);
        Passenger p1(passengerName,insurance,weight_of_luggage,destination,price,priorityBoarding);
        Orderlist.push_back(p1);
    }
    double getPrice(string destnation){     //TODO:function to read a file/ database to find the price of the flight and return
        double fare;
        cout<<"\nEnter Fare: ";
        cin>>fare;
        return fare;
    }
    public:
    void addnew(){
        cout<<"\nEnter name : ";
        cin>>ws;
        getline(cin,name);
        cout<<"\nEnter phone : ";
        cin>>phone;
        validatePhone();

        cout<<"\nEnter email : ";
        cin>>email;
        validateEmail();
        cout<<"\nEnter address : ";
        cin>>ws;
        getline(cin,address);
    }

    void edit(){
        int ch=0;
        cout<<"\nWhat do you want to edit? ";
        cout<<"\n1.Name\n2.Phone Number\n3.Email\n4.Address\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        update(ch);
    }

    void update(int ch){
        switch(ch){
            case 1: cout<<"\nEnter name : ";
                    cin>>ws;
                    getline(cin,name);
                    break;
            
            case 2: cout<<"\nEnter phone : ";
                    cin>>phone;
                    validatePhone();
                    break;

            case 3: cout<<"\nEnter email : ";
                    cin>>email;
                    validateEmail();
                    break;

            case 4: cout<<"\nEnter address : ";
                    cin>>ws;
                    getline(cin,address);
                    break;

            default:cout<<"\n\nWrong Choice Entered!\n";
            break;
        }
    }
    void createOrder(){                 //This customer creates an order
        if(Orderlist.size()>=maxTickets){
            cout<<"\nMax "<<maxTickets<<" tickets per customer!\n";
            return;
        }
/*
        use parameter in createOrder to select how many tickets to order
        then use while loop
*/
        addPassenger();        
    }

    
    //delete function
    void Delete(){
        delete this;
    }
};


int main(){
    Customer *c=new Customer;
    c->addnew();
    c->createOrder();
    c->createOrder();
    c->createOrder();

    return 0;
}