#ifndef RNGs_H
#define RNGs_H

#include <vector>

class RNGs {
private:
int modInverse(int x, int m);
int calculateValueOfMRG(const std::vector<int>& numbers,const std::vector<int>& coefficients,int iCurr,int q);
public:
     // 1. Inversive Congruential Generator
     std::vector<double> ICG(int seed, int a, int m, int count);

     // 2. Multiple Recursive Generator
     std::vector<double> MRG(const std::vector<int>& seeds, const std::vector<int>& coefficients,int q, int m, int count);
 
     // 3. Lagged Fibonacci Generator
     std::vector<double> LFG(const std::vector<int>& seeds, int j, int k, char operation, int m, int count);
 
     // 4. Mid-Square Method
     std::vector<double> MSM(int seed, int count);
 
     // 5. Linear Congruential Generator
     std::vector<double> LCG(int seed, int a, int c, int m, int count);
 
     // 6. Multiplicative Congruential Generator
     std::vector<double> MCG(int seed, int a, int m, int count);
};

#endif // RNGs_H
