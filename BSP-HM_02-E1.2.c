/*
* Operacoes matematicas
* =============================================================
* Escrito por: Eliane Chen Dahab

* Esse programa simula uma maquina que realiza operacoes matematicas.
* O usuario deve inserir dois numeros reais.
* O programa oferece ao usuario 6 operacoes para escolher.
* Sao 5 operacoes matematicas e 1 operacao finaliza o programa.
* As operacoes matematicas sao realizadas entre os dois numeros reais inseridos pelo usuario.
* O programa retorna o valor do resultado da operacao escolhida pelo usuario.
* Os resultados possuem 3 casas decimais.
* 
* Input: 3.985 e 2.016, depois selecione a operacao 3.
* Output: A multiplicacao dos dois numeros eh 8.034. 
*/
//----------------------------include section---------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//------------------------prototypes section----------------------------
void comando(int operador, float num1, float num2);

//-------------------------main section-------------------------------
int main()
{
    float num1, num2; //dois numeros reais do usuario
    int operador; //o digito para o comando
    char opc;
    
    setlocale(LC_ALL, "Portuguese"); 
    
    do
    {
        printf("\n");
        printf("CALCULADORA \n");
        printf("\n");
        printf("Digite dois numeros: \n");
        scanf("%f%f", &num1, &num2);
        printf("Escolha a operacao desejada: \n");
        printf("Digite 1 para soma. \n");
        printf("Digite 2 para subtracao. \n");
        printf("Digite 3 para multiplicacao. \n");
        printf("Digite 4 para divisao. \n");
        printf("Digite 5 para potenciacao. \n");
        scanf("%d", &operador);
        comando(operador, num1, num2); //chamando a funcao void dentro do main
        printf("Deseja repetir a operacao? Se sim, digite s ou S. \n");
        printf("Se nao deseja repetir a operacao, digite 6 para finalizar. \n");
    	scanf(" %c", &opc);
    } 
    while (opc == 'S' || opc == 's');
    
    printf("Operacao finalizada. \n");
    return 0;
}
//---------------------------------------------------------------
void comando(int operador, float num1, float num2)
{
    float soma, subt, mult, divisao, pot;
    
    switch(operador)
    {
        case 1: soma = num1 + num2;
            printf("A soma dos dois numeros e %.3f. \n", soma);
            break;
            
        case 2: subt = num1 - num2;
            printf("A subtracao dos dois numeros e %.3f. \n", subt);
            break;
            
        case 3: mult = num1 * num2;
            printf("A multiplicacao dos dois numeros e %.3f. \n", mult);
            break;
            
        case 4: divisao = num1 / num2;
            printf("A divisao dos dois numeros e %.3f. \n", divisao);
            break;
            
        case 5: pot = pow(num1, num2); //realiza a potenciacao do num1 com o expoente num2.
            printf("A potenciacao do primeiro numero com o segundo como expoente e %.3f. \n", pot);
            break;
            
        case 6: //para finalizar
            break;
            
        default: //qualquer comando maior do que 6 ou menor do que 1.
            printf("Operacao invalida. \n");
    }
}