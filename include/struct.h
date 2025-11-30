#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int acc_no;
    char name[50];
    char type;       // 'S' or 'C'
    double balance;
} Account;

#endif