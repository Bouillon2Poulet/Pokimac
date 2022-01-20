pokimac: main.o initialisation.o menu.o intro.o map.o pokemon.o combat.o
	g++ -o $@ build/main.o build/initialisation.o build/menu.o build/intro.o build/map.o build/pokemon.o build/combat.o

%.o: %.cpp %.h
	g++ -o build/$@ -c $< -Wall
