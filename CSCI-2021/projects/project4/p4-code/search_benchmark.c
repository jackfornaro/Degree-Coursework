#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "search.h"
// Complete this main to benchmark the search algorithms outlined in
// the project specification

int main(int argc, char *argv[]){
  //set the inputs upon compilation through the terminal (except argv[4])
  int min = atoi(argv[1]);
  int max = atoi(argv[2]);
  int reps = atoi(argv[3]);

  //boolean values telling us with algorithm(s) to run
  int run_linear_array = 0;
  int run_linear_list = 0;
  int run_binary_array = 0;
  int run_binary_tree = 0;

  printf("LENGTH  ");
  printf("SEARCHES");

  //if the string is not empty
  if(strlen(argv[4]) != 0){
    //set the string to the fourth argument
    char *algs_string = argv[4];
    for(int i = 0; i < strlen(algs_string); i++){
      if(algs_string[i] == 'a'){ //if 'a' is present in the string
        run_linear_array = 1; //set the boolean value for run_linear_array to 1
        printf("        array");
      }
      if(algs_string[i] == 'l'){
        run_linear_list = 1;
        printf("            list");
      }
      if(algs_string[i] == 'b'){
        run_binary_array = 1;
        printf("                binary");
      }
      if(algs_string[i] == 't'){
        run_binary_tree = 1;
        printf("                  tree");
      }
    }
  }
  //if the string is empty, i.e. no argv[4] is present, perform the
  //benchmark on all the algorithms
  else{
    run_linear_array = 1;
    run_linear_list = 1;
    run_binary_array = 1;
    run_binary_tree = 1;
    printf("        array");
    printf("            list");
    printf("                binary");
    printf("                  tree");
  }

  //initializing the clock and the cur_search_size variable
  clock_t begin, end;
  int cur_val = 1;

  //loop starts at one and goes until the max value is reached
  for(int i = 1; i <=max; i++){
    cur_val = cur_val * 2; //doubled, (2^i), each itearation
    //if i should start outputting results based on the length
    if(i >= min){
      //print the length and the # of searches
      printf("%d ", cur_val);
      printf("    %d", reps * (2 * cur_val));
    }
    //Case 1: run_linear_array = 1
    if(run_linear_array == 1){
      if(i >= min){
        //create the array of length(cur_val)
        int arr1 = make_evens_array(cur_val);
        begin = clock(); //start the timer
        //goes through the amount of repititions
        for(int i = 0; i < reps; i++){
          //goes through 2 * length - 1
          for(int j = 0; j < (2 * cur_val) - 1; j++){
            //perform the single search on arr1, searching for j
            linear_array_search(arr1, (2 * cur_val) - 1, j);
          }
        }
        end = clock(); //end the timer
        //saved time that will print the time it took to complete the search
        double cpu_time_linear_array = ((double) (end - begin)) / CLOCKS_PER_SEC;
        printf("        %.4e  ", cpu_time_linear_array);
        free(arr1);
      }
    }
    //Case 2: run_linear_list = 1
    if(run_linear_list == 1){
      if(i >= min){
        //create the list of length(cur_val)
        list_t *list = make_evens_list(cur_val);
        begin = clock(); //start the timer
        //goes through the amount of repititions
        for(int i = 0; i < reps; i++){
          //goes through 2 * length - 1
          for(int j = 0; j < (2 * cur_val) - 1; j++){
            //perform the single search on list, searching for j
            linkedlist_search(list, (2 * cur_val) - 1, j);
          }
        }
        end = clock(); //end the timer
        //saved time that will print the time it took to complete the search
        double cpu_time_list = ((double) (end - begin)) / CLOCKS_PER_SEC;
        printf("        %.4e  ", cpu_time_list);
        list_free(list);
      }
    }
    //Case 3: run_binary_array = 1
    if(run_binary_array == 1){
      if(i >= min){
        //create the array of length(cur_val)
        int arr2 = make_evens_array(cur_val);
        begin = clock();
        for(int i = 0; i < reps; i++){
          for(int j = 0; j < (2 * cur_val) - 1; j++){
            //perform the single search on arr2, searching for j
            binary_array_search(arr2, (2 * cur_val) - 1, j);
          }
        }
        end = clock();
        //saved time that will print the time it took to complete the search
        double cpu_time_binary_array = ((double) (end - begin)) / CLOCKS_PER_SEC;
        printf("        %.4e  ", cpu_time_binary_array);
        free(arr2);
      }
    }
    //Case 4: run_binary_tree
    if(run_binary_tree == 1){
      if(i >= min){
        //create the tree of length(cur_val)
        bst_t *tree = make_evens_tree(cur_val);
        begin = clock();
        for(int i = 0; i < reps; i++){
          for(int j = 0; j < (2 * cur_val) - 1; j++){
            //perform the single search on tree, searching for j
            binary_tree_search(tree, (2 * cur_val) - 1, j);
          }
        }
        end = clock();
        //saved time that will print the time it took to complete the search
        double cpu_time_tree = ((double) (end - begin)) / CLOCKS_PER_SEC;
        printf("        %.4e  ", cpu_time_tree);
        bst_free(tree);
      }
    }
    //prints a newline for formatting
    printf("\n");
  }
  return 0;
}
