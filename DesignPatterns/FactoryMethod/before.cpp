// A design without factory pattern
#include <iostream>

class Vehicle
{
	public:
		virtual void printVehicle() = 0;
};

class TwoWheeler : public Vehicle
{
	public:
		void printVehicle();
};

void TwoWheeler::printVehicle()
{
	std::cout<<"Two Wheeler"<<std::endl;
}

class FourWheeler : public Vehicle
{
	public:
		void printVehicle();
};

void FourWheeler::printVehicle()
{
	std::cout<<"Four Wheeler"<<std::endl;
}

class Client
{
	public:
		Client(int type);
		Vehicle* getVehicle();
		~Client();

	private:
		Vehicle *pVehicle;
};

Client::Client(int type)
{
	if(type == 1)
	{
		pVehicle = new TwoWheeler();
	}else if(type == 2)
	{
		pVehicle = new FourWheeler();
	}
	else
	{
		pVehicle = nullptr;
	}
}

Vehicle* Client::getVehicle()
{
	return pVehicle;
}

Client::~Client()
{
	delete[] pVehicle;
	pVehicle = nullptr;
}

int main()
{
	Client *pClient = new Client(1);
	Vehicle *pVehicle = pClient -> getVehicle();
	pVehicle -> printVehicle();
		
	return 0;
}

/*Output:
Two Wheeler
*/
