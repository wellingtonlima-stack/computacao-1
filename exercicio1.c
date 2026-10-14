#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	srand(time(0));

	int numero_secreto1, numero_secreto2;
	int chute1, chute2;
	int qtd_tentativas;
	int continua = 1;

	while(continua)
	{
		qtd_tentativas = 1;

		// Sorteia os dois números entre 1 e 20
		numero_secreto1 = (rand() % 20) + 1;
		numero_secreto2 = (rand() % 20) + 1;

		do
		{
			// Exibe os números secretos (remova esta linha se quiser esconder do jogador)
			printf("\nOs números secretos são %d e %d \n", numero_secreto1, numero_secreto2);

			printf("Digite o primeiro número: ");
			scanf("%d", &chute1);

			printf("Digite o segundo número: ");
			scanf("%d", &chute2);

			// Se pelo menos um dos chutes for diferente do número secreto correspondente
			if (chute1 != numero_secreto1 || chute2 != numero_secreto2)
			{
				qtd_tentativas = qtd_tentativas + 1;

				// Feedback visual de acertos parciais
				if (chute1 == numero_secreto1)
					printf(">> Você acertou apenas o PRIMEIRO número!\n");
				else if (chute2 == numero_secreto2)
					printf(">> Você acertou apenas o SEGUNDO número!\n");
				else
					printf(">> Você errou OS DOIS números!\n");
			}

		}
		while (chute1 != numero_secreto1 || chute2 != numero_secreto2);

		printf("\nParabéns! Você acertou os dois números!\n");
		printf("Quantidade de tentativas: %d\n", qtd_tentativas);

		if (qtd_tentativas <= 3)
		{
			printf("Você é ÓTIMO!\n");
			continua = 0;
		}
		else if (qtd_tentativas <= 6)
		{
			printf("Você é BOM!\n");
			continua = 0;
		}
		else if (qtd_tentativas <= 10)
		{
			printf("Você é FRACO!\n");
		}
		else
		{
			printf("Você é PÉSSIMO!!!\n");
		}
	}

	return 0;
}
