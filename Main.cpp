//preprocessor directives
#include<iostream>
#include<list>
#include<iterator>
#include "Customer.cpp"
#include "Admin.cpp"

using namespace std;
list<Customer> CustomerList{};
Customer customermenu(Customer c){
        int choice;
        do{                             //menu driven system
                cout<<"\n\n\nMENU\n\n";
                cout<<"\n1.Book Ticket.";
                cout<<"\n2.Edit Existing Account.";
                cout<<"\n3.Display Bookings.";
                cout<<"\n4.Delete Account.";
                cout<<"\n5.Return.";
                cout<<"\n\nEnter Choice: ";
                cin>>choice;
                switch(choice){
                        case 1:c.createOrder();
                                break;
                        case 2:c.edit();
                                break;
                        case 3:c.displayOrders();
                                break;
                        case 4:c.Delete();
                                choice=5;
                                break;
                        case 5:break;
                        default:cout<<"\nWrong Input.\nTry Again.\n";
                                break;
                }
        }while(choice!=5);  //exiting condition
        return c;
}

void schedulemenu(){
        int choice;
        do{
                cout<<"\n1.Schedule Flight.";
                cout<<"\n2.Remove Flight.";
                cout<<"\n3.Display Flight Schedule.";
                cout<<"\n4.Return.";
                cout<<"\nEnter your choice : ";
                cin>>choice;
                switch(choice){
                        case 1:schedule->addFlight();
                                break;
                        case 2:schedule->removeFlight();
                                break;
                        case 3:schedule->display();
                                break;
                        case 4: break;
                        default:cout<<"\nWrong Input.\nTry Again.\n";
                                break;
                }
        }while(choice!=4);               //exit condition

}


void selectExistingCustomer(){
        list<Customer>::iterator it;
        if(CustomerList.empty()){
                cout<<"\nNo customer details in the system!";
                return;
        }
        int i=0,num;
        string name;
        for(it=CustomerList.begin();it!=CustomerList.end();it++,i++){
                cout<<endl<<i+1<<". "<<it->getName();
        }
        do{
                cout<<"\n\nSelect account : ";
                cin>>num;
        }while(num>i+1);
        it=CustomerList.begin();
        for(i=0;i<num-1;i++)
                it++;
        *it=customermenu(*it);
        cout<<endl<<it->getName();
}

Customer createCustomer(){
        Customer c;
        c.addnew();
        c=customermenu(c);
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
                flag=true;
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
                cout<<"\n2.Select Exisiting Customer.";
                cout<<"\n3.Manage Flight Schedule.";
                cout<<"\n4.Exit";
                cout<<"\n\nEnter your choice : ";
                cin>>choice;
                switch(choice){
                        case 1:CustomerList.push_back(createCustomer());
                                break;
                        case 2:selectExistingCustomer();
                                break;
                        case 3:schedulemenu();
                                break;
                        case 4:cout<<"\nExiting\n";
                                break;
                        default:cout<<"\nWrong Input.\nTry Again.\n";
                                break;
                }
        }while(choice!=4);  //exiting condition
        return 0;
}