Calculator: Calculator.o CalculatorInput.o LinkedList.o ourStack.o calcNode.o operationFunctions.o 
	g++ Calculator.o CalculatorInput.o LinkedList.o ourStack.o calcNode.o operationFunctions.o  -o calc
Calculator.o: Calculator.cpp
	g++ -c Calculator.cpp
CalculatorInput.o: CalculatorInput.cpp
	g++ -std=c++11 -c CalculatorInput.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
ourStack.o: ourStack.cpp
	g++ -c ourStack.cpp
calcNode.o: calcNode.cpp
	g++ -c calcNode.cpp
operationFunctions.o: operationFunctions.cpp
	g++ -c operationFunctions.cpp
clean:
	rm *.o calc