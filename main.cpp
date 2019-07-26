#include "Alignment.h"
#include <iostream>

using namespace Alignment;
using namespace std;

void main()
{
    VarStr v1("aa");
    cout << v1 << endl;

    VarInt v2(3);
    cout << v2 << endl;

    VarPair v3(new VarStr("aa"), new VarInt(3));
    cout << v3 << endl;

    VarPair v4(new VarStr("aa"), new VarPair(new VarStr("aa"), new VarInt(3)));
    cout << v4 << endl;

}
