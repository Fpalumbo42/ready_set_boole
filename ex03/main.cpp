#include <iostream>
#include <stack>

using namespace std;

bool is_symbol(char c) {
    if (c == '!' || c == '&' || c == '|' || c == '^' || c == '>' || c == '=')
        return true;
    else
        return false;
}

bool parse(string formula) {

    int nb_symbol = 0;
    int nb_number = 0;

    for (size_t i = 0; i < formula.length(); ++i) {

        if (formula[i] == '0' || formula[i] == '1')
            nb_number++;

        else if (is_symbol(formula[i]))
            nb_symbol++;

        else {
            cout << "Error: Unknown character" << endl;
            return 1;
        }
    }

    if (nb_symbol != nb_number - 1 || nb_number <= 1) {
        cout << "Error: Syntax is not correct" << endl;
        return 1;
    }

    return 0;
}

bool eval_formula(string formula) {

    int i = 0;
    long long tmp;
    long long tmp2;
    bool res;
    stack<int> st;

    if (!parse(formula))
        return 1;

    while (formula[i]) {

        if (formula[i] == '0' || formula[i] == '1')
        st.push(formula[i] - '0');
        
        else if (formula[i] == '!' && st.size() >= 1) {

            tmp = st.top();
            if (formula[i] == '!') {
                res = !tmp;
                st.push(res);
            } 
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
                res = !tmp2 ^ tmp;
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
    return res;
}

int main() {

    cout << "=== Subject tests ===" << endl;
    cout << "eval_formula(\"10&\") = " << eval_formula("10&") << endl;
    cout << "eval_formula(\"10|\") = " << eval_formula("10|") << endl;
    cout << "eval_formula(\"11>\") = " << eval_formula("11>") << endl;
    cout << "eval_formula(\"10=\") = " << eval_formula("10=") << endl;
    cout << "eval_formula(\"1011||=\") = " << eval_formula("1011||=") << endl;

    cout << "\n=== NOT operator tests ===" << endl;
    cout << "eval_formula(\"1!\") = " << eval_formula("1!") << endl;
    cout << "eval_formula(\"0!\") = " << eval_formula("0!") << endl;
    cout << "eval_formula(\"1!!\") = " << eval_formula("1!!") << endl;

    cout << "\n=== AND operator tests ===" << endl;
    cout << "eval_formula(\"00&\") = " << eval_formula("00&") << endl;
    cout << "eval_formula(\"01&\") = " << eval_formula("01&") << endl;
    cout << "eval_formula(\"10&\") = " << eval_formula("10&") << endl;
    cout << "eval_formula(\"11&\") = " << eval_formula("11&") << endl;

    cout << "\n=== OR operator tests ===" << endl;
    cout << "eval_formula(\"00|\") = " << eval_formula("00|") << endl;
    cout << "eval_formula(\"01|\") = " << eval_formula("01|") << endl;
    cout << "eval_formula(\"10|\") = " << eval_formula("10|") << endl;
    cout << "eval_formula(\"11|\") = " << eval_formula("11|") << endl;

    cout << "\n=== XOR operator tests ===" << endl;
    cout << "eval_formula(\"00^\") = " << eval_formula("00^") << endl;
    cout << "eval_formula(\"01^\") = " << eval_formula("01^") << endl;
    cout << "eval_formula(\"10^\") = " << eval_formula("10^") << endl;
    cout << "eval_formula(\"11^\") = " << eval_formula("11^") << endl;

    cout << "\n=== IMPLY operator tests ===" << endl;
    cout << "eval_formula(\"00>\") = " << eval_formula("00>") << endl;
    cout << "eval_formula(\"01>\") = " << eval_formula("01>") << endl;
    cout << "eval_formula(\"10>\") = " << eval_formula("10>") << endl;
    cout << "eval_formula(\"11>\") = " << eval_formula("11>") << endl;

    cout << "\n=== EQUIV operator tests ===" << endl;
    cout << "eval_formula(\"00=\") = " << eval_formula("00=") << endl;
    cout << "eval_formula(\"01=\") = " << eval_formula("01=") << endl;
    cout << "eval_formula(\"10=\") = " << eval_formula("10=") << endl;
    cout << "eval_formula(\"11=\") = " << eval_formula("11=") << endl;

    cout << "\n=== Complex formulas ===" << endl;
    cout << "eval_formula(\"10&0|1^\") = " << eval_formula("10&0|1^") << endl;
    cout << "eval_formula(\"101|&\") = " << eval_formula("101|&") << endl;
    cout << "eval_formula(\"10!&\") = " << eval_formula("10!&") << endl;
    cout << "eval_formula(\"10&!\") = " << eval_formula("10&!") << endl;
    cout << "eval_formula(\"1010^^=\") = " << eval_formula("1010^^=") << endl;

    return 0;
}