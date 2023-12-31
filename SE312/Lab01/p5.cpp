<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i, j, k, mid;
    char w[50];
    cin >> w;
    for (i = 0; i < w[i] != '\0'; i++)
        ;
    // cout<<i<<endl;
    if (i % 2 == 0)
        mid = i / 2;
    else
        mid = i / 2 + 1;

    for (j = i / 2 - 1, k = mid; w[k] != '\0'; j--, k++)
    {
        if (w[j] != w[k])
        {
            cout << "NOT palindrome...:(" << endl;
            return 0;
        }
    }
    cout << "PALINDROME...:)" << endl;
=======
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the DFA transition function
int dfa_transition(int state, char input) {
    // Modify the transition function based on user input
    // Example: return the transition for state 'state' and input character 'input'
}

// Function to check if the input string is accepted by the DFA
bool is_string_accepted(char input_string[], int start_state, int final_state) {
    int current_state = start_state;

    printf("Path of Transition: ");
    for (int i = 0; input_string[i] != '\0'; i++) {
        printf("%d -> ", current_state);
        current_state = dfa_transition(current_state, input_string[i]);
        if (current_state == -1) {
            printf("Invalid transition at character %c\n", input_string[i]);
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
    printf("Enter the input string: ");
    scanf("%s", input_string);

    // Check if the input string is accepted by the DFA
    if (is_string_accepted(input_string, start_state, final_state)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

>>>>>>> 5329502a4564f9befa0f1a6956bd7b18e825763c
    return 0;
}
