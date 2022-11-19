#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <time.h>
using namespace std;

void FlightChc();

int main() {
	srand(time(0));
	FlightChc();
}

void FlightChc() {
	string flightNm[5] = {"Jakarta, Indonesia", "Amsterdam, Netherlands", "New York, USA", "Manila, Philippines", "Osaka, Japan" };
	string flightTm[10] = { "10:00PM - 11:00PM", "12:15AM - 2:00AM", "3:00AM - 3:45AM", "4:00AM - 5:30AM", "12:00PM - 2:15PM", "8:00AM - 9:20AM", "3:00PM - 4:45PM", "5:30PM - 7:00PM", "7:15PM - 8:50PM", "9:15PM - 9:50PM" };
	string flightUser[1][3];
	int depChc, ariChc, timeChc, seat, randStore[5];
	int seatNo = (rand() % 500) + 1;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ". " << flightNm[i] << endl;
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
	repeat:
		r = rand() % 10;
		if (randStore[0] == r || randStore[1] == r || randStore[2] == r || randStore[3] == r || randStore[4] == r) {
			goto repeat;
		}
		randStore[c] = r;
		cout << c + 1 << ". " << flightTm[r] << endl;
		c++;
	}
	timeslot:
	cout << "Enter your time slot: ";
	cin >> timeChc;
	if (timeChc > 5 || timeChc < 1) {
		cout << "Invalid time slot!";
		goto timeslot;
	}
	flightUser[0][2] = flightTm[timeChc-1];
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
	cout << "Seat # " << seat;
}