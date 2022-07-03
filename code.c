//监狱管理系统
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define M 1000
//结构体**********************************************************************************
struct people
{
	char name[30];// 姓名！
	char fang[30];//牢房姓名！
	char num[30];//编号！
	int xingbie;//性别！
	int starttime;//羁押开始时间 ！
	int endtime;//羁押结束时间！
	int alltime;// 羁押时长！ 
	int shengyu;//剩余时长！
	int time;//时间！
	int time_true_id;//时间是否设置校验值
	int peo_true_id;//是否有人校验值
};
void color(short x)	//自定义函根据参数改变颜色***********************************************
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
	else//默认的颜色白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//函数声明********************************************************************************
void fileread(struct people peo[M]);//*读取文件函数 
void filesave(struct people peo[M]);//*保存文件函数 
void input(struct people peo[M]);//****输入数据函数 
void output(struct people peo[M]);//***输出函数 
void del(struct people peo[M]);//******删除信息函数 （1 、2） 
void gai(struct people peo[M]);//******改信息函数 
void chakan(struct people peo[M]);//**查询信息函数 
void name_(struct people peo[M]);//****使用姓名删其信息 1 
void num_(struct people peo[M]);//*****使用编号删其信息 2
void xingname_(struct people peo[M]);//****使用姓名加其刑 1 
void xingnum_(struct people peo[M]);//*****使用编号加其刑 2
void order(struct people peo[M]);//****进行排序函数
void time(struct people peo[M]);//输入时间
void addxing(struct people peo[M]);//加刑
void shengyu0(struct people peo[M]);//今日出狱
void shengyu7(struct people peo[M]);//七日出狱
void shengyu30(struct people peo[M]);//三十日出狱
//****************************************************************************************

int count = 0;//输入信息的个数，一开始为零
struct people t;
//这个t是进行order排序时用的 
//****************************************************************************************


