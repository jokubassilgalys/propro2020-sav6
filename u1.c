#include <stdio.h>

/*skaiciaus faktorialas spausdinamas i isvesties faila*/

void clean(){
    int ch;
    do{
        ch = getchar();
    }
    while (ch != EOF && ch != '\n');

    return;
}

int input(int x)
{
    printf("iveskite skaiciu kurio faktoriala norite suskaiciuoti ");

    if(scanf("%d", &x) != 1 || x  < 0){
        printf("neteisinga ivestis\n");
        clean();
        input(x);
    }

    return x;
}

int main()
{
    FILE *outputFile = fopen("out.txt", "w");
    int x, ats = 1;
    
    x = input(x);
    
    for(int i = 1; i <= x; ++i){
        ats *= i;
    }
    
    printf("skaiciaus %d faktorialas lygus %d", x, ats);
    fprintf(outputFile, "%d", ats);
    fclose(outputFile);

    return 0;
}