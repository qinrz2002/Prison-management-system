//��������ϵͳ
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define M 1000
//�ṹ��**********************************************************************************
struct people
{
	char name[30];// ������
	char fang[30];//�η�������
	char num[30];//��ţ�
	int xingbie;//�Ա�
	int starttime;//�Ѻ��ʼʱ�� ��
	int endtime;//�Ѻ����ʱ�䣡
	int alltime;// �Ѻʱ���� 
	int shengyu;//ʣ��ʱ����
	int time;//ʱ�䣡
	int time_true_id;//ʱ���Ƿ�����У��ֵ
	int peo_true_id;//�Ƿ�����У��ֵ
};
void color(short x)	//�Զ��庯���ݲ����ı���ɫ***********************************************
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ 
	else//Ĭ�ϵ���ɫ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//��������********************************************************************************
void fileread(struct people peo[M]);//*��ȡ�ļ����� 
void filesave(struct people peo[M]);//*�����ļ����� 
void input(struct people peo[M]);//****�������ݺ��� 
void output(struct people peo[M]);//***������� 
void del(struct people peo[M]);//******ɾ����Ϣ���� ��1 ��2�� 
void gai(struct people peo[M]);//******����Ϣ���� 
void chakan(struct people peo[M]);//**��ѯ��Ϣ���� 
void name_(struct people peo[M]);//****ʹ������ɾ����Ϣ 1 
void num_(struct people peo[M]);//*****ʹ�ñ��ɾ����Ϣ 2
void xingname_(struct people peo[M]);//****ʹ������������ 1 
void xingnum_(struct people peo[M]);//*****ʹ�ñ�ż����� 2
void order(struct people peo[M]);//****����������
void time(struct people peo[M]);//����ʱ��
void addxing(struct people peo[M]);//����
void shengyu0(struct people peo[M]);//���ճ���
void shengyu7(struct people peo[M]);//���ճ���
void shengyu30(struct people peo[M]);//��ʮ�ճ���
//****************************************************************************************

int count = 0;//������Ϣ�ĸ�����һ��ʼΪ��
struct people t;
//���t�ǽ���order����ʱ�õ� 
//****************************************************************************************


