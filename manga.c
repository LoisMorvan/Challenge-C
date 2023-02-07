#include <stdio.h>
#include <stdlib.h>


typedef struct Manga {
    char titre[50];
    int age;
    float prix;
} Manga;

Manga* create_manga () {
    Manga* m = malloc(sizeof(Manga));

    printf("Saisir le titre du manga:\n> ");
    char c;
    while (scanf("%c", &c) == '\n') {
        printf("%c", c);
        getchar();
    }
    scanf("%[^\n]s", m->titre);
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
    Manga** m = malloc(sizeof(Manga)*n);
    
    for (int i = 0 ; i < n ; i++) {
        m[i] = create_manga();
    }

    return m;
}

void print_manga (Manga mt[], int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("\nTitre: %s\nAge: %d\nPrix: %.2f\n", mt[i].titre, mt[i].age, mt[i].prix);
    }
}

int main(void) {
    int n = 2;

    Manga* mt = add_manga(n);
    print_manga(mt, n);

    return 0;
}