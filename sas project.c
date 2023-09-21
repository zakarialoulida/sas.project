#include <stdio.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    int identifiant;
    char titre[100];
    char description[800];
    date deadline;
    char status[100];
} tache;

int taille = 0;

void ajoutertache(tache m[]) {
    printf("Entrez le titre de la tache : ");
    getchar(); // Pour consommer le caractère de nouvelle ligne restant dans le tampon
    fgets(m[taille].titre, sizeof(m[taille].titre), stdin);

    printf("Entrez la description de la tache : ");
    fgets(m[taille].description, sizeof(m[taille].description), stdin);

    printf("Entrez la date limite (jour mois annee) : ");
    scanf("%d %d %d", &m[taille].deadline.jour, &m[taille].deadline.mois, &m[taille].deadline.annee);

    printf("Entrez le statut de la tache : ");
    getchar(); // Pour consommer le caractère de nouvelle ligne restant dans le tampon
    fgets(m[taille].status, sizeof(m[taille].status), stdin);

    if (taille == 0) {
        m[taille].identifiant = 200;
    } else {
        m[taille].identifiant = m[taille - 1].identifiant + 1;
    }

    taille++;
}

void affich(tache m) {
    printf("Identifiant : %d\n", m.identifiant);
    printf("Titre de la tache : %s", m.titre);
    printf("Description : %s", m.description);
    printf("Deadline : %d/%d/%d\n", m.deadline.jour, m.deadline.mois, m.deadline.annee);
    printf("Statut : %s\n", m.status);
    printf("-----------------------------\n");
}

void affichplus(tache m[], int n) {
    for (int i = 0; i < n; i++) {
        affich(m[i]);
    }
}

int supprimertacheparID(int id, tache m[]) {
    int index = -1;

    for (int i = 0; i < taille; i++) {
        if (m[i].identifiant == id) {
            index = i;
            break; // Sortez de la boucle dès que vous avez trouvé l'ID
        }
    }

    if (index != -1) {
        for (int i = index; i < taille - 1; i++) {
            m[i] = m[i + 1];
        }
        taille--;
    }

    return taille;
}

void rechercheparid(tache m[], int id) {
    for (int i = 0; i < taille; i++) {
        if (m[i].identifiant == id) {
            affich(m[i]);
        }
    }
}

int main() {
    tache M[100];

    int choix;

    while (1) {
        printf("Menu:\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Rechercher une tache par ID\n");
        printf("4. Supprimer une tache par ID\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajoutertache(M);
                break;
            case 2:
                printf("\nListe de toutes les taches :\n");
                affichplus(M, taille);
                break;
            case 3:
                printf("\nEntrez l'ID de la tache à rechercher : ");
                int id;
                scanf("%d", &id);
                rechercheparid(M, id);
                break;
            case 4:
                printf("\nEntrez l'ID de la tache à supprimer : ");
                int idASupprimer;
                scanf("%d", &idASupprimer);
                taille = supprimertacheparID(idASupprimer, M);
                break;
            case 5:
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}