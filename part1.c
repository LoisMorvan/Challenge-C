#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ASCII_Letter {
	char letter;
	int code;
} ASCII_Letter;

ASCII_Letter* init_tab(int n) {
    return (ASCII_Letter*) malloc(n * sizeof(ASCII_Letter));
}

void fill_array (char* str, ASCII_Letter* tab) {
	for (int i = 0 ; i < strlen(str) ; i++) {
		tab[i].letter = str[i];
		tab[i].code = (int) str[i];
	}
}

int main () {
	ASCII_Letter* tab = init_tab(2);
	fill_array("ab", tab);
	return 0;
}