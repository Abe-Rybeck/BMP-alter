#include <stdio.h>
#include <stdlib.h>

struct Node{
	int grade;
	struct Node* next;
};
void clean(struct Node* head);
int main(){
	char cont = 121;
	while(cont == 121){
		int input;
		struct Node* last;
		struct Node* head;
		head = (struct Node*)malloc(sizeof(struct Node)); //head
		last = head;
		printf("input grade, or enter '-1' to end: ");
		scanf("%d",&input);
		while(input != -1){
			struct Node* point = (struct Node*)malloc(sizeof(struct Node));
			point->grade = input;
			last->next = point;
			last = point;
			printf("input grade, or enter '-1' to end: ");
			scanf("%d",&input);
		}
		
		//print
		struct Node* show;
		show = head;
		int count;
		int total = 0;
		for(count=0;show->next != NULL;count++){
			show = show->next;
			total += show->grade;
		}	
		double avg = (double) total/ (double) count;
		printf("avg: %.2f\n",avg);
		
		//clean
		clean(head);
		printf("continue? y/n: ");
		scanf(" %c",&cont);
	}
return 0;
}
void clean(struct Node* current){
	struct Node* next;
	if(current->next != NULL){
		next = current->next;
		clean(next);
	}
	free(current);
	current = NULL;
}