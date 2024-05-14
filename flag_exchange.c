#include <stdio.h>
#include <stdlib.h>

// Function to print colored text
void print_colored(const char *text, const char *color_code)
{
    printf("%s%s\033[0m", color_code, text);
}

// ASCII art for welcome message
void print_welcome_message()
{
    print_colored("Welcome to the flag exchange\n", "\033[1;34m");
    print_colored("We sell flags\n\n", "\033[1;34m");

    print_colored("  ______ _             _               ______ _ _             \n", "\033[1;33m");
    print_colored(" |  ____(_)           | |             |  ____(_) |            \n", "\033[1;33m");
    print_colored(" | |__   _ _ __   __ _| | _____ _ __  | |__   _| | __ _ _   _ \n", "\033[1;33m");
    print_colored(" |  __| | | '_ \\ / _` | |/ / _ \\ '__| |  __| | | |/ _` | | | |\n", "\033[1;33m");
    print_colored(" | |    | | | | | (_| |   <  __/ |    | |    | | | (_| | |_| |\n", "\033[1;33m");
    print_colored(" |_|    |_|_| |_|\\__,_|_|\\_\\___|_|    |_|    |_|_|\\__,_|\\__, |\n", "\033[1;33m");
    print_colored("                                                         __/ |\n", "\033[1;33m");
    print_colored("                                                        |___/ \n\n", "\033[1;33m");
}

int main()
{
    setbuf(stdout, NULL);
    int con = 0;
    int account_balance = 1100;

    while (con == 0)
    {
        print_welcome_message();

        printf("\033[1;32m1. Check Account Balance\n");
        printf("2. Buy Flags\n");
        printf("3. Exit\n\033[0m");

        int menu;
        printf("\n\033[1;36mEnter a menu selection: \033[0m");
        fflush(stdin);
        scanf("%d", &menu);

        if (menu == 1)
        {
            printf("\n\n\n\033[1;35mBalance: %d \n\n\n\033[0m", account_balance);
        }
        else if (menu == 2)
        {
            printf("\033[1;32mCurrently for sale\n");
            printf("1. Definitely not the flag Flag\n");
            printf("2. 1337 Flag\n\033[0m");

            int auction_choice;
            fflush(stdin);
            scanf("%d", &auction_choice);

            if (auction_choice == 1)
            {
                printf("\033[1;33mThese knockoff Flags cost 900 each, enter desired quantity\n\033[0m");

                int number_flags = 0;
                fflush(stdin);
                scanf("%d", &number_flags);

                if (number_flags > 0)
                {
                    int total_cost = 0;
                    total_cost = 900 * number_flags;
                    printf("\n\033[1;33mThe final cost is: %d\n\033[0m", total_cost);

                    if (total_cost <= account_balance)
                    {
                        account_balance = account_balance - total_cost;
                        printf("\n\033[1;35mYour current balance after transaction: %d\n\n\033[0m", account_balance);
                    }
                    else
                    {
                        printf("\033[1;31mNot enough funds\n\033[0m");
                    }
                }
            }
            else if (auction_choice == 2)
            {
                printf("\033[1;33m1337 flags cost 100000 dollars, and we only have 1 in stock\n");
                printf("Enter 1 to buy one\n\033[0m");

                int bid = 0;
                fflush(stdin);
                scanf("%d", &bid);

                if (bid == 1)
                {
                    if (account_balance > 100000)
                    {
                        FILE *f = fopen("flag.txt", "r");
                        if (f == NULL)
                        {
                            printf("\033[1;31mFlag file not found\n\033[0m");
                            exit(0);
                        }

                        char buf[64];
                        fgets(buf, 63, f);
                        printf("\033[1;32mYOUR FLAG IS: %s\n\033[0m", buf);
                    }
                    else
                    {
                        printf("\n\033[1;31mNot enough funds for transaction\n\n\n\033[0m");
                    }
                }
            }
        }
        else
        {
            con = 1;
        }
    }

    return 0;
}
