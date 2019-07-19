#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale>
#include<conio.h>
#include<windows.h>
#include<time.h>

//Registros
typedef struct Gerente{
	char login[20];
	int senha;
	
}Gerente;

typedef struct Operacao{
	char operacao[20];
	float valor;
	
}Operacao;

typedef struct Emprestimo{
	float credito, valor, juros, valortotal, parcelas;
	
}Emprestimo;

typedef struct Conta{
	char nome[20];
	float saldo, salario;
	int c, senha, numero_conta, agencia;
	Operacao op[5];
	Emprestimo emprestimo;
	
}Conta;

// Procedimentos
void Tela_login();
void tela_carregando();
void tela_carregando2();
void Tela_Gerente(Gerente gerente, Conta conta[], int t, int *p_conta);
void cadastrar_conta(Conta conta[], int t, int *p_conta);
void solicitar_emprestimo(Conta conta[], int t, int *p_conta);
void Tela_Cliente(int j, Conta conta[], int t, int *p_conta);
void consulta_extrato(int j, Conta conta[], int t);
void realizar_deposito(int j, Conta conta[], int t);
void realizar_saque(int j, Conta conta[], int t);
void realizar_emprestimo(int j, Conta conta[], int t);
void consultar_emprestimo(int j, Conta conta[], int t);

// Funções 
int Pesquisar_conta(Conta conta[],int t);
int calcular_operacao(int j, Conta conta[], int t, int op);

main(){
	
	setlocale(LC_ALL,"Portuguese");
	system("color 1f");
	
	//tela_carregando();

	Tela_login();
	
	
}//main

void Tela_login(){
	
	
	Gerente gerente;
	Conta conta[10];
	
		int cont_conta=0, op, teste_login=0;
		
		char login_pesq[20];
		int senha_pesq;
		
		//inicializando adm
		strcpy(gerente.login,"adm");
		gerente.senha=123;	
		
		for(int z=0; z<10; z++){
			conta[z].c=0;
		}	
		
	do{
		teste_login=0;
		system("cls");
		
		printf("\t\t\t\t\t\t\t\t\t\t\t\t"__DATE__" ");
		
		
		system("title \t\t\tBANCO FAMETRO\n\n");
		printf("\t\t\tBANCO FAMETRO\n\n");
		
		printf("\n\t\t\tLOGIN OU Nº DA CONTA: ");
		fflush(stdin);
		gets(login_pesq);
		
		printf("\n\t\t\tSENHA: ");
		scanf("%i", &senha_pesq);
	
	
		if(strcmp(login_pesq,gerente.login)==0 && senha_pesq==gerente.senha){
		teste_login=1;
		
		Tela_Gerente(gerente, conta, 10, &cont_conta);
				
			
		}else{
	
		for(int j=0; j<cont_conta; j++){
		
		if(conta[j].numero_conta==atoi(login_pesq) && senha_pesq==conta[j].senha){
			teste_login=1;
			Tela_Cliente(j, conta, 10, &cont_conta);
			
		
		}// if
		
		}//for
		
	}//else
	
		if(teste_login==0){
			system("cls");
	
			printf("\n\n\n\t\t\tLogin ou senha, invalidos\n");
		
		printf("\n1) Tentar novamente\n2) SAIR \nOPÇAO: ");	
		scanf("%i", &op);
		
	
		if(op==2){
			op=3;
		}//if
			
		}//if
		
	}while(op!=3);//do/while
	
}// tela login

void Tela_Gerente(Gerente gerente, Conta conta[], int t, int *p_conta){
	
	int op;
	
	do{
		system("cls");
		
		printf("\n\t\t\tBem vindo ADM: %s", gerente.login);
		
		
	printf("\n1) ABRIR CONTA: %i", *p_conta);
	printf("\n2) SOLICITAR EMPRESTIMO");
	printf("\n0) SAIR");
	printf("\nOPÇÃO: ");
	scanf("%i", &op);

	
	switch(op){
		
		case 1:
			system("cls");
		cadastrar_conta(conta,10,p_conta);
			break;
			
		case 2:
			system("cls");
		solicitar_emprestimo(conta,10,p_conta);	
			break;
			
		case 0:
			op=9;
			break;
			
		default:
			
			printf("\n\n\n\t\t\tOPÇÃO INVALIDA");
			break;
		
	}//switch
	
	}while(op!=9);
	
}// void tela gerente

