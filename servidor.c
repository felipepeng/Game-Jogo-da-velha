#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

void escolherPalavra(char *palavraEscolhida) {
    // Palavras disponíveis
    const char *palavras[] = {
        "programacao",
        "computador",
        "engenharia",
        "software",
        "dados",
        "ciencia",
        "internet",
        "vpn",
        "byte",
		"bit",
		"rede",
		"chip",
		"cpu",
		"rAM",
		"web",
		"dados",
		"jorge",
		"computador",
		"internet",
		"ciberseguranca",
		"firewall",
		"servidor",
		"codigo",
		"cache",
		"driver",
		"backup",
		"algoritmo"
    };
    
    // Total de palavras no array
    int totalPalavras = sizeof(palavras) / sizeof(palavras[0]);
    
    // Inicializar o gerador de números aleatórios
    srand(time(NULL));

    // Escolher uma palavra aleatória
    int indiceAleatorio = rand() % totalPalavras;

    // Copiar a palavra escolhida para a variável de saída
    strcpy(palavraEscolhida, palavras[indiceAleatorio]);
}

int main() {
    char palavra[50];

    // Escolher uma palavra aleatória
    escolherPalavra(palavra);

    printf("A palavra escolhida aleatoriamente foi: %s\n", palavra);

    return 0;
}
