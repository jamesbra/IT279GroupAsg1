#ifndef CALC_INPUT
#define CALC_INPUT
#include "calcNode.cpp"
class CalculatorInput{
    
    public:
        static struct calcNode receiveInput();
    
    private:
        static struct calcNode temp;
    };
#endif