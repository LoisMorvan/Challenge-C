#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASCII_Letter{
	char letter;
	int code;
}ASCII_Letter;

typedef struct codage1{
	ASCII_Letter lettre;
	ASCII_Letter crypte;
}Codage1;

void afficher_letter(ASCII_Letter letter) {
	printf("%c %d \n", letter.code, letter.letter);
}

void afficher_crypte(Codage1 codage) {
	printf("%c %d \n", codage.crypte.code, codage.crypte.letter);
}

void afficher_tab(ASCII_Letter *tab, int len) {
	int i;
	for(i = 0; i < len; i++) {
		afficher_letter(*(tab+i));
	}
}

void afficher_codage(Codage1 *codage, int len) {
	int i;
	for(i = 0; i < len; i++) {
		afficher_crypte(*(codage+i));
	}
}

void afficher_nombre(nb) {
	printf("%d", nb);
}

ASCII_Letter* init_tab(int n){
    return (ASCII_Letter*) malloc(n * sizeof(ASCII_Letter));
}

Codage1* init_codage1(int n){
    return (Codage1*) malloc(n * sizeof(Codage1));
}

char* saisie_chaine() {
	char* chaine = (char*)malloc(sizeof(char));
	printf("Saisir une chaine de caractere : ");
	scanf("%s", chaine);
	return chaine;
}

ASCII_Letter create_ascii() {
	ASCII_Letter ascii;
	char letter;
	printf("Saisir une lettre : ");
	scanf("%c", &letter);
	ascii.letter = letter;
	ascii.code = (int) letter;
	return ascii;
}

void remplir_tab(ASCII_Letter *tab, char* chaine) {
	int i;
	for(i = 0; i < strlen(chaine); i++){
		(*(tab+i)).letter = *(chaine+i);
		(*(tab+i)).code = (int) *(chaine+i);
	}
}

void remplir_codage(Codage1* codage, char* chaine, int n) {
	ASCII_Letter* tab = init_tab(strlen(chaine));
	remplir_tab(tab, chaine);
	
	int i;
	for(i = 0; i < strlen(chaine); i++){
		(*(codage+i)).lettre = (*(tab+i));
		(*(codage+i)).crypte.letter = n + (*(tab+i)).letter;
		(*(codage+i)).crypte.code = (int) n + (*(tab+i)).letter;
	}
}

int recherche(Codage1* codage, int n) {
	char lettre;
	printf("Saisir la lettre a rechercher : ");
	scanf(" %c", &lettre);
	int i;
	int nb = 0;
	for(i = 0; i < n; i++) {
		if(codage[i].lettre.letter == lettre) {
			nb += 1;
		}	
	}
	return nb;
}

int main() {
	ASCII_Letter ascii;
	
	ascii = create_ascii();
	afficher_letter(ascii);
	
	char* chaine = (char*)malloc(sizeof(char));
	int n;
	
	chaine = saisie_chaine();
	
	ASCII_Letter* tab;
	Codage1* codage;
	
	n = strlen(chaine);
	tab = init_tab(n);
	codage = init_codage1(n);
	
	remplir_tab(tab, chaine);
	afficher_tab(tab, n);
	
	remplir_codage(codage, chaine, 5);
	afficher_codage(codage, n);
	
	int nb = recherche(codage, n);
	afficher_nombre(nb);
	
	return 0;
}
