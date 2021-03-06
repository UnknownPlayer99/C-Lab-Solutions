#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ARRAY_SIZE 5
#define INPUT_MAX 100

typedef struct Products {
    char name[INPUT_MAX];
    float amount;
    char unit[INPUT_MAX];
}Product;


typedef struct shopping_lists{
    Product list[ARRAY_SIZE];
    int length;
}shoppingList;



void addProductToList(Product* list, int* size){
    char userInput[INPUT_MAX];
    float temp;
    char str[INPUT_MAX];
    if(*size > ARRAY_SIZE -1){
        printf("List s full!\n");
        return;
    }
    while(1){
    printf("Enter product name: ");
        fgets(userInput, INPUT_MAX, stdin);
        if(sscanf(userInput, "%f", &temp) == 1){
            printf("Input error.\n");
        }
        else if(sscanf(userInput, "\n%[^\n]%*c", str) == 1){
            strcpy(list[*size].name, str);
            break;
        }
        else{
            printf("Input error.\n");
        }
    }
    while(1){
        printf("Enter amount: ");
        fgets(userInput, INPUT_MAX, stdin);
        if(sscanf(userInput, "%f", &temp) == 1){
            if(temp > 0){
            list[*size].amount = temp;
            break;
            }
            else{
                printf("Input error.\n");
            }
        }
        else{
            printf("Input error.\n");
        }
    }
    while(1){
        printf("Enter unit: ");
        fgets(userInput, INPUT_MAX, stdin);
        if(sscanf(userInput, "%f", &temp) == 1){
            printf("Input error.\n");
        }
        else if(sscanf(userInput, "\n%[^\n]%*c", str) == 1){
            strcpy(list[*size].unit, str);
            break;
        }
        else{
            printf("Input error.\n");
        }
    }
    *size = *size + 1;
}

void printList(Product* list, int size){
    int strMax = 0;
    for(int i = 0; i < size; i++){
        if(strlen(list[i].name) > strMax){
            strMax = strlen(list[i].name);
        }
    }
    if(size > 0){
        printf("\nList:");
        for(int i = 0; i < size; i++){
            printf("\n%-*s%4g %s", strMax+4, list[i].name, list[i].amount, list[i].unit);
        }
        printf("\n");
    }
    else{
        printf("\nYour list is empty.\n");
    }
}


int main(){
    shoppingList list;
    list.length = 0;
    int quit = 0;
    while(1){
        int command;
        char userInput[100] = "";
        printf("\nWelcome to your shopping list.\n1 - Add product to list.\n2 - Print shopping list.\n3 - Quit.\nEnter command: ");
        fgets(userInput, 100, stdin);
        if(sscanf (userInput, "%d", &command)){
            switch(command){
                case 1:
                    addProductToList(list.list, &list.length);
                    break;
                case 2:
                    printList(list.list, list.length);
                    break;
                case 3:
                    quit = 1;
                    break;
                default:
                    printf("Input error. \n");
                    break;
            }
        }
        else{
            printf("Input error. \n");
        }
        if(quit){
            break;
        }
    }
    return 0;
}
