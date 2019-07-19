#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include <time.h>

void CADASTRAR_EXAMES();
void CADASTRAR_PACIENTE();
void LISTAR_CADASTROS();
void REALIZAR_CONSULTA();
void REALIZAR_CONSULTA();
void REALIZAR_EXAME();
void LISTAR_EXAMES();
void LISTAR_PACIENTES();
void LISTAR_EXAMES_REALIZADOS();

typedef struct exames{
		char nome_exame[10][10];
		
	}exame; //registro exames
	
	typedef struct paciente{
		int cod;
		char nome_paciente[10];
		char sintomas[25][25];
		char status_exames[25];
		char exame_agendado[25];
		int cont_sintomas; // contador de sintomas 
		
		
	}paciente;	// registro paciente
	
		paciente nomep[10]; // variavel registro paciente
		exame nomee; // variavel regristo exames
		
		int op, op1,op2, op3, op4, op5,op6;
		char nomep_pesq[10];
		
		int cont, cont1,cont2,cont3;
			
		
		int cont_exame=0; //incrementador exame
		int cont_paciente=0; // incrementador paciente 
		int cont_exame_realizado=0;
		int s=1; // contador de sintomas
		int menu_exame, menu_paciente,menu_listar,menu_paciente1;
		
	
		int teste_exame=0,teste_paciente=0,teste_consulta=0;
		


int main(){
	
	for(int ind=0; ind<10;ind++){
		nomep[ind].cont_sintomas=0; 							  // INICIANDO CONTADORES  DE SINTOMAS
		nomep[ind].cod=0; 									 	 // INICIANDO O CODIGO DO PACIENTE
		strcpy(nomep[ind].status_exames,"Exame nao realizado"); //INICIANDO STATUS
	} // for
	
	do{
		
		system("color 1f");
		system("cls");
		printf("\t\t\t\t\t\t\t"__DATE__" "__TIME__"\n");
		 printf("--------------------------------------------------------------------------\n");
	     printf("\t\t\tSISTEMA UNICO DE SAUDE\t\t\t");
		 printf("\n--------------------------------------------------------------------------\n");
	     setlocale(LC_ALL,"Portuguese");
	     printf("1) CADASTRAR EXAMES\n2) CADASTRAR PACIENTE\n3) LISTAR CADASTROS\n4) REALIZAR CONSULTA MEDICA\n5) REALIZAR EXAME\n6) FINALIZAR O SISTEMA\n");
	     printf("\n--------------------------------------------------------------------------\n");
	     printf("opção: ");
	    scanf("%d",&op); 
	    
	    switch(op){
			case 1:
				system("cls");
				CADASTRAR_EXAMES();
				break;
				
			case 2:
			     system("cls");
	             CADASTRAR_PACIENTE();
			     break;
	        case 3:
	        	system("cls");
			    LISTAR_CADASTROS();
			    break;			
			    
			    case 4:
			      system("cls");
			      REALIZAR_CONSULTA();
			        break;
			        
			     case 5:
				 system("cls");
				 REALIZAR_EXAME();
				 break;   
			    
			     case 6:
				 system("cls");
				 printf("\n\n\n\n\n\n\n\t\t\tSISTEMA FINALIZANDO\n\n");
				 op=6;
				 getch();
				 break;
				 
				 default:
				 system("cls");
				 printf("\n\n\n\n\n\n\n\t\t\tOPÇÃO INVALIDA\n\n");
				 system("pause");
				 break;   
			        
			        
		}
		
		
		
	}while(op!=6);
	
}// main

void CADASTRAR_EXAMES(){
	
	do{
				system("cls");
				
				printf("Cadastre o exame:\n");
				
					printf("Informe o nome do exame %i:",cont_exame+1);
					fflush(stdin);
					gets(nomee.nome_exame[cont_exame]);
					
					system("cls");
					
					printf("\nExame %i cadastrado com sucesso\n\n",cont_exame+1);
					teste_exame++; // teste de quantidade
					cont_exame++; // Quantidade de exame
					
				
					
					printf("\nDeseja cadastrar mais exames?\n1- SIM \n0- NAO\n\nOpcao:");
					scanf("%i", &menu_exame);
					
					if(menu_exame==0){
						menu_exame=0;
					}
					
				}while(menu_exame!=0); //loop menu exame
	
	
}// CADASTRAR EXAMES

void CADASTRAR_PACIENTE(){
	
	do{
				system("cls");
				
				printf("Cadastra Paciente\n\n");
				
				printf("Informe o nome do paciente %i: ",cont_paciente+1);
				fflush(stdin);
				gets(nomep[cont_paciente].nome_paciente);
				
				system("cls");
				
				printf("Paciente %i cadastrado com sucesso\n\n", cont_paciente+1);
				nomep[cont_paciente].cod=nomep[cont_paciente].cod+cont_paciente;
				teste_paciente++; // teste de quantidade
				cont_paciente++;	 // Quantidade de paciente
			
				
                    printf("\nDeseja cadastrar mais Paciente?\n1- SIM \n0- NAO\n\nOpcao:");
					scanf("%i", &menu_paciente);
					
					switch(menu_paciente){
						
						case 0:
							menu_paciente=0;
							break;
					
					}//switch
					
				}while(menu_paciente!=0); //loop menu paciente	
				
}// CADASTRAR PACIENTE

