#include <stdio.h>

/*apskaiciuojama ivestos datos savaites diena*/

void clean(){
    int ch;
    do{
        ch = getchar();
    }
    while (ch != EOF && ch != '\n');
    return;
}

int main()
{
    int year, month, day, count = 0;

    printf("iveskite data formatu YYYY-MM-DD ");

    for(;;){
        if(scanf("%d-%d-%d", &year, &month, &day) != 3){
            printf("neteisinga ivestis, veskite is naujo\n");
            clean();
        }
        else{
            break;
        }
    }

    int weekday = (day += month < 3 ? --year : year - 2, 23*month/9 + day + 4 + year/4 - year/100 + year/400) % 7;
    
    if(weekday == 0){
        weekday = 7;
    }
    --weekday;


    FILE *dayNameFile = fopen("week.txt", "r");
    char dayName[30];


    while(fgets(dayName, sizeof dayName, dayNameFile) != NULL){
        if(count == weekday){
            puts(dayName);
        }
        else{
            ++count;
        }
        
    }
    fclose(dayNameFile);

    return 0;
}