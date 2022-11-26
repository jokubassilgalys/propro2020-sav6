#include <stdio.h>
#include <string.h>

/*sudaromas ivestu el. pasto adresu indeksas*/

void clean(){
    int ch;
    do{
        ch = getchar();
    }
    while (ch != EOF && ch != '\n');
    return;
}

int func(char email[])
{
    int count = 0, atIndex, emailLength = strlen(email);

    for(int i = 0; i < emailLength; ++i){
        if(email[i] == '@'){
            ++count;
            atIndex = i;
        }
    }

    if(atIndex == 0){
        printf("pries simboli @ privalo buti bent vienas simbolis ");
        return 1;
    }
    if(count == 0){
        printf("adrese nera nei vieno @ simbolio ");
        return 1;
    }
    if(count > 1){
        printf("adrese yra daugiau nei vienas @ simbolis ");
        return 1;
    }

    count = 0;
    for(int i = atIndex+1; i < emailLength; ++i){
        if(email[i] == '.'){
            ++count;
            break;
        }
    }
    if(count == 0){
        printf("adrese nera nei vieno tasko po @ simbolio ");
        return 1;
    }
    if(email[atIndex+1] == '.'){
        printf("adrese nera nei vieno simbolio tarp @ ir tasko ");
        return 1;
    }
    if(email[emailLength-1] == '.'){
        printf("paskutinis adreso simbolis negali buti taskas");
        return 1;
    }

    FILE *outputFile = fopen("emails.txt", "a");

    for(int i = atIndex+1; i < emailLength; ++i){
        fprintf(outputFile, "%c", email[i]);
    }
    fprintf(outputFile, "\n");

    fclose(outputFile);

    return 0;
}

void input(char email[])
{
    
    if(scanf("%s", email) != 1){
        printf("iveskite el. pasta is naujo\n");
        clean();
        input(email);
    }

    if(func(email) == 1){
        printf("iveskite el. pasta is naujo\n");
        input(email);
    }

    return;
}

int main()
{
    char email[255];
    
    printf("iveskite el. pasto adresa ");
    input(email);


    return 0;
}