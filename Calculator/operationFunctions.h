#include "stack.cpp"
#include "calcNode.cpp"


class operationfucntions
{
  public:
    
    static void addition(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void subtraction(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void multiplication(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void division(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void modulo(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void undo(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void redo(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void clear(const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
};
