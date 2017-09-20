#include "stack.cpp"
#include "calcNode.cpp"


class operationFunctions
{
  public:
    static void addition(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void subtraction(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void multiplication(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void division(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void modulo(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void undo(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void redo(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
    static void clear(int& output, const calcNode& temp,stack<calcNode>& undoStack,stack<calcNode>& redoStack);
};
