#include "matching_brackets.h"
#include "stdlib.h"
#include <stdio.h>
enum BracketType{
    PAREN = '(',
    PAREN_C = ')',
    
    SQUARE = '[',
    SQUARE_C = ']',
    
    CURLY = '{',
    CURLY_C = '}',
    
    ANGLE = '<',
    ANGLE_C = '>',
    
};

       
Stack* create_stack(){
   Stack* s = malloc(sizeof(Stack));
    s->top = 0;
    s->bottom = 20;
    return s;
}

void push(Stack* s, char c){
    if(s->top > s->bottom){
        printf("overflow");
    }
    s->top++;
    s->array[s->top] = c;
}

void pop(Stack* s){
    if(s->top == 0){
        printf("Empty stack cannot pop");
    } else{
          s->top--;  
    }

}
bool is_paired(const char *input){
  // We need to check that it's an open bracket and a closing bracket
   
    Stack* mystack = create_stack();
    bool result = false;
// Push all opening brackets to the stack
    for(int i = 0; input[i] != '\0';i++){
        switch(input[i]){
            case PAREN:
                push(mystack,input[i]);
                break;
            case SQUARE:
                push(mystack,input[i]);
                break;
            case CURLY:
                push(mystack,input[i]);
                break;
            case ANGLE:
                push(mystack,input[i]);
                break;
            // If stack [top] char == input[i] pop stack
                case PAREN_C:
                if(mystack->array[mystack->top] == PAREN){
                  pop(mystack);
                    break;
                }
                push(mystack,input[i]);
                break;
            case SQUARE_C:
                if(mystack->array[mystack->top] == SQUARE){
                  pop(mystack);
                    break;
                }
                push(mystack,input[i]);
                break;
             case CURLY_C:
                if(mystack->array[mystack->top] == CURLY){
                  pop(mystack);
                    break;
                }
                push(mystack,input[i]);
                break;
            case ANGLE_C:
                if(mystack->array[mystack->top] == ANGLE){
                  pop(mystack);
                    break;
                }
                push(mystack,input[i]);
                break;
        }
    }

   




    
    // If stack is not empty, return false
    if(mystack->top > 0){
       return result;
    }
// char* c = mystack->array;
//    for(int i = 0; c[i] != '\0'; i++){
//     printf("%c",c[i]);
//    }
    result = true;
    return result; 
    
   
}