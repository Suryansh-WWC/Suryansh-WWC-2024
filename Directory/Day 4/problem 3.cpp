#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

// Define a structure for catalog items
struct CatalogItem {
    std::string title;  // Title of the movie or TV show
    int totalViews;     // Total views
    double userRating;  // Average user rating
    int releaseYear;    // Release year
    double trendingScore;  // Combined score for popularity and recency

    // Constructor for easier initialization
    CatalogItem(const std::string& title, int totalViews, double userRating, int releaseYear)
        : title(title), totalViews(totalViews), userRating(userRating), releaseYear(releaseYear), trendingScore(0.0) {}
};

// Function to calculate trending score (popularity and recency combined)
double calculateTrendingScore(int totalViews, double userRating, int releaseYear, int currentYear) {
    double recencyFactor = 1.0 / (1.0 + std::exp(-(currentYear - releaseYear - 5))); // Exponential decay for older content
    return totalViews * 0.6 + userRating * 100 * 0.4 + recencyFactor * 100;
}

// Function to calculate personalized relevance score (dummy function for illustration)
double calculateRelevanceScore(const CatalogItem& item, const std::vector<std::string>& userHistory) {
    for (const auto& watched : userHistory) {
        if (item.title.find(watched) != std::string::npos) {
            return item.trendingScore * 1.5; // Boost score for related content
        }
    }
    return item.trendingScore;
}

// Comparison function to sort items by trending score in descending order
bool compareByTrendingScore(const CatalogItem& item1, const CatalogItem& item2) {
    return item1.trendingScore > item2.trendingScore;
}

// Comparison function to sort items by relevance score in descending order
bool compareByRelevanceScore(const std::pair<CatalogItem, double>& item1, const std::pair<CatalogItem, double>& item2) {
    return item1.second > item2.second;
}

int main() {
    // Example catalog
    std::vector<CatalogItem> catalog = {
        CatalogItem("Movie A", 100000, 4.5, 2020),
        CatalogItem("Movie B", 50000, 4.7, 2018),
        CatalogItem("TV Show C", 150000, 4.2, 2023),
        CatalogItem("Movie D", 20000, 3.8, 2015),
        CatalogItem("TV Show E", 80000, 4.6, 2021)
    };

    int currentYear = 2024; // Assume current year is 2024

    // Calculate trending scores for each item
    for (auto& item : catalog) {
        item.trendingScore = calculateTrendingScore(item.totalViews, item.userRating, item.releaseYear, currentYear);
    }

    // Sort catalog by trending score
    std::sort(catalog.begin(), catalog.end(), compareByTrendingScore);

    // Output catalog sorted by trending score
    std::cout << "Catalog sorted by trending score:\n";
    for (const auto& item : catalog) {
        std::cout << "Title: " << item.title
                  << ", Total Views: " << item.totalViews
                  << ", User Rating: " << item.userRating
                  << ", Release Year: " << item.releaseYear
                  << ", Trending Score: " << item.trendingScore
                  << std::endl;
    }

    // Example user viewing history
    std::vector<std::string> userHistory = {"Movie A", "TV Show C"};

    // Calculate relevance scores for each item
    std::vector<std::pair<CatalogItem, double>> personalizedCatalog;
    for (const auto& item : catalog) {
        double relevanceScore = calculateRelevanceScore(item, userHistory);
        personalizedCatalog.push_back({item, relevanceScore});
    }

    // Sort catalog by relevance score
    std::sort(personalizedCatalog.begin(), personalizedCatalog.end(), compareByRelevanceScore);

    // Output personalized catalog sorted by relevance score
    std::cout << "\nPersonalized catalog sorted by relevance score:\n";
    for (const auto& pair : personalizedCatalog) {
        const auto& item = pair.first;
        std::cout << "Title: " << item.title
                  << ", Total Views: " << item.totalViews
                  << ", User Rating: " << item.userRating
                  << ", Release Year: " << item.releaseYear
                  << ", Relevance Score: " << pair.second
                  << std::endl;
    }

    return 0;
}
