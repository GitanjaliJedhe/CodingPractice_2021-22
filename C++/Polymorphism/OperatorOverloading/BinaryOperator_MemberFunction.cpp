#include <iostream>

using namespace std;

class Distance
{
	private:
		int feet, inch;
	public:
		Distance(int f = 0, int i = 0)
		{
			feet = f;
			inch = i;
		}
		
		Distance operator +(Distance d2)
		{
			Distance d3;

			d3.feet = this->feet + d2.feet;
			d3.inch = this->inch + d2.inch;

			return d3;
		}
		
		void Display()
		{
			cout<<"Feet & Inches "<<feet<<"'"<<inch<<endl;
		}	
};

int main()
{
	Distance d1(8, 9), d2(10, 2), d3;
	d3 = d1 + d2;
	d3.Display();
	exit(0);
}

/*Output:-)
Feet & Inches 18'11
*/
