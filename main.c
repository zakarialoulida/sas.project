#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int taille=0;
typedef struct {
 int jour;
 int mois;
 int annee;
}date;
typedef struct {
int identifient;
char titre[100];
char description[800];
date deadline;
char status[100];
}tache;
void ajoutertache(tache m[]){

 printf("entre le titre de la tache : ");
 getchar();
 fgets(m[taille].titre,1000,stdin);
 printf("entre la description de la tache :");
 fgets(m[taille].description,100,stdin);
 printf("entre votre deadline : \n");
 
 printf("jour:");scanf("%d",&m[taille].deadline.jour);
printf("mois:");scanf("%d",&m[taille].deadline.mois);
printf("annee :");scanf("%d",&m[taille].deadline.annee);



 //scanf("%s",m[taille].status);
if(taille==0){
m[taille].identifient=200;}
else{
m[taille].identifient++;}
taille++; 

 }
 void ajouterplusieurtache(tache m[]){
int nbr;
printf("entrer nbr de tache a ajouter:");
scanf("%d",&nbr);
for (int i = 0; i < nbr; i++)
{
 ajoutertache(m);
 
}
 }
 void affiche_trialphabet(tache m[],int n){
  for(int i=1;i<n;i++){
    tache cmd=m[i];
    int j=i-1;
while(strcmp(cmd.titre, m[j].titre)<0 &&  j>=0){
    m[j+1]=m[j];
j--;
}
m[j+1]=cmd;
  }
  
 }
 void affich(tache m[]){
  for (int i = 0; i < taille; i++)
  {
    
  printf("your identifient: %d\n",m[i].identifient);

 printf("votre titre de la tache est: %s\n",m[i].titre);
 
 printf("sa description est  : %s\n",m[i].description);
 
 printf("votre deadlineest  est \n %d/%d/%d,",m[i].deadline.jour,m[i].deadline.mois,m[i].deadline.annee);
 


  }
  
  
 }
 int main()
{ 
tache M[100];

  ajouterplusieurtache(M);
  //system("cls");
  //affich(M);
  affiche_trialphabet(M,taille);
  affich(M);


    return 0;
}
