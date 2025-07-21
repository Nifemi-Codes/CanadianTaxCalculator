// Canadian Tax Calculator
/* This program calculates the estimated federal and Ontario provincial tax based on 
user input for taxable income, using 2024 tax rates. It does not account for deductions, 
credits, or other provinces. */

#include <stdio.h>

/*
 * Function: calculate_federal_tax
 * -------------------------------
 * Calculates Canadian federal tax for 2024.
 * income: User's taxable income
 * returns: Federal tax amount
 */
double calculate_federal_tax(double income) {
    double tax = 0.0;

    // 2024 Canadian Federal Tax Brackets
    if (income <= 55567)
        tax = income * 0.15;
    else if (income <= 111733)
        tax = 55567 * 0.15 + (income - 55567) * 0.205;
    else if (income <= 173205)
        tax = 55567 * 0.15 + (111733 - 55567) * 0.205 + (income - 111733) * 0.26;
    else if (income <= 246752)
        tax = 55567 * 0.15 + (111733 - 55567) * 0.205 + (173205 - 111733) * 0.26 + (income - 173205) * 0.29;
    else
        tax = 55567 * 0.15 + (111733 - 55567) * 0.205 + (173205 - 111733) * 0.26 +
              (246752 - 173205) * 0.29 + (income - 246752) * 0.33;

    return tax;
}

/*
 * Function: calculate_ontario_tax
 * -------------------------------
 * Calculates Ontario provincial tax for 2024.
 * income: User's taxable income
 * returns: Ontario provincial tax amount
 */
double calculate_ontario_tax(double income) {
    double tax = 0.0;

    // 2024 Ontario Provincial Tax Brackets
    if (income <= 50297)
        tax = income * 0.0505;
    else if (income <= 100392)
        tax = 50297 * 0.0505 + (income - 50297) * 0.0915;
    else if (income <= 150000)
        tax = 50297 * 0.0505 + (100392 - 50297) * 0.0915 + (income - 100392) * 0.1116;
    else if (income <= 220000)
        tax = 50297 * 0.0505 + (100392 - 50297) * 0.0915 + (150000 - 100392) * 0.1116 +
              (income - 150000) * 0.1216;
    else
        tax = 50297 * 0.0505 + (100392 - 50297) * 0.0915 + (150000 - 100392) * 0.1116 +
              (220000 - 150000) * 0.1216 + (income - 220000) * 0.1316;

    return tax;
}


 //Main Function
 
int main() {
    double income, federal_tax, provincial_tax, total_tax, net_income;

    // Welcome message and instructions
    printf("=== 2024 Canadian Tax Calculator (Federal + Ontario) ===\n");
    printf("Enter your taxable income (CAD): $");
    scanf("%lf", &income);

    // Calculate taxes
    federal_tax = calculate_federal_tax(income);
    provincial_tax = calculate_ontario_tax(income);
    total_tax = federal_tax + provincial_tax;
    net_income = income - total_tax;

    // Display results
    printf("\nTaxable Income: $%.2f\n", income);
    printf("Estimated Federal Tax: $%.2f\n", federal_tax);
    printf("Estimated Ontario Provincial Tax: $%.2f\n", provincial_tax);
    printf("Total Tax: $%.2f\n", total_tax);
    printf("Net Income after Tax: $%.2f\n", net_income);

    // Advise about limitations
    printf("\nNote: This is a simplified calculator for federal and Ontario taxes (2024 rates).\n");
    printf("It does not account for deductions, credits, or other provinces.\n");

    return 0;
}