//主函数**********************************************************************************
int main()
{
	int key;//设置密码！
	do//密码模块
	{
		color(7);
		printf_s("请输入系统密码\n");
		color(0);
		scanf_s("%d", &key);
		system("cls");
	} while (key != 5216120);

	int sum = 0, xuanze;//xuanze一开始进入界面进行选择
	system("mode con: cols=200 lines=200"); //控制编译器高和宽 
	struct people peo[M];
	int j = 0;
	for (j; j < 999; j++)
	{
		strcpy(peo[j].fang, "无");
	}
	system("cls");//清屏
	//**********代码运行界面********
	color(7);
	do {
		printf_s("\n");
		printf_s("\n");
		printf_s("|-----------------------------------------------------|   |------------------------------------------------------|   |------------------------------------------------------|\n");
		printf_s("|-----------------------------------------------------|   |------------------ 牢 房 实 时 监 控 -----------------|   |------------------------------------------------------|\n");
		printf_s("|                                                     |   |------------------------------------------------------|   |                                                      |\n");
		printf_s("|*                 监 狱 管 理 系 统                 *|   |----------|----------|----------|----------|----------|   |         ****       监  狱  守  则        ****        |\n");
		if (peo[999].time_true_id == 1) {
			int nian, yue, ri;
			nian = peo[999].time / 10000;
			yue = (peo[999].time % 10000) / 100;
			ri = peo[999].time % 100;
			printf_s("|              当前时间：%4d年%2d月%2d日               |   |   0号    |   1号    |   2号    |   3号    |   4号    |   |                                                      |\n", nian, yue, ri);
		}
		else {
			printf_s("|                   当前时间：未设置                  |   |   0号    |   1号    |   2号    |   3号    |   4号    |   |                                                      |\n");
		}

		printf_s("|******************法网恢恢*疏而不漏******************|   | %-9s| %-9s| %-9s| %-9s| %-9s|   |------------------------------------------------------|\n", peo[0].fang, peo[1].fang, peo[2].fang, peo[3].fang, peo[4].fang);
		printf_s("|-----------------------------------------------------|   |          |          |          |          |          |   |                                                      |\n");
		printf_s("|                                                     |   |----------|----------|----------|----------|----------|   |    第一条 拥护宪法，遵守法律法规规章和监规纪律。     |\n");
		printf_s("| 【在 监 人 员】  1 - 创建    2 - 查看    3 - 查询   |   |   5号    |   6号    |   7号    |   8号    |   9号    |   |                                                      |\n");
		printf_s("|                                                     |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |    第二条 服从管理，接受教育，参加劳动，认罪悔罪。   |\n", peo[5].fang, peo[6].fang, peo[7].fang, peo[8].fang, peo[9].fang);
		printf_s("|                  4 - 修改    5 - 删除    6 - 排序   |   |          |          |          |          |          |   |                                                      |\n");
		printf_s("|                                                     |   |----------|----------|----------|----------|----------|   |    第三条 爱祖国，爱人民，爱集体，爱学习，爱劳动。   |\n");
		printf_s("| 【文 件 操 作】  7 - 读取    8 - 保存               |   |   10号   |   11号   |   12号   |   13号   |   14号   |   |                                                      |\n");
		printf_s("|                                                     |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |    第四条 明礼诚信，互助友善，勤俭自强。             |\n", peo[10].fang, peo[11].fang, peo[12].fang, peo[13].fang, peo[14].fang);
		printf_s("| 【出 狱 查 询】  9 - 今日    10- 七日    11- 三十日 |   |          |          |          |          |          |   |                                                      |\n");
		printf_s("|                                                     |   |----------|----------|----------|----------|----------|   |    第五条 依法行使权利，采用正当方式和程序维护个人   |\n");
		printf_s("| 【【加 刑】】    12- 加刑                           |   |   15号   |   16号   |   17号   |   18号   |   19号   |   |           合法权益。                                 |\n");
		printf_s("|                                                     |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |                                                      |\n", peo[15].fang, peo[16].fang, peo[17].fang, peo[18].fang, peo[19].fang);
		printf_s("|-----------------------------------------------------|   |          |          |          |          |          |   |    第六条 服刑期间严格遵守纪律。                     |\n");
		printf_s("|        13-设置时间                 14-清屏          |   |----------|----------|----------|----------|----------|   |                                                      |\n");
		printf_s("|-----------------------------------------------------|   |   20号   |   21号   |   22号   |   23号   |   24号   |   |                  好好改造，重新做人                  | \n");
		printf_s("|                    【  0-退出  】                   |   | %-9s| %-9s| %-9s| %-9s| %-9s|   |                                                      |\n", peo[20].fang, peo[21].fang, peo[22].fang, peo[23].fang, peo[24].fang);
		printf_s("|                     版本 V 1.1.0                    |   |          |          |          |          |          |   |------------------------------------------------------|\n");
		printf_s("|-----------------------------------------------------|   |----------|----------|----------|----------|----------|   |------------------------------------------------------|\n");
		printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf_s("|                                                                            版权所有 侵权必究                                                                              |\n");
		printf_s("|                                                                   Copyright infringement 05216120 秦睿桢                                                                  |\n");
		printf_s("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf_s("\n");
		printf_s("请输入你的选择:\n");
		scanf("%d", &xuanze); //进行选择功能 
		fflush(stdin);       //清除输入缓冲区
		if (xuanze > 13 || xuanze <= 0)
		{
			sum++;
			if (sum >= 13)
			{
				printf("输入错误次数过13次,程序将重新开始\n");
				//通过限制错误输入，避免进入死胡同 
				system("pause");        //程序暂停，重新选择 
				system("cls");   //清屏语句
			}
		}
		switch (xuanze)       //根据选择，调用不同的函数来完成不同的任务
		{
		case 1:input(peo); break;   //输入 
		case 2:output(peo); break;  //输出 
		case 3:chakan(peo); break;  //查询 
		case 4:gai(peo); break;     //修改 
		case 5:del(peo); break;     //删除
		case 6:order(peo); break;   //排序 
		case 7:fileread(peo); break;//读取文件数据 
		case 8:filesave(peo); break;//保存文件数据
		case 9:shengyu0(peo); break;//剩余0天出狱
		case 10:shengyu7(peo); break;//剩余7天出狱
		case 11:shengyu30(peo); break;//剩余30天出狱
		case 12:addxing(peo); break;//加刑
		case 13:time(peo); break;//保存文件数据
		case 14:system("cls"); break;//清屏
		case 0:printf("使用完毕，请关掉程序\n"); system("pause"); break;
		default:system("cls"); break;
		}
	} while (xuanze != 0);
	printf("本程序结束 over\n");
	return 0;
}


//设置时间********************************************************************************
void time(struct people peo[M])
{
	system("cls");//清屏语句
	printf_s("请输入当前时间\n");
	scanf_s("%d", &peo[999].time);
	system("cls");//清屏语句
	printf_s("已设置\n");
	peo[999].time_true_id = 1;
}



//加刑************************************************************************************
void addxing(struct people peo[M])
{
	int choice;
	system("cls");//清屏语句 
	if (count == 0)
	{
		printf("目前没有在押人员信息\n");
		return;
	}
	else
	{
		printf("请选择你所要加刑的方式:1、编号 2、姓名 3、取消\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 3:return; break;
		case 2:xingname_(peo); break;
		case 1:xingnum_(peo); break;
		default:printf("，输入错误，重新输入\n"); break;
		}

	}

}
void xingname_(struct people peo[M])//使用姓名加其刑
{
	int k = 0, j, day;
	char xm[25];
	system("cls");//清屏语句 
	printf("所要加其刑的在押人员姓名为：\n");
	scanf("%s", xm);
	fflush(stdin);//清除输入缓冲区
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].name, xm) == 0)
		{
			k = 1;
			printf("给%s加其刑的天数为：\n", peo[j].name);
			scanf("%d", &day);
			peo[j].endtime = peo[j].endtime + day;
			peo[j].alltime = peo[j].alltime + day;
			printf("已成功给%s加刑%d天\n", peo[j].name, day);
			printf("当前天数为：%d天\n", peo[j].alltime);
			int nian = (peo[j].endtime / 10000) + day / 365, yue = ((peo[j].endtime % 10000) / 100) + ((day % 365) / 30), ri = (peo[j].endtime % 100) + ((day % 365) % 30);
			do {
				if (ri > 30) {
					ri = ri - 30; yue = yue + 1;
				}
				if (yue > 12) {
					yue = yue - 12; nian = nian + 1;
				}
			} while (ri > 30 && yue > 12);

			printf("预计释放时间：%4d年%2d月%2d日\n", nian, yue, ri);
		}
	}
	if (k == 0)
		printf("没有你所要加刑的在押人员的信息\n");
}
void xingnum_(struct people peo[M])//使用编号加其刑
{
	int j, k = 0, day;
	char xh[25];
	system("cls");//清屏语句 
	printf("所要加其刑的在押人员编号为：\n");
	scanf("%s", xh);
	fflush(stdin);//清除输入缓冲区
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].num, xh) == 0)
		{
			k = 1;
			printf("给%s加其刑的天数为：\n", peo[j].name);
			scanf("%d", &day);
			peo[j].endtime = peo[j].endtime + day;
			peo[j].alltime = peo[j].alltime + day;
			printf("已成功给%s加刑%d天\n", peo[j].name, day);
			printf("当前天数为：%d天\n", peo[j].alltime);
			int nian = (peo[j].endtime / 10000) + day / 365, yue = ((peo[j].endtime % 10000) / 100) + ((day % 365) / 30), ri = (peo[j].endtime % 100) + ((day % 365) % 30);
			if (ri > 30) {
				ri = ri - 30; yue = yue + 1;
			}
			if (yue > 12) {
				yue = yue - 12; nian = nian + 1;
			}
			printf("预计释放时间：%4d年%2d月%2d日\n", nian, yue, ri);
		}
	}
	if (k == 0)
		printf("没有你所要加刑的在押人员的信息\n");
}


