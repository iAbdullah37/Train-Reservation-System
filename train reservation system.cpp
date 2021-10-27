#include <bits/stdc++.h>
using namespace std;


// 23 october 2018
// Hello World ^_^
// this is my first program i coded in my studying journey at computer science 

// structure of the program
struct seat {
	int number;
	bool statue;
};

struct car {
	int id;
	int num_seats;
	seat seats;
};

struct train_element {
	car cars;
};
train_element t[10][30];


// functions for main menu

// function for reserve a seat
void reserve() {
	int car_id, seat_id;

	cout << "Choose the [Car id] You want to reserve your seat in from [1] to [10] \n";
	cin >> car_id;
	cout << "Choose the [seat Number] You want to reserve your seat in from [1] to [30] \n";
	cin >> seat_id;

	if (!(car_id >= 1 && car_id <= 10 && seat_id >= 1 && seat_id <= 30)) {
		cout << "Sorry invalid seat number or car id , please try again \n";
	}
	else if (t[car_id - 1][seat_id - 1].cars.seats.statue == 1) {
		cout << "Sorry this seat is already reserved and not available \n";
	}
	else {
		t[car_id - 1][seat_id - 1].cars.seats.statue = 1;
		cout << "Booking successful! , select another operation\n";
	}

}

// function for cancel reserve of a seat
void cancel_reserve() {
	int car_id, seat_id;
	cout << "Choose the [Car id] You want to cancel your reserve seat from [1] to [10] \n";
	cin >> car_id;
	cout << "Choose the [seat Number] You want to cancel your reserve seat from [1] to [30] \n";
	cin >> seat_id;
	if (!(car_id >= 1 && car_id <= 10 && seat_id >= 1 && seat_id <= 30)) {
		cout << "Sorry invalid seat number or car id , please try again  \n";
	}
	else if (t[car_id - 1][seat_id - 1].cars.seats.statue == 0) {
		cout << "Sorry but this seat is not reserved yet, please try again \n";
	}
	else {
		t[car_id - 1][seat_id - 1].cars.seats.statue = 0;
		cout << "Booking successfully canceled! , select another operation\n";
	}
}

// function to show all the seats status of a specific car
void show() {
	cout << "enter the car id that you want show all the seats status of it\n";
	int c;
	cin >> c;
	if (c >= 1 && c <= 10) {
		for (int i = 0; i < 30; i++) {
			cout << "seat [" << i + 1 << "] is " << (t[c - 1][i].cars.seats.statue ? "not available to reserve\n" : "available to reserve\n");
		}
	}
	else {
		cout << "invalid car id, please try again\n";
	}
}


// function for show the available seats in a specific car
void av() {
	cout << "enter the car id that you want show the available seats of it\n";
	int c, s = 0;
	cin >> c;
	if (c >= 1 && c <= 10) {
		for (int i = 0; i < 30; i++) {
			if (!(t[c - 1][i].cars.seats.statue))s++;
		}
		cout << "the available seats of car [" << c << "] is " << s << '\n';
	}
	else {
		cout << "invalid car id, please try again\n";
	}
}

// function to check specific seat is available or not
void specific_seat() {
	cout << "enter the car id that you want check a specific seat of it\n";
	int c, se;
	cin >> c;
	cout << "enter the seat number that you want check it\n";
	cin >> se;
	if (c >= 1 && c <= 10 && se >= 1 && se <= 30) {
		cout << (t[c - 1][se - 1].cars.seats.statue ? "Sorry this seat in not available\n" : "congrats!, this seat is available and you ca reserve it now!\n");
	}
	else {
		cout << "invalid car id or seat number, please try again\n";
	}
}

// function to check specific car has available seat or not
void av_s() {
	cout << "enter the car id that you want to check if has available seat or not\n";
	int c, s = 0;
	cin >> c;
	if (c >= 1 && c <= 10) {
		for (int i = 0; i < 30; i++) {
			if (!(t[c - 1][i].cars.seats.statue)) {
				s = 1;
				break;
			}
		}
		cout << (s ? "congrats this car have available seat\n" : "sorry this car have not any available seat\n");
	}
	else {
		cout << "invalid car id, please try again\n";
	}
}

int main()
{
	// preprocessing train data
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 30; j++) {
			// data for cars
			t[i][j].cars.id = i + 1;
			t[i][j].cars.num_seats = 30;
			// data for seats of car
			t[i][j].cars.seats.number = j + 1;
			t[i][j].cars.seats.statue = 0;
		}
	}

	// check for welcome message for only first time
	bool welcome = 1;

	while (true) {
		// welcome message
		if (welcome)
			cout << "Welcome to Assyut Train Station \n------------------------------------\n";

		//change welcome boolean to not show welcome message again after first time
		welcome = 0;

		// main menu
		cout << "Choose the Number of Operation : \n";
		cout << "1- Reserve a ticket \n";
		cout << "2- Cancel a reservation \n";
		cout << "3- Check whether a specific car has available seat or not \n";
		cout << "4- Check whether a specific seat is available or not \n";
		cout << "5- Get the number of the available seats in a specific car \n";
		cout << "6- Show all the seats status of a specific car \n";
		cout << "7- Exit.\n";

		// choices
		int choose;
		cin >> choose;
		if (choose == 1)
			reserve();
		else if (choose == 2)
			cancel_reserve();
		else if (choose == 3)
			av_s();
		else if (choose == 4)
			specific_seat();
		else if (choose == 5)
			av();
		else if (choose == 6)
			show();
		else {
			cout << "Have a good day!\n";
			break;
		}
	}
	return 0;
}