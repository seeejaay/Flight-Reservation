#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;

string uName, pWord, flightTm[5];

void mainmenu(), logIn(), signUp(), menu(), popFlight();

int main()
{
    signUp();
    system("cls");
    mainmenu();
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

void popFlight() {
    //cout << "Manila - Osaka:";
}