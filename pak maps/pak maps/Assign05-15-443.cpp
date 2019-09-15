#include<iostream>
#include<string>
#include<fstream> 
using namespace std;
 

class graph
{   
	int size;
	int **arr;
	int *smallest;
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
 
	void display()
	{   ofstream fout;
		fout.open("output.txt");
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				cout<<arr[i][j]<<" ";
				fout<<arr[i][j]<<" ";
			}	
			cout<<endl;
			fout<<endl;
		}
			
	}

  void dijkestra(int ve )
     { 
	    smallest=new int [size];
       for(int i=0;i <size;i++)
           smallest[i]=arr[ve][i];
    
         bool * visited = new bool [size];
     
         for(int i=0;i <size; i++)
            visited[i]=false;

             visited[ve]=true;
             smallest[ve]=0;
     
         for(int i=0; i<size-1;i++)
         {
            double min=9999;
            int v;
       
		    for(int i=0;i<size ;i++)
              if(!visited[i])
               if(smallest[i]<min)
                 { v=i;
                  min=smallest[i]; 
                 }

           visited[v]=true;

           for(int i=0;i<size;i++)
             if(!visited[i])
               if(min+arr[v][i]<smallest[i] )
                 smallest[i]=min+arr[v][i];

        } 
	   int k=0;
	   //////////////////////////////displaying shortest paths///////////////
		cout<<"/n Distance of you entered city to other cities (in km):"<<endl;
		cout<<"Islamabad     "<<smallest[k]<<endl;
		k++;
		cout<<"Rawalpindi    "<<smallest[k]<<endl;
		k++;
		cout<<"Peshawar      "<<smallest[k]<<endl;
		k++;
		cout<<"Gujranwala    "<<smallest[k]<<endl;
		k++;
		cout<<"Jehlum        "<<smallest[k]<<endl;
		k++;
		cout<<"Lahore        "<<smallest[k]<<endl;
		k++;
		cout<<"Faisalabad    "<<smallest[k]<<endl;
		k++;
		cout<<"Multan        "<<smallest[k]<<endl;
		k++;
		cout<<"DG khan       "<<smallest[k]<<endl;
		k++;
		cout<<"Quetta        "<<smallest[k]<<endl;
		k++;
		cout<<"Jacobabad     "<<smallest[k]<<endl;
		k++;
		cout<<"khanpur       "<<smallest[k]<<endl;
		k++;
		cout<<"Rahimyar khan "<<smallest[k]<<endl;
		k++;
		cout<<"Sukkur        "<<smallest[k]<<endl;
		k++;
		cout<<"Nawabshah     "<<smallest[k]<<endl;
		k++;
		cout<<"Hyderabad     "<<smallest[k]<<endl;
		k++;
		cout<<"Thatta        "<<smallest[k]<<endl;
		k++;
		cout<<"Karachi       "<<smallest[k]<<endl;
		k++;
		cout<<"Nushki        "<<smallest[k]<<endl;
		k++;
		cout<<"nok kundi     "<<smallest[k]<<endl;
		k++;
		

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

//g.display();
///////....fileclose....//////////////

cout<<"islamabad"<<endl;
cout<<"rawalpindi"<<endl;
cout<<"peshawar"<<endl;
cout<<"gujranwala"<<endl;
cout<<"jehlum"<<endl;
cout<<"lahore"<<endl;
cout<<"faisalabad"<<endl;
cout<<"multan"<<endl;
cout<<"dgkhan"<<endl;
cout<<"quetta"<<endl;
cout<<"jacobabad"<<endl;
cout<<"khanpur"<<endl;
cout<<"rahimyarkhan"<<endl;
cout<<"sukkur"<<endl;
cout<<"nawabshah"<<endl;
cout<<"hyderabad"<<endl;
cout<<"thatta"<<endl;
cout<<"karachi"<<endl;
cout<<"nushki"<<endl;
cout<<"nokkundi"<<endl;


string cityname;
cout<<"\nEnter the city name(all small letters) from which you want to search for smallest distance of all cities."<<endl;
cin>>cityname;
if(cityname=="islamabad")
	g.dijkestra(0);
else 
	if(cityname=="rawalpindi")
	g.dijkestra(1);
else
	if(cityname=="peshawar")
	g.dijkestra(2);
else
	if(cityname=="gujranwala")
	g.dijkestra(3);
else
	if(cityname=="jhelum")
	g.dijkestra(4);
else
	if(cityname=="lahore")
	g.dijkestra(5);
else
	if(cityname=="faisalabad")
	g.dijkestra(6);
else
	if(cityname=="multan")
	g.dijkestra(7);
else
	if(cityname=="dgkhan")
	g.dijkestra(8);
else
	if(cityname=="quetta")
	g.dijkestra(9);
else
	if(cityname=="jacobabad")
	g.dijkestra(10);
else
	if(cityname=="khanpur")
	g.dijkestra(11);
else
	if(cityname=="rahimyarkhan")
	g.dijkestra(12);
else
	if(cityname=="sukkur")
	g.dijkestra(13);
else
	if(cityname=="nawabshah")
	g.dijkestra(14);
else
	if(cityname=="hyderabad")
	g.dijkestra(15);
else
	if(cityname=="thatta")
	g.dijkestra(16);
else
	if(cityname=="karachi")
	g.dijkestra(17);
else
	if(cityname=="nushki")
	g.dijkestra(18);
else
	if(cityname=="nokkundi")
	g.dijkestra(19);

}

	