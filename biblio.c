#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100
#define MAX_TITRE 50

char titres[MAX_LIVRES][MAX_TITRE];
float prix[MAX_LIVRES];
int quantites[MAX_LIVRES];
char auteurs[MAX_LIVRES][MAX_TITRE];
int nombreLivres = 0;

int rechercherLivre(char titre[]) {
    int i;
    for (i = 0; i < nombreLivres; i++) {
        if (strcmp(titres[i], titre) == 0) {
            return i;
        }
    }
    return -1;
}

void ajouterLivre(char titre[], float prixLivre, int quantite, char auteur[]) {
    int i;
    i = nombreLivres;
    strcpy(titres[i], titre);
    prix[i] = prixLivre;
    quantites[i] = quantite;
    strcpy(auteurs[i], auteur);
    nombreLivres = nombreLivres + 1;
}

void afficherTous() {
    int i;
    for (i = 0; i < nombreLivres; i++) {
        printf("Livre %d:\n", i + 1);
        printf("Titre: %s\n", titres[i]);
        printf("Prix: %.2f\n", prix[i]);
        printf("Quantite: %d\n", quantites[i]);
        printf("Auteur: %s\n\n", auteurs[i]);
    }
}

void afficherLivre(char titre[]) {
    int index;
    index = rechercherLivre(titre);
    if (index != -1) {
        printf("Titre: %s\n", titres[index]);
        printf("Prix: %.2f\n", prix[index]);
        printf("Quantite: %d\n", quantites[index]);
        printf("Auteur: %s\n", auteurs[index]);
    } else {
        printf("Livre non trouvé\n");
    }
}

void supprimerLivre(char titre[]) {
    int index;
    index = rechercherLivre(titre);
    if (index != -1) {
        int i;
        for (i = index; i < nombreLivres - 1; i++) {
            strcpy(titres[i], titres[i + 1]);
            prix[i] = prix[i + 1];
            quantites[i] = quantites[i + 1];
            strcpy(auteurs[i], auteurs[i + 1]);
        }
        nombreLivres = nombreLivres - 1;
    } else {
        printf("Livre non trouvé\n");
    }
}

void modifierQuantite(char titre[], int nouvelleQuantite) {
    int index;
    index = rechercherLivre(titre);
    if (index != -1) {
        quantites[index] = nouvelleQuantite;
        printf("Quantite modifiée\n");
    } else {
        printf("Livre non trouvé\n");
    }
}

void afficherNombreTotalLivresEnStock() {
    int i;
    int total = 0;
    for (i = 0; i < nombreLivres; i++) {
        total = total + quantites[i];
    }
    printf("Nombre total de livres en stock: %d\n", total);
}

int main() {
    int choix;
    char titre[MAX_TITRE];
    float prixLivre;
    int quantite;
    char auteur[MAX_TITRE];

    do {
        printf("1. Afficher tous les livres\n");
        printf("2. Afficher un livre\n");
        printf("3. Ajouter un livre\n");
        printf("4. Supprimer un livre\n");
        printf("5. Modifier la quantite d'un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        getchar();

        if (choix == 1) {
            afficherTous();
        } else if (choix == 2) {
            printf("Titre du livre à afficher: ");
            fgets(titre, MAX_TITRE, stdin);
            titre[strcspn(titre, "\n")] = 0;
            afficherLivre(titre);
        } else if (choix == 3) {
            printf("Titre: ");
            fgets(titre, MAX_TITRE, stdin);
            titre[strcspn(titre, "\n")] = 0;
            printf("Prix: ");
            scanf("%f", &prixLivre);
            printf("Quantite: ");
            scanf("%d", &quantite);
            getchar();
            printf("Auteur: ");
            fgets(auteur, MAX_TITRE, stdin);
            auteur[strcspn(auteur, "\n")] = 0;
            ajouterLivre(titre, prixLivre, quantite, auteur);
        } else if (choix == 4) {
            printf("Titre du livre à supprimer: ");
            fgets(titre, MAX_TITRE, stdin);
            titre[strcspn(titre, "\n")] = 0;
            supprimerLivre(titre);
        } else if (choix == 5) {
            printf("Titre du livre pour modifier la quantite: ");
            fgets(titre, MAX_TITRE, stdin);
            titre[strcspn(titre, "\n")] = 0;
            printf("Nouvelle quantite: ");
            scanf("%d", &quantite);
            modifierQuantite(titre, quantite);
        } else if (choix == 6) {
            afficherNombreTotalLivresEnStock();
        } else if (choix == 7) {
            printf("Au revoir!\n");
        } else {
            printf("Choix invalide\n");
        }
    } while (choix != 7);

    return 0;
}
