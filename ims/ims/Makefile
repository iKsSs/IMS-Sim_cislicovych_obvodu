CC=g++
PRE=-std=c++11 

all:
	$(CC) $(PRE) main.cpp AND.cpp NAND.cpp OR.cpp NOR.cpp NOT.cpp CLKGen.cpp Connect.cpp Connections.cpp Logic.cpp LogicsTable.cpp PlotCreator.cpp Scheduler.cpp SimCore.cpp parser.cpp scanner.cpp -g -o sim

run:
	./sim dek1z4.txt > dek1z4.log 2> dek1z4.err
	./sim 2bitkom.txt > 2bitkom.log 2> 2bitkom.err
	./sim d.txt > d.log 2> d.err
	./sim test.txt > test.log 2> test.err

clean:							# smazani nezadoucich souboru
	rm -f *~ *.o sim *.dat *.plt *.log *.err

