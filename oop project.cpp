#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <random>
#include <iomanip>
#include <memory>
#include <chrono>
#include <thread>
#include <cmath>

// Forward declarations
class Stock;
class Investor;
class StockExchange;

// Observer pattern interface
class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

// Subject pattern interface
class Subject {
protected:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }
    
    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    
    void notifyObservers(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }
    
    virtual ~Subject() = default;
};

// Stock class that represents a tradable asset
class Stock {
private:
    std::string symbol;
    std::string name;
    double price;
    int availableShares;
    std::vector<double> priceHistory;
    
public:
    Stock(const std::string& symbol, const std::string& name, double initialPrice, int initialShares) 
        : symbol(symbol), name(name), price(initialPrice), availableShares(initialShares) {
        priceHistory.push_back(initialPrice);
    }
    
    // Getters
    std::string getSymbol() const { return symbol; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getAvailableShares() const { return availableShares; }
    
    // Buy shares
    bool buyShares(int quantity) {
        if (quantity <= availableShares) {
            availableShares -= quantity;
            return true;
        }
        return false;
    }
    
    // Sell shares
    void sellShares(int quantity) {
        availableShares += quantity;
    }
    
    // Update price
    void updatePrice(double newPrice) {
        price = newPrice;
        priceHistory.push_back(newPrice);
    }
    
    // Get price history
    const std::vector<double>& getPriceHistory() const {
        return priceHistory;
    }
    
    // Calculate volatility (standard deviation of price changes)
    double getVolatility() const {
        if (priceHistory.size() < 2) return 0.0;
        
        std::vector<double> returns;
        for (size_t i = 1; i < priceHistory.size(); ++i) {
            returns.push_back((priceHistory[i] - priceHistory[i-1]) / priceHistory[i-1]);
        }
        
        double mean = 0.0;
        for (double r : returns) {
            mean += r;
        }
        mean /= returns.size();
        
        double variance = 0.0;
        for (double r : returns) {
            variance += (r - mean) * (r - mean);
        }
        variance /= returns.size();
        
        return std::sqrt(variance);
    }
};

// Transaction class - represents a buy or sell operation
class Transaction {
public:
    enum Type { BUY, SELL };
    
private:
    Type type;
    std::string stockSymbol;
    int quantity;
    double price;
    std::string investorId;
    std::chrono::system_clock::time_point timestamp;
    
public:
    Transaction(Type type, const std::string& stockSymbol, int quantity, double price, const std::string& investorId)
        : type(type), stockSymbol(stockSymbol), quantity(quantity), price(price), investorId(investorId),
          timestamp(std::chrono::system_clock::now()) {}
    
    Type getType() const { return type; }
    std::string getStockSymbol() const { return stockSymbol; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    std::string getInvestorId() const { return investorId; }
    std::chrono::system_clock::time_point getTimestamp() const { return timestamp; }
    
    double getTotalValue() const {
        return quantity * price;
    }
    
    std::string getTypeString() const {
        return type == BUY ? "BUY" : "SELL";
    }
};

// Portfolio class - manages the stocks owned by an investor
class Portfolio {
private:
    std::map<std::string, int> holdings; // Map of stock symbol to quantity
    std::vector<Transaction> transactions;
    
public:
    // Add stocks to the portfolio
    void addStock(const std::string& symbol, int quantity) {
        holdings[symbol] += quantity;
    }
    
    // Remove stocks from the portfolio
    bool removeStock(const std::string& symbol, int quantity) {
        if (holdings.find(symbol) != holdings.end() && holdings[symbol] >= quantity) {
            holdings[symbol] -= quantity;
            if (holdings[symbol] == 0) {
                holdings.erase(symbol);
            }
            return true;
        }
        return false;
    }
    
    // Get quantity of a specific stock
    int getStockQuantity(const std::string& symbol) const {
        auto it = holdings.find(symbol);
        return (it != holdings.end()) ? it->second : 0;
    }
    
    // Get all holdings
    const std::map<std::string, int>& getHoldings() const {
        return holdings;
    }
    
    // Record a transaction
    void recordTransaction(const Transaction& transaction) {
        transactions.push_back(transaction);
    }
    
    // Get transaction history
    const std::vector<Transaction>& getTransactionHistory() const {
        return transactions;
    }
    
