#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../include/modifyaccount.h"
#include"../include/accountexist.h"
#include"../include/stdin.h"
#include"../include/struct.h"
#include "../include/config.h"


void modify_account() {

    int acc_no;
    Account a;
    printf("\n--- Modify Account ---\nEnter Account Number: ");
    if (scanf("%d", &acc_no) != 1) { clear_stdin(); printf("Invalid input.\n"); return; }
    FILE *fp = fopen("account.dat", "rb+");
    if (fp == NULL) 
    { 
        printf("No records found.\n"); 
        return; 
    }
    
    int found = 0;
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.acc_no == acc_no) {
            found = 1;
            printf("Current Name: %s\n", a.name);
            clear_stdin();
            printf("Enter New Name (leave blank to keep): ");
            char newname[50];
            fgets(newname, sizeof(newname), stdin);
            if (newname[0] != '\n') 
            {
                strncpy(a.name, newname, sizeof(a.name));
                a.name[sizeof(a.name)] = '\0';
            }
            printf("Current Type: %c\n", a.type);
            printf("Enter New Type (S/C, or press Enter to keep): ");
            int ch = getchar();
            clear_stdin();
            if (ch == 'S' || ch == 'C' || ch == 's' || ch == 'c') {
                if (ch >= 'a')
                a.type = (char)ch;
            }
            printf("Current Balance: %.2f\n", a.balance);
            printf("Enter New Balance (or -1 to keep): ");
            double b;
            if (scanf("%lf", &b) == 1) 
            {
                if (b >= 0) a.balance = b;
            } else { 
                clear_stdin(); 
            }
            fseek(fp, -((long)sizeof(Account)), SEEK_CUR);
            fwrite(&a, sizeof(Account), 1, fp);
            printf("Account updated successfully.\n");
            break;
        }
    }
    if (!found) 
    printf("Account %d not found.\n", acc_no);
    fclose(fp);
}