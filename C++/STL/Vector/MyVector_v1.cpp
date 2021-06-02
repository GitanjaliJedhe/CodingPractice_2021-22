// Self implementation of the Vector class in C++

#include <iostream>

using namespace std;

template <typename T>
class MyVector
{
	private:
		//int *arr;
		T *arr;
		int size;
		int capacity;

	public:
		// Default Constructor
		/*Initial capacity of 1 element and 
		 *allocating storage using dynamic allocation*/
		MyVector()
		{
			//arr = new int[1];
			arr = new T[1];
			size = 0;
			capacity = 1;
		}

		//void push(int data)
		void push(T data)
		{
			// If number of elements is equal to capacity. We need to double the capacity
			if(size == capacity)
			{
				//int *temp = new int[2 * capacity];
				T *temp = new T[2 * capacity];

				// Copying old array elements into new array 
				for(int i = 0; i < size; i++)
				{
					temp[i] = arr[i];
				}

				// Delete previous array
				delete []arr;
				capacity = capacity * 2;
				arr = temp;
			}

			// Inserting data
			arr[size] = data;
			size++;
		}

		//void push(int data, int index)
		void push(T data, int index)
		{
			// If index is equal to capacity then 
			// this function is same as push defined above
			if(index == capacity)
			{
				push(data);
			}
			else
			{
				arr[index] = data;
			}
		}

		// Function to delete last element
		void pop()
		{
			size--;
		}

		//int get(int index)
		T get(int index)
		{
			if(index < size) 
			{
				return arr[index];
			}
		}

		int getsize()
		{
			return size;
		}

		int getcapacity()
		{
			return capacity;
		}

		void print()
		{
			for(int i = 0; i < size; i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main()
{
	MyVector<int> vec;

	vec.push(10);
	vec.push(20);
	vec.push(30);
	vec.push(40);
	vec.push(50);

	cout<<"Vector elements: ";
	vec.print();

	vec.pop();
	vec.push(80, 3);

	cout<<"Vector elements: ";
	vec.print();

	cout<<"Element at 3rd index: "<<vec.get(3)<<endl;

	cout<<"Vector size: "<<vec.getsize()<<endl;
	cout<<"Vector capacity: "<<vec.getcapacity()<<endl;

	MyVector<char> vec1;

	vec1.push('J');
	vec1.push('E');
	vec1.push('D');
	vec1.push('H');
	vec1.push('E');

	cout<<"Vector elements: ";
	vec1.print();

	vec1.pop();
	vec1.push('E', 2);

	cout<<"Vector elements: ";
	vec1.print();

	cout<<"Element at 3rd index: "<<vec1.get(0)<<endl;

	cout<<"Vector size: "<<vec1.getsize()<<endl;
	cout<<"Vector capacity: "<<vec1.getcapacity()<<endl;

	return 0;
}

/*Output:
Vector elements: 10 20 30 40 50
Vector elements: 10 20 30 80
Element at 3rd index: 80
Vector size: 4
Vector capacity: 8
Vector elements: J E D H E
Vector elements: J E E H
Element at 3rd index: J
Vector size: 4
Vector capacity: 8
*/
