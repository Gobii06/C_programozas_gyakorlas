#include <stdio.h>
#include <stdlib.h>

void proba();
void StringHason();
void NovekvoTomb(int* tarolo, int elemSzam);
int FajlHossz();
int Beolvas(int* tomb, int elemSzam);
void TombKiir(int* tomb, int elemSzam, char* uzenet);

int main() {

	proba();

	StringHason();

	int n = 10;

	int* tarolo = malloc(n * sizeof(int));

	NovekvoTomb(tarolo, n);

	for (int i = 0; i < n; i++) {
		printf("%d\t", tarolo[i]);
	}
	printf("\n");

	int fajlhossz = FajlHossz();
	if (fajlhossz == -1) {
		return 1;
	}
	else {
		printf(" A fajl hossza sikeresen meghatarozasra kerult.\n");
	}

	int* stat = NULL;

	stat = malloc(fajlhossz * sizeof(int));
	if (Beolvas(stat, fajlhossz)) {
		printf("Hiba a fajl megnyitasa kozben.\n");
		return -1;
	}

	TombKiir(stat, fajlhossz, "Beolvasott tomb:\n");

	return 0;
}

void TombKiir(int* tomb, int elemSzam, char* uzenet) {
	printf("%s", uzenet);

	for (int i = 0; i < elemSzam; i++)
	{
		printf("%d\n", tomb[i]);
	}

}

int Beolvas(int* tomb, int elemSzam) {

	FILE* bemenet = NULL;

	if (!(bemenet = fopen("szamok.txt", "r"))) {
		return 1;
	}

	for (int i = 0; i < elemSzam; i++) {
		fscanf(bemenet, "%d", &tomb[i]);
	}
	fclose(bemenet);
	return 0;
}

int FajlHossz() {

	FILE* bemenet;

	if (!(bemenet = fopen("szamok.txt", "r"))) {
		return -1;
	}

	int sorszam = 0;
	char c = 0;

	while ((c = fgetc(bemenet)) != EOF) {
		if (c == '\n') {
			sorszam++;
		}
	}

	fclose(bemenet);
	return sorszam;
}

void proba() {

	int* szam = NULL;

	szam = malloc(sizeof(int));

	*szam = 12;

	printf("A memoriaterulet cime: %p\n", szam);
	printf("A pointer altal mutatott valtozo erteke: %d\n", *szam);

	*szam += 5;

	printf("A pointer altal mutatott valtozo erteke: %d\n", *szam);

}

void StringHason() {

	char tomb1[11];
	char tomb2[11];

	printf("Adja meg az egyik karakter lancot!\n");
	scanf("%s", tomb1);

	printf("Adja meg a masik karakter lancot!\n");
	scanf("%s", tomb2);

	printf("%s\t%s\n", tomb1, tomb2);

	int i = 0;
	int talalat = 0;

	while (tomb1[i]) {

		if (tomb1[i] == tomb2[i]) {
			talalat++;
		}
		i++;

	}

	int j = 0;

	while (tomb2[j]) {
		j++;
	}

	if (talalat == i && i == j) {
		printf("A ket sztring egyforma.\n");
	}
	else {
		printf("A ket sztring nem egyforma.\n");
	}

}

void NovekvoTomb(int* tarolo, int elemSzam) {

	for (int i = 0; i < elemSzam; i++) {
		printf("Adja meg a %d. szamot (%d/%d): ", i + 1, i + 1, elemSzam);
		scanf("%d", &tarolo[i]);
		printf("%d\n", tarolo[i]);
	}

	int csere = 1;
	int seged = 0;

	while (csere) {

		csere = 0;

		for (int i = 0; i < elemSzam - 1; i++) {

			if (tarolo[i + 1] < tarolo[i]) {

				seged = tarolo[i];
				tarolo[i] = tarolo[i + 1];
				tarolo[i + 1] = seged;
				csere = 1;

			}
		}
	}
}