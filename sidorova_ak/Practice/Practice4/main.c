#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 62
#define COUNT 25

int ScanBarcode(char a[][4], int check[][2], int k)               // ������� �� ������������ �����-����
{
    int i = 0, number = -1, f = 0;
    char inbarcode[4];

    for (i; i < 4; i++)                                           // ���� ����������� 
    {
        inbarcode[i] = getchar();
        if (inbarcode[i] == '\n')                                 // �������, ���� �����-��� ������ 4 �������� (� �����)
        {
            f = 1;                                                // ��� ����� �������� ������ � ������ �� ����� ����� �����
            break;
        }
    }

    if (f == 1) return -1;                                        // ���� ������ 4 ��������, �� �� ����� �� �������

    if (getchar() != '\n')                                        // ������� �� �������� ������ 4 ��������. ���� ��������� ������ (5-��)
    {                                                             // �� ������� ������ (enter), � ��� ���� ������
        while (getchar() != '\n');                                // �������� ������ ����� �� \n (�������� ������, �.�. enter)
        return -1;
    }

    for (i = 0; i < N + 1; i++)                                   // ����� ���������� � ����� ������ �����-����� ������� �� ������ � ��
    {
        if ((inbarcode[0] == a[i][0]) && (inbarcode[1] == a[i][1]) && (inbarcode[2] == a[i][2]) && (inbarcode[3] == a[i][3]))
        {
            number = i;                                           // ��� ���������� ����������� ����� ������ � ���� ������
            break;
        }
    }

    if ((number != -1) && (number != 62))                         // ���� ��� �� "�����" �����-��� � �� 0000, �� ���������� � �� ����
    {                                                             // �� ������ - ���������� ��������� �������
        check[k][0] = number;                                     // ����� ������ � �� ����
        check[k][1] = 1;                                          // ���������� ������ �� ������ � �� ����
    }

    return number;
}

void DescriptionOfProduct(int number, char barc[][4], char db[][16], int pr[], int sale[])  // ������� �� �������� ������
{
    int i = 0;
    printf(" Product - %c%c%c%c ", barc[number][0], barc[number][1], barc[number][2], barc[number][3]);
    for (i; i < 16; i++)
    {
        printf("%c", db[number][i]);                              // ����� ������������ ������
    }
    printf(" %d rub. %d%%\n ", pr[number], sale[number]);
}

int AllCost(int check[][2], int price[], int count_products)      // ������� �� ����� ������ ��������� ��� ������
{
    int cost = 0, i = 0;

    for (i; i < count_products; i++)
        cost += check[i][1] * price[check[i][0]];                 // � ����� ���������� ���������� ������ � �� ����, ����������
                                                                  // �� ��� ���� �� �� �������� �� ������ � �� ����
    return cost;
}

float TotalCost(int check[][2], int prices[], int sales[], int count_products, int cost)        // ������� �� ����� ��������� �� ��������
{
    float cost_with_sales = 0;
    int i = 0;

    for (i; i < count_products; i++)                                                           // ���� �� ����� ���� ����������
    {                                                                                          // ������� � ������� �� ������
        cost_with_sales += check[i][1] * prices[check[i][0]] * (1.0 - sales[check[i][0]] / 100.0);
    }

    return cost_with_sales;                                       // ���������� �������� ����� ������
}                                                                 // ����� (1 - ��������� ����� �� �������� �� ������ ����� �������)

void OutputCheck(char name[][16], int price[], int count[][2], int sale[], int count_product, int cost, float cost_sale, float total)
{                                                                 // ������� �� ����� ����
    int i = 0, j;

    printf("\n ****** Loading ... ******\n\n #########################\n ######### CHECK #########\n #########################\n");
    printf("\n Market: \"MARIA RA\" \n Cashier: Sidorova Alexandra\n Products:\n ");

    for (i; i < count_product; i++)                               // ���������� ������ � ���������
    {
        for (j = 0; j < 16; j++)
            printf("%c", name[count[i][0]][j]);
        printf(" %d rub. %d it. %.2f rub.\n ", price[count[i][0]], count[i][1], price[count[i][0]] * count[i][1] * (1.0 - sale[count[i][0]] / 100.0));
    }

    printf("\n Cost: %d rub.\n Total sale: %.1f%%\n Total cost: %.2f rub.\n", cost, cost_sale, total);
    printf("\n #########################\n ###### Thank  you! ######\n #########################\n");
}

