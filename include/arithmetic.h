// объявление функций и классов для вычисления арифметических выражений

#ifndef __ARIFM_H__
#define __ARIFM_H__

#include"stack.h"
#include <vector>
#include "stack.h"

bool bracket(const string& s) //проверка на правильность расстановки скобок
{
    int l_b = 0;
    int r_b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            l_b++;
        if (s[i] == ')')
            r_b++;
    }
    if (l_b != r_b)
        return false;
    return true;
}

bool isCorrect(const string& s)
{
    if (!bracket(s))
        return false;
    if (s[0] == '-' || s[0] == '+' || s[0] == '/' || s[0] == '*')
        return false;
    if (s[s.size()-1] == '-' || s[s.size() - 1] == '+' || s[s.size() - 1] == '/' || s[s.size() - 1] == '*')
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '/' && s[i + 1] == 0 || s[i] == '/' && s[i + 1] == '/' || s[i] == '-' && s[i + 1] == '-'
            || s[i] == '+' && s[i + 1] == '+' || s[i] == '0' && s[i + 1] == '0')
            return false;
        if (s[i] == '/' && s[i + 1] == 0)
            return false;
    }
    return true;
}

// вспомогательная функция для возврата приоритета данного оператора
int priority(const char& operation)
{
    if (operation == '(' || operation == ')')
        return 0;
    if (operation == '+' || operation == '-')
        return 1;
    if (operation == '*' || operation == '/')
        return 2;
    else
        return -1;
}
//функция для преобразования инфиксного выражения в постфиксное выражение
//эта функция ожидает корректное инфиксное выражение
string CreatePostfix(string s) 
{
    
    TStack<double> st;
    string postfix;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) {
            postfix.push_back(c);
        }
       //если отсканированный символ представляет собой «(», помещаем его в стек
        else if (c == '(')
            st.push('(');
        //если сканируемый символ — это «)», извлекаем и добавляем к выходной 
        //строке из стека до тех пор, пока не встретим «(»
        else if (c == ')') {
            while (st.top_stack() != '(') {
                postfix += st.top_stack();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        //если оператор сканируется
        else {
            while (!st.empty() && priority(s[i]) < priority(st.top_stack()) ||
                !st.empty() && priority(s[i]) == priority(st.top_stack())) {
                postfix += st.top_stack();
                st.pop();
            }
            st.push(c);
        }
    }
    //добавляем все оставшиеся операторы в stack в конце постфиксного выражения
    while (!st.empty()) {
        postfix += st.top_stack();
        st.pop();
    }
    return postfix;
}

double Calculate(string s)
{
    TStack<double> st;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        // если текущий символ является операндом, поместите его в stack
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        // если текущий символ является оператором
        else {
            // удаляем два верхних элемента из stack
            int x = st.top_stack();
            st.pop();

            int y = st.top_stack();
            st.pop();

            // оцениваем выражение 'x or y' и результат обратно в stack
            if (c == '+') 
            {
                st.push(y + x);
            }
            else if (c == '-') 
            {
                st.push(y - x);
            }
            else if (c == '*') 
            {
                st.push(y * x);
            }
            else if (c == '/') 
            {
                st.push(y / x);
            }
        }
    }
    // В этот момент в stack остается только один элемент, т.е.
    // результат выражения
    return st.top_stack();
}
#endif