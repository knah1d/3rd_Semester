#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> nfa_transitions;

void add_transition(int from_state, int input, int to_state) {
    nfa_transitions[from_state][input].push_back(to_state);
}

bool is_string_accepted_nfa(char input_string[], int current_state, int final_state, int input_index) {
    if (input_string[input_index] == '\0') {
        return current_state == final_state;
    }

    int input = input_string[input_index] - 48;
    bool result = false;

    cout << current_state << " -> ";
    
    for (int next_state : nfa_transitions[current_state][input]) {
        result = result || is_string_accepted_nfa(input_string, next_state, final_state, input_index + 1);
    }

    return result;
}

int main() {
    int num_states, start_state, final_state;
    char input_string[100];

    //freopen("input.txt", "r", stdin);

    cout << "Enter the number of states: ";
    cin >> num_states;

    cout << "Enter the start state: ";
    cin >> start_state;

    cout << "Enter the final state: ";
    cin >> final_state;

    nfa_transitions.resize(num_states, vector<vector<int>>(2));
    cout << "Enter the transition function" << endl;
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < 2; j++) {
            int num_transitions;
            cout << "Number of transitions from state " << i << " for input " << j << ": ";
            cin >> num_transitions;

            cout << "Transitions for state " << i << " and input " << j << ": ";
            for (int k = 0; k < num_transitions; k++) {
                int to_state;
                cin >> to_state;
                add_transition(i, j, to_state);
            }
        }
    }

    cout << "Enter the input string: ";
    cin >> input_string;

    if (is_string_accepted_nfa(input_string, start_state, final_state, 0)) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }

    return 0;
}
