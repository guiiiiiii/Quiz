#include<stdio.h>   // 입출력
#include<conio.h>   // getch 함수
#include<windows.h>   // system 함수
#include<ctype.h>   // toupper 함수
#include<stdlib.h>   // srand
#include<time.h>   // time
#include<dos.h>      // exit


void displayscore()
{ 
	
	char name[20]; 
	float s; //점수
	int i = 0;
	FILE *f;
	system("cls");
	f = fopen("score.txt", "r");

	fscanf(f, "%s%f", &name, &s);

	for (i = 0; name[i] != '\0'; i++)
	{
		name[i] = name[i] == '_' ? ' ' : name[i];  //<== '_' 를 ' ' 변경하여 표현
	}

	printf("\n\n\t\t ");
	printf("\n\n\t\t %s has secured the Highest Score %.2f", name, s);
	printf("\n\n\t\t ");
	fclose(f);
	getch();
}


void help()
{
	system("cls");
	printf("\n\n\n\t이 게임은 당신의 유머감각을 테스트하는 퀴즈입니다 ");
	printf("\n\n\t닉네임을 입력하시면, 바로 게임이 시작됩니다");
	printf("\n\n\t총 4개의 답안 중 올바르다고 생각하는 것을 골라주세요!");
	printf("\n\n\t오랜 시간을 사용하여 해결하는 경우 불이익이 있다는 점 명시하세요!");
	printf("\n\n\t가장 높은 점수를 얻게 된다면,");
	printf("\n\n\t최고점수로 기록되는 영광을 얻으실 수 있습니다 ");
	printf("\n\n\tGood Luck!!");
}


