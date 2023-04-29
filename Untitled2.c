#include <stdio.h>
#include <stdlib.h>
typedef struct {
    float income;
    float tax;
} IncomeTax;

// Input module function
int get_input(IncomeTax *it) {
    printf("Enter your income: ");
    if (scanf("%f", &(it->income)) != 1) {
        return 0;
    }
    return 1;
}

// Calculation module function
void calculate_tax(IncomeTax *it) {
    float income = it->income;
    float tax = 0.0;
    if (income <= 250000) {
        tax = 0.0;
    } else if (income <= 500000) {
        tax = 0.05 * (income - 250000);
    } else if (income <= 1000000) {
        tax = 0.05 * 250000 + 0.2 * (income - 500000);
    } else {
        tax = 0.05 * 250000 + 0.2 * 500000 + 0.3 * (income - 1000000);
    }
    it->tax = tax;
}

// Output module function
void display_output(IncomeTax *it) {
    printf("Income: %.2f\nTax: %.2f\n", it->income, it->tax);
}

// Error handling module function
void handle_error() {
    printf("Error: Invalid input!\n");
    exit(1);
}

// Data storage module function
void save_data(IncomeTax *it) {
    FILE *fp = fopen("tax_records.txt", "a");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }
    fprintf(fp, "Income: %.2f, Tax: %.2f\n", it->income, it->tax);
    fclose(fp);
}

// Main function
int main() {
    IncomeTax it;
    if (!get_input(&it)) {
        handle_error();
    }
    calculate_tax(&it);
    display_output(&it);
    save_data(&it);
    return 0;
}
