#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABET 2

// Define the DFA transition function
int dfa_transition[MAX_STATES][MAX_ALPHABET];

// Function to check if the input string is accepted by the DFA
bool is_string_accepted(char input_string[], int start_state, int final_state) {
    int current_state = start_state;

    printf("Path of Transition: ");
    for (int i = 0; input_string[i] != '\0'; i++) {
        int input = input_string[i] - '0'; // Assuming the input alphabet is 0 and 1
        printf("%d -> ", current_state);
        if (input >= 0 && input < MAX_ALPHABET) {
            current_state = dfa_transition[current_state][input];
        } else {
            printf("Invalid input character %c\n", input_string[i]);
            return false;
        }
    }
    printf("%d\n", current_state);

    // Check if the final state is an accepting state.
    return current_state == final_state;
}

int main() {
    int num_states, start_state, final_state;
    char input_string[100];

    printf("Enter the number of states: ");
    scanf("%d", &num_states);

    printf("Enter the start state: ");
    scanf("%d", &start_state);

    printf("Enter the final state: ");
    scanf("%d", &final_state);

    // Input the transition function based on user-defined states and alphabet.
    printf("Enter the transition function:\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < MAX_ALPHABET; j++) {
            printf("Transition from state %d for input %d: ", i, j);
            scanf("%d", &dfa_transition[i][j]);
        }
    }

    printf("Enter the input string: ");
    scanf("%s", input_string);

    // Check if the input string is accepted by the DFA
    if (is_string_accepted(input_string, start_state, final_state)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}