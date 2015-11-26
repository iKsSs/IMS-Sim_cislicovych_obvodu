CC=g++
PRE=-std=c++11 

all:
	$(CC) $(PRE) main.cpp AND.cpp NAND.cpp OR.cpp NOR.cpp NOT.cpp CLKGen.cpp Connect.cpp Connections.cpp Logic.cpp LogicsTable.cpp PlotCreator.cpp Scheduler.cpp SimCore.cpp parser.cpp scanner.cpp -o sim

run:
	./sim test.txt

clean:							# smazani nezadoucich souboru
	rm -f *~ *.o sim *.dat *.plt

