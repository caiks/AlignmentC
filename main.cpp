#include "Alignment.h"
#include <iostream>

using namespace Alignment;
using namespace std;

void main()
{
    Var v1("aa");
    cout << v1 << endl;

    Var v2(3);
    cout << v2 << endl;

    Var v3(new Var("aa"), new Var(3));
    cout << v3 << endl;

    Var v4(new Var("aa"), new Var(new Var("aa"), new Var(3)));
    cout << v4 << endl;


}
