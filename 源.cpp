#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L1 sizeof(struct Student)
#define L2 sizeof(struct Score)

//学生基本信息
struct Student {      
		char Name[5];                                                                               //姓名
		int ID ;                                                                                          //学号   不重复，不删减
		char Major[10] ;                                                                           //专业
		int Class;                                                                                      //班级
		struct Student *next;
};
typedef struct Student Student;
static int id = 20200000;                                                                        //学号
static int Student_num = 0;                                                                    //现有人数
Student* student_head = nullptr, * student_end = nullptr;                   //学生基本信息链表的头，尾
//成绩
struct Score {     
	int ID;                                                                                                //学号
	char Student_Name[5];                                                                     //姓名
	char S_Name[4][10];                                                                       //课程名称
	int Score[4];                                                                                     //分数
	struct Score* next;
};
typedef struct Score Score;
Score* score_head = nullptr, * score_end = nullptr;
static int Score_num = 0;
//课程名称与编号
struct Sourse {    
	int S_ID;                                                                                         //课程编号
	char S_Name[10];                                                                          //课程名称
}sourse[4];
typedef struct Sourse Sourse;

/*函数声明*/
void menu();                                                                        //主菜单界面
void input();                                                                        //信息录入
void in_menu();                                                                  //录入子菜单界面
Student* input_student();                                                   //学生基本信息录入
Score* input_score();                                                         //学生成绩录入
void input_sourse();                                                           //课程名称与编号录入
void search();                                                                     //信息查询
void search_menu();                                                          //查询子菜单界面
int Search_choose();                                                           //查询方式
Student* search_student();                                                 //学生基本信息查询
Score* search_score();                                                       //学生成绩查询
Sourse* search_sourse();                                                    //课程名称与编号查询
void Display_Student();                                                     //学生基本信息遍历
void display_student(Student* This);                                //个人基本信息显示
void Display_Score();                                                        //总成绩遍历
void display_score(Score* This);                                      //个人成绩显示
void Display_sourse();                                                       //课程目录遍历
void display_sourse(Sourse* This);                                   //课程显示
void del();                                                                           //信息删除
void del_menu();                                                               //删除子菜单界面
Student* del_student(Student* This);                                //删除学生基本信息
Score* del_score(Score* This);                                        //删除学生成绩
Sourse* del_sourse(Sourse* This);                                   //删除课程
void modify();                                                                    //信息修改
void modify_menu();                                                        //修改子菜单界面
Student* modify_student(Student* This);                         //修改个人基本信息
Score* modify_score(Score* This);                                 //修改个人成绩
Sourse* modify_sourse(Sourse* This);                            //修改课程名称
void statistical();                                                               //信息统计
void statistical_menu();                                                    //统计子菜单界面
void sourse_score();                                                         //统计方式：课程名+分数段
void del_all();                                                                   //清空系统
void  ReadStudent();                                                        //读取学生个人基本信息
void ReadScore();                                                            //读取学生成绩
void ReadSchool();                                                          //读取课程名称与编号
void WriteStudent();                                                        //保存学生个人基本信息
void WriteScore();                                                          // 保存学生成绩
void WriteSchool();                                                        //保存课程名称与编号
/*主函数*/
int main() {
	int num;
	do {
		menu();                                                                //主菜单
		scanf_s("%d", &num);                                        //编号
		switch (num) {
		case 1: {                                                              //读取
			ReadStudent(); 
			ReadScore();
			ReadSchool();
			printf("读取成功。\n");
			system("pause");
			break;}
		case 2: {input();break;}                                        //录入
		case 3: {statistical();break;}                                 //统计
		case 4:{search();break;}                                       //查询
		case 5:{modify();break;}                                     //修改
 		case 6:{del();break;}                                           //删除

		case 7: {                                                             //保存
			WriteStudent();
			WriteScore();
			WriteSchool();
			break;}                         //退出
		}
	} while (num != 7);
	del_all();
	printf("------------------------------已退出系统----------------------------------\n");
}

/*---主菜单---*/
void menu() {
	system("cls");
	printf("****************************学生成绩管理系统*********************************\n");
	printf("                                  菜单 \n");
	printf(" 1.读取                                             2.录入\n");
	printf(" 3.统计                                             4.查询 \n");
	printf(" 5.修改                                             6.删除\n");
	printf(" 7.退出(保存文档)\n");
	printf("\n*****************************************************************************\n");
	printf(" 欢迎使用学生成绩管理系统，请输入你要查询的编号：");
}

