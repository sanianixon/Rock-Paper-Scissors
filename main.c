#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int predict_user_move(int history[]) {
    int max_count = history[0];
    int max_indices[3] = {0, 0, 0}; // max indices tie
    int max_count_indices = 1;

    for (int i = 1; i < 3; i++) {
        if (history[i] > max_count) {
            max_count = history[i];
            max_indices[0] = i;
            max_count_indices = 1;
        } else if (history[i] == max_count) {
            max_indices[max_count_indices++] = i;
        }
    }

    // If tie, pick randomly among tied max choices
    if (max_count_indices == 1) {
        return max_indices[0];
    } else {
        int r = rand() % max_count_indices;
        return max_indices[r];
    }
}

int counter_move(int predicted_move) {
    return (predicted_move + 1) % 3;
}

int main() {
    char user_input[20];
    const char *choices[] = {"rock", "paper", "scissors"};
    int user_choice, computer_choice;
    int user_history[3] = {0, 0, 0};

    srand(time(NULL));

    printf("Welcome to Rock-Paper-Scissors with improved learning!\n");
    printf("Type 'rock', 'paper', or 'scissors' to play.\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printf("\nYour move: ");
        scanf("%19s", user_input);

        if (strcmp(user_input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        user_choice = -1;
        for (int i = 0; i < 3; i++) {
            if (strcmp(user_input, choices[i]) == 0) {
                user_choice = i;
                break;
            }
        }

        if (user_choice == -1) {
            printf("Invalid input! Please enter rock, paper, or scissors.\n");
            continue;
        }

        user_history[user_choice]++;

        int total_moves = user_history[0] + user_history[1] + user_history[2];

        if (total_moves < 3) {
            // Not enough data, pick random
            computer_choice = rand() % 3;
        } else {
            int predicted = predict_user_move(user_history);
            computer_choice = counter_move(predicted);
            printf("[DEBUG] User history: rock=%d paper=%d scissors=%d\n", user_history[0], user_history[1], user_history[2]);
            printf("[DEBUG] Predicted user move: %s\n", choices[predicted]);
            printf("[DEBUG] Computer move (counter): %s\n", choices[computer_choice]);
        }

        printf("Computer chose: %s\n", choices[computer_choice]);

        if (user_choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((user_choice == 0 && computer_choice == 2) ||
                   (user_choice == 1 && computer_choice == 0) ||
                   (user_choice == 2 && computer_choice == 1)) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }
    }

    return 0;
}
