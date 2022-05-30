
#include <stdio.h>

typedef struct Employee
{
    char *givenName;
    char *familyName;
    char *birthDate;
    char *jobTitle;
    float salary;

} Employee;

void paymentRaise(Employee *emp, float raise);
void showInfo(Employee emp);
Employee addEmployee();


int main(int argc, char const *argv[])
{
    int i = 1;
    int count = 0;
    char addMore;
    Employee emp[100];
    Employee *ptr_emp = emp;
    while (i == 1)
    {
        emp[count] = addEmployee();

        printf("Antes do aumento: \n");
        showInfo(emp[count]);

        printf("Depois do aumento: \n");
        paymentRaise(ptr_emp, 1.1);
        showInfo(emp[count]);

        printf("Adicionar outro Employee? (y/n)\t");
        scanf("%c", &addMore);
        fflush(stdin); // Limpa o buffer do teclado

        if (addMore == 'n')
        {
            continue;
        }
        count++;
    }    
    
    return 0;
}

void paymentRaise(Employee *emp, float raise) {
    emp->salary *= raise;
}

void showInfo(Employee emp) {

    Employee *ptr_emp = &emp;

    printf("Nome completo: %s %s\n", *ptr_emp->givenName, *ptr_emp->familyName);
    printf("Ano de nascimento: %s\n", *ptr_emp->birthDate);
    printf("Cargo: %s\n", *ptr_emp->jobTitle);
    printf("Salário mensal: %0.2f\n", ptr_emp->salary);
}

Employee addEmployee() {

    char givenName[15] = "\0";
    char familyName[15];
    char birthDate[10];
    char jobTitle[15];
    float salary = 0.0;

    printf("Nome: ");
    fgets(givenName, 15, stdin);
    fflush(stdin);
    printf("\nSobrenome: ");
    fgets(familyName, 15, stdin);
    fflush(stdin);
    printf("\nAno de nascimento: ");
    fgets(birthDate, 10, stdin);
    fflush(stdin);
    printf("\nCargo: ");
    fgets(jobTitle, 15, stdin);
    fflush(stdin);
    printf("\nSalário mensal: ");
    scanf("%f", &salary);
    fflush(stdin);

    Employee emp;

    emp.givenName = givenName;
    emp.familyName = familyName;
    emp.birthDate = birthDate;
    emp.jobTitle = jobTitle;
    emp.salary = salary;

    return emp;
    
}
