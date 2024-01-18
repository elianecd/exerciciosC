/*
* Maquina de fichas
* =============================================================
* Escrito por: Eliane Chen Dahab

* Esse programa simula uma maquina de fichas.
* A maquina possui 5 fichas de valores diferentes.
* As fichas sao de 5, 10, 20, 50 e 100.
* Os valores das fichas sao representados por seus respectivos valores.
* A maquina apresenta ao usuario as fichas e os seus valores.
* O usuario insere o valor desejado.
* Em resposta a maquina calcula a quantidade de cada ficha.
* E calcula o total de fichas que o usuario vai receber.
*
* Input: 155
* Output: 1 ficha(s) de 100. 
*         1 ficha de 50. 
*         1 ficha de 5. 
*         Quantidade total de fichas: 3 
*/

//---------------------include section--------------------------
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//---------------------prototypes section------------------------
void ler_input(int valor); //funcao para ler o input
int func_centenas(int valor, int count); //funcao pra contar as centenas
int func_dezenas(int valor, int count); //funcao para contar as dezenas
int func_unidades(int valor, int count); //funcao para contar as unidades, ou seja, 
                                        //se o valor termina em 5.
                                    
//-------------------------main section--------------------------
int main()
{
    int valor; 
    char opc;
    
    setlocale(LC_ALL, "Portuguese"); 
    
    do
    {
        printf("Bem-vindo a SmartBox! \n");
        printf("Possuimos fichas de 5, 10, 20, 50 e 100. \n");
        printf("Os valores das fichas sao: \n");
        printf("Ficha de 5 = 5 Reais \n");
        printf("Ficha de 10 = 10 Reais \n");
        printf("Ficha de 20 = 20 Reais \n");
        printf("Ficha de 50 = 50 Reais \n");
        printf("Ficha de 100 = 100 Reais \n");
        printf("A maquina nao retorna troco. \n");
        printf("Digite o valor em Reais que deseja comprar de fichas: \n");
        scanf("%d", &valor); //valor inserido pelo usuario.
        
        ler_input(valor);
        
        printf("Deseja repetir a operacao? Se sim, digite s ou S. \n");
        printf("Se nao deseja repetir a operacao, digite qualquer tecla para sair. \n");
        scanf(" %c", &opc);
        
    } while (opc == 's' || opc == 'S');

    return 0;
}
//----------------------------functions section------------------------------
void ler_input(int valor)
{
    int count = 0;//o COUNT armazena a quantidade total de fichas.
    
    if (valor < 5 || valor > 1000) //o valor minimo eh 5 e o maximo 100.
        printf("Valor indisponivel. \n");
    
    else if (valor % 5 == 0) //verificando que o valor inserido termina em 5 ou 0.
    {
        if (valor >= 100)
            func_centenas(valor, count); //vai levar pra funcao onde se conta as centenas.
        if (valor >= 10 && valor < 100)
            func_dezenas(valor, count); //vai levar pra funcao onde se conta as dezenas.
        if (valor < 10)
            func_unidades(valor, count); //vai levar pra funcao onde se conta as unidades, ou seja, 5.
    }   
    else
        printf("Valor invalido. \n"); //a maquina nao recebe valores 63, 27, etc...
}
//------------------------------------------------------------------------
int func_centenas(int valor, int count)
{
    int fichas_100; 
    
    fichas_100 = valor / 100; //armazena o digito mais a esquerda.
    printf("%d ficha(s) de 100. \n", fichas_100);
    
    while (fichas_100 > 0) //contando as fichas de 100
    {
        count++; 
        fichas_100--;
    }
    
    valor = valor % 100; //armazena o resto do valor, tirando as centenas.
    
    if (valor == 0) //se o valor terminar em 00, como 100, 200, etc...
        printf("Quantidade total de fichas: %d \n", count); 
    else
    {
        if (valor == 5) //se o valor terminar em 05, como 105
            return func_unidades(valor, count);
        else
            return func_dezenas(valor, count); //daqui vai para a contagem das fichas de dezenas.
    }
}
//--------------------------------------------------------------------
int func_dezenas(int valor, int count) 
{
    int ficha_50 = 1; //a quantidade da ficha de 50 sera sempre 1.
    int resto_dec, resto_uni;
    
    if (valor >= 50)
    {
        count++; //se o valor eh maior do que 50, entao contabilizamos a ficha de 50.
        valor = valor - 50; //calculamos o valor sem os 50, pois agora o que muda sao as fichas menores.
        printf("%d ficha de 50. \n", ficha_50); //se entrou no if, entao com certeza tem 1 ficha de 50.
        if (valor == 0) 
        { //caso o valor sem os 50 seja 00, como os valores 50, 150, etc..
            printf("Quantidade total de fichas: %d \n", count);
            return 0; //para esses casos terminamos o programa aqui.
        }
        if (valor == 5) //para valores que terminam em 5 como 55, 155, etc...
            return func_unidades(resto_uni, count); //leva para a funcao das unidades.
    }
    
    resto_dec = valor / 10; //resto decimal armazena o digito mais a esquerda.
    resto_uni = valor % 10; //resto unitario armazena o digito mais a direita.
    
    if (resto_dec % 2 == 0) //para valores que terminam em 20 ou 40
    {
        count = count + (resto_dec/2); //conta as fichas de 20.
        printf("%d ficha(s) de 20. \n", resto_dec/2);
    }
    if (resto_dec == 1) //para valores que terminam em 10
    {
       count++;
       printf("%d ficha de 10. \n", resto_dec);
    }
    if (resto_dec == 3) //para valores que terminam em 30 ou 80.
    {
        count = count + 2; //contabiliza as fichas de 20 e 10;
        printf("%d ficha(s) de 20. \n", resto_dec - 2);
        printf("%d ficha de 10. \n", resto_dec - 2);
    }
    
    if (resto_uni == 0)
    { //se o resto unitario eh 0, entao terminamos aqui o programa.
        printf("Quantidade total de fichas: %d \n", count);
        return 0;
    }
    else //se o valor termina em 5
        return func_unidades(resto_uni, count);
}
//----------------------------------------------------------------
int func_unidades(int valor, int count)
{
    int ficha_5 = 1; //a ficha de 5 tambem sempre sera 1.
    count++; //contabilizamos a ficha de 5.
    printf("%d ficha de 5. \n", ficha_5);
    printf("Quantidade total de fichas: %d \n", count);
}