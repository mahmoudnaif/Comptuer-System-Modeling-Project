#include "KS-Test.h"


std::map<int, KSCriticalValues> KSTest::table;

void KSTest::KSTestInitize() {
        table[1] = {0.950, 0.975, 0.995};
        table[2] = {0.776, 0.842, 0.929};
        table[3] = {0.642, 0.708, 0.828};
        table[4] = {0.565, 0.624, 0.733};
        table[5] = {0.510, 0.565, 0.669};
        table[6] = {0.470, 0.521, 0.618};
        table[7] = {0.438, 0.486, 0.577};
        table[8] = {0.411, 0.457, 0.543};
        table[9] = {0.388, 0.432, 0.514};
        table[10] = {0.358, 0.410, 0.490};
        table[11] = {0.352, 0.391, 0.468};
        table[12] = {0.338, 0.375, 0.450};
        table[13] = {0.325, 0.361, 0.433};
        table[14] = {0.314, 0.349, 0.418};
        table[15] = {0.304, 0.338, 0.404};
        table[16] = {0.295, 0.328, 0.392};
        table[17] = {0.286, 0.318, 0.381};
        table[18] = {0.278, 0.309, 0.371};
        table[19] = {0.272, 0.301, 0.363};
        table[20] = {0.264, 0.294, 0.356};
        table[25] = {0.24, 0.27, 0.32};
        table[30] = {0.22, 0.24, 0.29};
        table[35] = {0.21, 0.23, 0.27};
    }
   
KSCriticalValues KSTest::getValues(int N) {
        if (N <= 35)
        {
            auto it = table.find(N);
            
            return it->second;
            
        }
        else
        {
            double sqrtN = sqrt(N);
            return {1.22 / sqrtN, 1.36 / sqrtN, 1.63 / sqrtN};
        }
    }

void KSTest::KST(vector<double>& nums, double version) {
    int N = nums.size();
    deque<double> DP,DM;
    double dPlusMax = 0.0, dMinusMax = 0.0;
    sort(nums.begin(), nums.end());

    for (int i = 1; i <= N; i++)
    {
        double dPlus = (double)i / N - nums[i - 1];
        double dMinus = nums[i - 1] - (double)(i - 1) / N;

        dPlusMax = max(dPlusMax, dPlus);
        dMinusMax = max(dMinusMax, dMinus);

        DP.push_back(dPlus);DM.push_back(dMinus);
    }
//---------------------------------------------------------------------------------------------------------------------
    cout <<endl<< "+-------+--------------+---------------------+-----------------------+" << endl;
    cout << "| Index | Sorted Value | D+ (i/N - X[i])     | D- (X[i] - (i-1)/N)   |" << endl;
    cout << "+-------+--------------+---------------------+-----------------------+" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(5) << i + 1 << " | "
             << setw(12) << fixed << setprecision(4) << nums[i] << " | "
             << setw(19) << fixed << setprecision(6) << DP[i] << " | "
             << setw(21) << fixed << setprecision(6) << DM[i] << " |" << endl;
    }
    cout << "+-------+--------------+---------------------+-----------------------+" << endl<<endl;

    double D = max(dMinusMax, dPlusMax);
    cout<< "max(D+) = "<<dPlusMax<<setw(44)<<"max(D-) = "<<dMinusMax<<endl;
    cout <<setw(20)<< "D =  " << "max("<<dPlusMax<<","<<dMinusMax<<") = "<< setprecision(4) <<D <<endl<<endl;
//---------------------------------------------------------------------------------------------------------------------
    KSTest k1;
    KSCriticalValues C1 = k1.getValues(N);

    double dAlpha;
    if (version == 0.1)
        dAlpha = C1.d10;
    else if (version == 0.05)
        dAlpha =    C1.d05;
    else if (version == 0.01)
        dAlpha = C1.d01;
    else {
        cout << "Invalid alpha version. Use 0.1, 0.05, or 0.01"<<endl;
    }

    cout << "for alpha = " << version << endl<<" D alpha   = "<< dAlpha<<endl<<endl;
    cout<<"D > D alpha ?"<<endl;
    if(D > dAlpha)
    {
        cout << " yes, H0 is rejected" << endl;
    }
    else
    {
        cout << " no, H0 is not rejected " << endl;
    }
}

