#define _CRT_SECURE_NO_WARNINGS//scanf����
#include <stdio.h>//������Լ�
#include <conio.h>//getch() ��� ���� ����
#include <stdlib.h>//���ڿ����� ��, rand() ����ϱ����� ����
#include <Windows.h>//������ �ܼ� ��ɾ ����ϱ����� ����
#include <time.h>//������ ����ϱ����� ����

char id[100];//�Է¹��� �̸��� ������ ����
int password;//�Է¹��� ��й�ȣ�� ������ ����

struct goods//��ǰ ����� ����ü�� ����
{
	int prize[5];//��ǰ ��Ͽ��� ������ ���� ����
	char name[5][20];//��ǰ ��Ͽ��� �̸��� ���� ����
	char code[5];//��ǰ ��Ͽ��� �ڵ带 ���� ����
	int remain[5];//��ǰ ��Ͽ��� �ܰ� ���� ����
};

void clear()//�ѹ�Ŭ���� ȭ�� û��
{
	getch();//�ƹ� ������ �Է��ϸ� �Ѿ�� �Է��Լ�
	system("cls");//cmd�� ��ɾ� cls�������� ȭ�� ����
}

void signup()//ȸ������
{
	int passcheck;//�Է¹��� ��й�ȣ ���Է½� ���ϱ� ���� ����
	while (1) 
	{
		printf("\n �̸��� �Է��� �ּ���> ");
		scanf("%s", &id);
		printf("\n ��й�ȣ 4�ڸ��� �Է��� �ּ���> ");
		scanf("%d", &password);
		printf("\n ��й�ȣ 4�ڸ��� �ѹ��� �Է��� �ּ���> ");
		scanf("%d", &passcheck);
		if (password == passcheck)//�Է°� ���Է¹����� ��
		{
			printf("\n ȸ�������� �Ϸ�Ǿ����ϴ�.\n");
			clear();
			break;
		}
		else
		{
			printf("\n �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
			clear();
		}
	}
}

void login()//�α���
{
	char typedid[100];//�Է¹��� �̸�
	int typedpassword;//�Է¹��� ��й�ȣ
	
	while (1)//���̵�� ��й�ȣ�� �°� �Էµɶ����� �ݺ�
	{
		printf("\n �̸��� �Է��� �ּ���> ");
		scanf("%s", &typedid);
		printf("\n ��й�ȣ 4�ڸ��� �Է��� �ּ���> ");
		scanf("%d", &typedpassword);
		if (strcmp(typedid, id) == 0 && password == typedpassword)//�Է¹��� �̸��� ��й�ȣ�� �´��� ��
		{
			printf("\n ���������� �α��� �Ǿ����ϴ�.\n");
			clear();
			break;
		}
		else
		{
			printf("\n ���̵� �Ǵ� ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n");
			clear();
		}
	}
}

int sell(int money, int o)//����
{
	system("cls");
	srand((unsigned int)time(0));//������ ����ϱ����� �ð��� �޾� srand�� �Է�
	int random = rand() % (50 - 40 + 1);//������ ����ϱ����� ������ rand()����
	int i;//for����
	char yn;//y,n�� �Է¹��� ����
	static struct goods s1 = { .prize = { 5000,1000,15000,35000,4000 },
							   .name = { "ĵ����","����","�Ϸ���Ʈ��","�������͸�","��ƼĿ" },
							   .code = { 'a','b','c','d','e' },
							   .remain = {30, 200, 5, 3, 50 }};//��ǰ��� ����ü ����
	
	while (1)//y/n���� �˸´� ���ڰ� �Էµɶ����� �ݺ�
	{
		if (s1.remain[o] <= 0)//�ܰ� ������
		{
			printf("\n �� ��ǰ�� �����Ǿ����ϴ� �˼��մϴ�.\n");
			clear();
			return 1;
		}
		if (s1.prize[o] > money)//�� ���� ���ݺ��� ������
		{
			printf("\n ���� �����մϴ�. �ݾ��� Ȯ���� �ּ���.\n");
			clear();
			return 1;
		}
		else if (s1.prize[o] <= money)//�� ���� ���ݺ��� ũ�ų� ������
		{
			printf("\n ���Ÿ� �Ͻðڽ��ϱ�? y/n\n");
			printf(" > ");
			scanf(" %c", &yn);
			if (yn == 'y')//y/n���� y�Է�
			{
				printf(" ");
				for (i = 0; i <= random; i++) {//�ε�â ����
					printf("��");
					Sleep(200);
					printf("\b��");
					Sleep(200);
					printf("\b\b��");
					Sleep(200);
					printf("\b��\b\b");
					Sleep(200);
				}
				system("cls");
				printf("\n �ŷ��� �Ϸ�Ǿ����ϴ�.\n");
				if (s1.prize[o] < money)//�� ���� ���ݺ��� Ŭ��
				{
					printf("\n �Ž������� %d���Դϴ�.\n", money - s1.prize[o]);
					clear();
				}
				s1.remain[o]--;//�ܰ� -1
				return 0;
			}
			else if (yn == 'n')//y/n���� n�Է�
			{
				printf("\n �ŷ��� ��ҵǾ����ϴ�.\n");
				clear();
				return 2;
			}
			else//y,n���� �ٸ����� �Է½�
			{
				printf("\n �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
				clear();
				continue;
			}
		}
	}
}

int main()
{
	time_t t = time(NULL);//�ð� ǥ�ø� ���� �ð����� ����
	struct tm tm = *localtime(&t);//�ð� ǥ�ø� ���� ����ü ����
	struct goods s1 = { .prize = { 5000,1000,15000,35000,4000 },
						.name = { "ĵ����","����","�Ϸ���Ʈ��","�������͸�","��ƼĿ" },
						.code = { 'a','b','c','d','e' },
						.remain = {30, 200, 5, 3, 50 }};//��ǰ��� ����ü ����
	
	int i = 0;//��ǰǰ�񸮽�Ʈ�� �迭�� ��ȣ�� ��� ����
	int returned = 0; //�ڵ忡�� ����� ����Ҷ� 
	int money = 0; //�Է¹��� �� ���� ��� ����
	int selector = 0; //switch������ case�� ����ų ����
	char wantbuy; //������ ��ǰ�� code�� ��� ����
	
	while (1)//ȸ������, �α��μ����� ���, �߸� �Է¹������ clear ������ �ٽ� �ݺ�
	{
		printf("��------------------------�� \n");
		printf("��                        �� \n");
		printf("��       1. ȸ������      �� \n");
		printf("��                        �� \n");
		printf("��       2. �α���        �� \n");
		printf("��                        �� \n");
		printf("��------------------------�� \n");
		printf(" > ");
		scanf("%d", &selector);
		switch (selector)//����ġ������ ���ϴ� �ڵ� ����
		{
		case 1:
			system("cls");
			signup();
			continue;
		case 2:
			system("cls");
			login();
			break;
		default:
			printf("\n �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
			clear();
			continue;
		}
		break;
	}
	
	while (1)//������ ��ǰ�� �ڵ�� �� ���� �Է��ϴ°�, �߸� �Է¹������ clear ������ �ٽ� �ݺ�
	{
		taecho://goto���� �� ����
		system("cls");
		printf("                 ��ǰ ����Ʈ\n\n");
		printf(" �ڵ�          �̸�          ����             �ܰ�\n");
		for (i = 0; i < 5; i++)//�迭�� ����Ǿ��ִ� ��ǰ��� ���
		{
			printf("\n  %c      %10s  %10d�� %10d������\n", s1.code[i], s1.name[i], s1.prize[i], s1.remain[i]);
		}
		printf("\n �����ϰ���� ��ǰ�� �ڵ带 �Է��ϼ���> ");
		scanf(" %c", &wantbuy);
		for (i = 0; i < 5; i++)//�Է¹��� ��ǰ�� �ڵ�� ��ǰ��� �����Ͽ� ������� retured������ 1�� �ʱ�ȭ
		{
			if (s1.code[i] == wantbuy)
			{
				returned = 1;
				break;
			}
		}
		if (returned == 1)//�ڵ尡 �°� �Է������
		{
			printf("\n ���� ���� �ݾ��� �Է����ּ���> ");
			scanf("%d", &money);
			returned = sell(money, i);//return�Ȱ��� returned�� ���� 
			if (returned == 1)
			{
				continue;//1�ϰ�� ���� �����̹Ƿ� �ٽ� �ʱ�ȭ������ ���ư�
			}
			else
			{
				if (returned == 0)
				{
					s1.remain[i]--;
					FILE *fp = fopen("receipt.txt", "a");//�������丮�� receipt.txt���� �߰������� ����
					fprintf(fp, "%d/%d/%d %d:%d:%d\n�̸� : %s\n��й�ȣ : %d\n��ǰ�� : %s\n���ŵ� : %d\n�Ž����� : %d\n\n", //�������� ���͵� �Է�
					tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, id, password, s1.name[i], money, money - s1.prize[i]);
					fclose;
				}
				
				while (1)
				{
					printf("��------------------------�� \n");
					printf("��                        �� \n");
					printf("��    1. �ٸ���ǰ ����    �� \n");
					printf("��                        �� \n");
					printf("��    2. ���α׷� ����    �� \n");
					printf("��                        �� \n");
					printf("��------------------------�� \n"); 
					printf(" > ");
					selector = 0;
					scanf("%d", &selector);
					switch (selector)//1������ ó�� ��ġ �����Ѱ����� �̵� 2�Ͻ� ���α׷� ����
					{
					case 1:
						goto taecho;
					case 2:
						return 0;
					default:
						printf("\n �߸� �����ϼ̽��ϴ�.\n");
						clear();
						continue;
					}
				}
			}
		}
		else//�ڵ尡 �߸� �Է������
		{
			returned = 0;
			printf("\n �߸� �����ϼ̽��ϴ�, �ٽ� �Է����ּ���.");
			clear();
			continue;
		}
	}
}