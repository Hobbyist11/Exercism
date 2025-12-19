#include "high_scores.h"
int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len-1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t highest_score = 0;
    for (size_t i = 0; i < scores_len;i++){
        if (scores[i]>highest_score)
            highest_score = scores[i];
    }
    return highest_score;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,int32_t *output){
    size_t size = 0;
    if(scores_len < 3){
     size = scores_len;
    } else{
        size = 3;
    }
     // init size for top 3 array
    for (size_t i = 0; i < size; i++){
        output[i] = 0;
    }
    for(size_t i = 0; i < scores_len; i++){
        if(scores[i]>output[0]){
            output[2] = output[1];
            output[1] = output[0];
            output[0] = scores[i];
        } else if (scores[i]>output[1]){
            output[1] = scores[i];
        } else if(scores[i]>output[2]){
            output[2]  = scores[i];
        }
    }
    // for(size_t i = 0; i < 3 && i < scores_len; i++){
    //     output[i] = tops[i];
    // }
    
    return size;
}