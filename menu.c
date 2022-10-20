#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

typedef struct {
  char codice[6];
  char nome[8];
  char cognome[8];
  float stipendio;
}
persone;

void inserimento(persone user, FILE *fp, int count);
void stampa(persone user, FILE *fp, int count);
void ricerca(persone user, FILE *fp, int count)

int main() {
  FILE * fp;
  persone user;
  int i;
  int sc;
  int count = 0;
  bool rt = false;
  while (rt != true) {
    printf("\n1-Inserire utente nella lista");
    printf("\n2-Visualizza il file");
    printf("\n3-Ricerca Utente");
    printf("\n4-Esci dal programma");
    printf("\n----->");
    scanf("%d", & sc);
    switch (sc) {
    case 1:
     

      inserimento(user, fp, count);

      count++;

      break;

    case 2:
    	
    	 stampa(user, fp, count);

      break;

    case 3:

      break;
    case 4:
   exit (1);
    break;
    }
  }

}

void inserimento(persone user, FILE *fp, int count) {
  int controllo=0;
  fp = fopen("utenti.txt", "wb");

  while(controllo!=1)
  {
    printf("\nInserisci il nome del utente:");
    scanf("%s",user.nome);
    printf("\nInserisci il cognome del utente:");
    scanf("%s",user.cognome);
    
    printf("\nInserisci lo stipendio:");
    scanf("%f",&user.stipendio);

    fwrite(user, sizeof(char),1,fp);

    printf("File (0=no,1=si)\n");
    scanf("%d",&controllo);
  }
  
  fclose(fp);
  return;
}

void stampa(persone user, FILE *fp, int count) {
	
	int control=1;
	fp=fopen("utenti.txt", "rb"); 
   while(control!=1)
  {
  printf("%s",user.nome);
  printf("\n");
  printf("%s",user.cognome);
  printf("\n");
  printf("%f",user.stipendio);
   }
   fclose(fp); 
		
}

void ricerca(persone user[], FILE *fp, int count) {
char nome;
char cognome;
int result1;
int result2;
int controllo3=1;
while((fread(&user),sizeof(char), 100, fp)>0){
	fp=fopen("utenti.txt", "rb"); 	
  printf("scrivi il Nome:");
  scanf("%s",nome);
 printf("scrivi il Cognome:");
  scanf("%s",cognome);
 result1 = strcmp(nome, user.nome);
 result2 = strcmp(cognome, user.cognome);
if((result1 ==  0)&&(result2 == 0))
{

printf("\nInserisci il nuovo nome del utente:");
  scanf("%s",user[].nome);
  fwrite(user[].nome, sizeof(char),1,fp);
  printf("\nInserisci il nuovo cognome del utente:");
  scanf("%s",user[].cognome);
  fwrite(user[].cognome, sizeof(char),1,fp);

}
}







    fclose(fp); 



}

