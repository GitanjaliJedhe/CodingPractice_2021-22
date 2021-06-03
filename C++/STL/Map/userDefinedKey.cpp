// User defined class objects as key in std::map

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Student
{
	private:
		int m_rollNum;
		string m_name;

	public:
		Student(int rno, string name) : m_rollNum(rno), m_name(name)
		{
		}

		const int& getRollNum() const
		{
			return m_rollNum;
		}

		const string& getName() const
		{
			return m_name;
		}

		bool operator < (const Student &sObj) const
		{
			if(sObj.m_rollNum < this->m_rollNum)
			{
				return true;
			}
		}
};

void example_1()
{
	map<Student, char> StudentInfo;

	StudentInfo.insert(make_pair<Student, char>(Student(1, "Gitanjali"), 'A'));
	StudentInfo.insert(make_pair<Student, char>(Student(2, "Snehal"), 'B'));
	StudentInfo.insert(make_pair<Student, char>(Student(3, "Gitanjali"), 'C'));

	map<Student, char>::iterator itr = StudentInfo.begin();
	while(itr != StudentInfo.end())
	{
		cout<<itr->first.getName()<<" :: "<<itr->second<<endl;
		itr++;
	}
}

struct StudentNameComparator
{
	bool operator() (const Student &left, const Student &right) const
	{
		return (left.getName() > right.getName());
	}
};

void example_2()
{
	map<Student, char, StudentNameComparator> StudentInfo;

	StudentInfo.insert(make_pair<Student, char>(Student(1, "Gitanjali"), 'A'));
	StudentInfo.insert(make_pair<Student, char>(Student(2, "Snehal"), 'B'));
	StudentInfo.insert(make_pair<Student, char>(Student(3, "Gitanjali"), 'C'));

	map<Student, char, StudentNameComparator>::iterator itr = StudentInfo.begin();
	while(itr != StudentInfo.end())
	{
		cout<<itr->first.getName()<<" :: "<<itr->second<<endl;
		itr++;
	}
}

int main()
{
	cout<<"Example 1:: Comparing by ID"<<endl;
	example_1();

	cout<<"\nExample 2:: Comparing by Name"<<endl;
	example_2();

	return 0;
}

/*Output:
Example 1:: Comparing by ID
Gitanjali :: C
Snehal :: B
Gitanjali :: A

Example 2:: Comparing by Name
Snehal :: B
Gitanjali :: A
*/