void LISTAR_CADASTROS(){
	
		system("cls");
		
		do{
		
		 printf("\n--------------------------------------------------------------------------\n");
	     setlocale(LC_ALL,"Portuguese");
	     printf("1) LISTAR EXAMES\n2) LISTAR PACIENTE\n3) LISTAR EXAMES REALIZADO\n4) VOLTAR\n");
	     printf("\n--------------------------------------------------------------------------\n");
	     printf("opção: ");
	    scanf("%d",&op6); 
	    
	    system("cls");
	    
	    switch(op6){
	    	
	    	case 1:
	    		LISTAR_EXAMES();
	    		break;
	    		
	    	case 2:
	    		LISTAR_PACIENTES();
	    		break;
	    		
	    	case 3:
	    		LISTAR_EXAMES_REALIZADOS();
	    		break;
	    		
	    	case 4:
	    		menu_listar=0;
	    		break;
	    		
	    	default:
	    		printf("\n\n\n\n\n\n\n\t\t\tOPÇÃO INVALIDA:\n");
	    		system("pause");
	    		break;
	    	
		}// switch
			
		}while(menu_listar!=0); // loop menu listar
	
	
}// LISTAR CADASTROS

void REALIZAR_CONSULTA(){
	
	system("cls");
		if(teste_paciente==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO EXISTEM PACIENTES CADASTRAD0 NO SISTEMA\n\n");
		   system("pause");
	 } // teste para ver se existem paciente cadastrados
	 else if(teste_exame==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO EXISTEM EXAMES CADASTRAD0 NO SISTEMA\n\n");
		   system("pause");
	 }// teste para ver se existem exames cadastrados
	 else{
		
				printf("\t\tREALIZAR CONSULTA MEDICA:");
				
				printf("\nInforme o nome do paciente: ");
				fflush(stdin);
				gets(nomep_pesq); // pesquisa por nome
				
				for(cont1=0; cont1<cont_paciente;cont1++){
				if(strcmp(strlwr(nomep[cont1].nome_paciente),nomep_pesq)==0){
					printf("Paciente encontrado: %s\n\n", nomep[cont1].nome_paciente);
					
				
				do{
                    system("cls");
                    
                    printf("Paciente: %s\n\n", nomep[cont1].nome_paciente);
                    
					printf("\nInforme o sintoma: ");
					fflush(stdin);
					gets(nomep[cont1].sintomas[nomep[cont1].cont_sintomas]);
					
					system("pause");
					system("cls");
					
					printf("\nSintoma cadastrado!!\n\n");
					nomep[cont1].cont_sintomas++;
					
					
					printf("\nDeseja cadastrar mais sintomas?\n1- SIM \n0- NAO\n\nOpcao:");
					scanf("%i", &op1);
					
					if(op1==0){
						op1=0;
					}
					
				}while(op1!=0); //loop sintomas	
				
				system("cls");	
				printf("\nExames Disponiveis:");
			
				for(cont2=0; cont2<cont_exame; cont2++){
					printf("\n%i - %s", cont2+1, nomee.nome_exame[cont2]);
					
				}// listando exames disponiveis
				
				
				printf("\n\nInforme o exame para agendamento:");
				scanf("%i", &op3);
				
				printf("\n\nExame Agendado: %s\n", nomee.nome_exame[op3-1]);
				strcpy(nomep[cont1].exame_agendado,nomee.nome_exame[op3-1]);
			
			
				printf("\n\n\n\n\n\n\n\t\t\tCONSULTA REALIZADA!!\n\n");
				nomep[cont1].cod=1;
				teste_consulta++;
				system("pause");
				}// comparando o nome do paciente 
				
				
				else if(!strcmp(strlwr(nomep[cont].nome_paciente),nomep_pesq)==0 && cont1>cont_paciente){
					printf("\n\n\n\n\n\n\n\t\t\tPaciente inexistente\n");
					system("pause");
				}//else
			
		}// FOR	
	
	}//else
	
}// REALIZAR CONSULTA MEDICA

