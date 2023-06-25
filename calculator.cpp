#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <libc.h>


// NAMESPACE
using namespace std;

// CONSTANTS
#define MAX24H 23
#define MAX12H MAX12H - 12
#define MAXMIN 59
#define MAXSEC 59

// VARIABLES
bool menuShow;
int option;
time_t now = time(0);
tm *ltm = localtime(&now);
int seconds = (ltm->tm_sec);
int minutes = (ltm->tm_min);
int hours = (ltm->tm_hour);
int sec_pre = 0;

void clocks();


// DISPLAY FUNCTION
void displayM() {


    cout << endl;
    menuShow = true;
    while (menuShow != false) {
        cout << "*************************" << endl;
        cout << "* 1 - Add One Hour      *" << endl;
        cout << "* 2 - Add One Minute    *" << endl;
        cout << "* 3 - Add One Second    *" << endl;
        cout << "* 4 - Exit Program      *" << endl;
        cout << "*************************" << endl;

        cin >> option;

        switch(option) {
            case 1:
                hours = hours + 1;
                clocks();
                cout << endl;

                break;
            case 2:
                minutes = minutes + 1;
                clocks();
                cout << endl;
          
                break;
            case 3:
                seconds = seconds + 1;
                clocks();
                cout << endl;
         
                break;
            case 4:
                menuShow = false;
                break;
            default:
                cout << "Try again :: Not Valid" << endl;
                cout << "Choose again" << endl;
                cin >> option;
                break;
        }

    }

}


void clock12() {

  

    cout << hours << ":";
    
    
    cout << minutes << ":";
 
    
    cout << seconds;

}

void clock24() {
    
    if (hours > 12) {
            cout << hours - 12 << ":";
    }
    else {
        cout << hours << ":";
    }
    if (seconds > 59) {
        seconds = 0;
        minutes++;
    }

    if (minutes > 59 ) {
        minutes = 0;
        hours++;
    }

    if (hours > 24) {
        seconds = 0;
        minutes = 0;
        hours = 1;
    }

    
    cout << minutes << ":";
    cout << seconds;

    


}

// CLOCKS
void clocks() {

    
    cout << "**********************" << endl;
    cout << "*    12-Hour Clock   *" << endl;
    cout << "*       ";
    clock24();
    cout << "      *" << endl;
    cout << "**********************" << endl;

    cout << endl;

    cout << "**********************" << endl;
    cout << "*    24-Hour Clock   *" << endl;
    cout << "*       ";
    clock12();
    cout << "     *" << endl;
    cout << "**********************" << endl;

  

    }



// MAIN DRIVER
int main() {
    
    clocks();
  
    cout << endl;
    displayM();

    return 0;
}