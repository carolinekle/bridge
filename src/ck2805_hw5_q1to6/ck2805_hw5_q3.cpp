#include <iostream>
#include <string>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay) {
    int currentDay = startingDay;

    cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun" << endl;

    for (int j = 1; j < startingDay; j++) {
        cout << "\t";
    }

    for (int day = 1; day <= numOfDays; day++) {
        cout << day << "\t";

        currentDay++;

        if (currentDay == 8) {
            cout << endl;
            currentDay = 1; 
        }
    }

    cout << endl;

    
    return currentDay;
}

bool leapYear(int year){
    int div100 = year %100;
    int div4 = year %4;
    int div400 = year %400;
    
    if (div4 == 0 && div100 != 0 ||div400==0 ){
        return true;
    }else{
        return false;
    }

}



int printYearCalender(int year, int startingDay) {
    int currentDay = startingDay;
    

    for (int i = 1; i <= 12; i++) {
        if (i == 1) cout << "January " << year << endl;
        else if (i == 2) cout << "February " << year << endl;
        else if (i == 3) cout << "March " << year << endl;
        else if (i == 4) cout << "April " << year << endl;
        else if (i == 5) cout << "May " << year << endl;
        else if (i == 6) cout << "June " << year << endl;
        else if (i == 7) cout << "July " << year <<  endl;
        else if (i == 8) cout << "August " << year << endl;
        else if (i == 9) cout << "September " << year << endl;
        else if (i == 10) cout << "October " << year << endl;
        else if (i == 11) cout << "November " << year << endl;
        else if (i == 12) cout << "December " << year << endl;
        
        if (i == 2) { 
            if (leapYear(year)) {
                currentDay = printMonthCalendar(29, currentDay);
            } else {
                currentDay = printMonthCalendar(28, currentDay);
            }
        }else if (i == 4 || i == 6 || i == 9 || i == 11) {
            currentDay = printMonthCalendar(30, currentDay);
        }else {
            currentDay = printMonthCalendar(31, currentDay);
        }
        cout << endl; 
    }
    
}

int main() {
    int num, start;
    cout << "Enter the number of days in the month and the starting day " << endl;
    cin >> num;
    cin >> start;
    int day = printMonthCalendar(num, start)-1;

    cout<< "Last day: "<<day<<endl;

    cout<<"section b: "<<"\n"<<"enter a year to find out if its a leap year: "<<endl;
    int year;
    cin>>year;

    if (leapYear(year)){
        cout<<year<<" is a leap year."<<endl;
    }else{
        cout<<year<<" is not a leap year."<<endl;
    }

    cout<<"Enter a year and starting day"<<endl;

    int entireYear;
    int startingDay;
    cin>>entireYear;
    cin>>startingDay;
    printYearCalender(entireYear, startingDay);


    return 0;
}