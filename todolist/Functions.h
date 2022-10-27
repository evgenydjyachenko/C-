#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <ctime>
#define INCORRECT_INPUT "Некорректный ввод, попробуйте еще раз..."
#define INCORRECT_CASE "Такой команды нет, попробуйте еще раз..."
#define NOT_FOUND "Ничего не найдено, попробуйте еще раз..."

using namespace std;

struct Dela
{
    char name[35];
    int priority;
    char description[255];
    int min;
    int hour;
    int mday;
    int mon;
    int week;
};

bool check_date(Dela p);
bool check_time(Dela p);
int week(Dela t);
void start(Dela* p, int k);
void menu(Dela* dela, int k);
void print2();
void print(Dela p);
void print_all(Dela* dela, int k);
void add_delo(Dela* (&p), int& k);
void copy(Dela* (&p_new), Dela* (&p), int k);
void copy_Dela(Dela& p_new, Dela& p);
int list_number(int k);
void del_delo(Dela* (&p), int& k);
void edit(Dela* p, int k);
void search(Dela* p, int k);
int sum(Dela& p, int k);
void sort(Dela* p, int k);
void sort2(Dela* p, int k);
void select_date(Dela* p, int k, int n2);
void list_del(Dela* (&p), int& k);