//������**********************************************************************************
int main()
{
	int key;//�������룡
	do//����ģ��
	{
		color(7);
		printf_s("������ϵͳ����\n");
		color(0);
		scanf_s("%d", &key);
		system("cls");
	} while (key != 5216120);

	int sum = 0, xuanze;//xuanzeһ��ʼ����������ѡ��
	system("mode con: cols=200 lines=200"); //���Ʊ������ߺͿ� 
	struct people peo[M];
	int j = 0;
	for (j; j < 999; j++)
	{
		strcpy(peo[j].fang, "��");
	}
	system("cls");//����
	//**********�������н���********
	color(7);
	do {
		printf_s("\n");
		printf_s("\n");
		printf_s("|-----------------------------------------------------|   |------------------------------------------------------|   |------------------------------------------------------|\n");
		printf_s("|-----------------------------------------------------|   |------------------ �� �� ʵ ʱ �� �� -----------------|   |------------------------------------------------------|\n");
		printf_s("|                                                     |   |------------------------------------------------------|   |                                                      |\n");
		printf_s("|*                 �� �� �� �� ϵ ͳ                 *|   |----------|----------|----------|----------|----------|   |         ****       ��  ��  ��  ��        ****        |\n");
		if (peo[999].time_true_id == 1) {
			int nian, yue, ri;
			nian = peo[999].time / 10000;
			yue = (peo[999].time % 10000) / 100;
			ri = peo[999].time % 100;
			printf_s("|              ��ǰʱ�䣺%4d��%2d��%2d��               |   |   0��    |   1��    |   2��    |   3��    |   4��    |   |                                                      |\n", nian, yue, ri);
		}
		else {
			printf_s("|                   ��ǰʱ�䣺δ����                  |   |   0��    |   1��    |   2��    |   3��    |   4��    |   |                                                      |\n");
		}

		printf_s("|******************�����ֻ�*�����©******************|   | %-9s| %-9s| %-9s| %-9s| %-9s|   |------------------------------------------------------|\n", peo[0].fang, peo[1].fang, peo[2].fang, peo[3].fang, peo[4].fang);
		printf_s("|-----------------------------------------------------|   |          |          |          |          |          |   |                                                      |\n");
		printf_s("|                                                     |   |----------|----------|----------|----------|----------|   |    ��һ�� ӵ���ܷ������ط��ɷ�����ºͼ����ɡ�     |\n");
		printf_s("| ���� �� �� Ա��  1 - ����    2 - �鿴    3 - ��ѯ   |   |   5��    |   6��    |   7��    |   8��    |   9��    |   |                                                      |\n");
		printf_s("|                                                     |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |    �ڶ��� ���ӹ������ܽ������μ��Ͷ���������   |\n", peo[5].fang, peo[6].fang, peo[7].fang, peo[8].fang, peo[9].fang);
		printf_s("|                  4 - �޸�    5 - ɾ��    6 - ����   |   |          |          |          |          |          |   |                                                      |\n");
		printf_s("|                                                     |   |----------|----------|----------|----------|----------|   |    ������ ������������񣬰����壬��ѧϰ�����Ͷ���   |\n");
		printf_s("| ���� �� �� ����  7 - ��ȡ    8 - ����               |   |   10��   |   11��   |   12��   |   13��   |   14��   |   |                                                      |\n");
		printf_s("|                                                     |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |    ������ ������ţ��������ƣ��ڼ���ǿ��             |\n", peo[10].fang, peo[11].fang, peo[12].fang, peo[13].fang, peo[14].fang);
		printf_s("| ���� �� �� ѯ��  9 - ����    10- ����    11- ��ʮ�� |   |          |          |          |          |          |   |                                                      |\n");
		printf_s("|                                                     |   |----------|----------|----------|----------|----------|   |    ������ ������ʹȨ��������������ʽ�ͳ���ά������   |\n");
		printf_s("| ������ �̡���    12- ����                           |   |   15��   |   16��   |   17��   |   18��   |   19��   |   |           �Ϸ�Ȩ�档                                 |\n");
		printf_s("|                                                     |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |                                                      |\n", peo[15].fang, peo[16].fang, peo[17].fang, peo[18].fang, peo[19].fang);
		printf_s("|-----------------------------------------------------|   |          |          |          |          |          |   |    ������ �����ڼ��ϸ����ؼ��ɡ�                     |\n");
		printf_s("|        13-����ʱ��                 14-����          |   |----------|----------|----------|----------|----------|   |                                                      |\n");
		printf_s("|-----------------------------------------------------|   |   20��   |   21��   |   22��   |   23��   |   24��   |   |                  �úø��죬��������                  | \n");
		printf_s("|                    ��  0-�˳�  ��                   |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |                                                      |\n", peo[20].fang, peo[21].fang, peo[22].fang, peo[23].fang, peo[24].fang);
		printf_s("|                     �汾 V 1.1.0                    |   |          |          |          |          |          |   |------------------------------------------------------|\n");
		printf_s("|-----------------------------------------------------|   |----------|----------|----------|----------|----------|   |------------------------------------------------------|\n");
		printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf_s("|                                                                            ��Ȩ���� ��Ȩ�ؾ�                                                                              |\n");
		printf_s("|                                                                   Copyright infringement 05216120 �����                                                                  |\n");
		printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf_s("\n");
		printf_s("���������ѡ��:\n");
		scanf("%d", &xuanze); //����ѡ���� 
		fflush(stdin);       //������뻺����
		if (xuanze > 13 || xuanze <= 0)
		{
			sum++;
			if (sum >= 13)
			{
				printf("������������13��,�������¿�ʼ\n");
				//ͨ�����ƴ������룬�����������ͬ 
				system("pause");        //������ͣ������ѡ�� 
				system("cls");   //�������
			}
		}
		switch (xuanze)       //����ѡ�񣬵��ò�ͬ�ĺ�������ɲ�ͬ������
		{
		case 1:input(peo); break;   //���� 
		case 2:output(peo); break;  //��� 
		case 3:chakan(peo); break;  //��ѯ 
		case 4:gai(peo); break;     //�޸� 
		case 5:del(peo); break;     //ɾ��
		case 6:order(peo); break;   //���� 
		case 7:fileread(peo); break;//��ȡ�ļ����� 
		case 8:filesave(peo); break;//�����ļ�����
		case 9:shengyu0(peo); break;//ʣ��0�����
		case 10:shengyu7(peo); break;//ʣ��7�����
		case 11:shengyu30(peo); break;//ʣ��30�����
		case 12:addxing(peo); break;//����
		case 13:time(peo); break;//�����ļ�����
		case 14:system("cls"); break;//����
		case 0:printf("ʹ����ϣ���ص�����\n"); system("pause"); break;
		default:system("cls"); break;
		}
	} while (xuanze != 0);
	printf("��������� over\n");
	return 0;
}


