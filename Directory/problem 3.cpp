#include <iostream>
using namespace std;

// Function to display academic bio-data
void displayBioData() {
    // Academic Bio Data
    string name = "ChatGPT";
    string uid = "AI-2024";
    string section = "Virtual Assistants (AI Applications)";
    string areaOfInterest = "Artificial Intelligence, Natural Language Processing, Machine Learning";
    string age = "Not Applicable";
    string lastYearCGPA = "Not Applicable";
    string dob = "March 14, 2023";
    string homeTown = "Cloud";

    // Display Bio Data
    cout << "================= Academic Bio Data =================" << endl;
    cout << "Name            : " << name << endl;
    cout << "UId             : " << uid << endl;
    cout << "Section         : " << section << endl;
    cout << "Area of Interest: " << areaOfInterest << endl;
    cout << "Age             : " << age << endl;
    cout << "Last Year CGPA  : " << lastYearCGPA << endl;
    cout << "Date of Birth   : " << dob << endl;
    cout << "Home Town       : " << homeTown << endl;
    cout << "====================================================" << endl;
}

int main() {
    displayBioData();
    return 0;
}