void writescore(float score, char plnm[20])
{
	float sc;
	char nm[20];
	int i;

	FILE *f;
	system("cls");
	f = fopen("score.txt", "w");
	fscanf(f, "%s%f", &nm, &sc);			//분명히 최고점이 아닌 최근점수가 저장되는 오류가 있습니다 하지만
	if (score >= sc)						//어떻게 고쳐야할지 모르겠어요 점수를 비교해도 이름과 함께 저장해야 할텐데..
	{										//그리고 똑같이w모드로 열건데 왜 번거롭게 두번이나 열고 닫았는지 이해가 안갑니다
		sc = score;

		for (i = 0; plnm[i] != '\0'; i++)
		{
			plnm[i] = plnm[i] == ' ' ? '_' : plnm[i];  //<== ' ' 를 '_' 로변경하여 저장
		}
		fprintf(f, "%s    %.2f", plnm, score);
	}
	fclose(f);

}
int main()
{
	int countq, countr;
	int r, i, t; //시간을 점수에 포함하는 방법을 변경하기위해 변수t추가
	int pa; int nq[6]; int w;   //pa는 왜 사용?
	float score;
	char choice;
	char check;
	char playername[20];
	time_t initialtime, finaltime;
	system("cls");
	srand((unsigned)time(NULL));  // 문제를 다양화하기위해 난수 발생지점 수정
								  //randomize();

mainhome:
	system("cls");
	puts("\n\t\t WELCOME TO IDIOT WORLD\n\n");
	puts("\n\t\t-------------------------------");

	puts("\n\t\t당신은 상식이 통하지 않는 세상에 떨어졌습니다");

	puts("\n\t\t퀴즈를 풀어 이 세계를 탈출하세요!!");

	puts("\n\t\t주의: 상식이 통하지 않을 수 있음");
	puts("\n\t\t Enter 'S' to start game       ");
	puts("\n\t\t Enter 'V' to view lately score  ");
	puts("\n\t\t Enter 'H' for help            ");
	puts("\n\t\t Enter 'Q' to quit             ");
	printf("\n\t\t-------------------------------\n\n\t\t  ");
	choice = toupper(getch());   // 문자 c가 소문자일 경우 대문자로 바꿔준다. 아닐 경우 그대로 유지
	if (choice == 'V')
	{
		displayscore();
		goto mainhome;
	}
	else if (choice == 'Q')
		exit(1);
	else if (choice == 'H')
	{
		help();
		getch();
		goto mainhome;
	}
	else if (choice == 'S') {
		system("cls");

		printf("\n\n\n\t\t\t나는 IDIOT WORLD의 왕...");

		printf("\n\n\n\t\t\t내가내는 퀴즈를 맞춰야 원래 세계로 보내주겠다!\n");

		printf("\n\n\n\t\t\t이름은 까먹지 않았겠지...");
		printf("\n\t\t\t(빈칸없이 입력하거라)\n\n\t\t\t");
		gets(playername);

	home:
		system("cls");
		initialtime = time(NULL);
		countq = countr = 0;
		i = 0;
	start:
		r = rand() % 23 + 1;// 주석을 풀어 문제수를 늘리면 출제 하는 범위도 늘려야함
							
							// nq[i] = r;
							//for (w = 0; w < i; w++)
							// if (nq[w] == r) goto start;   왜하는건지 모르겠..어욥..
		switch (r)
		{
		case 1:
			system("cls");
			printf("\n\n천재 남편과 바보 아내가 결혼하면 어떤 아이를 낳을까?");
			printf("\n\nA.짱구\tB.갓난 아기\n\nC.옆집 아기\nD.코난\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'B')      //다른 알파벳을 입력하면 화면이 넘어가지않음
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 B.갓난 아기");
					break;
				}
			}
			getch();  //바로화면을 넘길 시 정답의 여부가 안보여지므로 문자 하나를 더 입력해야함
			break;
		case 2:
			system("cls");
			printf("\n\n\n할아버지가 제일 좋아하는 돈은?");
			printf("\n\nA.할머니\tB.아주머니\n\nC.아이구머니\tD.산와머니\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'A')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 A.할머니");
					break;
				}
			}
			getch();
			break;
		case 3:
			system("cls");
			printf("\n\n\n차마 눈뜨고 볼 수 없는 여자는?");
			printf("\n\nA.꿈속의 여자\tB.지나가는 여자\n\nC.아는 여자\tD.못생긴 여자\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'A')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 A.꿈속의 여자");
					break;
				}
			}

			getch();
			break;

		case 4:
			system("cls");
			printf("\n\n\n머리가 수염보다");
			printf(" 더 빨리 희어지는 이유는?");
			printf("\n\nA.신경을 많이써서\tB.간때문이야!\n\nC.머리가 20년 빨리나서\tD.글쎄..\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.머리가 20년 빨리나서");
					break;
				}
			}

			getch();
			break;
		case 5:
			system("cls");
			printf("\n\n\n세상에서 제일 더럽고 추잡스럽기 짝이 없는 개는?");
			printf("\n\nA.광견\tB.꼴불견\n\nC.꼴깝견\tD.꼴난견\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'B')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 B.꼴불견");
					break;
				}
			}

			getch();
			break;
		case 6:
			system("cls");
			printf("\n\n\n김밥이 교도소에 간 이유는?");
			printf("\n\nA.김밥이 상해 배탈나서\tB.참기름이 고소해서\n\nC.교도소에서 시켜서\tD.단무지가 없어서\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'B')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 B.참기름이 고소해서");
					break;
				}
			}

			getch();
			break;
		case 7:
			system("cls");
			printf("\n\n\n콩쥐팥쥐에서 꺠진 독을 수리해 준 사람은?");
			printf("\n\nA.독수리오형제\tB.엿장수\n\nC.옆집아저씨\tD.두꺼비\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'A')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 A.독수리오형제");
					break;
				}
			}

			getch();
			break;

		case 8:
			system("cls");
			printf("\n\n\n한 입 베어물은 사과는? ");
			printf("\n\nA.사과반쪽\tB.우리집 냉장고 사과\n\nC.파인애플\tD.맛없는사과\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.파인애플");
					break;
				}
			}

			getch();
			break;

		case 9:
			system("cls");
			printf("\n\n\n만일(萬一)과 같은 말은?");
			printf("\n\nA.만약\tB.그대\n\nC.내 노랠\t\tD.듣는다면\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'A')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 A.만약");
					break;
				}
			}

			getch();
			break;

		case 10:
			system("cls");
			printf("\n\n\n 하늘과 땅 사이에 있는것은?");
			printf("\n\nA.별\tB.공기\n\nC.과\tD.달\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.과");
					break;
				}
			}

			getch();
			break;
		case 11:
			system("cls");
			printf("\n\n\n다섯 그루의 나무를 심으면?");
			printf("\n\nA.파이브목\tB.식목왕\nC.오목\tD.오심\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.오목");
					break;
				}
			}

			getch();
			break;
		case 12:
			system("cls");
			printf("\n\n\n세상에서 가장 빨리 자는 사람은?");
			printf("\n\na.이미자\tb.잠꾸러기 그녀\n\nc.잠만보\td.이나영\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'A')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은A.이미자");
					break;
				}
			}

			getch();
			break;
		case 13:
			system("cls");
			printf("\n\n\n엄마는 하나고 아빠는 둘인 아이는?");
			printf("\n\na.수박\tb.옆집 순이\n\nc.그게뭐야..슬퍼..\td.두부한모\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'D')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 D.두부한모");
					break;
				}
			}

			getch();
			break;
		case 14:
			system("cls");
			printf("\n\n\n소녀시대는 소원을 몇 번 들어줄까?");
			printf("\n\na.2\tb.3\n\nc.4\td.5\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.4");
					break;
				}
			}

			getch();
			break;
		case 15:
			system("cls");
			printf("\n\n\n개미를 3등분으로 나누면?");
			printf("\n\na.머리 가슴 배\tb.살 가죽 뼈\n\nc.죽는다\td.불쨩...\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.죽는다");
					break;
				}
			}

			getch();
			break;
		case 16:
			system("cls");
			printf("\n\n\n우리나라 수영 기네스북에 실린 사람은?");
			printf("\n\na.박태환\tb.지은이\n\nc.심청이\td.나희\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.심청이");
					break;
				}
			}

			getch();
			break;
		case 17:
			system("cls");
			printf("\n\n\n비둘기의 평균수명은?");
			printf("\n\na.9\tb.99\n\nc.81\td.9달\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.81");
					break;
				}
			}

			getch();
			break;
		case 18:
			system("cls");
			printf("\n\n\n왕이하는 인사는?");
			printf("\n\na.바이킹a\tb.안녕하왕\n\nc.하잉\td.안녕하시오\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'A')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 A.바이킹");
					break;
				}
			}

			getch();
			break;
		case 19:
			system("cls");
			printf("\n\n\n초코파이엔 초코가 얼마나들었을까?");
			printf("\n\na.파이\tb.얼마가들었든 창렬\n\nc.손톱만큼\td.100그람\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'A')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 A.파이");
					break;
				}
			}

			getch();
			break;
		case 20:
			system("cls");
			printf("\n\n\n누워서 떡먹기보다 더 쉬운 것은?");
			printf("\n\na.누워서 침뱉기\tb.누워서 죽먹기\n\nc.떡먹고 눕기\td.누워서 물먹기\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.떡먹고 눕기");
					break;
				}
			}

			getch();
			break;
		case 21:
			system("cls");
			printf("\n\n\n가톨릭대학교 총장님의 성함은?");
			printf("\n\na.김지은\tb.박나희\n\nc.박영식\td.정성묵\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.박영식");
					break;
				}
			}

			getch();
			break;
		case 22:
			system("cls");
			printf("\n\n\n어른은 못타는데 어른이 있어야 움직이는 차는?");
			printf("\n\na.벤쯔\tb.소나타\n\nc.유모차\td.녹차\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.유모차");
					break;
				}
			}

			getch();
			break;
		case 23:
			system("cls");
			printf("\n\n\n이 곳에 들어가면 이름이 똑같아지는데 이것의 이름은?");
			printf("\n\na.군대\tb.회사\n\nc.쓰레기통\td.학교\n\n");
			countq++;
			while (1) {
				check = toupper(getch());
				if (check == 'C')
				{
					printf("\n\n정답!!!");
					countr++; break;
				}
				else if (check >= 65 && check <= 68) {
					printf("\n\nWrong!!! 정답은 C.쓰레기통");
					break;
				}
			}

			getch();
			break;
		}

		i++;
		if (i < 5) goto start;
		finaltime = time(NULL);
		t = difftime(finaltime, initialtime) / 3;

		if (t < 30)
		{
			t = 0;
		}     //걸린시간이 30초 이상일 경우에만 시간만큼 감점

		score = (float)countr / countq * 100 - t;

		if (score < 0) score = 0;
		printf("\n\n\nYour Score: %.2f", score);
		if (score == 100) printf("\n\n큭..이걸 다맞추다니...내가 졌다");
		else if (score >= 80 && score < 100) printf("\n\n이 정도면 훌륭하군 나가도 좋다!!");
		else if (score >= 60 && score < 80) printf("\n\n좋아! 하지만 더 노력해야겠어.");
		else if (score >= 40 && score < 60) printf("\n\n너,...이곳에서 살아도 될 것 같은데?");
		else printf("\n\n 이곳에서 평생 살자꾸나");

		puts("\n\nNEXT PLAY?(Y/N)");
		while (1) {
			if (toupper(getch()) == 'Y')
				goto home;
			else if (toupper(getch()) == 'N')
			{
				writescore(score, playername);
				
				goto mainhome;
			}
		}
	}
	else
	{
		printf("\n\n\t\t  Enter the right key\n\n\t\t  ");
		Sleep(700);
		goto mainhome;
	}
	return 0;
}
