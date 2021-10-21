/*
     ��ࠦ����� 12 (fio_12fw). �뢮� � 䠩�.
     �������筮 �ࠦ����� 11 � �� ���� ��� ��室����, ��  �뢮� �� ���᮫�  
��������� �� �뢮� � ��᫥����⥫�� 䠩� fio_12xx.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "gpi_09i.h"

void gpi__set_gpi_n(struct gpi_Struct* gpi_struct);
void gpi__set_gpi_c(struct gpi_Struct* gpi_struct);
void gpi__set_gpi_k(struct gpi_Struct* gpi_struct);
void gpi_10fv(struct gpi_Struct* gpi_struct);	
void gpi__print_info(struct gpi_Struct* gpi_struct);
void gpi__print_table_head();
void gpi__print_element(const int gpi_i, struct gpi_Struct* gpi_arr);
void gpi__print_table(const int gpi_length, struct gpi_Struct* gpi_arr);
void gpi__print_if_c_more_than_50(const int gpi_length, struct gpi_Struct* gpi_arr);
void gpi__print_csv_file(const int gpi_length, struct gpi_Struct* gpi_arr);

int main()
	{
    const int gpi_length = GPI_ARRAY_LENGTH;
	struct gpi_Struct gpi_arr[GPI_ARRAY_LENGTH];
	/* --------------------------------------------------------- */	
	
	system("chcp 866");
	
	printf(" =������� �.�.=     =gpi_12fw= \n");
	printf(" ��ࠦ����� 12 (fio_12fw). �뢮� � 䠩�. \n");
    printf(" \n");

    int gpi_i = 0;
    while(gpi_i < gpi_length)
        {
        printf(" { \n");
        gpi__set_gpi_n(&gpi_arr[gpi_i]);
        
        if(gpi_arr[gpi_i].gpi_n[0] == '*')
            {
            printf(" ��室 �� 横�� \n");
            printf(" } \n");
            break;
            }
        
        gpi__set_gpi_c(&gpi_arr[gpi_i]);
        gpi__set_gpi_k(&gpi_arr[gpi_i]);
        gpi_10fv(&gpi_arr[gpi_i]);
        gpi__print_info(&gpi_arr[gpi_i]);
        printf(" } \n");
        ++gpi_i;
        }
        
    gpi__print_table(gpi_i, gpi_arr);
    gpi__print_if_c_more_than_50(gpi_i, gpi_arr);
    gpi__print_csv_file(gpi_i, gpi_arr);
	
	printf(" \n press any key \n");
	getch();

	return(0);
	}

void gpi__set_gpi_n(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s �������� ���ਠ�� ");
	scanf("%s", gpi_struct->gpi_n);
	}
	
void gpi__set_gpi_c(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s ���� ");
	scanf("%d", &(gpi_struct->gpi_c));
	}
	
void gpi__set_gpi_k(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s ������⢮ ");
	scanf("%d", &(gpi_struct->gpi_k));
	}
	
void gpi_10fv(struct gpi_Struct* gpi_struct)
	{
	gpi_struct->gpi_s = gpi_struct->gpi_c * gpi_struct->gpi_k;
	}
	
void gpi__print_info(struct gpi_Struct* gpi_struct)
	{
	printf(" ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n",
		gpi_struct->gpi_n,
		gpi_struct->gpi_c,
		gpi_struct->gpi_k,
		gpi_struct->gpi_s
		);
	}

void gpi__print_table_head()
    {
    printf(" \n");
    printf(" | %4s | %12s | %12s | %12s | %12s | \n",
        " ID ",
        "������������",
        "    ����    ",
        " ������⢮ ",
        " �⮨�����  "
        );
        
    printf(" | %4s | %12s | %12s | %12s | %12s | \n",
        "----",
        "------------",
        "------------",
        "------------",
        "------------"
        );
    }

void gpi__print_element(const int gpi_i, struct gpi_Struct* gpi_arr)
    {
    printf(" | %4d | %12s | %12d | %12d | %12d | \n",
        gpi_i,
        gpi_arr[gpi_i].gpi_n,
        gpi_arr[gpi_i].gpi_c,
        gpi_arr[gpi_i].gpi_k,
        gpi_arr[gpi_i].gpi_s
        );
    }

void gpi__print_table(const int gpi_length, struct gpi_Struct* gpi_arr)
    {
    gpi__print_table_head();
    int gpi_i = 0;
    while(gpi_i < gpi_length)
        {
        gpi__print_element(gpi_i, gpi_arr);
        ++gpi_i;
        }
    printf(" \n");
    }


void gpi__print_if_c_more_than_50(const int gpi_length, struct gpi_Struct* gpi_arr)
    {
    int gpi_number = 50;
    int gpi_counter = 0;
    gpi__print_table_head();
    int gpi_i = 0;
    while(gpi_i < gpi_length)
        {
        if (gpi_arr[gpi_i].gpi_c >= gpi_number)
            {
            gpi__print_element(gpi_i, gpi_arr);
            ++gpi_counter;
            }
        ++gpi_i;
        }
    if (gpi_counter == 0)
        {
        printf(" ��� ⠪�� ���ਠ���, � ������ 業� ����� %d \n", gpi_number);
        }
    else
        {
        printf(" �� ���ਠ��, � ������ 業� ����� %d \n", gpi_number);
        }
    printf(" \n");
    }

void gpi__print_csv_file(const int gpi_length, struct gpi_Struct* gpi_arr)
    {
    char gpi_path[] = "gpi_12xx.csv";
    FILE* gpi_file_pointer = fopen(gpi_path, "w");
    if (gpi_file_pointer == NULL)
        {
        printf(" ���� %s �� �� ����� ��� ����� \n", gpi_path);
        return;
        }
    int gpi_i = 0;
    while(gpi_i < gpi_length)
        {
        fprintf(gpi_file_pointer, "%s", gpi_arr[gpi_i].gpi_n);
        fprintf(gpi_file_pointer, ",");
        
        fprintf(gpi_file_pointer, "%d", gpi_arr[gpi_i].gpi_c);
        fprintf(gpi_file_pointer, ",");
        
        fprintf(gpi_file_pointer, "%d", gpi_arr[gpi_i].gpi_k);
        fprintf(gpi_file_pointer, "\n");
                
        ++gpi_i;
        }
    fclose(gpi_file_pointer);
    printf(" ����� ����ᠭ� � %s 䠩� \n", gpi_path);
    }