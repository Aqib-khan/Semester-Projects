#include<iostream>
#include<string>
#include<stack>
#include<fstream> 
using namespace std;
 

class graph
{   
	int size;
	int **arr;
	int *smallest;
	stack <int> st;
public:
	
	graph(int v)
	{   
		size = v;
		arr=new int *[size];
		for(int i=0;i<size;i++)
		{
			arr[i]=new int [size];
		}
		
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
		      arr[i][j]=99999999;
		}
	}
  
	void add(int v, int connectedto, int weight)
	{   
		arr[v][connectedto]=weight;
	}

	int encoder(string cityname)
	{
		int x;
    if(cityname=="islamabad")
	x=0;
	else 
	if(cityname=="rawalpindi")
	x=1;
	else
	if(cityname=="peshawar")
	x=2;
	else
	if(cityname=="gujranwala")
	x=3;
	else
	if(cityname=="jhelum")
	x=4;
	else
	if(cityname=="lahore")
	x=5;
	else
	if(cityname=="faisalabad")
	x=6;
	else
	if(cityname=="multan")
	x=7;
	else
	if(cityname=="dgkhan")
	x=8;
	else
	if(cityname=="quetta")
	x=9;
	else
	if(cityname=="jacobabad")
	x=10;
	else
	if(cityname=="khanpur")
	x=11;
	else
	if(cityname=="rahimyarkhan")
	x=12;
	else
	if(cityname=="sukkur")
	x=13;
	else
	if(cityname=="nawabshah")
	x=14;
	else
	if(cityname=="hyderabad")
	x=15;
	else
	if(cityname=="thatta")
	x=16;
	else
	if(cityname=="karachi")
	x=17;
	else
	if(cityname=="nushki")
	x=18;
    else
	if(cityname=="nokkundi")
	x=19;
	else
	if(cityname=="bela")
	x=20;
	else
	if(cityname=="panjgur")
	x=21;
	else
	if(cityname=="turbat")
	x=22;
	else
	if(cityname=="gawadar")
	x=23;
	else
	if(cityname=="bannu")
	x=24;
	else
	if(cityname=="mianwali")
	x=25;
	else
	if(cityname=="tank")
	x=26;
	else
	if(cityname=="zhob")
	x=27;
	else
	if(cityname=="bahawalpur")
	x=28;
	else
	if(cityname=="jiwani")
	x=29;
		
	return x ;
	}

	string decoder(int x)
	{
	string cityname;

    if(x==0)
	cityname="islamabad";
	else 
	if(x==1)
	cityname="rawalpindi";
	else
	if(x==2)
	cityname="peshawar";
	else
	if(x==3)
	cityname="gujranwala";
	else
	if(x==4)
	cityname="jhelum";
	else
	if(x==5)
	cityname="lahore";
	else
	if(x==6)
	cityname="faisalabad";
	else
	if(x==7)
	cityname="multan";
	else
	if(x==8)
	cityname="dgkhan";
	else
	if(x==9)
	cityname="quetta";
	else
	if(x==10)
	cityname="jacobabad";
	else
	if(x==11)
	cityname="khanpur";
	else
	if(x==12)
	cityname="rahimyarkhan";
	else
	if(x==13)
	cityname="sukkur";
	else
	if(x==14)
	cityname="nawabshah";
	else
	if(x==15)
	cityname="hyderabad";
	else
	if(x==16)
	cityname="thatta";
	else
	if(x==17)
	cityname="karachi";
	else
	if(x==18)
	cityname="nushki";
    else
	if(x==19)
	cityname="nokkundi";
	else
	if(x==20)
	cityname="bela";
	else
	if(x==21)
	cityname="panjgur";
	else
	if(x==22)
	cityname="turbat";
	else
	if(x==23)
	cityname="gawadar";
	else
	if(x==24)
	cityname="bannu";
	else
	if(x==25)
	cityname="mianwali";
	else
	if(x==26)
	cityname="tank";
	else
	if(x==27)
	cityname="zhob";
	else
	if(x==28)
	cityname="bahawalpur";
	else
	if(x==29)
	cityname="jiwani";

	return cityname;
	}

	void floyd(string city1 , string city2)
	{
		int x,y;
		x=encoder(city1);
		y=encoder(city2);
		int **D;//shortest path weight matrix
		int **P;//shortest path  matrix 
     
//////////       initializing D matrix ///////////
		D=new int *[size];
		for(int i=0;i<size;i++)
		{
			D[i]=new int [size];
		}
		
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
		      D[i][j]=arr[i][j];
		}
