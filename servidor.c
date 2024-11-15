#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

void escolherPalavra(char *palavraEscolhida) {
    // Palavras dispon�veis
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
    
    // Inicializar o gerador de n�meros aleat�rios
    srand(time(NULL));

    // Escolher uma palavra aleat�ria
    int indiceAleatorio = rand() % totalPalavras;

    // Copiar a palavra escolhida para a vari�vel de sa�da
    strcpy(palavraEscolhida, palavras[indiceAleatorio]);
}

int main() {
    char palavra[50];

    // Escolher uma palavra aleat�ria
    escolherPalavra(palavra);

    printf("A palavra escolhida aleatoriamente foi: %s\n", palavra);

    return 0;
}
