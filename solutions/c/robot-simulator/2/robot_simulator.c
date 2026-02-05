#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t robot = {
     .direction = direction,
    .position = {.x = x, .y=y}
    };
        return robot;
}
void robot_move(robot_status_t *robot, const char *commands){
    static int incx[] = {0,1,0,-1};
    static int incy[] = {1,0,-1,0};
    while(*commands != '\0'){
        switch (*commands) {
                case'R':
                robot->direction = (robot->direction+1)%4;
                break;
               
            case 'L':
                robot->direction = (robot->direction-1)%4;
                break;
            case 'A':
                 robot->position.x += incx[robot->direction];
                robot->position.y += incy[robot->direction];
                break;
        }
        commands++;
    }
}