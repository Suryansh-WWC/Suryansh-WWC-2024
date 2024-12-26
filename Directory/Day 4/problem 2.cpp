#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

// Define a structure for trade records
struct Trade {
    std::string timestamp;  // Timestamp of the trade
    std::string stockSymbol;  // Stock symbol
    double tradePrice;  // Trade price
    int tradeVolume;  // Trade volume

    // Constructor for easier initialization
    Trade(const std::string& timestamp, const std::string& stockSymbol, double tradePrice, int tradeVolume)
        : timestamp(timestamp), stockSymbol(stockSymbol), tradePrice(tradePrice), tradeVolume(tradeVolume) {}
};

// Comparison function to sort trades by timestamp
bool compareByTimestamp(const Trade& t1, const Trade& t2) {
    return t1.timestamp < t2.timestamp;
}

// Comparison function to sort trades by stock symbol
bool compareByStockSymbol(const Trade& t1, const Trade& t2) {
    return t1.stockSymbol < t2.stockSymbol;
}

// Function to group trades by trading volume trends
std::map<int, std::vector<Trade>> groupByVolume(const std::vector<Trade>& trades) {
    std::map<int, std::vector<Trade>> volumeGroups;
    for (const auto& trade : trades) {
        volumeGroups[trade.tradeVolume].push_back(trade);
    }
    return volumeGroups;
}

int main() {
    // Example vector of trade records
    std::vector<Trade> trades = {
        Trade("2024-12-26T10:00:00Z", "AAPL", 150.25, 1000),
        Trade("2024-12-26T10:01:00Z", "GOOGL", 2800.50, 500),
        Trade("2024-12-26T10:00:30Z", "AAPL", 151.00, 2000),
        Trade("2024-12-26T10:02:00Z", "MSFT", 300.75, 1500),
        Trade("2024-12-26T10:01:30Z", "GOOGL", 2805.00, 700)
    };

    // Sort trades by timestamp
    std::sort(trades.begin(), trades.end(), compareByTimestamp);

    // Output trades sorted by timestamp
    std::cout << "Trades sorted by timestamp:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp
                  << ", Stock: " << trade.stockSymbol
                  << ", Price: " << trade.tradePrice
                  << ", Volume: " << trade.tradeVolume
                  << std::endl;
    }

    // Sort trades by stock symbol
    std::sort(trades.begin(), trades.end(), compareByStockSymbol);

    // Output trades sorted by stock symbol
    std::cout << "\nTrades sorted by stock symbol:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp
                  << ", Stock: " << trade.stockSymbol
                  << ", Price: " << trade.tradePrice
                  << ", Volume: " << trade.tradeVolume
                  << std::endl;
    }

    // Group trades by trading volume
    auto volumeGroups = groupByVolume(trades);

    // Output grouped trades by volume
    std::cout << "\nTrades grouped by trading volume:\n";
    for (const auto& group : volumeGroups) {
        std::cout << "Volume: " << group.first << "\n";
        for (const auto& trade : group.second) {
            std::cout << "  Timestamp: " << trade.timestamp
                      << ", Stock: " << trade.stockSymbol
                      << ", Price: " << trade.tradePrice
                      << std::endl;
        }
    }

    return 0;
}
