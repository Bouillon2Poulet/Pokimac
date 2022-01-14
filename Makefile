pokimac: main.o menu.o intro.o map.o pokemon.o
	g++ -o $@ build/main.o build/menu.o build/intro.o build/map.o build/pokemon.o

%.o: %.cpp %.h
	g++ -o build/$@ -c $< -Wall
