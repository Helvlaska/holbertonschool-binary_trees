#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * calculate_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL, otherwise the height
 */
int calculate_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL) /*verifie si l'arbre est vide*/
		return (0); /*si echec retourne 0*/

	left = calculate_height(tree->left);
	right = calculate_height(tree->right);

	/*on compare les hauteurs gauche et droite*/
	if (left > right)
		return (left + 1); /*on return la height G + 1*/
	else
		return (right + 1); /*on return la height D + 1*/
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL, otherwise the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/*compteur de stockage gauche et droite*/
	int height_left = 0, height_right = 0, balance = 0;

	if (tree == NULL) /*verifie si l'arbre est vide*/
		return (0); /*si echec retourne 0*/

	/*si il y a une brache a gauche*/
	if (tree->left) /*on recupère la hauteur du coté gauche*/
		height_left = calculate_height(tree->left);
	/*si il y a une branche a droite*/
	if (tree->right) /*on récupère la hauteur du coté droit*/
		height_right = calculate_height(tree->right);

	/*on récupère la différence entre le coté droite et gauche*/
	balance = height_left - height_right;

	return (balance);
}
