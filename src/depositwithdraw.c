#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../include/depositwithdraw.h"
#include"../include/accountexist.h"
#include"../include/stdin.h"
#include"../include/struct.h"
#include "../include/config.h"

void deposit_withdraw(int is_deposit) 
{
    double amt;
    FILE *fp = fopen(FILENAME, "rb+");
     if (fp== NULL) 
    { 
        printf("No records found.\n"); 
        return; 
    }
    int acc_no;
    printf("\n--- %s ---\n", is_deposit ? "Deposit" : "Withdraw");
    printf("Enter Account Number: ");
    if (scanf("%d", &acc_no) != 1) 
    {  
        printf("Invalid input.\n"); 
        return; 
    }
    Account a;
    int found = 0;
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.acc_no == acc_no) {
            found = 1;
            printf("Account found: %s | Balance: %.2f\n", a.name, a.balance);
            printf("Enter amount: ");
            
            if (scanf("%lf", &amt) != 1) { clear_stdin(); printf("Invalid amount.\n"); break; }
            if (amt <= 0) 
            { 
                printf("Amount must be positive.\n"); 
                break; 
            }
            if (is_deposit) 
            {
                a.balance += amt;
            } else 
            {
                if (amt > a.balance) {
                    printf("Insufficient balance.\n");
                    break;
                }
                a.balance -= amt;
            }
            // write back
            fseek(fp, -((long)sizeof(Account)), SEEK_CUR);
            fwrite(&a, sizeof(Account), 1, fp);
            printf("%s successful. New balance: %.2f\n", is_deposit ? "Deposit" : "Withdrawal", a.balance);
            break;
        }
    }
    if (!found) printf("Account %d not found.\n", acc_no);
    fclose(fp);
}