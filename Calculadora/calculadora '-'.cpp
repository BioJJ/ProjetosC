#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>


main(){

	char oppesq[2], a[2],s[2],m[2],d[2],area[2];
	int op;
	
	float n1, n2, n3, resultado;
	
	
	strcpy(a,"+");
	strcpy(s,"-");
	strcpy(m,"*");
	strcpy(d,"/");
	strcpy(area,"a");
	do{
		
		
		printf("Informe a operacao:\n");
		printf("\n+ para Adicao: ");
		printf("\n- para nSubtracao: ");
		printf("\n* para Multiplicacao: ");
		printf("\n/ para Divisao: ");
		printf("\nA para Calcular a area:");
		printf("0 - para sair\n\n ");
		fflush(stdin);
		gets(oppesq);
		
		if(strcmp(strlwr(oppesq),a)==0){
			
			system("cls");
			printf("Adicao:");
			
			printf("\nInforme os valor:");
			printf("\nPrimeiro valor:");
			scanf("%f", &n1);
			printf("\nsegundo valor:");
			scanf("%f", &n2);
			
			resultado=n1+n2;
			
			printf("\nO resultado da soma é: %2.f\n", resultado);
		}
		
		else if(strcmp(strlwr(oppesq),s)==0){
			system("cls");
			printf("Subtracao:");
			
			printf("Informe os valor:");
			printf("\nPrimeiro valor:");
			scanf("%f", &n1);
			printf("\nSegundo valor:");
			scanf("%f", &n2);
			
			resultado=n1-n2;
			
			printf("\nO resultado da subtracao é: %2.f\n", resultado);
				
			
		}
		else if(strcmp(strlwr(oppesq),m)==0){
			system("cls");
			printf("Multiplicacao:");
			
			printf("Informe os valor:");
			printf("\nPrimeiro valor:");
			scanf("%f", &n1);
			printf("\nSegundo valor:");
			scanf("%f", &n2);
			
			resultado=n1*n2;
			
			printf("\nO resultado da Multiplicacao é: %2.f\n", resultado);	
			
		}
		else if(strcmp(strlwr(oppesq),d)==0){
				system("cls");
				printf("Divisao:");
			
			printf("Informe os valor:");
			printf("\nPrimeiro valor:");
			scanf("%f", &n1);
			printf("\nSegundo valor:");
			scanf("%f", &n2);
			
			resultado=n1/n2;
			
			printf("\nO resultado da divisao é: %2.f\n", resultado);
			
		}
		else if(strcmp(strlwr(oppesq),area)==0){
			
				system("cls");
				printf("Area:");
				
				printf("\n 1- Um circulo: ");
			    printf("\n 2- Um Quadrado: ");
			    printf("\n 3- Um Trapezio: ");
			    scanf("%i", &op);
			    
			    
			    if(op==1){
			    	printf("Area do Circulo:");
			    	
			printf("Informe os valor:");
			printf("\nRaio:");
			scanf("%f", &n1);
			
			
			resultado=3,14*(n1*n1);
			
			printf("\nO A area do circulo e: %2.f\n", resultado);
			
			    	
				}else if(op==2){
					
					printf("Area do quadrado:");
			printf("Informe os valor:");
			printf("\nLargura:");
			scanf("%f", &n1);
			printf("\ncomprimento:");
			scanf("%f", &n2);
			
			resultado=n1*n2;
			
			printf("\nO A area do quadrado e: %2.f\n", resultado);
					
				}else if(op==3){
			printf("Area do trapezio:");		
			printf("Informe os valor:");
			printf("\nBase Menor:");
			scanf("%f", &n1);
			printf("\nBase Maior:");
			scanf("%f", &n2);
			printf("\nAltura:");
			scanf("%f", &n3);
			
			resultado=((n1+n2)*n3)/2;
			
			printf("\nO A area do trapezio e: %2.f\n" , resultado);
			
					
				}else{
					printf("opcao invalida\n");
				}
				
			
		}else if(strcmp(strlwr(oppesq),"0")==0){
		op=0;
			
		}else {
			printf("Opcao invalida\n");
			 getch();
			 
			 system("cls");
			
			
		}		
		
		
	}while(op!=0);



 getch();

}
