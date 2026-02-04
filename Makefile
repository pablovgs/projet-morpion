# Nom du programme
NAME = morpion_exe

# La règle principale
all:
	g++ -std=c++17 -Iinclude src/*.cpp -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o

# Pour tout effacer et recommencer
clean:
	rm -f $(NAME) *.o