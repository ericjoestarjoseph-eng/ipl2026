#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure definition
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Function declarations
void writeRecords(Student s[], int n, const char *filename);
int createSeekPositions(long pos[], const char *filename);
void displayRecordAtPosition(const char *filename, long position);

int main() {

    Student s[MAX];
    long positions[MAX];

    int n, i, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input records
    for(i = 0; i < n; i++) {

        printf("\nStudent %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Write to ASCII file
    writeRecords(s, n, "students.txt");

    // Create seek position array
    int total = createSeekPositions(positions, "students.txt");

    printf("\nRecord Positions:\n");

    for(i = 0; i < total; i++) {
        printf("Record %d starts at byte position %ld\n",
               i + 1, positions[i]);
    }

    // Display any record using seek position
    printf("\nEnter record number to display: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= total) {
        displayRecordAtPosition("students.txt",
                                positions[choice - 1]);
    }
    else {
        printf("Invalid record number\n");
    }

    return 0;
}

// Function to write structures in ASCII format
void writeRecords(Student s[], int n, const char *filename) {

    FILE *fp;

    fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    for(int i = 0; i < n; i++) {

        fprintf(fp, "%d %s %.2f\n",
                s[i].id,
                s[i].name,
                s[i].marks);
    }

    fclose(fp);

    printf("\nRecords written successfully\n");
}

// Function to store beginning positions of each record
int createSeekPositions(long pos[], const char *filename) {

    FILE *fp;

    char ch;

    int count = 0;

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Cannot open file\n");
        return 0;
    }

    // First record starts at 0
    pos[count++] = 0;

    while((ch = fgetc(fp)) != EOF) {

        if(ch == '\n') {

            long nextPos = ftell(fp);

            // Avoid storing EOF position
            if(fgetc(fp) != EOF) {
                pos[count++] = nextPos;
            }

            fseek(fp, nextPos, SEEK_SET);
        }
    }

    fclose(fp);

    return count;
}

// Display record using seek position
void displayRecordAtPosition(const char *filename,long position) {

    FILE *fp;

    int id;
    char name[50];
    float marks;

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Cannot open file\n");
        return;
    }

    // Move to desired position
    fseek(fp, position, SEEK_SET);

    // Read record
    fscanf(fp, "%d %s %f",
           &id,
           name,
           &marks);

    printf("\n===== RECORD =====\n");

    printf("ID     : %d\n", id);
    printf("Name   : %s\n", name);
    printf("Marks  : %.2f\n", marks);

    fclose(fp);
}