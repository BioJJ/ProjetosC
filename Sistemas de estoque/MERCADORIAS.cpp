#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#define tam 50
void LOGIN();
void Home();
void CADASTRAR_MERCADORIAS();
void LISTAGEM();
void PESQUISAR();
void REALIZARVENDA();
void VENDAS_REALIZADAS();
void ALTERAR_ESTOQUE();

int CODIGO[tam],ESTOQUE[tam]; 
double final=0;

char NOME[tam][200],venda_desc_prod[tam][200];  
float VALOR[tam];
char opc;
int op,op6,buscar_pesquisar_cod_produto,procura_cod_barra_venda, atual_estoque=0, item_venda=0;

int x=0,i,lista_produro[tam]; 
float provalor[tam],total[tam],qtde[tam]; 
int teste,buscar_cod_produto,lista_produto,lista;   
int cod_ref_prod,vend_cod_produto[tam],v=0, t=0,teste_este,procura_este,venda_estoque_produto[tam];
float valor_venda,venda_preco_produto[tam];
int procura_cod_venda,adriano[tam];
int cod_venda[tam],venda_qtd_prod[tam]; 

int main(){
	Home();
}

void Home(){
	do{
		system("color 1f");
		system("cls");
		 printf("--------------------------------------------------------------------------\n");
	     printf("\t\t\tSISTEMA DE MERCADORIAS\n\t\t\t\tVENDAS");
		 printf("\n--------------------------------------------------------------------------\n");
	     setlocale(LC_ALL,"Portuguese");
	     printf("1) CADASTRAR MERCADORIAS\n2) MERCADORIAS CADASTRADAS\n3) PESQUISAR MERCADORIA PELO CÓDIGO\n4) REALIZAR VENDA\n5) VENDAS REALIZADAS\n6) ATUALIZAR ESTOQUE\n7) FINALIZAR O SISTEMA\n");
	     printf("\n--------------------------------------------------------------------------\n");
	     printf("opção: ");
	    scanf("%d",&op); 
		
		switch(op){
			case 1:
				system("cls");
				CADASTRAR_MERCADORIAS();
				break;
				
			case 2:
			     system("cls");
	             LISTAGEM();
			     break;
	        case 3:
	        	system("cls");
			    PESQUISAR();
			    break;			
			    
			    case 4:
			      system("cls");
			      REALIZARVENDA();
			        break;
			        
			     case 5:
				 system("cls");
				 VENDAS_REALIZADAS();
				 break;   
			        
				 
				 case 6:
				 	system("cls");
				 	ALTERAR_ESTOQUE();
				 	break;
				 	
			     case 7:
				 system("cls");
				 printf("\n\n\n\n\n\n\n\t\t\tSISTEMA FINALIZANDO");
				 op=7;
				 getch();
				 break;
				 
				 default:
				 system("cls");
				 printf("Opção invalida");
				 break;   
			        
			        
		}
		
	}while(op!=7);
	
}


void CADASTRAR_MERCADORIAS(){
 do{ 
      do{  
	      system("cls");  		     
		    teste=0;
		    setlocale(LC_ALL,"portuguese");
		    printf("CÓDIGO DA MERCADORIA: ");
		    scanf("%d",&CODIGO[x]);
		
		   for(i=0; i<x; i++){
		        if(CODIGO[x] == CODIGO[i]){
				system("cls");
				  setlocale(LC_ALL,"portuguese");
				  printf("\n\n\n\n\n\n\n\t\t\tCODIGO EXISTENTE NO SISTEMA");
				  getch();
				  teste=1;
		       }
		   }
	  }while(teste==1); 
		
		setlocale(LC_ALL,"portuguese");
		printf("DESCRIÇÃO: ");
		scanf("%s",&NOME[x]);
    	
		do{ 
		    teste=0;
		    printf("VALOR: ");
		    scanf("%f",&VALOR[x]);
	 	    
			 if(VALOR[x]<=0){
	 	    	printf("\t\t\t\t\t\tDIGITE UM VALOR SUPERIOR A 0");
	 	    	teste=1;
			 }
  	    }while(teste==1);
	    
		do{ 
			teste=0; 
		    setlocale(LC_ALL,"portuguese");
		    printf("ESTOQUE: ");
		    scanf("%d",&ESTOQUE[x]);
    	    
			   if(ESTOQUE[x]<=0){
			   	
    	        	printf("\t\t\t\t\t\tESTOQUE NÃO PODE SER 0");
    	        	teste=1; 
			   }   
    	}while(teste==1);
         
		    setlocale(LC_ALL,"portuguese");
		    printf("\n\n\n\tDESEJA CONTINUAR [S]SIM OU [N]NÃO :");
		    scanf("%s",&opc);
	        x++; 
	        lista_produto++;
 }while(opc=='S'); 
}

void LISTAGEM(){

  if(x==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO A NENHUMA MERCADORIA CADASTRADA NO SISTEMA");
		   getch();
	 }else{ 
	  do{  
		  lista=0; 
		  setlocale(LC_ALL,"portuguese");
          printf("\n\tCódigo\tDescrição\tValor\t\tEstoque");
	
		  for(i=0; i<lista_produto; i++){
		      if(CODIGO[i]>0){
		         printf("\n\t%d\t%s\t\t%.2f\t\t%d",CODIGO[i],NOME[i],VALOR[i],ESTOQUE[i]);
		      } 
		  }
		           getch();
		
	  }while(lista==1);
  }	
}


