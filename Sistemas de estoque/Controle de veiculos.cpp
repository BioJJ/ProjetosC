#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){
	
	int op1,op2,op3,op4;
	
	char loginpesq[10],Login_gerente[10], Login_gerente2[10];
	int senhapesq,senha_gerente, senha_gerente2;
	
	// variaveis do cadastro de carro
	char marca1[10], marca2[10], modelo1[10], modelo2[10], chassi1[10], chassi2[10], chassipesq[10],modelopesq[10];
	float valor1, valor2,valor_total;
	int qtd,qtd1, qtd2, ano1, ano2;	
	
	// variaveis do cadastrar vendedor 
	char vendedor1[10], vendedor2[10];
	int matricula1, matricula2;
	
	// cadastro de cliente
	char cliente1[10], cliente2[10],cpf1[12], cpf2[12];
	
	
strcpy(Login_gerente,"admin");
senha_gerente=123;


do{
	system("cls");
printf("Braga Veiculo\n");       
printf("Login: ");       
fflush(stdin);
gets(loginpesq);
printf("Senha: ");       
scanf("%i",&senhapesq);

if(strcmp(strlwr(loginpesq),Login_gerente)==0 && senhapesq==senha_gerente || (strcmp(strlwr(loginpesq),Login_gerente2)==0 && senhapesq==senha_gerente2)){
 do{
 system("cls");
 printf("Bem vindo Gerente\n");    
 printf("1-Cadastrar Carro\n");    
 printf("2-Cadastrar Vendedor\n");    
 printf("3-Pesquisar por Chassi\n");    
 printf("0-Sair\n");    
 scanf("%i",&op2);
 system("pause");
 system("cls");
	
	if(op2==1){
	 system("cls");
	 printf("Cadastro de carro\n");
	 printf("Informe a marca:");
	 fflush(stdin);
	 gets(marca1);
	 printf("Informe o modelo:");
	 fflush(stdin);
	 gets(modelo1);
	 printf("Informe o ano do carro:");
	 scanf("%i",&ano1);
	 printf("Informe o valor do carro:");
	 scanf("%f",&valor1);
	 printf("Informe o Quantidade");
	 scanf("%i",&qtd1);
	 printf("Informe o chassi:");
	 fflush(stdin);
	 gets(chassi1);
	 
	 system("cls");
	 printf("Carro 1º cadastrado\n");
	 system("pause");
	 system("cls");
	 
	 printf("Cadastre o 2º carro\n");
	 printf("Informe a marca:");
	 fflush(stdin);
	 gets(marca2);
	 printf("Informe o modelo:");
	 fflush(stdin);
	 gets(modelo2);
	 printf("Informe o ano do carro:");
	 scanf("%i",&ano2);
	 printf("Informe o valor do carro:");
	 scanf("%f",&valor2);
	 printf("Informe o Quantidade");
	 scanf("%i",&qtd2);
	 printf("Informe o chassi:");
	 fflush(stdin);
	 gets(chassi2);
	 
	 system("cls");
	 printf("Carro 2º cadastrado\n");
	 system("pause");
	 system("cls");
     
	
	}// cadastrar carro
	else if(op2==2){
		
		system("cls");
		printf("Cadastro de Vendedor\n");
		
		printf("Informe o nome: ");
		fflush(stdin);
		gets(vendedor1);
		printf("Matricula:");
		scanf("%i", &matricula1);
		
	 system("cls");
	 printf("Vendedor 1º cadastrado\n");
	 system("pause");
	 system("cls");
	 
	 printf("Cadastre o 2º Vendedor\n");
		
		printf("Informe o nome: ");
		fflush(stdin);
		gets(vendedor2);
		printf("Matricula:");
		scanf("%i", &matricula2);
		
		 system("cls");
	 printf("Vendedor 2º cadastrado\n");
	 system("pause");
	 system("cls");
		
		
		
	}// cadastrar vendedor
	else if(op2==3){
		system("cls");
	 
	 printf("Pesquise por chassi\n");
	 printf("Informe o chassi: ");
	 fflush(stdin);
	 gets(chassipesq);
	 
	 if((strcmp(strlwr(chassipesq),chassi1)==0 )){
	 	printf("carro encontrado\n");
	 	system("pause");
	 system("cls");
	 
	 printf("Marca: %s", marca1);
	 printf("Modelo: %s", modelo1);
	 printf("Ano: %i", ano1);
	 printf("Chassi: %s", chassi1);
	 printf("Valor: %f", valor1);
	 printf("Quantidade: %i", qtd1);
	 
	 }// if se chassi 1 
	 else if((strcmp(strlwr(chassipesq),chassi2)==0 )){
	 	printf("carro encontrado");
	 	system("pause");
	 system("cls");
	 
	 printf("Marca: %s", marca2);
	 printf("Modelo: %s", modelo2);
	 printf("Ano: %i", ano2);
	 printf("Chassi: %s", chassi2);
	 printf("Valor: %f", valor2);
	 printf("Quantidade: %i", qtd2);
	 
	 }// if se chassi 2
	 else{
	 	printf("Carro não encontrado");
	 }
		
		
	}// Pesquisar por chassi
	else if(op2==0){
	 				
		
	}// sair
	else {
		printf("opçao invalida");
		system("pause");
	 system("cls");
	}
	
	
}while(op2!=0);
	
}// Gerente 

else if(strcmp(strlwr(loginpesq),vendedor1)==0 && senhapesq==matricula1 || (strcmp(strlwr(loginpesq),vendedor2)==0 && senhapesq==matricula2)){

do{

	system("cls");
	
	printf("Bem vindo Vendedor\n");
	printf("1 - Realizar venda:\n");
	printf("2 - Cadastrar Cliente:\n");
	printf("3 - Gerar Nota Fiscal:\n");
	printf("0- sair\n");
	scanf("%i", &op3);
	
	if(op3==1){
		
		system("cls");
		
		printf("Realizar venda\n");
		
	 printf("Pesquise por modelo");
	 printf("Informe o modelo");
	 fflush(stdin);
	 gets(modelopesq);
	 
	 if((strcmp(strlwr(modelopesq),modelo1)==0 )){
	 	
	 	printf("Valor do modelo: %f", valor1);
	 	
	 	printf("\nInforme a quantidade desejada:");
	 	scanf("%i", &qtd);
	 	
	 	if(qtd<=qtd1){
	 		
	 		valor_total=valor1*qtd;
	 		
	 		printf("Valor total: %.2f", valor_total);
	 		
	 		qtd1=qtd1-qtd;
	 		
	 		printf("venda realizada\n");
	 		
	 		system("pause");
		 	system("cls");
	 		
		 }else{
		 	printf("estoque insuficiente\n");
		 	system("pause");
		 	system("cls");
		 }
	 }
		
		
		
	} //realizar venda
	else if(op3==2){
		system("cls");
		
		printf("Cadastro de Cliente\n");
		printf("Informe o nome:");
		fflush(stdin);
		gets(cliente1);
		printf("Informe o CPF:");
		fflush(stdin);
		gets(cpf1);
		
		system("cls");
		printf("Cliente 1 cadastrado\n");
		system("pause");
		system("cls");
		
		printf("Informe o nome:");
		fflush(stdin);
		gets(cliente2);
		printf("Informe o CPF:");
		fflush(stdin);
		gets(cpf2);
		
		system("cls");
		printf("Cliente 2 cadastrado\n");
		system("pause");
		system("cls");
		
		
		
		
		
	}// cadastrar cliente
	
	else if(op3==3){
		
		
		
	}// Gerar nota fiscal
	
	else if(op3==0){
		
	}else{
			printf("opçao invalida");
		system("pause");
	 system("cls");
	}
	
	
	
}while(op3!=0);	
	
}// vendedor


else{//fim login
printf("Login e senha invalida\n");
printf("Deseja continuar no sistema\n");
printf("1-Continuar\n");
printf("0-Sair do sistema\n");
scanf("%i",&op1);
if(op1==0){
exit(0);     
}//para sair direto sistema

}

}while(op1!=0);

}
