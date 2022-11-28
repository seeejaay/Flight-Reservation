#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;

string flightNm[5] = { "Jakarta, Indonesia", "Amsterdam, Netherlands", "New York, USA", "Manila, Philippines", "Osaka, Japan" };
string flightTm[10] = { "10:00PM - 11:00PM", "12:15AM - 2:00AM", "3:00AM - 3:45AM", "4:00AM - 5:30AM", "12:00PM - 2:15PM", "8:00AM - 9:20AM", "3:00PM - 4:45PM", "5:30PM - 7:00PM", "7:15PM - 8:50PM", "9:15PM - 9:50PM" };
string months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec" };
string flightUser[1][4];
string uName, pWord;
void mainmenu(), logIn(), signUp(), menu(), FlightChc(), logOut();

int main()
{
    srand(time(0));
    //menu();
    FlightChc();
}

void mainmenu() {
    int i = 0;
    while (i < 120) {
        cout << "*";
        i++;
    }
    cout << "*" << '\n' << "*" << setw(78) << "Welcome to BBMM's Flight Reservation!" << setw(43) << "*\n";
    i = 0;
    cout << "*";
    while (i < 119) {
        cout << "~";
        i++;
    }
    cout << "*\n";
    cout << "*" << setw(62) << "__ | __" << setw(58) << "*" << endl;
    cout << "*" << setw(68) << "--@--@--(_)--@--@--" << setw(52) << "*" << endl;
    cout << "*" << setw(120) << "*" << endl;
}


void menu() {
    int n;
    string reply;
    cout << "[1] Login" << endl << "[2] Sign Up" << endl << "[3] Log Out" << endl << "[4] Exit" << endl << "Choice: ";
    cin >> n;
    cin.ignore();
    switch (n)
    {
    case 1:
        //prevent form bypassing login, checks if placeholder has value
        if (uName.empty() && pWord.empty())
        {
            cout << "There is no registered account yet" << endl;
            Sleep(1000);
            system("cls");
            return menu();
        }
        logIn();
        break;
    case 2:
        signUp();
        break;
    case 3:
        //logs the user out
        return menu();
        break;
    case 4:
        //check if you want to exit program
        cout << "Do you really want to exit the program? [Y/YES] / [N/NO]: ";
        getline(cin, reply);
        // converts reply to uppercase
        transform(reply.begin(), reply.end(), reply.begin(), ::toupper);
        if (reply == "Y" || reply == "YES")
        {
            //exits the program
            exit(1);
        }
        menu();
        
        break;
    default:
        cout << "Invalid input!";
        return menu();
        break;
    }
}

void signUp()
{
    string pWordRepeat;


    cout << "Enter your Username: ";
    getline(cin, uName);
    cout << "Password must be more then 10 characters" << endl;
again:

    cout << "Enter Password: ";
    getline(cin, pWord);
    if (pWord.length() <= 10) {
        cout << "Password is too Short" << endl;
        goto again;
    }

    do {
        cout << "Enter Password Again: ";
        getline(cin, pWordRepeat);

    } while (pWord != pWordRepeat);


    cout << "You have Succesfully Signed Up!" << endl;
    Sleep(1000);
    system("cls");
    return menu();

}
void logIn()
{
    string cuName, cpWord;
    do {
        cout << "Enter your Username: ";
        getline(cin, cuName);
        cout << "Enter Password: ";
        getline(cin, cpWord);
    }while(cuName != uName || cpWord != pWord);

    cout << "You have succesfully logged in!" << endl;
    Sleep(1000);
    system("cls");
    return FlightChc();
    
}


