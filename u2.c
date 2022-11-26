#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char* reinput()
{
    char * name;
    name = malloc(sizeof(char)*100);

    printf("pateikite kito failo pavadinima ");
    scanf("%s", name);

    return name;
}

int func(char str[], int x, int count, int n)
{
    if(sscanf(str, "%d", &x) != 1){
        printf("ivestis neteisingas\n");
        n = 0;
        return 1;
    }

    else if(x < 10 || x > 1000){
        printf("skaicius nera intervalo ribose\n");
        n = 0;
        return 1;
    }
    
    while(x != 0){
        x /= 10;
        ++count;
    }

    int countB = 0;
    for(int i = count+1; i < n; ++i){
        if(isdigit(str[i]) != 1){
            printf("ivestis neteisinga\n");
            i = n; count = 0; n = 0;
            
            return 1;
        }
        if(countB >= 3 && str[n] != '0'){
            printf("skaicius turi daugiau nei 3 skaicius po kablelio\n");
            i = n; countB = 0; count = 0; n = 0;
            
            return 1;
        }
        ++countB;
        
    }
    int countBoth = count + countB;

    printf("skaicius yra %d skaitmenu ilgio", countBoth);
    return 0;
}

void input(char fileName[], char str[], int x, int count, int n)
{
    FILE *inputFile = fopen(fileName, "r");

    n = 0;
    do{
        str[n] = fgetc(inputFile);
        ++n;
    } while(str[n-1] != EOF);
    --n;

    fclose(inputFile);

    if(func(str, x, count, n) == 1){
        input(reinput(), str, x, count, n);
    }
}

int main()
{
    char fileName[7] = "in.txt";
    char str[255];
    int x, count = 0, n = 0;

    printf("pateikite skaiciu tarp 10 ir 1000 in.txt faile\n");

    input(fileName, str, x, count, n);
    


    return 0;
}