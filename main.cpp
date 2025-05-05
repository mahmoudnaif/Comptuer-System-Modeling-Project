#include <iostream>
#include "RNGs.h"
#include "KS-Test.h"
#include "utils.h"

using namespace std;



int main() {
    KSTest::KSTestInitize();
    RNGs rng;
    int userInput = 0;
    utils::AlgoType algoSwit = static_cast<utils::AlgoType>(1);
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
            utils::handleInvalidInput();
            continue;
        }


        algoSwit = static_cast<utils::AlgoType>(userInput);

        switch (algoSwit)
        {
        case utils::LCG:
            {
                int seed = utils::getPositiveInt("Please enter the seed value: ");
                int a = utils::getPositiveInt("Please enter the a: ");
                int c = utils::getPositiveInt("Please enter the c: ");
                int m = utils::getPositiveInt("Please enter the m: ");
                int count = utils::getPositiveInt("Please enter the Number of random values you want: ");

                lastVector = rng.LCG(seed,a,c,m,count);
                utils::printVector(lastVector);
            }
            

            break;
        case utils::MCG:
        {
            int seed = utils::getPositiveInt("Please enter the seed value: ");
            int a = utils::getPositiveInt("Please enter the a: ");
            int m = utils::getPositiveInt("Please enter the m: ");
            int count = utils::getPositiveInt("Please enter the Number of random values you want: ");
            
            lastVector = rng.MCG(seed,a,m,count);
            utils::printVector(lastVector);
        }
            break;
        case utils::ICG:
        {
            int seed = utils::getPositiveInt("Please enter the seed value: ");
            int a = utils::getPositiveInt("Please enter the a: ");
            int m = utils::getPositiveInt("Please enter the m: ");
            int count = utils::getPositiveInt("Please enter the Number of random values you want: ");
            

            lastVector = rng.ICG(seed,a,m,count);
            utils::printVector(lastVector);
        }
            break;
        case utils::MRG:
        {
            int q = utils::getPositiveInt("Please enter the number of coefficients: ");
            int m = utils::getPositiveInt("Please enter the m: ");
            int count = utils::getPositiveInt("Please enter the Number of random values you want: ");

            vector<int> coefficients = utils::getPositiveIntVector(q,"coefficients");
            vector<int> seeds = utils::getPositiveIntVector(q,"seeds");
           
            lastVector = rng.MRG(seeds,coefficients,q,m,count);
            utils::printVector(lastVector);
        }
            break;
        case utils::LFG:
        {
            int k = utils::getPositiveInt("Please enter the number k (also number of seeds): ");
            int j = utils::getPositiveInt("Please enter the number J: ");
            int m = utils::getPositiveInt("Please enter the m: ");
            int count = utils::getPositiveInt("Please enter the Number of random values you want: ");
            char operation = utils::getValidOperation();

            if(k < j){
                
                while(true){
                    cout << "K must always be larger than J!!\n";
                    cout << "Press any key to continue...\n";
                    _getch(); 
                    k = utils::getPositiveInt("Please enter the number k (also number of seeds): ");
                    j = utils::getPositiveInt("Please enter the number J: ");
                    if (k > j){
                        break;
                    }
                }
            }
            
            vector<int> seeds = utils::getPositiveIntVector(k,"seeds");;
        
            lastVector = rng.LFG(seeds,j,k,operation,m,count);
            utils::printVector(lastVector);
        }
            break;
        case utils::MSM:
            {
                int seed = utils::getPositiveInt("Please enter the seed value: ");
                int count = utils::getPositiveInt("Please enter the Number of random values you want: ");

                if( ((seed== 0) ? 1 : static_cast<int>(log10(abs(seed)) + 1)) != 4){
                    while(true){
                        cout << "Seed must always consist of 4 didgits\n";
                        cout << "Press any key to continue...\n";
                        _getch(); 
                        seed = utils::getPositiveInt("Please enter the seed value: ");

                        if(((seed== 0) ? 1 : static_cast<int>(log10(abs(seed)) + 1)) == 4){
                            break;
                        }
                        
                    }
                }
                lastVector = rng.MSM(seed,count);
                utils::printVector(lastVector);
            }
            break;
        case utils::TEST:
        {
            lastVector = utils::getTestVector(lastVector);
            double testType = utils::getTestType();
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