void logOut()
{
    repeat:
    string reply;
    cout << "Do you want to logout? [Y/N]: ";
    getline(cin, reply);
    transform(reply.begin(), reply.end(), reply.begin(), ::toupper);
    if (reply == "Y" || reply == "YES") {
        Sleep(1000);
        system("cls");
        return menu();
    }
    else goto repeat;
}
void FlightChc() {
    string reply, flightTmStore[5];
    int depChc, ariChc, timeChc, seat, randStore[5] = {},monthPicker,datePicker, passengerNum;
    int seatNo = (rand() % 500) + 1;
    int counter;
    cout << "How many seat do you want to reserve? : ";
    cin >> passengerNum;
    int* seatPos = new int(passengerNum);
        //displays flight locations
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << flightNm[i] << endl;
        }
    depart:
        cout << "Enter your departure location from the list: ";
        cin >> depChc;
        //checks if invalid
        if (depChc < 1 || depChc > 5) {
            cout << "Invalid location\n";
            goto depart;
        }
        flightUser[0][0] = flightNm[depChc - 1];
    arriv:
        cout << "Enter your arrival location from the list: ";
        cin >> ariChc;
        //checks if invalid
        if (ariChc != depChc) {
            if (ariChc < 1 || ariChc > 5) {
                cout << "Invalid location!\n";
                goto arriv;
            }
        }
        //checks if duplicate
        else {
            cout << "Duplicate location!\n";
            goto arriv;
        }

    enterMonthNum:
        cout << "Enter the Month Number (1,2,3,4,5,...) : ";
        cin >> monthPicker;


        if (monthPicker == 4 || monthPicker == 6 || monthPicker == 11)
        {
            do
            {
                cout << "Enter Preferred Date: ";
                cin >> datePicker;
            } while (datePicker > 30);
        }
        else if (monthPicker == 2)
        {
            do
            {
                cout << "Enter Preferred Date: ";
                cin >> datePicker;
            } while (datePicker > 28);
        }
        else if (monthPicker == 1 || monthPicker == 3 || monthPicker == 5 || monthPicker == 7 || monthPicker == 8 || monthPicker == 10 || monthPicker == 12)
        {
            do
            {
                cout << "Enter Preferred Date: ";
                cin >> datePicker;
            } while (datePicker > 31);
        }
        else
        {
            cout << "INVALID INPUT";
            Sleep(1);
            goto enterMonthNum;
        }
        monthPicker -= 1;


        flightUser[0][1] = flightNm[ariChc - 1];
        cout << "Your flight will be from " << flightUser[0][0] << " to " << flightUser[0][1] << "." << endl;
        cout << "The time slots are: " << endl;
        int c = 0, r;
        //randomizes index of randStore[]
        srand(time(0));
        //outputs random time
        while (c < 5) {
            do
            {
                r = rand() % 10;
            } while (randStore[0] == r || randStore[1] == r || randStore[2] == r || randStore[3] == r || randStore[4] == r);
            randStore[c] = r;
            cout << c + 1 << ". " << flightTm[r] << endl;
            flightTmStore[c] = flightTm[r];
            c++;
        }
    timeslot:
        cout << "Enter your time slot: ";
        cin >> timeChc;
        //checks if valid input
        if (timeChc > 5 || timeChc < 1) {
            cout << "Invalid time slot!\n";
            goto timeslot;
        }
        flightUser[0][2] = flightTmStore[timeChc - 1];
        for (counter = 1; counter <= passengerNum; counter++) {
seatChc:
        cout << "The available seats left are: " << seatNo << ". \nPlease enter your seat: ";
        cin >> seat;
        seatPos[counter - 1] = seat;
        //outputs random no. of seats from 0 - 500
        if (seatNo == 0) {
            cout << "There are no more seats available, please choose a different time slot";
            system("pause");
            goto timeslot;
        }
        //checks if invalid input
        if (seat > seatNo) {
            cout << "Invalid seat, please choose another one!\n";
            goto seatChc;
        }
        //outputs flight receipt
        int i = 0;
        cout << "Please double check your flight details:" << endl;
        cout << "Destination: " << flightUser[i][0] << " to " << flightUser[i][1] << endl;
        cout << "Departure Date: " << months[monthPicker] << " " << datePicker << endl;
        cout << "Time Slot: " << flightUser[i][2] << endl;
        cout << "Seat # " << seatPos[counter - 1] << endl;
        i++;
        seatNo -= 1;
        cin.ignore();
    }
    logOut();
}