//����ʱ��********************************************************************************
void time(struct people peo[M])
{
	system("cls");//�������
	printf_s("�����뵱ǰʱ��\n");
	scanf_s("%d", &peo[999].time);
	system("cls");//�������
	printf_s("������\n");
	peo[999].time_true_id = 1;
}



//����************************************************************************************
void addxing(struct people peo[M])
{
	int choice;
	system("cls");//������� 
	if (count == 0)
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ\n");
		return;
	}
	else
	{
		printf("��ѡ������Ҫ���̵ķ�ʽ:1����� 2������ 3��ȡ��\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 3:return; break;
		case 2:xingname_(peo); break;
		case 1:xingnum_(peo); break;
		default:printf("�����������������\n"); break;
		}

	}

}
void xingname_(struct people peo[M])//ʹ������������
{
	int k = 0, j, day;
	char xm[25];
	system("cls");//������� 
	printf("��Ҫ�����̵���Ѻ��Ա����Ϊ��\n");
	scanf("%s", xm);
	fflush(stdin);//������뻺����
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].name, xm) == 0)
		{
			k = 1;
			printf("��%s�����̵�����Ϊ��\n", peo[j].name);
			scanf("%d", &day);
			peo[j].endtime = peo[j].endtime + day;
			peo[j].alltime = peo[j].alltime + day;
			printf("�ѳɹ���%s����%d��\n", peo[j].name, day);
			printf("��ǰ����Ϊ��%d��\n", peo[j].alltime);
			int nian = (peo[j].endtime / 10000) + day / 365, yue = ((peo[j].endtime % 10000) / 100) + ((day % 365) / 30), ri = (peo[j].endtime % 100) + ((day % 365) % 30);
			do {
				if (ri > 30) {
					ri = ri - 30; yue = yue + 1;
				}
				if (yue > 12) {
					yue = yue - 12; nian = nian + 1;
				}
			} while (ri > 30 && yue > 12);

			printf("Ԥ���ͷ�ʱ�䣺%4d��%2d��%2d��\n", nian, yue, ri);
		}
	}
	if (k == 0)
		printf("û������Ҫ���̵���Ѻ��Ա����Ϣ\n");
}
void xingnum_(struct people peo[M])//ʹ�ñ�ż�����
{
	int j, k = 0, day;
	char xh[25];
	system("cls");//������� 
	printf("��Ҫ�����̵���Ѻ��Ա���Ϊ��\n");
	scanf("%s", xh);
	fflush(stdin);//������뻺����
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].num, xh) == 0)
		{
			k = 1;
			printf("��%s�����̵�����Ϊ��\n", peo[j].name);
			scanf("%d", &day);
			peo[j].endtime = peo[j].endtime + day;
			peo[j].alltime = peo[j].alltime + day;
			printf("�ѳɹ���%s����%d��\n", peo[j].name, day);
			printf("��ǰ����Ϊ��%d��\n", peo[j].alltime);
			int nian = (peo[j].endtime / 10000) + day / 365, yue = ((peo[j].endtime % 10000) / 100) + ((day % 365) / 30), ri = (peo[j].endtime % 100) + ((day % 365) % 30);
			if (ri > 30) {
				ri = ri - 30; yue = yue + 1;
			}
			if (yue > 12) {
				yue = yue - 12; nian = nian + 1;
			}
			printf("Ԥ���ͷ�ʱ�䣺%4d��%2d��%2d��\n", nian, yue, ri);
		}
	}
	if (k == 0)
		printf("û������Ҫ���̵���Ѻ��Ա����Ϣ\n");
}


