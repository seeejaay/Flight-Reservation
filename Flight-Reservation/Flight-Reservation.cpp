#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;

string uName, pWord, flightTm[5];

void mainmenu(), signUp(), menu();

int main()
{
    //signUp();
    //system("cls");
    //mainmenu();
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
    //menuRepeat:
    int n;
    cout << "[1] Login" << endl << "[2] Sign Up" << endl << "[3] Log Out" << endl << "[4] Exit" << endl << "Choice: ";
    cin >> n;
    cin.ignore();
    switch (n)
    {
    menuRepeat:
    case 1:
        logIn();
        break;
    case 2:
        signUp();
        break;
    case 3:
        //logOut();
        break;
    case 4:
        // exitProgram();
        break;
    default:
        cout << "Invalid input!";
        goto menuRepeat;
        break;
    }
}

void signUp()
{
    string pWordRepeat;


    cout << "Enter your Username: ";
    getline(cin, uName);
    again:
    cout << "Enter Password: ";
    getline(cin, pWord);
    if (pWord.length() <= 10) {
        cout << "Password is too Short" << endl;
        goto again;
    }
    else;
    do {
        cout << "Enter Password Again: ";
        getline(cin, pWordRepeat);

    } while (pWord != pWordRepeat);


    cout << "You have Succesfully Signed Up!\n";
    return menu();
    
}
void logIn()
{
    string cuName, cpWord;
    confirm:
    cout << "Enter your Username: ";
    getline(cin, cuName);
    cout << "Enter Password: ";
    getline(cin, cpWord);
    if (cuName == uName && cpWord == pWord) {
        cout << "You have Succesfully Logged In!\n" << endl;
        return menu();
    }
    else {
        cout << "Incorrect username or password" << endl;
        goto confirm;
    }
}

void FlightChc() {
    string flightNm[5] = { "Jakarta, Indonesia", "Amsterdam, Netherlands", "New York, USA", "Manila, Philippines", "Osaka, Japan" };
    string flightTm[10] = { "10:00PM - 11:00PM", "12:15AM - 2:00AM", "3:00AM - 3:45AM", "4:00AM - 5:30AM", "12:00PM - 2:15PM", "8:00AM - 9:20AM", "3:00PM - 4:45PM", "5:30PM - 7:00PM", "7:15PM - 8:50PM", "9:15PM - 9:50PM" };
    string flightUser[1][2];
    int depChc, ariChc;
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
    string departLoc = flightNm[depChc - 1];
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
    string arrivLoc = flightNm[ariChc - 1];
    cout << "Your flight will be from " << departLoc << " to " << arrivLoc << "." << endl;
    cout << "The time slots are: " << endl;
    int c = 0, r, i = rand();
    srand(time(0));
    while (c < 5) {
    repeat:
        r = rand() % 10;
        if (r != rand()) {
            cout << c + 1 << ". " << flightTm[r] << endl;
        }
        else {
            goto repeat;
        }
        c++;
    }
}