void cadastrar_conta(Conta conta[], int t, int *p_conta){
	

	int op, i=*p_conta;
	
	do{
		
		if(i>10){
			
			printf("\n\n\n\t\t\tCADASTRO EXCEDIDO \n");
			getch();
			op=8;
		}else{
		
		
		printf("\t\t\tCADASTRAR CONTA\n");
		
		printf("\nInforme os dados: ");
		printf("\n\nNome: ");
		fflush(stdin);
		gets(conta[i].nome);
		
		printf("\nNúmero da conta: ");
		scanf("%i", &conta[i].numero_conta);
		
		printf("\nAgencia: ");
		scanf("%i", &conta[i].agencia);
		
		printf("\nSenha: ");
		scanf("%i", &conta[i].senha);
		
		printf("\nSaldo R$: ");
		scanf("%f", &conta[i].saldo);
		
		printf("\nSalario R$: ");
		scanf("%f", &conta[i].salario);
		
		i++;
		*p_conta=i;
		system("cls");
		
		printf("\n\t\t\tCONTA CADASTRADA COM SUCESSO");
		
		}
		
		if(op!=8){
		
		printf("\n\nDeseja continuar cadastrando?");
		printf("\n1) sim \n2) não \nOpção: ");
		scanf("%i", &op);
		
		if(op==2){
			op=8;
		}
		
		}
	}while(op!=8);
	
	
}//void cadastrar conta

void solicitar_emprestimo(Conta conta[], int t, int *p_conta){
	int a=*p_conta;
	int op,op2, pesq;
	float limite_maximo=0,salario=0;
	
	do{
		system("cls");
		
		if(a==0){
			system("cls");
			printf("\t\t\tPor favor, abra uma conta!!\n");
			getch();
			
			op=6;
			
		}else{
		printf("\n\t\tPESQUISAR CONTA: \n");
		pesq=Pesquisar_conta(conta,a);
		
		if(pesq<0){
			system("cls");
			printf("\n\n\n\t\t\tCONTA NÃO ENCONTRADA\n");
			
			printf("1) tentar novamente \n2) sair \nOpção: ");
			scanf("%i", &op);
			
			if(op==2){
				op=6;
					
			}
	
		}else{
			
			do{
			
			system("cls");
			
			printf("\n\t\t\tCONTA ENCONTRADA\n");
			
			printf("\nNome: %s", conta[pesq].nome);
			printf("\nSalario: R$ %.2f", conta[pesq].salario);
			salario=conta[pesq].salario;
			
			limite_maximo=salario+(salario*80/100);
			
			printf("\nLimite maximo para emprestimo: R$ %.2f", limite_maximo);
			
			printf("\n\nInforme o limite para emprestimo: ");
			scanf("%f", &conta[pesq].emprestimo.credito);
			
			
			if(conta[pesq].emprestimo.credito<limite_maximo){
				
			system("cls");
			
			printf("\t\t\tLiberacao feita com sucesso\n");
			
			op2=99;
			op=6;
			}else{
				system("cls");
				printf("\n\n\n\t\t\tLIMITE DE CREDITO INVALIDO\n");
				getch();
			}
			
			
			}while(op2!=99);
					
			
		}//else
		
		}// else
		
	}while(op!=6);
	
	
}

void Tela_Cliente(int j, Conta conta[], int t, int *p_conta){
	
	int op;
	float valorpesq;
	float juros=0, valortotal, parcelas;
	
	do{
		system("cls");
		
		printf("\t\t\tSeja Bem Vindo Cliente: %s\n\n", conta[j].nome);
		
		printf("\n\t\t\tO QUE DESEJA FAZER?: \n");
		printf("1) CONSULTAR EXTRATO\n");
		printf("2) REALIZAR DEPOSITO\n");
		printf("3) REALIZAR SAQUE\n");
		printf("4) REALIZAR EMPRESTIMO\n");
		printf("5) CONSULTAR EMPRESTIMO\n"); 
		printf("0) SAIR\n");
		printf("Opção: \n");
		scanf("%i", &op);
		
		switch(op){
			
			case 1:
				consulta_extrato(j, conta, 10);
				
				break;
				
			case 2:
				realizar_deposito(j, conta, 10);
				
				break;
				
			case 3:
				realizar_saque(j, conta, 10);
				
				break;
			
			case 4:
				
				realizar_emprestimo(j, conta, 10);
				
				break;
				
			case 5:
				
				consultar_emprestimo(j, conta, 10);
				
				break;
				
			case 0:
				op=7;
				break;
				
			default:
				printf("\n\n\n\t\t\tOPÇÃO INVALIDA\n");
				break;
		}
		
	}while(op!=7);
	
}//void tela cliente

