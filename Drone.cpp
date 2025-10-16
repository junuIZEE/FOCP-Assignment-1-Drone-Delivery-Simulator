//Working code for the Drone simulator, v1.0
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main()
{
    int BATTERY = 100;
    cout << "Press enter to start deliveries\n";
    cin.get();
    srand(time(0));
    int SuccesfulDeliveries = 0;
    for (int a = 1; a <= 3; a++)
    {
        cout << "Delivery #" << a << ": \n";
        int R_weather = rand() % 3 + 1;  // 1=Sunny, 2=Windy, 3=Rainy
        int R_obstacle = rand() % 2 + 1; // 1=claer, 2=obstacle
        int R_batteryusage = rand() % 16 + 10;
        int R_Malfunction = rand() % 10;
        int R_Wait = rand() % 500;

        for (int b = 0; b <= 10; b++)
        {
            Sleep(R_Wait);
            cout << "...";
        }
        cout << endl;

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
            SuccesfulDeliveries += 1;
            BATTERY -= R_batteryusage;
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
            SuccesfulDeliveries += 1;
            BATTERY -= R_batteryusage;
            cout << "Battery Remaining: " << BATTERY << "%" << endl;
        }

        cout << endl;
    }

    int SCORE = BATTERY / 2 + SuccesfulDeliveries * 20;
    int Starcount;
   
    if (SCORE >= 80)
    {
        Starcount = 5;
    }
    if (SCORE >= 60 && SCORE <= 80)
    {
        Starcount = 4;
    }
    if (SCORE >= 40 && SCORE <= 60)
    {
        Starcount = 3;
    }
    if (SCORE >= 20 && SCORE <= 40)
    {
        Starcount = 2;
    }
    if (SCORE >= 0 && SCORE <= 20)
    {
        Starcount = 1;
    }

    cout << "Performance Rating: ";
    for (int d = 1; d <= Starcount; d++)
    {
        cout << " * ";
    }

    return 0;
}
