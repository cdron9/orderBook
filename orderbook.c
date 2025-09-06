#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "types.h"
#include "orderbook.h"

OrderType GetOrderType(void)
{
    printf("=== SELECT ORDER TYPE ===\n");
    printf("1: Market Buy\n2: Limit Buy\n3: Market Sell\n4: Limit Sell\n5: Exit.\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            return BUY_MARKET;
            break;
        case 2:
            return BUY_LIMIT;
            break;
        case 3:
            return SELL_MARKET;
            break;
        case 4:
            return SELL_LIMIT;
            break;
        case 5:
            break;  
        default:
            printf("Invalid choice, defaulting to Market Buy\n");
            return BUY_MARKET;
    }
    return 0;
}

double GetOrderQuantity(void)
{
    printf("Enter how much stock you want to execute order on: ");
    double OrderQuantity;
    scanf("%lf", &OrderQuantity);

    if (OrderQuantity > 0) {
        return OrderQuantity;
    } else {
        printf("Invalid quantity, must be greater than 0 and less that available stock quantity\n");
        return 0;
    }

    return 0;
}

// TODO fix input issues 
// still breaks if entering number followed by char 
// needs to accept ONLY numbers.
double GetOrderPrice(void)
{
    double ExecutionPrice;

    while (1) {
        printf("Enter desired execution price: ");

        if (scanf("%lf", &ExecutionPrice) != 1) {
            // invalid input (letters, symbols, etc.)
            printf("Value must be numerical, please re-enter.\n");

            // clear the invalid input from stdin
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // check if valid positive number
        if (ExecutionPrice > 0) {
            return ExecutionPrice;
        } else {
            printf("Execution price must be positive.\n");
        }
    }
}


char* GetOrderTicker(void)
{
    static char ticker[32];
    printf("Enter stock ticker: ");
    scanf("%31s", ticker);
    
    for (int i = 0; ticker[i]; i++) {
        ticker[i] = tolower((unsigned char) ticker[i]);
    }

    return ticker;
}


