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

int calcul(string formula) {

    int i = 0;
    long long tmp;
    long long tmp2;
    long long result;
    stack<int> st;

    while (formula[i])
    {
        if (formula[i] == '0' || formula[i] == '1')
            st.push(formula[i] - '0');
        else if (is_symbol(formula[i]) && st.size() >= 2)
        {
            tmp = st.top();
            st.pop();
            tmp2 = st.top();
            st.pop();
            if (formula[i] == '!')
                result = tmp2 ! tmp;
            else if (formula[i] == '+')
                result = tmp2 + tmp;
            else if (formula[i] == '*')
                result = tmp2 * tmp;
            else if (formula[i] == '/')
            {
                if (tmp != 0)
                    result = tmp2 / tmp;
                else
                    throw RPN::DivisionError();
            }
            if (result > INT_MAX || result < INT_MIN)
                throw RPN::TooBigTooLow();
            st.push(result);
        }
        else if (formula[i] == ' ')
        {
            i++;
            continue;
        }
        else
            throw RPN::StackError();
        i++;
    }
    return result;
}

int main() {

    string str = "10&";
    string str2 = "1011||=";

    cout << parse(str) << endl;
    cout << parse(str2) << endl;

    return 0;
}