Rendu du chapitre CPP02 - Piscine C++ - Ecole 42

Infos general : 

Les .hpp respectent une norme dans laquelle les prototypes des fonctions et membres ne decrivent pas les parametres. L'objectif etant de simplifier le code, de le rendre plus lisible en limitant les informations affichees.
Le Makefile est setup pour pouvoir est utlise partout de la meme facon, donc dossiers inc, src, .obj( ignores par gitignore) puis une separation entre Abstract, Concrete, et Interface classes reproduits dans chaque dossier

EX00 -

A partir d'ici, les formes cannoniques seront etablies dans une norme specifique

EX01 -

On continue a tout normer

EX02 - La division est un cas particulier, le reste est plutot facilement explicable

EX03 - 
BSP
La technique utilisee pour savoir si un point est ou non a l'interieur du triangle repose sur la question de la position de ce point par rapport a chaque segment du triangle. Ainsi, si le point est, pour chaque segment du meme "cote", il est forcement a l'interieur du triangle. 
Pour ca, nous convertissons les segments en vecteurs, une forme mathematique suffisamment proche du point pour etre utilisee dans l'exercice.
On calcule ensuite le produit vectoriel (cross product) qui nous donne une direction finale (gauche ou droite).
Comparons chaque segment au point et nous avons notre resultat.