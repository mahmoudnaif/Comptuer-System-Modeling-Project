#ifndef utils_H
#define utils_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <cmath> 
#include <string>

using namespace std;
class utils {
private:
public:
static void printVector(const std::vector<double>& ans);

static int getPositiveInt(const string& prompt);

static double  getPositiveDouble(const string& prompt);


static char getValidOperation();

static vector<int> getPositiveIntVector(int size, const string& label);

static vector<double> getPositiveDoubleVector(int size, const string& label);


static double getTestType();

static vector<double> getTestVector(vector<double>& oldvector);


static void handleInvalidInput();

static void handleInvalidInputInLoop();

enum AlgoType{
    LCG = 1,
    MCG = 2,
    ICG = 3,
    MRG = 4,
    LFG = 5,
    MSM = 6,
    TEST = 7
};


};

#endif // RNGs_H
