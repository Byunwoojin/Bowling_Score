#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_FRAME 10
#define STRIKE 1
#define SPARE 2
#define NONE 3
struct frame {
	int first;
	int second;
	int result;
};
typedef struct frame score;
typedef struct node_type *node_ptr;
struct node_type {
	score data;
	node_ptr link;
};

void sum_score(node_ptr list, int i);
node_ptr list, node1, node2, node3, node4, node5, node6, node7, node8, node9, node10, node11;
int sum = 0; state = 0; str_count = 0; int s_sum[11];
void main() {
	int score1 = 0; int score2 = 0; node_ptr p;
	node1 = (node_ptr)malloc(sizeof(struct node_type));
	list = node1; p = node1;
	node2 = (node_ptr)malloc(sizeof(struct node_type));
	node1->link = node2;
	node3 = (node_ptr)malloc(sizeof(struct node_type));
	node2->link = node3;
	node4 = (node_ptr)malloc(sizeof(struct node_type));
	node3->link = node4;
	node5 = (node_ptr)malloc(sizeof(struct node_type));
	node4->link = node5;
	node6 = (node_ptr)malloc(sizeof(struct node_type));
	node5->link = node6;
	node7 = (node_ptr)malloc(sizeof(struct node_type));
	node6->link = node7;
	node8 = (node_ptr)malloc(sizeof(struct node_type));
	node7->link = node8;
	node9 = (node_ptr)malloc(sizeof(struct node_type));
	node8->link = node9;
	node10 = (node_ptr)malloc(sizeof(struct node_type));
	node9->link = node10;
	node11 = (node_ptr)malloc(sizeof(struct node_type));
	node10->link = node11;
	node11->link = NULL;
	while (p->link) {
		p->data.first = 0;
		p->data.second = 0;
		p->data.result = 0;
		p = p->link;
	}
	node11->data.first = 0;
	node11->data.second = 0;
	node11->data.result = 0;
	node_ptr temp = list;
	int i = 1;
	while (temp->link) {
		printf("First score of the %d frame  : ", i); scanf("%d", &temp->data.first);
		printf("Second score of the %d frame : ", i); scanf("%d", &temp->data.second);
		sum_score(temp, i);
		temp = temp->link;
		i++;
	}
	if (state == STRIKE&& temp == node11) {

		printf("Bonus score1: "); scanf("%d", &node11->data.first);
		printf("Bonus score2: "); scanf("%d", &node11->data.second);
		if (str_count == 1 || str_count == 2)
			sum += temp->data.first + temp->data.second;
		if (str_count == 2)sum += node11->data.first;
	}
	if (state == SPARE &&temp == node11) {
		printf("Bonus score1: "); scanf("%d", &node11->data.first);
		sum += node11->data.first;
	}
	printf("(Bonus %d, %d)\n", node11->data.first, node11->data.second);
	printf("total : %d\n\n", sum);
	int k;
	printf("\n\n");
	printf("       |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  | Bonus |\n");
	printf("\n-------------------------------------------------------------------------------\n");
	printf(" First |");
	for (k = 1, p = node1; p->link; p = p->link, k++) {
		if (p->data.first == 0)
			printf("  式  |");
		else printf(" %3d |", p->data.first);
	}
	if (node11->data.first == 0)printf("  式     |");
	else printf(" %3d    |", node11->data.first);
	printf("\n-------------------------------------------------------------------------------\n");
	printf("Second |");
	for (k = 1, p = node1; p->link; p = p->link, k++) {
		if (p->data.second == 0)
			printf("  式  |");
		else printf(" %3d |", p->data.second);
	}
	if (node11->data.first == 0)printf("  式     |");
	else printf(" %3d    |", node11->data.second);
	printf("\n--------------------------------------------------------------------------------\n");
	printf(" Score |");
	for (k = 1; k < i; k++) {
		printf(" %3d |", s_sum[k]);
	}
	printf(" %3d    |", sum);
	printf("\n--------------------------------------------------------------------------------\n\n");

}


void sum_score(node_ptr node, int i) {
	node_ptr temp = node; int j = i; node_ptr p; int k = 1;
	switch (state) {
	case STRIKE:
		if (str_count == 1 || str_count == 2)
			sum += temp->data.first + temp->data.second;
		if (str_count == 2)sum += temp->data.first;
		break;
	case SPARE:sum += temp->data.first;
		break;
	default:break;
	}
	if (temp->data.first == 10) {
		temp->data.result = STRIKE;
		sum += temp->data.first;
		temp->data.result = STRIKE;
		if (str_count == 0)str_count++;
		if (state == STRIKE) {
			if (str_count == 2)str_count--;
			str_count++;
		}
		state = STRIKE;
	}
	else if ((temp->data.first + temp->data.second) == 10) {
		temp->data.result = SPARE;
		state = SPARE;
		str_count = 0;
		sum += temp->data.first + temp->data.second;
	}
	else {
		temp->data.result = NONE;
		str_count = 0;
		state = NONE;
		sum += temp->data.first + temp->data.second;
	}
	s_sum[j] = sum;
	switch (temp->data.result) {
	case STRIKE:printf("%d/%d: %d STRIKE!\n", temp->data.first, temp->data.second, sum);
		break;
	case SPARE:printf("%d/%d: %d Spare\n", temp->data.first, temp->data.second, sum);
		break;
	default: printf("%d/%d: %d\n", temp->data.first, temp->data.second, sum);
		break;
	}
	printf("\n\n");
	printf("       |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  | Bonus |\n");
	printf("\n-------------------------------------------------------------------------------\n");
	printf(" First |");
	for (k = 1, p = node1; p->link; p = p->link, k++) {
		if (k <= i&&p->data.first == 0)
			printf("  式  |");
		else if (k > i&&p->data.first == 0)
			printf("     |");
		else printf(" %3d |", p->data.first);
	}
	printf("\n-------------------------------------------------------------------------------\n");
	printf("Second |");
	for (k = 1, p = node1; p->link; p = p->link, k++) {
		if (k <= i&&p->data.second == 0)
			printf("  式  |");
		else if (k > i&&p->data.second == 0)
			printf("     |");
		else printf(" %3d |", p->data.second);
	}
	printf("\n--------------------------------------------------------------------------------\n");
	printf(" Score |");
	for (k = 1; k <= j; k++) {
		printf(" %3d |", s_sum[k]);
	}printf("\n--------------------------------------------------------------------------------\n\n");
}
