// Working code for the Drone simulator, v2.0

// Headers
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;


// Definitions
#define DOTS 30 // How many times to print ...'s
#define WAIT 1200 // Wait between deliveries
#define START "Press ENTER to start deliveries\n"
#define FIVESTAR 80
#define FOURSTAR 60
#define THREESTAR 40
#define TWOSTAR 20


// Prototype
int random(int range, int base);			// Returns a random int from 1 to (inclusive) range, with base added on top.
void loading(int repetitions, int wait);	// Prints dots to show a dynamic delay. (Purely UI)
int get_starCount(int score);				// Returns a star count to show how successful the delivery was.
void display_performance(int stars);			// Looks Pretty (^_^) 


// Main
int main()
{

	// Init
	int BATTERY = 100;

	// Waits for the user to press enter.
	{
		cout << START;
		cin.get();
		srand(time(0));
	}

	// Start
	int successfulDeliveries = 0;
	for (int a = 1; a <= 3; a++)
	{
		cout << "Delivery #" << a << ": \n";

		// Gets random conditions
		int R_weather = random(3, 1);		// 1 = Sunny, 2 = Windy, 3 = Rainy
		int R_obstacle = random(2, 1);		// 1 = Clear, 2 = Obstacle
		int R_batteryUsage = random(16, 10);
		int R_Malfunction = random(10, 0);
		int R_Wait = random(100, 10);

		loading(DOTS, R_Wait); // For UI

		cout << endl;

		// What to do under certain conditions
		if (R_weather == 3)
		{
			cout << "FLIGHT DELAYED because of rain\n";
		}
		else if (R_weather == 2 && BATTERY < 40)
		{
			cout << "Battery Remaining: " << BATTERY << "%" << endl;
			cout << "Returning to base for a quick recharge!\n";
			BATTERY += 10;
			a -= 1;
		}
		else if (R_obstacle == 2)
		{
			cout << "OBSTACLE DETECTED.....rerouting......\n";
			BATTERY -= 5;
			cout << "DELIVERY SUCCESSFUL!\n";
			successfulDeliveries += 1;
			BATTERY -= R_batteryUsage;
			cout << "Battery Remaining: " << BATTERY << "%" << endl;
		}
		else if (R_Malfunction == 1)
		{
			cout << "ERROR-致命的なエラーが発生しました。システムを再起動してください\n";
			cout << "Delivery Failed\n";
		}
		else // Kachow
		{
			cout << "DELIVERY SUCCESSFUL!\n";
			successfulDeliveries += 1;
			BATTERY -= R_batteryUsage;
			cout << "Battery Remaining: " << BATTERY << "%" << endl;
		}

		Sleep(WAIT);

		cout << endl;
	}

	int SCORE = BATTERY / 2 + successfulDeliveries * 20;
	int starCount;

	starCount = get_starCount(SCORE);

	display_performance(starCount);

	cout << endl;
	system("pause");
	return 0;
}

// Helpers
int random(int range = 1, int base = 0) {
	return rand() % range + base;
}

void loading(int repetitions, int wait) {
	for (int b = 1; b <= repetitions; b++)
	{
		Sleep(wait);
		cout << ".";
	}
}

int get_starCount(int SCORE) {
	if (SCORE >= FIVESTAR)
	{
		return 5;
	}
	else if (SCORE >= FOURSTAR)
	{
		return 4;
	}
	else if (SCORE >= THREESTAR)
	{
		return 3;
	}
	else if (SCORE >= TWOSTAR)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

void display_performance(int stars) {

	cout << "Performance Rating: ";
	for (int d = 1; d <= stars; d++)
	{
		cout << " * ";
	}
}