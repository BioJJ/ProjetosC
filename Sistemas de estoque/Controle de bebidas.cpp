#include<stdlib.h>
#include<stdio.h>
#include<string.h>

main(){
	
	int op;
	
	// variaveis do cliente
	char nome_cliente[10][10];
	char rua[10][10];
	char bairro[10][10];
	int casa[10], telefone[10];
	int i=1,ii=0;
	
	// variaveis da bebida
	 
	char decricao[10][10];
	int qtd_bebida[10];
	float valor_bebida[10];	
	int j=1,jj=0;
	
	// variaveis Venda
	char nome_cliente_pesq[10];
	char decricao_pesq[10];
	int qtd_pesq[10];
	float valor_total[10],troco[10],valor_pago[10];
	
	
	do{
	
	system("cls");
	printf("\n1- cadastro de cliente:(RESTANTES: %i)", 10-ii);
	printf("\n2- cadastro de Bebidas:(RESTANTES: %i)", 10-jj);
	printf("\n3- Realizar venda:");
	printf("\n4- Gerar entrega:");
	printf("\n0- Sair:\n");
	scanf("%i", &op);
	
	
	if(op==1){
		system("cls");
		
		printf("Cadastro de clientes\n");
		
		
		if(i<=10){
			
			printf("cadastre o %iº cliente",i);
			printf("\nInforme o nome do cliente:");
			fflush(stdin);
			gets(nome_cliente[i]);
			
			printf("\nInforme o telefone:");
			scanf("%i", &telefone[i]);
			
			printf("\nEndereco:\n");
			
			printf("Rua:");
			fflush(stdin);
			gets(rua[i]);
			
			printf("casa:");
			scanf("%i", &casa[i]);
			
			printf("Bairro:");
			fflush(stdin);
			gets(bairro[i]);
			
			printf("\ncliente %i cadastrado", i);
			
			
			system("pause");
			
			i++;
			ii++;
			
			
		}else{
			printf("Cadastro cheio");
			
			system("pause");
		}
		
		
		
	}//cadastro de cliente 
	
	else if(op==2){
		
		system("cls");
		
		printf("Cadastro de Bebidas");
		
		if(j<=10){
			
			printf("\nCadastre a %iº bebida:", j);
			
			printf("\nInforme o nome da bebida:");
			fflush(stdin);
			gets(decricao[j]);
			
			printf("Informe a quantidade no estoque:");
			scanf("%i", &qtd_bebida[j]);
			
			printf("Informe o valor da bebida:");
			scanf("%f", &valor_bebida[j]);
			
			printf("\nBebida %i cadastrada com sucesso!", j);
			
			system("pause");
			
			j++;
			jj++;
			
		}else{
			printf("\nCadastro cheio");
			
			system("pause");
		}
		
		
	}// cadastro de bebidas
	
	else if(op==3){
		system("cls");
		printf("Realizar venda:\n");
		
		if(i>ii){
			
			printf("\t\t\t\tPesquisa por nome do cliente:\n\n");
			
			printf("Informe o nome do cliente:");
			fflush(stdin);
			gets(nome_cliente_pesq);
			
			for(int cont=1; cont<i; cont++){
				if(strcmp(strlwr(nome_cliente[cont]),nome_cliente_pesq)==0){
					
					printf("Cliente encontrado:\n");
					
					system("pause");
					system("cls");
					
					printf("Nome do cliente: %s\n\n", nome_cliente[cont]);
					
					
			if(j>jj){
			
			printf("\t\t\t\tPesquisa por nome da bebida:\n\n");	
				
					printf("Informe o nome da bebida:");
					fflush(stdin);
					gets(decricao_pesq);
					
					for(int cont1=1; cont1<j; cont1++){
						
							if(strcmp(strlwr(decricao[cont1]),decricao_pesq)==0){
								
							printf("Bebida encontrada!!\n\n");
							system("pause");
							system("cls");
							
							printf("Nome do cliente: %s\n\n", nome_cliente[cont]);
							printf("Nome da Bebida: %s\n", decricao[cont1]);
							printf("Quantidade no estoque: %i",qtd_bebida[cont1]);
							
							printf("\nInforme a quantidade para venda:");
							scanf("%i", &qtd_pesq[cont1]);
							
							if(qtd_bebida[cont1]>=qtd_pesq[cont1]){
								qtd_bebida[cont1]=qtd_bebida[cont1]-qtd_pesq[cont1];
								valor_total[cont1]=valor_bebida[cont1]*qtd_pesq[cont1];
								
								printf("\n\n valor unitario: %f",valor_bebida[cont1]);
								
								printf("\n valor total a pagar: %f", valor_total[cont1]);
								
								printf("\nInforme o valor pago:");
								scanf("%f", &valor_pago[cont1]);
								
								troco[cont1]=valor_pago[cont1]-valor_total[cont1];
								
								printf("\nSeu troco é: %f", troco[cont1]);
								
								printf("\t\tVenda realizada com sucesso!\n\n");
								
								system("pause");
								
								
							}// comparando o estoque com a qtd pesquisada
							else{
								printf("\t\t\tEstoque insuficiente!!\n\n");
								system("pause");
							}
							
							
							}// if do nome da bebida
							else{
								printf("\t\t\tBebida não cadastrado ou escrita errado '-' \n\n");
								system("pause");
							}
					
					
					}// comparando o bebidas	
				
					
					
			}// if se tem bebida cadastrada
			else{
			printf("\n\t\t\tPor favor, cadastre uma bebida!!\n\n");
			system("pause");
				
			}	
					
					
				}// if do nome cliente
				else{
					printf("\t\t\tCliente não cadastrado ou escrita errado '-' \n\n");
					system("pause");
				}				
				
				
			}// comparando o cliente
			
			
		}// if se tem cliente cadastrado
		else{
			printf("\n\t\t\tPor favor, cadastre um cliente!!\n\n");
			system("pause");
			
		}
		
		
	} // realizar venda
	else if(op==4){
		
		system("cls");
		
		printf("Gerar Relatorio:\n");
		
		if(i>ii){
		
		
			printf("\t\t\t\tPesquisa por nome do cliente:\n\n");
			
			printf("Informe o nome do cliente:");
			fflush(stdin);
			gets(nome_cliente_pesq);
			
			for(int cont=1; cont<i; cont++){
				if(strcmp(strlwr(nome_cliente[cont]),nome_cliente_pesq)==0){
					
					printf("Cliente encontrado:\n");
					
					system("pause");
					system("cls");
					
					printf("\nNome do cliente: %s\n\n", nome_cliente[cont]);
			
					printf("\nInforme o telefone: %i", telefone[cont]);
			
					printf("\n\t\t\tEndereco de entrega:\n");
			
					printf("Rua: %s", rua[cont]);
			
					printf("\tcasa: %i",casa[cont]);
			
					printf("\tBairro: %s",bairro[cont]);
					
					
					printf("\n\t\t\tPEDIDO:\n");
					
					
					printf("\nNome da bebida: %s", decricao[cont]);
					
					printf("\nQuantidade adquirida: %i", qtd_pesq[cont]);
					
					printf("\nValor total da compra: %f", valor_total[cont]);
					
					printf("\nValor pago: %f", valor_pago[cont]);
					
					printf("\nTroco: %f", troco[cont]);
					
					system("pause");
					
					
					
					
					
					
					
				}// comparando nome
				else{
					printf("\t\t\tCliente não cadastrado ou escrita errado '-' \n\n");
					system("pause");
				}
				
				
			}// 
			
			}// if pra ver se tem cliente cadastrado '-'
			else{
			printf("\n\t\t\tPor favor, cadastre um cliente!!\n\n");
			system("pause");
			
		}
	}// Gerar relatorio 
	
	else{
		printf("\t\t\t Opcao invalida!!\n\n ");
		system("pause");
	}
	
		
	}while(op!=0);// loop menu	
	
}//main