//出狱************************************************************************************
void shengyu0(struct people peo[M])//今日出狱
{
	int i = 0, j;
	system("cls");//清屏语句 
	if (count == 0)//判断是否有在押人员信息 
	{
		printf("目前没有在押人员信息\n");
		return;
	}
	else
	{
		printf("【今日】出狱的人员为:\n");
		fflush(stdin);//清除输入缓冲区
		for (j = 0; j < count; j++)
		{
			peo[j].shengyu = peo[j].endtime - peo[999].time;
			if (peo[j].shengyu == 0)
			{
				printf("%s\n", peo[j].name);
				i++;
			}
		}
		if (i == 0) printf("无");

	}
}
void shengyu7(struct people peo[M])//七日出狱
{
	int i = 0, j;
	system("cls");//清屏语句 
	if (count == 0)//判断是否有在押人员信息 
	{
		printf("目前没有在押人员信息\n");
		return;
	}
	else
	{
		printf("【七日内】出狱的人员为:\n");
		fflush(stdin);//清除输入缓冲区
		for (j = 0; j < count; j++)
		{
			peo[j].shengyu = peo[j].endtime - peo[999].time;
			if (peo[j].shengyu <= 7)
			{
				printf("%s\n", peo[j].name);
				i++;
			}
		}
		if (i == 0) printf("无");

	}
}
void shengyu30(struct people peo[M])//三十日出狱
{
	int i = 0, j;
	system("cls");//清屏语句 
	if (count == 0)//判断是否有在押人员信息 
	{
		printf("目前没有在押人员信息\n");
		return;
	}
	else
	{
		printf("【三十日内】出狱的人员为:\n");
		fflush(stdin);//清除输入缓冲区
		for (j = 0; j < count; j++)
		{
			peo[j].shengyu = peo[j].endtime - peo[999].time;
			if (peo[j].shengyu <= 30)
			{
				printf("%s\n", peo[j].name);
				i++;
			}
		}
		if (i == 0) printf("无");

	}
}



