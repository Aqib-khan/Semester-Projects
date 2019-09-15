#include <iostream>
#include <string>

using namespace std;
// point of sale program
//this program assumes items are sold one at a time.

enum itemtype
{
	FROZEN,
	JUNK_FOOD,
	PLASTIC,
	METAL
};

struct struct_grocery_item
{
	string name;
	string barcode;
	float price;
	int type;
	struct_grocery_item *next;
};

struct_grocery_item g_list[1000];
int g_iCount = 0; //g to signify this is a global variable

void DisplayMenu()
{
	cout << "Welcome: Choose from following actions!\n";
	cout << "a: add item\n";
	cout << "s: sell item\n";
	cout << "e: exit\n";
	cout << "Currently there are " << g_iCount << " items in store\n";
}

char GetChoice()
{
	char choice;
	cin >> choice;
	return choice;
}

void get_type(int &ty)
{
	cout << "type: ";
	cout << "choose from:\n0 = FROZEN\n1 = JUNK_FOOD\n2 = PLASTIC, 3 = METAL\n";
	cin >> ty;
}

int AddItem(struct_grocery_item &it)
{
	if(g_iCount != 0)
		g_list[g_iCount-1].next = &it;
	
	cout << "name: "; cin >> it.name;
	cout << "barcode: "; cin >> it.barcode;
	cout << "price: "; cin >> it.price;
	get_type(it.type);

	g_iCount++;

	return 0;
}

void SellItem()
{
	//sells one item
	cout << "Enter barcode of item to be sold\n";
	string code;
	cin >> code;

	for(int i = 0; i < g_iCount; i++)
	{
		if(code.compare(g_list[i].barcode) == 0) //match
		{
			for(int j = i; j < g_iCount-1; j++) //move back next in list by one position
				g_list[j] = g_list[j+1];

			g_iCount--;
			break;
		}
	}
}

void main(void)
{
	g_iCount = 0;

	while(1)
	{
		DisplayMenu();
		switch(GetChoice())
		{
		case 'a':
			AddItem(g_list[g_iCount]);
			break;
		case 's':
			SellItem();
			break;
		case 'e':
			exit(0);
		default:
			break;
		}
	}
}
