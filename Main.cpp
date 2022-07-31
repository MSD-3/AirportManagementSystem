//preprocessor directives
#include<iostream>
#include<array>
#include<iterator>
#include "Customer.cpp"
#include "Admin.cpp"
using namespace std;
array<Customer,100> CustomerList;
void customermenu(Customer *c){
        int choice;
        do{                             //menu driven system
                cout<<"\n\n\nMENU\n\n";
                cout<<"\n1.Book Ticket.";
                cout<<"\n2.Edit Existing Account.";
                cout<<"\n3.Display Bookings.";
                cout<<"\n4.Delete Account.";
                cout<<"\n5.Exit.";
                cout<<"\n\nEnter Choice: ";
                cin>>choice;
                switch(choice){
                        case 1:c->createOrder();
                                break;
                        case 2:c->edit();
                                break;
                        case 3:c->displayOrders();
                                break;
                        case 4:c->Delete();
                                choice=5;
                                break;
                        case 5:break;
                        default:cout<<"\nWrong Input.\nTry Again.\n";
                                break;
                }
        }while(choice!=5);  //exiting condition
        return;
}

void selectExistingCustomer(){
        if(CustomerList.empty()){
                cout<<"\nNo customer details in the system!";
                return;
        }
        int i=0,num;
        string name;
        for(;i<CustomerList.size();i++){
                cout<<endl<<i+1<<". "<<CustomerList.at(i).getName();
        }
        do{
                cout<<"\n\nSelect account : ";
                cin>>num;
        }while(num>i+1);
        customermenu(&CustomerList.at(num-1));
}

Customer createCustomer(){
        Customer c;
        c.addnew();
        customermenu(&c);
        return c;
}
int main(){
        string dash="--------------------------";
        cout<<dash<<"\n Airline Booking Services\n"<<dash<<endl;
        string id,password;
        int choice=6;
        int i=0;
        bool flag=true;         //flag for admin credentials input
        Admin *a=new Admin;
        do{
                cout<<"\nEnter Admin Credentials";              //taking input of admin credentials
                cout<<"\nID: ";
                cin>>id;
                cout<<"\nPassword: ";
                cin>>password;
                if(id!=a->getID() || password!=a->getPassword())        //verifying credentials
                        cout<<"\nWrong Credentials. Try Again.\n";
                else flag=false;
        }while(flag);
        do{                             //menu driven system
                cout<<"\n\n\nMENU\n\n";
                cout<<"\n1.Add new Customer.";
                cout<<"\n2.Select Exisiting Customer. ";
                cout<<"\n3.Schedule Flight.";
                cout<<"\n4.Search Flight.";
                cout<<"\n5.Remove Flight.";
                cout<<"\n6.Exit";
                cout<<"\n\nEnter your choice : ";
                cin>>choice;
                switch(choice){
                        case 1:CustomerList[i++]=createCustomer();
                                break;
                        case 2:selectExistingCustomer();
                                break;
                        case 3://scheduleflight
                                break;
                        case 4://searchflight
                                break;
                        case 5://removeflight
                                break;
                        case 6:cout<<"\nExiting\n";
                                break;
                        default:cout<<"\nWrong Input.\nTry Again.\n";
                                break;
                }
        }while(choice!=6);  //exiting condition
        return 0;
}
