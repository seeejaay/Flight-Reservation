#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;
/*
    Project Manager/ Main Programmers - Carl Justine Malabanan,Mark Jandhel Maca
    Programmers - Miguel Nicos Baltazar, Troy Jansen Bay
    Documentation - Everyone
*/
string flightNm[5] = { "Jakarta, Indonesia", "Amsterdam, Netherlands", "New York, USA", "Manila, Philippines", "Osaka, Japan" };
string flightTm[10] = { "10:00PM - 11:00PM", "12:15AM - 2:00AM", "3:00AM - 3:45AM", "4:00AM - 5:30AM", "12:00PM - 2:15PM", "8:00AM - 9:20AM", "3:00PM - 4:45PM", "5:30PM - 7:00PM", "7:15PM - 8:50PM", "9:15PM - 9:50PM" };
string months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec" };
string flightUser[4];
string uName, pWord;
bool viewTix = false;
bool payclass = false;
int numTicket[50][2], datePicker, passengerNum;

void mainmenu(), logIn(), signUp(), menu(), FlightChc(), logOut(), popFlight(), Ticketing(), Class();

int main()
{
    srand(time(0));
    system("Color 03");

    mainmenu();
    menu();


}

void mainmenu() {
    system("cls");
    int i = 0;
    int b = 0;
    cout << setw(5);
    while (i < 110) {
        cout << "*";
        i++;
    }

    cout << setw(90) << "Welcome to Big Big MJ MACA's Flight Reservation!" << setw(43) << "\n";

    i = 0;
    cout << setw(5);
    while (i < 110) {
        cout << "~";
        i++;
    }


    cout << setw(72) << "__ | __" << setw(58) << endl;
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

    int n ;
    string reply;
    cout << setw(46) << "[1] Login" << endl << setw(48) << "[2] Sign Up" << endl << setw(48) << "[3] Log Out" << endl << setw(45) << "[4] Exit" << endl << setw(53) << "[5] View Tickets" << setw(45) << endl << "Choice: ";
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
        //signs the user up
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
        system("cls");
        mainmenu();
        menu();
        break;

    case 5:
        //views tickets if available
        if (viewTix == true) {
            Ticketing();
        }
        else {
            cout << "No tickets available!";
            Sleep(1000);
            system("cls");
            mainmenu();
            menu();
        }
        break;

    default:
        //resets if invalid input
        cout << "Invalid input!";
        mainmenu();
        menu();
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
    //checks for pWord length
    if (pWord.length() <= 10) {
        cout << "Password is too Short" << endl;
        goto again;
    }
    //checks if pWordRepeat is correct to pWord
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
    //checks if the same as sign up details and logs user in
    do {
        cout << "Enter your Username: ";
        getline(cin, cuName);
        cout << "Enter Password: ";
        getline(cin, cpWord);
    } while (cuName != uName || cpWord != pWord);
    cout << "You have succesfully logged in!" << endl;
    Sleep(1000);
    system("cls");
    return FlightChc();

}

void logOut()
{
    cin.ignore();
repeat:
    string reply;
    cout << "Do you want to logout? [Y/N]: ";
    getline(cin, reply);
    //converts input to all caps
    transform(reply.begin(), reply.end(), reply.begin(), ::toupper);
    //checks for user decision
    if (reply == "Y" || reply == "YES") {
        Sleep(1000);
        system("cls");
        mainmenu();
        menu();
    }
    else {
        goto repeat;
    }
}

