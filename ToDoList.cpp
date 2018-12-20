#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

//Global Declaration
string iToString(int a);
int taskNameID,taskCounter;

//Add specific task
void addTask(string str,string str1){
	int temp;
	string temp1;
	char name[10];
	//read how many task is there..
	ifstream count("taskCounter");
	count>>taskCounter;
	count.close();
	
	taskCounter++;
	temp = taskCounter+1000;
	temp1=iToString(temp);
	for(int j=0;j<temp1.size();j++){
		name[j]=temp1[j];
	}
	
	ofstream inputs(name,ios::out|ios::app);
	inputs<<str<<"\n";
	inputs<<str1<<"\n";
	inputs.close();
	
	//Write the task id ..
	ofstream taskNameOut("taskName",ios::out|ios::app);
	taskNameOut<<temp<<"\n";
	taskNameOut.close();

	ofstream count1("taskCounter");
	count1<<taskCounter;
	count1.close();
}

//Show all task
void showTask(){
	int temp;
	string temp1,temp2;
	char name[10];
	//read how many task is there..
	ifstream count("taskCounter");
	if(!count){
		cout<<"Problem to read the countID file\n";
	}
	count>>taskCounter;
	count.close();
	
	if(taskCounter==0){
		cout<<"ToDo is Empty\n";
		return ;
	}
	cout<<".................................................\nTasks....";

	//read task ID to read the the discription....
	ifstream taskNameIn("taskName");
	for(int i=1;i<=taskCounter;i++){
		cout<<"Task "<<i<<": \n";
		taskNameIn>>taskNameID;
		temp1=iToString(taskNameID);
		for(int j=0;j<temp1.size();j++){
			name[j]=temp1[j];
		}
		ifstream streams(name);
		getline(streams,temp2);
		cout<<temp2<<endl;
		getline(streams,temp2);
		cout<<temp2<<endl;
		cout<<endl;
	}
}

//delete specific task
void deleteTask(){
	cout<<"Upgrading processing\n";
}

//int to string convert..
string iToString(int a){
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

//main driver function...
int main(){
	int num;
	char ch;
	string description,timeAndDate;
	while(1){
		cout<<"\n\n";
		cout<<"Press number to access..\n";
		cout<<"1.Show Task\n";
		cout<<"2.Add task\n";
		cout<<"3.Delete task\n";
		cout<<"4.Quit\n";
		cin>>num;
		if(num==1){
			showTask();
		}
		else if(num==2){
			cout<<"...................................................................\n";
			cout<<"\nInter The task description in 10 Words\n";
			cin.ignore();
			getline(cin,description);
			cout<<"Inter Date And time..\n";
			cin.ignore();
			getline(cin,timeAndDate);
			addTask(description,timeAndDate);
		}
		else if(num==3){
			deleteTask();
		}
		else{
			break;
		}
	}
	
	return 0;
}