void PESQUISAR(){
	
  do{ system("cls");
  setlocale(LC_ALL,"Portuguese");
     printf("CÓDIGO DA MERCADORIA: ");
     scanf("%d",&buscar_pesquisar_cod_produto);
			  
     if(lista_produro==0){
     	system("cls");
     	setlocale(LC_ALL,"Portuguse");
	  	printf("\n\t\t\t\tMERCADORIA NÃO EXISTENTE NO SISTEMA");
	  	getch();
	  	break;
     }else{
		  	
 	   setlocale(LC_ALL,"portuguese");
       printf("\n\tCódigo\tDescrição\tValor\t\tEstoque");
	   teste=0;

     	for(i=0; i<=lista_produto;i++){

	  		 if(buscar_pesquisar_cod_produto==CODIGO[i]){
    	         printf("\n\t%d\t%s\t\t%.2f\t\t%d",CODIGO[i],NOME[i],VALOR[i],ESTOQUE[i]);
			  	teste=1;
			   }
		 }
	   {
	  
		  if(teste==0){
	        system("cls");
	        setlocale(LC_ALL,"Portuguese");
		  	printf("\n\n\n\n\n\n\n\n\t\tMERCADORIA NÃO EXISTENTE NO SISTEMA");
		  	getch();
			break;
		  }			  	
	   }
	 }
	 setlocale(LC_ALL,"Portuguese");
	  printf("\n\nDESEJA CONTINUAR PESQUISANDO [S] SIM OU [N]NÃO: ");
	  scanf("%s",&opc);
  }while(opc=='S');	
}

void REALIZARVENDA(){		
do{system("cls");
	 
	 do{

		setlocale(LC_ALL,"portuguese");
	
		printf("Informe o código de barra: ");
		scanf("%d",&procura_cod_barra_venda);
		
			for(i=0; i<x; i++){
			if(procura_cod_barra_venda==CODIGO[i]){
					
					//	printf("codigo encontrado\n");
						printf("\nPRODUTO:%s", NOME[i]);
						printf("\nPREÇO R$:  %.2f",VALOR[i]);
						
			
			cod_ref_prod=i;
			i=x;
			teste=0;
			
			vend_cod_produto[v] = procura_cod_barra_venda;				
		
		
			do{
		teste_este=0;
		
		setlocale(LC_ALL,"portuguese");
		printf("\nQuantidade que voçê deseja: ");
		scanf("%d",&procura_este);
		
		
		if(procura_este<=0){
			printf("Estoque vazio!!");
			teste_este=1;
		}else{
			   if(procura_este>ESTOQUE[cod_ref_prod]){
				  system("cls");
				  printf("\nA QUANTIDADE INFORMADA É INFERIOR DO ESTOQUE");
				  
				  t=v;
				  teste_este=1;
				  break;
		       }else{
		       	ESTOQUE[cod_ref_prod]=ESTOQUE[cod_ref_prod]-procura_este;
		       	venda_estoque_produto[v]=procura_este;
		       
			   
			   }
		}		
	
		valor_venda=procura_este*VALOR[cod_ref_prod]; 
	
	venda_preco_produto[v]=valor_venda;  
	final=final+venda_preco_produto[cod_ref_prod]; 		
	v++;
	}while(teste_este==1); 
			}
			else if(procura_cod_barra_venda==0 || procura_cod_barra_venda>x){
			setlocale(LC_ALL,"Portuguese");
			printf("\n\n\n\n\n\t\t\tCÓDIGO NÃO EXISTENTE");
		//	getch();
			
		}	
		
	}
		
	}while(teste==1);
	
	
	printf("\n\n\n\t\tDeseja continuar sim[s] ou nao[n]: ");
	scanf("%s",&opc);
getch();
}while(opc=='s');
	
}

void VENDAS_REALIZADAS(){
	setlocale(LC_ALL,"Portuguese");	     
    printf("ITEM\t\tDescrição\tValor\t\tqtd\t\ttotal");

	for(i=0; i<v; i++){
	
		
		//	     printf("\n%d\t\t%s\t\t%.2f\t\t%d\t\t%.2f",i+1,desq,VALOR[i],q,vv);	
	     printf("\n%d\t\t%s\t\t%.2f\t\t%d\t\t%.2f",i+1,NOME[i],VALOR[i],venda_estoque_produto[i],venda_preco_produto[i]);	
		
		}
	
    	 printf("\n\n--------------------------------------------------------------------------\n");
		 printf("Faturamento R$....................................... %.2f",final);
				 getch();


		}

void ALTERAR_ESTOQUE(){

	if(x==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO A NENHUMA MERCADORIA CADASTRADA NO SISTEMA");
		   getch();
	 }else{ 
	  do{  
		  lista=0; 
		setlocale(LC_ALL,"portuguese");
		system("cls");
		printf("INFORME O CÓDIGO DA MERCADORIA: ");
		scanf("%d",&procura_cod_barra_venda);
		
	
			for(i=0; i<x; i++){
			if(procura_cod_barra_venda==CODIGO[i]){
							
				printf("QUANTIDADE:");
				scanf("%i",&atual_estoque);
				
				ESTOQUE[i]=ESTOQUE[i]+atual_estoque;		
			getch();
			
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\t\t\tESTOQUE ATUALIZADO \n\t\t\t\t%i", ESTOQUE[i]);
		   	getch();
			}else if(procura_cod_barra_venda==0 || procura_cod_barra_venda>x){
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\t\t\tCÓDIGO NÃO EXISTENTE");
		   
				getch();
			}
	}	
	
	system("cls");
	setlocale(LC_ALL,"Portuguese");
	printf("\n\n\n\n\n\n\n\t\t\tDESEJA ALTERAR OUTRO ESTOQUE? \n\t\t\t\t1-SIM \n\t\t\t\t0-NÃO\n\t\t\t\tOPÇÃO: ");
	scanf("%i",&op6);	
}while(op6!=0);
}
  }

