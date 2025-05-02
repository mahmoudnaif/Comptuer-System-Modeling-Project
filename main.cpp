#include <iostream>
#include "RNGs.h"
#include "KS-Test.h"
#include <conio.h>
#include <cstdlib>
#include <cmath> 
#include <string>
using namespace std;

void printVector(const std::vector<double>& ans) {
    cout << "Vector:\n";
    for (double value : ans) {
        std::cout << value << std::endl;
    }
    std::cout << "Press any key to continue...\n";
    _getch(); 
}

int getPositiveInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        
            cout << "Please enter a **positive integer**.\n";
            cout << "Press any key to continue...\n";
            _getch(); 
        } else {
            return value;
        }
    }
}

double  getPositiveDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0 || value > 1) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        
            cout << "Please enter a percentage. [0,1] only \n";
            cout << "Press any key to continue...\n";
            _getch(); 
        } else {
            return value;
        }
    }
}


char getValidOperation() {
    char op;
    while (true) {
        cout << "Please enter the operation type (+,-,*,^): ";
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '^') {
            return op;
        }
        cout << "Invalid operation. Try again.\n";
    }
}

vector<int> getPositiveIntVector(int size, const string& label) {
    vector<int> vec(size);
    cout << "Please enter " << size << " " << label << " values:\n";
    for (int i = 0; i < size; ++i) {
        vec[i] = getPositiveInt(label + " [" + to_string(i + 1) + "]: ");
    }
    return vec;
}

vector<double> getPositiveDoubleVector(int size, const string& label) {
    vector<double> vec(size);
    cout << "Please enter " << size << " " << label << " values:\n";
    for (int i = 0; i < size; ++i) {
        vec[i] = getPositiveDouble(label + " [" + to_string(i + 1) + "]: ");
    }
    return vec;
}


double getTestType(){
    double value;
    while (true) {
        cout << "Please enter the test type from one of the following: (0.01, 0.05, 0.10)\nChoice: ";
        cin >> value;

        if (cin.fail() || (value != 0.01 &&value != 0.05 &&value != 0.1)  ) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        
            cout << "Please enter a valid test type\n";
            cout << "Press any key to continue...\n";
            _getch(); 
        } else {
            return value;
        }
    }
}

vector<double> getTestVector(vector<double>& oldvector){
    int value;
    while (true) {
        cout << "1- Enter the last Vector output\n2- Enter a new vector\nChoice: ";
        cin >> value;

        if (cin.fail() || (value != 1 && value !=2)  ) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        
            cout << "Please enter 1 or 2\n";
            cout << "Press any key to continue...\n";
            _getch(); 
        } else {
            break;
        }
    }

    if (value == 1){
        return oldvector;
    }
    else{
        int sOfVector = getPositiveInt("Please enter the size of your Vector");
        return getPositiveDoubleVector(sOfVector,"TestVec");
    }

}





void handleInvalidInput() {
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  

    cout << "Invalid input. Please enter a number.\n";
    cout << "Press any key to continue...\n";
    _getch(); 
    system("cls");
}

void handleInvalidInputInLoop() {
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
}
enum AlgoType{
    LCG = 1,
    MCG = 2,
    ICG = 3,
    MRG = 4,
    LFG = 5,
    MSM = 6,
    TEST = 7
};


