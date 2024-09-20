#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Function to calculate the Greatest Common Divisor (GCD)
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Function to calculate the Least Common Multiple (LCM)
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

public:
    // Constructor
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        normalize();
    }

    // Normalize fraction by dividing by the GCD of numerator and denominator
    void normalize() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        if (denominator < 0) {  // Keep the denominator positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Overloaded addition operator
    Fraction operator+(const Fraction& other) {
        int common_denominator = lcm(denominator, other.denominator);
        int num = (numerator * (common_denominator / denominator)) + 
                  (other.numerator * (common_denominator / other.denominator));
        return Fraction(num, common_denominator);
    }

    // Overloaded subtraction operator
    Fraction operator-(const Fraction& other) {
        int common_denominator = lcm(denominator, other.denominator);
        int num = (numerator * (common_denominator / denominator)) - 
                  (other.numerator * (common_denominator / other.denominator));
        return Fraction(num, common_denominator);
    }

    // Overloaded multiplication operator
    Fraction operator*(const Fraction& other) {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Overloaded division operator
    Fraction operator/(const Fraction& other) {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    // Overload output operator (<<) for printing fractions
    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    // Method to read input from input stream (file or standard input)
    void readFromStream(istream& is) {
        char slash;  // To ignore the '/' character between numerator and denominator
        is >> numerator >> slash >> denominator;
        normalize();
    }
};

int main() 
{
    // make sure that the file is being opened 
    ifstream infile("input.txt");
    if (!infile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    Fraction frac1, frac2;
    char operation;

    // make a while loop to read in the whole file, ws is to ignore the whitespaces in the file
    while (infile >> ws && !infile.eof()) 
    {  
            // Read the first fraction
            frac1.readFromStream(infile);

            // Read the operator
            infile >> ws >> operation >> ws;

            // Read the second fraction
            frac2.readFromStream(infile);

            // Perform the operation based on the operator
            Fraction result;
                switch (operation) {
                    case '+':
                        result = frac1 + frac2;
                        break;
                    case '-':
                        result = frac1 - frac2;
                        break;
                    case '*':
                        result = frac1 * frac2;
                        break;
                    case '/':
                        result = frac1 / frac2;
                        break;
                    default:
                        cout << "Unknown operator: " << operation << endl;
                        return 1;
                }

                // Output the result
                cout << frac1 << " " << operation << " " << frac2 << " = " << result << endl;

            } 
        

        
    }

