#include "treemap.h"
#include <string.h>

int main(int argc, char *argv[]){

  //initialize the echo
  int echo = 0;
  if(argc > 1 && strcmp("-echo", argv[1]) == 0){
    echo = 1;
  }

  printf("TreeMap Editor\n");
  printf("Commands:\n");
  printf("  quit:            exit the program\n");
  printf("  print:           shows contents of the tree in reverse sorted order\n");
  printf("  add <key> <val>: inserts the given key/val into the tree, duplicate keys are ignored\n");
  printf("  get <key>:       prints FOUND if the name is in the tree, NOT FOUND otherwise\n");
  printf("  clear:           eliminates all key/vals from the tree\n");
  printf("  preorder:        prints contents of the tree in pre-order which is how it will be saved\n");
  printf("  save <file>:     writes the contents of the tree in pre-order to the given file\n");
  printf("  load <file>:     clears the current tree and loads the one in the given file\n");

  //intialize tree
  treemap_t t;
  treemap_init(&t);

  while(1){
    printf("TM> ");
    char compare[128];
    char key[128];
    char val[128];
    fscanf(stdin, "%s", compare);
    //all of the if statements compare the input value to the command.
    //If it matches, perform the command and echo.
    if(strcmp(compare, "quit") == 0){
      if(echo){
        printf("quit\n");
      }
      break;
    }
    else if(strcmp(compare, "print") == 0){
      if(echo){
        printf("print\n");
      }
      treemap_print_revorder(&t);
    }
    else if(strcmp(compare, "add") == 0){
      scanf("%s %s", key, val);
      if(echo){
        printf("add %s %s\n", key, val);
      }
      treemap_add(&t, key, val);
    }
    else if(strcmp(compare, "get") == 0){
      scanf("%s", key);
      if(echo){
        printf("get %s\n", key);
      }
      if(treemap_get(&t, key) == NULL){
        printf("NOT FOUND\n");
      }
      else{
        printf("FOUND:  %s\n", treemap_get(&t, key));
      }
    }
    else if(strcmp(compare, "clear") == 0){
      if(echo){
        printf("clear\n");
      }
      treemap_clear(&t);
    }
    else if(strcmp(compare, "preorder") == 0){
      if(echo){
        printf("preorder\n");
      }
      treemap_print_preorder(&t);
    }
    else if(strcmp(compare, "save") == 0){
      scanf("%s", key);
      if(echo){
        printf("save %s\n", key);
      }
      treemap_save(&t, key);
    }
    else if(strcmp(compare, "load") == 0){
      scanf("%s", key);
      if(echo){
        printf("load %s\n", key);
      }
      treemap_load(&t, key);
    }
  }
  return 0;
}