/*
*功能：录入学生基本信息、成绩，当前学年学期，课程编号与名称
*/
void input() {
	int in_num=0;                                                       
	do {
		in_menu();                                                          //录入子菜单
		printf("请输入编号:");
		scanf_s("%d", &in_num);                                
			switch (in_num) {
			case 1: {input_student();break;}                  
			case 2: {input_score();break;}                                        
			case 3: {input_sourse();break;}                  
			case 4:break;                                                 
		}
	} while (in_num != 4);
}

//录入子菜单
void in_menu() {
	system("cls");
	printf("********************************录入******************************************\n");
	printf(" 1.学生基本信息。\n");
	printf(" 2.学生成绩。\n");
	printf(" 3.课程编号及名称\n");
	printf(" 4.返回上一级目录\n");
	printf("******************************************************************************\n");
}
 

/*
*功能：录入学生个人基本信息，以链表形式储存，记录学生信息个数。
*返回：链表头 
*/
Student* input_student()   //返回链表头地址                
{
	Student* Snew = (Student*)malloc(L1);                    
	Snew->next = nullptr;
	do {
		if (Snew == nullptr) {
			free(Snew);
			Student* Snew = (Student*)malloc(L1);
		}
	} while (Snew == nullptr);
	Student_num++;                                                         
	printf("请输入姓名：");                                            
	scanf_s("%s", &Snew->Name,5);
	fflush(stdin);
	Snew->ID =++id;
	printf("您的学号为%d。\n",Snew->ID);
	printf("请输入专业：");
	scanf_s("%s", &Snew->Major,10);
	fflush(stdin);
	printf("请输入班级(小写)：");
	scanf_s("%d",&Snew->Class);
	fflush(stdin);
	//链接
	if (student_head == nullptr) {                                         //空链表链接
		student_head = student_end = Snew;
	}
	else {                                                                               //非空链表
		student_end->next = Snew;
		student_end = Snew;
		student_end->next = nullptr;
	}
	printf("已录入。\n");
	system("pause");
	return student_head;
}
/*
*功能：录入学生个人成绩，以链表形式储存。
*返回：链表头
*/
Score* input_score() {
	Score* Snew = (Score*)malloc(L2);                              
	Snew->next = nullptr;
	do {
		if (Snew == nullptr) {
			free(Snew);
			Score* Snew = (Score*)malloc(L2);
		}
	} while (Snew == nullptr);
	Score_num++;
	printf("请输入姓名：");                                             
	scanf_s("%s", &Snew->Student_Name,5);
	printf("请输入学号：");
	scanf_s("%d", &Snew->ID);
	for (int i = 0;i < 4;i++) {
		strcpy_s(Snew->S_Name[i], sourse[i].S_Name);
		printf("%s\n", &Snew->S_Name[i]);
     	printf("请输入分数：");
	    scanf_s("%d", &Snew->Score[i]);
	}
		//链接
	if (score_head == nullptr) {                                           //空链表链接
		score_head = score_end = Snew;
	}
	else {                                                                                //非空链表
		score_end->next = Snew;
		score_end = Snew;
		score_end->next = nullptr;
	}
	printf("已录入。\n");
	system("pause");
	return score_head;
}
/*
*功能：录入课程编号，名称，以数组形式存储，共四组。
*/
void input_sourse() {
	for (int i = 0;i < 4;i++) {
		printf("请输入课程名称：");
		scanf_s("%s", &sourse[i].S_Name, 10);
		printf("请输入课程编号：");
        scanf_s("%d", &sourse[i].S_ID);
	}
	printf("已录入。\n");
	system("pause");
}
/*信息统计*/
void statistical() {
	int statis_num;
	do {
		statistical_menu();
		printf("请输入编号：");
		scanf_s("%d", &statis_num);
		switch (statis_num) {
		case 1: {                                                                       //课程+分数段
			sourse_score();
			system("pause");
			break;
		}
		case 2: { Display_Score();break;}                              //总成绩单遍历
		case 3: {Display_Student();break;}                            //学生基本信息
		case 4: { Display_sourse();break; }
		case 5:break;                                                                //返回上一级
		}
	} while (statis_num != 5);
}
//统计子菜单
void statistical_menu() {
	system("cls");
	printf("********************************统计******************************************\n");
	printf(" 成绩统计方式：\n");
	printf(" 1.课程名称+分数段。\n");
	printf(" 2.总成绩单\n");
	printf(" 3.学生基本信息\n");
	printf(" 4.课程名称与编号表\n");
	printf(" 5.返回上一级目录\n");
	printf("******************************************************************************\n");
}
//课程名称+分数段
void sourse_score() {
	Sourse* This = nullptr;
	char name[10];
	printf("请输入课程：");
	scanf_s("%s", &name, 10);                               //要查询的课程名
	fflush(stdin);
	//查找课程
	int i = 0;
	for (; i < 4;i++) {
		if (strcmp(sourse[i].S_Name, name) == 0)break;       //查找课程位置
	}
	if (i == 4) { printf("没有此课程"); return; }                   //没有 退出， 有 继续
	int up, down;
	printf("请输入上限：");
	scanf_s("%d", &up);
	printf("请输入下限：");
	scanf_s("%d", &down);
	Score* p = score_head;
	printf("\t\t姓名\t学号\t\t%s\n", &p->S_Name[i]);
	printf("\t\t------------------------------------------\n");
	while (p != nullptr) {
		if (p->Score[i] <= up && p->Score[i] >= down) {    //课程对应分数段判断
			printf("\t\t%s\t%d\t%d\n", p->Student_Name, p->ID, p->Score[i]);
			printf("\t\t------------------------------------------\n");
		}
		p = p->next;
	}
}
/*
功能：信息查询  个人基本信息，个人成绩。
*/
void search() {
	int search_num;
	do {
		search_menu();                                                                     
		printf("请输入编号：");
		scanf_s("%d", &search_num);                                            
		switch(search_num) { 
		    case 1: {display_student(search_student()); break;}        
			case 2:{display_score(search_score()); break;}          
			case 3: break;                          

				}
	}while (search_num != 3);
}

