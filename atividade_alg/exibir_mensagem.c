#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma region Funcoes Atividade 1.1

void exibir_mensagem() {
	printf("Aprendendo procedimentos em C!\n\n");
}

#pragma endregion

#pragma region Funcoes Atividade 1.2

void saudacao(const char* nome) {
	printf("Seja bem-vindo(a) %s\n\n", nome);
}

#pragma endregion

#pragma region Funcoes Atividade 1.3

void soma(float num1, float num2) {

	float resultado = num1 + num2;

	printf("O resultado da soma e %f", resultado);
}

void subtracao(float num1, float num2) {

	float resultado = num1 - num2;

	printf("\nO resultado da subtracao e %f", resultado);
}

void multiplicacao(float num1, float num2) {

	float resultado = num1 * num2;

	printf("\nO resultado da multiplicacao e %f", resultado);
}

void divisao(float num1, float num2) {

	if (num2 != 0) {
		float resultado = num1 / num2;

		printf("\nO resultado da Divisao: %.2f\n", resultado);
	}
	else {
		printf("\nErro: divisao por zero!");
	}
}

#pragma endregion

#pragma region Funcoes Atividade 2.1

void calcular_quadrado(float numero) {
	int resultado = numero * numero;
	printf("\nO quadrado do numero digitado e: %d\n", resultado);
}

#pragma endregion

#pragma region Funcoes Atividade 2.2

void verificar_paridade(int num) {
	int resultado;

	resultado = num % 2;

	if (resultado == 0) {
		printf("1\n");
	}
	else {
		printf("0\n");
	};
}
#pragma endregion

#pragma region Funcoes Atividade 2.3

#pragma endregion

#pragma region Funcoes Atividade 3.1

void calcular_fatorial(int num) {

	int result = num;

	for (int i = num; i > 0; i--)
	{
		result = result * i;

	};

	printf("\nO fatorial do numero digitado eh: %d\n", result);

}
#pragma endregion

#pragma region Funcoes Atividade 3.2

void verificar_primo(int num) {

	int resultado = num;
	int cont_div = 0;

	for (int i = 1; i <= num; i++)
	{
		resultado = num % i;

		if (resultado == 0) {
			cont_div++;
		}
	};

	if (cont_div == 2) {
		printf("\n1\n");
	}
	else {
		printf("\n0\n");

	};

}

#pragma endregion

#pragma region Funcoes Atividade 3.3

void calcular_potencia(int base, int expoente) {

	int resultado = 1;

	for (int i = 1; i <= expoente; i++)
	{
		resultado = resultado * base;
	};

	printf("\nO resultado eh: %d\n", resultado);
}

#pragma endregion

#pragma region Funcoes Atividade 4.1
void operacaoSimples(int operacao_digitada) {
	float num1, num2;
	printf("\nDigite dois numeros: ");

	if (scanf_s("%f %f", &num1, &num2) != 2) {
		printf("Erro ao ler os numeros.\n\n");
		return 1;
	}

	switch (operacao_digitada) {
	case 1:
		soma(num1, num2);
	case 2:
		subtracao(num1, num2);
	case 3:
		multiplicacao(num1, num2);
	case 4:
		divisao(num1, num2);
	case 5:
		calcular_potencia(num1, num2);
	default:
		return 0;
	}
}

void operacaoComplexa(int operacao_digitada) {
	int num1;

	printf("\nDigite um numero inteiro nao negativo: ");
	scanf_s("%d", &num1);

	switch (operacao_digitada) {
	case 6:
		calcular_fatorial(num1);
	case 7:
		verificar_primo(num1);
	default:
		return 0;
	}
}

void menu() {
	int operacao_digitada;

	printf("\nDigite uma opcao;\n");
	printf("\n Para soma, digite 1; ");
	printf("\n Para subtracao, digite 2; ");
	printf("\n Para multiplicacao, digite 3; ");
	printf("\n Para divisao, digite 4; ");
	printf("\n Para Potenciação, digite 5; ");
	printf("\n Para Fatorial, digite 6; ");
	printf("\n Para Verificacao de numero primo digite 7 \n\n; ");

	scanf_s("%d", &operacao_digitada);

	if (operacao_digitada == 0 || operacao_digitada > 7) {
		return 0;
	};

	if (operacao_digitada < 6) {
		operacaoSimples(operacao_digitada);
	}
	else {
		operacaoComplexa(operacao_digitada);
	}
	menu();
}
#pragma endregion

#pragma region Funcoes Atividade 4.2

int fibonacci(int n) {

	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

void exibir_fibonacci(int n) {
	printf("Sequência de Fibonacci com %d termos:\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d ", fibonacci(i));
	}
	printf("\n");
}

int getFibonacci() {
	int n;
	printf("Digite um número inteiro positivo: ");
	scanf_s("%d", &n);

	exibir_fibonacci(n);

	printf("O %dº termo da sequência de Fibonacci é: %d\n", n, fibonacci(n - 1));

	return 0;
}
#pragma endregion

