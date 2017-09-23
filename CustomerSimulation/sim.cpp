#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	
	int x = 0;
	//for when customer arrivers
	int customer = 1;
	//for when custoemr leaves
	int customerL =1;
	int size = 0;
	int maxSize = 0;
	int maxWait = 0;
	int wait = 0; 
	
	//prearrival-customer waiting to arrive
	int pa = 0;
	//being currently serviced- value is the time the customer will be done and can leave
	int bcs = 0;
	//Stil needs ques made*****************
	//que for customers who have arrived but arent being serviced
	//que line
	//que for the time a customer arrives, once the customer starts being serviced current time and this will be used to determine wait time
	//que time
	
	cout<<Please enter a value for X ";
	cin>>x;
	//this for loop simulates a 12 hour shift where each i increment is 1 minute
	for(int i=1;i<720;i++){
		//if customer arrives
		if(pa=i){
			cout<<"Customer "<<customer<<" arrived at "<<i<<endl;
			customer++;
			//check if line que and being currently served is empty
			if(size=0 && bcs=0){
				//sill needs random number of range 1 to x ***********
				bcs = RandomNum + i;
				pa = RandomNum + i;
			}
			else{
				//someone else is already being serviced,wait in line,Then schdule next customer
				//sill needs random number of range 1 to x ***********
				line.add(Randomnum);
				//add the current time so when customer finishes line you can compare time and get wait time
				time.add(i);
				size++;
				pa= RandomNum+i;	
			}
		
		
		}
		//if current customer is done being serviced
		if(bcs=i){
			cout<<"Customer "<<customerL<<" left at "<<i<<endl;
			customerL++;
			//this if statment checks to make sure that there is a customer wwaiting in line
			if(size>0){
				bcs = line.remove+i;
				size--;
				wait = i-time.remove;
			}
		
		}
		//checks the size of the line once a minute
		if(size>maxSize){
			maxSize = size;
		}
		//checks the wait time against the max
		if(wait>maxWait){
			maxWait wait;
		}
		//reseting these values
		wait=0;
		size=0;
	}
	cout<<"The longest the line was at any minute during the simulation was "<<maxSize<<" Customers."<<endl;
	cout<<"The longest an indivudal customer waited in line was "<<maxWait<<" minutes"<<endl; 
}