//查询子菜单
void search_menu() {
	system("cls");
	printf("********************************查询******************************************\n");
	printf(" 1.学生基本信息。\n");
	printf(" 2.学生成绩。\n");
	printf(" 3.返回上一级目录\n");
	printf("******************************************************************************\n");
}
/*
功能：查询方式的选择：字符 / 数字。
*/
int Search_choose() {
	int choose=0;
	printf("查询方式选择：\n");
	printf("1.姓名/课程名\n");
	printf("2.学号/课程编号\n");
	printf("请选择：");
	scanf_s("%d", &choose);
	return choose;
}
/*
功能：查询学生基本信息，先选择输入数据类型（字符 / 数字）遍历链表匹配
            匹配成功，返回地址；匹配不成功，提示用户，返回空指针。
*/
Student* search_student() {
	//查询方式选择，查询，显示
    Student* This = student_head;
	//选择查询方式
	if (Search_choose() == 1) {                                            //姓名查询 
		char name[5];
		printf("请输入姓名：");
		scanf_s("%s", &name,5);                                             
		fflush(stdin);                                                                  
		//查找name
		while (This != nullptr) {                                               
			if (strcmp(This->Name, name) == 0)break;            
			else This = This->next;                                              
		}
		if (This == nullptr) {
			printf("系统中没有此人。请检查姓名是否正确，重新查询\n");	
			return nullptr;                                                            
		}      
		else return This;                                                           
	}
	else {                                                                                  //学号查询
		int id;
		printf("请输入学号(20xxxxxx)：");
		scanf_s("%d", &id);                                                     
		fflush(stdin);
		while (This != nullptr) {                                               
			if (This->ID == id) {                                            
				return This;
			}
			else This = This->next;
		}
        if (This == nullptr) {
	    	printf("系统中没有此人信息。请检查学号是否正确，重新查询\n");
	    	return nullptr;                                                               
	    }
	}
}
//查询学生成绩   返回数组地址 没有为空
Score* search_score() {               
	Score* This=score_head;
	//查询方式选择
	if (Search_choose() == 1) {                                               //姓名查询
		char name[5];
		printf("请输入姓名：");
		scanf_s("%s", &name, 5);                                       
		fflush(stdin);
		while (This != nullptr) {
			if (strcmp(This->Student_Name, name) == 0)break;
			else This = This->next;
		}
			if (This != nullptr) return This;                             
			else {
				printf("没有此人信息。\n");
				return nullptr;
			}
		
	}
	else {                                                                                 //学号查询
		int id;
		printf("请输入学号(20xxxxxx)：");
		scanf_s("%d", &id);                                                    
		fflush(stdin);
		while (This != nullptr) {
			if (This->ID == id) {                                               
				return This;
			}
			else This = This->next;
		}
		if (This == nullptr) {
			printf("没有此人信息。\n");
			return nullptr;
		}
	}
}
//查询课程名称与编号     返回数组地址 没有为空
/*
功能：查询课程名称与编号  调用方式选择函数（字符  /  数组）
*/
Sourse* search_sourse() {
	Sourse* This = nullptr;
	//查询方式选择
	if (Search_choose() == 1) {                                             //课程名查询
		char name[10];
		printf("请输入课程：");
		scanf_s("%s", &name, 10);                                        //要查询的课程
		fflush(stdin);
		int i = 0;
		for (; i < 4;i++) {
			if (strcmp(sourse[i].S_Name, name) == 0)break;       //判断
		}
		if (i != 4) { 
            This = &sourse[i];                                                  //找到，返回数组的地址
			return This; }
		else {
			printf("没有此课程。\n");
		}

	}
	else {                                                                             //编号查询
		int id;
		printf("请输入课程编号：");
		scanf_s("%d", &id);                                                  //需要查询的编号
		fflush(stdin);
		for (int i = 0;i < 4;i++) {
			if (sourse[i].S_ID == id) {
				return &sourse[i];                                             //找到返回数组地址
			}
		}
        if (This==nullptr) {                                                      //没有找到
	    	printf("没有此课程。");
	} 
	}
	
	return nullptr;                                                               //返回空指针                                                              
}
/*显示*/
//学生基本信息遍历
void Display_Student() {
	Student* p = student_head;
	if (p == nullptr) { 
		printf("此表为空。");
	    system("pause");
	    return; 
	}
	while(p != nullptr){
		printf("\t----------------------------\n");
    	printf("\t姓名：%s\n", p->Name);
		printf("\t学号：%d\n",p->ID);
		printf("\t专业：%s\n",p->Major);
		printf("\t班级：%d\n",p->Class);
		p = p->next;
	}
	system("pause"); //冻结屏幕
}
//个人基本信息
void display_student(Student* This) {//需要显示处的地址
	if (This == nullptr) {
		system("pause");
		return;
	}
	printf("\t姓名：%s\n", This->Name);
	printf("\t学号：%d\n", This->ID);
	printf("\t专业：%s\n", This->Major);
	printf("\t班级：%d\n", This->Class);
	system("pause");
}
//总成绩遍历
void Display_Score() {
	Score* p = score_head;
	if (p == nullptr) { 
		printf("此表为空。");
		system("pause");
		return; 
	}
	printf("\t\t姓名\t学号\t\t%s\t%s\t%s\t%s\n", 
			p->S_Name[0], p->S_Name[1], p->S_Name[2], p->S_Name[3]);
	while (p != nullptr) {
		printf("\t\t----------------------------------------------------------\n");
		printf("\t\t%s\t%d\t%d\t%d\t%d\t%d\n", 
			p->Student_Name,p->ID, p->Score[0], p->Score[1], p->Score[2], p->Score[3]);
		printf("\t\t----------------------------------------------------------\n");
		p = p->next;
	}
	system("pause");
}
//个人成绩
void display_score(Score* This) {                            //需要显示处的地址
	if (This == nullptr) {
		system("pause");
		return;
	}
	printf("\t\t姓名\t学号\t\t%s\t%s\t%s\t%s\n",
		This->S_Name[0], This->S_Name[1], This->S_Name[2], This->S_Name[3]);
	printf("\t\t----------------------------------------------------------\n");
	printf("\t\t%s\t%d\t%d\t%d\t%d\t%d\n",
		This->Student_Name, This->ID, This->Score[0], This->Score[1], This->Score[2], This->Score[3]);
	printf("\t\t---------------------------------------------------------\n");
	system("pause");
}
//课程目录遍历
void Display_sourse() {
	for (int i = 0;i < 4;i++) {
		printf("课程编号：%d\n", sourse[i].S_ID);
		printf("课程名称：%s\n", &sourse[i].S_Name);
	}
	system("pause");
}
//课程显示
void display_sourse(Sourse* This) {//需要显示的地址
	if (This == nullptr)return;
	printf("课程编号：%d\n", This->S_ID);
	printf("课程名称：%s\n", This->S_Name);
	system("pause");
}

