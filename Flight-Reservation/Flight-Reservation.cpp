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
string flightUser[1][3];
string uName, pWord;

void mainmenu(), logIn(), signUp(), menu(), FlightChc(),logOut();

int main()
{
    srand(time(0));
    menu();
    
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
    i = 0;
    while (i < 3) {
        cout << "*" << setw(120) << "*" << endl;
        i++;
    }
    cout << "*" << setw(67) << "Popular Flights:" << setw(53) << "*" << endl;
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
    string reply;
    int depChc, ariChc, timeChc, seat, randStore[5];
    int seatNo = (rand() % 500) + 1;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << flightNm[i] << endl;
    }
depart:
    cout << "Enter your departure location from the list: ";
    cin >> depChc;
    if (depChc < 1 || depChc > 5) {
        cout << "Invalid location\n";
        goto depart;
    }
    flightUser[0][0] = flightNm[depChc - 1];
arriv:
    cout << "Enter your arrival location from the list: ";
    cin >> ariChc;
    if (ariChc != depChc) {
        if (ariChc < 1 || ariChc > 5) {
            cout << "Invalid location!\n";
            goto arriv;
        }
    }
    else {
        cout << "Duplicate location!\n";
        goto arriv;
    }
    flightUser[0][1] = flightNm[ariChc - 1];
    cout << "Your flight will be from " << flightUser[0][0] << " to " << flightUser[0][1] << "." << endl;
    cout << "The time slots are: " << endl;
    int c = 0, r;
    srand(time(0));
    while (c < 5) {
        do 
        {
            r = rand() % 10;
        }while(randStore[0] == r || randStore[1] == r || randStore[2] == r || randStore[3] == r || randStore[4] == r);
    /*repeat:
        r = rand() % 10;
        if (randStore[0] == r || randStore[1] == r || randStore[2] == r || randStore[3] == r || randStore[4] == r) {
            goto repeat;
        }*/
        randStore[c] = r;
        cout << c + 1 << ". " << flightTm[r] << endl;
        c++;
    }
timeslot:
    cout << "Enter your time slot: ";
    cin >> timeChc;
    if (timeChc > 5 || timeChc < 1) {
        cout << "Invalid time slot!\n";
        goto timeslot;
    }
    flightUser[0][2] = flightTm[timeChc - 1];
seatChc:
    cout << "The available seats left are: " << seatNo << ". \nPlease enter your seat: ";
    cin >> seat;
    if (seatNo == 0) {
        cout << "There are no more seats available, please choose a different time slot";
        system("pause");
        goto timeslot;
    }
    if (seat > seatNo) {
        cout << "Invalid seat, please choose another one!\n";
        goto seatChc;
    }
    cout << "Please double check your flight details:" << endl;
    cout << "Destination: " << flightUser[0][0] << " to " << flightUser[0][1] << endl;
    cout << "Time Slot: " << flightUser[0][2] << endl;
    cout << "Seat # " << seat <<endl;
    cin.ignore();
 
    logOut();
    
    
}