//����************************************************************************************
void shengyu0(struct people peo[M])//���ճ���
{
	int i = 0, j;
	system("cls");//������� 
	if (count == 0)//�ж��Ƿ�����Ѻ��Ա��Ϣ 
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ\n");
		return;
	}
	else
	{
		printf("�����ա���������ԱΪ:\n");
		fflush(stdin);//������뻺����
		for (j = 0; j < count; j++)
		{
			peo[j].shengyu = peo[j].endtime - peo[999].time;
			if (peo[j].shengyu == 0)
			{
				printf("%s\n", peo[j].name);
				i++;
			}
		}
		if (i == 0) printf("��");

	}
}
void shengyu7(struct people peo[M])//���ճ���
{
	int i = 0, j;
	system("cls");//������� 
	if (count == 0)//�ж��Ƿ�����Ѻ��Ա��Ϣ 
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ\n");
		return;
	}
	else
	{
		printf("�������ڡ���������ԱΪ:\n");
		fflush(stdin);//������뻺����
		for (j = 0; j < count; j++)
		{
			peo[j].shengyu = peo[j].endtime - peo[999].time;
			if (peo[j].shengyu <= 7)
			{
				printf("%s\n", peo[j].name);
				i++;
			}
		}
		if (i == 0) printf("��");

	}
}
void shengyu30(struct people peo[M])//��ʮ�ճ���
{
	int i = 0, j;
	system("cls");//������� 
	if (count == 0)//�ж��Ƿ�����Ѻ��Ա��Ϣ 
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ\n");
		return;
	}
	else
	{
		printf("����ʮ���ڡ���������ԱΪ:\n");
		fflush(stdin);//������뻺����
		for (j = 0; j < count; j++)
		{
			peo[j].shengyu = peo[j].endtime - peo[999].time;
			if (peo[j].shengyu <= 30)
			{
				printf("%s\n", peo[j].name);
				i++;
			}
		}
		if (i == 0) printf("��");

	}
}



//�����ļ�����****************************************************************************
void filesave(struct people peo[M])
{
	int a = 0;
	FILE* fp;
	if ((fp = fopen("D:\\QRZ\\peodata.txt", "wb")) == NULL)
	{
		printf("�ļ��򿪴��󣬳����޷�����\n");
		exit(0);
	}
	for (a = 0; a < 30; a++)
	{
		fwrite(&peo[a], sizeof(struct people), 1, fp);
	}
	fclose(fp);
	if (count == 0)
		printf("����Ѻ��Ա��Ϣ�����ܱ���\n");
	else
		printf("�����Ѿ����� ok\n");
	system("cls");//������� 
	system("pause");//ϵͳ���¿�ʼ ������ѡ����
	return;
}


//��ȡ�ļ�����****************************************************************************
void fileread(struct people peo[M])
{
	int a = 0;
	FILE* fp;
	system("cls");//�������
	if ((fp = fopen("D:\\QRZ\\peodata.txt", "rb")) == NULL)
	{
		printf("�ļ��򿪴��󣬳����ܽ���\n");
		exit(0);
	}
	fread(&peo[a], sizeof(struct people), 1, fp);
	count = 0;
	count++;
	a++;
	while (fread(&peo[a], sizeof(struct people), 1, fp))
	{
		a++;
		count++;
	}
	fclose(fp);
	printf("���ݶ�ȡ���!!!\n");
	count = 0;
	for (int i = 0; i < 30; i++)
	{ 
		if (peo[i].peo_true_id == 1)
		{
			count++;
		}
	}
	printf("%d", count);
	system("cls");//������� 
	system("pause");//ϵͳ���¿�ʼ ������ѡ����
	return;

}


