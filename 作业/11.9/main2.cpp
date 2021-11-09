#include <stdio.h> 
#include <stdlib.h>
struct Stu *create(int n);
void print(struct Stu *head);
void deleteNode(struct Stu *head,int n);
void insertNode(struct Stu *head,int n);
void change(struct Stu *head,int n);
struct Stu{
	int id;
	char name[50];
	struct Stu *next;
};
int main(){
	int n,j,in,cn;
	char c;
	struct Stu *head = NULL;   //����ͷָ�� 
	printf("����������Ҫ�����Ľڵ������\n");
	scanf("%d",&n);
	head = create(n);
	print(head);
	while(true){
	printf("��ѡ������Ҫִ�еĲ�����\n");
	printf("1.����ڵ�\n2.ɾ���ڵ�\n3.�޸Ľڵ�\n4.�˳�����\n");
	scanf(" %c",&c);
	if(c =='1'){
	printf("����Ҫ���Ĳ���ڵ㣺\n");
	scanf("%d",&in);
	insertNode(head,in);
	print(head); 
	}else if(c == '2'){
	printf("����Ҫɾ���ĸ��ڵ�����ݣ�\n");
	scanf("%d",&j);
	deleteNode(head,j);
	print(head);
	}else if(c =='3'){
	printf("����Ҫ�޸��ĸ��ڵ�����ݣ�\n");
	scanf("%d",&cn);
	change(head,cn);
	print(head); 
	}else if(c =='4'){
		exit(0);
	} 		
 } 
}
struct Stu *create(int n){
	struct Stu *head,*node,*end;   						//����ͷ�ڵ㣬��ͨ�ڵ㣬β�ڵ� 
	head = (struct Stu *)malloc(sizeof(struct Stu)); 	//��ͷ�ڵ������ڴ� 
	//head->id = n;										//ͷ�ڵ�������򱣴�����ĳ��� 
	end = head;        									//���ǿձ���ͷβ��ַһ�� 
	for(int i=0;i<n;i++){								//����forѭ����������������� 
		node = (struct Stu *)malloc(sizeof(struct Stu));//����ͨ�ڵ������ڴ�ռ� 
		scanf("%d %s",&node->id,node->name);			//��������ֵ 
		end->next = node;								//����һ���ڵ��������ָ��ǰ�ڵ� 
		end = node;     								//endָ��ǰ�ڵ㣬����endָ��β�ڵ� 
	}
	end->next = NULL;                                   //��end��ָ�����ÿ� 
	return head;                                        //����ͷ�ڵ�ĵ�ַ 
}
void print(struct Stu *head){
	struct Stu *p = head;
	int j =1;
	p = p->next;  //����ӡͷ�ڵ���������е�ֵ 
	while(p != NULL){
		printf("%d\t%d\t%s\n",j,p->id,p->name);
		p = p->next;
		j++;
	}
}
void deleteNode(struct Stu *head,int n){         //ɾ��n���Ľڵ� 
	struct  Stu *p = head,*pr = head;
	int i =0;
	while(i<n&&p!=NULL){       //����ָ���ڵ㣬��ʱpָ��ָ���ڵ㣬prָ����һ�ڵ� 
		pr = p;
		p = p->next;
		i++;
	}
	if(p!=NULL){
		pr->next = p->next;
		free(p);
	} else{
		printf("�ڵ㲻���ڣ�\n"); 
	}
} 
void insertNode(struct Stu *head,int n){    //����ڵ� 
	struct Stu *p = head,*pr;
	pr = (struct Stu*)malloc(sizeof(struct Stu));  //��prָ���½��ڵ�������ڴ� 
	printf("input data:\n");
	scanf("%d %s",&pr->id,pr->name);
	int i = 0;
    //������λ����β�ڵ�ʱ��ֻҪ��β�ڵ���ٲ���һ���ڵ㣬����β�ڵ��ָ����ָ���½��ڵ㣬�½��ڵ��ָ�����ÿ�
    while(i<n&&p!=NULL){             //ʹpָ��Ҫ����ڵ��λ�� 
    	p = p->next;
		i++;
	}
	if(p!=NULL){            //���pûԽ�� 
		pr->next = p->next; //���½��ڵ�ĵ�ַָ��Ҫ����ڵ�ĺ�һ���ڵ�ĵ�ַ 
		p->next = pr;       //ʹ����ڵ�ָ���½��ڵ� 
	}else{
		printf("�ڵ㲻���ڣ�\n");
	}
}
void change(struct Stu *head,int n){
	struct Stu *p = head;
	int i = 0;
	while(i<n && p!=NULL){      //ʹpָ�����޸Ľڵ� 
		p = p->next;
		i++;
	}
	if(p != NULL){             
	printf("�������޸�֮���ֵ:\n");
	scanf("%d %s",&p->id,p->name);	
	}else{
		printf("�ڵ㲻���ڣ�\n");
	} 	 
} 
