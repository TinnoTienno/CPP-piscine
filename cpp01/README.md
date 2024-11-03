Rendu du chapitre CPP01 - Piscine C++ - Ecole 42

Infos general : 

Les .hpp respectent une norme dans laquelle les prototypes des fonctions et membres ne decrivent pas les parametres. L'objectif etant de simplifier le code, de le rendre plus lisible en limitant les informations affichees.
Le Makefile est setup pour pouvoir est utlise partout de la meme facon, donc dossiers inc, src, .obj( ignores par gitignore) puis une separation entre Abstract, Concrete, et Interface classes reproduits dans chaque dossier

EX00 - 
Not much to say, other than the idea of dynamically allocating a zombie seems like a bad idea, because then you have to keep track of each and delete them, then again, you cant return a local allocated zombie to another function.

EX01 -
Same biz, no protection from new, but we havent discovered the exceptions yet

EX02 -
Qu'est ce qu'une reference ?
Ba tu vois comme en c, le seul moyen de ne pas passer une copie d'un element, c'est d'envoyer un pointeur sur cette element, pointeur qui du coup, peut buguer, parce que si il est mal utilise, il peut etre set a nul etc ? 
Ba c'est la que la reference entre en jeu en c++, ca permet de passer la valeur, sans copie, et sans utiliser de pointeur, alors, a quoi ca sert, ba deja ca rend le code plus rapide, moins d'allocation, meme sur la stack, puisque pas de copie. En plus ca rend le code plus propre parce que tu sais precisement ce qui se cache derriere la ref, cad la variable appelee.
En plus, ca permet de renommer une variable, si toutefois ca vous parait necessaire

EX03 -
"HumanA can have a reference or a pointer to the Weapon." Ca veut dire quoi ca ? En vrai, c'est un des exos les plus durs, faudrait peut etre le faire checker par quelqu'un

EX04 - 
Tests a faire : 
pas le bon nom de fichier
pas de key
pas de remplacement
pas de fichier
un fichier bloque 
un fichier sortie dont les permissions sont bloquees
test uniforme
