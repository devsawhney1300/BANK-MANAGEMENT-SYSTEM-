#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../include/deleteaccount.h"
#include"../include/accountexist.h"
#include"../include/stdin.h"
#include"../include/struct.h"
#include "../include/config.h"


int delete_account() {
    int acc_no;
    printf("\n--- Delete Account ---\nEnter Account Number: ");
    if (scanf("%d", &acc_no) != 1) { 
        clear_stdin(); printf("Invalid input.\n"); 
        return -1; 
    }
    FILE *fp; 
    fp =fopen("account.dat", "rb");
    if (fp == NULL) 
    { 
        printf("No records found.\n"); 
        return 0; 
    }
    FILE *tmp = fopen("temp.txt", "wb");
    if (tmp == NULL) { 
        printf("Temp file error"); 
        fclose(fp); 
        return -1; 
    }
    Account a;
    int found = 0;
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.acc_no == acc_no) {
            found = 1;
            continue; 
        }
        fwrite(&a, sizeof(Account), 1, tmp);
    }
    fclose(fp);
    fclose(tmp);
    if (found) {
        remove("account.dat");
        rename("temp.txt", "account.dat");
        printf("Account %d deleted.\n", acc_no);
    } else {
        remove("temp.txt");
        printf("Account %d not found.\n", acc_no);
    }
    return 0;
}