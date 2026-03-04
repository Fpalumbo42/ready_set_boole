#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <map>
#include <stack>

using namespace std;

bool is_symbol(char c) {
    if (c == '!' || c == '&' || c == '|' || c == '^' || c == '>' || c == '=')
        return true;
    else
        return false;
}

bool parse(const string& formula) {
    int nb_var = 0;
    int nb_binary = 0;

    for (size_t i = 0; i < formula.length(); ++i) {
        if (formula[i] >= 65 && formula[i] <= 90)
            nb_var++;
        else if (formula[i] == '!')
            continue;
        else if (is_symbol(formula[i]))
            nb_binary++;
        else
            return 1;
    }

    if (nb_var != nb_binary + 1)
        return 1;

    return 0;
}

void extract_variables(const string& formula, map<char, int>& variables) {
    for (size_t i = 0; i < formula.length(); i++) {
        if (formula[i] >= 65 && formula[i] <= 90)
            variables[formula[i]] = 0;
    }
}

bool eval_formula(const string& formula, const map<char, int>& variable) {
    int i = 0;
    long long tmp;
    long long tmp2;
    bool res;
    stack<int> st;

    while (formula[i]) {
        if (formula[i] >= 65 && formula[i] <= 90)
            st.push(variable.at(formula[i]));

        else if (formula[i] == '!' && st.size() >= 1) {
            tmp = st.top();
            st.pop();
            res = !tmp;
            st.push(res);
        }

        else if (is_symbol(formula[i]) && st.size() >= 2) {
            tmp = st.top();
            st.pop();
            tmp2 = st.top();
            st.pop();

            if (formula[i] == '&')
                res = tmp2 & tmp;
            else if (formula[i] == '|')
                res = tmp2 | tmp;
            else if (formula[i] == '^')
                res = tmp2 ^ tmp;
            else if (formula[i] == '>')
                res = !tmp2 | tmp;
            else if (formula[i] == '=')
                res = !(tmp2 ^ tmp);

            st.push(res);
        }
        else {
            cout << "error" << endl;
            return 1;
        }
        i++;
    }
    return st.top();
}

void print_header(const string &formula, const map<char, int>& variables) {
    map<char, int>::const_iterator it;

    cout <<"Formula : " << formula << endl;

    cout << "|";
    for (it = variables.begin(); it != variables.end(); it++)
        cout << " " << it->first << " |";
    cout << " = |" << endl;

    cout << "|";
    for (it = variables.begin(); it != variables.end(); it++)
        cout << "---|";
    cout << "---|" << endl;
}

void print_row(const map<char, int>& variables, bool res) {
    map<char, int>::const_iterator it;

    cout << "|";
    for (it = variables.begin(); it != variables.end(); it++)
        cout << " " << it->second << " |";
    cout << " " << res << " |" << endl;
}

#endif
