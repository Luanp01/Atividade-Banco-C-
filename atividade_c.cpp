#include <stdio.h>

int main (){
	
	int senha;
    float saldo = 500;
    float maior_dep = 0;
    int opcao;
    
	
	do {
		
	printf("Crie uma senha numerica de 4 digios: \n");
	scanf("%d", &senha);
	
	if (senha < 1000 || senha > 9999) {
		printf("ERRO: A senha tem que ter somente 4 digitos e nao pode ser negativa!\n");
	}
}
	while (senha < 1000 || senha > 9999);

	printf("Conta criada!\n");
	printf("Seu saldo: R$ %.2f\n", saldo);
	
	do {
		printf("\n===MENU PRINCIPAL===\n");
		printf(" 1 - Depositar\n");
		printf(" 2 - Sacar\n");
		printf(" 3 - Consultar Saldo e Estatisticas\n");
		printf(" 4 - Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				float valor_deposito;
				
				printf("Digite o valor do deposito: ");
				scanf("%f", &valor_deposito);
				
				if (valor_deposito <= 0) {
					printf ("Valor invalido!\n");
				}
				else {
					saldo = saldo + valor_deposito;
					
					if (valor_deposito > maior_dep) {
						maior_dep = valor_deposito;
					}
					printf("Deposito de R$ %.2f realizado com sucesso!\n", valor_deposito);	
				}
				break;
			
			case 2:
				int senha_inserida;
				float valor_saque;
				
				printf("Digite a sua senha de 4 digitos: ");
				scanf("%d", &senha_inserida);
				
				if (senha_inserida != senha) {
					printf("Senha incorreta! Operacao cancelada!\n");
					break;
				}
				printf("Digite o valor do saque: ");
                scanf("%f", &valor_saque);
                
                if (valor_saque >  saldo) {
                	printf("Saldo insuficiente!\n");
				}
				else {
					saldo = saldo - valor_saque;
					printf("Saque de R$ %.2f realizado com sucesso!\n", valor_saque);
				}
				break;
			
			case 3:
				printf("\n===SALDO E ESTATISTICAS===\n");
				printf("Saldo atual: R$ %.2f\n", saldo);
				printf("Maior deposito realizado: R$ %.2f\n", maior_dep);
				break;
				
			case 4:
				printf("Obrigado por usar nosso banco!\n");
				break;
				
			default:
				printf("Opcao invalida! Digite um numero de 1 a 4.\n");
				break;
		}
	}
	while (opcao != 4);
	
	return 0;
}
