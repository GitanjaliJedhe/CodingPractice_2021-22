#include <iostream>
#include <vector>

using namespace std;

class Item
{
	public:
		static int m_constructorCalledCount;
		static int m_destructorCalledCount;
		static int m_copyConstructorCalledCount;
		Item() {
			m_constructorCalledCount++;
		}

		Item(const Item & obj) {
			m_copyConstructorCalledCount++;
		}

		~Item() {
			m_destructorCalledCount++;
		}
};

int Item::m_constructorCalledCount = 0;
int Item::m_copyConstructorCalledCount = 0;
int Item::m_destructorCalledCount = 0;

class ItemFactory {
	public:
		static vector<Item> getItemObjects(int count) {
			vector<Item> vecOfItem;
			vecOfItem.reserve(count);

			for(int i = 0; i < count; i++) {
				vecOfItem.push_back(Item());
			}
			return vecOfItem;
		}
};

class ItemFactoryImproved {
	public:
		static void getItemObjects_1(vector<Item> &vecItems, int count) {
			vecItems.assign(count, Item());
		}

		static vector<Item> getItemObjects_2(int count) {
			vector<Item> vecOfItems;
			vecOfItems.assign(count, Item());
			return vecOfItems;
		}
};

int main()
{
	int count = 10000;

	vector<Item> vecOfItem;
	vecOfItem = ItemFactory::getItemObjects(count);

	cout<<"Total Item Objects constructed "<<(Item::m_constructorCalledCount + Item::m_copyConstructorCalledCount)<<endl;
	cout<<"Constructor called "<<Item::m_constructorCalledCount<<endl;
	cout<<"Copy Constructor called "<<Item::m_copyConstructorCalledCount<<endl;
	cout<<"Total Item Objects destructed "<<Item::m_destructorCalledCount<<endl;
	cout<<endl;

	Item::m_constructorCalledCount = 0;
	Item::m_copyConstructorCalledCount = 0;
	Item::m_destructorCalledCount = 0;

	vector<Item> vecOfItem_2; 
	ItemFactoryImproved::getItemObjects_1(vecOfItem_2, count);

	cout<<"Total Item Objects constructed "<<(Item::m_constructorCalledCount + Item::m_copyConstructorCalledCount)<<endl;
	cout<<"Constructor called "<<Item::m_constructorCalledCount<<endl;
	cout<<"Copy Constructor called "<<Item::m_copyConstructorCalledCount<<endl;
	cout<<"Total Item Objects destructed "<<Item::m_destructorCalledCount<<endl;
	cout<<endl;

	Item::m_constructorCalledCount = 0;
	Item::m_copyConstructorCalledCount = 0;
	Item::m_destructorCalledCount = 0;

	vector<Item> vecOfItem_3 = ItemFactoryImproved::getItemObjects_2(count);

	cout<<"Total Item Objects constructed "<<(Item::m_constructorCalledCount + Item::m_copyConstructorCalledCount)<<endl;
	cout<<"Constructor called "<<Item::m_constructorCalledCount<<endl;
	cout<<"Copy Constructor called "<<Item::m_copyConstructorCalledCount<<endl;
	cout<<"Total Item Objects destructed "<<Item::m_destructorCalledCount<<endl;

	exit(0);
}
