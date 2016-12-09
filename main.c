#define _CRT_SECURE_NO_WARNINGS ;
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

void sorgula(int no);
void simgeKontrol();
void yeniden_adlandir();


struct Element {
	int number;
	char simge[500];
	char isim[500];
};

struct Element element[1000];
int sayac = 0;

void main() {

	int secim, element_no;
	char str[50];
	printf("Dosya adi girin :");
	scanf("%s", str);
	FILE * fp;
	fp = fopen(str, "r");
	while (!feof(fp)) {
		fscanf(fp, "%d\t%s\t%s", &element[sayac].number, &element[sayac].simge, &element[sayac].isim);
		printf("%d %s %s \n", element[sayac].number, element[sayac].simge, element[sayac].isim);
		sayac++;
	}
	printf("\n\n");
	do {
		printf("1-element sorgula\n2-simgeleri kontrol et\n3-yeniden isimlendirme\n4-cikis\n");
		scanf("%d", &secim);
		switch (secim)
		{
		case 1:
			printf("element no : ");
			scanf("%d", &element_no);
			sorgula(element_no - 1);
			break;
		case 2:
			simgeKontrol();
			break;
		case 3:
			yeniden_adlandir();
			break;
		default:
			printf("yanlis secim");
			break;
		}

		fclose(fp);

	} while (secim != 4);
}


void sorgula(int no) {

	printf("%d %s %s\n", element[no].number, element[no].simge, element[no].isim);
}


void simgeKontrol() {

	int sira1=0, sira2=0, counter=0;
	bool flag = true;

	for (int i = 0; i < sayac; i++)// element
	{
		if (strlen(element[i].simge) != 2 ) {
			printf("%d %s %s Kisa/uzun simge\n", element[i].number, element[i].simge, element[i].isim);
			continue;
		}

		for (int k = 0; k < strlen(element[i].simge); k++)
		{
			flag = true;
			for (int m = 0; m < strlen(element[i].isim) && flag; m++)
			{
				 if (tolower(element[i].simge[k]) == tolower(element[i].isim[m])) {

					if (counter == 0) {
						sira1 = m+1;
						counter++;
					}
					else if (counter == 1) {
						sira2 = m+1;
						counter++;
					}

					flag = false;

				}

			}

			if (flag) {
				printf("%d %s %s hatali simge\n", element[i].number, element[i].simge, element[i].isim);
				break;
			}

			
		}

			if (sira1 > sira2) {
				printf("%d %s %s hatali simge\n", element[i].number, element[i].simge, element[i].isim);
				continue;
			}
			int sayac = 0;
			if ( tolower(element[i].simge[0]) == tolower(element[i].simge[1])) { // Xx ise  Xenon

				for (int x = 0; x < strlen(element[i].isim); x++)
				{
					if (tolower(element[i].simge[1]) == tolower(element[i].isim[x]))
						sayac++;
				}


				if (sayac != 2) {
					printf("%d %s %s hatali simge\n", element[i].number, element[i].simge, element[i].isim);
					continue;
				}

			}


	}

}


void yeniden_adlandir() {

	for (int i = 0; i < sayac; i++)
	{
		if (strlen(element[i].simge) == 1)
			printf("%d %c%c %s\n", element[i].number, element[i].isim[0], element[i].isim[1], element[i].isim);
		else if (strlen(element[i].simge) == 2) 
			printf("%d %c%c %s\n", element[i].number, element[i].isim[0], element[i].isim[1], element[i].isim);
		else
			printf("%d %c%c %s\n", element[i].number, element[i].isim[0], element[i].isim[1], element[i].isim);

	}

}
