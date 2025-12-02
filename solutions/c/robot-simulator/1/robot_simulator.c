#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    // return robot_status_t robot = {
    //     direction,
    //     {x,y}
    // }
    robot_status_t robot;
    robot.direction = direction;
    robot.position.x = x;
    robot.position.y = y;
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands){
    while(*commands != '\0'){
        switch(*commands){
            // Case A must move in the that direction.
        case 'A':
            // Add more cases for the numbers?
            switch(robot->direction){
                case DIRECTION_NORTH:
                    robot->position.y = robot->position.y+1;
                    break;
                case DIRECTION_EAST:
                    robot->position.x = robot->position.x+1;
                    break; 
                case DIRECTION_SOUTH:
                    robot->position.y = robot->position.y-1;
                    break;
                case DIRECTION_WEST:
                    robot->position.x = robot->position.x-1;
                    break; 
                case DIRECTION_MAX:
                    robot->position.x =0;
                    robot->position.y = 0;
            }
            break;
        case 'R':
            robot->direction = robot->direction+1;
            // Can we use the max direction enum?
            if(robot->direction > 3 ){
                robot->direction = 0;
            }
            break;
        case 'L':
            if(robot->direction == 0){
                robot->direction = DIRECTION_WEST;
            } else{
               robot->direction = robot->direction-1; 
            }
            
            break;
    }
        commands++;
    }
    
}