#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED
#include "desenho.h"
#include "arquivos.h"

void checkstr(char *wor){ //funcao para checar se o input � uma palavra(ou seja, fomada s� com os digitos do alfabeto) e deixar a palavra totalmente em letra minuscula
    int i,a,l,k;
    k=1;
    while(k==1){//loop ate q o input seja uma palavra
        printf("\nDigite a palavra a ser adivinhada:");
        scanf("%s",wor);
        l=strlen(wor);
        k=1;
        i=0;
        for(i=0;i<l;i++){
            a=isalpha(*(wor+i));
            if(a==0){//checando se o character pertence ao alfabeto
                printf("Input invalido, digite a palavra novamente.\n");
                break;
        }
        else if(a==1){
            *(wor+i)=*(wor+i)+32;//transformando as letras maiusculas em minusculas
        }
        if(i==l-1){
            k=0;
        }

        }
    }




}
void checkchar(char *wor){//func q checa se o input � uma letra(ou seja, um string com strlen==1), e transforma em minusculo
    int i,a,l,k;
    k=1;
    while(k==1){
        printf("Digite a letra: ");
        //scanf("%s",wor);
        fgets(wor, 2, stdin);
        
        system("cls");
        
        l=strlen(wor);
        k=1;
        i=0;
        a=isalpha(*(wor));
        if(l!=1 || a==0){
            printf("Input invalido, digite a letra novamente.");
        }
        else{
            k=0;
            if(a==1){
                *wor=*wor+32;
            }
        }

    }




}

int Forca(char *word){
    char guess[50],erradas[7],certas[50],wordcop[50],chara[50];
    char letter;
    char alfa[]="abcdefghijklmnopqrstuvwxyz";
    int j,k,m,let,len,cont_errada,cont_cert,x,y;
    int modo;
    
    int pontos = 1000;

    len=strlen(word);

    strcpy(wordcop,word);

    strcpy(certas,word);

    cont_cert = 0;
    cont_errada = 0;


    for(k=0;k<len;k++){
        certas[k]='_';
    }

    desenharForca(0);

    j=0;
    y=0;

    while(cont_errada<7){

    	// Limpar o buffer de entrada antes de ler a palavra
    	while (getchar() != '\n');

        printf("\nEscolha o modo:\n 1-Chute direto\n 2-Letra por letra\n Modo:");
        scanf("%d", &modo);

        // Limpar o buffer de entrada antes de ler a palavra
    	while (getchar() != '\n');

        if(modo == 1){

            checkstr(guess);

            if(strcmp(wordcop,guess)==0){
                printf("\nVoce venceu!");
                pontos *= (len-(cont_cert+1)); //bonus por acertar direto
                printf("\tPontos: %d", pontos);
                return pontos;
            }
            else{
                printf("\nVoce perdeu... a palavra era %s",wordcop);
                pontos = 0;
                printf("\tPontos: %d", pontos);
                return 0;

            }
            return 0;
        }
        else if(modo == 2){
                checkchar(chara);
                letter=chara[0];
                let = letter-97;
                x=0;
                if(letter!=alfa[let]){
                    printf("\nLetra ja digitada.\n");
                }
                else{
                    alfa[let]='0';
                    for(j=0;j<len;j++){

                        if(letter==word[j]){
                            word[j]='0';
                            certas[j]=letter;
                            x+=1;
                        }
                        if (j==len-1){
                            if(x==0){
                                erradas[cont_errada]=letter;
                                printf("\nLetra errada\n");
                                cont_errada++;
                                pontos -= 100; //errou a letra
                            }
                            else{
                                cont_cert+=x;
                                printf("\nLetra certa\n");
                                pontos += 500; //acertou a letra
                            }
                        }
                        if(cont_cert==len){                           
                            pontos *= 2; //bonus de vitoria
							printf("\nVoce venceu!");
                            printf("\tPontos: %d", pontos);                     
                            return pontos;
                        }
                        else if(cont_errada==7){
                            printf("\nVoce perdeu... A palavra era: %s", wordcop);
                            printf("\tPontos: %d", pontos);
                            return pontos;
                        }


                    }
                    printf("\n");
                    desenharForca(cont_errada);
                    printf("\n");
                    printf("Ja adivinhado:");
                    for(y=0;y<len;y++){
                        printf("%c",certas[y]);
                    }
                    printf(" Erradas:");
                    for(y=0;y<cont_errada;y++){
                        printf("%c ",erradas[y]);
                    }
                    printf("\n");
        }
    }
    else{
        printf("Modo invalido, digite novamente.\n");
    }
    }
}

#endif
