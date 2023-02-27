#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int valtype;
typedef int priotype;

typedef struct prioqueue{
valtype value;
priotype priority;
struct prioqueue* next;
} prioqueue;    // mano structas, kurio duomenys yra pats skaicius ir prioritetas to skaiciaus. Tada next rodo i kita nari eileje. Structas yra pavadintas prioqueue

typedef struct node{
prioqueue* head;
struct node* next;
} Node;

Node* Create(void); //Sukuria tuscia eile // Jie grazina NULL tai neuztenka atminties

int IsEmpty(Node* list); //Patikrina ar eile tuscia(tai yra ar yra elemetu joje yra(jei yra tiesiog sukurta eile, tai reiskia, kad eile yra dar tuscia)).Jei eile tuscia grazina 1, o jei ne 0.

void* Insert(Node* list, priotype prio, valtype val); //Ideda elementa i eile pagal prioriteta. Pirma bus isimami elementai su tuo auksciausiu prioritetu.
// jei graazina NULL tai neuztenka atminteis

valtype Remove(Node* list); //Grazina eiles elemento value. Ir kartu istrina ta prioqueue is eiles.

void Join(Node* list1, Node** list2);//Sujungia dvi prioritetines eiles i viena. Tai yra prie pirmos eiles yra prijungiama antra eile. Antra eile yra sunaikinama.

void Destroy(Node** list); //Sunaikinama eile.

prioqueue GetData(Node* list);//Gaunami virsunes duomenys nesunaikinus jos

void print(Node* list);//Atprintina visus eiles narius nuo didziausio prioriteto iki maziausio.
#endif
