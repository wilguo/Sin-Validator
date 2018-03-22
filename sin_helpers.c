#include <stdio.h>
#include <stdlib.h>

int get_number_of_digits(int num){
	int n = 0;
    while(num) {
        num /= 10;
        n = n + 1;
    }
    return n;
}

// TODO: Implement populate_array
/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
	int num_digits = get_number_of_digits(sin);
	if(num_digits != 9){
		return 1;
	}else{
		for(int i = 8; i >= 0; i--){
			sin_array[i] = sin % 10;
			sin = sin / 10;
		}
	    return 0;		
	}
	return 0;
}

// TODO: Implement check_sin
/* 
 * Return 0 (true) iff the given sin_array is a valid SIN.
 */
int check_sin(int *sin_array) {
	int total = 0;
	for(int i = 0; i < 9; i++){
		if(i % 2 == 0){
			//even
			int result = sin_array[i] * 1;
			if(get_number_of_digits(result) == 1){
				total = total + result;
			}else{
				total = total + (result % 10);
				result = result / 10;
				total = total + result;
			}
		}else if(i % 2 == 1){
			//odd
			int result = sin_array[i] * 2;
			if(get_number_of_digits(result) == 1){
				total = total + result;
			}else{
				total = total + (result % 10);
				result = result / 10;
				total = total + result;
			}
		}
	}
	if(total % 10 == 0){
		printf("Valid SIN\n");
	}else{
		printf("Invalid SIN\n");
	}
    return 1;
}