# 42_push_swap

42_push_swap est un projet de l'école 42 dans lequel nous devons trier une liste donnée de nombres aléatoires avec un ensemble limité d'instruction, en utilisant le plus petit nombre d'action possible.

## Règles

Nous avons 2 stacks nommées **a** et **b**.
Au début **a** contient un nombre aléatoire de nombres positifs ou négatifs sans aucun doublon et **b** est vide.
Le but est de trier par ordre croissant les numéros dans la pile **a**.

Les actions possibles sont :
* ```sa``` : swap **a** - Échange les deux premiers éléments en haut de la pile **a** . Ne fait rien s’il n’y a qu’un ou aucun élément.
* ```sb``` : swap **b** - Échange les deux premiers éléments en haut de la pile **b** . Ne fait rien s’il n’y a qu’un ou aucun élément.
* ```ss``` : Fait ```sa``` et ```sb``` en même temps.
* ```pa``` : push **a** -  Prend le premier élément en haut de **b** et le place en haut de **a** . Ne fait rien si **b** est vide.
* ```pb``` : push **b** - Prend le premier élément en haut de **a** et le place en haut de **b** . Ne fait rien si **a** est vide.
* ```ra``` : rotate **a** - Décale tous les éléments de la pile **a** vers le haut de un. Le premier élément devient le dernier.
* ```rb``` : rotate **b** - Décale tous les éléments de la pile **b** vers le haut de un. Le premier élément devient le dernier.
* ```rr``` : Fait ```ra``` et ```rb``` en même temps.
* ```rra``` : reverse rotate **a** - Décale tous les éléments de la pile **a** vers le bas de un. Le dernier élément devient le premier.
* ```rrb``` : reverse rotate **b** - Décale tous les éléments de la pile **b** vers le bas de un. Le dernier élément devient le premier.
* ```rrr``` : Fait ```rra``` et ```rrb``` en même temps.

## Usage

Utilisez la commande ```make``` pour compiler puis exécutez avec : 
```
./push_swap <list of numbers>
```
Exemple:
```
./push_swap 2 1 3 6 5 8
```
ou:
```
./push_swap "2 1 3 6 5 8"
```
***
