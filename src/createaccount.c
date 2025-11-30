#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include"../include/createaccount.h"
#include"../include/accountexist.h"
#include"../include/stdin.h"
#include"../include/struct.h"
#include"../include/config.h"

void create_account(void) {
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) 
    { 
        printf("File open error"); 
        return; 
    }
    Account a;
    printf("\n--- Create New Account ---\n");
    printf("Enter Account Number: ");
    if (scanf("%d", &a.acc_no) != 1) 
    { 
        printf("Invalid input.\n"); 
        return; 
    }
    if (account_exists(a.acc_no)) 
    {
        printf("Account %d already exists.\n", a.acc_no);
        return;
    }
    fflush(stdin);
    printf("Enter the Name: ");
    fgets(a.name,50 , stdin);
    printf("Account Type (S for Savings / C for Current): ");
    a.type = getchar();
    clear_stdin();
    if (a.type != 'S' && a.type != 'C' && a.type != 's' && a.type != 'c') {
        printf("Invalid account type. Use S or C.\n");
        return;
    }
    printf("Initial Deposit Amount: ");
    if (scanf("%lf", &a.balance) != 1) 
    { 
        printf("Invalid amount.\n"); 
        return; 
    }
    if (a.balance < 0) 
    { 
        printf("Balance cannot be negative.\n"); 
        return; 
    }

    
    fwrite(&a, sizeof(Account), 1, fp);
    fclose(fp);

    printf("Account created successfully.\n");
}