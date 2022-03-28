#include "treemap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//initializer of trees
void treemap_init(treemap_t *tree){
  tree->root = NULL;
  tree->size = 0;
}

int treemap_add(treemap_t *tree, char key[], char val[]){
  //case for an empty tree
  if(tree->root == NULL){
    node_t *node = malloc(sizeof(node_t));
    strcpy(node->key, key);
    strcpy(node->val, val);
    node->left = NULL;
    node->right = NULL;
    tree->root = node;
    tree->size++;
    return 1;
  }
  node_t *current = tree->root;
  while(1){
    int diff = strcmp(key, current->key);
    //case where the key is found
    if(diff == 0){
      strcpy(current->val, val);
      return 0;
    }
    //case where the node is placed to the left
    else if(diff < 0){
      if(current->left == NULL){
        node_t *node = malloc(sizeof(node_t));
        strcpy(node->key, key);
        strcpy(node->val, val);
        node->left = NULL;
        node->right = NULL;
        current->left = node;
        return 1;
      }
      else{
        current = current->left;
      }
    }
    //case where the node is placed to the right
    else if(diff > 0){
      if(current->right == NULL)
      {
        node_t *node = malloc(sizeof(node_t));
        strcpy(node->key, key);
        strcpy(node->val, val);
        node->left = NULL;
        node->right = NULL;
        current->right = node;
        return 1;
      }
      else{
        current = current->right;
      }
    }
  }
  printf("I shouldn't be printing\n");
  return -1;
}

char *treemap_get(treemap_t *tree, char key[]){
  node_t *current = tree->root;
  int diff;
  if(current == NULL){
    return NULL;
  }
  while(1){
    diff = strcmp(key, current->key);
    if(current == NULL){
      return NULL;
    }
    if(diff < 0){
      current = current->left;
    }
    else if(diff > 0){
      current = current->right;
    }
    else if(diff == 0){
      return current->val;
    }
  }
}

void treemap_clear(treemap_t *tree){
  if(tree->root == NULL){
    return;
  }
  node_remove_all(tree->root);
}

void node_remove_all(node_t *cur){
  if(cur->left != NULL){
    node_remove_all(cur->left);
  }
  else if(cur->right != NULL){
    node_remove_all(cur->right);
  }
  free(cur);
}

//uses the helper function to perform its task
void treemap_print_revorder(treemap_t *tree){
  node_print_revorder(tree->root, 0);
}


void node_print_revorder(node_t *cur, int indent){
  if(cur == NULL){
    return;
  }
  //perform the function on the right side
  node_print_revorder(cur->right, indent + 2);
  //add indents where needed
  for(int i = 0; i < indent; i++){
    printf(" ");
  }
  //perform the function on the left side
  printf("%s -> %s\n", cur->key, cur->val);
  node_print_revorder(cur->left, indent + 2);
  return;
}

void treemap_print_preorder(treemap_t *tree){
  node_write_preorder(tree->root, stdout, 0);
}

void treemap_save(treemap_t *tree, char *fname){
  FILE *file = fopen(fname, "w");
  node_write_preorder(tree->root, file, 0);
  fclose(file);
}

void node_write_preorder(node_t *cur, FILE *out, int depth){
  if(cur == NULL){
    return;
  }
  for(int i = 0; i < depth; i++){
    fprintf(out, " ");
  }
  fprintf(out, "%s %s\n", cur->key, cur->val);
  node_write_preorder(cur->left, out, depth++);
  node_write_preorder(cur->right, out, depth++);
  return;
}

int treemap_load(treemap_t *tree, char *fname){
    //Open file and make sure it opened properly
    FILE *file = fopen(fname, "r");
    if(file == NULL){
      return 0;
    }
    //Call treemap_clear to reset the tree
    treemap_clear(tree);
    //Create key and val arrays
    char key[128];
    char val[128];
    while(!feof(file)){
      //Scan in two strings at a time into key and val
      //Call treemap_add to create a new node in the tree
      //with the new key and val pair scanned from the file
      fscanf(file, " %s  %s", key, val);
      treemap_add(tree, key, val);
    }
    //close file
    fclose(file);
    return 1;
}
