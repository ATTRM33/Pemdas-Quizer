//Zach Brown
//CS2
//Module 5 lab PEMDAS QUIZ

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;


// prototypes
void printScores(vector<double> modulus, vector<double> pemmdas);
double modulusQuiz();
double pemmdasQuiz();
double solve(vector<double>& operands, vector<char>& operators);

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

        vector<double> numbers;
        vector<char> operators;

        // generate random operands and operators
        numbers.push_back(rand() % 19 + 1);

        for (int i = 0; i < 4; ++i) {  
            int randOperator = rand() % 5;
            char op;
            switch (randOperator) {
            case 0: op = '+'; break;
            case 1: op = '-'; break;
            case 2: op = '/'; break;
            case 3: op = '*'; break;
            case 4: op = '%'; break;
            }
            operators.push_back(op);
            numbers.push_back(rand() % 19 + 1);
        }

        // display the problem to the user
        cout << "What is: ";
        for (int i = 0; i < operators.size(); ++i) {
            cout << numbers[i] << " " << operators[i] << " ";
        }
        cout << numbers.back() << "?" << endl;

        double userAnswer;
        cin >> userAnswer;

        while (!operators.empty()) {
            char op = operators.back();
            operators.pop_back();

            double rightNum = numbers.back();
            numbers.pop_back();
            double leftNum = numbers.back();
            numbers.pop_back();

            double result;
            if (op == '*') {
                result = leftNum * rightNum;
            }
            else if (op == '/') {
                result = leftNum / rightNum;
            }
            else if (op == '%') {
                result = static_cast<int>(leftNum) % static_cast<int>(rightNum);
            }
            else if (op == '+') {
                result = leftNum + rightNum;
            }
            else { // op == '-'
                result = leftNum - rightNum;
            }

            // push the result back to the vector
            numbers.push_back(result);
        }

        //final result
        double correctAnswer = numbers.back();

        if (abs(userAnswer - correctAnswer) < 1e-9) {  
            cout << "That's right!" << endl;
            score++;
        }
        else {
            cout << "No, the answer is " << correctAnswer << endl;
        }

        times--;
    }

    //format and display the percentage correct
    double percent = score / static_cast<double>(total) * 100;
    std::cout << "You scored " << score << " out of " << total << endl
    << "That's " << percent << "%." << endl;

    return percent;
}

double solve(vector<double>& operands, vector<char>& operators) {

    //base case for when vector is empty
    if (operators.empty()) {
        return operands.back();
    }

    char op = operators.back();
    operators.pop_back();

    double rightNum = operands.back();
    operands.pop_back();

    double leftNum = operands.back();
    operands.pop_back();

    double result;
    if (op == '*') {
        result = leftNum * rightNum;
    }
    else if (op == '/') {
        result = leftNum / rightNum;
    }
    else if (op == '%') {
        result = static_cast<int>(leftNum) % static_cast<int>(rightNum);
    }
    else if (op == '+') {
        result = leftNum + rightNum;
    }
    else { 
        result = leftNum - rightNum;
    }

    // push the result back to operands vector
    operands.push_back(result);

    // recursion to process all operators and operands
    return solve(operands, operators);
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