/*信息修改*/  
void modify() {
	int modify_num;                                                  //所选编号
	do {
		modify_menu();                                               //修改子菜单
		printf("请输入编号:");
		scanf_s("%d", &modify_num);
		switch (modify_num) {
		case 1 :{                                                           //修改个人基本信息
			Student* This = search_student();
			if (This == nullptr) {
				system("pause");
				break;
			}
			display_student(This);                                //查询，显示原信息
			printf("----------------\n");
			modify_student(This);                                //修改
			printf("----------------\n");
			printf("修改后：\n");
			display_student(This);                               //显示修改后信息
			system("pause");
			break;
		}
		case 2 :{                                                          //修改个人成绩
			Score* This = search_score();
			if (This == nullptr) { 
				system("pause");
				break; }
			display_score(This);                                  //查询，显示原信息
			printf("----------------\n");
			modify_score(This);                                  //修改
			printf("----------------\n");
			printf("修改后：\n");
			display_score(This);                                  //显示修改后信息
			system("pause");
			break;
		}
		case 3 :{                                                         //修改课程名称 编号
			Sourse* This = search_sourse();                
			if (This == nullptr) {
				system("pause");
				break;
			}
			display_sourse(This);                                //查询，显示原信息
			printf("----------------\n");
			modify_sourse(This);                                //修改
			printf("----------------\n");
			printf("修改后：\n");
			display_sourse(This);                               //显示修改后信息
			break;
		}
		case 4:break;                                                //返回上一级
		}
	} while (modify_num != 4);
}

