#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

// Define a structure for advertisements
struct Advertisement {
    std::string advertiserName;  // Name of the advertiser
    double bidAmount;            // Bid amount per impression
    double engagementRate;       // Engagement rate (clicks/views)
    double remainingBudget;      // Remaining budget for the ad
    double priorityScore;        // Combined score for prioritization

    // Constructor for easier initialization
    Advertisement(const std::string& advertiserName, double bidAmount, double engagementRate, double remainingBudget)
        : advertiserName(advertiserName), bidAmount(bidAmount), engagementRate(engagementRate), remainingBudget(remainingBudget), priorityScore(0.0) {}
};

// Function to calculate priority score (bid amount, engagement rate, and remaining budget combined)
double calculatePriorityScore(double bidAmount, double engagementRate, double remainingBudget) {
    return bidAmount * 0.5 + engagementRate * 0.3 + remainingBudget * 0.2;
}

// Comparison function to sort advertisements by priority score in descending order
bool compareByPriorityScore(const Advertisement& ad1, const Advertisement& ad2) {
    return ad1.priorityScore > ad2.priorityScore;
}

int main() {
    // Example advertisements
    std::vector<Advertisement> ads = {
        Advertisement("Advertiser A", 2.5, 0.1, 10000),
        Advertisement("Advertiser B", 3.0, 0.2, 5000),
        Advertisement("Advertiser C", 1.5, 0.15, 20000),
        Advertisement("Advertiser D", 4.0, 0.05, 8000),
        Advertisement("Advertiser E", 2.0, 0.25, 12000)
    };

    // Calculate priority scores for each advertisement
    for (auto& ad : ads) {
        ad.priorityScore = calculatePriorityScore(ad.bidAmount, ad.engagementRate, ad.remainingBudget);
    }

    // Sort advertisements by priority score
    std::sort(ads.begin(), ads.end(), compareByPriorityScore);

    // Output sorted advertisements
    std::cout << "Advertisements sorted by priority score:\n";
    for (const auto& ad : ads) {
        std::cout << "Advertiser: " << ad.advertiserName
                  << ", Bid Amount: " << ad.bidAmount
                  << ", Engagement Rate: " << ad.engagementRate
                  << ", Remaining Budget: " << ad.remainingBudget
                  << ", Priority Score: " << ad.priorityScore
                  << std::endl;
    }

    return 0;
}
