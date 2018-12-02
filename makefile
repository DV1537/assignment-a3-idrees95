a.exe: A2.cpp  Triangle.cpp Polygon.cpp Point.cpp Line.cpp Shape.cpp
	g++ -g Shape.cpp Triangle.cpp Polygon.cpp Point.cpp Line.cpp A2.cpp -o a.exe -std=c++17 -Wall -pedantic-errors

test.o: A2.cpp
	g++ -g -c Main.cpp -o Main.o -std=c++17 -Wall -pedantic-errors

Shape.o: A2.cpp
	g++ -g -c Shape.cpp -o Shape.o -std=c++17 -Wall -pedantic-errors

Triangle.o: A2.cpp
	g++ -g -c Triangle.cpp -o Triangle.o -std=c++17 -Wall -pedantic-errors

Polygon.o: A2.cpp
	g++ -g -c Polygon.cpp -o Polygon.o -std=c++17 -Wall -pedantic-errors

Point.o: A2.cpp
	g++ -g -c Point.cpp -o Point.o -std=c++17 -Wall -pedantic-errors

Line.o: A2.cpp
	g++ -g -c Line.cpp -o Line.o -std=c++17 -Wall -pedantic-errors

assembly: A2.cpp
	g++ -S -masm=intel -fverbose-asm -03 A2.cpp

clean:
	del a.exe A2.s A2.o 
	