#pragma region DESAFIO

// Função para calcular a média aritmética
float calcularMedia(float numeros[], int n) {
	float soma = 0.0;
	for (int i = 0; i < n; i++) {
		soma += numeros[i];
	}
	return soma / n;
}

// Função para ordenar os números (necessária para calcular a mediana)
void ordenar(float numeros[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (numeros[j] > numeros[j + 1]) {
				float temp = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = temp;
			}
		}
	}
}

// Função para calcular a mediana
float calcularMediana(float numeros[], int n) {
	ordenar(numeros, n);
	if (n % 2 == 0) {
		return (numeros[n / 2 - 1] + numeros[n / 2]) / 2.0;
	}
	else {
		return numeros[n / 2];
	}
}

// Função para encontrar o maior valor
float encontrarMaior(float numeros[], int n) {
	float maior = numeros[0];
	for (int i = 1; i < n; i++) {
		if (numeros[i] > maior) {
			maior = numeros[i];
		}
	}
	return maior;
}

// Função para encontrar o menor valor
float encontrarMenor(float numeros[], int n) {
	float menor = numeros[0];
	for (int i = 1; i < n; i++) {
		if (numeros[i] < menor) {
			menor = numeros[i];
		}
	}
	return menor;
}

// Função para calcular o desvio padrão
float calcularDesvioPadrao(float numeros[], int n) {
	float media = calcularMedia(numeros, n);
	float soma = 0.0;
	for (int i = 0; i < n; i++) {
		soma += pow(numeros[i] - media, 2);
	}
	return sqrt(soma / n);
}

#pragma endregion


int main() {

#pragma region Chamando Atividade 1.1	

	exibir_mensagem();

#pragma endregion

#pragma region Chamando Atividade 1.2	

	saudacao("Kaique");
	saudacao("Leticia");
	saudacao("Professor");

#pragma endregion

#pragma region Chamando Atividade 1.3	

	float num1, num2;
	printf("\nDigite dois numeros: ");

	if (scanf_s("%f %f", &num1, &num2) != 2) {
		printf("Erro ao ler os numeros.\n\n");
		return 1;
	}

	soma(num1, num2);
	subtracao(num1, num2);
	multiplicacao(num1, num2);
	divisao(num1, num2);

#pragma endregion

#pragma region Chamando Atividade 2.1

	int numero;
	printf("\nDigite um numero: ");
	scanf_s("%d", &numero);
	calcular_quadrado(numero);

#pragma endregion

#pragma region Chamando Atividade 2.2
	int numpar;

	printf("\nDigite um numero inteiro: ");

	scanf_s("%d", &numpar);

	verificar_paridade(numpar);

#pragma endregion

#pragma region Chamando Atividade 2.3

#pragma endregion

#pragma region Chamando Atividade 3.1

	int numfatorial;

	printf("\nDigite um numero inteiro nao negativo: ");

	scanf_s("%d", &numfatorial);

	calcular_fatorial(numfatorial);

#pragma endregion

#pragma region Chamando Atividade 3.2

	int numprimo;

	printf("\nDigite um numero inteiro: ");

	scanf_s("%d", &numprimo);

	verificar_primo(numprimo);

#pragma endregion

#pragma region Chamando Atividade 3.3

	int num_base;
	int num_exp;

	printf("\nDigite um numero base: ");

	scanf_s("%d", &num_base);

	printf("\nDigite um numero expoente: ");

	scanf_s("%d", &num_exp);

	calcular_potencia(num_base, num_exp);

	return 0;

#pragma endregion

#pragma region Chamando Atividade 4.1

	menu();

#pragma endregion

#pragma region Chamando Atividade 4.2

	getFibonacci();

#pragma endregion

#pragma region DESAFIO

#define MAX_NUMEROS 100

	int n;
	printf("Quantos números você deseja inserir? ");
	scanf_s("%d", &n);

	if (n <= 0) {
		printf("Número inválido de elementos.\n");
		return 1;
	}

	float* numeros = (float*)malloc(n * sizeof(float));
	if (numeros == NULL) {
		printf("Erro de alocação de memória.\n");
		return 1;
	}

	printf("Digite os números:\n");
	for (int i = 0; i < n; i++) {
		printf("Número %d: ", i + 1);
		scanf_s("%f", &numeros[i]);
	}

	// Calculando e exibindo os resultados
	printf("\n--- Resultados ---\n");
	printf("Média Aritmética: %.2f\n", calcularMedia(numeros, n));
	printf("Mediana: %.2f\n", calcularMediana(numeros, n));
	printf("Maior Valor: %.2f\n", encontrarMaior(numeros, n));
	printf("Menor Valor: %.2f\n", encontrarMenor(numeros, n));
	printf("Desvio Padrão: %.2f\n", calcularDesvioPadrao(numeros, n));

	free(numeros); // Liberar a memória alocada
	return 0;

#pragma endregion

}
