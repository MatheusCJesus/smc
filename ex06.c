
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char givenName[15];
    char familyName[15];
    char birthDate[15];
    char jobTitle[15];
    float salary;

} Employee;

void paymentRaise(Employee *emp, float raise);
void showInfo(Employee emp);
void addEmployee();


int main(int argc, char const *argv[])
{
    int i = 1;
    int count = 0;
    char addMore;
    Employee emp[100];

    for(;;)
    {
        addEmployee(emp, count);

        printf("Antes do aumento: \n");
        showInfo(emp[count]);

        printf("Depois do aumento: \n");
        paymentRaise(&emp[count], 1.1);
        showInfo(emp[count]);

        printf("Adicionar outro Employee? (y/n)\t");
        scanf("%c", &addMore);

        if (addMore == 'n')
        {
            break;
        }
        count++;
    }    
    
    return 0;
}

void paymentRaise(Employee *emp, float raise) {
    emp->salary *= raise;
}

void showInfo(Employee emp) {

    printf("Nome completo: %s %s\n", emp.givenName, emp.familyName);
    printf("Ano de nascimento: %s\n", emp.birthDate);
    printf("Cargo: %s\n", emp.jobTitle);
    printf("Salário mensal: %0.2f\n", emp.salary);
}
void addEmployee(Employee *ptr_emp, int pos) {

    printf("\nSalário mensal: ");
    scanf("%f", &(ptr_emp + pos)->salary);
    getchar();

    printf("\nNome: ");
    // fgets((ptr_emp + pos)->givenName, 15, stdin);
    scanf("%14[^\n]", (ptr_emp + pos)->givenName);
    getchar();

    printf("\nSobrenome: ");
    // fgets((ptr_emp + pos)->familyName, 15, stdin);
    scanf("%14[^\n]", (ptr_emp + pos)->familyName);
    getchar();

    printf("\nAno de nascimento: ");
    scanf("%14[^\n]", (ptr_emp + pos)->birthDate);
    getchar();

    printf("\nCargo: ");
    scanf("%14[^\n]", (ptr_emp + pos)->jobTitle);
    getchar();
  
}
