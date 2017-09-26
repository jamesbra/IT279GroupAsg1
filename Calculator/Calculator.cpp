#include <iostream>
#include "CalculatorInput.h"
#include "ourStack.cpp"
#include "calcNode.cpp"
#include "operationFunctions.h"

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
    int currentValue =0;
    ourStack<calcNode> redoStack;
    ourStack<calcNode> undoStack;
    calcNode temp;
    temp.operation = '+';
    temp.operandOne = 0;
    temp.operandTwo = 0;
    temp.help = false;
    cout<<"\n"<<currentValue<<endl;
    temp = CalculatorInput::receiveInput();
    //above gets the first input from the user then the while loop handels the rest
    while(temp.operation!='Q')
    {
      //switch statement to deal with all the different operations
      //all of the functions for the operations must pass by reference three things
      //1: the stack "redoStack"
      //2: the stack "undoStack"
      //3: the calNode "temp"
      //4: the int "currentValue"
      //this can be changed if for a function we realize we don't need one of these
     switch(temp.operation)
     {
       case '+':
	      //call function to deal with +
	      operationFunctions::addition(currentValue,temp,undoStack,redoStack);
	      break;
	 
       case '-':
	      //call function to deal with -
	 operationFunctions::subtraction(currentValue,temp,undoStack,redoStack);
	      break;
	 
       case '*':
	      //call function to deal with *
	 operationFunctions::multiplication(currentValue,temp,undoStack,redoStack);
	      break;
	 
       case '/':
	      //call function to deal with /
	 operationFunctions::division(currentValue,temp,undoStack,redoStack);
	      break;
	 
       case '%':
	      //call function to deal with %
	 operationFunctions::modulo(currentValue,temp,undoStack,redoStack);
	      break;
	 
       case 'U':
	      //call function to deal with U
	 operationFunctions::undo(currentValue,temp,undoStack,redoStack);
	      break;
	 
       case 'R':
	      //call function to deal with R
	 operationFunctions::redo(currentValue,temp,undoStack,redoStack);
	      break;
       case 'C':
	      //call function to deal with C
	 operationFunctions::clear(currentValue,temp,undoStack,redoStack);
	    break;
       default:
	  cout<<"Not a valid input"<<endl;
     }
     cout<<currentValue<<endl;
     //cout<<"Top of Undo Stack: "<<undoStack.peek().operandOne<<endl;
     //cout<<"Top of Redo Stack: "<<redoStack.peek().result<<endl;
     //after dealling with current temp calcNode, get a new one
     temp = CalculatorInput::receiveInput();
    }
  return 0;
};