// optimized versions of matrix diagonal summing
#include "matvec.h"

int matsquare_VER1(matrix_t mat, matrix_t matsq) {
  //creating a variable matlen that represents the length of the rows,
  //the lengths of the columns, and the amount of additions in a given matrix index
  int matlen = mat.rows;
  //setting all the indexes in matsq to 0
  for(int i=0; i<matlen; i++){
    for(int j=0; j<matlen; j++){
      MSET(matsq,i,j,0);
    }
  }
  //initializing k for the purpose of scope
  int k;
  //going through the rows
  for(int i = 0; i < matlen; i++){
    //going through the cols
    for(int j = 0; j < matlen; j++){
      //creating the lead variable which changes upon col iteration
      int lead = MGET(mat, i, j);
      //loop unrolled for loop for the number of additions in each index
      //stride = 2
      for(k = 0; k < matlen - 2; k+=2){
        int res = MGET(matsq, i, k);
        int cur = MGET(mat, j, k);
        int val = (cur * lead) + res;
        //saving the current value of the index for further manipulation if needed
        MSET(matsq, i, k, val);
        int res1 = MGET(matsq, i, k+1);
        int cur1 = MGET(mat, j, k+1);
        int val1 = (cur1 * lead) + res1;
        //saving the current value of the index for further manipulation if needed
        MSET(matsq, i, k+1, val1);
      }
      //cleanup for k-values that weren't reached in the for-loop
      for(; k < matlen; k++){
        int res = MGET(matsq, i, k);
        int cur = MGET(mat, j, k);
        int val = (cur * lead) + res;
        MSET(matsq, i, k, val);
      }
    }
  }
  return 0;
}

int matsquare_OPTM(matrix_t mat, matrix_t matsq) {
  if(mat.rows != mat.cols ||                       // must be a square matrix to square it
     mat.rows != matsq.rows || mat.cols != matsq.cols)
  {
    printf("matsquare_OPTM: dimension mismatch\n");
    return 1;
  }


  // Call to some version of optimized code
  return matsquare_VER1(mat, matsq);
}
