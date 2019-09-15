#include<iostream>
#include<fstream>
#include<string>
using namespace std;



int hashFunction(string str)
{  
int keyLength=str.size();
unsigned long sum = 0;
int seed=71;

for (int j = 0; j < keyLength; j++)
{   
	sum = (sum*seed)+ static_cast<int>(str[j]);
}

return (sum % 15991);
} 

struct datatype
{
	string data;
	datatype *pnext;
};
class linklist
{
	datatype *phead;
 
public:
	linklist()
	{
		phead=NULL;
	}
	
	void addnode(string str)
	{   
		datatype *temp= new datatype;
		temp->data=str;
		temp->pnext=NULL;
		if(phead==NULL)
		{
			phead=temp;
		}
		else
		{
			temp->pnext=phead;
			phead=temp;
		}
	}
 
	void search(string strx)
	{
		datatype *temp ;
		temp=phead;
		int y=0;
		while(temp!=NULL)
		{   
			if(temp->data==strx)
			  y=1;
			temp=temp->pnext;
		}
		if(!y)
			cout<<"word not in dic: "<<strx<<endl;
	}

	bool empty()
	{
		if(phead==NULL)
			return true;
		else
			return false;
	}
};

int main()
{
	ifstream fin;
	string str;
	linklist arr[15991];
	int i;
	int collision=0;
	

	fin.open("wordlist.txt");
		if(!fin)
			cout<<"Failed to open file "<<endl;
		else
		{
			while(fin>>str)
			{   
				i=hashFunction(str);
				arr[i].addnode(str);
			}
		}
	fin.close();

	int x=0,y=0;
	for(int j=0;j<15991;j++)
	{
		if(arr[j].empty())
              x++;
		else
			y++;
	}
   //cout<<"empty array slots: "<<x<<endl;
     cout<<"Nonempty array slots: "<<y<<endl;
	 cout<<endl;

	string str1;
	cout<<"Enter the string "<<endl;
	getline(cin,str1);
    
	string temp;
	for(int k=0;k<str1.size();k++)
	{
		if(str1[k]!=' ')
		{
			temp=temp+str1[k];
		}
		else if(str1[k]==' ')
		{
			i=hashFunction(temp);
			arr[i].search(temp);
			temp.clear();
		}
	}
	i=hashFunction(temp);
	arr[i].search(temp);

}