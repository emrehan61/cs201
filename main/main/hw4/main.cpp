﻿//Emrehan Hoşver 21903488
#include "AlgebraicExpression.h"

#include <iostream>
using namespace std;
int main()
{   
    cout << infix2prefix("(12+5)-20* 4") << endl;// boşluklara yetişemedim
    cout << infix2postfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << prefix2infix("* + * 100 2 4 - 12 4") << endl;
    cout << prefix2postfix("* + * 100 2 4 - 12 4") << endl;
    cout << postfix2prefix("100 12 2 - 8 * + 4 /") << endl;
    cout << postfix2infix("100 12 2 - 8 * + 4 /") << endl;
    cout << "Hello World!\n";
}

