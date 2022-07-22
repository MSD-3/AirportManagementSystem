#include<iostream>
#include <ctime>
#include<cstdio>
using namespace std;

class Time{
    int day,month,year;
    int hr,min,sec;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    public:
    void setTime(){     //setting required time to object  format : HH:MM:SS  
        cout<<"\nEnter time in HH:MM:SS format : ";
        scanf("%d:%d:%d",&hr,&min,&sec);
        validateTime();
    }

    void setDate(){     //setting required date to object format : dd/mm/yyyy
        cout<<"\nEnter date in dd/mm/yyyy format : ";
        scanf("%d/%d/%d",&day,&month,&year);
        validateDate();
        setTime();
    }

    void validateTime(){
        //checking for time input error
        if(hr>23 || hr<00 || min>=60 || min<00 || sec>=60 || sec<00){                     //basic checks
            cout<<"\nWrong time Input . Enter again!\n";
            setTime();
            return;
        }
    }

    void validateDate(){
        //checking for date input error
        if(day>31 || month>12 || day<1 || month< 1 || year<1900+ltm->tm_year){          //basic checks
            cout<<"\nWrong date input. Enter again!\n";
            setDate();
            return;
        }
        if(month==2 && (day>28 || (LeapYear(year) && day>29))){         //february check
            cout<<"\nWrong date input. Enter again!\n";
            setDate();
            return;
        }
        if((month== 1 ||month== 3 || month== 5 || month== 7 || month== 8 || month== 10 || month== 12) && day>31){         //31 days month check
            cout<<"\nWrong date input. Enter again!\n";
            setDate();
            return;
        }
        if((month== 4 ||month== 6 || month== 9 || month== 11 ) && day>30){         //31 days month check
            cout<<"\nWrong date input. Enter again!\n";
            setDate();
            return;
        }

    }

    bool LeapYear(int year){
        if (year % 400 == 0)        //leap year multiple of 400
            return true;

        if (year % 100 == 0)        //non leap year if multiple of 100 but not 400
            return false;

        if (year % 4 == 0)          //leap year multiple of 4 but not 100
            return true;
    return false;
    }

};