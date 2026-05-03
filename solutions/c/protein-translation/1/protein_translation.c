#include "protein_translation.h"
#include <stdio.h>
#include <string.h>
protein_t protein(const char *const rna) {
  char codons[17][4] = {"AUG", "UUU", "UUC", "UUA", "UUG", "UCU",
                        "UCC", "UCA", "UCG", "UAU", "UAC", "UGU",
                        "UGC", "UGG", "UAA", "UAG", "UGA"};
  protein_t result = {.valid = true, .count = 0};
  char c[4] = {0};
    bool isvalid = false;

  // Iterate by 3s over the rna
  for (size_t i = 0; i < strlen(rna); i += 3) {
    memcpy(c, &rna[i], 3);
    c[3] = '\0';
 isvalid = false;

    // Iterate over the list of valid RNAs and check
    for (int j = 0; j < 17; j++) {
      // STOP
      
      bool same = strcmp(c, codons[j]);
      if (same == 0) {
        isvalid = true;
        if (j >= 14)
        return result;
        switch (j) {
        case 0:
          result.amino_acids[result.count] = Methionine;
          break;
        case 1:
        case 2:
          result.amino_acids[result.count] = Phenylalanine;
          break;
        case 3:
        case 4:
          result.amino_acids[result.count] = Leucine;
          break;
        case 5:
        case 6:
        case 7:
        case 8:
          result.amino_acids[result.count] = Serine;
          break;
        case 9:
        case 10:
          result.amino_acids[result.count] = Tyrosine;
          break;
        case 11:
        case 12:
          result.amino_acids[result.count] = Cysteine;
          break;
        case 13:
          result.amino_acids[result.count] = Tryptophan;
          break;
        // case 14:
        // case 15:
        // case 16:
        //      result.amino_acids[i] = STOP;
        //     break;
        }
        result.count++;
        break;
      }
    }
      if(isvalid == false){
          result.valid = false;
          return result;
      }
 
  }
  return result;
}