void FlightChc() {
    string reply, flightTmStore[5];
    int depChc, ariChc, timeChc, seat = 0, randStore[5] = {}, monthPicker;
    int seatNo = (rand() % 500);
    int counter;
    mainmenu();
    // lets user input how many seats to reserve
    do {
        cout << "\tHow many seat do you want to reserve? : ";
        cin >> passengerNum;
    } while (passengerNum > 50 || passengerNum < 0);
    //displays flight locations
    for (int i = 0; i < 5; i++)
    {
        cout <<"\t" << i + 1 << ". " << flightNm[i] << endl;
    }
    
depart:
    cout << "\tEnter your departure location from the list: ";
    cin >> depChc;
    //checks if invalid
    if (depChc < 1 || depChc > 5)
    {
        cout << "\tInvalid location\n";
        goto depart;
    }
    flightUser[0] = flightNm[depChc - 1];
arriv:
    cout << "\tEnter your arrival location from the list: ";
    cin >> ariChc;
    //checks if invalid
    if (ariChc != depChc)
    {
        if (ariChc < 1 || ariChc > 5) {
            cout << "\tInvalid location!\n";
            goto arriv;
        }
    }
    //checks if duplicate
    else
    {
        cout << "\tDuplicate location!\n";
        goto arriv;
    }
    //lets you pick departure date
    flightUser[1] = flightNm[ariChc - 1];
    cout << setw(5);
    
    int b = 0;
    
    cout << endl << setw(5);
    while (b < 110) {
        cout << "~";
        b++;
    }
    cout << endl << setw(5);
enterMonthNum:
    cout << "\tEnter the Month Number (1,2,3,4,5,...) : ";
    cin >> monthPicker;

    //mos. with 30 days
    if (monthPicker == 4 || monthPicker == 6 || monthPicker == 11 || monthPicker == 9)
    {
        //enter dates from 1 to 30
        do
        {
            cout << "\tEnter Preferred Date: ";
            cin >> datePicker;
        } while (datePicker > 30 || datePicker < 1);
    }
    //february no leap year
    else if (monthPicker == 2)
    {
        //enter dates from 1 to 28
        do
        {
            cout << "\tEnter Preferred Date: ";
            cin >> datePicker;
        } while (datePicker > 28 || datePicker < 1);
    }
    //months with 31 days
    else if (monthPicker == 1 || monthPicker == 3 || monthPicker == 5 || monthPicker == 7 || monthPicker == 8 || monthPicker == 10 || monthPicker == 12)
    {
        //enter dates from 1 to 31
        do
        {
            cout << "\tEnter Preferred Date: ";
            cin >> datePicker;
        } while (datePicker > 31 || datePicker < 1);
    }
    //checks for invalid input
    else
    {
        cout << "\tINVALID INPUT" << endl;
        Sleep(1);
        goto enterMonthNum;
    }
    cout << setw(5);
    
    flightUser[3] = months[monthPicker - 1];
    cout << "\tYour flight will be from " << flightUser[0] << " to " << flightUser[1] << "." << endl;
    cout << "\tThe time slots are: " << endl;
    int c = 0, r;
    //outputs random time
    while (c < 5)
    {
        //checks for duplicate time
        do
        {
            r = rand() % 10;
        } while (randStore[0] == r || randStore[1] == r || randStore[2] == r || randStore[3] == r || randStore[4] == r);
        randStore[c] = r;
        cout <<"\t"<< c + 1 << ". " << flightTm[r] << endl;
        flightTmStore[c] = flightTm[r];
        c++;
    }
timeslot:
    cout << "\tEnter your time slot: ";
    cin >> timeChc;
    //checks if valid input
    if (timeChc > 5 || timeChc < 1) {
        cout << "\tInvalid time slot!\n";
        goto timeslot;
    }
    flightUser[2] = flightTmStore[timeChc - 1];
    int i = 0;
    c = 0;
    //loops seat selection based on number of passengers entered
    cout << setw(5);
    int a = 0;

    cout <<endl<< setw(5);
    while (a < 110) {
        cout << "~";
        a++;
    }
    cout << endl << setw(5);
    for (counter = 1; counter <= passengerNum; counter++)
    {
    seatChc:
        cout << endl << "\tThe available seats left are: " << seatNo << ". \n\tPlease enter your seat: ";
        cin >> seat;
        //checks for invalid seat
        if (seat > seatNo || seat <= 0) {
            cout << "\tInvalid seat!" << endl;
            goto seatChc;
        }
        //loops seat input into array depending on condition
        for (i; i < passengerNum; i++) {
            //loops checking for duplicate seats
            for (int j = 0; j < passengerNum; j++) {
                //checks for seat duplication
                if (seat == numTicket[j][0]) {
                    cout << "\tSeat " << seat << " is already booked!" << endl;
                    goto seatChc;
                    break;
                }
            }
            if (seat != numTicket[i][0]) {
                numTicket[i][0] = seat;
                break;
            }
        }
        numTicket[c][1] = rand() % 999999;
        cout << "\tTicket Number: " << numTicket[c][1] << endl;
        cout << "\tSeat # " << numTicket[i][0] << endl;
        seatNo -= 1;
        i++;
        c++;
        cin.ignore();
    }
    system("pause");
    Class();

}