/*修改子菜单*/
void modify_menu() {
	system("cls");
	printf("********************************修改******************************************\n");
	printf(" 1.学生基本信息。\n");
	printf(" 2.学生成绩。\n");
	printf(" 3.课程编号及名称\n");
	printf(" 4.返回上一级目录\n");
	printf("******************************************************************************\n");
}
/*修改个人基本信息*/
Student* modify_student(Student* This) {
	printf("请重新输入姓名：");                                   //信息重新录入；
	scanf_s("%s", &This->Name, 5);
	fflush(stdin);
	printf("您的学号为%d。\n", This->ID);
	printf("请重新输入专业：");
	scanf_s("%s", &This->Major, 10);
	fflush(stdin);
	printf("请重新输入班级(小写)：");
	scanf_s("%d", &This->Class);
	fflush(stdin);
	return This;
}
/*修改个人成绩*/
Score* modify_score(Score*This) {
	printf("请重新输入姓名：");                                   //信息重新录入；
	scanf_s("%s", &This->Student_Name, 5);
	printf("请重新输入学号：");
	scanf_s("%d", &This->ID);
	for (int i = 0;i < 4;i++) {
		strcpy_s(This->S_Name[i], sourse[i].S_Name);
		printf("%s\n", &This->S_Name[i]);
		printf("请重新输入分数：");
		scanf_s("%d", &This->Score[i]);
	}
	return This;
}
/*修改课程名称*/
Sourse* modify_sourse(Sourse* This) {
	printf("请重新输入课程名称：");                            //信息重新录入
	scanf_s("%s", &This->S_Name, 10);
	printf("请重新输入课程编号：");
	scanf_s("%d", &This->S_ID);
	return This;
}