//���뺯��********************************************************************************
void input(struct people peo[M])
{
	if (peo[999].time_true_id == 1)
	{
		int len;
		system("cls");//������� 
		printf("�����Ҫ������Ѻ��Ա����Ϣ\n");
		do {
			printf("������Ѻ��Ա���(4λ��)\n");
			//do-whileѭ�������ʱ������ʾ�����Ϊ4�����֣� 
			scanf("%s", &peo[count].num);
			len = strlen(peo[count].num);
		} while (len != 4);
		printf("������Ѻ��Ա������\n");
		scanf("%s", peo[count].name);
		printf("�����Ա����:1��  2Ů \n");
		scanf("%d", &peo[count].xingbie);
		printf("������Ѻ��ʼʱ��:20xx01xx \n");
		scanf("%d", &peo[count].starttime);
		do {
			printf("������Ѻ��Ա�����Ѻʱ��\n");
			scanf("%d", &peo[count].endtime);
		} while (peo[count].endtime < peo[count].starttime);
		//�жϽ���ʱ���Ƿ�ȿ�ʼʱ���磬������������ 
		peo[count].alltime = peo[count].endtime - peo[count].starttime;      //�Ѻʱ��
		peo[count].shengyu = peo[count].endtime - peo[999].time;
		strcpy(peo[count].fang, peo[count].name);
		count++;   //������Ѻ��Ա��Ϣ�ĸ���
		peo[count].peo_true_id = 1;
	}
	else
	{
		system("cls");
		printf_s("δ����ʱ��\n");
	}

}


//�������********************************************************************************
void output(struct people peo[M])
{
	int j;
	system("cls");//������� 
	if (count == 0)
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ��¼\n");
		return;
	}
	for (j = 0; j < count; j++)
	{
		for (j = 0; j < count; j++)
		{       //forѭ����������ĸ���
			printf("���:%s  ", peo[j].num);
			printf("����:%s  ", peo[j].name);
			if (peo[j].xingbie == 1)
				printf("��  ");
			else if (peo[j].xingbie == 2)
				printf("Ů  ");
			printf("��ʼʱ��:%d  ", peo[j].starttime);
			printf("����ʱ��:%d  ", peo[j].endtime);
			printf("ʱ��:%d ��   ", peo[j].alltime);
			printf("˳��:%d \n", j + 1);
		}
	}
}


//�鿴����********************************************************************************
void chakan(struct people peo[M])
{
	int i = 0;
	char xh[25];//ͨ����Ų�����Ѻ��Ա��Ϣ
	system("cls");
	if (count == 0)
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ\n");
		return;
	}
	else
	{
		printf("����������Ҫ�鿴����Ѻ��Ա���(4λ����)\n");
		scanf("%s", &xh);
		fflush(stdin);//������뻺����
		int j = 0;
		for (i = 0; i < count; i++)
		{
			if (strcmp(peo[i].num, xh) == 0)//�жϴ�С�Ƿ���� 
			{
				printf("���:%s  ", peo[i].num);
				printf("����:%s  ", peo[i].name);
				if (peo[i].xingbie == 1)
					printf("��  ");
				else if (peo[i].xingbie == 2)
					printf("Ů  ");
				printf("��ʼʱ��:%d  ", peo[i].starttime);
				printf("����ʱ��:%d  ", peo[i].endtime);
				printf("ʱ��:%d ", peo[i].alltime);
				j = 1;
				fflush(stdin);//������뻺����
				//�ڲ鿴������Ѻ��Ա��Ϣʱ�����Կ���ʱ������
				int a, b, c = i;
				for (a = 0; a < count; a++)    //ð������
				{
					for (b = a + 1; b < count; b++)
					{
						if (peo[b].alltime > peo[a].alltime)
						{
							t = peo[b];
							peo[b] = peo[a];
							peo[a] = t;
						}
					}
				}
				int d = 1;
				for (a = 0; a < count; a++)
				{
					if (peo[c].alltime < peo[a].alltime)
						d++;
					else
						break;
				}
				printf("ʱ������:%d\n", d);
			}
		}
		if (j == 0)//�ж��Ƿ�����Ѻ��Ա��Ϣ 
			printf("û�������鿴����Ѻ��Ա��Ϣ\n");
	}
}


//�޸���Ϣ����****************************************************************************
void gai(struct people peo[M])
{
	int j;
	char xh[25];
	system("cls");//������� 
	if (count == 0)//�ж��Ƿ�����Ѻ��Ա��Ϣ 
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ\n");
		return;
	}
	else
	{
		printf("�޸ĵ���Ѻ��Ա���Ϊ:\n");
		scanf("%s", &xh);
		fflush(stdin);//������뻺����
		for (j = 0; j < count; j++)
			if (strcmp(peo[j].num, xh) == 0)
			{
				printf("�޸���Ѻ��Ա��Ϣ\n");
				printf("�����µĽ���ʱ��:\n");
				scanf("%d", &peo[j].endtime);
				peo[j].alltime = peo[j].endtime - peo[j].starttime;
				int i;
				printf("�����µ��η����:\n");
				scanf("%d", &i);
				char t[30];
				strcpy(t, peo[i].fang);
				strcpy(peo[i].fang, peo[j].name);
				strcpy(peo[j].fang, t);
			}
	}
}


