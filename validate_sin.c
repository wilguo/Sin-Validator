#include <stdio.h>
#include <stdlib.h>

int populate_array(int, int *);
int check_sin(int *);


int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.
	if(argc != 2){
		return 1;
	}
    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.

  	int arr[9];
  	int sin = strtol(argv[1], NULL, 10);
	populate_array(sin, arr);
	check_sin(arr);

    return 0;
}
