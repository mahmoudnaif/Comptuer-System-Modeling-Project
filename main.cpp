#include <iostream>
#include "RNGs.h"
#include <conio.h>
#include <cstdlib>
#include <cmath> 

using namespace std;

void printVector(const std::vector<double>& ans) {
    cout << "Vector:\n";
    for (double value : ans) {
        std::cout << value << std::endl;
    }
    std::cout << "Press any key to continue...\n";
    _getch(); 
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
                int seed,a,c,m,count;
                cout << "Please enter the seed value: "; cin >> seed; cout <<endl;
                cout << "Please enter the a: "; cin >> a; cout <<endl;
                cout << "Please enter the c: "; cin >> c; cout <<endl;
                cout << "Please enter the modular value: "; cin >> m; cout <<endl;
                cout << "Please enter the Number of random values you want: "; cin >> count; cout <<endl;
                
                if (cin.fail()) {
                    handleInvalidInput();
                    continue;
                }

                if(seed <= 0 || a <= 0 || c <= 0 || m <= 0 || count <=0){
                    cout << "All numbers must be positive\n";
                    cout << "Press any key to continue...\n";
                    _getch();
                    system("cls");
                    continue;
                }
                lastVector = rng.LCG(seed,a,c,m,count);
                printVector(lastVector);
            }
            

            break;
        case MCG:
        {
            int seed,a,m,count;
            cout << "Please enter the seed value: "; cin >> seed; cout <<endl;
            cout << "Please enter the a: "; cin >> a; cout <<endl;
            cout << "Please enter the modular value: "; cin >> m; cout <<endl;
            cout << "Please enter the Number of random values you want: "; cin >> count; cout <<endl;
            
            if (cin.fail()) {
                handleInvalidInput();
                continue;
            }

            if(seed <= 0 || a <= 0 || m <= 0 || count <=0){
                cout << "All numbers must be positive\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            lastVector = rng.MCG(seed,a,m,count);
            printVector(lastVector);
        }
            break;
        case ICG:
        {
            int seed,a,m,count;
            cout << "Please enter the seed value: "; cin >> seed; cout <<endl;
            cout << "Please enter the a: "; cin >> a; cout <<endl;
            cout << "Please enter the modular value: "; cin >> m; cout <<endl;
            cout << "Please enter the Number of random values you want: "; cin >> count; cout <<endl;
            
            if (cin.fail()) {
                handleInvalidInput();
                continue;
            }

            if(seed <= 0 || a <= 0 || m <= 0 || count <=0){
                cout << "All numbers must be positive\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            lastVector = rng.ICG(seed,a,m,count);
            printVector(lastVector);
        }
            break;
        case MRG:
        {
            int q,m,count;
            cout << "Please enter the number of coefficients: "; cin >> q; cout <<endl;
            if (cin.fail()) {
                handleInvalidInput();
                continue;
            }
            if(q<=0){
                cout << "Number of coefficients numbers must be positive\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            vector<int> coefficients = vector<int>(q,0);
            vector<int> seeds = vector<int>(q,0);
            cout << "please enter your Coefficients: \n";
            bool failed = false;
            for(int i =0; i<q;i++){
                cin >> coefficients[i]; 
                if (cin.fail()) {
                    handleInvalidInputInLoop();;
                    failed = true;
                    break;
                }
                if(coefficients[i] <=0){
                    failed = true;
                    break;
                }
            }
            if(failed){
                cout << "Please enter valid intergerss \n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }

            cout << "please enter your Seeds: \n";
            for(int i =0; i<q;i++){
                cin >> seeds[i]; 
                if (cin.fail()) {
                    handleInvalidInputInLoop();;
                    failed = true;
                    break;
                }
                if(seeds[i] <=0){
                    failed = true;
                    break;
                }
            }
            if(failed){
                cout << "Please enter valid intergerss \n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }

            cout << "Please enter the modular value: "; cin >> m; cout <<endl;
            cout << "Please enter the Number of random values you want: "; cin >> count; cout <<endl;
            
            if (cin.fail()) {
                handleInvalidInput();
                system("cls");
                continue;
            }

            if(m <= 0 || count <=0){
                cout << "All numbers must be positive\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            lastVector = rng.MRG(seeds,coefficients,q,m,count);
            printVector(lastVector);
        }
            break;
        case LFG:
        {
            int j,k,m,count;
            char operation;
            cout << "Please enter the number k (also number of seeds): "; cin >> k; cout <<endl;
            cout << "Please enter the number J: "; cin >> j; cout <<endl;
            
            if (cin.fail()) {
                handleInvalidInput();
                continue;
            }

            if(k<=0 || j<=0){
                cout << "Numbers numbers must be positive\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            if(k < j){
                cout << "K must always be larger than J!!\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            
            vector<int> seeds = vector<int>(k,0);
            cout << "please enter your Seeds: \n";
            bool failed = false;
            for(int i =0; i<k;i++){
                cin >> seeds[i]; 
                if (cin.fail()) {
                    handleInvalidInputInLoop();;
                    failed = true;
                    break;
                }
                if(seeds[i] <=0){
                    failed = true;
                    break;
                }
            }
            if(failed){
                cout << "Seed must be positive\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }

            cout << "Please enter the modular value: "; cin >> m; cout <<endl;
            cout << "Please enter the Number of random values you want: "; cin >> count; cout <<endl;
            
            if (cin.fail()) {
                handleInvalidInput();
                continue;
            }

            if(m <= 0 || count <=0){
                cout << "All numbers must be positive\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            cout << "Please enter the operation type (+,-,*,^): "; cin >> operation; cout <<endl;

            if(operation !='+' && operation !='-' && operation !='*' && operation !='^' ){
                cout <<"Invalid operation\n";
                cout << "Press any key to continue...\n";
                _getch(); 
                system("cls");
                continue;
            }
            lastVector = rng.LFG(seeds,j,k,operation,m,count);
            printVector(lastVector);
        }
            break;
        case MSM:
            {
                int seed,count;
                cout << "Please enter the seed value: "; cin >> seed; cout <<endl;
                cout << "Please enter the Number of random values you want: "; cin >> count; cout <<endl;
                if (cin.fail()) {
                    handleInvalidInput();
                    continue;
                }
                
                if(seed <= 0 || count <=0){
                    cout << "All numbers must be positive\n";
                    cout << "Press any key to continue...\n";
                    _getch(); 
                    system("cls");
                    continue;
                }

                if( ((seed== 0) ? 1 : static_cast<int>(log10(abs(seed)) + 1)) != 4){
                    cout << "Seed must always consist of 4 didgits\n";
                    cout << "Press any key to continue...\n";
                    _getch(); 
                    system("cls");
                    continue;
                }
                lastVector = rng.MSM(seed,count);
                printVector(lastVector);
            }
            break;
        case TEST:
        /* code */
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
