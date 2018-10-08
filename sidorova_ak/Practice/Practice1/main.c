#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	float h, w, d, m; // ��������� �����
	float densityDSP, densityDVP, densityTree; // ��������� ����������
	float wall, sides, doors, lids, shelfs; // ����� �����
	setlocale(LC_ALL, "Russian");

	printf("������� ������ (�� 180 �� 220 ��), ������ (�� 80 �� 130 ��), ������� (�� 50 �� 90 ��) ����� � ��: ");
	scanf("%f %f %f", &h, &w, &d);

	if ((h < 180.0) || (h > 220.0) || (w < 80.0) || (w > 130.0) || (d < 50.0) || (d > 90.0))
	{
		printf("������� ������� ������.\n");
		return;
	}

	printf("������� ��������� ���, ��� � ������ � ��/�^3 : ");
	scanf("%f %f %f", &densityDSP, &densityDVP, &densityTree);

	if ((densityDSP <= 0) || (densityDVP <= 0) || (densityTree <= 0))
	{
		printf("������� ������� ������.\n");
		return;
	}

	h /= 100.0f;
	w /= 100.0f;
	d /= 100.0f;

	wall = h * w * (5 / 1000.0f) * densityDVP;
	sides = 2 * h * d * (15 / 1000.0f) * densityDSP;
	lids = 2 * w * d * (15 / 1000.0f) * densityDSP;
	doors =  h * w * (1 / 100.0f) * densityTree;
	shelfs = floor(h / (0.4 + 15 / 1000.0f)) * w * d * (15 / 1000.0f) * densityDSP; // ����� ������ ����� ����� 15 ��

	m = wall + sides + lids + doors + shelfs;
	printf("����� ����� � �� ����� %.3f\n", m);
}
