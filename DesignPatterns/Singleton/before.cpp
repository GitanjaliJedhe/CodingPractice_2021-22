// Before 

#include <iostream>

using namespace std;

class Example
{
	private:
		int m_value;
	public:
		Example(int v = 0)
		{
			m_value =  v;
		}

		void set_value(int v)
		{
			m_value = v;
		}

		int get_value()
		{
			return m_value;
		}
};

// Default Initialization
Example *global_ptr = NULL;

void test_1(void)
{
	if(global_ptr == NULL)
		global_ptr = new Example();

	global_ptr -> set_value(876);
	cout<<"test_1: global_ptr is "<<global_ptr -> get_value()<<endl;
}

void test_2(void)
{
	if(global_ptr == NULL)
		global_ptr = new Example();

	global_ptr -> set_value(465);
	cout<<"test_1: global_ptr is "<<global_ptr -> get_value()<<endl;
}

int main() 
{
	if(global_ptr == NULL)
		global_ptr = new Example();

	cout<<"main: global_ptr is "<<global_ptr -> get_value()<<endl;

	test_1();
	test_2();

	return 0;
}

/*Output:
main: global_ptr is 0
test_1: global_ptr is 876
test_1: global_ptr is 465
*/
