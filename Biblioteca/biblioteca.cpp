#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

void Home();
void ADICIONAR_LIVRO();
void LISTAGEM();
void PESQUISARPORNOME();
void PESQUISARPORNOMEAUTOR();

char nome[100];
int op,contador=0;
FILE* arquivo;

typedef struct Livro LIVRO; 
 struct Livro{
  char LICOD[20],LITITULO[100],LIEDITORA[100],LIEDICAO[100],LIANOPUBLICADO[20],LIAUTOR[100],LIGENERO[100];
 };
 

int main(){
Home();	
}


void Home(){
	system("color 1f");
	system("Title Home");
	
	do{
		
		system("cls");
		setlocale(LC_ALL,"Portuguese");
	     printf("--------------------------------------------------------------------------\n");
	     printf("\t\t\tSISTEMA DE BIBLIOTECA");
		 printf("\n--------------------------------------------------------------------------\n");
	
		printf("--------------------------------------------------------------------------\n");
		printf("1-) CADASTRAR LIVRO\n2-) LIVROS CADASTRADOS\n3-) PESQUISAR PELO TITULO DO LIVRO\n4-) PESQUISAR POR AUTOR DO LIVRO\n5-) FINALIZAR O SISTEMA");
		printf("\n--------------------------------------------------------------------------\n");
		printf("OPÇÃO: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				system("Title Cadastro");
				system("cls");
				ADICIONAR_LIVRO();
			    break;
              
              case 2:
              	system("Title Livros Cadastrados");
                system("cls");
                LISTAGEM();
				break;
			
			  case 3:
			  	system("Title Pesquisar pelo titulo do livro");
			  	system("cls");
				PESQUISARPORNOME();				
				break;
				
			  case 4:
			  system("Title Pesquisar pelo autor");
			  system("cls");
			  PESQUISARPORNOMEAUTOR();
			  break;
			  	
			  case 5:
                system("cls");
				printf("\n\n\n\n\n\n\n\t\t\tFINALIZANDO O SISTEMAS");
				getch();
				break;
				
				default:
					system("cls");
					setlocale(LC_ALL,"Portuguese");
		            printf("\n\n\n\n\n\n\n\t\t\t\tOPÇÃO INVALIDA");
		 		    getch();
		}
	}while(op!=5);
	
}

void ADICIONAR_LIVRO(){
LIVRO livro;
arquivo = fopen("biblioteca.txt","ab");
   	if(arquivo == NULL){
   		setlocale(LC_ALL,"Portuguese");
 		printf("ERRO AO ABRIR O ARQUIVO PARA CADASTRO \nARQUIVO NÃO EXISTENTE");
	   }else{
	           do{
	               system("cls");
	 	           setlocale(LC_ALL,"Portuguese");
	               printf("CÓDIGO DO LIVRO: ");
                   fflush(stdin);
                   gets(livro.LICOD);
                   setlocale(LC_ALL,"Portuguese");
                   
                   printf("TITULO DO LIVRO: ");
                   fflush(stdin);
                   gets(livro.LITITULO);
    
                   printf("EDITORA: ");
                   fflush(stdin);
                   gets(livro.LIEDITORA);
                   
                   printf("EDIÇÃO: ");
                   fflush(stdin);
                   gets(livro.LIEDICAO);
                   
                   printf("ANO DE PÚBLICAÇÃO: ");
                   fflush(stdin);
                   gets(livro.LIANOPUBLICADO);
                   
                   printf("GENERO: ");
                   fflush(stdin);
                   gets(livro.LIGENERO);
                  
                   printf("AUTOR: ");
                   fflush(stdin);
                   gets(livro.LIAUTOR);
               
                   fwrite(&livro,sizeof(LIVRO),1,arquivo);
	               setlocale(LC_ALL,"Portuguese");
               
			       printf("\nDeseja continuar Cadastrando sim[s] ou não[n]: ");
	                
	           }while(getche() =='s');
	   
		       fclose(arquivo);	
	   }
}

