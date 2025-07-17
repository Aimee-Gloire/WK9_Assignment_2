#include <stdio.h>
#include <stdlib.h>

// Function to calculate tax based on salary range
float calculateTax(float *grossSalary) {
    if (*grossSalary <= 100) {
        return 0.0;
    } else if (*grossSalary > 100 && *grossSalary <= 300) {
        return (*grossSalary) * 0.20;
    } else {
        return (*grossSalary) * 0.28;
    }
}

// Function to calculate medical insurance (5% of gross salary)
float calculateMedicalInsurance(float *grossSalary) {
    return (*grossSalary) * 0.05;
}

// Function to calculate maternity leave (0.3% of gross salary)
float calculateMaternityLeave(float *grossSalary) {
    return (*grossSalary) * 0.003;
}

// Function to calculate social security fund (3% of gross salary)
float calculateSocialSecurityFund(float *grossSalary) {
    return (*grossSalary) * 0.03;
}

// Net salary calculator function that aggregates all deductions
float calculateNetSalary(float *grossSalary) {
    float tax = calculateTax(grossSalary);
    float medicalInsurance = calculateMedicalInsurance(grossSalary);
    float maternityLeave = calculateMaternityLeave(grossSalary);
    float socialSecurityFund = calculateSocialSecurityFund(grossSalary);
    
    float totalDeductions = tax + medicalInsurance + maternityLeave + socialSecurityFund;
    return (*grossSalary) - totalDeductions;
}

int main() {
    float grossSalary;
    
    printf("=== Net Salary Calculator ===\n");
    printf("Enter your gross salary (USD): ");
    scanf("%f", &grossSalary);
    
    // Calculate individual deductions for display
    float tax = calculateTax(&grossSalary);
    float medicalInsurance = calculateMedicalInsurance(&grossSalary);
    float maternityLeave = calculateMaternityLeave(&grossSalary);
    float socialSecurityFund = calculateSocialSecurityFund(&grossSalary);
    float netSalary = calculateNetSalary(&grossSalary);
    
    // Display breakdown
    printf("\n=== Salary Breakdown ===\n");
    printf("Gross Salary: $%.2f\n", grossSalary);
    printf("=====================================\n");
    printf("Tax: $%.2f\n", tax);
    printf("Medical Insurance (5%%): $%.2f\n", medicalInsurance);
    printf("Maternity Leave (0.3%%): $%.2f\n", maternityLeave);
    printf("Social Security Fund (3%%): $%.2f\n", socialSecurityFund);
    printf("\n");
    printf("Total Deductions: $%.2f\n", tax + medicalInsurance + maternityLeave + socialSecurityFund);
    printf("=====================================\n");
    printf("Net Salary: $%.2f\n", netSalary);
    
    return 0;
}