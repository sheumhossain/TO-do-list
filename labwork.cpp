#include <iostream>
#include <string>
#include<fstream>
using namespace std;


int positionInList = 0;
int listSize = 0;
struct list
{
	string name;
   string description;
   string Date;
};
struct list data[100];



bool Add_in_file(string name,string description, string Date)
{
	
   if (listSize < 101)
   {
      list y = { name,description, Date };
      data[listSize] = y;
      listSize++;
      return true;
   }
   else
   {
      return false;
   }
}


void Show_file()
{
	ofstream file_open("To_Do_list.txt",ios::app);
   for (int i = 0; i < listSize; i++)
   {
   	  file_open<<data[i].name<<endl;
   	  file_open<<data[i].description<<endl;
   	  file_open<<data[i].Date<<endl;
   	  file_open<<"\n"<<endl;
   	  cout<<"Name : "<<data[i].name<<endl;
      cout <<"Description : "<<data[i].description << endl;
      cout <<"Date : "<< data[i].Date << endl;
      cout << "" << endl;
   }
}
void Delete(int x)
{
	ofstream file_open("To_Do_list.txt",ios::app);
	file_open<<"Delete "<<x+1<<" positionInList "<<endl;
	for(int i=0;i<listSize;i++)
	{
		if(x<i)
		{
			data[i-1].name=data[i].name;
			data[i-1].description=data[i].description;
			data[i-1].Date=data[i].Date;
		}
	}
	listSize-=1;

}

int main()
{
   int choice = 0;
   while (1)
   {
      cout << "Enter you choice " << endl;
      cout << "1. add information" << endl;
      cout << "2. show information" << endl;
      cout << "3. Delete information"<<endl;
      cout << "4. exit"<<endl;
      cin >> choice;

      if (choice == 1)
      {
      	 string name;
         string description;
         string Date;
         cin.ignore();
         cout<<"Entr your name : ";
         getline(cin,name);
         cout << "Enter your discription : " << endl;
         getline(cin, description);
         cout << "Enter date :" << endl;
         cin >> Date;
         Add_in_file(name,description, Date);
      }
      else if (choice == 2)  Show_file();
      else if(choice == 3)  
      	{
      		cout<<"Enter which list you want Delete : ";
      		int y;
      		cin>>y;
      		Delete(y-1);
      	}
      else if(choice==4) return 0;
   }
   
   return 0;
}
