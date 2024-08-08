#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char String[100];

    printf("\nEnter a string: ");
    fgets(String,sizeof(String), stdin);

    printf("\n");

    int length = strlen(String) - 1;

    for(int i = 0; i < length; i++){
        int ocurrence = 0;

        for(int j = 0; j < length; j++){
            if(String[i] == String[j]){
                ocurrence++;
            }
        }

        printf("letter = %c ocurence = %d\n",String[i], ocurrence);
    }


    return 0;

}