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
	struct Stu *head = NULL;   //创建头指针 
	printf("请输入你想要创建的节点个数：\n");
	scanf("%d",&n);
	head = create(n);
	print(head);
	while(true){
	printf("请选择你想要执行的操作：\n");
	printf("1.插入节点\n2.删除节点\n3.修改节点\n4.退出程序\n");
	scanf(" %c",&c);
	if(c =='1'){
	printf("你想要在哪插入节点：\n");
	scanf("%d",&in);
	insertNode(head,in);
	print(head); 
	}else if(c == '2'){
	printf("你想要删除哪个节点的数据：\n");
	scanf("%d",&j);
	deleteNode(head,j);
	print(head);
	}else if(c =='3'){
	printf("你想要修改哪个节点的数据：\n");
	scanf("%d",&cn);
	change(head,cn);
	print(head); 
	}else if(c =='4'){
		exit(0);
	} 		
 } 
}
struct Stu *create(int n){
	struct Stu *head,*node,*end;   						//定义头节点，普通节点，尾节点 
	head = (struct Stu *)malloc(sizeof(struct Stu)); 	//给头节点申请内存 
	//head->id = n;										//头节点的数据域保存链表的长度 
	end = head;        									//若是空表，则头尾地址一致 
	for(int i=0;i<n;i++){								//利用for循环向链表中添加数据 
		node = (struct Stu *)malloc(sizeof(struct Stu));//给普通节点申请内存空间 
		scanf("%d %s",&node->id,node->name);			//给数据域赋值 
		end->next = node;								//让上一个节点的数据域指向当前节点 
		end = node;     								//end指向当前节点，最终end指向尾节点 
	}
	end->next = NULL;                                   //给end的指针域置空 
	return head;                                        //返回头节点的地址 
}
void print(struct Stu *head){
	struct Stu *p = head;
	int j =1;
	p = p->next;  //不打印头节点的数据域中的值 
	while(p != NULL){
		printf("%d\t%d\t%s\n",j,p->id,p->name);
		p = p->next;
		j++;
	}
}
void deleteNode(struct Stu *head,int n){         //删除n处的节点 
	struct  Stu *p = head,*pr = head;
	int i =0;
	while(i<n&&p!=NULL){       //到达指定节点，此时p指向指定节点，pr指向上一节点 
		pr = p;
		p = p->next;
		i++;
	}
	if(p!=NULL){
		pr->next = p->next;
		free(p);
	} else{
		printf("节点不存在！\n"); 
	}
} 
void insertNode(struct Stu *head,int n){    //插入节点 
	struct Stu *p = head,*pr;
	pr = (struct Stu*)malloc(sizeof(struct Stu));  //让pr指向新建节点申请的内存 
	printf("input data:\n");
	scanf("%d %s",&pr->id,pr->name);
	int i = 0;
    //当插入位置是尾节点时，只要在尾节点后再插入一个节点，并让尾节点的指针域指向新建节点，新建节点的指针域置空
    while(i<n&&p!=NULL){             //使p指向将要插入节点的位置 
    	p = p->next;
		i++;
	}
	if(p!=NULL){            //如果p没越界 
		pr->next = p->next; //将新建节点的地址指向将要插入节点的后一个节点的地址 
		p->next = pr;       //使插入节点指向新建节点 
	}else{
		printf("节点不存在！\n");
	}
}
void change(struct Stu *head,int n){
	struct Stu *p = head;
	int i = 0;
	while(i<n && p!=NULL){      //使p指向需修改节点 
		p = p->next;
		i++;
	}
	if(p != NULL){             
	printf("请输入修改之后的值:\n");
	scanf("%d %s",&p->id,p->name);	
	}else{
		printf("节点不存在！\n");
	} 	 
} 
