#include <stdio.h>      // Pour les entrées/sorties
#include <stdlib.h>     // Pour les fonctions utilitaires (exit, etc.)
#include <string.h>     // Pour la manipulation de chaînes (strcmp, strcpy)

// Définition d'une structure pour représenter un étudiant
struct Etudiant {
    int id;                         // Identifiant de l'étudiant
    char nom[50];                   // Nom de l'étudiant
    float moyenne;                  // Moyenne de l'étudiant
};

// Déclaration d'un tableau de structures pour stocker les étudiants
struct Etudiant liste[100];         // Tableau pour stocker jusqu'à 100 étudiants
int nombre = 0;                     // Nombre actuel d'étudiants dans le tableau

// Fonction pour ajouter un étudiant
void ajouterEtudiant() {
    printf("Entrer l'ID de l'étudiant : ");
    scanf("%d", &liste[nombre].id);      // Saisie de l'ID

    printf("Entrer le nom de l'étudiant : ");
    scanf("%s", liste[nombre].nom);      // Saisie du nom (sans espaces)

    printf("Entrer la moyenne : ");
    scanf("%f", &liste[nombre].moyenne); // Saisie de la moyenne

    nombre++;     // Incrémente le nombre d'étudiants
    printf("Étudiant ajouté avec succès !\n");
}

// Fonction pour afficher tous les étudiants
void afficherEtudiants() {
    printf("\nListe des étudiants :\n");
    for (int i = 0; i < nombre; i++) {
        // Affiche les informations de chaque étudiant
        printf("ID: %d | Nom: %s | Moyenne: %.2f\n", liste[i].id, liste[i].nom, liste[i].moyenne);
    }
}

// Fonction pour trier les étudiants par moyenne (ordre décroissant)
void trierEtudiants() {
    struct Etudiant temp;   // Variable temporaire pour l'échange

    for (int i = 0; i < nombre - 1; i++) {
        for (int j = i + 1; j < nombre; j++) {
            if (liste[i].moyenne < liste[j].moyenne) {
                // Échange les éléments si l'étudiant j a une meilleure moyenne
                temp = liste[i];
                liste[i] = liste[j];
                liste[j] = temp;
            }
        }
    }
    printf("Tri effectué par moyenne décroissante.\n");
}

// Fonction pour sauvegarder les données dans un fichier texte
void sauvegarderFichier() {
    FILE *fichier = fopen("etudiants.txt", "w");  // Ouvre un fichier en écriture

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < nombre; i++) {
        // Écrit les données de chaque étudiant dans le fichier
        fprintf(fichier, "%d %s %.2f\n", liste[i].id, liste[i].nom, liste[i].moyenne);
    }

    fclose(fichier);   // Ferme le fichier
    printf("Données sauvegardées dans etudiants.txt\n");
}

// Fonction principale
int main() {
    int choix;   // Variable pour stocker le choix de l'utilisateur

    do {
        // Affiche le menu
        printf("\n--- MENU ---\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Afficher les étudiants\n");
        printf("3. Trier par moyenne\n");
        printf("4. Sauvegarder dans un fichier\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);   // Lecture du choix

        // Exécute une action selon le choix
        switch (choix) {
            case 1: ajouterEtudiant(); break;
            case 2: afficherEtudiants(); break;
            case 3: trierEtudiants(); break;
            case 4: sauvegarderFichier(); break;
            case 5: printf("Au revoir !\n"); break;
            default: printf("Choix invalide.\n");
        }

    } while (choix != 5);  // Continue tant que l'utilisateur ne choisit pas de quitter

    return 0;   // Fin normale du programme
}