void main()
{
    char db[N][16] = { "bread", "milk", "pack of eggs", "pasta", "1kg flour", "1kg chicken", "1kg beef", "bottle of water",
        "pack of sausages", "1kg turkey", "1kg duck", "1kr goose", "1kg lamb", "1kg pork", "tea \"Limpron\"",
        "coffee \"Nescafe\"", "cocoa \"Nescafe\"", "apple juice", "orange juice", "multi juice","0.1kg carrots",
        "0.1kg potatoes", "0.1kg tomatos", "0.1kg cucumber", "0.1kg onions", "0.1kg red pepp.", "cabbage",
        "cob of corn", "0.1kg mushrooms", "banana", "kiwi", "pear", "apple", "0.2kg cherry", "0.1kg strawberry",
        "0.2kg grapes", "orange", "plum", "lemon", "pineapple", "watermole", "melon", "crab", "1kg shrimps",
        "1kg salmon", "sardines", "yogurt", "lemonade", "soda", "Coca-Cola", "Fanta", "mayonnaise", "mustard",
        "ketchup", "sour cream", "chocolate", "choco ice cream", "van. ice cream", "bubble gum", "\"Kit-Kat\"",
        "\"Snickers\"", "\"Mars\"" };
    int price[N] = { 20, 50, 40, 85, 65, 150, 350, 30, 65, 256, 300, 300, 270, 260, 125, 230, 185, 65, 70, 70, 25, 10, 25, 30, 30,
        40, 40, 90, 100, 15, 20, 15, 10, 80, 50, 50, 30, 30, 25, 70, 100, 120, 500, 700, 800, 300, 40, 58, 35, 60, 60,
        82, 50, 70, 70, 55, 45, 45, 30, 35, 40, 40 };
    int sale[N];
    char barcode[N + 1][4] = { "0101", "0102", "0103", "0104", "0105", "0106", "0107", "0108", "0109", "0110", "0111", "0112", "0113",
        "0114", "0115", "0116", "0117", "0118", "0119", "0120", "0121", "0122", "0123", "0124", "0125", "0126",
        "0127", "0128", "0129", "0130", "0131", "0132", "0133", "0134", "0135", "0136", "0137", "0138", "0139",
        "0140", "0141", "0142", "0143", "0144", "0145", "0146", "0147", "0148", "0149", "0150", "0151", "0152",
        "0153", "0154", "0155", "0156", "0157", "0158", "0159", "0160", "0161", "0162", "0000" };
    int check_barcode[COUNT][2] = { 0 };
    int barcode_number, i, count_product = 0, cost = 0, f = 0;             // count_product - ���������� ������ �������
    float all_sale = 0, total = 0;
    srand((unsigned int)time(0));

    for (i = 0; i < N; i++)                                                // � ������ �������� ������ ��������� ��������� ������� :)
        sale[i] = rand() % 50 + 1;

    printf("\n /-------------/Cashbox/-------------/\n");
    printf("\n Welcome to the Cashbox!Let's start scanning barcodes.\n\n ATTENTION! Be careful! Barcode must be from 0101 to 0162! ");
    printf("This Cashbox cannot scan other barcodes!\n Enter \"0000\" to complete the scan and .\n Products:\n ");

    do                                                                       // ������ ��������� �������� �� ����� 0000
    {
        barcode_number = ScanBarcode(barcode, check_barcode, count_product); // ������������ �����-����
        if ((barcode_number != -1) && (barcode_number != 62))                // ���� �����-��� ������, �� ������� �������� ������
        {
            DescriptionOfProduct(barcode_number, barcode, db, price, sale);
            for (i = 0; i < count_product; i++)                              // ��������: ��� �� ����� ����� �����
                if (check_barcode[i][0] == barcode_number)                   // ���� ���, ������ ���� � ����������� ��� ����������
                {                                                            // �� ������ � �� ����
                    f = 1;
                    check_barcode[i][1]++;
                }
            if (f == 0) count_product++;                                     // ���� �� ���� ������, �� ����������� ����������
            f = 0;                                                           // ������� ��� �� ����
        }
        if (barcode_number == -1) printf(" Barcode must be from 0101 to 0162! It's not our product :)\n ");
    } while (barcode_number != 62);                                          // �������� �� ����� 62 "������" - �.�. �� 0000

    cost = AllCost(check_barcode, price, count_product);                     // ����������� ������ �����
    total = TotalCost(check_barcode, price, sale, count_product, cost);      // ����������� ����� ����� �� ��������
    all_sale = (1.0 - (float)total / (float)cost) * 100.0;                   // ����������� ����� ������
    OutputCheck(db, price, check_barcode, sale, count_product, cost, all_sale, total);   // ��������� ���
}