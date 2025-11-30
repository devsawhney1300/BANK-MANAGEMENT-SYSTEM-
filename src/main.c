#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../include/createaccount.h"
#include"../include/displayaccount.h"
#include"../include/depositwithdraw.h"
#include"../include/deleteaccount.h"
#include"../include/modifyaccount.h"
#include"../include/accountexist.h"
#include"../include/stdin.h"
#include"../include/struct.h"
#include "../include/config.h"

int main()
{
    int choice;
    while (1)
    {
        printf("\n=========================\n");
        printf("   BANK MANAGEMENT\n");
        printf("=========================\n");
        printf("1. Create new account\n");
        printf("2. Display account\n");
        printf("3. Deposit amount\n");
        printf("4. Withdraw amount\n");
        printf("5. Modify account\n");
        printf("6. Delete account\n");
        printf("7. Exit\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            display_account();
            break;
        case 3:
            deposit_withdraw(1);
            break;
        case 4:
            deposit_withdraw(0);
            break;
        case 5:
            modify_account();
            break;
        case 6:
            delete_account();
            break;
        case 7:
            printf("Thankyou for visiting.\n");
            exit(0);
        default:
            printf("Invalid choice. Try 1-7.\n");
        }
    }
    return 0;
}