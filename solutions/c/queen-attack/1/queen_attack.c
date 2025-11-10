#include "queen_attack.h"
    #include <stdlib.h>
attack_status_t can_attack(position_t queen_1, position_t queen_2){
    attack_status_t result;
 // Invalid if posiitoin is  > 7?
 if( queen_1.column  > 7 || queen_1.row  > 7  || queen_2.column > 7  || queen_2.row  > 7) {
    result = INVALID_POSITION;
}
    
    
   
     // invalid position if same row and column
    else if(queen_1.row == queen_2.row && queen_1.column == queen_2.column){
        result = INVALID_POSITION;
    }


    // else can attack same row,column, what is a diag? diag
    else if(queen_1.row == queen_2.row || queen_1.column == queen_2.column || abs(queen_1.column - queen_2.column) / abs(queen_1.row - queen_2.row) == 1 ){
        result = CAN_ATTACK;
    } //Cannot attack !row, ! column, row is not +- 1, column is not +-1
    else{
        result = CAN_NOT_ATTACK;
    }

   
    
    return result;
}