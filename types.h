#ifndef TYPES_H
#define TYPES_H

#define MAX_STOCKS 5

// navigation states
typedef enum {
    SCREEN_ORDERBOOK,
    SCREEN_ACCOUNT,
    SCREEN_SEARCH,
    SCREEN_EXECUTE
} Screen;

typedef enum {
    BUY_MARKET,
    BUY_LIMIT,
    SELL_MARKET,
    SELL_LIMIT
} OrderType;

typedef struct {
    const char* symbol; // e.g. (AAPL)
    int quantity;       // available quantity
    double price;       // current price of stock
} Stock;    

typedef struct {
    double cash;                // user cash, as per user input on pragram startup
    Stock holdings[MAX_STOCKS]; // user holdings, stores all info from Stock struct in array
    double pnl;                 // user pnl calculated via change in cash amount 
} User;

typedef struct {
    OrderType type;     // ordertype as per enum
    double quanitity;   // how many shares to execute
    double price;       // what price to execute at (ONLY USED FOR LIMIT ORDERS)
    char stock[5];      // ticker symbol
} Order;


#endif // TYPES_H

