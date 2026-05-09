#include "kindergarten_garden.h"
#include <stdio.h>
#include<string.h>
plants_t plants(const char *diagram, const char *student)
{
    plants_t result = {.plants = {0, 0, 0, 0}};
    char student_list[12][8] = {"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};

    int col_num = 0;
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(student, student_list[i]) == 0)
        {
            col_num = i;
        }
    }

    const char *newline_ptr = strchr(diagram, '\n');
    if (!newline_ptr)
        return result; // Invalid diagram format

    int row_length = newline_ptr - diagram;
    int row2_start = row_length + 1;

    int index_in_row = col_num * 2;

    // char plant1 = diagram[index_in_row];
    // char plant2 = diagram[index_in_row + 1];
    // char plant3 = diagram[row2_start + index_in_row];
    // char plant4 = diagram[row2_start + index_in_row + 1];
    char plant_list[] = {'A', 'A', 'A', 'A'};
    plant_list[0] = diagram[index_in_row];
    plant_list[1] = diagram[index_in_row + 1];
    plant_list[2] = diagram[row2_start + index_in_row];
    plant_list[3] = diagram[row2_start + index_in_row + 1];

    // Convert the Char to the correct int
    for(int i = 0; i < 4; i++)
    {
        switch (plant_list[i])
        {
        case 'C':
            result.plants[i] = 0;
            break;
        case 'G':
            result.plants[i] = 1;
            break;
        case 'R':
            result.plants[i] = 2;
            break;
        case 'V':
            result.plants[i] = 3;
            break;
        default:
            result.plants[i] = -1; // Invalid plant
            break;
        }
    }

    return result;
}