#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct person
{
	string first_name;
	string last_name;
	string company_name;
	string city;
	string phone;
	string email;
	person * left;
	person * right;
 };
 class BST
 {
	 person * root;
 public:
	 BST()
	 {
		 root=NULL;
	 }

     void addnode(person node)
	 {   person * nodeptr; 
		 person * newnode= new person;
	      newnode->first_name=node.first_name;
		  newnode->last_name=node.last_name;
		  newnode->company_name=node.company_name;
		  newnode->city=node.city;
		  newnode->phone=node.phone;
		  newnode->email=node.email;
		  newnode->left=NULL;
		  newnode->right=NULL;


		 if(root==NULL)
			 root=newnode;
		 else
		 {   
			 nodeptr=root;
		    while(nodeptr!=NULL)
			{
               if(newnode->email > nodeptr->email)//go right
			   {   
				   if(nodeptr->right==NULL)
					  { 
						  nodeptr->right=newnode;
						  break;
				       }
				   else
					   nodeptr=nodeptr->right;

			   }
			   else
			   if(newnode->email < nodeptr->email)
			   {
				   if(nodeptr->left==NULL)
				   {
					   nodeptr->left=newnode;
					   break;
				   }
				   else
					   nodeptr=nodeptr->left;  
			   }
			   else 
				   cout<<"duplicate value found."<<endl;

		    }
			 
		 }
	 }

	 void searchbymail(string mail)
	 {
		 person * tempptr=root;
         int y=1;
		while(tempptr!=NULL)
		{
		   if(mail > tempptr->email)
			 tempptr=tempptr->right;
		   else 
		   if(mail < tempptr->email)
			 tempptr=tempptr->left;
		   else
		   {
			   cout<<"found "<<endl;
			   cout<<tempptr->first_name<<"   "<<tempptr->last_name<<"   "<<tempptr->company_name<<"   "<<tempptr->city<<"   "<<tempptr->phone<<"   "<<tempptr->email<<endl;
		       y=0;
			   break;
		   }

		}
		if(y)
			cout<<"not found"<<endl;
	 }

	 void ss(person * nodeptr,string str)
	 {
		 if(nodeptr)
		 {
			 ss(nodeptr->left,str);
			 if(str==nodeptr->city)
			 { 
		      cout<<nodeptr->first_name<<" "<<nodeptr->last_name<<" "<<nodeptr->company_name<<" "<<nodeptr->city<<" "<<nodeptr->phone<<" "<<nodeptr->email<<endl;
			  cout<<endl;
			 }
			 ss(nodeptr->right,str);
		 }
	 }
	 void searchbycity(string city)
	 {
		 ss(root,city);
	 }
 };

person createnode(string str)
{
	string tempfname,templname,tempcompname,tempcity,tempphone,tempemail;
	int i=0;
	person tempnode;
	int size=str.size();

	while(str[i]!='\t')
	{	
		tempfname=tempfname+str[i];
		i++;
	}
	i++;

	while(str[i]!='\t')
	{	
		templname=templname+str[i];
		i++;
	}
	i++;

	while(str[i]!='\t')
	{	
		tempcompname=tempcompname+str[i];
		i++;
	}
	i++;

	while(str[i]!='\t')
	{	
		tempcity=tempcity+str[i];
		i++;
	}
	i++;

	while(str[i]!='\t')
	{	
		tempphone=tempphone+str[i];
		i++;
	}
	i++;

	for(int j=i;j<size;j++)
	{	
		tempemail=tempemail+str[j];
		 
	}
	

	tempnode.first_name=tempfname;
	tempnode.last_name=templname;
	tempnode.company_name=tempcompname;
	tempnode.city=tempcity;
	tempnode.phone=tempphone;
	tempnode.email=tempemail;
	tempnode.left=NULL;
	tempnode.right=NULL;
	return tempnode;
}
int main()
{   
	ifstream fin;
	string str,fname,lname,cname,city,phone,email;
	person pnode;
	BST objbst;

	fin.open("Assig04-person-data.txt");

	while(getline(fin,str))
	{
		pnode=createnode(str);
		
		objbst.addnode(pnode);

	}

	fin.close();

	int n;
	string str1;
	string str2;
	cout<<"Press 1 to search by email or 2 search by city."<<endl;
	cin>>n;
	cin.ignore();
	switch(n)
	{	case 1 :	
			cout<<"Enter email to search in the tree"<<endl;
	        cin>>str1;
	        objbst.searchbymail(str1);
			break;
		case 2 :
			cout<<"Enter city name to search."<<endl;
		    
			getline(cin,str2);
			objbst.searchbycity(str2);
			break;
		default:
			cout<<"you entered wrong number program is terminating."<<endl;
	 }
	
	
}