//保存文件函数****************************************************************************
void filesave(struct people peo[M])
{
	int a = 0;
	FILE* fp;
	if ((fp = fopen("D:\\QRZ\\peodata.txt", "wb")) == NULL)
	{
		printf("文件打开错误，程序无法进行\n");
		exit(0);
	}
	for (a = 0; a < 30; a++)
	{
		fwrite(&peo[a], sizeof(struct people), 1, fp);
	}
	fclose(fp);
	if (count == 0)
		printf("无在押人员信息，不能保存\n");
	else
		printf("数据已经保存 ok\n");
	system("cls");//清屏语句 
	system("pause");//系统重新开始 ，进行选择功能
	return;
}


//读取文件函数****************************************************************************
void fileread(struct people peo[M])
{
	int a = 0;
	FILE* fp;
	system("cls");//清屏语句
	if ((fp = fopen("D:\\QRZ\\peodata.txt", "rb")) == NULL)
	{
		printf("文件打开错误，程序不能进行\n");
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
	printf("数据读取完毕!!!\n");
	count = 0;
	for (int i = 0; i < 30; i++)
	{ 
		if (peo[i].peo_true_id == 1)
		{
			count++;
		}
	}
	printf("%d", count);
	system("cls");//清屏语句 
	system("pause");//系统重新开始 ，进行选择功能
	return;

}


//输入函数********************************************************************************
void input(struct people peo[M])
{
	if (peo[999].time_true_id == 1)
	{
		int len;
		system("cls");//清屏语句 
		printf("请添加要输入在押人员的信息\n");
		do {
			printf("输入在押人员编号(4位数)\n");
			//do-while循环，输错时，有提示（编号为4个数字） 
			scanf("%s", &peo[count].num);
			len = strlen(peo[count].num);
		} while (len != 4);
		printf("输入在押人员的姓名\n");
		scanf("%s", peo[count].name);
		printf("输入性别代码:1男  2女 \n");
		scanf("%d", &peo[count].xingbie);
		printf("输入在押开始时间:20xx01xx \n");
		scanf("%d", &peo[count].starttime);
		do {
			printf("输入在押人员结束羁押时间\n");
			scanf("%d", &peo[count].endtime);
		} while (peo[count].endtime < peo[count].starttime);
		//判断结束时间是否比开始时间早，早则重新输入 
		peo[count].alltime = peo[count].endtime - peo[count].starttime;      //羁押时长
		peo[count].shengyu = peo[count].endtime - peo[999].time;
		strcpy(peo[count].fang, peo[count].name);
		count++;   //输入在押人员信息的个数
		peo[count].peo_true_id = 1;
	}
	else
	{
		system("cls");
		printf_s("未设置时间\n");
	}

}


//输出函数********************************************************************************
void output(struct people peo[M])
{
	int j;
	system("cls");//清屏语句 
	if (count == 0)
	{
		printf("目前没有在押人员信息记录\n");
		return;
	}
	for (j = 0; j < count; j++)
	{
		for (j = 0; j < count; j++)
		{       //for循环控制输出的个数
			printf("编号:%s  ", peo[j].num);
			printf("姓名:%s  ", peo[j].name);
			if (peo[j].xingbie == 1)
				printf("男  ");
			else if (peo[j].xingbie == 2)
				printf("女  ");
			printf("开始时间:%d  ", peo[j].starttime);
			printf("结束时间:%d  ", peo[j].endtime);
			printf("时长:%d 天   ", peo[j].alltime);
			printf("顺序:%d \n", j + 1);
		}
	}
}


//查看函数********************************************************************************
void chakan(struct people peo[M])
{
	int i = 0;
	char xh[25];//通过编号查找在押人员信息
	system("cls");
	if (count == 0)
	{
		printf("目前没有在押人员信息\n");
		return;
	}
	else
	{
		printf("请输入你想要查看的在押人员编号(4位数字)\n");
		scanf("%s", &xh);
		fflush(stdin);//清除输入缓冲区
		int j = 0;
		for (i = 0; i < count; i++)
		{
			if (strcmp(peo[i].num, xh) == 0)//判断大小是否相等 
			{
				printf("编号:%s  ", peo[i].num);
				printf("姓名:%s  ", peo[i].name);
				if (peo[i].xingbie == 1)
					printf("男  ");
				else if (peo[i].xingbie == 2)
					printf("女  ");
				printf("开始时间:%d  ", peo[i].starttime);
				printf("结束时间:%d  ", peo[i].endtime);
				printf("时长:%d ", peo[i].alltime);
				j = 1;
				fflush(stdin);//清除输入缓冲区
				//在查看个人在押人员信息时，可以看到时长排名
				int a, b, c = i;
				for (a = 0; a < count; a++)    //冒泡排序
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
				printf("时长排名:%d\n", d);
			}
		}
		if (j == 0)//判断是否有在押人员信息 
			printf("没有你所查看的在押人员信息\n");
	}
}


//修改信息函数****************************************************************************
void gai(struct people peo[M])
{
	int j;
	char xh[25];
	system("cls");//清屏语句 
	if (count == 0)//判断是否有在押人员信息 
	{
		printf("目前没有在押人员信息\n");
		return;
	}
	else
	{
		printf("修改的在押人员编号为:\n");
		scanf("%s", &xh);
		fflush(stdin);//清除输入缓冲区
		for (j = 0; j < count; j++)
			if (strcmp(peo[j].num, xh) == 0)
			{
				printf("修改在押人员信息\n");
				printf("输入新的结束时间:\n");
				scanf("%d", &peo[j].endtime);
				peo[j].alltime = peo[j].endtime - peo[j].starttime;
				int i;
				printf("输入新的牢房编号:\n");
				scanf("%d", &i);
				char t[30];
				strcpy(t, peo[i].fang);
				strcpy(peo[i].fang, peo[j].name);
				strcpy(peo[j].fang, t);
			}
	}
}


//自定义删除函数**************************************************************************
void del(struct people peo[M])
{
	int choice;
	system("cls");//清屏语句 
	if (count == 0)
	{
		printf("目前没有在押人员信息\n");
		return;
	}
	else
	{
		printf("请选择你所要删除的方式:1、编号 2、姓名 3、取消\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 3:return; break;
		case 2:name_(peo); break;
		case 1:num_(peo); break;
		default:printf("，输入错误，重新输入\n"); break;
		}
	}
}


//通过编号删除在押人员信息函数************************************************************
void num_(struct people peo[M])
{
	int j, index = 0, k = count;
	char xh[25];
	system("cls");//清屏语句 
	printf("所要删除的在押人员编号为：\n");
	scanf("%s", xh);
	fflush(stdin);//清除输入缓冲区
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].num, xh) == 0)
		{
			strcpy(peo[j].fang, "无");
			for (j = index; j < count; j++)
				peo[j] = peo[j + 1];
			count--;
			if (count < k)
				printf("删除成功\n");
		}
		index++;
	}
	if (j == count)
		printf("没有你所要删除的在押人员的信息\n");
}


