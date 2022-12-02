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
string flightUser[4];
string uName, pWord;

int numTicket[50][2], datePicker, passengerNum;

void mainmenu(), logIn(), signUp(), menu(), FlightChc(), logOut(), popFlight(), Ticketing();


int main()
{
    srand(time(0));
    system("Color 03");
    //mainmenu();
    FlightChc();
    /*mainmenu();
    menu();*/
    Ticketing();
    //testing purpose
    //FlightChc();
}

void mainmenu() {
    int i = 0;
    int b = 0;
    cout << setw(5);
    while (i < 110) {
        cout << "*";
        i++;
    }
    
    cout << setw(88) << "Welcome to BBMM's Flight Reservation!" << setw(43) << "\n";
   
    i = 0;
    cout << setw(5);
    while (i < 110) {
        cout << "~";
        i++;
    }
    

    cout << setw(72) << "__ | __" << setw(58)<< endl;
    cout << setw(72) << "--@--@--(_)--@--@--" << setw(52) << endl;
    
    cout << setw(95) << "\n";
    
    b = 0;
    popFlight();
    cout << setw(5);
    while (b < 110) {
        cout << "~";
        b++;
    }
    cout << endl;
    
}


void menu() {
    int n;
    string reply;
    cout <<setw(46) <<  "[1] Login" << endl << setw(48) << "[2] Sign Up" << endl << setw(48) << "[3] Log Out" << endl << setw(45) << "[4] Exit" << endl << setw(45) << "Choice: ";
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
            mainmenu();
            menu();
        }
        logIn();
        break;
    case 2:
        signUp();
        break;
    case 3:
        //logs the user out
        logOut();
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
            Sleep(1000);
            system("cls");
            exit(1);
        }
        mainmenu();
        
        break;
    default:
        cout << "Invalid input!";
        return mainmenu();
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
    mainmenu();
    menu();

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
    //convers input to all caps
    transform(reply.begin(), reply.end(), reply.begin(), ::toupper);
    if (reply == "Y" || reply == "YES") {
        Sleep(1000);
        system("cls");
        mainmenu();
        menu();
    }
    else goto repeat;
}


