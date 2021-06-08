[PROJET MALLOC ETNA]


| Introduction du projet |

Le but principal du projet est de reprogrammer les fonctions malloc/free système
qui permettent d'allouer et de libérer de la mémoire de façon dynamique.
L'usage des fonctions brk et sbrk nous permettent de modifier la taille du
segment de données.

*-------------------------*
| Stratégie mise en place |
*-------------------------*

La stratégie adoptée est la méthode du "premier segment de donnée",
aussi appeler "first fit".
Cette solution est facile à implémenter, néanmoins, elle ne lutte pas
contre la fragmentation et ne permet pas d'avoir les meilleures
performances possibles. Cette méthode reste fiable néanmoins.

*-----------------------------*
| Récapitulatif de la méthode |
*-----------------------------*

1) On parcoure les blocs
2) On s'assure que le bloc contient suffisamment de donnée
3) On s'assure que le bloc n'est pas déjà alloué
4) On alloue selon la taille demandée par l'utilisateur
