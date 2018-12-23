

/* 
 * File:   field.h
 * Author: valentine
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

void obstacles(char **p_field, char ch);
void danger(char **p_field, int row, int col, char ch);

#endif /* FIELD_H */