void consulta_extrato(int j, Conta conta[], int t){
	
	system("cls");
 			
 			printf("\t\t\tCONSULTA EXTRATO");
 			
 			printf("\nCliente: %s", conta[j].nome);		
 			printf("\nNumero da conta: %i", conta[j].numero_conta);
			printf("\nAgencia: %i", conta[j].agencia);
			printf("\nSaldo: R$ %2.f", conta[j].saldo);
			
			if(conta[j].c==0){
			
				
				printf(" ");
				
			}else{
				
		
			printf("\n\n\n\t\t\tULTIMAS TRANSAÇOES:\n");
			
			for(int t=0; t<conta[j].c; t++){
				
				printf("\nOperação: %s",conta[j].op[t].operacao);
 				printf("\nValor: R$ %.2f",conta[j].op[t].valor);
 				
 				printf("\n-----------------\n");
 				
			}// for
			
				}
 					getch();
	
}

void realizar_deposito(int j, Conta conta[], int t){
	
	int op=1;

		system("cls");
 				printf("\t\t\tREALIZAR DEPOSITO\n\n");
 				
 				calcular_operacao(j, conta,10,op);
 				
 					tela_carregando2();
 				system("cls");
 				printf("\n\n\n\t\t\tDeposito realizado com sucesso!!");
 				getch();
	
}

void realizar_saque(int j, Conta conta[], int t){
	
	int op=2, teste, menu;
	
		do{
	
 				system("cls");
 				printf("\t\t\tREALIZAR SAQUE\n\n");
 					
 					teste=calcular_operacao(j, conta,10,op);
 					
 					if(teste>=0){
 						tela_carregando2();
 						system("cls");
 					
 					printf("\n\n\n\t\t\tSaque realizado com sucesso!!");
 					menu=7;
 					getch();
 				system("cls");
					 }else{
					 	
					 		system("cls");
 					printf("\n\n\n\t\t\tSaldo insuficiente para retirada\n");
				 	printf("\n\n\n\t\t\tSaldo atual: R$ %2.f", conta[j].saldo);
				 	
				 		getch();
					 }
				
		}while(menu!=7);
	
}

void realizar_emprestimo(int j, Conta conta[], int t){
	
	int op=3, teste, menu;
	
		do{
			
			if(conta[j].emprestimo.credito==0){
				
				system("cls");
				printf("\n\n\n\t\t\tSEM CREDITO PARA EMPRESTIMO\n");
				menu=9;
				getch();
			}else{
		
				system("cls");
 				
 				printf("\t\t\tREALIZAR EMPRESTIMO\n\n");
 				
 					teste=calcular_operacao(j, conta,10,op);
 					
 					
 				if(teste>=0){
				 
 				tela_carregando2();
 				system("cls");
 					
 					printf("\n\n\n\t\t\tSEU EMPRESTIMO FOI APROVADO");
 					menu=9;
 				getch();
 				
				 }else{
				 	
				 	system("cls");
				 	printf("\n\n\n\t\t\tEMPRESTIMO EXCEDEU O LIMITE DISPONIVEL!");
				 	printf("\n\n\n\t\t\tLIMITE: %.2f", conta[j].emprestimo.credito);
				 	getch();
				 	
			}
			
				}// else
			
	
		}while(menu!=9);
}

