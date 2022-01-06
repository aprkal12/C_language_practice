#include <stdio.h>
// 2020 3.7 Åä¿äÀÏ ¹éÁØ 2851¹ø
int main(void) {
	int score = 0;
	int arr[10] = { 0, };
	int i = 0;
	int a = 0, b = 0;

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 10; i++) {
		a = 100 - score;
		b = 100 - (score + arr[i]);
		if (a < 0) {
			a *= -1;
		}
		if (b < 0) {
			b *= -1;
		}
		if (a >= b) {
			score += arr[i];
		}
		else {
			break;
		}
	}
	printf("%d", score);
	return 0;
}
// ¹éÁØ 5565¹ø
/*int main(void) {
	int n = 0;
	int arr[10] = { 0, };
	int i = 0;

	scanf("%d", &n);
	for (i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 9; i++) {
		n -= arr[i];
	}
	printf("%d", n);
	return 0;
}*/
// 2020 3.6 ¹éÁØ 2839¹ø ¹®Á¦
/*int main(void) {
	int BigBag = 5;
	int SmallBag = 3;
	int i,count = 0;
	int n = 0;

	scanf("%d", &n);
	for (; n - SmallBag >= 0; count++) {
		for (; (n - BigBag >= 0)&&((n % 3!= 0)||(n%5 == 0)); count++) {
			n -= BigBag;
			if (n == 0) {
				break;
			}
		}
		n -= SmallBag;

	}
	if (n % BigBag != 0 && n % SmallBag != 0) {
		printf("%d",-1);
		return 0;
	}
	printf("%d", count);
	return 0;
}*/
// ¹éÁØ 5543¹ø
/*int main(void) {
	int a = 0, b = 0, c = 0;
	int x = 0, y = 0;
	int money = 0;
	int i = 0;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	
	money = a < b ? a : b;
	money = money < c ? money : c;

	if (x > y) {
		money += y;
	}
	else {
		money += x;
	}
	printf("%d", money-50);
	return 0;
}*/
// ¹éÁØ 10871¹ø ¹®Á¦
/*int main(void) {
	int n = 0, tar = 0;
	int arr[10000] = { 0, };
	int i = 0;
	scanf("%d %d", &n, &tar);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++) {
		if (arr[i] < tar) {
			printf("%d ", arr[i]);
		}
	}
	return 0;
}*/
// 2020.3.2 ¿À·£¸¸¿¡ c¾ğ¾î
// ÄÚµå¾÷ 4085¹ø
/*int main(void) {
	int arr[101][101] = { 0, };
	int x = 0, y = 0, m = 0, n = 0;
	int i = 0, j = 0, k = 0;
	int cur_ka = 0; // ÇöÀç ºñ¿Áµµ
	int ka = 0; // ÃÖ´ë ºñ¿Áµµ
	int cur_x = 0, cur_y = 0;
	scanf("%d %d %d %d", &x, &y, &m, &n);
	
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (1) {
		if (cur_x == x && cur_y == y) {
			break;
		}
		if (ka < cur_ka) {
			ka = cur_ka;
		}
		if (cur_x < x) {
			cur_x++;
		}
		if (cur_x == x && cur_y < y) {
			cur_y++;
			cur_x = 0;
		}
		cur_ka = 0;
		for (i = cur_y; i < cur_y+n; i++) {
			for (j = cur_x; j < cur_x+m; j++) {
				cur_ka += arr[i][j];
			}
		}	
	}
	printf("%d\n", ka);
	//for (i = 0; i < y; i++) {
	//	for (j = 0; j < x; j++) {
	//		printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}
	return 0;
}*/
// 2019.10.9 c¾ğ¾î Å×½ºÆ®¿¬½À
/*int main(void) {
	int arr[6] = { 1,2,3,4,5,6 };
	int* p1 = arr, * p2 = &arr[5];
	int i;
	int t;
	for (i = 0; i < 3; i++) {
		t = *p1;
		*p1 = *p2;
		*p2 = t;
		p1++;
		p2--;
	}
	for (i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}*/
