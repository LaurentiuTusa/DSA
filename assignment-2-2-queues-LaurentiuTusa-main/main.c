#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{//If no valid conversion could be performed, it returns zero.
 //   val = atoi(str);
    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");
    char caracter_timp[100];
    char nume[15];
    int timp[10];
    int money[8];
    int seconds[8];
    int j;
    int l;
    int i=0;
    int p=1;
    int proba;
    int amount;
    int nr_secunde_acumulate;

    while (fscanf(fi, "%s", caracter_timp) && atoi(caracter_timp) != 0)
    {
        i++;
        timp[i] = atoi(caracter_timp);

    }

        fscanf(fi, "%d", money + p);
        fscanf(fi, "%d", seconds + p);
        p++;

        while ( fscanf(fi, "%s", nume) != EOF)
        {

            fscanf(fi, "%d", money + p);
            fscanf(fi, "%d", seconds + p);
            p++;
        }

    for (j=1; j<=i; j++)//i reprezinta intervalele de timp
    {
        nr_secunde_acumulate = 0;
        amount = 0;
        l=0;
        proba = 0;
        while ((proba < timp[j]) && (l<5))
        {
            l++;
            if (l==5)
            {
                nr_secunde_acumulate = nr_secunde_acumulate + seconds[l];
                amount = amount + money[l];
                break;
            }
            else
            {
                nr_secunde_acumulate = nr_secunde_acumulate + seconds[l];
                proba = nr_secunde_acumulate + seconds[l+1];
                amount = amount + money[l];
            }

        }
        fprintf(fo, "After %d seconds: %d\n", timp[j], amount);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
