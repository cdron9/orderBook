#include <stdio.h>
#include <stdbool.h>
#include "types.h"


int main(void) {
    printf("\033[2J\033[H");
    Screen current_screen = SCREEN_ORDERBOOK;

    // main program loop
    bool running = true;

    while (running) {
        printf("\033[2J\033[H");

        // alwats show orderbook first
        printf("=== ORDERBOOK ===\n");
        // TODO: print orderbook here
        
        // show whatever screen is active
           switch (current_screen) {
                case SCREEN_ORDERBOOK:
                    printf("\n[1] Execute Trade\n[2] Account\n[3] Search Stock\n[4] Quit\n");
                    break;
                case SCREEN_ACCOUNT:
                    printf("\n=== ACCOUNT ===\n");
                    printf("[1] Back to Orderbook\n");
                    break;
                case SCREEN_SEARCH:
                    printf("\n=== SEARCH ===\n");
                    printf("[1] Back to Orderbook\n");
                    break;
                case SCREEN_EXECUTE:
                    printf("\n=== EXECUTE ORDER ===\n");
                    printf("[1] Back to Orderbook\n");
                    break;
            }

        int choice;
        scanf("%d", &choice);

        // update screen based on input
        if (current_screen == SCREEN_ORDERBOOK) {
            switch (choice) {
                case 1: current_screen = SCREEN_EXECUTE; break;
                case 2: current_screen = SCREEN_ACCOUNT; break;
                case 3: current_screen = SCREEN_SEARCH; break;
                case 4: running = false; break;
            }
        } else {
            // any input goes back for now
            current_screen = SCREEN_ORDERBOOK;
        }
    }
}