// 2019.10.4 n*n ¹è¿­ Å×µÎ¸®ÀÇ ÇÕ
/*int main(void) {
	int arr[101][101] = { 0, };
	int i, j, n, sum = 0, k = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			arr[i][j] = k++;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				sum += arr[i][j];
			}
			else if (i == n-1 || j == n-1) {
				sum += arr[i][j];
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}*/
// 2019.9.13 1000! Á¤¼ö ±¸Çö (¹è¿­ È°¿ë)
/*
int cal[10000] = { 0, };
int res[10000] = { 0, };
int pre[10000] = { 1, };
int n=0;
±¸ÇöÇØ¾ß ÇÒ Á¶°Ç
1. ÆÑÅä¸®¾ó 

2. ¹è¿­ ÀÎµ¦½º·Î ÀÎ°£Ã³·³ °ö¼ÀÇÏ±â

¿¹) 12 * 5
1*5 = 5, ÀÚ¸´¼ö : 1+0 = 1
Áï. res[1] += 5
±×ÈÄ °ö 2*5: 10  ÀÚ¸´¼ö: 0+0 = 0
ÀÚ¸´¼ö 0ÀÇ 10 ÀÌ´Ï ÀÚ¸´¼ö 1¿¡ 1 ´õÇØÁÖ°í 0¹øÂ°¿¡´Â 0´õÇØÁÜ
´ä == 60

¿¹) 25 * 5
¸ÕÀú 2*5 : 10 ÀÚ¸´¼ö 1+0 = 1
ÀÚ¸´¼ö 1À» ±âÁØÀ¸·Î 10ÀÌ´Ï±î res[2] += 1, res[1] += 0 
±× ´ÙÀ½ 5*5 = 25 ÀÚ¸´¼ö 0+0 = 0
res[1] += 2, res[0] += 5
´ä == 125

¿¹) 12 * 34
1 * 3 = 3, ÀÚ¸® 2
res[2] += 3
2 * 3 = 6 ÀÚ¸® 1
res[1] += 6
1 * 4 = 4 ÀÚ¸® 1
res[1] += 4
2 * 4 = 8 ÀÚ¸® 0
res[0] = 8

´ä == 408

3. Ãâ·ÂÁ¶°Ç ¼³Á¤
ÀÚ¸´¼ö Áß °¡Àå ³ôÀº °ªÀ» µû·Î ÀúÀåÇØ¼­ ¹İº¹¹® Á¾·áÁ¶°ÇÀ¸·Î ¼³Á¤ÇÑ µÚ 
±× ÀÚ¸´¼ö ±îÁö Ãâ·Â

4. ³ª¸ÓÁö´Â ±¸ÇöÇÏ¸é¼­ ÀÛ¼º

void com(int a, int b) {
	int c;
	int i=0,cnt;
	
	c = a * b;
	cnt = c;
	
	while (cnt > 0) {
		n++;
		cnt /= 10;
	}

	if (c >= 10) {
		for (i=0; c > 0; i++) {
			cal[i] = c % 10;
			c /= 10;
		}
	}
	else {
		cal[i] = c;
	}
	
}

int main(void) {
	int i,a,b;

	printf("¼ıÀÚ µÎ°³ ÀÔ·Â : ");
	scanf("%d %d", &a, &b);
	
	com(a, b);

	for (i = n-1; i >= 0; i--) {
		printf("%d ", cal[i]);
	}

	return 0;
}
*/
// 2019.7.29 ¿ù¿äÀÏ
// ¿¬°á¸®½ºÆ®(c¾ğ¾î)
/*
#include <stdlib.h>
//Æ¯Á¤ ³ëµå »èÁ¦ÇÔ¼ö ´Ù½Ã °øºÎ(ÄÚµùµµÀå)
struct node {
	struct node* next;
	int data;
};
void add(struct node* target, int data) { //Ã¹ ³ëµå Ãß°¡ ÇÔ¼ö
	struct node* new = malloc(sizeof(struct node));
	new->next = target->next;
	new->data = data;

	target->next = new;
}
void removefirst(struct node* target) { // Ã¹ ³ëµå »èÁ¦
	struct node* remove =target->next;
	target->next = remove->next;
	free(remove);
}
struct node* findnode(struct node* node, int data) { //Æ¯Á¤ ³ëµåÃ£±â
	if (node == NULL)
		return NULL;

	struct node* curr = node->next;
	while (curr != NULL)
	{
		if (curr->data == data)
			return curr;

		curr = curr->next;
	}

	return NULL;
}
int main(void) {
	struct node* head = malloc(sizeof(struct node));

	head->next = NULL;

	add(head, 10);
	add(head, 20);
	add(head, 30);
	
	struct node* found = findnode(head, 20); // ¿ä¼Ò Ã£±â
	printf("%d\n", found->data);

	struct node* cur = head->next;
	while (cur != NULL) { // ³ëµå ­x·Â
		printf("%d\n", cur->data);
		cur = cur->next;
	}

	cur = head->next;
	while (cur != NULL) { // »ç¿ëÇÑ ¿¬°á¸®½ºÆ®µé ¸Ş¸ğ¸®ÇØÁ¦
		struct node* next = cur->next;
		free(cur);
		cur = next;
	}

	free(head);

	return 0;
}
*/
//2019.7.27 Åä¿äÀÏ
/*int main(void) {
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		printf("%d\n", i);
	}
	return 0;
} */
// 2019.7.26 ±İ¿äÀÏ
// ÇÏ³ëÀÌÅ¸¿ö 3,4°³ ÇØº¸±â
/* void hanoi(int num, char from, char by, char to) {
	// printf("hanoi0 %d\n", c);
	if (num == 1) { // ÀÌµ¿ÇÒ ¿ø¹İ ¼ö°¡ 1°³
		printf("hanoi0 Àç±Í ³¡ %d\n", num);
		printf("¿ø¹İ1À» %c¿¡¼­ %c·Î ÀÌµ¿ \n", from, to);
	}
	else {
		printf("hanoi1 down %d\n", num);
		hanoi(num - 1, from, to, by);
		printf("\n");
		printf("hanoi1 up %d\n", num);

		printf("¿ø¹İ %d¸¦ %c¿¡¼­ %c·Î ÀÌµ¿ \n", num, from, to);

		printf("hanoi2 down %d\n", num);
		printf("\n");
		hanoi(num - 1, by, from, to);
		printf("hanoi2 up %d\n", num);
		
	}
}
int main(void) {
	// ¸·´ë aÀÇ ¿ø¹İ 3°³¸¦ ¸·´ëb¸¦ °æÀ¯ÇÏ¿© ¸·´ë c·Î ¿Å±â±â
	hanoi(4, 'A', 'B', 'C');
	return 0;
} */
//2019.7.25 ¸ñ¿äÀÏ
// ÀÌÁøÅ½»ö Àç±Í±¸Çö
/* int search(int arr[], int st, int end, int target) {
	int mid;
	if (st > end) {
		return -1;
	}
	mid = (st + end) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	else if (target < arr[mid]) {
		return search(arr, st, mid - 1, target);
	}
	else {
		return search(arr, mid + 1, end, target);
	}
}
int main(void) {
	int arr[9] = { 1,2,3,7,9,12,21,23,27 };
	int st,end, target;
	int i;
	st = arr[0];
	end = arr[8];
	scanf("%d", &target);
	printf("¸î¹øÂ°¿¡ ÀÖ¾î¤¿?  = %d\n", search(arr, st, end, target));
	return 0;
} */
// a^x = N -> log a N
// aÀÇ xÁ¦°öÀº N -> ·Î±× a N
//2019.7.24 ¼ö 
//ÀÌÁø Å½»ö
/* int search(int ar[], int len, int target) {
	int first = 0;
	int end = len - 1;
	int mid;
	while (first <= end) {
		mid = (first + end) / 2;
		if (target == ar[mid]) {
			return mid;
		}
		else {
			if (target < ar[mid]) {
				end = mid - 1;
			}
			else {
				first = mid + 1;
			}
		}
	}
	return -1;
}
int main(void) {
	int arr[9] = { 1,2,3,7,9,12,21,23,27 };
	int l, target;
	int i;
	l = sizeof(arr) / sizeof(int);
	scanf("%d", &target);
	if (search(arr, l, target) == -1) {
		printf("Å¸°ÙÀÌ ¾ø¾î¿ä");
	}
	else {
		printf("Å¸°Ù¾îµğ? = %d ", search(arr, l, target)+1);
	}
	return 0;
} */
//2019.7.23 È­
//Á¾ÀÌ¸¸µé±â ÄÚµå¾÷ (1677) 
/* int main(void) {
	int n,m;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 && j == 0) {
				printf("+");
			}
			else if (i == 0 && j == n - 1) {
				printf("+");
			}
			else if (i == m - 1 && j == 0) {
				printf("+");
			}
			else if (i == m - 1 && j == n - 1) {
				printf("+");
			}
			else if (i == 0 || i == m - 1) {
				printf("-");
			}
			if (i == 0 || i == m - 1) {
			}
			else if (j == 0 || j == n - 1) {
				printf("|");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
} */
// 2019.7.22 ¿ù¿äÀÏ
//·¹ÀÌÁ® Ã¼½º (ÄÚµå¾÷ 1514)
/* int arr[8][8] = { 0, };
void arrgo(int n) {
	int i, j, k,l;
	for (i = 1; i < 8; i++) {
		for (j = 1; j < 8; j++) {
			if (n != 999) {
				if (arr[j][n] != 2) {
					arr[j][n] = 1;
				}
				else if(arr[j][n] == 2){
					for (k = 1; k < 8; k++) {
						if (arr[j][k] != 2) {
							arr[j][k] = 1;
						}
						else if (arr[j][k] == 2) {
							for (l = 1; l < 8; l++) {
								if (arr[l][k] != 2) {
									arr[l][k] = 1;
								}
							}
						}
					}
				}
			}
			
		}
	}
}
int main(void) {
	int i, j, n1, n2, n = 999;
	for (i = 0; i < 3; i++) {
		scanf("%d %d", &n1, &n2);
		arr[n1][n2] = 2;
	}
	for (i = 1; i < 8; i++) {
		if (arr[4][i] != 2) {
			arr[4][i] = 1;
		}
		else {
			n = i;
			arrgo(n);
		}
		
	}
	
	for (i = 1; i < 8; i++) {
		for (j = 1; j < 8; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
} */
// Æ¯ÀÌÇÑ »ç°¢Çü ( ÄÚµå¾÷ 1365,1366)
/*int main(void) {
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 || i == n - 1) {
				printf("*");
			}
			else if (j == 0 || j == n - 1) {
				printf("*");
			}
			else if (i == j) {
				printf("*");
			}
			else if (i == n - j-1) {
				printf("*");
			}
			else if (i == n / 2) {
				printf("*");
			}
			else if (j == n / 2) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
} */
// ÆòÇà »çº¯Çü ( ÄÚµå¾÷ 1367, 1368)
/*int main(void) {
	int h, k;
	char d;
	int i, j;
	scanf("%d %d %c", &h,&k,&d);
	if (d == 'l' || d == 'L') {
		for (i = 0; i < h; i++) {
			for (j = 0; j < i; j++) {
				printf(" ");
			}
			for (j = 0; j < k; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	else if (d == 'r' || d == 'R') {
		for (i = 0; i < h; i++) {
			for (j = i; j < h - 1; j++) {
				printf(" ");
			}
			for (j = 0; j < k; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0; 
} */
// Áö±×Àç±× ( ÄÚµå¾÷ 1370))
/*int main(void) {
	int h, r;
	int i, j,k;
	scanf("%d %d", &h, &r);
	for (k = 0; k < r; k++) {
		for (i = 0; i < h; i++) {
			for (j = 0; j < i; j++) {
				printf(" ");
			}
			printf("*");
			printf("\n");
		}
		for (i = 0; i < h-1; i++) {
			for (j = i; j < h - 2; j++) {
				printf(" ");
			}
			printf("*");
			printf("\n");
		}
	}
	
	return 0;
} */

