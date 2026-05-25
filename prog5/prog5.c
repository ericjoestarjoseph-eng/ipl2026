#include <stdio.h>

// Define union with bitfields
union decision {

    struct field {
        unsigned int your_choice:1;
        unsigned int your_mothers_choice:1;
        unsigned int your_fathers_choice:1;
        unsigned int socially_acceptable:1;
        unsigned int financially_viable:1;
        unsigned int do_you_have_aptitude:1;
        unsigned int do_you_likeit:1;
        unsigned int decision:1;
    } bits;

    unsigned char flags;

};

// Function declarations
union decision input();
void make_decision(union decision *d);
void print_decision(union decision d);
void print_conclusion_based_on_flags(union decision d);

// Main function
int main() {

    union decision d;

    d = input();

    make_decision(&d);

    print_decision(d);

    print_conclusion_based_on_flags(d);

    return 0;
}

// Input function
union decision input() {

    union decision d;

    int temp;

    d.flags = 0; // clear all bits

    printf("Enter your choice (0/1): ");
    scanf("%d", &temp);
    d.bits.your_choice = temp;

    printf("Enter your mother's choice (0/1): ");
    scanf("%d", &temp);
    d.bits.your_mothers_choice = temp;

    printf("Enter your father's choice (0/1): ");
    scanf("%d", &temp);
    d.bits.your_fathers_choice = temp;

    printf("Is it socially acceptable? (0/1): ");
    scanf("%d", &temp);
    d.bits.socially_acceptable = temp;

    printf("Is it financially viable? (0/1): ");
    scanf("%d", &temp);
    d.bits.financially_viable = temp;

    printf("Do you have aptitude? (0/1): ");
    scanf("%d", &temp);
    d.bits.do_you_have_aptitude = temp;

    printf("Do you like it? (0/1): ");
    scanf("%d", &temp);
    d.bits.do_you_likeit = temp;

    return d;
}

// Decision making function
void make_decision(union decision *d) {

    d->bits.decision =
    (
        d->bits.do_you_likeit &&
        d->bits.do_you_have_aptitude &&
        d->bits.financially_viable &&
        (
            d->bits.your_choice ||
            d->bits.your_mothers_choice ||
            d->bits.your_fathers_choice
        )
    );
}

// Print detailed narrative
void print_decision(union decision d) {

    printf("\n===== DECISION REPORT =====\n");

    printf("Your choice            : %s\n",
           d.bits.your_choice ? "YES" : "NO");

    printf("Mother supports        : %s\n",
           d.bits.your_mothers_choice ? "YES" : "NO");

    printf("Father supports        : %s\n",
           d.bits.your_fathers_choice ? "YES" : "NO");

    printf("Socially acceptable    : %s\n",
           d.bits.socially_acceptable ? "YES" : "NO");

    printf("Financially viable     : %s\n",
           d.bits.financially_viable ? "YES" : "NO");

    printf("You have aptitude      : %s\n",
           d.bits.do_you_have_aptitude ? "YES" : "NO");

    printf("You like it            : %s\n",
           d.bits.do_you_likeit ? "YES" : "NO");

    printf("\nFINAL DECISION         : %s\n",
           d.bits.decision ? "GO FOR IT!" : "RECONSIDER");
}

// Use flags value creatively
void print_conclusion_based_on_flags(union decision d) {

    printf("\n===== FLAG ANALYSIS =====\n");

    printf("Flags value = %u\n", d.flags);

    if (d.flags == 255) {
        printf("Perfect alignment. Destiny agrees.\n");
    }
    else if (d.flags > 200) {
        printf("Strong positive indicators.\n");
    }
    else if (d.flags > 100) {
        printf("Mixed situation. Think carefully.\n");
    }
    else {
        printf("Too many risks involved.\n");
    }
}