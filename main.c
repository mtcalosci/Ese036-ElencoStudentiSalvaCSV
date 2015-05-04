#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30
#define FNAME "elenco.csv"

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    FILE *puntaFile;
    int i;
    studente elenco [N];
    
    puntaFile = fopen(FNAME,"w");
    if(puntaFile == NULL) {
        fprintf(stderr, "Errore durante l'apertura del file\n");
    }
   
    printf("Inserisci i dati relativi a %d studenti ! \n",N);
    
    fprintf(puntaFile,"NOME; COGNOME; ETA'; CLASSE;\n"); 
    for(i = 0; i < N; i++) {
        printf("Inserisci il nome del %d° alunno: ", i + 1);
        scanf("%s", elenco[i].nome);
        printf("Inserisci il cognome del %d° alunno: ",i + 1);
        scanf("%s", elenco[i].cognome);
        printf("Inserisci l'eta' del %d° alunno: ",i + 1);
        scanf("%d", &(elenco[i].eta));
        printf("Inserisci la classe del %d° alunno: ",i + 1);
        scanf("%s", elenco[i].classe);
        
        fprintf(puntaFile, "%s; %s; %d; %s;\n", elenco[i].nome, elenco[i].cognome, elenco[i].eta, elenco[i].classe);
    } 
    fclose(puntaFile);
    
    return (EXIT_SUCCESS);
}