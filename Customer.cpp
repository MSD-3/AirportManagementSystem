//preprocessor directives
#include<iostream>
#include<list>
#include<iterator>
#include "Order.cpp"
#define maxTickets 5
using namespace std;

class Customer{
    string email,name,address,phone;
    list <Passenger> Orderlist;
    
    void validatePhone(){       //function ot validate phone number
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
    
    void validateEmail(){            //function to validate email
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
        cout<<"\nPress 1 for priority boarding. Press 2 for normal boarding. : ";
        cin>>temp;
        if(temp==1)
            priorityBoarding=true;
        else if(temp==2)
            priorityBoarding=false;
        price=getPrice();
        Passenger p1(passengerName,insurance,weight_of_luggage,price,priorityBoarding);     //creating object of Passenger class
        Orderlist.push_back(p1);                                                                        //pushing object to list
    }
    double getPrice(){     //TODO:function to read a file/ database to find the price of the flight and return
        double fare;
        cout<<"\nEnter Fare: ";
        cin>>fare;
        return fare;
    }

    void update(int ch){            //private function to update data members
        cout<<"\n1.Edit Customer Account\n";
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
            case 5: break;

            default:cout<<"\n\nWrong Choice Entered!\n";
            break;
        }
    }
    public:
    void addnew(){              //public function to add new customer account
        cout<<"\n1.Create Customer Account\n";
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

    void edit(){                //public function to select what to edit in customer details. calls update() to finish task
        int ch=0;
        cout<<"\nWhat do you want to edit? ";
        cout<<"\n1.Name\n2.Phone Number\n3.Email\n4.Address\n5.Go back\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        update(ch);             //calling update()
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
        addPassenger();         //calls private addPassenger() to create new ticket  
    }

    void displayOrders(){       //public function to display all the orders made against an account
        list<Passenger>::iterator it;
        int i=1;
        if(Orderlist.empty()){
            cout<<"\nNo Booking History!\n";
            return;
        }
        for(it=Orderlist.begin();it!=Orderlist.end();it++){
            cout<<"\n\nOrder #"<<i++;
            it->display();
        }
    }
    
    //delete function
    void Delete(){              //public function to delete account 
        Orderlist.clear();
        delete this;
        cout<<"\nAccount Deleted!\n";
    }
};
