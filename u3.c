#include <stdio.h>
#include <stdlib.h>

void clean(){
    int ch;
    do{
        ch = getchar();
    }
    while (ch != EOF && ch != '\n');
    return;
}

char* inputFileName()
{
    char *name;
    name = malloc(sizeof(char)*100);
    
    if(scanf("%s", name) != 1){
        printf("pavadinimas neteisingas, veskite is naujo\n");
        clean();
        inputFileName();
    }

    return name;
}


int main()
{
    double a, b, c, mid;
    printf("iveskite 3 skaicius, be tarpu, kuriuos skiria kabliataskiai ");
    
    for(;;){
        if(scanf("%lf;%lf;%lf", &a, &b, &c) != 3){
            printf("neteisinga ivestis, veskite is naujo\n");
            clean();
        }
        else{
            break;
        }
    }


    if((a < b && b < c) || (c < b && b < a)){
        mid = b;
    }
    else if((b < a && a < c) || (c < a && a < b)){
        mid = a;
    }
    else {
        mid = c;
    }

    printf("iveskite rezultatu failo pavadinima (turi baigtis .txt) ");
    FILE *outputFile = fopen(inputFileName(), "w");

    fprintf(outputFile, "%lf", mid);
    fclose(outputFile);
    
    return 0;
}