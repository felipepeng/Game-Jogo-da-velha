#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_ATTEMPTS 10

void displayWord(const char *word, const char *guessedLetters) {
	int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i])) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int isWordGuessed(const char *word, const char *guessedLetters) {
	int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (!strchr(guessedLetters, word[i])) {
            return 0; // Palavra ainda n�o foi adivinhada
        }
    }
    return 1; // Palavra foi completamente adivinhada
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char word[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH] = {0};
    char guess;
    char chute[50];
    int attemptsLeft = MAX_ATTEMPTS;
    int currentPlayer = 1;

    // Configura��o da palavra secreta
    printf("Servidor, digite a palavra secreta: ");
    scanf("%s", word);

    // Convertendo para letras mai�sculas para padronizar
    int i;
    for (i = 0; word[i]; i++) {
        word[i] = toupper(word[i]);
    }

    clearScreen();

    // Loop do jogo
    while (attemptsLeft > 0) {
    	system("cls");
        printf("\nJogador %d, e a sua vez!\n", currentPlayer);
        displayWord(word, guessedLetters);
        printf("Tentativas restantes: %d\n", attemptsLeft);
        printf("Letras tentadas: " );
        int i;
        for (i = 0; guessedLetters[i] != '\0'; i++) {
        printf("%c ", guessedLetters[i]); // Exibir cada letra seguida de um espa�o
    	}
   		 printf("\n");
        printf("Digite uma letra: ");
        scanf(" %s", &chute);
        //Pega apenas a primeira letra digitada
		guess = chute[0];
		
        // Convertendo a letra para mai�scula
        guess = toupper(guess);

        // Verificando se a letra j� foi usada
        if (strchr(guessedLetters, guess)) {
            printf("Voc� j� tentou a letra '%c'. Tente outra.\n", guess);
            continue;
        }

        // Adicionando a letra �s letras j� tentadas
        strncat(guessedLetters, &guess, 1);

        // Verificando se a letra est� na palavra
        if (strchr(word, guess)) {
            printf("Boa! A letra '%c' esta na palavra.\n", guess);
            if (isWordGuessed(word, guessedLetters)) {
            	system("cls");
                printf("\nParabens, Jogador %d! \nVoce adivinhou a palavra: %s\n", currentPlayer, word);
                break;
            }
        } else {
            printf("Ops! A letra '%c' nao esta na palavra.\n", guess);
            attemptsLeft--;
        }

        // Alternando o jogador
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    if (attemptsLeft == 0) {
        printf("\nGame Over! Ningu�m conseguiu adivinhar a palavra: %s\n", word);
    }

    return 0;
}
