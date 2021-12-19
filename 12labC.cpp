#include <stdio.h>
#include <conio.h>
#include <locale>

struct Figures {
	int x;
	int y;
	int rad;
	int R;
	int G;
	int B;
	int W;
};

int main() {
	setlocale(LC_ALL, "Rus");
	FILE* f;
	fopen_s(&f, "E:\\lab12.bin", "wb");
	printf("Введите кол-во фигур: ");
	int colvo;
	scanf_s("%d", &colvo);
	fwrite(&colvo, sizeof(int), 1, f);
	for (int i = 0; i < colvo; i++) {
	Figures fig;
		printf("Введите данные фигуры %d:\nx = ", i + 1);
		scanf_s("%d", &fig.x);
		printf("y = ");
		scanf_s("%d", &fig.y);
		printf("Radius = ");
		scanf_s("%d", &fig.rad);
		printf("R = ");
		scanf_s("%d", &fig.R);
		printf("G = ");
		scanf_s("%d", &fig.G);
		printf("B = ");
		scanf_s("%d", &fig.B);
		printf("Толщина = ");
		scanf_s("%d", &fig.W);
		fwrite(&fig, sizeof(Figures), 1, f);
	}
	fclose(f);
	return 0;
}