void Class() {
    viewTix = true;
    int classes, i = 0;
    float price = 0, Payment;
    char checking;
    //user chooses a seat class then proceed to payment
    int a = 0;
    cout << endl << setw(5);
    int b = 0;
    while (b < 110) {
        cout << "~";
        b++;
    }
    cout << endl << setw(5);
    do {
    Class:
        cout << "\tPlease pick a seat class (Price included):" << endl;
        cout << "\t1. Economy Class: 300$" << endl;
        cout << "\t2. Business Class: 700$" << endl;
        cout << "\t3. First Class: 1200$" << endl;
        cout << "\tChoice: ";
        cin >> classes;
        switch (classes) {
            case 1: {
                cout << "\tAre you sure about that? [Y/N]: ";
                cin >> checking;
                if (checking == 'Y' || checking == 'y')
                {
                    cout << "\tYou Have Chosen Economy Class!" << endl;
                    price = 300;

                }
                else if (checking == 'N' || checking == 'n') {
                    goto Class;
                }
                break;
            }

            case 2: {
                cout << "\tAre you sure about that? [Y/N]: ";
                cin >> checking;
                if (checking == 'Y' || checking == 'y')
                {
                    cout << "\tYou Have Chosen Business Class" << endl;
                    price = 700;

                }
                else if (checking == 'N' || checking == 'n') {
                    goto Class;
                }
                break;
            }

            case 3: {
                cout << "\tAre you sure about that? [Y/N]: ";
                cin >> checking;
                if (checking == 'Y' || checking == 'y')
                {
                    cout << "\tYou Have Chosen First Class" << endl;
                    price = 1200;

                }
                else if (checking == 'N' || checking == 'n') {
                    goto Class;
                }
                break;
            }

            default: {
                cout << "\tInvalid Input" << endl;
                Sleep(2000);
                break;
            }
        }
    } while (classes > 3 || classes < 1);
    //computes for price based on seats
    price = price * passengerNum;
    cout << "\tYour total ticket price is " << price;
    //loops payment input if not enough
    do {
        cout << endl << "\tEnter your payment: " ;
        cin >> Payment;
    } while (Payment < price);

    cout << "Processing Receipt";
    while (i < 3) {
        cout << " . ";
        i++;
        Sleep(1000);
    }
    system("cls");

    cout <<"Welcome to BIG BIG MJ MACA's Flight Receipt!" << setw(39) << "\n";
    cout << "----------------------------------------" << endl;
   
    //outputs the receipt
    cout << "Total number of passengers: " << setw(12) << passengerNum << endl;
    cout << "Order Total:" << setw(28) << price << endl;
    cout << "Amount Tendered:" << setw(24) << Payment << endl;
    cout << "----------------------------------------" << endl;
    cout << "Change:" << setw(33) << Payment - price << endl;

    logOut();

}

void popFlight()
{
    int i, cNm, cNm2, cTm;
    cout << setw(80) << "Today's most popular flights are:" << endl;
    //lists random flight arrival & destination, along with random time
    for (i = 0; i < 3; i++) {
        cNm = rand() % 5;
        cTm = rand() % 10;
        cout << setw(32) << i + 1 << ". " << flightNm[cNm] << " to ";
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
    system("cls");
    payclass = true;
selectseat:
    int viewChc, ticketNo, seatNo;
    cout << "\tHow would you like to view your ticket?:" << endl << "[1] By Ticket No." << endl << "[2] By Seat No." << endl << "[3] All Tickets" << endl << "Choice: ";
    cin >> viewChc;
    //checks for user input
    if (viewChc == 1) {
    ticketChc:
        cout << "\tPlease enter the ticket no.: ";
        cin >> ticketNo;
        int i = 0;
        //loops while inputted tickets are below passengerNum
        /*while (i <= passengerNum)
        {
           */ //loops ticket output based on number of passengers entered
            for (int b = 0; b <= passengerNum; b++)
            {
                //checks if inputted ticket is valid
                if (ticketNo == numTicket[b][1])
                {
                    cout << "Ticket Number: " << numTicket[b][1] << endl;
                    cout << "Seat #" << numTicket[b][0] << endl;
                    cout << "Destination: " << flightUser[0] << " to " << flightUser[1] << endl;
                    cout << "Departure Date: " << flightUser[3] << " " << datePicker << endl;
                    cout << "Time Slot: " << flightUser[2] << endl;
                    break;
                }
            }
            char in;
            cout << "\tSearch Ticket again? [Y/N]: ";
            cin >> in;
            if (in == 'Y' || in == 'y')
            {
                goto ticketChc;
            }
            else logOut();
            /*i++;
        }*/
    }
    else if (viewChc == 2) {
    seatChc:
        cout << "\tPlease enter the seat no.: ";
        cin >> seatNo;
        int i = 0;
        while (i <= passengerNum)
        {
            for (int b = 0; b <= passengerNum; b++)
            {
                if (seatNo == numTicket[b][0])
                {
                    cout << "\tTicket Number: " << numTicket[b][1] << endl;
                    cout << "\tSeat #" << numTicket[b][0] << endl;
                    cout << "\tDestination: " << flightUser[0] << " to " << flightUser[1] << endl;
                    cout << "\tDeparture Date: " << flightUser[3] << " " << datePicker << endl;
                    cout << "\tTime Slot: " << flightUser[2] << endl;
                    i++;
                    break;
                }
                
            }
            char in;
            cout << "\tSearch Ticket again? [Y/N]: ";
            cin >> in;
            if (in == 'Y' || in == 'y')
            {
                goto seatChc;
            }
            else logOut();
            i++;
        }

    }
    else if (viewChc == 3) {
        system("cls");
        for (int i = 0; i < passengerNum; i++) {
            cout << "\tTicket " << i + 1 << endl;
            cout << "\tTicket Number: " << numTicket[i][1] << endl;
            cout << "\tSeat #" << numTicket[i][0] << endl;
            cout << "\tDestination: " << flightUser[0] << " to " << flightUser[1] << endl;
            cout << "\tDeparture Date: " << flightUser[3] << " " << datePicker << endl;
            cout << "\tTime Slot: " << flightUser[2] << endl << endl;

        }
        logOut();
    }
    else
    {
        cout << "\tInvalid Input!";
        Sleep(1000);
        system("cls");
        goto selectseat;
    }
}




