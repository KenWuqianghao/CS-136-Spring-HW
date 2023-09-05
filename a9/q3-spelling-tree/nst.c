/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//
//
// Name: Ken Wu
// login ID: 20999205
//////////////////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "nst.h"

// === N-Search Tree Node =====================================================

// LETTERS represents the number of children in a nst_node
const int LETTERS = 26;

// nst_node represents a node in a n-search tree
struct nst_node {
  bool end;                   // indicates if a node can be the end of a word
  struct nst_node **children; // pointer to the node's children
};

// your implementation goes here

// === N-Search Tree ==========================================================

// nst represents a n-search tree
struct nst {
  struct nst_node *root;
};

// See nst.h for documentation
struct nst *nst_create() {
  struct nst *tree = malloc(sizeof(struct nst));
  return tree;
}

// nstnode_destroy(node) deallocates all dynamically allocated memory
//   within the entire bst
// effects : the memory at node is invalid (freed)
// time : O(n)
void nstnode_destroy(struct nst_node *node) {
  if (node) {
    for (int i = 0; i < LETTERS; i++) {
      nstnode_destroy(node->children[i]);
    }
    free(node->children);
    free(node);
  }
}

// See nst.h for documentation
void nst_destroy(struct nst *tree) {
  assert(tree);
  nstnode_destroy(tree->root);
  free(tree);
}

struct nst_node *new_leaf(char *string) {
  struct nst_node * leaf = malloc(sizeof(struct nst_node) + strlen(string) * sizeof(struct nst_node *)); 
  for (int i = 0; i < strlen(string); i++) {
    leaf->children[i] = string[i];
  }
  return leaf; 
}

// See nst.h for documentation
void nst_insert(struct nst *tree, const char *word) {
  assert(tree);
  assert(word);

  for (int i = 0; i < strlen(word); i++) {
    if (tree->root == NULL) {
      tree->root = new_leaf(word[i]);
    }
    else {
      struct nst_node *curr = tree->root;
      while (curr->children[word[i] - 'a'] != NULL) {
        curr = curr->children[word[i] - 'a'];
      }
      curr->children[word[i] - 'a'] = new_leaf(word[i]);
    }
  }
}

// See nst.h for documentation
bool nst_spellcheck(const struct nst *tree, const char *word) {
  assert(tree);
  assert(word);
  return false;
}

// See nst.h for documentation
int nst_memory(const struct nst *tree) {
  assert(tree);
  return 0;
}