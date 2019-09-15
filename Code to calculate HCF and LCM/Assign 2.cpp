//This program take two integer as a input from user and calculates it's LCM and HCF.
#include<iostream>
using namespace std;
int main()

{
	int a,b,lcm,m,hcf,d;  //declairing variable.

	cout<<"Enter any two integer to calculate thier LCM and HCF."<<endl; 
	cin>>a>>b;    //taking input from user 
	 
	while (a<=0 || b<=0 )                     //while loop to ask for re-enter 
		{cout<<"Invalid entry"<<endl;         //integer if it is zero or negative integer.
	     cout<<endl;
	     cout<<"Enter again"<<endl;	
		 cin>>a>>b;	}

	cout<<endl;

	if (a>b)                        //if first entered integer is greator then next entered
     { lcm=a;                       //this 'if' and 'while' loop will calculate LCM.
	   m=1;
		while(lcm%b!=0)
		{m=m+1;
		lcm=a*m;}
		cout<<"LCM ="<<lcm<<endl; }
		
	else                          //if first entered integer is less than or equal to next entered
	{lcm=b;                       //this 'if' and 'while' loop will calculate LCM.
	 m=1;
	 while(lcm%a!=0)
	 {m=m+1;
	 lcm=b*m;}
	 cout<<"LCM ="<<lcm<<endl;}


	if(a>b)                    //if first entered integer is greator then next entered    
	{ hcf=b;                   //this 'if' and 'while' loop will calculate LCM.
	  d=2;
	  while(a%hcf!=0 ||b%hcf!=0)
	  {hcf=b/d;
	  d=d+1;}
	  cout<<"HCF ="<<hcf<<endl;}

	else                    //if first entered integer is less than or equal to next entered
	{hcf=a;                 //this 'if' and 'while' loop will calculate LCM.
	 d=2;
	 while(a%hcf!=0 ||b%hcf!=0)
	 {hcf=a/d;
	 d=d+1;}
	 cout<<"HCF ="<<hcf<<endl;}

}