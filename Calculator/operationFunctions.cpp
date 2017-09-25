#include "operationFunctions.h"




void operationFunctions::addition(int& output,calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  temp.operandOne = output;
  output+=temp.operandTwo;
  temp.result=output;
  undoStack.push(temp);
  redoStack.clear();
}

void operationFunctions::subtraction(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{  
  temp.operandOne = output;
  output-=temp.operandTwo;
  temp.result=output;
  undoStack.push(temp);
  redoStack.clear();
}

void operationFunctions::multiplication(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  temp.operandOne = output;
  output=output*temp.operandTwo;
  temp.result=output;
  undoStack.push(temp);
  redoStack.clear();
}

void operationFunctions::division(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  temp.operandOne = output;
  output=output/temp.operandTwo;
  temp.result=output;
  undoStack.push(temp);
  redoStack.clear();
}

void operationFunctions::modulo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  temp.operandOne = output;
  output=output%temp.operandTwo;
  temp.result=output;
  undoStack.push(temp);
  redoStack.clear();
}

void operationFunctions::undo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
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

void operationFunctions::redo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  if(redoStack.getSize() !=0)
  {
    output=redoStack.peek().result;
    undoStack.push(redoStack.pop());
  }
  else
  {
    std::cout<<"Nothing to Redo\n";
  }
}

void operationFunctions::clear(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  temp.operandOne = output;
  output=0;
  temp.result=output;
  undoStack.push(temp);
  redoStack.clear();
}