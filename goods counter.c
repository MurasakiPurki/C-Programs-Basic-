#define _CRT_SECURE_NO_WARNINGS//scanf오류
#include <stdio.h>//입출력함수
#include <conio.h>//getch() 사용 위해 선언
#include <stdlib.h>//문자열끼리 비교, rand() 사용하기위해 선언
#include <Windows.h>//윈도우 콘솔 명령어를 사용하기위해 선언
#include <time.h>//난수를 사용하기위해 선언

char id[100];//입력받은 이름을 저장할 변수
int password;//입력받은 비밀번호를 저장할 변수

struct goods//물품 목록을 구조체로 저장
{
	int prize[5];//물품 목록에서 가격을 담을 변수
	char name[5][20];//물품 목록에서 이름을 담을 변수
	char code[5];//물품 목록에서 코드를 담을 변수
	int remain[5];//물품 목록에서 잔고를 담을 변수
};

void clear()//한번클릭후 화면 청소
{
	getch();//아무 자판을 입력하면 넘어가는 입력함수
	system("cls");//cmd의 명령어 cls실행으로 화면 정리
}

void signup()//회원가입
{
	int passcheck;//입력받은 비밀번호 재입력시 비교하기 위한 변수
	while (1) 
	{
		printf("\n 이름을 입력해 주세요> ");
		scanf("%s", &id);
		printf("\n 비밀번호 4자리를 입력해 주세요> ");
		scanf("%d", &password);
		printf("\n 비밀번호 4자리를 한번더 입력해 주세요> ");
		scanf("%d", &passcheck);
		if (password == passcheck)//입력과 재입력받은것 비교
		{
			printf("\n 회원가입이 완료되었습니다.\n");
			clear();
			break;
		}
		else
		{
			printf("\n 잘못 입력하셨습니다. 다시 입력해주세요.");
			clear();
		}
	}
}

void login()//로그인
{
	char typedid[100];//입력받은 이름
	int typedpassword;//입력받은 비밀번호
	
	while (1)//아이디와 비밀번호가 맞게 입력될때까지 반복
	{
		printf("\n 이름을 입력해 주세요> ");
		scanf("%s", &typedid);
		printf("\n 비밀번호 4자리를 입력해 주세요> ");
		scanf("%d", &typedpassword);
		if (strcmp(typedid, id) == 0 && password == typedpassword)//입력받은 이름과 비밀번호가 맞는지 비교
		{
			printf("\n 성공적으로 로그인 되었습니다.\n");
			clear();
			break;
		}
		else
		{
			printf("\n 아이디 또는 비밀번호가 틀렸습니다.\n");
			clear();
		}
	}
}

int sell(int money, int o)//구매
{
	system("cls");
	srand((unsigned int)time(0));//난수를 사용하기위해 시간을 받아 srand에 입력
	int random = rand() % (50 - 40 + 1);//난수를 사용하기위해 변수에 rand()선언
	int i;//for문용
	char yn;//y,n을 입력받을 변수
	static struct goods s1 = { .prize = { 5000,1000,15000,35000,4000 },
							   .name = { "캔뱃지","엽서","일러스트북","보조배터리","스티커" },
							   .code = { 'a','b','c','d','e' },
							   .remain = {30, 200, 5, 3, 50 }};//상품목록 구조체 선언
	
	while (1)//y/n에서 알맞는 문자가 입력될때까지 반복
	{
		if (s1.remain[o] <= 0)//잔고가 없을때
		{
			printf("\n 그 제품은 매진되었습니다 죄송합니다.\n");
			clear();
			return 1;
		}
		if (s1.prize[o] > money)//낼 돈이 가격보다 작을때
		{
			printf("\n 돈이 부족합니다. 금액을 확인해 주세요.\n");
			clear();
			return 1;
		}
		else if (s1.prize[o] <= money)//낼 돈이 가격보다 크거나 같을때
		{
			printf("\n 구매를 하시겠습니까? y/n\n");
			printf(" > ");
			scanf(" %c", &yn);
			if (yn == 'y')//y/n에서 y입력
			{
				printf(" ");
				for (i = 0; i <= random; i++) {//로딩창 구현
					printf("│");
					Sleep(200);
					printf("\b／");
					Sleep(200);
					printf("\b\b─");
					Sleep(200);
					printf("\b＼\b\b");
					Sleep(200);
				}
				system("cls");
				printf("\n 거래가 완료되었습니다.\n");
				if (s1.prize[o] < money)//낼 돈이 가격보다 클때
				{
					printf("\n 거스름돈은 %d원입니다.\n", money - s1.prize[o]);
					clear();
				}
				s1.remain[o]--;//잔고 -1
				return 0;
			}
			else if (yn == 'n')//y/n에서 n입력
			{
				printf("\n 거래가 취소되었습니다.\n");
				clear();
				return 2;
			}
			else//y,n제외 다른글자 입력시
			{
				printf("\n 잘못 입력하셨습니다. 다시 입력해주세요.");
				clear();
				continue;
			}
		}
	}
}

