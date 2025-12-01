#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len-1];
}


int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t max = 0;
    for (size_t i = 0; i < scores_len; i++){
        if(scores[i] > max){
            max = scores[i];
        }
    }
    return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,int32_t *output){
size_t size = 0;
// int offset = 0;
//     for(int i = 0; i < 3;i++){
//         if (i >0){
//             offset = 1;
//         }
//             for(size_t j = 0; j < scores_len-1;j++){
//                if(scores[j] > output[i]){
//                    output[i] = scores[j];
//                } 
//             }
//         if(size < scores_len && size < 3){
//             size++;
//         }
//     }
//     return size;
    // Figure out the size first
    if(scores_len < 3){
        size = scores_len;
    } else {
        size = 3;
    }

    // Initialize the values for the top 3 array
    for(size_t i = 0; i < size; i++){
        output[i] = 0;
    }

    // One pass the array, comparing the values to the first second and third value
    for(size_t i = 0; i < scores_len; i++){
        if(scores[i] > output[0]){
            output[2] = output[1];
            // Set the second element to current.
            output[1] = output[0];
            // Set the higgher element as first
            output[0] = scores[i];
        } else if (scores[i] > output[1]){
            output[2] = output[1];
            output[1] = scores[i];
        } else if(scores[i] > output[2]){
            output[2] = scores[i];
        }
    }
    return size;
}