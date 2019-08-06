#include"double_list.h"

typedef struct student_info
{
	int num;
        char *name;
}student;

void print_data(const void * const p)//参数类型为void*
{
        const student * pp=p;
        printf("%d(%s) ",pp->num,pp->name);
}

int sort_list_num(const void * const p1, const void * const p2)
{
	const student * stu1=p1;
	const student * stu2=p2;
//	printf("stu1->num=%d stu2->num=%d\n",stu1->num,stu2->num);
	if(stu1->num > stu2->num)
		return 1;
	else
		return 0;
}

int  find_data_num(const void* const p1,const void* const p2)
{
	const student *student1 = p1;
	const student *student2 = p2;
	if (student1->num == student2->num) 
	{
		return 1;
	}
	return 0;
}

int main(int argc,char*argv[])
{
	list *my_list;
	my_list=init_list();
	
	student stu[]={{1,"ysq"},{2,"yhh"},{3,"yjg"},{4,"yxx"}};
	insert_back(my_list,&stu[0]);
	insert_back(my_list,&stu[1]);
	insert_back(my_list,&stu[2]);
	insert_back(my_list,&stu[3]);
	print_list(my_list,print_data);

	print_length(my_list);
	
	int ret=find_data(my_list, &stu[0], find_data_num);	
	printf("index of num is %d\n",ret);

	Sort_List(my_list, sort_list_num);
	print_list(my_list,print_data);	
	
	delete_back(my_list);
	delete_head(my_list);
	print_list(my_list,print_data);
	
//	student stu3={2,"yhh"};

//	delete_val(my_list,&stu3);
//	print_list(my_list,print_data);

	clean_list(my_list);
	my_list=NULL;
	return 0;
}

