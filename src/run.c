#include "metropolis.h"

int main(int argc, char *argv[]) {

  if(argc != 4) {
    printf("This executable needs 3 arguments (size of grid, left, right)!");
    return 1;
  }

  double left;
  sscanf (argv[2],"%f",&left);
  double right;
  sscanf (argv[3],"%f",&right);
  unsigned int size_of_array;
  sscanf (argv[1],"%d",&size_of_array);
  double array[size_of_array];
  array[0] = left;
  array[size_of_array - 1] = right;


//  for ( unsigned int i = 0; i < size_of_array; ++i ) {
//       printf( "*(arr + %d) : %f\n", i, *(array + i));
//  }
  return 0;
}
