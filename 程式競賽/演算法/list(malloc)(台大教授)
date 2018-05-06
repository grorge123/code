#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
void printList(node*ptr)
{
	while(ptr!=NULL)
	{
		printf("%d ", ptr->data);
		ptr=ptr->next;
	} 
	puts("");
}
void freeList(node*ptr)
{
	node*ptr2;
	while(ptr!=NULL)
	{
		ptr2=ptr->next;
		free(ptr);
		ptr=ptr2;
	} 
}
node*getnode()
{
	node*p;
	p=(node *) malloc(sizeof(node));
	if(p==NULL)
	{
		printf("記憶體不足");
		exit(1);
	}
	return p;	
}
void freenode(node*p)
{
	free(p);
}
node *insert_node (node *head, node *ptr, node data)
{
	node *new_node; /* 新節點指標變數 */
	new_node = getnode(); /* 建立新節點,取得一個可用節點 */
	*new_node = data; /* 建立節點內容 */
	new_node->next = NULL; /* 設定指標初值 */
	if ( ptr == NULL ) /* 指標ptr是否是NULL */
		{
		/* 第一種情況: 插入第一個節點 */
		new_node->next = head; /* 新節點成為串列開始 */
		head = new_node;
		}
	else
	{
		if ( ptr->next == NULL ) /* 是否是串列結束 */
			/* 第二種情況: 插入最後一個節點 */
			ptr->next = new_node; /* 最後指向新節點 */
		else
		{
			/* 第三種情況: 插入成為中間節點 */
			new_node->next = ptr->next; /* (3) 新節點指向下一節點 (3)*/
			ptr->next = new_node; /* 節點ptr指向新節點 (4)*/
		}
	}
	return (head);
}
node *find_node(node *head, int num)
{
	node *ptr;
	ptr = head; /* 指向串列起始 */
	while ( ptr != NULL ) /* 走訪串列 */
	{
		if ( ptr->data == num ) /* 找尋data */
	 			return (ptr);
		ptr = ptr->next; /* 指向下一節點 */
	}
	return (ptr);
}
node *delete_node(node *head, node *ptr)
{
	node *previous; /* 指向前一節點 */
	if ( ptr == head ) /* 是否是串列開始 */
	/* 第一種情況: 刪除第一個節點 */
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr ) /* 找節點ptr的前節點 */
			previous = previous->next;
		if ( ptr->next == NULL ) /* 是否是串列結束 */
		/* 第二種情況: 刪除最後一個節點 */
			previous->next = NULL; /* 最後一個節點 */
		else
		/* 第三種情況: 刪除中間節點 */
			previous->next = ptr->next; /* 圖(3)之步驟(1) */
	}
	freenode(ptr); /* 此函數將節點歸還給記憶體 */
	return(head);
}



int main()
{
	int pos,i;
	node*head, *ptr;
	node input;
	int value;
	head=ptr=NULL;
	char op;
	while(1)
	{
		//puts("i");
		//puts("f");
		//puts("d");
		//puts("l");
		//puts("q");
		scanf(" %c ", &op);
		switch(op)
		{
			case 'i':
				scanf("%d", &input.data);
				if(head==NULL)
				{
					head=insert_node (head, NULL, input);
				}
				else
				{
					ptr=head;
					while(ptr->next!=NULL)
					{
						ptr=ptr->next;
					}
					head=insert_node (head, ptr, input);
				}				
				break;
			case'j':
				scanf("%d", &input.data);
			    head=insert_node (head, NULL, input);				
				break;
			case'n':
				scanf("%d", &value);
				ptr = find_node(head, value);
				if(ptr!=NULL)
				{
					scanf("%d", &input.data);
					head=insert_node (head, ptr, input);
				}
				else
				{
					printf("not found,can not insert");
				}
				break;
			case'm':
				scanf("%d", &pos);
				if(pos=0)
				{
					scanf("%d", &input.data);
					head=insert_node (head, NULL, input);
					break;
				}
				ptr=head;
				for(i=0;i<pos-1;i++)
				{
					if(ptr->next==NULL)break;
					ptr=ptr->next;
				}
				head=insert_node (head, ptr, input);
				scanf("%d", &input.data);
			case 'l':
				printList(head);
				break;
			case 'f':
				scanf("%d", &value);
				ptr = find_node(head, value);
				if(ptr!=NULL)
				{
					printf("found %d\n", ptr->data);
				}
				else
				{
					printf("not found");
				}
				break;
			case 'd':
				scanf("%d", &value);
				ptr=find_node(head, value);
				if(ptr!=NULL) 
				{
					head=delete_node(head, ptr);
					printf("Delete ok\n");
				}
				else
				{
					printf("cannot delete\n");
				}
				break;
			case 'q':
				freeList(head);
				return 0;
				break;
		}
	}
	return 0;
}
	
