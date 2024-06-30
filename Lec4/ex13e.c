#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("ERROR: You need one argument.\n");
		return 1;
	}

	int i = 0;
	for(i = 0; argv[1][i] != '\0'; i++){
		char letter = argv[1][i];

		switch(letter){
			
			case 'a':
				printf("%d: 'A'\n", i);
				break;
			case 'A':
				printf("%d: 'A'\n", i);
				argv[1][i] = argv[1][i] + 32;
				break;

			default:
				printf("%d: %c is not a vowel\n", i, letter);
				if(letter >= 'A' && letter <= 'Z'){
					argv[1][i] = '-';
				}
		}
	}

	printf("%s\n", argv[1]);

	return 0;
}
