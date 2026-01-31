# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Nom de l'exécutable
EXEC = morpion_exe

# Liste des fichiers sources (tout ce qui est dans src/)
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Règle principale
all: $(EXEC)

# Création de l'exécutable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Compilation des fichiers .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers temporaires
clean:
	rm -rf src/*.o $(EXEC)

# Tout nettoyer et recommencer
re: clean all