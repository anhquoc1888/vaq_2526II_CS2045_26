#include <iostream>
#include <vector>
#include <string>

using namespace std;

string loanDecision(int age, double income, int credit_score, char employment)
{   if (age < 18 || age > 65)
        return "Invalid Input";
    if (income < 5.0 || income > 500.0)
        return "Invalid Input";
    if (credit_score < 300 || credit_score > 850)
        return "Invalid Input";
    if (employment != 'C' && employment != 'F')
        return "Invalid Input";

    string risk;
    if (credit_score >= 300 && credit_score <= 500)
        risk = "High";
    else if (credit_score >= 501 && credit_score <= 700)
        risk = "Medium";
    else
        risk = "Low";

    // High Risk -> REJECT
    if (risk == "High")
        return "REJECT";
    // Income < 15
    if (income < 15.0){
        // Freelance -> REJECT
        if (employment == 'F')
            return "REJECT";
        // Contract + Medium -> REJECT
        if (risk == "Medium")
            return "REJECT";
        // Contract + Low -> MANUAL REVIEW
        return "MANUAL REVIEW";
    }
    // Income >= 15
    // Contract -> APPROVE
    if (employment == 'C')
        return "APPROVE";
    // Freelance -> MANUAL REVIEW
    return "MANUAL REVIEW";
}

struct TestCase
{   int age;
    double income;
    int score;
    char employment;
    string expected;
};

int main(){   
    vector<TestCase> tests = {
        // ===== INVALID INPUT =====
        {17, 20.0, 750, 'C', "Invalid Input"},
        {66, 20.0, 750, 'C', "Invalid Input"},
        {30, 4.9, 750, 'C', "Invalid Input"},
        {30, 500.1, 750, 'C', "Invalid Input"},
        {30, 20.0, 299, 'C', "Invalid Input"},
        {30, 20.0, 851, 'C', "Invalid Input"},
        {30, 20.0, 750, 'X', "Invalid Input"},

        // ===== AGE BOUNDARY =====
        {18, 20.0, 750, 'C', "APPROVE"},
        {19, 20.0, 750, 'C', "APPROVE"},
        {64, 20.0, 750, 'C', "APPROVE"},
        {65, 20.0, 750, 'C', "APPROVE"},

        // ===== INCOME BOUNDARY =====
        {30, 5.0, 750, 'C', "MANUAL REVIEW"},
        {30, 5.1, 750, 'C', "MANUAL REVIEW"},
        {30, 499.9, 750, 'C', "APPROVE"},
        {30, 500.0, 750, 'C', "APPROVE"},

        // ===== CREDIT SCORE BOUNDARY =====
        {30, 20.0, 300, 'C', "REJECT"},
        {30, 20.0, 301, 'C', "REJECT"},
        {30, 20.0, 849, 'C', "APPROVE"},
        {30, 20.0, 850, 'C', "APPROVE"},

        // ===== RISK BOUNDARY =====
        {30, 20.0, 500, 'C', "REJECT"},
        {30, 20.0, 501, 'C', "APPROVE"},
        {30, 20.0, 700, 'F', "MANUAL REVIEW"},
        {30, 20.0, 701, 'F', "MANUAL REVIEW"},

        // ===== DECISION TABLE =====
        // High Risk
        {30, 50.0, 400, 'C', "REJECT"},

        // Income < 15 + Freelance
        {30, 14.9, 750, 'F', "REJECT"},

        // Income < 15 + Contract + Medium
        {30, 14.9, 650, 'C', "REJECT"},

        // Income < 15 + Contract + Low
        {30, 14.9, 750, 'C', "MANUAL REVIEW"},

        // Income >= 15 + Contract + Medium
        {30, 15.0, 650, 'C', "APPROVE"},

        // Income >= 15 + Contract + Low
        {30, 15.1, 750, 'C', "APPROVE"},

        // Income >= 15 + Freelance + Medium
        {30, 15.0, 650, 'F', "MANUAL REVIEW"},

        // Income >= 15 + Freelance + Low
        {30, 15.1, 750, 'F', "MANUAL REVIEW"}
    };

    int passed = 0;

    for (int i = 0; i < tests.size(); i++)
    {
        string actual = loanDecision(
            tests[i].age,
            tests[i].income,
            tests[i].score,
            tests[i].employment);

        if (actual == tests[i].expected)
        {
            cout << "TC" << i + 1 << ": PASS" << endl;
            passed++;
        }
        else
        {
            cout << "TC" << i + 1 << ": FAIL";

            cout << " | Expected: "
                 << tests[i].expected;

            cout << " | Actual: "
                 << actual << endl;
        }
    }

    cout << endl;
    cout << "Passed: " << passed << "/" << tests.size() << endl;
    return 0;
}
