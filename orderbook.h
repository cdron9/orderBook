#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "types.h"

OrderType GetOrderType(void); 
double GetOrderQuantity(void);
double GetOrderPrice(void);   // only used for limit orders
char* GetOrderTicker(void);          // need to decide on method for choosing stocks.
int GetOrderId(void);                           // takes no value, should be an iterable integer.

#endif
