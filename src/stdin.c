#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../include/stdin.h"
#include"../include/struct.h"
#include "../include/config.h"


void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}