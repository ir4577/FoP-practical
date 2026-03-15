#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"

const char* morseTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void playMorseSound(const char* morse) {
    printf(CYAN "SIGNAL INCOMING...\n" RESET); 
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            Beep(800, 200);
        } else {
            Beep(800, 550);
        }
        Sleep(100);
    }
}

void showIntro() {
    system("cls");
    printf(CYAN BOLD "========================================\n");
    printf("   INITIALIZING NEURAL MORSE LINK...    \n");
    printf("========================================\n" RESET);
    Sleep(800);
    printf("Searching for satellites...\n");
    Sleep(500);
    printf(GREEN "CONNECTION ESTABLISHED.\n\n" RESET);
    Sleep(1000);
}

int main() {
    SetConsoleOutputCP(65001);
    srand(time(0));
    char input[10];
    int score = 0;
    int rounds = 3;

    showIntro();

    for (int i = 0; i < rounds; i++) {
        int targetIdx = rand() % 26;
        char targetLetter = 'A' + targetIdx;

        printf(BOLD "ROUND %d/%d\n" RESET, i + 1, rounds);
        printf("Transmission for letter: " YELLOW BOLD "%c\n" RESET, targetLetter);
        
        playMorseSound(morseTable[targetIdx]);

        printf("Your intercept (code): ");
        
        time_t start = time(NULL);
        scanf("%s", input);
        time_t end = time(NULL);

        double duration = difftime(end, start);

        if (duration > 10.0) { // Gave you a little more time since it's audio-only
            printf(RED "✘ TIMEOUT! Satellites lost the signal. (%.fs)\n" RESET, duration);
        } else if (strcmp(input, morseTable[targetIdx]) == 0) {
            printf(GREEN "✔ ACCESS GRANTED. Decryption successful!\n" RESET);
            score++;
        } else {
            printf(RED "✘ ACCESS DENIED. The correct code was %s\n" RESET, morseTable[targetIdx]);
        }
        printf("----------------------------------------\n\n");
        Sleep(1000);
    }

    system("cls");
    printf(CYAN BOLD "=== MISSION REPORT ===\n" RESET);
    printf("Final Score: %d/%d\n", score, rounds);
    if (score == rounds) printf(GREEN "RANK: ELITE GHOST AGENT\n" RESET);
    else if (score >= rounds/2.0) printf(YELLOW "RANK: FIELD ANALYST\n" RESET);
    else printf(RED "RANK: REJECTED - BACK TO ACADEMY\n" RESET);
    
    printf("\nPress any key to exit...");
    getch();

    return 0;
}