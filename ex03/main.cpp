#include <iostream>
#include <stack>

using namespace std;

bool is_symbol(const char c) {
    if (c == '!' || c == '&' || c == '|' || c == '^' || c == '>' || c == '=')
        return true;
    else
        return false;
}

bool parse(const string& formula) {
    int nb_number = 0;
    int nb_binary = 0;

    for (size_t i = 0; i < formula.length(); ++i) {
        if (formula[i] == '0' || formula[i] == '1')
            nb_number++;
        else if (formula[i] == '!')
            continue;
        else if (is_symbol(formula[i]))
            nb_binary++;
        else
            return false;
    }

    if (nb_number != nb_binary + 1)
        return false;
    
    return true;
}

bool eval_formula(const string& formula) {

    int i = 0;
    long long tmp;
    long long tmp2;
    bool res = false;
    stack<int> st;

    if (!parse(formula)) {
        cout << "Error: Syntax is not correct" << endl;
        return false;
    }

    while (formula[i]) {

        if (formula[i] == '0' || formula[i] == '1')
            st.push(formula[i] - '0');
        
        else if (formula[i] == '!' && st.size() >= 1) {

            tmp = st.top();
            st.pop();
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
                res = tmp2 ^ tmp;
            else if (formula[i] == '>')
                res = !tmp2 | tmp;
            else if (formula[i] == '=')
                res = !(tmp2 ^ tmp);

            st.push(res);
        }
        else {
            cout << "error" << endl;
            return false;
        }
        i++;
    }
    return st.top();
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

    cout << "\n=== Error cases ===" << endl;
    cout << "eval_formula(\"\") = " << eval_formula("") << endl;
    cout << "eval_formula(\"10\") = " << eval_formula("10") << endl;
    cout << "eval_formula(\"1&\") = " << eval_formula("1&") << endl;
    cout << "eval_formula(\"0|\") = " << eval_formula("0|") << endl;

    return 0;
}