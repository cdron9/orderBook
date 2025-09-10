#include "user.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

User u; // global user, only one exists

double GetUserCash(void) 
{
    u.cash = 10000;
    return u.cash;
}

double GetUserPNL(void)
{
    u.pnl = u.cash; // you’ll probably update this later
    return u.pnl;
}

void ShowUserCash(void)
{
    printf("Cash: %lf\n", u.cash);
}

void ShowUserPNL(void)
{
    printf("PnL: %lf\n", u.pnl);
}

