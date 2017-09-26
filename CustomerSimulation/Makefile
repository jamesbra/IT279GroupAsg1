sim: sim.o ourQueue.o LinkedList.o
	g++ sim.o ourQueue.o LinkedList.o -o LineSimulation
sim.o: sim.cpp
	g++ -std=c++11 -c sim.cpp
ourQueue.o: ourQueue.cpp
	g++ -c ourQueue.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
clean:
	rm *.o LineSimulation