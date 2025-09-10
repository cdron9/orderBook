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
    char* symbol;    // e.g. (AAPL)
    double quantity;    // available quantity
    double price;       // current price of stock
} Stock;    

typedef struct {
    double cash;                // user cash, as per user input on pragram startup
    Stock holdings[MAX_STOCKS]; // user holdings, stores all info from Stock struct in array
    double pnl;                 // user pnl calculated via change in cash amount 
} User;

typedef struct {
    OrderType type;     // ordertype as per enum
    double quantity;    // how many shares to execute
    double price;       // what price to execute at (ONLY USED FOR LIMIT ORDERS)
    char* symbol;    // ticker symbol
    int orderId;
} Order;

typedef struct {
    Order* orders;
    int size;
    int capacity;
} OrderList;

typedef struct {
    char* symbol;        // ticker
    OrderList buy_orders;   // descending price
    OrderList sell_orders;  // ascending price  
    double last_price;      // last matched price
} OrderBook;

// OrderBook tracks buy/sell sides and last traded price.
// last price can be used to show constantly updating price to user

#endif