//通过姓名方式删除在押人员信息函数********************************************************
void name_(struct people peo[M])
{
	int flag = 0, j, k = count;
	char xm[25];
	system("cls");//清屏语句 
	printf("所要删除的在押人员姓名为：\n");
	scanf("%s", xm);
	fflush(stdin);//清除输入缓冲区
	for (j = 0; j < count; j++)
	{
		if (strcmp(peo[j].name, xm) == 0)
		{
			strcpy(peo[j].fang, "无");
			for (j = flag - 1; j < count; j++)
				peo[j] = peo[j + 1];
			count--;
			if (count < k)
				printf("删除成功\n");
		}
		flag++;
	}
	if (j == count)
		printf("没有你所要删除的在押人员的信息\n");
}


//排序函数********************************************************************************
void order(struct people peo[M])
{
	int j, choice, i;
	system("cls");//清屏语句 
	printf("请输入你想要进行排序的方式(所有排序的方式均是降序)!!!\n");
	printf("1、结束时间 2、时长 3、编号 4、性别\n");
	scanf("%d", &choice);
	//以下都使用冒泡排序
	switch (choice)
	{
	case 1:for (i = 0; i < count; i++)   //结束时间排名（高-->低）
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
	case 2:for (i = 0; i < count; i++) //总时长排名（高-->低）
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
	case 3:for (i = 0; i < count; i++) //编号排名(小到大)
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
	case 4:for (i = 0; i < count; i++) //性别排名(小到大) 
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
	default:printf("请重新输入\n"); break;
	}
}