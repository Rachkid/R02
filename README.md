# Student Manager - Projet C

**Student Manager** est une application en ligne de commande développée en langage **C**, qui permet de gérer une liste d'étudiants à l'aide de structures et de fichiers.  
Elle offre des fonctionnalités telles que : l’ajout, l’affichage, le tri des étudiants par moyenne, et la sauvegarde des données dans un fichier texte.

---

## Fonctionnalités

- **Ajouter un étudiant** : saisie de l’ID, du nom, et de la moyenne.
- **Afficher les étudiants** : liste tous les étudiants ajoutés.
- **Trier les étudiants** : tri par moyenne décroissante.
- **Sauvegarder dans un fichier** : enregistre les données dans `etudiants.txt`.
- **Interface interactive** : menu simple en ligne de commande.

---

## Technologies utilisées

- Langage C
- Structures (`struct`)
- Tableaux
- Fichiers (`fopen`, `fprintf`, `fclose`)
- Interface CLI (Command Line Interface)

---

## Fichiers du projet

| Fichier            | Description                                       |
|--------------------|---------------------------------------------------|
| `student_manager.c`| Code source principal du programme                |
| `etudiants.txt`    | Fichier généré contenant les données sauvegardées |
| `README.md`        | Documentation du projet                           |

---

## Compilation et exécution

### Prérequis :
- Un compilateur C comme `gcc`

### Compilation :
```bash
gcc student_manager.c -o student_manager