/*信息删除*/
void del() {
	int del_num;
	do {
		del_menu();
		printf("请选择编号：");
		scanf_s("%d", &del_num);
		switch (del_num) {
		case 1: {                                                           //删除个人基本信息
			if (del_student(search_student()) == nullptr) {
				system("pause");
				break;
			}
			printf("成功删除。");
			system("pause");
			break;}
		case 2: {                                                           //删除个人成绩
			if (del_score(search_score()) == nullptr) {
				system("pause");
				break;
			}
			printf("成功删除。");
			system("pause");
			break;}
		case 3: {                                                          //删除课程
			if (del_sourse(search_sourse()) == nullptr) {
				system("pause");
				break;
			}
			printf("成功删除。");
			system("pause");
			break;}
		case 4:break;
		}
	} while (del_num != 4);
}
/*删除子菜单*/
void del_menu() {
	system("cls");
	printf("********************************删除******************************************\n");
	printf(" 1.学生基本信息。\n");
	printf(" 2.学生成绩。\n");
	printf(" 3.课程编号及名称\n");
	printf(" 4.返回上一级目录\n");
	printf("******************************************************************************\n");
}
/*
功能：删除学生基本信息
*/
Student* del_student(Student* This) {//返回链表，传入需要删除的地址
	if (This == nullptr)return nullptr;
	Student* p = This;
	Student_num--;
	if (student_head == student_end) {                         //只有一个节点
		free(p);                                                                 //删除
		student_head = student_end = nullptr;                //赋空
		return student_head;
	}
	if (student_head->next == student_end) {            //两个节点
		if (p == student_head) {                                      //头节点
			student_head = student_head->next;              //头后移
			free(p);                                                            //旧头删除
			return student_head;
		}
		if (p == student_end) {                                      //尾节点
			student_end = student_head;                         //尾前移
			student_end->next = nullptr;               
			free(p);                                                           //旧尾删除
			return student_head;
		}
	}
	else {                                                                      //两个节点以上
		if (p == student_head) {                                     //头节点
			student_head = student_head->next;
			free(p);
			return student_head;
		}
		Student* P = student_head;
		if (p == student_end) {                                      //尾节点
			while (P->next != p) {                                   //尾节点的前一个
				P = P->next;
			}
			student_end = P;                                            //尾前移
			P->next = nullptr;                              
			free(p);                                                           //删除
			return student_head;
		}
		else {                                                                  //中间节点
			while (P->next != p) {                                    //该节点的前一个           
				P = P->next;
			}
			P->next = p->next;                                          //该节点前一个连该节点的后一个
			free(p);                                                             //删除
			return student_head;
		}
	}
}
/*
功能：删除学生成绩
*/
Score* del_score(Score* This) {                               //返回链表，传入需要删除的地址
	if (This == nullptr)return nullptr;
	Score* p = This;
	Score_num--;
	if (score_head == score_end) {                             //只有一个节点
		free(p);                                                               //删除节点
		score_head = score_end = nullptr;                    //头尾赋空
		return score_head;
	}
	if (score_head->next == score_end) {                  //两个节点
		if (p == score_head) {                                       //头节点
			score_head = score_head->next;                   //头后移
			free(p);                                                           //删除
			return score_head;
		}
		if (p == score_end) {                                         //尾节点
			score_end = score_head;                               //尾前移
			score_end->next = nullptr;                    
			free(p);                                                           //删除
			return score_head;
		}
	}
	else {                                                                     //多个节点
		if (p == score_head) {                                       //头节点
			student_head = student_head->next;             //后移
			free(p);                                                           //删除
			return score_head;
		}
		Score* P = score_head;
		if (p == score_end) {                                         //尾节点
			while (P->next != p) {                                   //尾的前一个
				P = P->next;
			}
			score_end = P;                                               //尾前移
			P->next = nullptr;                                    
			free(p);                                                           //删除
			return score_head;
		}
		else {                                                                 //中间节点
			while (P->next != p) {                                   //该节点的前一个
				P = P->next;
			}
			P->next = p->next;                                        //前后相连
			free(p);                                                          //删除
			return score_head;
		}
	}

}
/*
功能：删除课程
返回数组首地址，传入需要删除的地址
*/
Sourse* del_sourse(Sourse* This) {
	if (This == nullptr)return nullptr;
	Sourse* p = This;
	p->S_ID = 0;                                                        //编号赋零
	strcpy_s(p->S_Name, "空");                                //名称赋空
	return sourse;
}
/*清空系统*/
void del_all() {
	Student* p = student_head,*P;
	while (p != nullptr) {
		P = p;
		p = p->next;
		free(P);
	}
	student_head = student_end = nullptr;
	Score* s = score_head, * S;
	while (s != nullptr) {
		S = s;
		s = s->next;
		free(S);
	}
	score_head = score_end = nullptr;
}

