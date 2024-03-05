#include <stdio.h>
#include <string.h>

//
// Created by Wiktor Prokopiszyn on 05/03/2024.
//
typedef struct
{
    char name[128];
    char surname[128];
    char phone[20]; // +48 123 456 789
}Contact;

void addContact(Contact *contacts, int index)
{
    printf("Podaj imie: ");
    scanf("%s", contacts[index].name);
    printf("Podaj nazwisko: ");
    scanf("%s", contacts[index].surname);
    printf("Podaj telefon: ");
    scanf("%s", contacts[index].phone);
}

Contact* searchContact(Contact *contacts, char surname[], int size)
{
    for(int i = 0; i < size; i++) {
        if(strcmp(contacts[i].surname, surname) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}


void deleteContact(Contact *contacts, char surname[], int *size)
{
    int i = 0;

    while(i < *size)
    {
        if(strcmp(contacts[i].surname, surname) == 0)
        {
            for(int j = i; j < *size - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
        } else {
            i++;
        }
    }
}

void printContacts(Contact *contacts, int size)
{
    for(int i = 0; i < size; i++) {
        printf("Kontakt %d:\n"
               "Imie: %s\n"
               "Nazwisko: %s\n"
               "Telefon: %s\n", i + 1, contacts[i].name, contacts[i].surname, contacts[i].phone);
    }
}


int main()
{
    int size = 3;
    Contact contacts[100] = {{"Andrzej", "Kowalski", "+48 123 456 789"},
                             {"Kuba", "Nowak", "+48 123 456 789"},
                             {"Wiktor", "Prokopiszyn", "+48 123 456 789"}};

    printContacts(contacts, size);
    printf("\n---------------\n");

    addContact(contacts, size);
    size++;
    printf("\n---------------\n");
    printContacts(contacts, size);
    printf("\n---------------\n");

    deleteContact(contacts, "Kowalski", &size);
    printf("\n---------------\n");

    printContacts(contacts, size);

    return 0;
}
