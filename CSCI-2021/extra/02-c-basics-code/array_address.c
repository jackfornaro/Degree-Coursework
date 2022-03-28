// array_address.c: demonstrate that the bare name of an array is
// always treated as its starting address.
#include <stdio.h>
int main(){
  int a[] = {5,10,15};          // declare array, auto size
  printf(" a: %p\n", a);        // print bare name a: its starting address
  printf("&a: %p\n",&a);        // print addrss of a: its starting address
  return 0;
}
