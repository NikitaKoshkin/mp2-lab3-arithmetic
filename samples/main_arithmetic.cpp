// реализация пользовательского приложения
#include "arithmetic.h"


int main()
{
    string infix = "2*(3*4+3*5)+7";
    //2 3 4 * 3 5 * + * 7 +
    cout << isCorrect(infix) << endl;
    string infix2 = "A*(B*C+D*E)+F";
    //A B C * D E * + * F +

    string postfix = CreatePostfix(infix);
    string postfix2 = CreatePostfix(infix2);


    cout << postfix << endl;
    cout << postfix2 << endl;

    cout << Calculate(postfix);
    //61




    return 0;
}