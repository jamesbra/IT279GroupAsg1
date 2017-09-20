#include <iostream>
#include "stack.cpp"
#include "calcNode.cpp"

using namespace std;

int main()
{
  //calculator instructions
cout<<"This is a standard integer calculator. It it provides the following functions for users: \n\n"
    <<"+: Adding two integers\n"
    <<"-: Subtracting two integers\n"
    <<"*: Multiplying two integers\n"
    <<"/: Dividing two integers (answer will result in a new integer)\n"
    <<"%: Modulo of a number\n"
    <<"U: Undo\n"
    <<"R: Redo\n"
    <<"C: Clear\n"
    <<"Q: Leave program\n";
cout<<"\nThe calculator starts off as zero. From there you perform operations on the number in the consol\n"
    <<"when prompet by the greater than sign: \">\"."<<endl; 
cout<<"There is a help feature, if you don't know how to use an operation type in a question mark\n"
    <<"then the operation to get an explanation of the operation (e.g. ?*,?%,?-,?R)\n";
    calcNode temp;
    temp.operation = '0';
    temp.operandOne = 0;
    temp.operandTwo = 0;
    temp.help = false;
    //temp = getInput();
    //above gets the first input from the user then the while loop handels the rest
    while(temp.operation!='Q')
    {
      //switch statement to deal with all the different operations
     switch(temp.operation)
     {
       case '+':
	 //call function to deal with +
	 break;
	 
       case '-':
	 //call function to deal with -
	 break;
	 
       case '*':
	 //call function to deal with *
	 break;
	 
       case '/':
	 //call function to deal with /
	 break;
	 
       case '%':
	 //call function to deal with %
	 break;
	 
	case 'U':
	  //call function to deal with U
	 break;
	 
	case 'R':
	  //call function to deal with R
	 break;
	 
	case 'C':
	  //call function to deal with C
	 break;
     }
     
     //after dealling with current temp calcNode, get a new one
     //temp = getInput();
    }
  return 0;
};