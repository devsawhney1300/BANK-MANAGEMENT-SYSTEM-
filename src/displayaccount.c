#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../include/displayaccount.h"
#include"../include/accountexist.h"
#include"../include/stdin.h"
#include"../include/struct.h"
#include "../include/config.h"




void display_account() {
    int acc_no;
    Account a;
    printf("\n--- Display Account ---\nEnter Account Number: ");
    if (scanf("%d", &acc_no) != 1) 
    { 
        clear_stdin(); 
        printf("Invalid input.\n"); 
        return; 
    }
    FILE *fp;
    fp = fopen(FILENAME, "r");
    if (fp == NULL) 
    { 
        printf("No records found.\n"); 
        return; 
    }
    
    int found = 0;
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.acc_no == acc_no) {
            printf("\nAccount No : %d\nName       : %s\nType       : %c\nBalance    : %.2f\n",
                   a.acc_no, a.name, a.type, a.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account %d not found.\n", acc_no);
    fclose(fp);
}