#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Define a structure for transactions
struct Transaction {
    int id;  // Unique transaction ID
    double size;  // Transaction size (e.g., in USD)
    int frequency;  // Frequency of transactions by the user
    std::string location;  // Geographical location
    double suspiciousnessScore;  // Calculated suspiciousness score

    // Constructor for easier initialization
    Transaction(int id, double size, int frequency, std::string location, double suspiciousnessScore)
        : id(id), size(size), frequency(frequency), location(location), suspiciousnessScore(suspiciousnessScore) {}
};

// Function to calculate suspiciousness score (dummy function for illustration)
double calculateSuspiciousnessScore(double size, int frequency, const std::string& location) {
    // Example formula: weight factors for size, frequency, and location risk (simplified)
    double locationRisk = (location == "high-risk-area") ? 1.5 : 1.0;
    return size * 0.4 + frequency * 0.3 + locationRisk * 0.3;
}

// Comparison function to sort transactions by suspiciousness score in descending order
bool compareBySuspiciousness(const Transaction& t1, const Transaction& t2) {
    return t1.suspiciousnessScore > t2.suspiciousnessScore;
}

int main() {
    // Example vector of transactions
    std::vector<Transaction> transactions = {
        Transaction(1, 5000.0, 10, "high-risk-area", 0.0),
        Transaction(2, 200.0, 5, "low-risk-area", 0.0),
        Transaction(3, 10000.0, 20, "high-risk-area", 0.0),
        Transaction(4, 50.0, 2, "low-risk-area", 0.0),
        Transaction(5, 700.0, 15, "medium-risk-area", 0.0)
    };

    // Calculate suspiciousness scores for each transaction
    for (auto& transaction : transactions) {
        transaction.suspiciousnessScore = calculateSuspiciousnessScore(transaction.size, transaction.frequency, transaction.location);
    }

    // Sort transactions by suspiciousness score
    std::sort(transactions.begin(), transactions.end(), compareBySuspiciousness);

    // Output sorted transactions
    std::cout << "Sorted Transactions by Suspiciousness Score:\n";
    for (const auto& transaction : transactions) {
        std::cout << "ID: " << transaction.id
                  << ", Size: " << transaction.size
                  << ", Frequency: " << transaction.frequency
                  << ", Location: " << transaction.location
                  << ", Suspiciousness Score: " << transaction.suspiciousnessScore
                  << std::endl;
    }

    return 0;
}
