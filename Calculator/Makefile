Calculator: Calculator.o CalculatorInput.o LinkedList.o stack.o calcNode.o
	g++ Calculator.o CalculatorInput.o LinkedList.o stack.o calcNode.o -o main
Calculator.o: Calculator.cpp
	g++ -c Calculator.cpp
CalculatorInput.o: CalculatorInput.cpp
	g++ -c CalculatorInput.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
stack.o: stack.cpp
	g++ -c stack.cpp
calcNode.o: calcNode.cpp
	g++ -c calcNode.cpp
clean:
	rm *.o main