void FlightChc() {
    string reply, flightTmStore[5];
    int depChc, ariChc, timeChc, seat = 0, randStore[5] = {}, monthPicker;
    int seatNo = (rand() % 500);
    int counter;
    //int Class;
    mainmenu();
    do {
        cout << "How many seat do you want to reserve? : ";
        cin >> passengerNum;
    } while (passengerNum > 50 || passengerNum < 0);
        //displays flight locations
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << flightNm[i] << endl;
        }
    depart:
        cout << "Enter your departure location from the list: ";
        cin >> depChc;
        //checks if invalid
        if (depChc < 1 || depChc > 5)
        {
            cout << "Invalid location\n";
            goto depart;
        }
        flightUser[0] = flightNm[depChc - 1];
    arriv:
        cout << "Enter your arrival location from the list: ";
        cin >> ariChc;
        //checks if invalid
        if (ariChc != depChc)
        {
            if (ariChc < 1 || ariChc > 5) {
                cout << "Invalid location!\n";
                goto arriv;
            }
        }
        //checks if duplicate
        else
        {
            cout << "Duplicate location!\n";
            goto arriv;
        }
        //lets you pick departure date
        flightUser[1] = flightNm[ariChc - 1];
    enterMonthNum:
        cout << "Enter the Month Number (1,2,3,4,5,...) : ";
        cin >> monthPicker;

        //mos. with 30 days
        if (monthPicker == 4 || monthPicker == 6 || monthPicker == 11)
        {
            do
            {
                cout << "Enter Preferred Date: ";
                cin >> datePicker;
            } while (datePicker > 30 || datePicker < 0);
        }
        //february no leap year
        else if (monthPicker == 2)
        {
            do
            {
                cout << "Enter Preferred Date: ";
                cin >> datePicker;
            } while (datePicker > 28 || datePicker < 0);
        }
        //months with 31 days
        else if (monthPicker == 1 || monthPicker == 3 || monthPicker == 5 || monthPicker == 7 || monthPicker == 8 || monthPicker == 10 || monthPicker == 12)
        {
            do
            {
                cout << "Enter Preferred Date: ";
                cin >> datePicker;
            } while (datePicker > 31 || datePicker < 0);
        }
        else
        {
            cout << "INVALID INPUT"<<endl;
            Sleep(1);
            goto enterMonthNum;
        }
        flightUser[3] = months[monthPicker - 1];
        cout << "Your flight will be from " << flightUser[0] << " to " << flightUser[1] << "." << endl;
        cout << "The time slots are: " << endl;
        int c = 0, r;
        //randomizes index of randStore[]
        
        //outputs random time
        while (c < 5)
        {
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
        flightUser[2] = flightTmStore[timeChc - 1];
        int i = 0;
        c = 0;
        for (counter = 1; counter <= passengerNum; counter++)
        {
            seatChc:
            cout << "The available seats left are: " << seatNo << ". \nPlease enter your seat: ";
            cin >> seat;
            for (i; i < passengerNum; i++) {
                if (seat != numTicket[i][0]) {
                    numTicket[i][0] = seat;
                }
                else {
                    cout << "Seat " << seat << " is already booked!" << endl;
                    goto seatChc;
                }
            }
            /*do {
            seatChc:
                
                seatnum
                int i = 0;
                for (i; i < passengerNum; i++) {

                }
            } while (seat <= seatNo);*/
            numTicket[c][1] = rand() % 999999;
            cout << "Ticket Number: " << numTicket[c][1] << endl;
            cout << "Seat # " << numTicket[i][0] << endl;
            seatNo -= 1;
            i++;
            c++;
            cin.ignore();
        }
        //Sleep(1000);
        //system("cls");
        //int i;
        ////outputs flight receipt
        //for (i = ;i <= passengerNum; i++) {
        //    cout << "Please double check your flight details:" << endl;
        //    cout << "Destination: " << flightUser[i][0] << " to " << flightUser[i][1] << endl;
        //    cout << "Departure Date: " << months[monthPicker] << " " << datePicker << endl;
        //    cout << "Time Slot: " << flightUser[i][2] << endl;
        //    cout << "Seat # " << seatPos[counter - 1] << endl;
        //    seatNo -= 1;
        //    cin.ignore();
        //}
 
        // User choose a seat class then proceed to payment
/*
Classes:

        cout << "Pick a seat class" << endl;
        cout << "1. Economy Class" << endl;
        cout << "2. First Class" << endl;
        cout << "3. Businesss Class" << endl;
        cin >> Class;

        switch (Class) {
        case 1: {
                cout << "You Have Chosen Economy Class!";
                break;
            }
        case 2: {
                cout << "You Have Chosen First Class";
                break;
            }
        case 3: {
                cout << "You Have Chosen Business Class";
                break;
            }
        default: {
                cout << "Invalid Input";
                Sleep(2000);
                system("cls");
                goto Classes;
                break;
            }
        }
    
        //price
        //  system("cls");
        cout << "Proceeding Payment";
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        system("cls");
        system("pause");
        
        cout << "andito na ako"; */

    //logOut();
}

void popFlight()
{
    int i, cNm, cNm2, cTm;
    cout << setw(80) << "Today's most popular flights are:" << endl;
    //lists random flight arriv & dest, along with random time
    for (i = 0; i < 3; i++) {
        cNm = rand() % 5;
        cTm = rand() % 10;
        cout <<setw(32) << i + 1 << ". " << flightNm[cNm] << " to ";
    repNm2:
        cNm2 = rand() % 5;
        if (cNm == cNm2) {
            goto repNm2;
        }
        else {
            cout << flightNm[cNm2] << ": ";
        }
        cout << flightTm[cTm] << endl;
    }
}

void Ticketing() {
    for(int i = 0; i<=10; i++)
    {
        cout << numTicket[i][0] << " " << numTicket[i][1] << endl;
    }

    int viewChc, ticketNo, maxCheck = 1;
    cout << "How would you like to view your ticket?:" << endl << "[1] By Ticket No." << endl << "[2] By Seat No." << endl;
    cin >> viewChc;
    if (viewChc == 1) {
    ticketChc:
        cout << "Please enter the ticket no.: ";
        cin >> ticketNo;
        int i = 0;
        while ( i <= passengerNum) {
            if (ticketNo != numTicket[i][1]) {
                cout << "Invalid ticket number!" << endl;
                goto ticketChc;
                
            }
            else  {
                cout << "Ticket Number: " << numTicket[i][1] << endl;
                cout << "Seat #" << numTicket[i][0] << endl;
                cout << "Destination: " << flightUser[0] << " to " << flightUser[1] << endl;
                cout << "Departure Date: " << flightUser[3] << " " << datePicker << endl;
                cout << "Time Slot: " << flightUser[2] << endl;
                maxCheck += 1;
                i++;
            }
            
        }
    }
    /*else if (viewChc == 2) {

        }
        else {

        }*/
}
