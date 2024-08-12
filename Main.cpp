/*
Contains Modulus Quizzer and PEMMDAS Quizzer
*/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;



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

        vector<double> operands;
        vector<char> operators;

        // Generate random operands and operators
        operands.push_back(rand() % 19 + 1);

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
            operands.push_back(rand() % 19 + 1);
        }

        // Display the problem to the user
        cout << "What is: ";
        for (int i = 0; i < operators.size(); ++i) {
            cout << operands[i] << " " << operators[i] << " ";
        }
        cout << operands.back() << "?" << endl;

        double userAnswer;
        cin >> userAnswer;

        while (!operators.empty()) {
            char op = operators.back();
            operators.pop_back();

            double rightOperand = operands.back();
            operands.pop_back();
            double leftOperand = operands.back();
            operands.pop_back();

            double result;
            if (op == '*') {
                result = leftOperand * rightOperand;
            }
            else if (op == '/') {
                result = leftOperand / rightOperand;
            }
            else if (op == '%') {
                result = static_cast<int>(leftOperand) % static_cast<int>(rightOperand);
            }
            else if (op == '+') {
                result = leftOperand + rightOperand;
            }
            else { // op == '-'
                result = leftOperand - rightOperand;
            }

            // Push the result back to the vector
            operands.push_back(result);
        }

        //final result
        double correctAnswer = operands.back(); 

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
    if (operators.empty()) {
        return operands.back();
    }

    char op = operators.back();
    operators.pop_back();

    double rightOperand = operands.back();
    operands.pop_back();
    double leftOperand = operands.back();
    operands.pop_back();

    double result;
    if (op == '*') {
        result = leftOperand * rightOperand;
    }
    else if (op == '/') {
        result = leftOperand / rightOperand;
    }
    else if (op == '%') {
        result = static_cast<int>(leftOperand) % static_cast<int>(rightOperand);
    }
    else if (op == '+') {
        result = leftOperand + rightOperand;
    }
    else { 
        result = leftOperand - rightOperand;
    }

    // Push the result back to operands vector
    operands.push_back(result);

    // Recur to process the remaining operators and operands
    return solve(operands, operators);
}