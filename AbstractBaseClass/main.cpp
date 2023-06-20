#include <iostream>
using namespace std;

class Vehicle
{
	int speed;
	const int MAX_SPEED;
public:
	Vehicle(int speed)
	{

	}
	virtual void move() = 0;	//Pure-virtual function - чисто виртуальная функция
};

class GroundVehicle: public Vehicle{};
class Car:public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина ездит на колесах" << endl;
	}
};
class Buldozer : public GroundVehicle
{
public:
	void move()
	{
		cout << "Бульдозер ездит на гусеницах" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	//Vehicle transport;	//Can not instantiate Abstract class
	//GroundVehicle gv;
	Car car;
	car.move();

	Buldozer amd;
	amd.move();
}