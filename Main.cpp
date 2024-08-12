/*
Contains Modulus Quizzer and PEMMDAS Quizzer
*/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;



double modulusQuiz();
double pemmdasQuiz();
void printScores(vector<double> modulus, vector<double> pemmdas);

int main()
{
    srand(time(0));
    char selection;
    vector<double> modulusScores;
    vector<double> pemmdasScores;


    do {
        cout << "Welcome to PEMMDAS practice.  " << endl
            << endl
            << "Select a menu option to proceed: " << endl
            << "1  Modulus Practice" << endl
            << "2  PEMMDAS Practice" << endl
            << "3  Score Report" << endl;
        cin >> selection;

        double tempScore = 0.0;
        switch (selection) {
        case '1': tempScore = modulusQuiz();
            modulusScores.push_back(tempScore);
            break;
        case '2': tempScore = pemmdasQuiz();
            pemmdasScores.push_back(tempScore);
            break;
        case '3': printScores(modulusScores, pemmdasScores);
            break;
        case '4': return 0;
        default:
            cout << " Please enter a valid entry.";
        }
    } while (true);


}


double modulusQuiz() {
    int times = 0;
    int score = 0;
    cout << "How many problems would you like to solve?" << endl;
    cin >> times;
    int total = times;


    while (times > 0) {
        int num1 = rand() % 10;
        int num2 = rand() % 9 + 1;
        int answer = 0;

        cout << "What is:" << endl
            << num1 << " % " << num2 << endl;
        cin >> answer;
        if (answer == (num1 % num2)) {
            cout << "That's right!" << endl;
            score++;
        }
        else {
            cout << "No, the answer is " << (num1 % num2) << endl;

        }
        times--;

    }

    double percent = score / static_cast<double>(total) * 100;
    cout << "You scored " << score << " out of " << total << endl
        << "That's " << percent << "%." << endl;

    return percent;
}

double pemmdasQuiz() {
    int times = 0;
    int score = 0;
    cout << "How many problems would you like to solve?" << endl;
    cin >> times;
    int total = times;

    while (times > 0) {

        //variable declaration

        //getnerate random number between 1 and 20
        int num1 = rand() % 19 + 1;
        int num2 = rand() % 19 + 1;
        int num3 = rand() % 19 + 1;
        int num4 = rand() % 19 + 1;
        int num5 = rand() % 19 + 1;
        int num6 = rand() % 19 + 1;
        int num7 = rand() % 19 + 1;
        int num8 = rand() % 19 + 1;
        int num9 = rand() % 19 + 1;

        //generate random number for arithmetic symbol
        int randOperator1 = rand() % 5;
        int randOperator2 = rand() % 5;
        int randOperator3 = rand() % 5;
        int randOperator4 = rand() % 5;
        int randOperator5 = rand() % 5;
        int randOperator6 = rand() % 5;
        int randOperator7 = rand() % 5;
        int randOperator8 = rand() % 5;

        char operator1;
        char operator2;
        char operator3;
        char operator4;
        char operator5;
        char operator6;
        char operator7;
        char operator8;
        int answer = 0;

        //switch cases to allocate an arithmetic symbol to a random integer
        switch (randOperator1) {
        case 0: operator1 = '+'; break;
        case 1: operator1 = '-'; break;
        case 2: operator1 = '/'; break;
        case 3: operator1 = '*'; break;
        case 4: operator1 = '%'; break;
        }

        switch (randOperator2) {
        case 0: operator2 = '+'; break;
        case 1: operator2 = '-'; break;
        case 2: operator2 = '/'; break;
        case 3: operator2 = '*'; break;
        case 4: operator2 = '%'; break;
        }

        switch (randOperator3) {
        case 0: operator3 = '+'; break;
        case 1: operator3 = '-'; break;
        case 2: operator3 = '/'; break;
        case 3: operator3 = '*'; break;
        case 4: operator3 = '%'; break;
        }

        switch (randOperator4) {
        case 0: operator4 = '+'; break;
        case 1: operator4 = '-'; break;
        case 2: operator4 = '/'; break;
        case 3: operator4 = '*'; break;
        case 4: operator4 = '%'; break;
        }

        switch (randOperator5) {
        case 0: operator5 = '+'; break;
        case 1: operator5 = '-'; break;
        case 2: operator5 = '/'; break;
        case 3: operator5 = '*'; break;
        case 4: operator5 = '%'; break;
        }

        switch (randOperator6) {
        case 0: operator6 = '+'; break;
        case 1: operator6 = '-'; break;
        case 2: operator6 = '/'; break;
        case 3: operator6 = '*'; break;
        case 4: operator6 = '%'; break;
        }

        switch (randOperator7) {
        case 0: operator7 = '+'; break;
        case 1: operator7 = '-'; break;
        case 2: operator7 = '/'; break;
        case 3: operator7 = '*'; break;
        case 4: operator7 = '%'; break;
        }

        switch (randOperator8) {
        case 0: operator8 = '+'; break;
        case 1: operator8 = '-'; break;
        case 2: operator8 = '/'; break;
        case 3: operator8 = '*'; break;
        case 4: operator8 = '%'; break;
        }



        // display random PEMMDAS problem to console
        cout << "What is:" << endl
            << num1 << operator1 << num2 << operator2 << num3 << operator3 << num4 << operator4 << num5 <<
            operator5 << num6 << operator6 << num7 << operator7 << num8 << operator8 << num9 << endl;
        cin >> answer;

        times--;

    }



    return 0;
}

void printScores(vector<double> modulus, vector<double> pemmdas) {
    int modCount = 1, pemCount = 1;
    cout << "Your percentages on modulus quizzes are:" << endl;
    for (double percent : modulus) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }
    cout << endl << endl;
    cout << "Your percentages on PEMMDAS quizzes are:" << endl;
    for (double percent : pemmdas) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }



}