    // Calculate total value of portfolio given current stock prices
    double calculateTotalValue(const std::map<std::string, Stock>& stocks) const {
        double totalValue = 0.0;
        for (const auto& holding : holdings) {
            const std::string& symbol = holding.first;
            int quantity = holding.second;
            
            auto stockIt = stocks.find(symbol);
            if (stockIt != stocks.end()) {
                totalValue += quantity * stockIt->second.getPrice();
            }
        }
        return totalValue;
    }
};

// Forward declare StockExchange for use in Investor class
class StockExchange;

// Investor class - represents a user of the stock market
class Investor : public Observer {
private:
    std::string id;
    std::string name;
    double cash;
    Portfolio portfolio;
    std::vector<std::string> notifications;
    
public:
    Investor(const std::string& id, const std::string& name, double initialCash)
        : id(id), name(name), cash(initialCash) {}
    
    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    double getCash() const { return cash; }
    const Portfolio& getPortfolio() const { return portfolio; }
    
    // Buy stocks
    bool buyStock(Stock& stock, int quantity, StockExchange& exchange);
    
    // Sell stocks
    bool sellStock(Stock& stock, int quantity, StockExchange& exchange);
    
    // Update method from Observer interface
    void update(const std::string& message) override {
        notifications.push_back(message);
        std::cout << "Notification for " << name << ": " << message << std::endl;
    }
    
    // Get notifications
    const std::vector<std::string>& getNotifications() const {
        return notifications;
    }
    
    // Calculate net worth
    double calculateNetWorth(const std::map<std::string, Stock>& stocks) const {
        return cash + portfolio.calculateTotalValue(stocks);
    }
};

// StockExchange class - manages all stocks and transactions
class StockExchange : public Subject {
private:
    std::string name;
    std::map<std::string, Stock> stocks;
    std::vector<Transaction> transactions;
    std::map<std::string, Investor*> investors;
    std::random_device rd;
    std::mt19937 gen;
    
public:
    StockExchange(const std::string& name) : name(name), gen(rd()) {}
    
    // Add a stock to the exchange
    void addStock(const Stock& stock) {
        stocks[stock.getSymbol()] = stock;
    }
    
    // Get a stock by symbol
    Stock* getStock(const std::string& symbol) {
        auto it = stocks.find(symbol);
        return (it != stocks.end()) ? &it->second : nullptr;
    }
    
    // Get all stocks
    const std::map<std::string, Stock>& getAllStocks() const {
        return stocks;
    }
    
    // Register an investor
    void registerInvestor(Investor* investor) {
        investors[investor->getId()] = investor;
        addObserver(investor); // Register investor as an observer
    }
    
    // Execute a transaction
    bool executeTransaction(const Transaction& transaction) {
        auto stockIt = stocks.find(transaction.getStockSymbol());
        if (stockIt == stocks.end()) return false;
        
        Stock& stock = stockIt->second;
        
        if (transaction.getType() == Transaction::BUY) {
            if (!stock.buyShares(transaction.getQuantity())) return false;
        } else { // SELL
            stock.sellShares(transaction.getQuantity());
        }
        
        transactions.push_back(transaction);
        
        // Notify observers about the transaction
        std::string message = "Transaction executed: " + transaction.getTypeString() + " " + 
                              std::to_string(transaction.getQuantity()) + " shares of " + 
                              transaction.getStockSymbol() + " at $" + 
                              std::to_string(transaction.getPrice());
        notifyObservers(message);
        
        return true;
    }
    
