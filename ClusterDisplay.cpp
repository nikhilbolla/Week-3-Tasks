#include <iostream>
#include <thread>    
#include <chrono>

using namespace std;

struct VehicleData {

    int speed;
    int fuelLevel;
    int engineTemp;

    VehicleData(int s, int f, int t) : speed(s), fuelLevel(f), engineTemp(t) {}
};

class Display {


    void displayData(VehicleData data)
    {
        cout << "==============================================" << endl;
        cout << "Speed: " << data.speed << "km/h" << endl;
        cout << "Fuel: " << data.fuelLevel << "%" << endl;
        cout << "Temperature: " << data.engineTemp << " C" << endl;

        if(data.engineTemp > 100)
        {
            cout <<"The temperature of the Vehicle is high!!" << endl;
        }

        if(data.fuelLevel < 10)
        {
            cout << "Warning! Low Fuel!!" << endl;
        }

    }

    public: 

    void stimulateData()
    {
      
        int fuel = 100;
        for(int i=0; i<10; i++)
        {
        srand((unsigned)time(0)); 
        int speed, temp;
        fuel-= 5;
        speed = (rand()%230)+30;
        temp = (rand()%100)+30;
        
        VehicleData data(speed, fuel, temp);
            displayData(data);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

    }

};

int main()
{
    Display cluster;
    cluster.stimulateData();
    return 0;
}