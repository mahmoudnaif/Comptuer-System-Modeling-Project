#include "utils.h"

void utils::printVector(const std::vector<double>& ans) {
    cout << "Vector:\n";
    for (double value : ans) {
        std::cout << value << std::endl;
    }
    std::cout << "Press any key to continue...\n";
    _getch(); 
}

int utils::getPositiveInt(const string& prompt) {
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

double  utils::getPositiveDouble(const string& prompt) {
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


char utils::getValidOperation() {
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

vector<int> utils::getPositiveIntVector(int size, const string& label) {
    vector<int> vec(size);
    cout << "Please enter " << size << " " << label << " values:\n";
    for (int i = 0; i < size; ++i) {
        vec[i] = getPositiveInt(label + " [" + to_string(i + 1) + "]: ");
    }
    return vec;
}

vector<double> utils::getPositiveDoubleVector(int size, const string& label) {
    vector<double> vec(size);
    cout << "Please enter " << size << " " << label << " values:\n";
    for (int i = 0; i < size; ++i) {
        vec[i] = getPositiveDouble(label + " [" + to_string(i + 1) + "]: ");
    }
    return vec;
}


double utils::getTestType(){
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

vector<double> utils::getTestVector(vector<double>& oldvector){
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


void utils::handleInvalidInput() {
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  

    cout << "Invalid input. Please enter a number.\n";
    cout << "Press any key to continue...\n";
    _getch(); 
    system("cls");
}

void utils::handleInvalidInputInLoop() {
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
}


