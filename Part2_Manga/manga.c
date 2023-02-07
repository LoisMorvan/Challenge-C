#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Manga {
    char titre[50];
    int age;
    float prix;
} Manga;

Manga* create_manga () {
    Manga* m = malloc(sizeof(Manga));

    printf("Saisir le titre du manga:\n> ");
    scanf(" %[^\n]s", m->titre);
    printf("Saisir l'age minimum:\n> ");
    scanf("%d", &m->age);
    printf("Saisir le prix du manga\n> ");
    scanf("%f", &m->prix);
    
    return m;
}

Manga* add_manga (int n) {
    Manga* m = malloc(sizeof(Manga)*n);
    
    for (int i = 0 ; i < n ; i++) {
        m[i] = *create_manga();
    }

    return m;
}

Manga** add_manga_p (int n) {
    Manga** m = malloc(sizeof(Manga*)*n);
    
    for (int i = 0 ; i < n ; i++) {
        m[i] = create_manga();
    }

    return m;
}

void print_1manga (Manga m) {
    printf("Titre: %s\nAge: %d\nPrix: %.2f\n", m.titre, m.age, m.prix);
}

void print_manga (Manga* mt, int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("\n\t(%d)\nTitre: %s\nAge: %d\nPrix: %.2f\n", i+1, (*(mt+i)).titre, mt[i].age, mt[i].prix);
    }
}

void print_manga_p (Manga** mt, int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("\nTitre: %s\nAge: %d\nPrix: %.2f\n", (*(*(mt+i))).titre, mt[i]->age, mt[i]->prix);
    }
}

void print_manga_age (Manga* mt, int size, int age) {
    for (int i = 0 ; i < size ; i++) {
        if (mt[i].age >= age) {
            printf("\nTitre: %s\nAge: %d\nPrix: %.2f\n", (*(mt+i)).titre, mt[i].age, mt[i].prix);
        }
    }
}

int nb_manga_titre (Manga* m, int size, char t) {
    int cpt = 0;
    for (int i = 0 ; i < size ; i++) {
        if (toupper(m[i].titre[0]) == toupper(t)) {
            cpt++;
        }
    }
    return cpt;
}

char* strtoupper (char* str) {
    char* res = malloc(sizeof(char)*strlen(str));
    int i = 0;
    while (str[i] != '\0') {
        res[i] = toupper(str[i]);
        i++;
    }
    return res;
}

float price_of_manga (Manga* m, int size, char* titre) {
    for (int i = 0 ; i < size ; i++) {
        if (strcmp(strtoupper(m[i].titre), strtoupper(titre)) == 0) {
            printf("%s / %s", strtoupper(m[i].titre), strtoupper(titre));
            return m[i].prix;
        }
    }
    return -1;
}

float sum_cart (Manga* m, char* num) {
    int i = 1;
    float sum = 0;
    char indice[2];
    while (num[i-1] != '\0') {
        if (num[i-1] != '|' && num[i] == '|') {
            indice[0] = num[i-1];
            sum += m[atoi(indice)-1].prix;
        }
        if (num[i-1] != '|' && num[i] != '|') {
            indice[0] = num[i-1];
            indice[1] = num[i];
            sum += m[atoi(indice)-1].prix;
        }
        i++;
    }
    return sum;
}

void menu (Manga* m, int size) {
    printf("\t--- Bienvenu dans votre espace Manga ---\n\n");

    while (1) {
        printf("\n1) Afficher mangas\n2) Afficher mangas avec restriction d'age\n3) Afficher mangas commancant par ...\n4) Rechercher un manga\n5) Panier\n\n");
        int choice;
        printf("Entrez votre choix :\n>");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_manga(m, size);
                break;
            case 2:
                printf("Quel est l'age limite ?\n>");
                int age;
                scanf("%d", &age);
                print_manga_age(m, size, age);
                break;
            case 3:
                printf("Entrez la première lettre du titre :\n>");
                char t;
                scanf(" %c", &t);
                printf("--- Il y a %d manga dans les %c ---\n", nb_manga_titre(m, size, t), t);
                break;
            case 4:
                printf("Quel manga faut-il charcher ?\n>");
                char* titre = malloc(sizeof(char)*50);
                scanf(" %s", titre);
                float prix = price_of_manga(m, size, titre);
                if (prix == -1) {
                    printf("Aucun manga n'a ete trouve\n");
                }
                else {
                    printf("--- Le prix de ce manga est %f ---\n", prix);
                }
                break;
            case 5:
                print_manga(m, size);
                printf("Quels mangas faut-il ajouter ? (entrez les numéros a ajouter séparé par | exemple: 2|3|5)\n>");
                char* cart = malloc(sizeof(char)*50);
                scanf(" %s", cart);
                printf("La somme du panier est de %f", sum_cart(m, cart));
                break;
            default:
                printf("ERROR");
        }
    }
}

int main(void) {
    printf("Combien de mangas faut-il ajouter ?\n>");
    int nb;
    scanf("%d", &nb);
    Manga* m = add_manga(nb);

    menu(m, nb);

    return 0;
}