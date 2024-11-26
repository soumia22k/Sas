#include <stdio.h>


typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct{
    char titre[8];
    char des[11];
    Date date;
    int priorite;
}Tache ;

Tache tch [20];
int nmbr=0 ;

void afficher(){
    if(nmbr==0 ){
        printf("aucun Tache ! \n");
        return;
    }

    for(int i=0;i<nmbr;i++){
    printf("tache:%d \n",i+1);
    printf("le titre : %s \n  ", tch[i].titre);
    printf("des   : %s \n", tch[i].des);
    printf("date : %d/ %d/%d \n ",tch[i].date.jour ,tch[i].date.mois, tch[i].date.annee);
    if (tch[i].priorite==1){
        printf("Prioriter: high:\n");
        
    }else if(tch[i].priorite==2){
        
        printf("Prioriter: low:\n");
    }
    else{
        printf("aucun priorite requis:\n");
    }
}
}
   int validateDate(int jour , int mois , int annee){
         if(annee< 2023 || annee> 2026){
        return 0; }
          if(mois<1 || mois>12){
                  return 0;
              
          }
    if ( jour<1 || jour>31){
          return 0; }
   
    return 1;
}
 
void ajouter() {
    int validepriorite;
    printf("Ajouter les informations de la tache:\n");
    printf("Ajouter le titre: ");
    scanf("%s", tch[nmbr].titre);
    printf("Ajouter la description: ");
    scanf("%s", tch[nmbr].des);

    do {
        printf("Ajouter la date (jour/mois/annee): ");
        scanf("%d %d %d", &tch[nmbr].date.jour, &tch[nmbr].date.mois, &tch[nmbr].date.annee);
        if (!validateDate(tch[nmbr].date.jour, tch[nmbr].date.mois, tch[nmbr].date.annee)) {
            printf("Date invalide, reessayez!\n");
        }
    } while (!validateDate(tch[nmbr].date.jour, tch[nmbr].date.mois, tch[nmbr].date.annee));

    do {
        printf("Ajouter la priorite (1 High, 2  low): ");
        scanf("%d", &tch[nmbr].priorite);
        if (tch[nmbr].priorite == 1 || tch[nmbr].priorite == 2) {
            validepriorite = 1;
        } else {
            printf("Priorité invalide, réessayez.\n");
        }
    } while (!validepriorite);

    nmbr++;
}


void modifier(int index){
    if(index<0 || index>=nmbr){
        printf("impossible de modifier !!");
    }else{
        printf("mise à jour des informations!:%d\n",index+1);
        printf("entrer le nouveau titre:\n");
        scanf("%s",tch[index].titre);
        printf("entrer la nouvelle description:\n");
        scanf("%s",tch[index].des);
        printf("entrer la nouvelle date:\n" );
        scanf("%d %d %d",&tch[index].date.jour,&tch[index].date.mois,&tch[index].date.annee) ;   
        printf("entrer la nouvelle prioriter:\n");
        scanf("%d",&tch[index].priorite);

    }
     }

   
void supprimer(int index ){
    if (index<0 || index>=nmbr){
        printf("impossible de supprimer!\n");
    }else {
        for(int i=index ;i<nmbr;i++){
            nmbr--;
            printf("tache supprimer!\n");
        }
    }
}

void filtrage(int recherche){
    int trouve=0;
    printf("la propriter des taches:\n");
    if(recherche==1){
        printf("la priorite est high:\n");
    }else if(recherche==2){
        printf("la priorite est low:\n");
    }
    else{
        printf("aucun priorite requis:\n");
    }
    for(int i=0; i<nmbr; i++){
    	
        if(tch[i].priorite==recherche){
        printf("tache:%d \n",i+1);
        printf("le titre : %s \n  ", tch[i].titre);
        printf("des   : %s \n", tch[i].des);
        printf("date : %d/ %d/%d \n ",tch[i].date.jour ,tch[i].date.mois, tch[i].date.annee);
        trouve=1;
    }   
       if (!trouve){
           printf("aucun priorite trouver!!!\n");
       }
}
    
}



int main()
{ 
    int choix ;
    int index;
    int priorite;
    do{
        printf("Menu:\n");
        printf("1-ajouter:\n");
        printf("2-afficher:\n");
        printf("3-supprimer:\n");
        printf("4-modifier:\n");
        printf("5-filtrage:\n");
        printf("entrer votre choix:\n");
        scanf("%d",&choix);

        switch(choix){
            case 1:ajouter();
            break; 
            case 2:afficher();
            break;
            case 3:
            printf("entrer l'index de tache:\n");
            scanf("%d",&index);
			supprimer(index);
            break;
            case 4:
            printf("entrer l'index de tache:\n");
            scanf("%d",&index);
			modifier(index);
            break;
            case 5:
            printf("entrer la priorité:\n");
            scanf("%d",&priorite);
            filtrage(priorite);
            break;
            default: printf("le choix invalide \n");
            break;
        }
    }
while(choix!=   5);
    return 0;
}
