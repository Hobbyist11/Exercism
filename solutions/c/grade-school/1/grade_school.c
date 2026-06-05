#include "grade_school.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>


void init_roster(roster_t* actual){
    for(size_t i = 0; i < MAX_STUDENTS; i++){
        actual->students[i] = (student_t){ 255, "" }; 
    }
   actual->count = 0;
   
}

bool add_student(roster_t *actual, const char *name, int grade)
{

    if (actual->count > 0)
    {
        for (size_t i = 0; i < actual->count; i++)
        {
            // Loop through our students see if the name already exists.
            if (strcmp(actual->students[i].name, name) == 0)
            {
                return false;
                // Loop through students, compare grade then name then switch places
            }
            else if (actual->students[i].grade > grade)
            {

                // actual->students[i].grade = grade;
                // strncpy(actual->students[i].name, name, sizeof(actual->students[i].name) - 1);
                // actual->students[i].name[sizeof(actual->students[i].name) - 1] = '\0';

                // actual->students[actual->count] = temp;

                // Shift elements down by the size of the elements being moved
                memmove(&actual->students[i + 1], &actual->students[i], (actual->count - i) * sizeof(student_t));
                strncpy(actual->students[i].name, name, sizeof(actual->students[i].name) - 1);
                actual->students[i].name[sizeof(actual->students[i].name) - 1] = '\0';
                actual->students[i].grade = grade;

                actual->count++;
                // break;
                return true;
            }
            else if (actual->students[i].grade == grade && strcmp(name, actual->students[i].name) < 0)
            {
                memmove(&actual->students[i + 1], &actual->students[i], (actual->count - i) * sizeof(student_t));
                strncpy(actual->students[i].name, name, sizeof(actual->students[i].name) - 1);
                actual->students[i].name[sizeof(actual->students[i].name) - 1] = '\0';
                actual->students[i].grade = grade;

                actual->count++;
                return true;
            }
        }
        actual->students[actual->count].grade = grade;
        strncat(actual->students[actual->count].name, name, strlen(name));
        actual->count++;
        return true;
    }

    else
    {
        actual->students[actual->count].grade = grade;
        strncat(actual->students[actual->count].name, name, strlen(name));
        actual->count++;
        return true;
    }
}


roster_t get_grade(roster_t *roster, int desired_grade){  
     roster_t result = {0,{(student_t){255,""}}};
   for(size_t i = 0; i < roster->count;i++){
       if(roster->students[i].grade == desired_grade){
            result.students[result.count] = roster->students[i];
            result.count++;
       }
   }
   
return result;
}