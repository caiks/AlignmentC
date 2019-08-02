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

    Var v3(Var("aa"), Var(3));
    cout << v3 << endl;

    Var v4(Var("aa"), Var(Var("aa"), Var(3)));
    cout << v4 << endl;

    Var v5(Var("aa"), Var(Var(3),Var("aa")));
    cout << v5 << endl;

    cout << "v1 < v1 == " << (v1 < v1) << endl;
    cout << "v1 > v1 == " << (v1 > v1) << endl;
    cout << "v1 == v1 == " << (v1 == v1) << endl;

    cout << "v2 < v2 == " << (v2 < v2) << endl;
    cout << "v2 > v2 == " << (v2 > v2) << endl;
    cout << "v2 == v2 == " << (v2 == v2) << endl;

    cout << "v3 < v3 == " << (v3 < v3) << endl;
    cout << "v3 > v3 == " << (v3 > v3) << endl;
    cout << "v3 == v3 == " << (v3 == v3) << endl;

    cout << "v4 < v4 == " << (v4 < v4) << endl;
    cout << "v4 > v4 == " << (v4 > v4) << endl;
    cout << "v4 == v4 == " << (v4 == v4) << endl;

    cout << "v5 < v5 == " << (v5 < v5) << endl;
    cout << "v5 > v5 == " << (v5 > v5) << endl;
    cout << "v5 == v5 == " << (v5 == v5) << endl;

    cout << "v1 < v2 == " << (v1 < v2) << endl;
    cout << "v1 > v2 == " << (v1 > v2) << endl;
    cout << "v1 == v2 == " << (v1 == v2) << endl;

    cout << "v2 < v3 == " << (v2 < v3) << endl;
    cout << "v2 > v3 == " << (v2 > v3) << endl;
    cout << "v2 == v3 == " << (v2 == v3) << endl;

    cout << "v3 < v4 == " << (v3 < v4) << endl;
    cout << "v3 > v4 == " << (v3 > v4) << endl;
    cout << "v3 == v4 == " << (v3 == v4) << endl;

    cout << "v4 < v5 == " << (v4 < v5) << endl;
    cout << "v4 > v5 == " << (v4 > v5) << endl;
    cout << "v4 == v5 == " << (v4 == v5) << endl;


}