//////////       initializing P matrix ///////////    
        P=new int *[size];
		for(int i=0;i<size;i++)
		{
			P[i]=new int [size];
		}
		
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(i==j || D[i][j]==99999999)
					P[i][j]=-1;
				else
					P[i][j]=i;
			}
		}

 ////////////////   applying floyd algo   ////////////
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
 
				for (int k = 0; k < size; k++)
				{
				if (D[j][k] > D[j][i] + D[i][k])
				{
					D[j][k] = D[j][i] + D[i][k];
					P[j][k] = i;
				}
				}
		}
   
		
		cout << "\nshortest path from " << city1 << " to " << city2 <<" is: "<< D[x][y]<< endl;
		cout<<"Path it follows will be "<<endl;
		st.push(y);
		while(y!=x)
		{
			y=P[x][y];
			st.push(y);
		}
		while(!st.empty())
		{   
			int a=st.top();
			string str;
			str = decoder(a);
			cout<<str<<" ";
			st.pop();
		}

		cout<<"\n"<<endl;
	}
 
};
 
 
int main()
{   
	int size;
	int v;
	int connectedto;
	int weight;
    string str;
	ifstream fin ;
	
////.......file opens.////////////////////////////////////////////
	fin.open("map.txt");

	getline(fin,str);
	size=stoi(str);
    graph g(size);

	for (int index = 0; index < size ;index++)
     {
               fin >> str;
			   v=stoi(str);
               fin >> str;
			   connectedto=stoi(str);
             while (connectedto !=-999 )
               {   
				   fin>>str;
				   weight=stoi(str);
				   g.add(v,connectedto,weight);
                   fin >> str;
				   connectedto=stoi(str);
				  
               }
      }

cout<<endl;
fin.close();
///////....fileclose....//////////////


cout<<"0.islamabad"<<endl;
cout<<"1.rawalpindi"<<endl;
cout<<"2.peshawar"<<endl;
cout<<"3.gujranwala"<<endl;
cout<<"4.jehlum"<<endl;
cout<<"5.lahore"<<endl;
cout<<"6.faisalabad"<<endl;
cout<<"7.multan"<<endl;
cout<<"8.dgkhan"<<endl;
cout<<"9.quetta"<<endl;
cout<<"10.jacobabad"<<endl;
cout<<"11.khanpur"<<endl;
cout<<"12.rahimyarkhan"<<endl;
cout<<"13.sukkur"<<endl;
cout<<"14.nawabshah"<<endl;
cout<<"15.hyderabad"<<endl;
cout<<"16.thatta"<<endl;
cout<<"17.karachi"<<endl;
cout<<"18.nushki"<<endl;
cout<<"19.nokkundi"<<endl;
cout<<"20.bela"<<endl;
cout<<"21.panjgur"<<endl;
cout<<"22.turbat"<<endl;
cout<<"23.gawadar"<<endl;
cout<<"24.bannu"<<endl;
cout<<"25.mianwali"<<endl;
cout<<"26.tank"<<endl;
cout<<"27.zhob"<<endl;
cout<<"28.bahawalpur"<<endl;
cout<<"29.jiwani"<<endl;

string city1 , city2;
cout<<"Enter cities name(all short) "<<endl;
cout<<"From : ";
cin>>city1;
cout<<"\nTo : ";
cin>>city2;
cout<<endl;
g.floyd(city1,city2);


}