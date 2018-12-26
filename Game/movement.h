/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   movement.h
 * Author: valentine
 *
 * Created on 25 декабря 2018 г., 9:27
 */

#ifndef MOVEMENT_H
#define MOVEMENT_H

//int move_rt(int j, int cols);
int move_rt(int j, int cols, int lim_rt, int step);
//int move_lt(int j, int num);
int move_lt(int j, int num, int step);
int move_up(int i, int lim_up);
int move_dn(int i, int rows, int lim_dn);

void jump_up(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht, int lim_up);
void jump_dn(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht, int lim);
void jump_up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int ht, int lim_rt);
void jump_dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int rows, int ht);


#endif /* MOVEMENT_H */

