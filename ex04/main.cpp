#include "utils.h"

void print_truth_table(const string& formula) {
    map<char, int> variables;
    map<char, int>::iterator it;

    if (parse(formula)) {
        cout << "Error: Syntax is not correct" << endl;
        return;
    }

    extract_variables(formula, variables);
    print_header(formula, variables);

    int n = variables.size();
    for (int i = 0; i < (1 << n); i++) {
        int k = 0;
        for (it = variables.begin(); it != variables.end(); it++) {
            it->second = (i >> (n - 1 - k)) & 1;
            k++;
        }
        print_row(variables, eval_formula(formula, variables));
    }
    cout << endl;
}

int main() {

    cout << "=== Subject test ===" << endl;
    print_truth_table("AB&C|");

    cout << "=== Single variable ===" << endl;
    print_truth_table("A");
    print_truth_table("A!");

    cout << "=== Two variables ===" << endl;
    print_truth_table("AB&");
    print_truth_table("AB|");
    print_truth_table("AB^");
    print_truth_table("AB>");
    print_truth_table("AB=");

    cout << "=== More variables ===" << endl;
    print_truth_table("AB&C^");
    print_truth_table("AB|C&A^B|C^");


    cout << "=== Error cases ===" << endl;
    print_truth_table("");
    print_truth_table("A&");
    print_truth_table("AB");

    return 0;
}
