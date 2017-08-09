/*#######################################################
  Criado por: Thiago Henrique Felix
  Version: 0.1
  Nome da aplicação: MobCript  
  Obs: Primeira versão da aplicação, criada na data 
  2016/12/07. 

  A atual aplicação tem como objetivo receber uma mensagem,
  criptografar e retornar ao cliente a mensagem criptada.
########################################################*/

// XXX Cabeçario
#include <stdio.h>
#include <string.h>
#include <locale.h> 

// XXX Variaveis globais 
char mensagem[10];
int key;

int main(int argc, char *argv[]){
 
 setlocale(LC_ALL,"portuguese");

 system("clear"); 
 
 printf("\n ---------------------------------------------------------------- \n O atual programa tem como objetivo receber uma mensagem, \n criptografar e retornar ao usuário a mensagem criptografada. \n Algoritimo: Criptografia de substituição  \n ---------------------------------------------------------------- \n"); 

 printf("\n ------------------------------------------------------- \n \t\t ATENÇÃO \n A atual aplicaçao aceita somente 10 caracteres. \n ------------------------------------------------------- \n"); 
  

 printf("\n Insira a mensagem a ser criptografada: "); gets(mensagem); 
 
 printf("\n ------------------------------------------------------- \n \t\t ATENÇÃO \n Não esqueça a chave, pois sem ela não será possivel \n descriptografar a mensagem.\n ------------------------------------------------------- \n"); 

 printf("\n Insira a chave da criptografia: "); scanf("%i",&key);

 printf("\n Criptografando a mensagem . . . . \n "); 

 
 // Apenas para verificação de log. =D
 printf("\n --------------> \n Mensagem; \n %s \n\n --------------> \n Key: %i \n\n",mensagem, key);

 // XXX Chamada ao metodo responsavel por criptografar a menssagem propriamente dita. 
 int retorno = algoritimo(); 
 
 if(retorno == 1){
 
  printf("\n\n ----------------------------------------------------------- \n \t Criptografia finalizada com sucesso. \n\n");
  
  }//IF

}//Main


// XXX Função responsavel por executar o algoritimo na mensagem recebida com a chave fornecida 
int algoritimo(void){
 
 // XXX Variaveis locais 
 char alfabeto[52] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R','S','T', 'U','V', 'W', 'X', 'Y', 'Z','a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s','t', 'u','v', 'w', 'x', 'y', 'z'}; 
 int verifica = 0; // XXX Variavel usada para verificar se um caracter ainda não entrou no for 
 
// TODO Todo algoritimo para realizar a criptografia deve ser feito aqui

// XXX For destinado a cada caracter da mensagem =D
for(int i=0;i<10;i++){
  
   for(int j=0;j<52;j++){
     
   
      // XXX Apenas para log
      //printf("\n Entrou no for interno, letra atual da mensagem: %c , do alfabeto: %c \n",mensagem[i],alfabeto[j]);   
 

     // XXX Comparo o caracter atual da mensagem com todas as letras do alfabeto
     if(mensagem[i] == alfabeto[j])
     {
           
        // XXX Troco o caracter atual pelo caracter a frente dele, a quantidade de caracter a frente dele é definido pela chave 
        mensagem[i] = alfabeto[(j+key)];
      
        // XXX Responsavel para verificação no else 
        verifica = 1;

        // XXX Após trocar o caracter, voltar ao loop externo      
        break;  

     }//IF

     else {

         // FIXME O objetivo atual não esta funcionando   
      
        // XXX Verifico se o caracter não foi enc ontrado no alfabeto caso 1 ele não foi encontrado  
        if(verifica == 1){

        mensagem[i] = '_';

        }//IF	
      
     }//ELSE
    

  }//For interno

 // XXX Reseta a variavel de verificação  
 verifica = 0;

}//For externo



 printf("\n\n ####### ---> Mensagem criptografada <--- ####### \n\n");
  
 printf("\n %s \n\n",mensagem); 




return 1; // XXX Será retornado 1 se a criptografia for finalizada com sucesso


}//ALGORITIMO