/*
功能：读取学生个人基本信息文件，建立链表
*/
void  ReadStudent() {
	FILE* fp;
	fopen_s(&fp, "Student.txt", "r");
	Student* p = nullptr;
	
	fscanf_s(fp, "%d\r\n", &Student_num);
	for (int i = 0;i < Student_num;i++) {
		p = (Student*)malloc(L1);
		p->next = nullptr;
		id++;
		do {
			if (p == nullptr) {
				free(p);
				Student* p = (Student*)malloc(L1);
				p->next = nullptr;
			}
		} while (p == nullptr);
	 fscanf_s(fp, "%s", p->Name, 5);
	 fscanf_s(fp, "%d", &(p->ID));
	 fscanf_s(fp, "%s", p->Major, 10);
	 fscanf_s(fp, "%d", &(p->Class));
		if (student_head == nullptr) {                                         //空链表链接
			student_head = student_end = p;
		}
		else {                                                                               //非空链表
			student_end->next = p;
			student_end = p;
			student_end->next = nullptr;
		}
	 }
	fclose(fp);
	
}
/*
功能：读取学生成绩
*/
void ReadScore() {
	FILE* fp;
	fopen_s(&fp, "Score.txt", "r");
	Score* p = nullptr;
	fscanf_s(fp, "%d\r\n", &Score_num);
	for (int i = 0;i < Score_num;i++) {
		p = (Score*)malloc(L2);
		p->next = nullptr;
		do {
			if (p == nullptr) {
				free(p);
				Score* p = (Score*)malloc(L2);
				p->next = nullptr;
			}
		} while (p == nullptr);
			fscanf_s(fp, "%s",p->Student_Name,5 );
			fscanf_s(fp, "%d",&(p->ID) );
			fscanf_s(fp, "%s", p->S_Name[0],10);
			fscanf_s(fp, "%d",&(p->Score[0]) );
			fscanf_s(fp, "%s", p->S_Name[1],10);
			fscanf_s(fp, "%d", &(p->Score[1]));
			fscanf_s(fp, "%s", p->S_Name[2],10);
			fscanf_s(fp, "%d", &(p->Score[2]));
			fscanf_s(fp, "%s", p->S_Name[3],10);
			fscanf_s(fp, "%d", &(p->Score[3]));
			if (score_head == nullptr) {                                           //空链表链接
				score_head = score_end = p;
			}
			else {                                                                                //非空链表
				score_end->next = p;
				score_end = p;
				score_end->next = nullptr;
			}
	}
	fclose(fp);
}
/*
功能：读取课程名称与编号
*/
void ReadSchool() {
	FILE* fp;
	fopen_s(&fp, "School.txt", "r");
	for (int i = 0;i < 4;i++) {
		fscanf_s(fp, "%s", &sourse[i].S_Name, 10);
		fscanf_s(fp, "%d", &sourse[i].S_ID);
	}
	fclose(fp);
}
/*
功能：保存学生个人基本信息
*/
void WriteStudent() {
	Student* p = student_head;
	FILE* fp;
	fopen_s(&fp, "Student.txt", "wb");
	fprintf(fp, "%d\r\n", Student_num);
	while(p!=nullptr){
		fprintf(fp, "%s %d %s %d\r\n", 
			p->Name, p->ID, p->Major, p->Class);
		p = p->next;
	
	}
	fclose(fp);
}
/*
功能：保存学生成绩
*/
void WriteScore() {
	Score* p = score_head;
	FILE* fp;
	fopen_s(&fp, "Score.txt", "wb");
	fprintf(fp, "%d\r\n", Score_num);
	while (p != nullptr) {
		fprintf(fp, "%s %d %s %d %s %d %s %d %s %d\r\n",
			p->Student_Name, p->ID,
			p->S_Name[0], p->Score[0],
			p->S_Name[1], p->Score[1], 
			p->S_Name[2], p->Score[2], 
			p->S_Name[3], p->Score[3] );
		p = p->next;

	}
	fclose(fp);
}
/*
功能：保存课程名称与编号
*/
void WriteSchool() {
	FILE* fp;
	fopen_s(&fp, "School.txt", "wb");
	for (int i = 0;i < 4;i++) {
		fprintf(fp, "%s %d", &sourse[i].S_Name, sourse[i].S_ID);
	}
	fclose(fp);
}