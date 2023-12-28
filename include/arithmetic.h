// ���������� ������� � ������� ��� ���������� �������������� ���������

#ifndef __ARIFM_H__
#define __ARIFM_H__

#include"stack.h"
#include <vector>
#include "stack.h"

bool bracket(const string& s) //�������� �� ������������ ����������� ������
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

// ��������������� ������� ��� �������� ���������� ������� ���������
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
//������� ��� �������������� ���������� ��������� � ����������� ���������
//��� ������� ������� ���������� ��������� ���������
string CreatePostfix(string s) 
{
    
    TStack<double> st;
    string postfix;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) {
            postfix.push_back(c);
        }
       //���� ��������������� ������ ������������ ����� �(�, �������� ��� � ����
        else if (c == '(')
            st.push('(');
        //���� ����������� ������ � ��� �)�, ��������� � ��������� � �������� 
        //������ �� ����� �� ��� ���, ���� �� �������� �(�
        else if (c == ')') {
            while (st.top_stack() != '(') {
                postfix += st.top_stack();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        //���� �������� �����������
        else {
            while (!st.empty() && priority(s[i]) < priority(st.top_stack()) ||
                !st.empty() && priority(s[i]) == priority(st.top_stack())) {
                postfix += st.top_stack();
                st.pop();
            }
            st.push(c);
        }
    }
    //��������� ��� ���������� ��������� � stack � ����� ������������ ���������
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
        // ���� ������� ������ �������� ���������, ��������� ��� � stack
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        // ���� ������� ������ �������� ����������
        else {
            // ������� ��� ������� �������� �� stack
            int x = st.top_stack();
            st.pop();

            int y = st.top_stack();
            st.pop();

            // ��������� ��������� 'x or y' � ��������� ������� � stack
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
    // � ���� ������ � stack �������� ������ ���� �������, �.�.
    // ��������� ���������
    return st.top_stack();
}
#endif