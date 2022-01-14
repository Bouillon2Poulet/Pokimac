pokimac: main.o map.o pokemon.o
	g++ -o $@ build/main.o build/map.o build/pokemon.o

%.o: %.cpp %.h
	g++ -o build/$@ -c $< -Wall
