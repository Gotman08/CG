# CityGenerator

Un générateur de grille de ville simple en C++20 qui crée des matrices aléatoires représentant des rues et des maisons.

## Description

Ce projet génère une grille n×n représentant une carte de ville où chaque cellule peut être:
- **0** : Une rue (Street)
- **1** : Une maison (Home)

La grille est remplie de manière aléatoire et affichée dans la console.

## Prérequis

- **Visual Studio 2022** (ou plus récent) avec support C++20
- **Windows 10/11** (pour les fichiers de projet Visual Studio)
- Compilateur compatible C++20

## Structure du projet

```
CG/
├── CityGenerator.h              # Déclaration de la classe CityGenerator
├── CityGenerator.cpp            # Implémentation de la classe
├── CityMain.cpp                 # Point d'entrée principal
├── CityGenerator.vcxproj        # Fichier de projet Visual Studio
├── CityGenerator.vcxproj.filters # Organisation des fichiers dans l'IDE
├── CityGenerator.sln            # Solution Visual Studio
└── README.md                    # Documentation
```

## Compilation et exécution

### Avec Visual Studio

1. Ouvrez le fichier `CityGenerator.sln` dans Visual Studio
2. Sélectionnez la configuration (Debug ou Release)
3. Appuyez sur `F5` pour compiler et exécuter
4. Ou utilisez le menu `Build > Build Solution` puis `Debug > Start Without Debugging`

### Avec MSBuild (ligne de commande)

```bash
msbuild CityGenerator.sln /p:Configuration=Release /p:Platform=x64
```

Puis exécutez:
```bash
.\x64\Release\CityGenerator.exe
```

## Exemple de sortie

```
[ 0, 1, 0, 1 ]
[ 1, 1, 0, 0 ]
[ 0, 0, 1, 1 ]
[ 1, 0, 1, 0 ]
```

## Architecture technique

### Classe CityGenerator

**Constantes:**
- `Street = 0` : Représente une rue
- `Home = 1` : Représente une maison

**Membres privés:**
- `std::vector<std::vector<int>> City` : Grille 2D de la ville
- `std::mt19937 randomGenerator` : Générateur de nombres aléatoires
- `std::uniform_int_distribution<int> distribution` : Distribution uniforme [0,1]

**Méthodes publiques:**
- `CityGenerator(int n)` : Constructeur créant une grille n×n
- `void remplire()` : Remplit la grille avec des valeurs aléatoires
- `const std::vector<std::vector<int>>& getCity() const` : Retourne la grille

**Méthodes privées:**
- `void GenerateCity()` : Génération avancée de ville (en développement)
- `bool verification(...)` : Vérifie les cellules voisines (en développement)

### Fonction principale

**CityMain.cpp** contient:
- `void afficher(const vector<vector<int>>& t)` : Affiche la grille formatée
- `int main()` : Point d'entrée créant une grille 4×4

## Technologies utilisées

- **C++20** : Standard moderne avec features avancées
- **STL** :
  - `std::vector` pour la gestion mémoire dynamique
  - `std::random` pour génération aléatoire de qualité
  - `std::iostream` pour l'affichage console
- **Visual Studio** : IDE et outils de build Microsoft

## Fonctionnalités

- Génération aléatoire de grilles de taille variable
- Affichage formaté dans la console
- Architecture orientée objet
- Gestion automatique de la mémoire avec std::vector
- Génération aléatoire de haute qualité avec Mersenne Twister

## Améliorations futures possibles

- Génération de villes plus complexes (arbres, parcs, commerces)
- Algorithmes de génération procédurale avancés
- Vérification de la connectivité des rues
- Export vers fichiers (JSON, CSV, images)
- Interface graphique avec Qt ou SFML
- Paramètres de densité configurables

## Historique

**Version 2.0** (Actuelle)
- Conversion complète de Java vers C++
- Utilisation de std::vector pour la sécurité mémoire
- Standard C++20
- Projet Visual Studio configuré
- Corrections de bugs de la version Java

**Version 1.0**
- Version initiale en Java
- Génération basique de grille

## Licence

Ce projet est libre d'utilisation pour des fins éducatives et personnelles.

## Auteur

Projet CityGenerator - Générateur de ville procédural
