//
//  main.c
//  Infix_Postfix
//
//  Created by João Condeço on 10/04/2021.
//

#include <stdio.h>
#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

int potencia(int x, int y){
    int score = 1;
    for(int i = 0; i<y; i++){
        score *= (x);
    }
    return score;
}


int calculus(char *s){
    
    struct StackRecord *S = CreateStack(100);
    
    int i = 0;
    int counter = 0;
    int adicionado = 0;
    
    int a, b;
    
    while(s[i]){
        if(s[i] == ((char)32)){
            for(int j = counter; j>0; j--){
                if(s[i-j] != '+'){
                    adicionado += (s[i - j] - '0') * potencia(10, j-1);
                }
            }
            if(adicionado != 0){
                Push(adicionado, S);
            }
            counter = 0;
            adicionado = 0;
        }
        else if (s[i] == '+'){
            a = Pop(S);
            b = Pop(S);
            printf("\na = %d, b = %d, a+b = %d\n", a, b, a+b);
            Push(b+a, S);
        }
        else if (s[i] == '-'){
            a = Pop(S);
            b = Pop(S);
            printf("\na = %d, b = %d, b-a = %d\n", a, b, b-a);
            Push(b-a, S);
        }
        else if (s[i] == '*'){
            a = Pop(S);
            b = Pop(S);
            printf("\na = %d, b = %d, b*a = %d\n", a, b, b*a);
            Push(b*a, S);
        }
        else if (s[i] == '/'){
            a = Pop(S);
            b = Pop(S);
            printf("\na = %d, b = %d, b/a = %d\n", a, b, b/a);
            Push(b/a, S);
        }
        else
            counter++;
        i++;
    }
    return Pop(S);
}

//void translation_one(char *t){
//    char *infix = malloc(100);
//
//}

int main(int argc, const char * argv[]) {
    
    char *t = malloc(100);
    
    printf("Hello There\nEste programa serve para calcular o valor das expressões em Postfix, quando desejar sair insira 'q' \n\n");
    
    while(1){
        printf("Insert Postfix: ");
        fgets(t, 100, stdin);
        if(t[0] == 'q'){
            break;
        }
        printf("\nO resultado é: %d\n\n", calculus(t));
    }
    
    system("clear");
    printf("Bye :)\n\n");
    return 0;
}
