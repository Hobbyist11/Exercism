#include "beer_song.h"
void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    int index = 0;
    for(uint8_t i = 0; i < take_down; i++){
        if(start_bottles < 1){
         sprintf(song[index++],"No more bottles of beer on the wall, no more bottles of beer.");
        sprintf(song[index++],"Go to the store and buy some more, 99 bottles of beer on the wall.");
        } else if (start_bottles == 1){
        sprintf(song[index++],"%d bottle of beer on the wall, %d bottle of beer.", start_bottles,                 start_bottles);
        } else {
        sprintf(song[index++],"%d bottles of beer on the wall, %d bottles of beer.", start_bottles,             start_bottles);
        }

        if(start_bottles > 0){
            start_bottles--;
                switch (start_bottles){
                  case 0:
                    sprintf(song[index++],"Take it down and pass it around, no more bottles of beer on the wall.");
                    break;
                        
                case 1:
                  sprintf(song[index++],"Take one down and pass it around, %d bottle of beer on the wall.",start_bottles);  
                    break;
                        
                default:
                   sprintf(song[index++],"Take one down and pass it around, %d bottles of beer on the wall.",start_bottles);
                    break;      
                }
 
        } 
        if(i < take_down-1){
            sprintf(song[index++],"%s","");
        }
        // continue;
    }
}
    
