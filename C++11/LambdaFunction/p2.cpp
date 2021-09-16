#include <iostream>

using namespace std;

int main()
{
	string msg = "Git";
	int counter = 10;

	// Capturing local variables by Value
	auto func = [msg, counter]() mutable {
		cout<<"Inside Lambda::msg = "<<msg<<endl;
		cout<<"Inside Lambda::counter = "<<counter<<endl;

		msg = "Gitanjali Jedhe";
		counter = 100;

		cout<<"Inside Lambda:: After change :: msg = "<<msg<<endl;
		cout<<"Inside Lambda:: After change :: counter = "<<counter<<endl;
	};

	func();

	cout<<"msg = "<<msg<<endl;
	cout<<"counter = "<<counter<<endl;

	exit(0);
}
