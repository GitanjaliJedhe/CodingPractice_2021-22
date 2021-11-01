// A design with factory pattern
// Create objects without exposing the creation logic to the client 

#include <iostream>

enum VehicleType 
{
	VT_TwoWheeler,
	VT_ThreeWheeler,
	VT_FourWheeler
};

class Vehicle
{
	public:
		virtual void printVehicle() = 0;
		static Vehicle* Create(VehicleType type);
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

class ThreeWheeler : public Vehicle
{
	public:
		void printVehicle();
};

void ThreeWheeler::printVehicle()
{
	std::cout<<"Three Wheeler"<<std::endl;
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

Vehicle* Vehicle::Create(VehicleType type)
{
	if(type == VT_TwoWheeler)
	{
		return new TwoWheeler();
	}
	else if(type == VT_ThreeWheeler)
	{
		return new ThreeWheeler();
	}
	else if(type == VT_FourWheeler)
	{
		return new FourWheeler();
	}
	else
	{
		return nullptr;
	}
}
class Client
{
	public:
		Client(VehicleType type);
		Vehicle* getVehicle();
		~Client();

	private:
		Vehicle *pVehicle;
};

Client::Client(VehicleType type)
{
	pVehicle = Vehicle::Create(type);
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
	Client *pClient = new Client(VT_FourWheeler);
	Vehicle *pVehicle = pClient -> getVehicle();
	pVehicle -> printVehicle();
		
	return 0;
}

/*Output:
Four Wheeler
*/
