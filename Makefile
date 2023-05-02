main: main.o game.o cellGrid.o cell.o
	$(CXX) main.o game.o cellGrid.o cell.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	$(CXX) -c main.cpp

game.o: game.cpp
	$(CXX) -c game.cpp

cellGrid.o: cellGrid.cpp	
	$(CXX) -c cellGrid.cpp

cell.o: cell.cpp	
	$(CXX) -c cell.cpp

distclean: 
	rm -f *.o
	rm -f game

run:
	./game

new: distclean main.o main run
	