    // Simulate market fluctuations
    void simulateMarketFluctuations() {
        std::normal_distribution<> distribution(0.0, 0.02); // Mean 0, StdDev 0.02 (2%)
        
        for (auto& stockPair : stocks) {
            Stock& stock = stockPair.second;
            
            // Generate a random price change (-5% to +5% typically)
            double percentChange = distribution(gen);
            double newPrice = stock.getPrice() * (1.0 + percentChange);
            
            // Ensure price doesn't go below $1
            newPrice = std::max(1.0, newPrice);
            
            stock.updatePrice(newPrice);
            
            // Notify observers about significant price changes
            if (std::abs(percentChange) > 0.03) {
                std::string message = "Significant price change for " + stock.getSymbol() + 
                                    ": " + (percentChange > 0 ? "+" : "") + 
                                    std::to_string(percentChange * 100) + "% to $" + 
                                    std::to_string(newPrice);
                notifyObservers(message);
            }
        }
    }
};

// Now implement Investor's buy and sell methods that depend on StockExchange
bool Investor::buyStock(Stock& stock, int quantity, StockExchange& exchange) {
    double totalCost = stock.getPrice() * quantity;
    
    if (cash >= totalCost && stock.getAvailableShares() >= quantity) {
        Transaction transaction(Transaction::BUY, stock.getSymbol(), quantity, stock.getPrice(), id);
        
        if (exchange.executeTransaction(transaction)) {
            cash -= totalCost;
            portfolio.addStock(stock.getSymbol(), quantity);
            portfolio.recordTransaction(transaction);
            return true;
        }
    }
    
    return false;
}

bool Investor::sellStock(Stock& stock, int quantity, StockExchange& exchange) {
    if (portfolio.getStockQuantity(stock.getSymbol()) >= quantity) {
        Transaction transaction(Transaction::SELL, stock.getSymbol(), quantity, stock.getPrice(), id);
        
        if (exchange.executeTransaction(transaction)) {
            cash += stock.getPrice() * quantity;
            portfolio.removeStock(stock.getSymbol(), quantity);
            portfolio.recordTransaction(transaction);
            return true;
        }
    }
    
    return false;
}

// TradingStrategy interface - Strategy pattern
class TradingStrategy {
public:
    virtual bool shouldBuy(const Stock& stock, const Investor& investor) const = 0;
    virtual bool shouldSell(const Stock& stock, const Investor& investor) const = 0;
    virtual int getBuyQuantity(const Stock& stock, const Investor& investor) const = 0;
    virtual int getSellQuantity(const Stock& stock, const Investor& investor) const = 0;
    virtual ~TradingStrategy() = default;
};

// Concrete trading strategies
class ValueTradingStrategy : public TradingStrategy {
public:
    bool shouldBuy(const Stock& stock, const Investor& investor) const override {
        // Buy if the stock price is below a certain threshold and we have enough cash
        double threshold = 50.0;
        return stock.getPrice() < threshold && investor.getCash() > stock.getPrice() * 10;
    }
    
    bool shouldSell(const Stock& stock, const Investor& investor) const override {
        // Sell if the stock price is above a certain threshold and we own some
        double threshold = 150.0;
        return stock.getPrice() > threshold && investor.getPortfolio().getStockQuantity(stock.getSymbol()) > 0;
    }
    
    int getBuyQuantity(const Stock& stock, const Investor& investor) const override {
        // Buy as many as we can afford, up to 10% of our cash
        int maxAffordable = static_cast<int>(investor.getCash() * 0.1 / stock.getPrice());
        return std::min(maxAffordable, stock.getAvailableShares());
    }
    
    int getSellQuantity(const Stock& stock, const Investor& investor) const override {
        // Sell half of our holdings
        return investor.getPortfolio().getStockQuantity(stock.getSymbol()) / 2;
    }
};

class MomentumTradingStrategy : public TradingStrategy {
public:
    bool shouldBuy(const Stock& stock, const Investor& investor) const override {
        // Buy if the stock has positive momentum (price increasing)
        const auto& history = stock.getPriceHistory();
        if (history.size() < 3) return false;
        
        return history[history.size()-1] > history[history.size()-2] && 
               history[history.size()-2] > history[history.size()-3] &&
               investor.getCash() > stock.getPrice() * 5;
    }
    
    bool shouldSell(const Stock& stock, const Investor& investor) const override {
        // Sell if the stock has negative momentum (price decreasing)
        const auto& history = stock.getPriceHistory();
        if (history.size() < 3) return false;
        
        return history[history.size()-1] < history[history.size()-2] && 
               history[history.size()-2] < history[history.size()-3] &&
               investor.getPortfolio().getStockQuantity(stock.getSymbol()) > 0;
    }
    
int getBuyQuantity(const Stock& stock, const Investor& investor) const override {
        // Buy proportionally to the momentum strength
        double momentum = 0;
        const auto& history = stock.getPriceHistory();
        if (history.size() >= 3) {
            momentum = (history[history.size()-1] - history[history.size()-3]) / history[history.size()-3];
        }
        
        int quantity = static_cast<int>(investor.getCash() * momentum * 0.5 / stock.getPrice());
        return std::min(quantity, stock.getAvailableShares());
    }
    
    int getSellQuantity(const Stock& stock, const Investor& investor) const override {
        // Sell proportionally to the negative momentum strength
        double momentum = 0;
        const auto& history = stock.getPriceHistory();
        if (history.size() >= 3) {
            momentum = (history[history.size()-3] - history[history.size()-1]) / history[history.size()-3];
        }
        
        int currentQuantity = investor.getPortfolio().getStockQuantity(stock.getSymbol());
        return static_cast<int>(currentQuantity * momentum * 0.5);
    }
};

// AI Trader class - uses trading strategies
class AITrader : public Investor {
private:
    std::unique_ptr<TradingStrategy> strategy;
    
public:
    AITrader(const std::string& id, const std::string& name, double initialCash, TradingStrategy* strategy)
        : Investor(id, name, initialCash), strategy(strategy) {}
    
