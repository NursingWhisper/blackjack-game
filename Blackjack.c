#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main () {
	int MAX_USER_CARDS = 10;
	int MAX_DEALER_CARDS = 10;
	int user_cards[MAX_DEALER_CARDS];
	int dealer_cards[MAX_DEALER_CARDS];
	char user_input;
	int user_total = 0;
	int dealer_total = 0;

	srand(time(NULL));

	do {
		user_cards[0] = rand() % 11 + 1;
		printf("Your first card is: %d\n", user_cards[0]);

		Sleep(1000);

		user_cards[1] = rand() % 11 + 1;
		printf("Your second card is: %d\n", user_cards[1]);

		Sleep(1000);
		user_total = user_cards[0] + user_cards[1];
		printf("Your total is: %d\n", user_total);
		
		Sleep(1000);

		dealer_cards[0] = rand() % 11 + 1;
		printf("The dealer is showing: %d\n", dealer_cards[0]);

		Sleep(1000);

		printf("Do you want to hit or stand? (h/s): ");
		scanf(" %c", &user_input);
		Sleep(1000);

		if (user_total == 21) {
			printf("You got a blackJack! You win!\n");
			Sleep(1000);
			break;
		}
		int user_card_count = 2;
		while (user_input == 'h' || user_input == 'H') {
			user_cards[user_card_count] = rand() % 11 + 1;
			user_total += user_cards[user_card_count];
			printf("You drew a %d\n", user_cards[user_card_count]);
			Sleep(1000);
			printf("Your total is now: %d\n", user_total);
			Sleep(1000);

			if (user_total > 21) {
				printf("You busted! Dealer wins.");
				Sleep(1000);
				break;

			}	
			printf("Do you want to hit or stand? (h/s): ");
			scanf(" %c", &user_input);
			Sleep(1000);
			user_card_count++;	
		}
		if (user_total <= 21) {
			dealer_cards[1] = rand() % 11 + 1;
			printf("The dealer's second card is: %d\n", dealer_cards[1]);
			dealer_total = dealer_cards[0] + dealer_cards[1];
		
			Sleep(1000);
			printf("The dealer's total is: %d\n", dealer_total);
			Sleep(1000);

			int dealer_card_count = 2;
			if (dealer_total < 21) {
				while (dealer_total < 17) {
					dealer_cards[dealer_card_count] = rand() % 11 + 1;
					dealer_total += dealer_cards[dealer_card_count];
					printf("The dealer drew a %d\n", dealer_cards[dealer_card_count]);
					Sleep(1000);
					printf("The dealer's total is now: %d\n", dealer_total);
					Sleep(1000);
					dealer_card_count++;

				}
			}

		}
		
		if (dealer_total > 21) {
			printf("The dealer busted! You win!\n");
		} else if (dealer_total == user_total) {
			printf("It's a tie!\n");
		} else if (dealer_total > user_total) {
			printf("Dealer wins with %d against your %d\n", dealer_total, user_total);
		} else if (user_total > dealer_total) {
			printf("You win with %d against the dealer's %d\n", user_total, dealer_total);
		}


		printf("Do you want to play again? (y/n): ");
		scanf(" %c", &user_input);
		printf("\n----------------------------------------------------\n\n");
	}while (user_input == 'y' || user_input == 'Y');

	return 0;
}