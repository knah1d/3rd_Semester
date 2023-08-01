#include <stdio.h>
#include <string.h>

// Define the states
#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3

// Define the alphabet
#define ZERO '0'
#define ONE '1'

// Define the transition function as a 2D array
int delta[4][2] = {
    {Q1, Q3}, // transitions from Q0
    {Q0, Q2}, // transitions from Q1
    {Q3, Q3}, // transitions from Q2
    {Q3, Q3}  // transitions from Q3
};

// Define the initial state
int q0 = Q0;

// Define the final state(s) as an array
int F[1] = {Q2};

// Check if a state is final or not
int is_final(int q) {
    for (int i = 0; i < 1; i++) {
        if (F[i] == q) {
            return 1;
        }
    }
    return 0;
}

// Simulate the DFA on an input string
void simulate(char* input) {
    // Initialize the current state to the initial state
    int q = q0;
    // Loop through each symbol of the input string
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        // Check if the symbol is valid or not
        if (c == ZERO || c == ONE) {
            // Update the current state using the transition function
            q = delta[q][c - ZERO];
        } else {
            // Invalid symbol, reject the input
            printf("Invalid input: %s\n", input);
            return;
        }
    }
    // Check if the current state is final or not
    if (is_final(q)) {
        // Accept the input
        printf("Accepted: %s\n", input);
    } else {
        // Reject the input
        printf("Rejected: %s\n", input);
    }
}

// Test some inputs
int main() {
    simulate("001");   // Accepted
    simulate("010");   // Rejected
    simulate("10010"); // Accepted
    simulate("10101"); // Rejected
    simulate("0110");  // Rejected
    simulate("abc");   // Invalid input
}
