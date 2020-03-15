#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void isPalindrome(char* str){
    int strSize = strlen(str);
    if(strSize == 1)
        printf("PALINDROMO");
    else{
        if(str[0] != str[strSize - 1]){
            printf("NÃO É PALINDROMO");
            return;
        }
        else{
            char newString[100];
            strcpy(newString, &str[1]);
            if(strlen(newString) == 1){
                printf("PALINDROMO");
                return;
            }
            newString[strlen(newString)-1] = '\0';
            isPalindrome(newString);
        }
    }

}

int greaterValue(int array[], int size){
    if(size == 0)
        return array[0];
    else{
        if(array[size-1] >= greaterValue(array, size-1))
            return array[size -1];
    }
}

int main(int argc, char* argv){
    char str[] = "socorrammesubinoonibusemmarrocos";
    //int array[] = {2,3,9,10,5,4,9,5};
    //printf("%d",greaterValue(array,sizeof(array)/sizeof(array[0])));
    isPalindrome(str);
    return 0;
}