    void evaluateAndTrade(const std::map<std::string, Stock>& stocks, StockExchange& exchange) {
        for (const auto& stockPair : stocks) {
            const Stock& stock = stockPair.second;
            
            // Check if we should buy this stock
            if (strategy->shouldBuy(stock, *this)) {
                int quantity = strategy->getBuyQuantity(stock, *this);
                if (quantity > 0) {
                    Stock* mutableStock = exchange.getStock(stock.getSymbol());
                    if (mutableStock) {
                        buyStock(*mutableStock, quantity, exchange);
                    }
                }
            }
            
            // Check if we should sell this stock
            if (strategy->shouldSell(stock, *this)) {
                int quantity = strategy->getSellQuantity(stock, *this);
                if (quantity > 0) {
                    Stock* mutableStock = exchange.getStock(stock.getSymbol());
                    if (mutableStock) {
                        sellStock(*mutableStock, quantity, exchange);
                    }
                }
            }
        }
    }
    
    void setStrategy(TradingStrategy* newStrategy) {
        strategy.reset(newStrategy);
    }
    
    const TradingStrategy* getStrategy() const {
        return strategy.get();
    }
};

// Main function to demonstrate the stock market simulation
int main() {
    // Create stock exchange
    StockExchange nyse("New York Stock Exchange");
    
    // Add some stocks
    nyse.addStock(Stock("AAPL", "Apple Inc.", 150.0, 10000));
    nyse.addStock(Stock("MSFT", "Microsoft Corporation", 280.0, 8000));
    nyse.addStock(Stock("GOOGL", "Alphabet Inc.", 2200.0, 5000));
    nyse.addStock(Stock("AMZN", "Amazon.com Inc.", 3300.0, 3000));
    nyse.addStock(Stock("TSLA", "Tesla Inc.", 700.0, 7000));
    
    // Create human investors
    Investor investor1("INV001", "John Smith", 100000.0);
    Investor investor2("INV002", "Jane Doe", 120000.0);
    
    // Register investors
    nyse.registerInvestor(&investor1);
    nyse.registerInvestor(&investor2);
    
    // Create AI traders with different strategies
    AITrader aiTrader1("AI001", "ValueBot", 200000.0, new ValueTradingStrategy());
    AITrader aiTrader2("AI002", "MomentumBot", 200000.0, new MomentumTradingStrategy());
    
    // Register AI traders
    nyse.registerInvestor(&aiTrader1);
    nyse.registerInvestor(&aiTrader2);
    
    // Execute some manual trades for human investors
    Stock* apple = nyse.getStock("AAPL");
    Stock* microsoft = nyse.getStock("MSFT");
    Stock* google = nyse.getStock("GOOGL");
    Stock* amazon = nyse.getStock("AMZN");
    Stock* tesla = nyse.getStock("TSLA");
    
    if (apple && microsoft && google && amazon && tesla) {
        investor1.buyStock(*apple, 10, nyse);
        investor1.buyStock(*google, 5, nyse);
        
        investor2.buyStock(*microsoft, 8, nyse);
        investor2.buyStock(*amazon, 3, nyse);
        investor2.buyStock(*tesla, 15, nyse);
    }
    
    // Run simulation for several days
    const int simulationDays = 30;
    
    std::cout << "=== STARTING STOCK MARKET SIMULATION FOR " << simulationDays << " DAYS ===" << std::endl;
    
    for (int day = 1; day <= simulationDays; ++day) {
        std::cout << "\n=== DAY " << day << " ===" << std::endl;
        
        // Simulate market fluctuations
        nyse.simulateMarketFluctuations();
        
        // Let AI traders make decisions
        aiTrader1.evaluateAndTrade(nyse.getAllStocks(), nyse);
        aiTrader2.evaluateAndTrade(nyse.getAllStocks(), nyse);
        
        // Print current stock prices
        std::cout << "\nCurrent Stock Prices:" << std::endl;
        for (const auto& stockPair : nyse.getAllStocks()) {
            const Stock& stock = stockPair.second;
            std::cout << stock.getSymbol() << " (" << stock.getName() << "): $" 
                     << std::fixed << std::setprecision(2) << stock.getPrice() 
                     << " - Available shares: " << stock.getAvailableShares() << std::endl;
        }
        
        // Print investor portfolios every 5 days
        if (day % 5 == 0) {
            std::cout << "\nInvestor Portfolios:" << std::endl;
            
            // Human investors
            std::cout << "\n" << investor1.getName() << " (Human):" << std::endl;
            std::cout << "Cash: $" << std::fixed << std::setprecision(2) << investor1.getCash() << std::endl;
            std::cout << "Portfolio value: $" << investor1.getPortfolio().calculateTotalValue(nyse.getAllStocks()) << std::endl;
            std::cout << "Net worth: $" << investor1.calculateNetWorth(nyse.getAllStocks()) << std::endl;
            
            std::cout << "\n" << investor2.getName() << " (Human):" << std::endl;
            std::cout << "Cash: $" << std::fixed << std::setprecision(2) << investor2.getCash() << std::endl;
            std::cout << "Portfolio value: $" << investor2.getPortfolio().calculateTotalValue(nyse.getAllStocks()) << std::endl;
            std::cout << "Net worth: $" << investor2.calculateNetWorth(nyse.getAllStocks()) << std::endl;
            
            // AI traders
            std::cout << "\n" << aiTrader1.getName() << " (AI - Value Strategy):" << std::endl;
            std::cout << "Cash: $" << std::fixed << std::setprecision(2) << aiTrader1.getCash() << std::endl;
            std::cout << "Portfolio value: $" << aiTrader1.getPortfolio().calculateTotalValue(nyse.getAllStocks()) << std::endl;
            std::cout << "Net worth: $" << aiTrader1.calculateNetWorth(nyse.getAllStocks()) << std::endl;
            
            std::cout << "\n" << aiTrader2.getName() << " (AI - Momentum Strategy):" << std::endl;
            std::cout << "Cash: $" << std::fixed << std::setprecision(2) << aiTrader2.getCash() << std::endl;
            std::cout << "Portfolio value: $" << aiTrader2.getPortfolio().calculateTotalValue(nyse.getAllStocks()) << std::endl;
            std::cout << "Net worth: $" << aiTrader2.calculateNetWorth(nyse.getAllStocks()) << std::endl;
        }
        
        // Sleep to simulate a day passing
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
    // Final summary
    std::cout << "\n=== SIMULATION SUMMARY AFTER " << simulationDays << " DAYS ===" << std::endl;
    
    // Calculate performance
    double investor1InitialCash = 100000.0;
    double investor2InitialCash = 120000.0;
    double aiTrader1InitialCash = 200000.0;
    double aiTrader2InitialCash = 200000.0;
    
    double investor1FinalWorth = investor1.calculateNetWorth(nyse.getAllStocks());
    double investor2FinalWorth = investor2.calculateNetWorth(nyse.getAllStocks());
    double aiTrader1FinalWorth = aiTrader1.calculateNetWorth(nyse.getAllStocks());
    double aiTrader2FinalWorth = aiTrader2.calculateNetWorth(nyse.getAllStocks());
    
    double investor1Return = (investor1FinalWorth - investor1InitialCash) / investor1InitialCash * 100;
    double investor2Return = (investor2FinalWorth - investor2InitialCash) / investor2InitialCash * 100;
    double aiTrader1Return = (aiTrader1FinalWorth - aiTrader1InitialCash) / aiTrader1InitialCash * 100;
    double aiTrader2Return = (aiTrader2FinalWorth - aiTrader2InitialCash) / aiTrader2InitialCash * 100;
    
    std::cout << "\nInvestment Returns:" << std::endl;
    std::cout << investor1.getName() << " (Human): " << std::fixed << std::setprecision(2) << investor1Return << "%" << std::endl;
    std::cout << investor2.getName() << " (Human): " << investor2Return << "%" << std::endl;
    std::cout << aiTrader1.getName() << " (AI - Value Strategy): " << aiTrader1Return << "%" << std::endl;
    std::cout << aiTrader2.getName() << " (AI - Momentum Strategy): " << aiTrader2Return << "%" << std::endl;
    
    // Determine winner
    std::vector<std::pair<std::string, double>> results = {
        {investor1.getName() + " (Human)", investor1Return},
        {investor2.getName() + " (Human)", investor2Return},
        {aiTrader1.getName() + " (AI - Value Strategy)", aiTrader1Return},
        {aiTrader2.getName() + " (AI - Momentum Strategy)", aiTrader2Return}
    };
    
    auto winner = std::max_element(results.begin(), results.end(), 
        [](const auto& a, const auto& b) { return a.second < b.second; });
    
    std::cout << "\nThe winner is: " << winner->first << " with a return of " 
             << std::fixed << std::setprecision(2) << winner->second << "%" << std::endl;
    
    return 0;
}   