// 2019. 7. 21 ¿ù¿äÀÏ
//È¿À²ÀûÀÎ °ø¹é º°Âï±â
//ÄÚµå¾÷ 1358
/* int main(void) {
	int i=0, n, j,m=0;
	scanf("%d", &n);
	while (i<=n) {
		if (i % 2 != 0) { //i = 1 3 5 7 9 ...
			for (j = 0; j < n - i - 1 - m++; j++) {
				printf(" ");
			}
			for (j = 0; j < i; j++) {
				printf("*");
			}
			printf("\n");
		}
		m = 0;
		i++;
	}
	return 0;
} */
//º° °è´Ü
// ÄÚµå¾÷ 1361
/* int main(void) {
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = n-1; j < n; j++) {
			printf("**\n");
		}
	}
	return 0;
} */
//¹®ÀÚ¿­¿¡¼­ ¹®ÀÚ À§Ä¡ Ãâ·Â
// ÄÚµå¾÷ 1418
/*int main(void) {
	char a[100];
	int i,n=0;
	scanf("%s", &a);
	for (i = 0; a[i] != '\0'; i++) {
		n++;
	}
	for (i = 0; i < n; i++) {
		if (a[i] == 't') {
			printf("%d ", i+1);
		}
	}
	return 0;
}*/
// ¾ÏÈ£ ÄÚµå¾÷ 1408
/* int main(void) {
	char n[21];
	int i, s=0;
	scanf("%s", &n);
	for (i = 0; n[i] != '\0'; i++) {
		s++;
	}
	for (i = 0; i < s; i++) {
		printf("%c", n[i] + 2);
	}
	printf("\n");
	for (i = 0; i < s; i++) {
		printf("%c", n[i]*7 %80 +48);
	}
	return 0;
} */

