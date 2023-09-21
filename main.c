#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} date;

typedef struct
{
    int identifiant;
    char titre[100];
    char description[800];
    date deadline;
    char status[100];
} tache;

int taille = 0;

void ajoutertache(tache m[])
{
    printf("Entrez le titre de la tâche : ");
    getchar();
    fgets(m[taille].titre, 100, stdin);

    printf("Entrez la description de la tâche : ");
    fgets(m[taille].description, 800, stdin);

    printf("Entrez votre deadline : \n");

    printf("Jour : ");
    scanf("%d", &m[taille].deadline.jour);

    printf("Mois : ");
    scanf("%d", &m[taille].deadline.mois);

    printf("Année : ");
    scanf("%d", &m[taille].deadline.annee);

    printf("Entrez le statut de la tâche : ");
    getchar();
    fgets(m[taille].status, 100, stdin);

    if (taille == 0)
    {
        m[taille].identifiant = 200;
    }
    else
    {
        m[taille].identifiant = m[taille - 1].identifiant + 1;
    }

    taille++;
}

void ajouterplusieurtache(tache m[])
{
    int nbr;
    printf("Entrez le nombre de tâches à ajouter : ");
    scanf("%d", &nbr);

    for (int i = 0; i < nbr; i++)
    {
        ajoutertache(m);
    }
}

void affiche_trialphabet(tache m[], int n)
{
    for (int i = 1; i < n; i++)
    {
        tache cmd = m[i];
        int j = i - 1;

        while (strcmp(cmd.titre, m[j].titre) < 0 && j >= 0)
        {
            m[j + 1] = m[j];
            j--;
        }

        m[j + 1] = cmd;
    }
}

void affich(tache m[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Identifiant : %d\n", m[i].identifiant);
        printf("Titre de la tâche : %s", m[i].titre);
        printf("Description : %s", m[i].description);
        printf("Deadline : %d/%d/%d\n", m[i].deadline.jour, m[i].deadline.mois, m[i].deadline.annee);
        printf("Statut : %s\n", m[i].status);
        printf("-----------------------------\n");
    }
}

void trierParDeadline(tache m[], int n)
{
    for (int i = 1; i < n; i++)
    {
        tache tacheCourante = m[i];
        int j = i - 1;

        int dateCourante = tacheCourante.deadline.annee * 10000 + tacheCourante.deadline.mois * 100 + tacheCourante.deadline.jour;

        while (j >= 0 && (m[j].deadline.annee * 10000 + m[j].deadline.mois * 100 + m[j].deadline.jour) > dateCourante)
        {
            m[j + 1] = m[j];
            j--;
        }

        m[j + 1] = tacheCourante;
    }
}

void affichdeadline3day(tache m[], int n)
{
    int jouractuel, moisactuel, anneeactuel;

    printf("Entrez la date actuelle\n");
    printf("Jour : ");
    scanf("%d", &jouractuel);

    printf("Mois : ");
    scanf("%d", &moisactuel);

    printf("Année : ");
    scanf("%d", &anneeactuel);

    for (int i = 0; i < n; i++)
    {
        if (m[i].deadline.annee == anneeactuel && m[i].deadline.mois == moisactuel && ((jouractuel - m[i].deadline.jour) <= 3))
        {
            printf("Identifiant : %d\n", m[i].identifiant);
            printf("Titre : %s", m[i].titre);
            printf("Description : %s", m[i].description);
            printf("Deadline : %d/%d/%d\n", m[i].deadline.jour, m[i].deadline.mois, m[i].deadline.annee);
            printf("Statut : %s\n", m[i].status);
            printf("-----------------------------\n");
        }
    }
}

int main()
{
    tache M[100];

    ajouterplusieurtache(M);


    system("cls");

    printf("\nTâches avec deadline dans les 3 prochains jours:\n");
    affichdeadline3day(M, taille);


    trierParDeadline(M, taille);

    printf("Liste triée par deadline:\n");
    affich(M, taille);

    return 0;
}
