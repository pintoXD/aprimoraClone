#include <stdio.h>
#include <stdlib.h>
#include <string.h>




FILE *arq;

void getDimension(FILE *arqAux, int *linPointer, int *colPointer){

          char buffer[2000];
          // char pattern[] = " ,{};=";
          char patternName[] = "<matriz[][]>";
              // char *buffer = (char*) malloc (sizeof(char)*100);

              printf("Tamanho: %ld\n", sizeof(buffer));
              int counter = 0;
              fseek(arq, 0, SEEK_END);
              char *tmp = (char*) malloc(sizeof(char) + 1);
              fgets(tmp, 70, arq);

              while(strstr(tmp, "<ma") == NULL){
                fseek(arq, counter, SEEK_END);
                fgets(tmp, 70, arq);

                counter = counter - 1;
              }

              fseek(arq, 0, SEEK_SET);
              // char* tmp = strstr(buffer, patternName);
              printf("TMP: %s\n", tmp);

                char *tmpAux = strtok(tmp, patternName);


              *linPointer = atoi(tmpAux);
              printf("tmpAux: %d\n", *linPointer);


              tmpAux = strtok(NULL, patternName);
              *colPointer = atoi(tmpAux);

              printf("tmpAux2: %d\n", *colPointer);


              free(tmp);

}


int main(){

    arq = fopen("vetorHUE3.txt", "r");

    if(arq == NULL)
        {
            perror("Erro: fopen");
            exit(EXIT_FAILURE);
        }

    int lin;
    int col;

    getDimension(arq, &lin, &col);

    // char buffer[2000];
    int matriz[lin][col];





      /*    while(fgets(buffer, sizeof(buffer), arq) != NULL){

              printf("Buffer: %s\n", buffer);
              char* token = strtok(buffer, pattern);

              char *teste = strstr(token, patternName);
                if(teste != NULL){

                      printf("Teste:\n%s\n", teste);
                }
      */

      /*        printf("Token is:\n%s\n", token);

              while(token != NULL){

                printf("%s\n",token);
                token = strtok(NULL, pattern);

              }
      */

      //}







}
