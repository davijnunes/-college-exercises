#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype of function
void inversionOfString(const char *input, char *ouput);
void showString(char *str);

int main(){


    char String[100], stringInversion[100];

    printf("\nEnter a string: ");
    fgets(String,sizeof(String), stdin);
     
    String[strcspn(String,"\n")] = '\0';

    inversionOfString(String,stringInversion);

    showString(stringInversion);

    return 0;

}

void inversionOfString(const char *input, char *output){

    // strlen return a quantity of characters
    int length = strlen(input) - 1;

    for(int i = length; i >= 0; i--){

        output[length - i] = input[i];

        //printf("%c\n", output[j - 1]);
    }

    // Add character final of string 
    output[length + 1] = '\0';

}

void showString(char *str){
    
    printf("\n");
    printf("Reversed string: %s", str);
    printf("\n");
}