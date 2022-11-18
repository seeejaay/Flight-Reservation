//Flight Reservation System
#include <iostream>
#include <string.h>
#include <string>
//Login Page
//




using namespace std;

string userName, passWord;

void menu();
void signUp();
int main()
{
    menu();
    cout << "test";
    return 0;
}

void menu()
{
    //menuRepeat:
    int n;
    cout << "[1] Login" << endl << "[2] Sign Up" << endl << "[3] Log Out" << endl << "[4] Exit" << endl << "Choice: ";
    cin >> n;
    cin.ignore();
    switch (n)
    {
    menuRepeat:
    case 1:
        //logIn();
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
    string uName, pWord, pWordRepeat;


    cout << "Enter your Username: ";
   getline(cin, uName);
    cout << "Enter Password: ";
   getline(cin, pWord);
    do {
        cout << "Ente Password Again: ";
        getline(cin, pWordRepeat);

    } while (pWord != pWordRepeat);


    cout << "You have Succesfully Signed Up!";
    return menu();

}

