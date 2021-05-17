#include <iostream>
#include <string>
#include <functional> 

using namespace std;

function<void()> getCallBack()
{
	int counter = 10;
	auto func = [&counter]() mutable {
		cout<<"Inside Lambda::counter = "<<counter<<endl;
		counter = 20;
		cout<<"Inside Lambda::After changing::counter = "<<counter<<endl;
	};
	return func;
}

int main()
{
	function<void()> func = getCallBack();

	func();

	exit(0);
}
