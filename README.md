# Morpion en C++ (POO & SFML)

Projet réalisé dans le cadre du rattrapage de Programmation Orientée Objet.

## Architecture
Le projet est structuré pour respecter les principes de séparation des responsabilités :
- **Modèle de données** : Classes `Cell` et `Player` avec héritage pour illustrer le polymorphisme.
- **Logique métier** : `Grid` gère le tableau 3x3 et `GameEngine` gère les règles du jeu.
- **Interface graphique** : `GameGUI` utilise la bibliothèque SFML pour l'affichage et les entrées utilisateur.

## Spécificités techniques
- **Polymorphisme** : Utilisation de destructeurs virtuels et de classes dérivées (`HumanPlayer`, etc.) pour garantir une gestion propre de la mémoire.
- **Règles** : Conformément à l'énoncé, seules les victoires horizontales et verticales sont comptabilisées.
- **Gestion du build** : Compilation automatisée via un Makefile.

## Comment jouer ?
1. Compiler avec `make`.
2. Lancer avec `./morpion_exe`.
3. Cliquer dans les cases pour jouer.
4. Une fois la partie finie, appuyer sur **R** pour recommencer.