//2019.7.19 ±İ¿äÀÏ
//±¸Á¶Ã¼ ¹®Á¦(¼®Â÷°è»ê)
/* typedef struct {
	int arr[300];
	int rank[300];
}score;
int main(void) {
	int n,i,j,high = 0;
	score s = { .arr = {0,},.rank = {0,} };
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s.arr[i]);
		s.rank[i] = 1;
	}	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (s.arr[i] < s.arr[j]) {
				s.rank[i]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d %d\n", s.arr[i], s.rank[i]);
	}
	return 0;
} */
// ¹è¿­(ºüÁøÄ«µå)
// ÄÚµå¾÷ 1411
/* int main(void) {
	int arr[101] = { 0, };
	int ar[101] = { 0, };
	int n,i,num=1,result=0,j,num2;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		ar[i] = num++;
	}
	for (i = 0; i < n-1; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++) {
		result = 0;
		for (j = 0; j < n - 1; j++) {
			if (ar[i] == arr[j]) {
				result = 1;
				break;
			}
		}
		if (result == 0) {
			num2 = ar[i];
		}
	}
	printf("%d", num2);
	return 0;
} */
// ¹è¿­(ÀÚ¸®¹èÄ¡)
// ÄÚµå¾÷ 1425
/* int main(void) {
	int arr[100] = { 0, };
	int i, n1,n2,j=0,tem;
	scanf("%d %d", &n1, &n2);
	for (i = 0; i < n1; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n1; i++){
		for (j = 0; j < n1 - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
			}
		}
	}
	for (i = 0; i < n1; i++) {
		printf("%d ", arr[i]);
		if (j++ == n2 - 1) {
			printf("\n");
			j = 0;
		}
	}
	return 0;
} */
// Æ¯ÀÌÇÑ º°Âï±â(±âÃÊ ¹İº¹¹®)
// ÄÚµå¾÷ 1356
 /* int main(void) {
	int i,n,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 || i == n - 1) {
				printf("*");
			}
			else if (j == 0 || j == n - 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
} */
// Æ¯ÀÌÇÑ º°Âï±â(±âÃÊ ¹İº¹¹®)
// ÄÚµå¾÷ 1357
/* int main(void) {
	int i, n, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = -1; j < i; j++) {
			printf("*");
		}
		
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
} */
//º°Âï±â ±âº» ÄÚµå
/* int main(void) {
	int i, n, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < i+i+1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
} */
// 2019.7.18 ¸ñ¿äÀÏ
// ¾Ë°í¸®Áò °øºÎ
// ¼±ÅÃÁ¤·Ä
/* int main(void) {
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	int i, j, min, index, temp;
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
} */
// ¹öºíÁ¤·Ä
/*
int main(void) {
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	int i, j, temp;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
} */
// »ğÀÔÁ¤·Ä
 /* int main(void) {
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	int i, j,tem;
	for (i = 0; i < 9; i++) {
		j = i;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			tem = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tem;
			j--;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
} */
// Àç±ÍÇÔ¼ö ¿¬½À (¹İº¹¹®x)
// (¹İº¹¹® ¾È¾²´Â º°Âï±â)
/* 
int cnt = 1;
int i = 0;
int recur(int x) {
	if (x == 0) {
		return;
	}
	if (i == cnt) {
		printf("\n");
		i = 0;
		cnt++;
		return recur(x - 1);
	}
	if (i < cnt) {
		printf("*");
		i++;
		return recur(x);
	}
}
int main(void) {
	int num;
	scanf("%d", &num);
	recur(num);
	return 0;
} */
// (¹İº¹¹® ¾È¾²´Â È¦¼öÃâ·Â)
/* int recur(int x,int y) {
	if (x == y) {
		if (x % 2 != 0) {
			printf("%d ", x);
		}
		return;
	}
	if (x % 2 != 0) {
		printf("%d ", x);
		return recur(x + 1, y);
	}
	else {
		return recur(x + 1, y);
	}
}
int main(void) {
	int n,n1;
	scanf("%d %d", &n,&n1);
	recur(n, n1);
	return 0;
} */
// 1ºÎÅÍ n±îÁöÀÇ ÇÕ
/* int recur(int x) {
	return (x * (x + 1)) / 2;
}
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d",recur(n));
	return 0;
} */
// ÆÑÅä¸®¾ó
/* int fac(int x) {
	if (x == 0) {
		return 1;
	}
	return x * fac(x - 1);
}
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d", fac(n));
	return 0;
} */
//ÇÇº¸³ªÄ¡ (¸Ş¸ğÀÌÁ¦ÀÌ¼Ç)
/* int arr[20] = { 0, };
int fivo(int x) {
	if (x <= 2) {
		arr[x] = 1;
		return arr[x];
	}
	if (arr[x] != 0) {
		return arr[x];
	}
	else {
		arr[x] = fivo(x - 1) + fivo(x - 2);
		return arr[x];
	}
}
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d", fivo(n));
	return 0;
}  */
// ¼±ÅÃÁ¤·Ä ¿¬½À
/* int main(void) {
	int arr[101] = { 0, };
	int i, j;
	int n,min,temp, index;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++) {
		min = -1;
		for (j = i; j < n; j++) {
			if (min < arr[j]) {
				min = arr[j];
				index = j;
			}	
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
} */
// 2019.7.17 ¼ö¿äÀÏ
// if¹®¾È¾²´Â ½Ã°£¹®Á¦0
/* 	int main(void) {
	int hour, min;
	int time;
	scanf("%d %d", &hour, &min);
	// if¹® »ç¿ë X
    if (min - 30 >= 0) {
		min -= 30;
	}
	else if (min - 30 < 0) {
		time = 30 - min;
		min -= min;
		hour -= 1;
		min = 60 - time;
	} 
	time = (hour * 60) + min;
	
	time -= 30;
	
	time = 24 * 60 + time;
	
	time = time % (24 * 60);
	

	hour = time / 60;
	min = time % 60;
	printf("%d %d\n", hour, min);
	return 0;
} */
// ¹öºíÁ¤·Ä
/*	int main(void) {
	int arr[10000] = { 0, };
	int i, j,num,tem;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j+1 < num; j++) {
			if (arr[j] > arr[j + 1]) {
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;

			}
		}
	}
	for (i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
} */
//ÀÔ·ÂÇÑ ¼ıÀÚÀÇ À§Ä¡
/* 	int main(void) {
	int n, k;
	int arr[100000];
	int i;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++) {
		if (arr[i] == k) {
			printf("%d\n", i+1);
			break;
		}
		if (i == n - 1) {
			printf("-1\n");
		}
	}
	return 0;
} */
//¸Ş¸ğÀÌÁ¦ÀÌ¼Ç ¿¬½À
/* int memoi[100] = { 0, };
int fivo(int x) {
	if (x <= 2) {
		return 1;
	}
	if (memoi[x] != 0) {
		return memoi[x];
	}
	else {
		memoi[x] = fivo(x - 1) + fivo(x - 2);
		return memoi[x];
	}
}
int main(void) {
	printf("%d \n", fivo(30));
	return 0;
} */
// ¸Ş¸ğÀÌÁ¦ÀÌ¼Ç ¹®Á¦
// ÄÚµå¾÷ 1930¹ø ¹®Á¦
/* int arr[15][15] = { 0, };
int supersum(int k, int n) {
	int i;
	if (k == 0) {
		arr[k][n] = n;
		return arr[k][n];
	}
	if (arr[k][n] != 0) {
		return arr[k][n];
	}
	
	for (i = 1; i <= n; i++) {
		arr[k][n] += supersum(k - 1, i);
	}
	return arr[k][n];
	
}
int main(void) {
	int k, n;
	while (scanf("%d %d", &k, &n) != EOF) {
		printf("%d\n", supersum(k, n));
	}
	return 0;
} */
//¸Ş¸ğÀÌÁ¦ÀÌ¼Ç
// ½Ã°£ Àç´Â¹ı(m/s)
/*  #include <time.h>
	clock_t start, end;
	double result;
	start = clock();
	end = clock();
	result = (double)(end - start);
	printf("%dm/s", result); */
