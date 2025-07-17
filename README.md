# Net Salary Calculator, Sorting Names, and Memory Management

## Overview

This project contains three C programs that solve different problems related to salary calculations, sorting names, and dynamic memory management. The programs were first written on an **locally** before being pushed to **GitHub**.

## Team Members and Contributions

| Name                         | Contributions                                                                                      |
|-----------------------------|----------------------------------------------------------------------------------------------------|
| **Aimee Gloire Imaragahinda** | Question 1: Net Salary Calculator<br> Question 3: malloc, realloc, display functions              |
| **Angelo Verlain Shema**      | Question 2: Sorting Names<br> Question 3: calloc, memory cleanup, main function coordination     |

---

## Program Descriptions

### 1. Net Salary Calculator

**Filename:** `salary_calc.c`
**Contributor:** Aimee

This program calculates the **net salary** of an employee based on the **gross salary** and several deductions:

- **Tax on salary** (based on salary range)
- **Medical insurance** (5%)
- **Maternity leave** (0.3%)
- **Social security fund** (3%)

Each deduction is implemented as a **separate function** that uses **pointers** to manipulate the salary. The net salary is then printed to the user.

---

### 2. Sorting Names (Bubble Sort)

**Filename:** `sort.c`
**Contributor:** Angelo

This program sorts a **list of 20 names** and lets user choose either:

- **Ascending order (A-Z)**
- **Descending order (Z-A)**

and the names are sorted using **Bubble Sort** before being displayed. Uses **function pointers** to abstract the sorting behavior

---

### 3. Memory Management (Storing Student Emails)

**Filename:** `memory_manage.c`
**Contributor:** Angelo & Aimee

This program dynamically stores the **email addresses** of **10 students** in an array using **malloc()**/**calloc**. Then, it demonstrates **shrinking memory** by reducing the array to **6 students** using **realloc()**. Finally, the program frees all allocated memory to avoid memory leaks.

---