void REALIZAR_EXAME(){
	
	system("cls");
	
	if(teste_consulta==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO EXISTEM CONSULTAS REALIZADAS NO SISTEMA\n\n");
		   system("pause");
	 }// teste para ver se existem consultas realizada
	 else{
	 
				printf("Realizar Exame:\n\n");
				
				printf("Informe o nome do paciente: ");
				fflush(stdin);
				gets(nomep_pesq); // pesquisa por nome
				
				for(cont=0; cont<cont_paciente;cont++){
				if(strcmp(strlwr(nomep[cont].nome_paciente),nomep_pesq)==0 && !strcmp(nomep[cont].status_exames,"Exame realizado")==0 &&nomep[cont].cod==1){
				
					printf("Paciente encontrado: %s\n\n", nomep[cont].nome_paciente);
					
					system("cls");
					
					printf("Paciente: %s\n", nomep[cont].nome_paciente);
					
					printf("\nSintomas do paciente:");
			
				for(cont3=0; cont3<nomep[cont].cont_sintomas; cont3++){
					printf("\n - %s", nomep[cont].sintomas[cont3]);
					
				}// listando Sintomas do paciente
				
				do{
					
					printf("\nExame Agendado: %s", nomep[cont].exame_agendado);
					printf("\nStatus: %s", nomep[cont].status_exames);
					
				printf("\n\n\n\t\t\nDeseja realizar o exame? \n1- Sim 0- nao\n\n");
				scanf("%i", &op4);
				
				if(op4==1){
					strcpy(nomep[cont].status_exames,"Exame realizado");
					cont_exame_realizado++;
					system("cls");
					
					
					printf("\nExame Agendado: %s", nomep[cont].exame_agendado);
					printf("\nStatus: %s\n\n", nomep[cont].status_exames);
					printf("\n\n\n\n\n\n\n\t\t\tExame Realizado!!\n\n");
					
					
					system("pause");
				
				}else if(op4==0){
					
					system("cls");
					
					
					printf("\nExame Agendado: %s", nomep[cont].exame_agendado);
					printf("\nStatus: %s", nomep[cont].status_exames);
					printf("\n\n\n\n\n\n\n\t\t\tExame Não Realizado!!\n\n");
					
					system("pause");
					op4=1;
					
				}
			
				else{
					printf("\n\n\n\n\n\n\n\t\t\tOPÇÃO ivalida\n\n");
				}
					
					
				}while(op4!=1); // loop perguntando se deseja realizar o exame
				
				
					
				}// comparando o nome do paciente 
				
		else if(strcmp(strlwr(nomep[cont].nome_paciente),nomep_pesq)==0 && !strcmp(nomep[cont].status_exames,"Exame realizado")==0 && nomep[cont].cod==0){
					printf("\n\n\n\n\n\n\n\t\t\tPaciente %s, NÃO TEM EXAME AGENDADO\n",nomep[cont].nome_paciente);
					system("pause");
				}// else teste para paciente sem agendamento
				
				
				
			else if(strcmp(strlwr(nomep[cont].nome_paciente),nomep_pesq)==0 && strcmp(nomep[cont].status_exames,"Exame realizado")==0) {
					
					printf("\n\n\n\n\n\n\n\t\t\tPaciente %s já com exame realizado\n", nomep[cont].nome_paciente);
					system("pause");
					
				}// else teste para paciente com exame agendado
				
				}//for
				
	}// else
	
}// REALIZAR EXAME

void LISTAR_EXAMES(){
	
		if(cont_exame==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO EXISTEM EXAMES CADASTRAD0 NO SISTEMA\n");
		   system("pause");
		   LISTAR_CADASTROS();
	 }// if para ver se existem exames cadastrados
	 else{ 
	
	int listar=0;
		printf("\n\t\tEXAMES CADASTRADOS:\n\n");

	while(listar<cont_exame){
		
		printf("%i) %s \n",listar+1,nomee.nome_exame[listar]);
		
		listar++;
		
	}// while
	
	system("pause");
	LISTAR_CADASTROS();
	
}// ELSE
	
}
void LISTAR_PACIENTES(){
	
		if(cont_paciente==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO EXISTEM PACIENTES CADASTRAD0 NO SISTEMA\n\n");
		   system("pause");
		   LISTAR_CADASTROS();
	 }// if para ver se existem pacientes cadastrados
	 else{ 
	
		int listar=0;
		printf("\n\t\tPACIENTES CADASTRADOS:\n\n");

	while(listar<cont_paciente){
		
		
		
		printf("%i) %s \n", listar+1,nomep[listar].nome_paciente);
		
		listar++;
		
	}// while
	
	system("pause");
	LISTAR_CADASTROS();
	
	
	}// else
	
}
void LISTAR_EXAMES_REALIZADOS(){
		
		
		if(cont_exame_realizado==0){
  	system("cls");
		   setlocale(LC_ALL,"portuguese");
		   printf("\n\n\n\n\n\n\n\n\n\t\tNÃO EXISTEM EXAMES REALIZADOS NO SISTEMA\n\n");
		   system("pause");
		   LISTAR_CADASTROS();
	 }// if para listar as consultas realizadas
	 else{ 
	
			int listar=0;
		printf("\n\t\tEXAMES REALIZADOS:\n\n");

	while(listar<cont_exame_realizado){
		
		if(strcmp(nomep[listar].status_exames,"Exame realizado")==0){
			
			printf("\nPaciente: %s",nomep[listar].nome_paciente);
			printf("\nSintomas: ");
			
				for(cont3=0; cont3<nomep[listar].cont_sintomas; cont3++){
					printf("\n - %s", nomep[listar].sintomas[cont3]);
					
				}// listando Sintomas do paciente
				
			printf("\nExame: %s",nomep[listar].exame_agendado);
			printf("\nStatus do exame: %s",nomep[listar].status_exames);
			printf("\n-------------------------------------\n");
		}
		
	listar++;
		
	}// while
	
	system("pause");
	LISTAR_CADASTROS();
	
}// ELSE
	
}
