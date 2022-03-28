// Demonstrate use binary file I/O functions with structs. Uses
// fwrite()/fread() functions to write/read byte/binary versions of
// struct array.
#include <stdlib.h>
#include <stdio.h>

typedef struct {                // simple struct 
  double x;     int y;    char nm[4];
} small_t;

int main(){
  small_t sarr[3] = {
    {.x=5.5,  .y=2, .nm = "oh"},
    {.x=15.5, .y=4, .nm = "my"},
    {.x=25.5, .y=6, .nm = "god"},
  };

  char *struct_file = "structs.dat";             // name of file: binary data

  FILE *fout = fopen(struct_file,"w");           // open for writing
  fwrite(sarr,sizeof(small_t), 3, fout);
  // for(int i=0; i<3; i++){
  //   fwrite(&sarr[i], sizeof(small_t), 1, fout);  // write bytes of 1 struct
  // }
  fclose(fout);                                  // close output file

  small_t *darr = malloc(sizeof(small_t)*3);     // dynamically allocate array
  FILE *fin = fopen(struct_file,"r");            // open file for reading
  fread(darr, sizeof(small_t), 3, fin);          // read bytes of 1 struct
  // for(int i=0; i<3; i++){
  //   fread(darr, sizeof(small_t), 1, fin);    // read bytes of 1 struct
  // }

  fclose(fin);                                   // close input file
  
  for(int i=0; i<3; i++){                        // print read array
    fprintf(stdout,"%f %d %s\n",                 // use open stdout to print
            darr[i].x, darr[i].y, darr[i].nm);
  }
  
  free(darr);                                    // free memory
  return 0;
}
