//Example: Logger

#include <iostream>

using namespace std;

class Singleton
{
	private:
		int m_value;
		static Singleton *s_instance;
		Singleton(int v = 0)
		{
			m_value = v;
		}
			
	public:
		void set_value(int v)
		{
			m_value = v;
		}

		int get_value()
		{
			return m_value;
		}

		static Singleton* instance()
		{
			if(s_instance == NULL)
				s_instance = new Singleton();
			return s_instance;
		}
};

Singleton * Singleton::s_instance = NULL;

void Example_1()
{
	Singleton::instance()->set_value(897);

	cout<<"Example_1: global_ptr is "<<Singleton::instance()->get_value()<<endl;
}

void Example_2()
{
	Singleton::instance()->set_value(465);

	cout<<"Example_2: global_ptr is "<<Singleton::instance()->get_value()<<endl;
}

int main()
{
	cout<<"main: global_ptr is "<<Singleton::instance()->get_value()<<endl;
	Example_1();
	Example_2();
	return 0;
}


/*Output:
main: global_ptr is 0
Example_1: global_ptr is 897
Example_2: global_ptr is 465
*/
