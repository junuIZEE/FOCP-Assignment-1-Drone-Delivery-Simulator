// Working code for the Drone simulator, v4

// Headers
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Definitions
#define DOTS 40 // How many times to print ...'s
#define DOT_WAIT 50
#define WAIT 1200 // Wait between deliveries
#define RAINY 3
#define WINDY 2
#define SUNNY 1
#define START "Press ENTER to start deliveries\n"
#define TOWARDS "Headed towards: "
#define ANOTHERTOWARDS "Headed towards another area within: "
#define HEAVY 25
#define FIVESTAR 80
#define FOURSTAR 60
#define THREESTAR 40
#define TWOSTAR 20

const string Locations[5] = { "H-12", "F-8", "F-6", "G-11", "H-13" };

// Prototypes
void display_performance(int, int, int, int, int, int);	// Looks Pretty (^_^) 
int get_starCount(int score);							// Returns a star count to show how successful the delivery was.
void loading(int repetitions, int wait);				// Prints dots to show a dynamic delay. (Purely UI)
bool obstacleExists();
int random(int range, int base);						// Returns a random int from 1 to (inclusive) range, with base added on top.
void start_day();
void show_battery(int battery);

// Global variables, so that the code can be modular
static int BATTERY = 100;
static int delayed = 0;
static int delivery = 1;
static int failed = 0;
static string lastLocation = "";
static int successfulDeliveries = 0;
static int lastWeather = 0;

// Main
int main() {

	// Waits for the user to press enter.
	{
		cout << START;
		cin.get();
		srand(time(0));
	}

	// Start
	for (;delivery <= 3; delivery++) {
		start_day();
	}

	int SCORE = BATTERY / 2 + successfulDeliveries * 20 - (10 * delayed) - (20 * failed);
	int starCount = get_starCount(SCORE);

	display_performance(starCount, 3, successfulDeliveries, failed, delayed, BATTERY);
	cout << endl;

	system("pause");

	return 0;
}

// Helpers
void display_performance(int stars, int total_deliveries, int successful, int failed, int delayed, int battery) {

	cout << endl;
	cout << "Performance Rating: ";

	// The pauses in the following are for added suspense
	for (int d = 1; d <= stars; d++)
	{
		if (d < 3)
			Sleep(5 * DOT_WAIT);
		else
			Sleep(800);

		cout << " * ";

	}
	if (stars != 5)
		Sleep(800);

	cout << endl;

	cout << "Details:\n";
	cout << "(1) Total: [" << total_deliveries << ']' << endl;
	cout << "(2) Successful: [" << successful << ']' << endl;
	cout << "(3) Failed: [" << failed << ']' << endl;
	cout << "(4) Delayed: [" << delayed << ']' << endl;
	cout << "(5) Battery left: [" << battery << "%]" << endl;
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

void loading(int repetitions, int wait) {
	for (int b = 1; b <= repetitions; b++)
	{
		Sleep(wait);
		cout << ".";
	}
}

bool obstacleExists() {
	int x = random(3, 1);

	if (x == 3)			// Implies a 33.33% chance
		return true;
	else
		return false;
}

int random(int range = 1, int base = 0) {
	return rand() % range + base;
}

void start_day()

{

	// Gets random conditions
	int R_weather = random(3, 1);		// 1 = Sunny, 2 = Windy, 3 = Rainy
	int R_obstacle = random(2, 1);		// 1 = Clear, 2 = Obstacle
	int R_batteryUsage = random(16, 10);
	int R_Malfunction = random(10, 0);
	int R_Wait = random(100, 10);
	int R_Weight = random(36, 0);

	string location = Locations[random(5, 0)];

	cout << "Delivery #" << delivery << ", ";
	if (R_weather != RAINY) {
		if (lastLocation == location && lastWeather != RAINY)
			cout << ANOTHERTOWARDS << location << endl;
		else
			cout << TOWARDS << location << endl;

		// Checks if the load is heavy and gives penalties in the case it is
		if (R_Weight >= HEAVY)
		{
			cout << "Heavy load!" << endl;
			R_Wait += 5;
			R_batteryUsage += 2;
		}

		loading(DOTS, R_Wait); // For UI
		cout << endl;
	}



	// What to do under certain conditions
	if (R_weather == RAINY)
	{
		cout << "FLIGHT DELAYED because of rain\n";
		delayed++;
	}
	else if (R_weather == WINDY && BATTERY < 40)
	{
		show_battery(BATTERY);
		cout << "Returning to base for a quick recharge!\n";
		BATTERY += 10;
		delivery--;
	}
	else if (obstacleExists())
	{
		cout << "OBSTACLE DETECTED.....rerouting......\n";
		BATTERY -= 6;
		cout << "DELIVERY SUCCESSFUL!\n";
		successfulDeliveries++;
		BATTERY -= R_batteryUsage;
		show_battery(BATTERY);
	}
	else if (R_Malfunction == 1)
	{
		cout << "ERROR-致命的なエラーが発生しました。システムを再起動してください\n";
		cout << "Delivery Failed\n";
		failed++;
	}
	else // Kachow
	{
		cout << "DELIVERY SUCCESSFUL!\n";
		successfulDeliveries++;
		BATTERY -= R_batteryUsage;
		show_battery(BATTERY);
	}

	Sleep(WAIT);

	cout << endl;
	lastLocation = location;
	lastWeather = R_weather;
}

void show_battery(int battery) {
	cout << "Battery Remaining: " << battery << "%" << endl;
}