/*##############################################################
#                                                              #
#  Criado por: Thiago Henrique Felix                           #
#  Version: 0.1.2 Development                                  #
#  Nome da aplicação: MobCript                                 #
#  Obs: Not                                                    #
#                                                              #
#  A atual aplicação tem como objetivo receber uma mensagem,   #
#  criptografar e retornar ao cliente a mensagem criptografada.#
#                                                              #
################################################################*/

/*##############################################################
#                                                              #
# Version 0.1 : Primeira versão da aplicação, foi criado a     #
# criprografia simples de um vetor de caracter aceitando       #
# somente 10 caracteres.                                       #
#                                                              #
# Version 0.1.1 : Segunda versão da aplicação.                 #
# * A mensagem de aviso no momento de criptografia foi         #
#   modificado de lugar.                                       #
# * Foi modificado o algoritimo de identificação de caracter   #
#    fora do alfabeto. Obs: Ainda não funciona.                #
#                                                              #
# Version 0.1.2 : Terceira versão da aplicação.                #
# * A variavel de detecção do caracter diferente do alfabeto   #
# que não funcionava foi retirada.                             #
#                                                              #
# * Adicionado a biblioteca ctype.                             #
#                                                              #
# * Adicionado a função isalpha da biblioteca ctype, para a    #
# detecção do caracter não presente no alfabeto.               #
#                                                              #
#                                                              #
#                                                              #
#                                                              #
################################################################*/


// XXX Cabeçario
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

// XXX Variaveis globais
char mensagem[10];
int key;
FILE *arq;


int main(int argc, char *argv[]){

 setlocale(LC_ALL,"portuguese");

 system("clear");

 //XXX log
 arq = fopen("logFile.txt","a");
 fprintf(arq,"\n====================================================================================\n Aplicação executada em %s , Horario: %s .",__DATE__,__TIME__);

 printf("\n ---------------------------------------------------------------- \n O atual programa tem como objetivo receber uma mensagem, \n criptografar e retornar ao usuário a mensagem criptografada. \n Algoritimo: Criptografia de substituição  \n ---------------------------------------------------------------- \n");

 printf("\n ------------------------------------------------------- \n \t\t ATENÇÃO \n A atual aplicaçao aceita somente 10 caracteres. \n ------------------------------------------------------- \n");


 printf("\n Insira a mensagem a ser criptografada: "); gets(mensagem);

 //XXX Log
 fprintf(arq,"\n\n Mensagem clara: %s \n",mensagem);

 printf("\n ------------------------------------------------------- \n \t\t ATENÇÃO \n Não esqueça a chave, pois sem ela não será possivel \n descriptografar a mensagem.\n ------------------------------------------------------- \n");

 printf("\n Insira a chave da criptografia: "); scanf("%i",&key);

 //XXX Log
 fprintf(arq," Chave de criptografia: %i \n",key);

 // FIXME Fazer carregamento enquanto faz a criptografia da mensagem.

 // XXX Chamada ao metodo responsavel por criptografar a menssagem propriamente dita.
 int retorno = algoritimo();

 if(retorno == 1){

  printf("\n\n ----------------------------------------------------------- \n \t Criptografia finalizada com sucesso. \n\n");

  }//IF


//XXX Log
fprintf(arq," Mensagem criptografada: %s \n\n",mensagem);

fprintf(arq,"\n====================================================================================\n");

close(arq);

}//Main


// XXX Função responsavel por executar o algoritimo na mensagem recebida com a chave fornecida
int algoritimo(void){

 // XXX Variaveis locais
 char alfabeto[52] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R','S','T', 'U','V', 'W', 'X', 'Y',   'Z','a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s','t', 'u','v', 'w', 'x', 'y', 'z'};
 int verifica = 0; // XXX Variavel usada para verificar se um caracter ainda não entrou no for

printf("\n Criptografando a mensagem . . . . \n ");


// XXX For destinado a cada caracter da mensagem =D
for(int i=0;i<10;i++){

   for(int j=0;j<52;j++){
                                       //XXX Detecção de caracter diferente do alfabeto
     if(!isalpha(mensagem[i]))
     {

       // TODO O caracter deve ser escolhido com base em um algoritimo
       mensagem[i] = '-';

      break;

     }//IF


     else
     {
        // XXX Comparo o caracter atual da mensagem com todas as letras do alfabeto
        if(mensagem[i] == alfabeto[j])
        {

          mensagem[i] = alfabeto[(j+key)];

          break;

        }//IF

     }//Else

  }//For interno


}//For externo


 printf("\n\n ####### ---> Mensagem criptografada <--- ####### \n\n");

 printf("\n %s \n\n",mensagem);


return 1;


}//ALGORITIMO
