#include <bits/stdc++.h>
using namespace std;

struct KSCriticalValues{
    double d10;
    double d05;
    double d01;
};
class KSTest {
private:
    static map<int, KSCriticalValues> table;
    static KSCriticalValues getValues(int N);

public:
static void KSTestInitize();
static void KST(vector<double>& nums, double version);

};



