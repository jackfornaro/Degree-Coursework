// Construct memory diagrams for the blocks below
#include <stdio.h>
int main(int argc, char *argv[]){

  // BLOCK A
  int a = 5;
  int b = 7;
  double x = 4.5;
  int *ip = &a;
  ip = &b;
  int c = *ip;
  *ip = 19;
  // DRAW MEMORY HERE


  // BLOCK B
  int arr[4] = {12, 14, 16, 18};
  int *arp = arr;
  int brr = 11;
  arr[1] = 23;
  arp[3] = 29;
  arp = &arr[2];
  *arp = brr;
  // DRAW MEMORY HERE

  // BLOCK C
  char *cp = NULL;
  char str[8] = "hello";
  str[5] = 'w';
  cp = str + 6;
  *cp = '\0';
  str[0] = 'y';
  // DRAW MEMORY HERE
  printf("%c\n", str[0]);
  printf("%c\n", str[1]);
  printf("%c\n", str[2]);
  printf("%c\n", str[3]);
  printf("%c\n", str[4]);
  printf("%c\n", str[5]);
  printf("%c\n", str[6]);
  printf("%c\n", str[7]);
  printf("%s\n", cp);
}
