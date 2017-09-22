#include "operationFunctions.h"




void operationFunctions::addition(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
  undoStack.push(temp);
  output+=temp.operandTwo;
}

void operationFunctions::subtraction(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{  
}

void operationFunctions::multiplication(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
}

void operationFunctions::division(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
}

void operationFunctions::modulo(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
}

void operationFunctions::undo(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
}

void operationFunctions::redo(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
}

void operationFunctions::clear(int& output, const calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack)
{
}