#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	// go through each string in argv
	// why am I skipping argv[0]?
	for(i = 1; i < argc; i++){
		printf("arg %d: %s\n", i, argv[i]);
	}

	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas",
		NULL
	};
	int num_states = 5;

	for(i = 0; i < num_states; i++){ 
		printf("states %d: %s\n", i, states[i]);
	 }

	argv[0] = states[1];
	states[1] = argv[1];
	printf("%d %s %s\n", argc, argv[0], states[1]);


	return 0;
}
