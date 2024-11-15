#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

#define MAX_PLAYERS 2
#define BUFFER_SIZE 1024
#define PORT 8080


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
        "vpn"
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

void initialize_winsock() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
}

int main() {
	initialize_winsock();
    SOCKET server_socket, client_socket[MAX_PLAYERS];
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int num_players = 0, correct_guesses = 0;
    
    // Escolher uma palavra aleatória
    char palavra[50];
    
    escolherPalavra(palavra);
    printf("A palavra escolhida aleatoriamente foi: %s\n", palavra);
    
    char display_word[strlen(palavra)];
    
    int i;
    for (i = 0; i < strlen(palavra); i++) {
        display_word[i] = '_';
    }
    
    display_word[strlen(palavra)] = '\0';

    
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        exit(EXIT_FAILURE);
    } else {
    	printf("Socket criado\n");
	}
	
	// Bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    
    listen(server_socket, MAX_PLAYERS);

    printf("Waiting for players to join...\n");
    
    while (num_players < MAX_PLAYERS) {
        SOCKET new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_socket == INVALID_SOCKET) {
            printf("Accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        client_socket[num_players++] = new_socket;
        printf("Player %d connected.\n", num_players);
        char welcome_message[BUFFER_SIZE];
        snprintf(welcome_message, sizeof(welcome_message), "Welcome Player %d!\n", num_players);
        send(new_socket, welcome_message, strlen(welcome_message), 0);
    }

    return 0;
}