// ¿À°¢Çü
/* int arr[100] = { 0, };
int overlap = 3;
int five(int x) {
	if (x == 1) {
		arr[x] += 5;
		return arr[x];
	}
	if (arr[x] != 0) {
		return arr[x];
	}
	arr[x] += (5*x) + five(x - 1) - overlap;
	overlap += 2;
	return arr[x];
}
int main(void) {
	int x;
	scanf("%d", &x); 
	printf("%d \n", five(x));
	return 0;
} */
// ¸®¸ğÄÁ¹®Á¦ ½ÇÆĞ
/* int arr[100] = { 0, };
int cont = 0;
int remote(int a, int b) {
	if (a < b) {
		if (a + 10 <= b) {
			a += 10;
			cont++;
			return remote(a, b);
		}
		else if (a + 5 <= b) {
			a += 5;
			cont++;
			return remote(a, b);
		}
		else if (a + 1 <= b) {
			a += 1;
			cont++;
			return remote(a, b);
		}
	}
	else if (a > b) {
		if (a - 10 >= b) {
			a -= 10;
			cont++;
			return remote(a, b);
		}
		else if (a - 5 >= b) {
			a -= 5;
			cont++;
			return remote(a, b);
		}
		else if (a - 1 >= b) {
			a -= 1;
			cont++;
			return remote(a, b);
		}
	}
	else if (a = b) {
		return;
	}
}
int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	remote(a, b);
	printf("%d ", cont);
	return 0;
} */

