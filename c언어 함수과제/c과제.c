#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// express ����ü ���� ����
int main(void) {
	FILE* fp1;
	FILE* fp2;
	char t1[100];
	char t2[100];
	char ch1, ch2;
	int c;
	int buf[100];
	printf("ù��° ���� �̸� : ");
	gets_s(t1, 100);
	printf("�ι�° ���� �̸� : ");
	gets_s(t2, 100);
	fp1 = fopen(t1, "rb");
	fp2 = fopen(t2, "wb");
	if (fp1 == NULL) {
		printf("���� ���� ����! 1\n");
		return 0;
	}
	if (fp2 == NULL) {
		printf("���� ���� ����! 2\n");
		return 0;
	}
	
	while ((c = fread((void*)buf,1,sizeof(buf),fp1))!=0) {
		fwrite((void*)buf, 1, c, fp2);
	}
	if (feof(fp1) == 0) {
		printf("���� ����!\n");
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
// 4�� ���Ҽ�����
/*typedef struct {
	double re;
	double im;
}com;
com add(com c1, com c2) {
	com res;
	
	res.re = c1.re + c2.re;
	res.im = c1.im + c2.im;
	return res;
}
com sub(com c1, com c2) {
	com res;
	res.re = c1.re - c2.re;
	res.im = c1.im - c2.im;
	return res;
}
com mul(com c1, com c2) {
	com res;
	res.re = ((c1.re * c2.re) - (c1.im * c2.im));
	res.im = ((c1.re * c2.im) + (c1.im * c2.re));
	return res;
}
int main(void) {
	com c1={ 3,4 };
	com c2 = { 1,2 };
	
	printf("���� ��� : %lf+%lfi\n", add(c1,c2).re, add(c1,c2).im);
	printf("���� ��� : %lf+%lfi\n", sub(c1, c2).re, sub(c1, c2).im);
	printf("���� ��� : %lf+%lfi\n", mul(c1, c2).re, mul(c1, c2).im);
	return 0;
}*/
// 13��
/*int main(void) {
	FILE* fp1;
	FILE* fp2;

	char n[100];
	char a[100];
	char f[1000];
	char ch[100];
	char* sp;
	printf("���� �̸� : ");
	gets_s(n, 100);
	fp1 = fopen(n, "rt");
	fp2 = fopen("andkor.txt", "wt");

	if (fp1 == NULL) {
		printf("���� ���� ����!\n");
		return 0;
	}
	if (fp2 == NULL) {
		printf("���� ���� ����!\n");
		return 0;
	}

	while (feof(fp1)==0) {
		fgets(a, 100, fp1);
		sp = strtok(a, " ");
		while (sp != NULL) {
			if (strcmp(sp, "Android") != 0) {
				fputs(sp, fp2);
				fputs(" ", fp2);
			}
			else {
				fputs("�ȵ���̵� ", fp2);
			}
			sp = strtok(NULL, " ");
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}*/
// 2019.12.8 12��
/*int main(void) {
	FILE* fp1;
	char a[100];
	int i = 0;
	char n[100];
	char tar[100];
	printf("���� �̸� : ");
	gets_s(n, 100);
	fp1 = fopen(n, "rt");
	if (fp1 == NULL) {
		printf("���� ���� ����!\n");
		return 0;
	}

	printf("Ž���� �ܾ� : ");
	gets_s(tar, 100);

	while (feof(fp1) == 0) {
		i++;
		if (strstr(fgets(a, 100, fp1), tar)) {
			printf("%s : %d  %s", n, i, a);
		}
	}
	fclose(fp1);
	return 0;
}*/
// 11�� �ٽ� �ѹ� Ǯ���
/*#define SIZE 100
typedef struct {
	char n[SIZE];
	char au[SIZE];
	char pu[SIZE];
}book;
void add(FILE* fp1) {
	book b;
	printf("������ �̸� : ");
	gets_s(b.n, SIZE);
	printf("���� : ");
	gets_s(b.au, SIZE);
	printf("���ǻ� : ");
	gets_s(b.pu, SIZE);

	fputs(b.n, fp1);
	fputs("\n", fp1);
	fputs(b.au, fp1);
	fputs("\n", fp1);
	fputs(b.pu, fp1);
	fputs("\n", fp1);
}
void print(FILE* fp1) {
	char a[SIZE];
	fseek(fp1, 0, SEEK_SET);
	while (feof(fp1)==0) {
		if (fgets(a, SIZE, fp1) == 0) {
			break;
		}
		printf("%s\n", a);
	}
}
void seach(FILE* fp1) {
	char a[SIZE];
	char tar[SIZE];
	int i;
	fseek(fp1, 0, SEEK_SET);
	printf("ã�� ������ �̸� �Է� : ");
	gets_s(a, SIZE);

	while (feof(fp1) == 0) {
		fgets(tar, SIZE, fp1);
		if (strstr(tar,a)!= NULL) {
			for (i = 0; i < 2; i++) {
				printf("%s\n", tar);
				fgets(tar, SIZE, fp1);
			}
			printf("%s\n", tar);
			break;
		}
	}
}
int main(void) {
	int c;
	FILE* fp1;
	
	fp1 = fopen("mylib.txt", "w+t");
	if (fp1 == NULL) {
		printf("���� ���� ����!\n");
		return 0;
	}
	
	while (1) {
		printf("===============\n");
		printf("1. �߰�\n");
		printf("2. ���\n");
		printf("3. �˻�\n");
		printf("4. ����\n");
		printf("===============\n");
		printf("���� ���� �Է��Ͻÿ� : ");
		scanf("%d", &c);
		getchar();
		switch (c) {
		case 1:
			add(fp1);
			break;
		case 2:
			print(fp1);
			break;
		case 3:
			seach(fp1);
			break;
		case 4:
			printf("�����մϴ�. \n");
			return 0;
		}
	}
	fclose(fp1);
	return 0;
}*/
// 2019.12.7 10��
/*int main(void) {
	FILE* fp1;
	char a[100];
	int i=0;
	fp1 = fopen("sams.txt", "rt");

	if (fp1 == NULL) {
		printf("���½���!\n");
		return 0;
	}
	while (fgets(a, sizeof(a), fp1) != NULL) {
		printf("%d: %s", i + 1, a);
		i++;
	}
	fclose(fp1);
	return 0;
}*/
// 9�� �ذ�ȉ� (�����ص� �ƹ��� ���Ͼ)
/*int main(int argc, char* argv[]){
	FILE* fp1, * fp2, * fp3;
	char file1[100], file2[100], file3[100];
	char buffer[100];
	if (argc >= 4) {
		strcpy(file1, argv[1]);
		strcpy(file2, argv[2]);
		strcpy(file3, argv[3]);
	}
	else {
		printf("�μ��� �����մϴ�.\n");
		return 0;
	}
	printf("%s ����+ %s������ %s���Ϸ� �����մϴ�.\n", file1, file2, file3);
	// ù��° ������ �б� ���� ����. 
	if ((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}
	// �ι�° ������ �б� ���� ����.
	if ((fp2 = fopen(file2, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file2);
		exit(1);
	}
	// �ι�° ������ �б� ���� ����.
	if ((fp3 = fopen(file3, "w")) == NULL)
	{
		fprintf(stderr, "��� ���� %s�� �� �� �����ϴ�.\n", file3);
		exit(1);
	}
	// ù��° ������ �ι�° ���Ϸ� �����Ѵ�.
	while (fgets(buffer, 100, fp1) != NULL)
		fputs(buffer, fp3);
	// ù��° ������ �ι�° ���Ϸ� �����Ѵ�.
	while (fgets(buffer, 100, fp2) != NULL)
		fputs(buffer, fp3);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}*/
// 8��
/*int main(void) {
	FILE* fp1;
	FILE* fp2;
	int i = 0;
	int rc;
	fp1 = fopen("sam1.txt", "wt");
	fp2 = fopen("sam2.b", "wb");
	if (fp1 == NULL) {
		printf("���� ���� (ù��°)\n");
		return 0;
	}
	if (fp2 == NULL) {
		printf("���� ���� (�ι�°)\n");
		return 0;
	}
	for (i = 0; i < 100; i++) {
		rc = rand();
		fprintf(fp1,"%d",rc);
		fwrite(&rc, 1, sizeof(rc), fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}*/
// 2019.12.6 c��� express ���� 7�� ����
/*int main(void) {
	FILE* fp;
	char a[100];
	char n[100];
	printf("���� �̸��� �Է��Ͻÿ� : ");
	scanf("%s", n);
	fp = fopen(n, "wt");
	if(fp == NULL){
		printf("���� ���� ����! \n");
	}
	while (fgets(a, sizeof(a), stdin)) {
		fputs(a, fp);
	}
	if (feof(fp)) {
		printf("���� ����!\n");
	}
	else {
		printf("���� ����!\n");
	}
	fclose(fp);
	return 0;
}*/
// c��� å 445�� 1��
/*int main(void) {
	char a[100];
	int i,s=0;
	printf("���ڿ� �Է� : ");
	gets(a);

	for (i = 0; i < strlen(a); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			s += a[i] - 48;
		}
	}
	printf("%d\n", s);
	return 0;
}*/
// c��� å 445�� 3��
/*int main(void) {
	char a1[100];
	char a2[100];
	char* p1;
	char* de1[100];
	char* p2;
	char* de2[100];
	int i = 0;

	printf("�̸�, ���� �Է� 1\n");
	gets(a1);
	printf("�̸�, ���� �Է� 2\n");
	gets(a2);
	p1 = strtok(a1, " ");
	while (p1 != NULL) {
		de1[i++] = p1;
		p1 = strtok(NULL, " ");
	}
	i = 0;
	p2 = strtok(a2, " ");
	while (p2 != NULL) {
		de2[i++] = p2;
		p2 = strtok(NULL, " ");
	}

	if (!strcmp(de1[0], de2[0])) {
		printf("�̸��� �����ϴ�.\n");
	}
	if (!strcmp(de1[1], de2[1])) {
		printf("���̰� �����ϴ�.\n");
	}
	return 0;
}*/
// c��� å 445�� 2������
/*int main(void) {
	char s1[20];
	char s2[20];
	char s3[40];
	int i = 0;
	printf("s1 : ");
	fgets(s1, 20, stdin);
	s1[strlen(s1)-1] = '\0';

	printf("s2 : ");
	fgets(s2, 20, stdin);
	s2[strlen(s2)-1] = '\0';

	for (i = 0; i < strlen(s1); i++) {
		s3[i] = s1[i];
	}
	for (i = 0; i < strlen(s2); i++) {
		s3[strlen(s1) + i] = s2[i];
	}
	s3[strlen(s1) + strlen(s2)] = '\0';
	printf("%s\n", s3);
	return 0;
}*/
// 2019.11.12 c��� express ���ڿ� 16��
/*int main(void) {
	char a[100];
	char* p;
	int i=0,j=0,n=0;
	printf("���� �ϰ� ���� �ؽ�Ʈ�� �Է��ϼ��� : ");
	gets(a);
	printf("====================================\n");
	p = a;
	for (i = 0; i < strlen(a); i++) {
		for (j = 0; j < strlen(a); j++) {
			printf("%c", p[(n+j)%strlen(a)]);		
		}
		printf("\n");
		n++;
		
	}
	return 0;
}*/
// 2019.11.3 c��� ���� ���ڿ� 29�� strcat ����
/*int main(void) {
	char m[1000];
	char o[1000];
	int l1,l2,i;
	char *resu;
	printf("���� ���ڿ� �Է� : ");
	fgets(m, 1000, stdin);
	printf("��ĥ ���ڿ� �Է� : ");
	fgets(o, 1000, stdin);
	l1 = strlen(m);
	l2 = strlen(o);

	resu = (char*)malloc(sizeof(char)*(l1+l2));
	for (i = 0; i < l1-1; i++) {
		resu[i] = m[i];
	}
	for (i = 0; i < l2-1; i++) {
		resu[l1 - 1 + i] = o[i];
	}
	resu[(l1 + l2)-2] = '\0';
	printf("��� : %s", resu);
	//printf("���� �Է� ���� : %s", m);
	//printf("���2 : %s", o);
}*/
// 2019.10.30 c��� ���� ���ڿ����� 22��
/*int main() {
	// �ؿ��ڵ�
	char nstr[100], place[5][4] = { "", "��", "��", "õ" }, place2[5][4] = { "", "��","��", "��", "��" };
	char dplace[11][4] = { "��", "��", "��", "��", "��", "��", "��", "ĥ", "��", "��" };
	scanf("%s", nstr);
	int len = (int)strlen(nstr), pcnt = !(len % 4) ? (int)(len / 4) - 1 : (int)(len / 4);
	for (int plc = len - 1; plc >= 0; plc--) {
		char chr = nstr[len - plc - 1];
		if (plc != 0) {  // 1���ڸ����� �ƴϸ�
			if ((chr == '1' && pcnt < 2) || chr == '0') // �ϸ� -> �� && �� -> �Ͼ�
				printf("");
			else
				printf("%s", dplace[chr - '0']); // �� ~ �� �� ���
			if (chr != '0')
				printf("%s", place[plc - (pcnt * 4)]);  // ��~õ �� ���
		}
		else  //1�� �ڸ������
			printf("%s", dplace[chr - '0']);  // �� ~ �� ���
		if (plc - (pcnt * 4) == 0) {
			printf("%s ", place2[pcnt]);  // �� ~ �� ���
			pcnt--;
		}
	}
}*/
/*int main(void) {
	char d[4][3] = { "��","��","õ" };
	char bigd[6][3] = { "��", "��","��","��","��","��" };
	char num[10][3] = { "��","��","��","��","��","��","��","ĥ","��","��" };
	char inp[1000];
	int len = 0, cur = 0, a = 0, i=0, loof = 0;
	printf("�Է� : ");
	scanf("%s", &inp);
	len = strlen(inp);

	while (1) {
		if (len == 1) {
			if (inp[cur] != '0' || cur == 0) {
				printf("%s", num[inp[cur] - 48]);
			}
			break;
		}
		if ((inp[cur] != '0' && inp[cur] != '1')|| (len - 5) % 4 == 0){
			printf("%s", num[inp[cur] - 48]); // �� �ڸ��� ���
		}	
		if (len / 5 > 0 && (len - 5) % 4 == 0) { // �� ���� �̻�
			if ((len-5) % 4==0) {
				i = len-5;
				printf("%s ", bigd[i/4]); // �� �̻�
			}
			else {
				printf("%s ", bigd[len / 5-1]); // �� ����
			}
			len--;
			cur++;
		}
		else if (len % 4 >= 0) { // �� , �� , õ
			a = len - 2;
			if (inp[cur] != '0') {
				printf("%s", d[a % 4]);
			}
			len--;

			cur++;
		}
	}
	return 0;
}*/
// c��� ���� 30��
/*int main(void) {
	char a1[7];
	char a2[8];
	char n,y[5], m[3], d[3];
	char s1[10] = "����",s2[10] = "����";
	int i = 0;

	printf("�ֹι�ȣ �Է� : ");
	fgets(a1, 7, stdin);
	n = getchar();
	fgets(a2, 8, stdin);

	if (a2[0] == '1' || a2[0] == '2') {
		for (i = 0; i < 2; i++) {
			y[0] = '1';
			y[1] = '9';
			y[i + 2] = a1[i];
			m[i] = a1[i + 2];
			d[i] = a1[i + 4];

		}
	}
	else if(a2[0] == '3' || a2[0] == '4'){
		for (i = 0; i < 2; i++) {
			y[0] = '2';
			y[1] = '0';
			y[i + 2] = a1[i];
			m[i] = a1[i + 2];
			d[i] = a1[i + 4];
		}
	}
	y[4] = '\0';
	m[2] = '\0';
	d[2] = '\0';
	printf("%s�� %s�� %s��\n", y, m, d);

	if (a2[0] == '1' || a2[0] == '3') {
		printf("%s\n", s1);
	}
	else if(a2[0] == '2' || a2[0] == '4'){
		printf("%s\n", s2);
	}
	else {
		printf("���� ����\n");
	}
	return 0;
}*/
// c��� 20�� �������� 2��
// ������ �迭
//#include <time.h>
//#include <stdlib.h>
/*int main(void) {
	//clock_t start, end;
	int n,i=0,j=0;
	int arr[50][50] = { 0, };
	int num = 1,chco=0,leri=0,updo = 0;

	//srand((unsigned int)time(NULL));

	//start = clock();

	printf("���ڸ� �Է��Ͻÿ�(10����) : ");
	scanf("%d", &n);
	// num == �迭�� �Է��Ϸ��� ��
	// chco(Check_Count) == ���° �ڳʸ� ���Ҵ��� �Ǵ�
	// leri(Left_Right) == ���� �������� ������ �������� �Ǵ�
	// 0�� ����, 1�� ����
	// updo(Up_Down) == ���� �������� �Ʒ��� �������� �Ǵ�
	
	// 0�� �Ʒ���(i�� ����), 1�� ����(i�� ����)

	// chco > 3 �̶�� ����� �Ѻκ�(n*n�� �׵θ��κ�)��
	// ���� ä������ �ƴ��� �Ǵ��ϴ� �ǹ�
	while (1) {
		// j++ ���� ���� 
		if (chco % 2 == 0 && leri == 0) {
			if (num == n*n+1) {
				break;
			}
			arr[i][j] = num++;
			j++;
			if (j == n-1 || arr[i][j] != 0) {
				chco += 1;
				leri = 1;
				if (chco > 3) {
					i += 1;
					j -= 1;
					
				}
			}
		}
		// i++ ������ ���� 
		else if (chco % 2 != 0 && updo == 0) {
			if (num == n*n+1) {
				break;
			}
			arr[i][j] = num++;
			i++;
			if (i == n - 1 || arr[i][j] != 0) {
				chco += 1;
				updo = 1;
				if (chco > 3) {
					i -= 1;
					j -= 1;
					
				}
			}
		}
		// j-- �Ʒ��� ����
		else if (chco % 2 == 0 && leri == 1) {
			if (num == n*n+1) {
				break;
			}
			arr[i][j] = num++;
			j--;
			if (j == 0 || arr[i][j] != 0) {
				chco += 1;
				leri = 0;
				if (chco > 3) {
					i -= 1;
					j += 1;
					
				}
			}
		}
		// i-- ���� ����
		else if (chco % 2 != 0 && updo == 1) {
			if (num == n*n+1) {
				break;
			}
			arr[i][j] = num++;
			i--;
			if (i == 0 || arr[i][j] != 0) {
				chco += 1;
				updo = 0;
				if (chco > 3) {
					i += 1;
					j += 1;
				}
			}
		}
		else {
			break;
		}
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	//end = clock();
	
	//printf("����ð� = %.3lf�и���, %.3lf��\n", (double)end-start,(end - start) / (double)1000);
	return 0;
}*/
// c��� 20�� ���� 3,4��(�������)
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int i;
	srand((int)time(NULL));

	for (i = 0; i < 2; i++) {
		printf("�ֻ���%d : %d\n",i+1, rand() % 6);
	}

	return 0;
}*/
// c��� 20�� ���� 5�� ( ���������� ����)
/* #include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void){	
	char *arr[] = { "����", "����", "��" };
	char *arr2[] = { "�̰���ϴ�!","�����ϴ�!","����� �����ϴ�." };
	int jud=0;
	int com=1,i,j,user=1;
	int draw = 0, win = 0, lose = 0;
	srand((int)time(NULL));

	while (1) {
		if (lose == 1) {
			break;
		}
		else {
			printf("������ 1, ������ 2, ���� 3 : ");
			scanf("%d", &user);
			com = 1+rand() % 3;
		}
		if (user == 1) {
			if (com == 1) {
				draw += 1;
				jud = 1;
			}
			else if (com == 2) {
				win += 1;
				jud = 0;
			}
			else if (com == 3) {
				lose += 1;
				jud = 2;
			}
		}
		else if (user == 2) {
			if (com == 1) {
				lose += 1;
				jud = 2;
			}
			else if (com == 2) {
				draw += 1;
				jud = 1;
			}
			else if (com == 3) {
				win += 1;
				jud = 0;
			}
		}
		else if (user == 3) {
			if (com == 1) {
				win += 1;
				jud = 0;
			}
			else if (com == 2) {
				lose += 1;
				jud = 2;
			}
			else if (com == 3) {
				draw += 1;
				jud = 1;
			}
		}
		printf("����� %s ����, ��ǻ�ʹ� %s ����, %s\n", arr[user-1], arr[com-1], arr2[jud]);
	}
	printf("������ ��� : %d�� %d��", win, draw);
	return 0;
} */
// c��� 20�� ���� 6�� ( ���ھ߱� ����)
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int com[3] = { 0, };
	int user[3] = { 0, };
	int n1,n2,n3,i,j,loco=1;
	int st = 0, b = 0;

	srand((int)time(NULL));
	for (i = 0; i < 3; i++) {
		if (i == 0) {
			com[i] = 1+rand() % 8;
		}
		else {
			com[i] = rand() % 9;
		}

	}
	printf("Start Game!\n");

	while (1) {
		if (st == 3) {
			printf("Game Over!\n");
			break;
		}
		else {
			st = 0;
			b = 0;
		}
		printf("3���� ���� ���� : ");
		scanf("%d %d %d", &n1, &n2, &n3);
		user[0] = n1;
		user[1] = n2;
		user[2] = n3;
		
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (user[i] == com[j] && i == j) {
					st += 1;
				}
				else if (user[i] == com[j]) {
					b+=1;
				}
			}
		}
		printf("%d��° ���� ��� : %d Stirke, %d Ball\n", loco++, st, b);

	}
	return 0;
} */