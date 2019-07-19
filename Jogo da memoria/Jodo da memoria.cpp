//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
 
int main(void){
    //vari�veis
    int i = 0, j = 0, acertos = 0;
    char c;
    int numeros[5];
    int respostas[5];
   
    //comando de regionaliza��o
    setlocale(LC_ALL, "Portuguese");
    //t�tulo do programa
    SetConsoleTitle("Jogo da memoria simples");
   
    srand(time(NULL));//semente para gerar os n�meros aleat�rios
   
    printf ("Este programa ir� gerar 5 n�meros aleat�rios entre 1 e 30.\n\n");
    printf ("Voc� deve decorar os n�meros exibidos em 5 segundos e depois escreve-los na\nordem em que foram exibidos.\n\n");
    printf ("Pressione ENTER para iniciar");
   
    do{
        c = getch();
    }while (c != 13);
   
    for (i=0;i<5;i++){
        numeros[i] = (rand() % 30)+1;
    }
   
    j=5;
   
    do{
        system ("cls");
        printf ("Decore os numeros abaixo em %d\n\n\n", j);
        j--;
        for (i=0;i<5;i++){
            printf ("%d\t", numeros[i]);
        }
        Sleep (1000);
    }while (j>0);
   
    system ("cls");
    printf ("Informe os n�meros que foram exibidos\n\n");
   
    for (i=0;i<5;i++){
        printf ("\t%d� n�mero: ", i+1);
        scanf ("%d", &respostas[i]);
        if (respostas[i]==numeros[i]){
            acertos++;
        }
    }
   
    if (acertos==5){
        printf ("\n\nParab�ns! Sua mem�ria � muito boa. Veja os n�mero exibidos:\n\n\t");
        for (i=0;i<5;i++){
            printf ("%d\t", numeros[i]);
        }
    }
    else
    {
        printf ("\n\nQue pena! Sua mem�ria n�o � muito boa. Veja os n�mero exibidos:\n\n\t");
        for (i=0;i<5;i++){
            printf ("%d\t", numeros[i]);
        }
    }
    printf ("\n\n");
    system ("pause");
    return 0;
}
