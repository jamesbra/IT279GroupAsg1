#ifndef operationFunctions_H
#define operationFunctions_H

#include "ourStack.cpp"
#include "calcNode.cpp"
#include <iostream>


class operationFunctions
{
  public:
    static void addition(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
    static void subtraction(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
    static void multiplication(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
    static void division(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
    static void modulo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
    static void undo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
    static void redo(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
    static void clear(int& output,  calcNode& temp,ourStack<calcNode>& undoStack,ourStack<calcNode>& redoStack);
};


#endif