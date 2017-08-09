/*###########################################################
# Autor: Thiago Henrique Felix                              #
# Version: 0.1                                              #
# Nome da aplcação: AnimationTOP                            #
# Objetivo: Criar uma simples animação                      #                                                      
#############################################################*/


#include<stdio.h>



int anicarCUB(int time){

int realTime = 0;

while(realTime < time){

printf("\t.");

sleep(1);

printf(" .");

sleep(1);

printf("\n");

printf("\t.");

sleep(1);

printf(" .");


sleep(1);

system("clear");

realTime++;

}//While



}//ANICARCUB


//XXX Animação Carregamento Eterno - anicarETR
int anicarETR(){



while(1){

 system("clear");
 
 printf("\n\n Carregando   ");
 
 sleep(1);
 
 system("clear");

 printf("\n\n Carregando . ");

 sleep(1);
 
 system("clear");

 printf("\n\n Carregando . . ");

 sleep(1);

 system("clear");

 printf("\n\n Carregando . . . ");

 sleep(1);

}//While

return 1;

}//ANICAR




