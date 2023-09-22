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
    printf("Entrez le titre de la tache : ");
    scanf(" %[^\n]", m[taille].titre);

    printf("Entrez la description de la tache : ");
    scanf(" %[^\n]",m[taille].description);

    printf("Entrez votre deadline : \n");

    printf("sous forme (JJ/mm/annee) : ");
    scanf("%d/%d/%d", &m[taille].deadline.jour,&m[taille].deadline.mois,&m[taille].deadline.annee);

    printf("Entrez le statut de la tache : ");
    scanf(" %[^\n]",m[taille].status);

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
    printf("Entrez le nombre de taches  ajouter : ");
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
void affich(tache m)
{
        printf("Identifiant : %d\n", m.identifiant);
        printf("Titre de la tache : %s", m.titre);
        printf("Description : %s", m.description);
        printf("Deadline : %d/%d/%d\n", m.deadline.jour, m.deadline.mois, m.deadline.annee);
        printf("Statut : %s\n", m.status);
        printf("-----------------------------\n");

}

void affichplus(tache m[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Identifiant : %d\n", m[i].identifiant);
        printf("Titre de la tache : %s\n", m[i].titre);
        printf("Description : %s\n", m[i].description);
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

    printf("Annee : ");
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
int supprimertacheparID(int id,int taille,tache m[])
{

   int index=-1 ;

    for (int i = 0; i < taille; i++)
    {
        if(m[i].identifiant==id)
        {index=i;}
    }
    if(index!=-1)
    for(int i=index; i<taille-1; i++)
        {
            m[i]=m[i+1];
            break;                                    //Sortez de la boucle dès que vous avez trouvé l'ID
        }
        taille--;
return taille;
}
void rechercheparid(tache m[],int taille,int id)
{
for (int i = 0; i < taille; i++)
{
    if(m[i].identifiant==id)
    {
        affich (m[i]);

    }

}

}
void recherchepartitre(tache m[],int taille){
char rechtitre[100];
printf("entrer le titre a rechercher :");
scanf(" %[^\n]",rechtitre);
for (int i = 0; i < taille; i++)
{
    if(strcmp(m[i].titre,rechtitre)==0)
    {
        affich (m[i]);
    }

}

}



void modifierdescrip(tache m[], int taille, int identif) {
    int index = -1; // Initialisation de l'index à -1 pour vérifier si l'identifiant a été trouvé

    for (int i = 0; i < taille; i++) {
        if (m[i].identifiant == identif) {
            index = i; // Stocke l'index de l'élément correspondant à l'identifiant
            break; // Sort de la boucle une fois que l'identifiant est trouvé
        }
    }

    if (index != -1) { // Vérifie si l'identifiant a été trouvé
        char newdescrip[800];
        printf("Modifier la description : ");
        scanf(" %[^\n]", newdescrip);
        strcpy(m[index].description, newdescrip);
    } else {
        printf("Identifiant non trouvé.\n");
    }
}

void modifierdeadline(tache m[], int taille, int identif) {
    int index = -1;

    for (int i = 0; i < taille; i++) {
        if (m[i].identifiant == identif) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        int jour, mois, annee;
        printf("Donner la nouvelle date sous forme (JJ/MOIS/ANNEE) : ");
        scanf("%d/%d/%d", &jour, &mois, &annee);
        m[index].deadline.jour = jour;
        m[index].deadline.mois = mois;
        m[index].deadline.annee = annee;
    } else {
        printf("Identifiant non trouve.\n");
    }
}

void modifierstatus(tache m[], int taille, int identif) {
    int index = -1;

    for (int i = 0; i < taille; i++) {
        if (m[i].identifiant == identif) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        char status[100];
        printf("Modifier le statut (a realiser/en cours de realisation/finalisee) : ");
        scanf(" %[^\n]", status);
        strcpy(m[index].status, status);
    } else {
        printf("Identifiant non trouve.\n");
    }
}
void afficherNombreTotalTaches(Tache m[], int taille) {
    printf("Le nombre total de taches est : %d\n", taille);
}
void afficherNombreTachesCompletesEtIncompletes(Tache m[], int taille) {
    int complet = 0, incomplet = 0;

    for (int i = 0; i < taille; i++) {
        if (strcmp(m[i].status, "finalisee") == 0) {
            complet++;
        } else {
            incomplet++;
        }
    }

    printf("Nombre de taches completes : %d\n", complet);
    printf("Nombre de taches incompletes : %d\n", incomplet);
}



int main()
{
    tache M[100];

    ajouterplusieurtache(M);

   system("cls");
affichplus(M, taille);
 /*  printf("\nTaches avec deadline dans les 3 prochains jours:\n");
    affichdeadline3day(M, taille);


    trierParDeadline(M, taille);

    printf("Liste triee par deadline:\n");
    affichplus(M, taille);*/
int ident;
    printf("entrer id pour : ");
    scanf("%d",&ident);

   // recherchepartitre(M,taille);
//taille=supprimertacheparID(ident,taille,M);

rechercheparid(M,taille,ident);
modifierstatus(M,taille,ident);
modifierdeadline(M,taille,ident);
modifierdescrip(M,taille,ident);
affichplus(M, taille);

    return 0;
}
