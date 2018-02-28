/*
 * mallocTeste.c
 *
 *  Created on: 22 de fev de 2018
 *      Author: ormel
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




FILE *arq, *arq2;


int main(){

//char c;
arq = fopen("vetor.txt", "r+");

if(arq == NULL)
    {
        perror("Erro: fopen");
        exit(EXIT_FAILURE);
    }

	printf("Início do programa\n");


		// char *buffer = (char*) malloc (sizeof(char) * 100);
    char buffer[100];
		char ch[3] = "};";

	    /* we read each line using fgets */

		int cont = 0;
    int  commaCont = 0;
    char *bufferAux = (char*) malloc (strlen(buffer));

	    while (fgets(buffer, sizeof(buffer), arq) != NULL) {

          for(unsigned int index = 0; index < strlen(buffer); index++){
                if(buffer[index] == ',')
                    commaCont++;
            }


	        /* write each line from file to stdout */

	    	char *aux = strstr(buffer, ch);
        char *charAux;

        // char *bufferSaida = (char*) malloc(strlen(buffer));

    if(aux){

      // printf("String Entrando:\n %s", bufferAux);
      /* Aqui é onde a mágica acontece.
          Nesse if, o programa irá analisar a linha obtida, formatar para
          um padrão determinado e armazenar os dados em um arquivo.

          A formatação deve ser configurada manualmente pelo usuário.

      */
          //Essa linha e a próxima é uma gambiarra pra pegar o "};"
          bufferAux = (char*) realloc(bufferAux, strlen(bufferAux) + strlen(buffer) + 4);
          // char *teste = buffer;
          // char teste2[] = teste;
          char teste[50];

          int number = 0;

          for(unsigned int index = 0; index < strlen(buffer); index++){
              if(buffer[index] == ';'){
                  buffer[index] = ',';
                  number = index;

                  printf("NUMBER: %d", number);
                }

          }

          if(fgets(teste, 50, arq) == NULL){
                printf("AAAAAAAAAAAAAA");
                printf("NUMBER: %d", number);
                // if(buffer[number] == ';'){
                    buffer[number] = '}';
                    strcat(buffer,";");
          //       // break;
        }

          strcat(bufferAux, buffer);

          // aux = strchr(buffer, ';');
          // printf("PRINTANDO TESTE: %s", teste);
          // *aux = 0;
          // strcat(bufferAux, buffer);

          // if(fgets(char *var, sizeof(buffer), arq) != NULL)
          // strcat(bufferAux, "},\n");
          // char *teste = strchr(bufferAux, '{');



          // printf("String Entrando:\n %s", teste);

            //Essa linha é onde eve ser configurada a formatação do novo arquivo.
            //Nesta configuração, cada linha saíra com o cabeçalho matriz[lin][col] =
            char *concatenada;

            if((cont -  1) == 0){
              const char* textoAux = "matriz[][] = ";

              char *texto = (char*) malloc (strlen(textoAux) + sizeof(int)*2);

                    // Essa linha pode não ser necessária dependendo do tipo de formatação desejada
                    sprintf(texto, "matriz[][%d] = {", commaCont + 1);

            concatenada = (char*) malloc (strlen(texto) + strlen(bufferAux) + 1);
            strcpy(concatenada,texto);
            strcat(concatenada,strchr(bufferAux, '{'));
            free(texto);
                texto = NULL;
            }

            else if ((cont - 1) > 0){

              concatenada = (char*) malloc (strlen(bufferAux) + 1);
              strcpy(concatenada,strchr(bufferAux, '{'));

              }//Concatenações para formatação da nova frase





              free(bufferAux);
                  bufferAux = NULL;




        //Após formatado, é hora de apagar qualquer espaço em branco ou tab existente.
        /*
          Após esse processo, o arquivo terá a forma matriz[lin][col] = {a,b,c,...};

          Independente da formatação escolhida, a seguinte manipulação irá deixar
          os dados na forma {a,b,c,...}. Não se deve alterar essa forma
        */
        char *bufferSaida = (char*) malloc(strlen(concatenada));

        // free(concatenada);

          bufferSaida[0] = 0;
        // char *token = strtok(buffer, "	");
          int controle = 0;
          char *token = strtok(concatenada, "			\t");
        // strcpy(bufferSaida,token);

          controle = 1;

          while(token != NULL){
              // printf("%s", token);
            // printf("%c", teste[i++]);
            if(controle > 0)
              strcat(bufferSaida, token);
              token = strtok(NULL, "			\t");

        }



        printf("String:\n %s", bufferSaida);

        arq2 = fopen("vetorHUE3.txt", "a");

        // fputs(buffer,arq2);
        fputs(bufferSaida,arq2);
        // fprintf(arq2, "%s\n",bufferSaida);


        fclose(arq2);







        /*Código aqui*/

        // cont = 0;
        commaCont = 0;
        bufferAux = (char*) malloc (strlen(buffer));
        free(concatenada);
        free(bufferSaida);


    }



	  if(!aux){

	    		char *newLine = strchr(buffer,'\n');

              if(newLine){
    	    			    *newLine = 0;

    	    		       }


            //
            // bufferSaida[0] = 0;
            // // char *token = strtok(buffer, "	");
            // int controle = 0;
            // char *token = strtok(buffer, "			\t");
            // // strcpy(bufferSaida,token);
            //
            // controle = 1;
            //
            //       while(token != NULL){
            //           // printf("%s", token);
            //                 // printf("%c", teste[i++]);
            //                 if(controle > 0)
            //                   strcat(bufferSaida, token);
            //                   token = strtok(NULL, "			\t");
            //
            //             }
            //         int commaCont = 0;
            //         for(unsigned int index = 0; index < strlen(bufferSaida); index++){
            //                 if(bufferSaida[index] == ',')
            //                     commaCont = commaCont + 1;
            //         }
            //
            //


            charAux = strchr(buffer, '{');



          if(charAux){




            printf("charAux:\n %s", charAux);
          //
             // char *pointer =  &buffer[0];
             // char *pointer2 = charAux;
             //---------------- Bloco Importante - Início --------------------
             /*
             const char* textoAux = "matriz[][] = ";

             char *texto = (char*) malloc (strlen(textoAux) + sizeof(int)*2);

             sprintf(texto, "matriz[%d][%d] = ", cont, cont+5);

             char *concatenada = (char*) malloc (strlen(texto) + strlen(charAux) + 1);


             strcpy(concatenada,texto);
             strcat(concatenada,charAux);
             strcpy(buffer, concatenada);

             free(texto);
             free(concatenada);
             //---------------- Bloco Importante - Fim --------------------
             */
             // printf("Buffer concatenado:\n %s\n", buffer);

            //  printf("pointer = %p", &buffer[0]);
            //  printf(" pointer2 = %p\n", pointer);
            //  printf("Diff: %ld\n", pointer2 - pointer);
            // //  printf("Buffer[0]: %s ",pointer );
            //  printf("Pointer2*: %s\n", pointer2);
            //
            // printf("Entrando no FOR:\n");

            //---- Começo

            /*Pedaço meio inútil, porque pega o que vem antes do caractere '{'.
             A ideia era apagar o que vem antes e substituir por algo novo,
             mas existem maneiras mais eficientes de se fazer isso, usando concatenação
             de strings. */

          /*
            char *auxChar2 = (char*) malloc (sizeof(char) * (pointer2 - pointer));

            for(int index = 0; index < (pointer2 - pointer); index++){
                printf("%c", buffer[index]);

                auxChar2[index] = buffer[index];

                // printf("")

              }

            free(auxChar2);
          */

           //------Fim
            printf("\n");




            cont++;

          }


        if(cont > 0)
              bufferAux = (char*) realloc (bufferAux, strlen(bufferAux) + strlen(buffer) + 1);

          if(cont == 0 && charAux != NULL)
              strcat(bufferAux, charAux);
          else
              strcat(bufferAux, buffer);








      // printf("\n");
	   }






        // free(bufferSaida);









        // printf("%s\n", buffer );
        // printf("%s", bufferSaida);

        // arq2 = fopen("vetorHUE.txt", "a");
        //
        // // fputs(buffer,arq2);
        // fputs(buffer,arq2);
        // // fprintf(arq2, "%s\n",bufferSaida);
        //
        //
        // fclose(arq2);

        // free(bufferSaida);










         //




	    }

	    printf("Cont: %d", cont);

       fclose(arq);

	  printf("Done");
		return 0;





}
