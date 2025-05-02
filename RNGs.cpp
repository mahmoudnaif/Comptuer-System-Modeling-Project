#include "RNGs.h"


std::vector<double> RNGs::LCG(int seed, int a, int c, int m, int count) {
    std::vector<int> numbers = std::vector<int>(count+1,0);
    numbers[0] = seed;
    for(int i = 1; i<= count; i++){
        numbers[i] = (a*numbers[i-1] + c) % m;
    }
    std::vector<double> ansVector = std::vector<double>(count,0);

    for(int i = 1; i<= count; i++){
        ansVector[i-1] = double(numbers[i]) / m;
    }
    return ansVector;
}



std::vector<double> RNGs::MCG(int seed, int a, int m, int count) {
    std::vector<int> numbers = std::vector<int>(count+1,0);
    numbers[0] = seed;
    for(int i = 1; i<= count; i++){
        numbers[i] = (a*numbers[i-1]) % m;
    }
    std::vector<double> ansVector = std::vector<double>(count,0);

    for(int i = 1; i<= count; i++){
        ansVector[i-1] = double(numbers[i]) / m;
    }
    return ansVector;
}

std::vector<double> RNGs::ICG(int seed, int a, int m, int count) {
    std::vector<int> numbers = std::vector<int>(count+1,0);
    numbers[0] = seed;
    for(int i = 1; i<= count; i++){
        numbers[i] = (a*modInverse(numbers[i-1], m)) % m;
    }
    std::vector<double> ansVector = std::vector<double>(count,0);

    for(int i = 1; i<= count; i++){
        ansVector[i-1] = double(numbers[i]) / m;
    }
    return ansVector;
}

std::vector<double> RNGs::MRG(const std::vector<int>& seeds, const std::vector<int>& coefficients,int q, int m, int count) {
    
    std::vector<int> numbers = std::vector<int>(count+q,0);

    std::copy(seeds.begin(), seeds.end(), numbers.begin());

    for(int i = q; i< count+q; i++){
        numbers[i] = calculateValueOfMRG(numbers,coefficients,i,q) % m;
    }
    std::vector<double> ansVector = std::vector<double>(count,0);

    for(int i = q; i< count+q; i++){
        ansVector[i-q] = double(numbers[i]) / m;
    }
    return ansVector;
}

std::vector<double> RNGs::LFG(const std::vector<int>& seeds, int j, int k, char operation, int m, int count) {
    
    std::vector<int> numbers = std::vector<int>(count+k,0);

    std::copy(seeds.begin(), seeds.end(), numbers.begin());

    for(int i = k; i< count+k; i++){
        int a = numbers[i - j];
        int b = numbers[i - k];
        switch (operation) {
            case '+':
                numbers[i] = (a + b) % m;
                break;
            case '-':
                numbers[i] = (a - b + m) % m; 
                break;
            case '*':
                numbers[i] = (1LL * a * b) % m;
                break;
            case '^':
                numbers[i] = (a ^ b) % m;
                break;
            default:
                return std::vector<double>(0,0);
        }
    }
    std::vector<double> ansVector = std::vector<double>(count,0);

    for(int i = k; i< count+k; i++){
        ansVector[i-k] = double(numbers[i]) / m;
    }
    return ansVector;
}

std::vector<double> RNGs::MSM(int seed, int count) {
    
    std::vector<int> numbers = std::vector<int>(count+1,0);
    numbers[0] = seed;

    for(int i = 1; i<= count; i++){
        std::string tempstr = std::to_string(numbers[i-1] * numbers[i-1]); 
        if(tempstr.length() != 8){
            tempstr = '0' + tempstr;
        }
        numbers[i] = std::stoi(tempstr.substr(2,4));


    }
    std::vector<double> ansVector = std::vector<double>(count,0);

    for(int i = 1; i<= count; i++){
        ansVector[i-1] = double(numbers[i]) / 10000;
    }
    return ansVector;
}
int RNGs::calculateValueOfMRG(const std::vector<int>& numbers,const std::vector<int>& coefficients,int iCurr,int q){
    int sum = 0;
    int i = iCurr-1;
    int indexOfCoff = 0;
    while (q>0){
        sum+= numbers[i]*coefficients[indexOfCoff];

        --q;
        --i;
        ++indexOfCoff;
    }
    return sum;
}


int RNGs::modInverse(int x, int m) {
    int m0 = m, t, q;
    int a = 0, b = 1;

    while (x > 1) {
        q = x / m;
        t = m;
        m = x % m;
        x = t;
        t = a;
        a = b - q * a;
        b = t;
    }

    if (b < 0)
        b += m0;

    return b;
}