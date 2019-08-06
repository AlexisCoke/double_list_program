#include"double_list.h"
#include"malloc.h"
node* create_node(void * const x)
{
	node *s = (node*)malloc(sizeof(node));	
	if(NULL == s)
	{
		return NULL;
	}
	s->data = x;
	s->front = NULL;
	s->next = NULL;
	return s;
}
list* init_list()
{  
 	list *l = (list*)malloc(sizeof(list));
	if(NULL == l)
	{
		return NULL;
	}
	l->first = NULL;
	l->last = NULL;
	l->size = 0;
	return l;
} 

int print_length(list * l)
{
	return l->size;
} 

void insert_back(list * l, void * const x)
{
	node *s = create_node(x);	
	if(l->size)
	{
		l->last->next = s;
		s->front = l->last;
		l->last = s;
	}
	else
	{
		l->first = s;
		l->last = s;
	}
	(l->size)++;
}

void insert_head(list * l, void * const x)//头部插入节点
{
	node *s = create_node(x);
	if(l->size)
        {
            	s->next = l->first;
				l->first->front = s;
                l->first = s;
        }
        else
        {
                l->first = s;
                l->last = s;
        }
	(l->size)++;
}


void print_list(list * l, void (*pt)(const void * const))//传入一个函数指针pt
{
	if(l->size == 0)
		return;
	node *p = l->first;
	while(NULL != p)
	{
		(*pt)(p->data);//调用print_data(void *)
		p = p->next;
	}
	printf("\n");
}

void delete_back(list * l)
{
	if(0 == l->size)
		return;
	if(1 == l->size)
	{
		free(l->first);
		l->first = NULL;
		l->last = NULL;
		(l->size)--;
	}
	node *p = l->last;
	l->last = p->front;
	p->front->next = NULL;
	free(p);
	(l->size)--;
}

void delete_head(list * l)
{
        if(0 == l->size)
                return;
	if(1 == l->size)
        {
                free(l->last);
                l->first = NULL;
		l->last = NULL;
                (l->size)--;
        }
	node *p = l->first;
	p->next->front = NULL;
	l->first = p->next;
	free(p);
        (l->size)--;
}

void delete_val(list * l,void * const x)
{
	if(l->size==0)
                return;
	node *p=l->first;
	int num=0;
	while(p!=NULL)
	{
		if(x==p->data)
		{
			if(p->next==NULL)
			{
				free(l->first);
				num++;
			}
			else
			{
				p->front->next=p->next;
				p->next->front=p->front;
				l->size--;
				num++;
				p=p->next;
			}
		}
		else
			p=p->next;
	}
	if(num==0)
		printf("所要查找数据不存在链表中!\n");
}

int find_data(list * l, void * const x, int (*fd)(const void * const, const void * const) )
{
	node *p = l->first;
	int index = 0;
	while(p != NULL)
	{
		if( (*fd)(p->data, x) == 1) 
		{
			return index;
		}
		p = p->next;
		index++;
	}
	return -1;
}

/*list*  sort_list(list *l, int (*pt)(const void * const ,const void * const))
{
	if(l->size==0||l->size==1)
		return l;
	int list_size=l->size;
	int i=0,j=0;
	int flag=-1;
	for(i=0;i<list_size;++i)
	{
		pnode p1=l->first;
       		pnode p2=p1->next;
		for(j=0;j<list_size-1-i;++j)
		{
			flag=(*pt)(p1->data, p2->data);
			if(1==flag)
			{
				if(p2->next==NULL)
				{
					p1->next=p2->next;
					p2->front=p1->front;
					p2->next=p1;
					p1->front->next=p2;
					p1->front=p2;
				}
				else
				{
					p1->next=p2->next;
                                        p2->front=p1->front;
                                        p2->next=p1;
                                        p1->front->next=p2;
					p2->next->front=p1;
					p1->front=p2;
					p2=p1->next;
				}
			}
			else
			{
				p1=p1->next;
				p2=p2->next;
			}
		}	
	}
	return l;		
}*/

void sort_list (node* first, node* last ,int(*cmp)(const void * const ,const void * const))
{
	if (first == last || !first || !last)  
	{
		return ;
	}
	node *low = first;
	node *high = last;
	 printf("first:%p last:%p\n",first,last);
	printf("low:%p high:%p\n",low,high);
	
   void *  p=first->data;
	printf("p:%p\n",p);
   while(first != last)
   {
      while (first != last && (*cmp)(p,last->data)) 
	  {
		 last = last->front;
	  }
	  if (first != last)
	  {
      first->data = last->data;
      first = first->next; 
	  }
	  else break;
      while (first != last && (*cmp)(first->data,p))
	  {
		  first = first->next;
	  }
      if (first != last)
	  {
          last->data = first->data;
          last = last->front;
        }
   else break;
   }
   last->data = p;
	printf("first:%p last:%p\n",first,last);
   printf("low:%p high:%p\n",low,high);
	printf("p:%p\n",p);
  if (low != first)
  {
	  sort_list(low,first->front,(*cmp));
  }
  if (first!=high)  
  {
	  sort_list(first->next,high,(*cmp));
  }	
}

void Sort_List (list *l, int (*sl)(const void* const ,const void* const))
{
	node *first = l->first;
  	node *last = l->last;
  	sort_list(first, last, (*sl));	
}

void clean_list(list * l)
{
	node *p = NULL;
	while(l->first)
	{
		p = l->first->next;
		free(l->first);
		l->first=p;
	}
	free(l);
	l->first = NULL;
	l->last = NULL;
}
