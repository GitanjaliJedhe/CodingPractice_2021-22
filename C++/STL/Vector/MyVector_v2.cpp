#include "iostream"
#define ll long long

using namespace std;

template <typename T>
class MyVector
{
	private:
		T *arr;
		ll length;
		ll capacity;

	public:
		MyVector(ll n = 100) : arr(new T[n]), length(0), capacity(n)
		{
		}

		ll push_back(T data);

		T pop_back();

		ll size() const;

		T& operator [](ll index);

		class iterator
		{
			private:
			
				T *ptr;

			public:
				iterator() : ptr(nullptr)
				{
				}
				
				iterator(T *p) : ptr(p)
				{
				}
				
				bool operator ==(const iterator& rhs) const
				{
					return ptr == rhs.ptr;
				}

				bool operator !=(const iterator& rhs) const
				{
					return !(*this == rhs);
				}

				T operator *() const
				{
					return *ptr;
				}

				iterator& operator ++() // Pre-increment
				{
					++ptr;
					return *this;
				}

				iterator& operator ++(int) // Post-increment
				{
					iterator temp(ptr);
					++ptr;
					return temp;
				}
		};

		iterator begin() const;
		iterator end() const;
};

template <typename T>
ll MyVector<T>::push_back(T data)
{
	if(length == capacity)
	{
		T *old = arr;
		arr = new T[capacity = capacity * 2];
		copy(old, old+length, arr);
		delete []old;
	}

	arr[length++] = data;
	return length;
}

template <typename T>
T MyVector<T>::pop_back()
{
	return arr[length-- - 1];
}

template <typename T>
ll MyVector<T>::size() const
{
	return length;
}

template <typename T>
T& MyVector<T>::operator [](ll index)
{
	if(index > length)
	{
		cout<<"Error: Array index out of bound";
		exit(0);
	}

	return *(arr+index);
}

template <typename T>
typename MyVector<T>::iterator MyVector<T>::begin() const
{
	return iterator(arr);
}

template <typename T>
typename MyVector<T>::iterator MyVector<T>::end() const
{
	return iterator(arr+length);
}

template <typename T>
void display_vector(T &v)
{
	typename T::iterator itr;
	for(itr = v.begin(); itr != v.end(); itr++) 
	{
		cout<<*itr<<' ';
	}
	cout<<endl;
}

int main()
{
	cout<<"Integer Vector"<<endl;

	MyVector<int> int_vec;

	int_vec.push_back(11);
	int_vec.push_back(22);
	int_vec.push_back(33);
	int_vec.push_back(44);
	int_vec.push_back(55);

	cout<<"Element in Vector: ";
	display_vector(int_vec);

	MyVector<int>::iterator itr;

	cout<<"Size : "<<int_vec.size()<<endl;

	cout<<"v[2] : "<<int_vec[2]<<endl;

	cout<<"Popped Element: "<<int_vec.pop_back()<<endl;
	
	cout<<"Element in Vector: ";
	display_vector(int_vec);

	cout<<endl;

	cout<<"Char Vector"<<endl;

	MyVector<char> char_vec;

	char_vec.push_back('G');
	char_vec.push_back('I');
	char_vec.push_back('T');
	char_vec.push_back('A');
	char_vec.push_back('N');
	char_vec.push_back('J');
	char_vec.push_back('A');
	char_vec.push_back('L');
	char_vec.push_back('I');

	cout<<"Element in Vector: ";
	display_vector(char_vec);

	MyVector<char>::iterator itr_1;

	cout<<"Size : "<<char_vec.size()<<endl;

	cout<<"v[2] : "<<char_vec[2]<<endl;

	cout<<"Popped Element: "<<char_vec.pop_back()<<endl;
	
	cout<<"Element in Vector: ";
	display_vector(char_vec);

	return 0;
}


/*Output:
Integer Vector
Element in Vector: 11 22 33 44 55
Size : 5
v[2] : 33
Popped Element: 55
Element in Vector: 11 22 33 44

Char Vector
Element in Vector: G I T A N J A L I
Size : 9
v[2] : T
Popped Element: I
Element in Vector: G I T A N J A L
*/
