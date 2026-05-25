#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50];
    float salary;
} Employee;

void storeRecords(char filename[], int n);
void displayMthRecord(char filename[], int m);
void deleteRecord(char filename[], int delId);

int main()
{
    int n, m, delId;

    printf("Enter number of records: ");
    scanf("%d", &n);

    storeRecords("employee.dat", n);

    printf("\nEnter record number to display: ");
    scanf("%d", &m);

    displayMthRecord("employee.dat", m);

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &delId);

    deleteRecord("employee.dat", delId);

    return 0;
}

void storeRecords(char filename[], int n)
{
    FILE *fp;
    Employee e;

    fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Employee %d details\n", i + 1);

        printf("ID: ");
        scanf("%d", &e.id);

        printf("Name: ");
        scanf("%s", e.name);

        printf("Salary: ");
        scanf("%f", &e.salary);

        fwrite(&e, sizeof(Employee), 1, fp);
    }

    fclose(fp);
}

void displayMthRecord(char filename[], int m)
{
    FILE *fp;
    Employee e;

    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    fseek(fp, (m - 1) * sizeof(Employee), SEEK_SET);

    if (fread(&e, sizeof(Employee), 1, fp))
    {
        printf("\nEmployee Record %d\n", m);
        printf("ID: %d\n", e.id);
        printf("Name: %s\n", e.name);
        printf("Salary: %.2f\n", e.salary);
    }
    else
    {
        printf("Record not found\n");
    }

    fclose(fp);
}

void deleteRecord(char filename[], int delId)
{
    FILE *fp, *temp;
    Employee e;
    int found = 0;

    fp = fopen(filename, "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File error\n");
        return;
    }

    while (fread(&e, sizeof(Employee), 1, fp))
    {
        if (e.id != delId)
        {
            fwrite(&e, sizeof(Employee), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.dat", filename);

    if (found)
        printf("Record deleted successfully\n");
    else
        printf("Record not found\n");
}