void consultar_emprestimo(int j, Conta conta[], int t){
	
	
	
		system("cls");
 				
 				
 				printf("\t\t\tCONSULTAR EMPRESTIMO");
 				
 				conta[j].emprestimo.juros=conta[j].emprestimo.valor*20/100;
 				conta[j].emprestimo.valortotal=conta[j].emprestimo.juros+conta[j].emprestimo.valor;
 				conta[j].emprestimo.parcelas=conta[j].emprestimo.valortotal/24;
 				
 				printf("\n\nQuantidade de parcelas: 24");
 				printf("\nvalor das parcelas: R$ %2.f", conta[j].emprestimo.parcelas);
 				printf("\nValor do emprestimo: R$ %2.f", conta[j].emprestimo.valor);
 				printf("\nValor total a pagar: R$ %2.f", conta[j].emprestimo.valortotal);
 				
 				getch();
	
}

void tela_carregando(){
	
	  int i, j;
   
   system ("cls");
   
   printf ("\n\n\n\n\n\t\t\tCARREGANDO SISTEMA \n\n");          
     
   for (i = 0; i <= 100; i++)
   {                
      printf ("\r  %i%%", i);      
      //printf ("  %d%%\r", i);
      fflush (stdout);                      
         
      for (j = 0; j < i; j++)
      {
         if (!j) // Da espaco na barra pra nao enconstar na borda da tela
           printf("  ");
           
         printf ("|");
         Sleep(1);
      }                      
   } 
   
}// TELA CARREGANDO 1

void tela_carregando2(){
	
	  int i, j;
   
   system ("cls");
   
   printf ("\n\n\n\n\n\n\t\t\tPROCESSANDO TRANSAÇÃO \n\n");          
     
   for (i = 0; i <= 100; i++){
                   
      printf ("\r  %i%%", i);      
      //printf ("  %d%%\r", i);
      fflush (stdout); // atualizar a tela              
         
      for (j = 0; j < i; j++){
      	
         if (!j) // Da espaco na barra pra nao enconstar na borda da tela
           printf("  ");
           
         printf ("|");
         Sleep(0.9);
      }                      
   } 
   
}// tela carregando

int Pesquisar_conta(Conta conta[],int t){
	
	char conta_pesq[20];
	
	int teste_cliente=(-1);
	
	printf("Informe o nome do cliente: ");
			fflush(stdin);
			gets(conta_pesq);
	
	for(int j=0; j<t;j++){
				
				if(strcmp(conta_pesq, conta[j].nome)==0){
					
					return j;
					
				}//if comparando cliente do registro
				else{
					teste_cliente= -1;
				}
				
				
			}//for
			
					
		return teste_cliente;
		
}	// função pesquisar cliente 

int calcular_operacao(int j,Conta conta[], int t, int op){
	
	float valorpesq;
	
	if(op==1){
		
	printf("Informe o valor do deposito:");
 				scanf("%f", &valorpesq);
 				
 				conta[j].saldo=conta[j].saldo+valorpesq;
 				
 				strcpy(conta[j].op[conta[j].c].operacao, "Deposito");
 				conta[j].op[conta[j].c].valor=valorpesq;
 				
 				conta[j].c++;
 				
 	// realizar deposito	
	}else if(op==2){
		
		
 				printf("\nInforme o valor do saque:");
 				scanf("%f", &valorpesq);
 				
 				if(valorpesq<=conta[j].saldo){
 					conta[j].saldo=conta[j].saldo-valorpesq;
 					
 				strcpy(conta[j].op[conta[j].c].operacao, "Saque");
 				conta[j].op[conta[j].c].valor=valorpesq;
 				
 				conta[j].c++;
 					return 1;
 					
 					 }else{
				 	return -1;
				 	
				 }
		// realizar saque
	}else if(op==3){
		
		printf("\nInforme o valor do emprestimo:");
 				scanf("%f", &conta[j].emprestimo.valor);
 				
 				if(conta[j].emprestimo.valor<= conta[j].emprestimo.credito){
 					
 					conta[j].saldo=conta[j].saldo+conta[j].emprestimo.valor;
 					
 					conta[j].emprestimo.credito=conta[j].emprestimo.credito-conta[j].emprestimo.valor;
 					
 					return 1;
 				}else {
 					
 					return -1;
				 }
		
		// realizar emprestimo
	}
	
	
}// função calcular operação