//�Զ���ɾ������**************************************************************************
void del(struct people peo[M])
{
	int choice;
	system("cls");//������� 
	if (count == 0)
	{
		printf("Ŀǰû����Ѻ��Ա��Ϣ\n");
		return;
	}
	else
	{
		printf("��ѡ������Ҫɾ���ķ�ʽ:1����� 2������ 3��ȡ��\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 3:return; break;
		case 2:name_(peo); break;
		case 1:num_(peo); break;
		default:printf("�����������������\n"); break;
		}
	}
}


//ͨ�����ɾ����Ѻ��Ա��Ϣ����************************************************************
void num_(struct people peo[M])
{
	int j, index = 0, k = count;
	char xh[25];
	system("cls");//������� 
	printf("��Ҫɾ������Ѻ��Ա���Ϊ��\n");
	scanf("%s", xh);
	fflush(stdin);//������뻺����
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].num, xh) == 0)
		{
			strcpy(peo[j].fang, "��");
			for (j = index; j < count; j++)
				peo[j] = peo[j + 1];
			count--;
			if (count < k)
				printf("ɾ���ɹ�\n");
		}
		index++;
	}
	if (j == count)
		printf("û������Ҫɾ������Ѻ��Ա����Ϣ\n");
}


//ͨ��������ʽɾ����Ѻ��Ա��Ϣ����********************************************************
void name_(struct people peo[M])
{
	int flag = 0, j, k = count;
	char xm[25];
	system("cls");//������� 
	printf("��Ҫɾ������Ѻ��Ա����Ϊ��\n");
	scanf("%s", xm);
	fflush(stdin);//������뻺����
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].name, xm) == 0)
		{
			strcpy(peo[j].fang, "��");
			for (j = flag - 1; j < count; j++)
				peo[j] = peo[j + 1];
			count--;
			if (count < k)
				printf("ɾ���ɹ�\n");
		}
		flag++;
	}
	if (j == count)
		printf("û������Ҫɾ������Ѻ��Ա����Ϣ\n");
}


//������********************************************************************************
void order(struct people peo[M])
{
	int j, choice, i;
	system("cls");//������� 
	printf("����������Ҫ��������ķ�ʽ(��������ķ�ʽ���ǽ���)!!!\n");
	printf("1������ʱ�� 2��ʱ�� 3����� 4���Ա�\n");
	scanf("%d", &choice);
	//���¶�ʹ��ð������
	switch (choice)
	{
	case 1:for (i = 0; i < count; i++)   //����ʱ����������-->�ͣ�
	{
		for (j = i + 1; j < count; j++)
		{
			if (peo[j].endtime > peo[i].endtime)
			{
				t = peo[j];
				peo[j] = peo[i];
				peo[i] = t;
			}
		}
	}; break;
	case 2:for (i = 0; i < count; i++) //��ʱ����������-->�ͣ�
	{
		for (j = i + 1; j < count; j++)
		{
			if (peo[j].alltime > peo[i].alltime)
			{
				t = peo[j];
				peo[j] = peo[i];
				peo[i] = t;
			}
		}
	}
		   break;
	case 3:for (i = 0; i < count; i++) //�������(С����)
	{
		for (j = i + 1; j < count; j++)
		{
			if (strcmp(peo[j].num, peo[i].num) < 0)
			{
				t = peo[j];
				peo[j] = peo[i];
				peo[i] = t;
			}
		}
	}
		   break;
	case 4:for (i = 0; i < count; i++) //�Ա�����(С����) 
	{
		for (j = i + 1; j < count; j++)
		{
			if (peo[j].xingbie < peo[i].xingbie)
			{
				t = peo[j];
				peo[j] = peo[i];
				peo[i] = t;
			}
		}
	}
		   break;
	default:printf("����������\n"); break;
	}
}