Rendu du chapitre CPP03 - Piscine C++ - Ecole 42

Infos general : 

Les .hpp respectent une norme dans laquelle les prototypes des fonctions et membres ne decrivent pas les parametres. L'objectif etant de simplifier le code, de le rendre plus lisible en limitant les informations affichees.
Le Makefile est setup pour pouvoir est utlise partout de la meme facon, donc dossiers inc, src, .obj( ignores par gitignore) puis une separation entre Abstract, Concrete, et Interface classes reproduits dans chaque dossier

EX00 - 
Not much to say except for class definition.
The subject is not yet hard to follow

EX01 -
We discover derived class set up by the " : public ClapTrap" in ScavTrap.hpp
Why is there no new function takeDamage() for the ScavTrap class, considering it print the type ClapTrap ?

EX02 -
Same question here for FragClap, also considering the attack() function. Otherwise, a mostly straight forward exercice.

EX03 -
Values of DiamondTrap : 
Hipoints = FragTrap = 100
Energy Points = ScavTrap = 50
Attack damage = FragTrap = 30
Worst problem so far, but the problem comes from the specific variable definition asked. I didnt want to set them myself, so I call default setters for each variable, do you have a better solution ?