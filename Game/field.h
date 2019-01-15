

/* 
 * File:   field.h
 * Author: valentyn
 *
 * Created on 23 декабря 2018 г., 17:00
 */

#ifndef FIELD_H
#define FIELD_H

#include "iostream"
using namespace std;

void show_field(char **p_field, int rows, int cols);
void del_field(char **p_field, int rows);
void init(char **p_field, int rows, int cols);
char **creat_field(int rows, int cols);

void obstacles(char **p_field, char ch, int numRow, int numCol);
void obstacles_horiz(char **p_field, int row_num, int col_num, int dist_rt, char ch);
void obstacles_vert(char **p_field, int row_num, int col_num, int dist_dn, char ch);
void menu();

bool checkPath_up(char **p_field, int row_num, int col_num, int dist_up, int dist_rt, char ch);
bool checkPath_dn(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch);
bool checkPath_rt(char **p_field, int row_num, int col_num, int dist_up, int dist_rt, char ch);
bool checkPath_lt(char **p_field, int row_num, int col_num, int dist_up, int dist_lt, char ch);

void test_checkPath_up(char **p_field, int row_num, int col_num, int dist_up, int dist_rt, char ch);
void test_checkPath_rt(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch);
void test_checkPath_lt(char **p_field, int row_num, int col_num, int dist_dn, int dist_lt, char ch);
void test_checkPath_dn(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch);

#endif /* FIELD_H */