int main()
{
	time_t t = time(NULL);//시간 표시를 위한 시간변수 선언
	struct tm tm = *localtime(&t);//시간 표시를 위한 구조체 선언
	struct goods s1 = { .prize = { 5000,1000,15000,35000,4000 },
						.name = { "캔뱃지","엽서","일러스트북","보조배터리","스티커" },
						.code = { 'a','b','c','d','e' },
						.remain = {30, 200, 5, 3, 50 }};//상품목록 구조체 선언
	
	int i = 0;//상품품목리스트의 배열의 번호를 담는 변수
	int returned = 0; //코드에서 결과를 출력할때 
	int money = 0; //입력받은 낼 돈을 담는 변수
	int selector = 0; //switch문에서 case를 가리킬 변수
	char wantbuy; //사고싶은 물품의 code를 담는 변수
	
	while (1)//회원가입, 로그인선택지 출력, 잘못 입력받을경우 clear 실행후 다시 반복
	{
		printf("┌------------------------┐ \n");
		printf("│                        │ \n");
		printf("│       1. 회원가입      │ \n");
		printf("│                        │ \n");
		printf("│       2. 로그인        │ \n");
		printf("│                        │ \n");
		printf("└------------------------┘ \n");
		printf(" > ");
		scanf("%d", &selector);
		switch (selector)//스위치문으로 원하는 코드 실행
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
			printf("\n 잘못 입력하셨습니다. 다시 입력해주세요.");
			clear();
			continue;
		}
		break;
	}
	
	while (1)//구매할 상품의 코드와 낼 돈을 입력하는곳, 잘못 입력받을경우 clear 실행후 다시 반복
	{
		taecho://goto문에 쓸 지점
		system("cls");
		printf("                 상품 리스트\n\n");
		printf(" 코드          이름          가격             잔고\n");
		for (i = 0; i < 5; i++)//배열로 저장되어있는 상품목록 출력
		{
			printf("\n  %c      %10s  %10d원 %10d개남음\n", s1.code[i], s1.name[i], s1.prize[i], s1.remain[i]);
		}
		printf("\n 구매하고싶은 상품의 코드를 입력하세요> ");
		scanf(" %c", &wantbuy);
		for (i = 0; i < 5; i++)//입력받은 상품의 코드와 상품목록 대조하여 맞을경우 retured변수를 1로 초기화
		{
			if (s1.code[i] == wantbuy)
			{
				returned = 1;
				break;
			}
		}
		if (returned == 1)//코드가 맞게 입력됬을경우
		{
			printf("\n 내실 돈의 금액을 입력해주세요> ");
			scanf("%d", &money);
			returned = sell(money, i);//return된값을 returned에 저장 
			if (returned == 1)
			{
				continue;//1일경우 실행 실패이므로 다시 초기화면으로 돌아감
			}
			else
			{
				if (returned == 0)
				{
					s1.remain[i]--;
					FILE *fp = fopen("receipt.txt", "a");//하위디렉토리에 receipt.txt파일 추가용으로 열기
					fprintf(fp, "%d/%d/%d %d:%d:%d\n이름 : %s\n비밀번호 : %d\n상품명 : %s\n내신돈 : %d\n거스름돈 : %d\n\n", //영수증에 들어갈것들 입력
					tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, id, password, s1.name[i], money, money - s1.prize[i]);
					fclose;
				}
				
				while (1)
				{
					printf("┌------------------------┐ \n");
					printf("│                        │ \n");
					printf("│    1. 다른상품 구매    │ \n");
					printf("│                        │ \n");
					printf("│    2. 프로그램 종료    │ \n");
					printf("│                        │ \n");
					printf("└------------------------┘ \n"); 
					printf(" > ");
					selector = 0;
					scanf("%d", &selector);
					switch (selector)//1누를시 처음 위치 지정한곳으로 이동 2일시 프로그램 종료
					{
					case 1:
						goto taecho;
					case 2:
						return 0;
					default:
						printf("\n 잘못 선택하셨습니다.\n");
						clear();
						continue;
					}
				}
			}
		}
		else//코드가 잘못 입력됬을경우
		{
			returned = 0;
			printf("\n 잘못 선택하셨습니다, 다시 입력해주세요.");
			clear();
			continue;
		}
	}
}