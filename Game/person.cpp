#include "person.h"

/*
    (#)
   #####
  # ### #   
  #  #  #
    ###
   #   #
   #   #
  ##   ##
 
 
 */
void person(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2)
{
    //head
    p_field[row_num][col_num + 2] = ch;
    p_field[row_num][col_num + 3] = ch2;
    p_field[row_num][col_num + 4] = ch1;
    //body
    p_field[row_num + 1][col_num + 1] = ch2;
    p_field[row_num + 1][col_num + 2] = ch2;
    p_field[row_num + 1][col_num + 3] = ch2;
    p_field[row_num + 1][col_num + 4] = ch2;
    p_field[row_num + 1][col_num + 5] = ch2;
    //body1
    p_field[row_num + 2][col_num] = ch2;
    p_field[row_num + 2][col_num + 2] = ch2;
    p_field[row_num + 2][col_num + 3] = ch2;
    p_field[row_num + 2][col_num + 4] = ch2;
    p_field[row_num + 2][col_num + 6] = ch2;
    //body2
    p_field[row_num + 3][col_num] = ch2;
    p_field[row_num + 3][col_num + 3] = ch2;
    p_field[row_num + 3][col_num + 6] = ch2;
    // legs
    p_field[row_num + 4][col_num + 2] = ch2;
    p_field[row_num + 4][col_num + 3] = ch2;
    p_field[row_num + 4][col_num + 4] = ch2;

    p_field[row_num + 5][col_num + 1] = ch2;
    p_field[row_num + 5][col_num + 5] = ch2;

    p_field[row_num + 6][col_num + 1] = ch2;
    p_field[row_num + 6][col_num + 5] = ch2;

    p_field[row_num + 7][col_num] = ch2;
    p_field[row_num + 7][col_num + 1] = ch2;
    p_field[row_num + 7][col_num + 5] = ch2;
    p_field[row_num + 7][col_num + 6] = ch2;


}

/*
          
    (#)
   ##### #
  # ### #   
   # # 
    # ###
    #  #
    #  ##
    ##  
 
 */
void person_rt(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2)
{
    p_field[row_num][col_num + 2] = ch;
    p_field[row_num][col_num + 3] = ch2;
    p_field[row_num][col_num + 4] = ch1;

    p_field[row_num + 1][col_num + 1] = ch2;
    p_field[row_num + 1][col_num + 2] = ch2;
    p_field[row_num + 1][col_num + 3] = ch2;
    p_field[row_num + 1][col_num + 4] = ch2;
    p_field[row_num + 1][col_num + 5] = ch2;
    p_field[row_num + 1][col_num + 7] = ch2;

    p_field[row_num + 2][col_num] = ch2;
    p_field[row_num + 2][col_num + 2] = ch2;
    p_field[row_num + 2][col_num + 3] = ch2;
    p_field[row_num + 2][col_num + 4] = ch2;
    p_field[row_num + 2][col_num + 6] = ch2;

    p_field[row_num + 3][col_num + 1] = ch2;
    p_field[row_num + 3][col_num + 3] = ch2;


    p_field[row_num + 4][col_num + 2] = ch2;
    p_field[row_num + 4][col_num + 4] = ch2;
    p_field[row_num + 4][col_num + 5] = ch2;
    p_field[row_num + 4][col_num + 6] = ch2;

    p_field[row_num + 5][col_num + 2] = ch2;
    p_field[row_num + 5][col_num + 5] = ch2;

    p_field[row_num + 6][col_num + 2] = ch2;
    p_field[row_num + 6][col_num + 5] = ch2;
    p_field[row_num + 6][col_num + 6] = ch2;

    p_field[row_num + 7][col_num + 2] = ch2;
    p_field[row_num + 7][col_num + 3] = ch2;



}

/*
          
    (#)
 # ##### 
  # ### #   
     # #
  ### #
   #  #
  ##  #
     ##
 
 */

void person_lt(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2)
{
    p_field[row_num][col_num + 2] = ch;
    p_field[row_num][col_num + 3] = ch2;
    p_field[row_num][col_num + 4] = ch1;

    p_field[row_num + 1][col_num - 1] = ch2;
    p_field[row_num + 1][col_num + 1] = ch2;
    p_field[row_num + 1][col_num + 2] = ch2;
    p_field[row_num + 1][col_num + 3] = ch2;
    p_field[row_num + 1][col_num + 4] = ch2;
    p_field[row_num + 1][col_num + 5] = ch2;
    

    p_field[row_num + 2][col_num] = ch2;
    p_field[row_num + 2][col_num + 2] = ch2;
    p_field[row_num + 2][col_num + 3] = ch2;
    p_field[row_num + 2][col_num + 4] = ch2;
    p_field[row_num + 2][col_num + 6] = ch2;

    p_field[row_num + 3][col_num + 3] = ch2;
    p_field[row_num + 3][col_num + 5] = ch2;


    p_field[row_num + 4][col_num ] = ch2;
    p_field[row_num + 4][col_num + 1] = ch2;
    p_field[row_num + 4][col_num + 2] = ch2;
    p_field[row_num + 4][col_num + 4] = ch2;

    p_field[row_num + 5][col_num + 1] = ch2;
    p_field[row_num + 5][col_num + 4] = ch2;

    p_field[row_num + 6][col_num] = ch2;
    p_field[row_num + 6][col_num + 1] = ch2;
    p_field[row_num + 6][col_num + 4] = ch2;

    p_field[row_num + 7][col_num + 3] = ch2;
    p_field[row_num + 7][col_num + 4] = ch2;



}



