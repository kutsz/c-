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

void move_Rt(int& step_rt_lt, int step_lth);
void move_Lt(int& step_rt_lt, int step_lth);
void move_Up(int& step_up_dn, int step_lth);
void move_Dn(int& step_up_dn, int step_lth);

void jump_Up(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_up, int dist_rt, char ch);
void jump_Dn(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_dn, int dist_rt, char ch);
void jump_Dn1(char **p_field, int& step_up_dn, int& step_rt_lt, int step_lth, int dist_dn, int dist_rt, char ch);
void jump_Up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_up, int dist_dn, int dist_rt, char ch);
void jump_Up_Bc(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_up, int dist_dn, int dist_rt, int dist_lt, char ch);
void jump_Dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_dn, int dist_rt, char ch);
void jump_Dn_Fd(char **p_field, int& step_up_dn, int& step_rt_lt, int step_lth, int dist_dn, int dist_rt, char ch);
void jump_Dn_Bc(char **p_field, int& step_up_dn, int& step_rt_lt, int step_lth, int dist_dn, int dist_rt, int dist_lt, char ch);

int move_rt(int j, int cols, int lim_rt, int step);
int move_lt(int j, int num, int step);
int move_up(int i, int lim_up);
int move_dn(int i, int rows, int lim_dn);

void move_up(char **p_field, int& row_num, int& col_num, int dist_up, int dist_rt, char ch);
void move_lt(char **p_field, int& row_num, int& col_num, int dist_dn, int dist_lt, char ch, int step);
void move_rt(char **p_field, int& row_num, int& col_num, int dist_dn, int dist_rt, char ch, int step);

void jump_up(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht, int lim_up);
void jump_dn(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht, int lim);
void jump_up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int ht, int lim_rt);
void jump_dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int rows, int ht);


#endif /* MOVEMENT_H */