int main() {
    KSTest::KSTestInitize();
    RNGs rng;
    int userInput = 0;
    AlgoType algoSwit = static_cast<AlgoType>(1);
    vector<double> lastVector;
    while (true)
    {
        cout <<"Please enter your choice\n";
        cout <<"1- LCG\n";
        cout <<"2- MCG\n";
        cout <<"3- ICG\n";
        cout <<"4- MRG\n";
        cout <<"5- LFG\n";
        cout <<"6- MSM\n";
        cout <<"7- TEST\n\n";
        cout << "Input: ";
        cin >> userInput;

        if (cin.fail()) {
            handleInvalidInput();
            continue;
        }


        algoSwit = static_cast<AlgoType>(userInput);

        switch (algoSwit)
        {
        case LCG:
            {
                int seed = getPositiveInt("Please enter the seed value: ");
                int a = getPositiveInt("Please enter the a: ");
                int c = getPositiveInt("Please enter the c: ");
                int m = getPositiveInt("Please enter the m: ");
                int count = getPositiveInt("Please enter the Number of random values you want: ");

                lastVector = rng.LCG(seed,a,c,m,count);
                printVector(lastVector);
            }
            

            break;
        case MCG:
        {
            int seed = getPositiveInt("Please enter the seed value: ");
            int a = getPositiveInt("Please enter the a: ");
            int m = getPositiveInt("Please enter the m: ");
            int count = getPositiveInt("Please enter the Number of random values you want: ");
            
            lastVector = rng.MCG(seed,a,m,count);
            printVector(lastVector);
        }
            break;
        case ICG:
        {
            int seed = getPositiveInt("Please enter the seed value: ");
            int a = getPositiveInt("Please enter the a: ");
            int m = getPositiveInt("Please enter the m: ");
            int count = getPositiveInt("Please enter the Number of random values you want: ");
            

            lastVector = rng.ICG(seed,a,m,count);
            printVector(lastVector);
        }
            break;
        case MRG:
        {
            int q = getPositiveInt("Please enter the number of coefficients: ");
            int m = getPositiveInt("Please enter the m: ");
            int count = getPositiveInt("Please enter the Number of random values you want: ");

            vector<int> coefficients = getPositiveIntVector(q,"coefficients");
            vector<int> seeds = getPositiveIntVector(q,"seeds");
           
            lastVector = rng.MRG(seeds,coefficients,q,m,count);
            printVector(lastVector);
        }
            break;
        case LFG:
        {
            int k = getPositiveInt("Please enter the number k (also number of seeds): ");
            int j = getPositiveInt("Please enter the number J: ");
            int m = getPositiveInt("Please enter the m: ");
            int count = getPositiveInt("Please enter the Number of random values you want: ");
            char operation = getValidOperation();

            if(k < j){
                
                while(true){
                    cout << "K must always be larger than J!!\n";
                    cout << "Press any key to continue...\n";
                    _getch(); 
                    k = getPositiveInt("Please enter the number k (also number of seeds): ");
                    j = getPositiveInt("Please enter the number J: ");
                    if (k > j){
                        break;
                    }
                }
            }
            
            vector<int> seeds = getPositiveIntVector(k,"seeds");;
        
            lastVector = rng.LFG(seeds,j,k,operation,m,count);
            printVector(lastVector);
        }
            break;
        case MSM:
            {
                int seed = getPositiveInt("Please enter the seed value: ");
                int count = getPositiveInt("Please enter the Number of random values you want: ");

                if( ((seed== 0) ? 1 : static_cast<int>(log10(abs(seed)) + 1)) != 4){
                    while(true){
                        cout << "Seed must always consist of 4 didgits\n";
                        cout << "Press any key to continue...\n";
                        _getch(); 
                        seed = getPositiveInt("Please enter the seed value: ");

                        if(((seed== 0) ? 1 : static_cast<int>(log10(abs(seed)) + 1)) == 4){
                            break;
                        }
                        
                    }
                }
                lastVector = rng.MSM(seed,count);
                printVector(lastVector);
            }
            break;
        case TEST:
        {
            lastVector = getTestVector(lastVector);
            double testType = getTestType();
            KSTest::KST(lastVector,testType);
            std::cout << "Press any key to continue...\n";
            _getch();
        }
            break;
        default:
            std::cout << "Please enter a number between 1 and 9.\n";
            std::cout << "Press any key to continue...\n";
            _getch();
            system("cls"); 
            break;
        }
        system("cls");
    }
    

    return 0;
}
