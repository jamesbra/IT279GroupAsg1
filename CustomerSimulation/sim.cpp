#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <regex>
#include <cstring>
#include <iomanip>
#include "ourQueue.cpp"
using namespace std;

int main(){
	
	
	regex userInput("[1-9]+");
	smatch m;
	int x = 0;
	string input = "";
	//for when customer arrivers
	int customer = 1;
	//for when customer leaves
	int customerL =1;
	int size = 0;
	int maxSize = 0;
	int maxWait = 0;
	int wait = 0; 
	srand(time(NULL));
	
	//prearrival- customer waiting to arrive
	int pa = 0;
	//being currently serviced- value is the time the customer will be done and can leave
	int bcs = -1;
	//que for customers who have arrived but arent being serviced
	ourQueue<int> line;
	//que for the time a customer arrives, once the customer starts being serviced current time and this will be used to determine wait time
	ourQueue<int> time;
	
	//user input for the range of random numbers
	while (!regex_match(input,m,userInput) || input=="0"){
		cout<<"Please enter a value for X ";
		getline(cin,input);
	}
	x = stoi(input.c_str());
	//setting up first customer to arrive
	pa = rand()%x+1;
	//this for loop simulates a 12 hour shift where each i increment is 1 minute
	for(int i=1; i<720; i++){
		//if customer arrives
		if(pa==i){
			cout<<"Customer "<<setw(3)<<customer<<setw(17)<<" arrival time: "<<setw(3)<<i<<" minutes"<<endl;
			customer++;
			//check if line que and being currently served is empty
			if(size == 0 && bcs == -1){
				bcs = (rand()%x+1) + i;
				pa = (rand()%x+1) + i;
			}
			else{
				//someone else is already being serviced,wait in line,Then schdule next customer
				line.enqueue(rand()%x + 1);
				//add the current time so when customer finishes waiting in line you can compare the times and get wait time
				time.enqueue(i);
				size++;
				pa = (rand()%x + 1) + i;	
			}
		
		
		}
		//if current customer is done being serviced
		if(bcs == i){
			cout<<"Customer "<<setw(3)<<customerL<<setw(12)<<" departure time: "<<setw(3)<<i<<" minutes"<<endl;
			customerL++;
			//this if statment checks to make sure that there is a customer waiting in line
			if(size > 0){
				bcs = line.dequeue()+i;
				size--;
				wait = i-time.dequeue();
			}
			else{
				bcs=-1;
			}

		}
		
		//checks the size of the line once a minute
		if(size > maxSize){
			maxSize = size;
		}
		//checks the wait time against the max
		if(wait > maxWait){
			maxWait = wait;
		}
		//reseting these values
		wait = 0;
	}
	cout<<"At its longest, the line was "<<maxSize<<" Customers long."<<endl;
	cout<<"The longest an individual customer waited in line was "<<maxWait<<" minutes."<<endl; 
	return 0;
}
