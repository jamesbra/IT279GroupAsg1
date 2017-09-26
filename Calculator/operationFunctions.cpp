#include "operationFunctions.h"




void operationFunctions::addition(int& output,calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  if(temp.help !=true)
  {
    temp.operandOne = output;
    output+=temp.operandTwo;
    temp.result=output;
    undoStack.push(temp);
    redoStack.clear();
  }
  else
  {
    std::cout<<"\nThe \"+\" operation adds two numbers together.\n"
	     <<"It does this by adding the number on the console\n"
	     <<"to the number you (the user) input. e.g\n"
	     <<"10\n"
	     <<">+5\n"
	     <<"15\n"
	     <<"The number in the console \"10\" was added to\n"
	     <<"the number you (the user) inputted \"5\"\n"
	     <<"to get the result 10 + 5 = 15.\n\n";
  }
}

void operationFunctions::subtraction(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{  
  if(temp.help !=true)
  {
    temp.operandOne = output;
    output-=temp.operandTwo;
    temp.result=output;
    undoStack.push(temp);
    redoStack.clear();
  }
  else
  {
    std::cout<<"\nThe \"-\" operation subtracts two numbers.\n"
	     <<"It does this by subtracting the number on the console\n"
	     <<"by the number you (the user) input. e.g\n"
	     <<"10\n"
	     <<">-5\n"
	     <<"5\n"
	     <<"The number in the console \"10\" was subtracted\n"
	     <<"by the number you (the user) inputted \"5\"\n"
	     <<"to get the result 10 - 5 = 5.\n\n";
  }
}

void operationFunctions::multiplication(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  if(temp.help != true)
  {
    temp.operandOne = output;
    output=output*temp.operandTwo;
    temp.result=output;
    undoStack.push(temp);
    redoStack.clear();
  }
  else
  {
    std::cout<<"\nThe \"*\" operation multiplies two numbers together.\n"
	     <<"It does this by multiplying the number on the console\n"
	     <<"by the number you (the user) input. e.g\n"
	     <<"10\n"
	     <<">*5\n"
	     <<"50\n"
	     <<"The number in the console \"10\" was multiplied\n"
	     <<"by the number you (the user) inputted \"5\"\n"
	     <<"to get the result 10 * 5 = 50.\n\n";
  }
}

void operationFunctions::division(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  if(temp.help != true)
  {
    temp.operandOne = output;
    output=output/temp.operandTwo;
    temp.result=output;
    undoStack.push(temp);
    redoStack.clear();
  }
  else
  {
    std::cout<<"\nThe \"\\\" operation divides two numbers.\n"
	     <<"It does this by dividing the number on the console\n"
	     <<"by the number you (the user) input. e.g\n"
	     <<"10\n"
	     <<">/5\n"
	     <<"2\n"
	     <<"The number in the console \"10\" was divided\n"
	     <<"by the number you (the user) inputted \"5\"\n"
	     <<"to get the result 10 / 5 = 2.\n\n";
  }
}

void operationFunctions::modulo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{ 
  if(temp.help != true)
  {
    temp.operandOne = output;
    output=output%temp.operandTwo;
    temp.result=output;
    undoStack.push(temp);
    redoStack.clear();
  }
  else
  {
    std::cout<<"\nThe \"%\" operation modulizes two numbers.\n"
	     <<"It does this by modulizing the number on the console\n"
	     <<"by the number you (the user) input. e.g\n"
	     <<"10\n"
	     <<">%5\n"
	     <<"2\n"
	     <<"The number in the console \"10\" was modulized\n"
	     <<"by the number you (the user) inputted \"5\"\n"
	     <<"to get the result 10 / 5 = 2.\n\n";
  }
}

void operationFunctions::undo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  if(temp.help != true)
  {
    if(undoStack.getSize()!=0)
    {
      output=undoStack.peek().operandOne;
      redoStack.push(undoStack.pop());

    }
    else
    {
      std::cout<<"Nothing to Undo\n";
    }
  }
  else
  {
    std::cout<<"\nThe undo operation will take you back one operation\n"
	     <<"and reset the console to the value it was before the\n"
	     <<"last operation made\n\n";
  }
}

void operationFunctions::redo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  if(temp.help != true)
  {
    if(redoStack.getSize() !=0)
    {
      output=redoStack.peek().result;
      //std::cout<<"Size of redostack - pre redo pop" << redoStack.getSize() <<std::endl;
      //std::cout<<"Size of undostack - pre redo pop" << undoStack.getSize() <<std::endl;
      //calcNode temp2 = redoStack.pop();
      undoStack.push(redoStack.pop());
      //std::cout<<"Size of redostack - post redo pop" << redoStack.getSize() <<std::endl;
      //std::cout<<"Size of undostack - post redo pop" << undoStack.getSize() <<std::endl;
    }
    else
    {
      std::cout<<"Nothing to Redo\n";
    }
  }
  else
  {
    std::cout<<"\nThe redo function undos the what was undone.\n"
	     <<"if you use any of the standard operands or clear\n"
	     <<"it will reset the redo operations and there will\n"
	     <<"be nothing to redo\n\n";
  }
}

void operationFunctions::clear(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  if(temp.help !=true)
  {
    temp.operandOne = output;
    output=0;
    temp.result=output;
    undoStack.push(temp);
    redoStack.clear();
  }
  else
  {
    std::cout<<"\nThe Clear functions sets the current value of the\n"
	     <<"consle to zero. This can be undone\n\n";
  }
  
}