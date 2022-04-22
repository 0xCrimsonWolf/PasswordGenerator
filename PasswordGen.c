#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int PasswordGen(bool, bool, int);

int main()
{
    srand(time(NULL));

    char menu;
    bool chiffre=true, spec=true;
    int taille=0;
    char *chif_bool="TRUE";
    char *spec_bool="TRUE";

    do
    {
        system("cls");
        printf("\n\
 /$$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$           /$$$$$$  /$$$$$$$$ /$$   /$$\n\
| $$__ $$  /$$__  $$| $$  /$ | $$| $$__  $$         /$$__  $$| $$_____/| $$$ | $$\n\
| $$  \ $$ |$$  \__/  | $$ /$$$| $$| $$  \  $$        | $$  \__/ | $$      | $$$$| $$\n\
| $$$$$$$ |  $$$$$$ | $$/$$ $$ $$| $$  | $$ /$$$$$$| $$ /$$$$| $$$$$   | $$ $$ $$\n\
| $$____/  \____  $$ | $$$$_  $$$$| $$  | $$|______/| $$|_  $$| $$__/   | $$  $$$$\n\
| $$       /$$  \ $$ | $$$/  \  $$$| $$  | $$        | $$  \ $$ | $$      | $$\   $$$\n\
| $$      |  $$$$$$/| $$/    \  $$| $$$$$$$/        |  $$$$$$/| $$$$$$$$| $$ \   $$\n\
|__/       \______/  |__/      \__/|_______/          \______/  |________/|__/   \__/\n\
                                                                                 \n\
");
        printf("---------------------------------- Password GEN ----------------------------------\n\n\
    1. Voulez-vous des chiffres ? (%s)\n\
    2. Voulez-vous des caract%cres speciaux ? (%s)\n\
    3. De quelle taille ? (%d)\n\
    4. Lancer la GEN.\n\
    5. Quitter.\n\n\
----------------------------------------------------------------------------------\n\n", chif_bool, 138, spec_bool, taille);

        fflush(stdin);
        scanf("%c", &menu);

        switch(menu)
        {
        case '1':
        {
            if (!chiffre)
            {
                chif_bool="TRUE";
                chiffre=true;
            }
            else
            {
                chif_bool="FALSE";
                chiffre=false;
            }
            break;
        }
        case '2':
        {
            if (!spec)
            {
                spec_bool="TRUE";
                spec=true;
            }
            else
            {
                spec_bool="FALSE";
                spec=false;
            }
            break;
        }
        case '3':
            system("cls");
            printf("Quelle taille ? \n\n\t> ");
            fflush(stdin);
            scanf("%d", &taille);

            if (taille>128)
            {
                system("cls");
                printf("\n\tTaille trop %clev%ce... ", 130, 130);
                sleep(2);
                break;
            }
            break;
        case '4':
        {
            system("cls");
            PasswordGen(chiffre, spec, taille);
            break;
        }
        case '5':
            return 0;
            break;
        }
    }while(menu!=('1'|'2'|'3'|'4'|'5'));
}

int PasswordGen(bool chiffre, bool car_speciaux, int taille)
{
    char abc[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char chif123[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char spec[18] = {'|','@','"','#','!','^','?','*',':','.',',','=','+','~','<','>',';','-'};
    char pswd[taille];
    int i, rdm;
    bool ok;

    printf("\nPSWD >   ");

    for (i=0;i<taille;i++)
    {
        ok=false;
        while(!ok)
        {
            rdm=rand() % 4;

            switch(rdm)
            {
                case 1:
                {
                    int rdm_abc;
                    rdm_abc=rand() % 52+1;

                    pswd[i]=abc[rdm_abc];
                    ok=true;
                    break;
                }
                case 2:
                {
                    if (chiffre)
                    {
                        int rdm_123;
                        rdm_123=rand() % 10+1;

                        pswd[i]=chif123[rdm_123];
                        ok=true;
                    }
                    else
                        ok=false;
                    break;
                }
                case 3:
                {
                    if (car_speciaux)
                    {
                        int rdm_spec;
                        rdm_spec=rand() % 18+1;

                        pswd[i]=spec[rdm_spec];
                        ok=true;
                    }
                    else
                        ok=false;
                    break;
                }
            }
        }
        Sleep(10);
        printf("%c", pswd[i]);
    }

    pswd[0]='\0';

    char c;
    printf("\n\nAppuyez sur ENTER pour revenir au menu. ");
    fflush(stdin);
    scanf("%c", &c);
}
