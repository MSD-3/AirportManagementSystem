//preprocessor directives
#include<iostream>
#include "Customer.cpp"
using namespace std;

int main(){
    string dash="--------------------------";
    cout<<dash<<"\n Airline Booking Services\n"<<dash<<endl;
    Customer *c=new Customer;
    c->addnew();
    int choice=6;
    do{                             //menu driven system
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
                    break;
            case 5:cout<<"\nExiting\n";
                    break;
            default:cout<<"\nWrong Input.\nTry Again.\n";
                    break;
        }
    }while(choice!=5);  //exiting condition
    return 0;
}