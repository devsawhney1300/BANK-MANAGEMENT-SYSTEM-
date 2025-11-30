#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../include/accountexist.h"
#include"../include/struct.h"
#include "../include/config.h"

int account_exists(int acc_no) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 0;
    Account a;
    while (fread(&a, sizeof(Account), 1, fp) == 1) {
        if (a.acc_no == acc_no) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}