void LISTAGEM(){
system("cls");
LIVRO livro;
nome==livro.LICOD;
arquivo = fopen("biblioteca.txt","rb");
 	
 	if(arquivo == NULL){
 		                setlocale(LC_ALL,"Portuguese");
                        printf("ERRO AO ABRIR O ARQUIVO PARA LISTAGEM\nARQUIVO NÃO EXISTENTE ");	 
     }else{	
             printf("--------------------------------------------------------------------------\n");
	         printf("\t\t\tLIVROS CADASTRADOS");
		     printf("\n--------------------------------------------------------------------------\n");
		 
	 	while(fread(&livro,sizeof(LIVRO),1,arquivo)==1){
	 		 
	 	    printf("--------------------------------------------------------------------------\n");
		 	printf("CÓDIGO: %s",livro.LICOD);
	 		printf("\nTITULO: %s",livro.LITITULO);
	 		printf("\nEDITORA: %s",livro.LIEDITORA);
	 		printf("\nEDIÇÃO: %s",livro.LIEDICAO);
	 		printf("\nANO DE PÚBLICAÇÃO: %s",livro.LIANOPUBLICADO);
	 		printf("\nAUTOR: %s",livro.LIAUTOR);
	 		printf("\nGENERO: %s",livro.LIGENERO);
		    printf("\n--------------------------------------------------------------------------\n");
	 	    getch();
		 }
	 }
	 fclose(arquivo);
	 getch();
 }
 

void PESQUISARPORNOME(){
LIVRO livro;
char nomepesquilivro[50];
arquivo = fopen("biblioteca.txt","rb");
   
   if(arquivo==NULL){
   	                  setlocale(LC_ALL,"Portuguese");
                      printf("ERRO AO ABRIR O ARQUIVO PARA PESQUISA\nARQUIVO NÃO EXISTENTE");
					  getch();
   }else{
   	     printf("--------------------------------------------------------------------------\n");
	     printf("\t\t\tPESQUISAR POR TITULO DO LIVRO");
		 printf("\n--------------------------------------------------------------------------\n");
		 	 
   	printf("\nINFORME O TITULO DO LIVRO: ");
   	fflush(stdin);
   	gets(nomepesquilivro);
   	while(fread(&livro,sizeof(LIVRO),1,arquivo)==1){
   		
   		if(strcmp(nomepesquilivro,livro.LITITULO)==0){
   		    printf("\n--------------------------------------------------------------------------\n");
	    	printf("CÓDIGO: %s",livro.LICOD);
	 		printf("\nTITULO: %s",livro.LITITULO);
	 		printf("\nEDITORA: %s",livro.LIEDICAO);
	 		printf("\nEDIÇÃO: %s",livro.LIEDICAO);
	 		printf("\nANO DE PÚBLICAÇÃO: %s",livro.LIANOPUBLICADO);
	 		printf("\nAUTOR: %s",livro.LIAUTOR);
	 		printf("\nGENERO: %s",livro.LIGENERO);
		 	printf("\n--------------------------------------------------------------------------\n");
   			getch();
		   }
	   }
   }
   fclose(arquivo);
 }
 

void PESQUISARPORNOMEAUTOR(){
LIVRO livro;
char nomepesquilivroautor[50];
arquivo = fopen("biblioteca.txt","rb");
   
   if(arquivo==NULL){
   	                  setlocale(LC_ALL,"Portuguese");
                      printf("ERRO AO ABRIR O ARQUIVO PARA PESQUISA\nARQUIVO NÃO EXISTENTE");
					  getch();
   }else{
   	
   	     printf("--------------------------------------------------------------------------\n");
	     printf("\t\t\tPESQUISAR POR AUTOR DO LIVRO");
		 printf("\n--------------------------------------------------------------------------\n");
		 	 
   	printf("\nINFORME O NOME DO AUTOR DO LIVRO: ");
   	fflush(stdin);
   	gets(nomepesquilivroautor);
   	while(fread(&livro,sizeof(LIVRO),1,arquivo)==1){
   		
   		if(strcmp(nomepesquilivroautor,livro.LIAUTOR)==0){
   		    printf("\n--------------------------------------------------------------------------\n");
	    	printf("CÓDIGO: %s",livro.LICOD);
	 		printf("\nTITULO: %s",livro.LITITULO);
	 		printf("\nEDITORA: %s",livro.LIEDICAO);
	 		printf("\nEDIÇÃO: %s",livro.LIEDICAO);
	 		printf("\nANO DE PÚBLICAÇÃO: %s",livro.LIANOPUBLICADO);
	 		printf("\nAUTOR: %s",livro.LIAUTOR);
	 		printf("\nGENERO: %s",livro.LIGENERO);
		 	printf("\n--------------------------------------------------------------------------\n");
   			getch();
		   }
	   }
   }
   fclose(arquivo);
 }


