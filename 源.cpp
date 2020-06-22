#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L1 sizeof(struct Student)
#define L2 sizeof(struct Score)

//ѧ��������Ϣ
struct Student {      
		char Name[5];                                                                               //����
		int ID ;                                                                                          //ѧ��   ���ظ�����ɾ��
		char Major[10] ;                                                                           //רҵ
		int Class;                                                                                      //�༶
		struct Student *next;
};
typedef struct Student Student;
static int id = 20200000;                                                                        //ѧ��
static int Student_num = 0;                                                                    //��������
Student* student_head = nullptr, * student_end = nullptr;                   //ѧ��������Ϣ�����ͷ��β
//�ɼ�
struct Score {     
	int ID;                                                                                                //ѧ��
	char Student_Name[5];                                                                     //����
	char S_Name[4][10];                                                                       //�γ�����
	int Score[4];                                                                                     //����
	struct Score* next;
};
typedef struct Score Score;
Score* score_head = nullptr, * score_end = nullptr;
static int Score_num = 0;
//�γ���������
struct Sourse {    
	int S_ID;                                                                                         //�γ̱��
	char S_Name[10];                                                                          //�γ�����
}sourse[4];
typedef struct Sourse Sourse;

/*��������*/
void menu();                                                                        //���˵�����
void input();                                                                        //��Ϣ¼��
void in_menu();                                                                  //¼���Ӳ˵�����
Student* input_student();                                                   //ѧ��������Ϣ¼��
Score* input_score();                                                         //ѧ���ɼ�¼��
void input_sourse();                                                           //�γ���������¼��
void search();                                                                     //��Ϣ��ѯ
void search_menu();                                                          //��ѯ�Ӳ˵�����
int Search_choose();                                                           //��ѯ��ʽ
Student* search_student();                                                 //ѧ��������Ϣ��ѯ
Score* search_score();                                                       //ѧ���ɼ���ѯ
Sourse* search_sourse();                                                    //�γ��������Ų�ѯ
void Display_Student();                                                     //ѧ��������Ϣ����
void display_student(Student* This);                                //���˻�����Ϣ��ʾ
void Display_Score();                                                        //�ܳɼ�����
void display_score(Score* This);                                      //���˳ɼ���ʾ
void Display_sourse();                                                       //�γ�Ŀ¼����
void display_sourse(Sourse* This);                                   //�γ���ʾ
void del();                                                                           //��Ϣɾ��
void del_menu();                                                               //ɾ���Ӳ˵�����
Student* del_student(Student* This);                                //ɾ��ѧ��������Ϣ
Score* del_score(Score* This);                                        //ɾ��ѧ���ɼ�
Sourse* del_sourse(Sourse* This);                                   //ɾ���γ�
void modify();                                                                    //��Ϣ�޸�
void modify_menu();                                                        //�޸��Ӳ˵�����
Student* modify_student(Student* This);                         //�޸ĸ��˻�����Ϣ
Score* modify_score(Score* This);                                 //�޸ĸ��˳ɼ�
Sourse* modify_sourse(Sourse* This);                            //�޸Ŀγ�����
void statistical();                                                               //��Ϣͳ��
void statistical_menu();                                                    //ͳ���Ӳ˵�����
void sourse_score();                                                         //ͳ�Ʒ�ʽ���γ���+������
void del_all();                                                                   //���ϵͳ
void  ReadStudent();                                                        //��ȡѧ�����˻�����Ϣ
void ReadScore();                                                            //��ȡѧ���ɼ�
void ReadSchool();                                                          //��ȡ�γ���������
void WriteStudent();                                                        //����ѧ�����˻�����Ϣ
void WriteScore();                                                          // ����ѧ���ɼ�
void WriteSchool();                                                        //����γ���������
/*������*/
int main() {
	int num;
	do {
		menu();                                                                //���˵�
		scanf_s("%d", &num);                                        //���
		switch (num) {
		case 1: {                                                              //��ȡ
			ReadStudent(); 
			ReadScore();
			ReadSchool();
			printf("��ȡ�ɹ���\n");
			system("pause");
			break;}
		case 2: {input();break;}                                        //¼��
		case 3: {statistical();break;}                                 //ͳ��
		case 4:{search();break;}                                       //��ѯ
		case 5:{modify();break;}                                     //�޸�
 		case 6:{del();break;}                                           //ɾ��

		case 7: {                                                             //����
			WriteStudent();
			WriteScore();
			WriteSchool();
			break;}                         //�˳�
		}
	} while (num != 7);
	del_all();
	printf("------------------------------���˳�ϵͳ----------------------------------\n");
}

/*---���˵�---*/
void menu() {
	system("cls");
	printf("****************************ѧ���ɼ�����ϵͳ*********************************\n");
	printf("                                  �˵� \n");
	printf(" 1.��ȡ                                             2.¼��\n");
	printf(" 3.ͳ��                                             4.��ѯ \n");
	printf(" 5.�޸�                                             6.ɾ��\n");
	printf(" 7.�˳�(�����ĵ�)\n");
	printf("\n*****************************************************************************\n");
	printf(" ��ӭʹ��ѧ���ɼ�����ϵͳ����������Ҫ��ѯ�ı�ţ�");
}

/*
*���ܣ�¼��ѧ��������Ϣ���ɼ�����ǰѧ��ѧ�ڣ��γ̱��������
*/
void input() {
	int in_num=0;                                                       
	do {
		in_menu();                                                          //¼���Ӳ˵�
		printf("��������:");
		scanf_s("%d", &in_num);                                
			switch (in_num) {
			case 1: {input_student();break;}                  
			case 2: {input_score();break;}                                        
			case 3: {input_sourse();break;}                  
			case 4:break;                                                 
		}
	} while (in_num != 4);
}

//¼���Ӳ˵�
void in_menu() {
	system("cls");
	printf("********************************¼��******************************************\n");
	printf(" 1.ѧ��������Ϣ��\n");
	printf(" 2.ѧ���ɼ���\n");
	printf(" 3.�γ̱�ż�����\n");
	printf(" 4.������һ��Ŀ¼\n");
	printf("******************************************************************************\n");
}
 

/*
*���ܣ�¼��ѧ�����˻�����Ϣ����������ʽ���棬��¼ѧ����Ϣ������
*���أ�����ͷ 
*/
Student* input_student()   //��������ͷ��ַ                
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
	printf("������������");                                            
	scanf_s("%s", &Snew->Name,5);
	fflush(stdin);
	Snew->ID =++id;
	printf("����ѧ��Ϊ%d��\n",Snew->ID);
	printf("������רҵ��");
	scanf_s("%s", &Snew->Major,10);
	fflush(stdin);
	printf("������༶(Сд)��");
	scanf_s("%d",&Snew->Class);
	fflush(stdin);
	//����
	if (student_head == nullptr) {                                         //����������
		student_head = student_end = Snew;
	}
	else {                                                                               //�ǿ�����
		student_end->next = Snew;
		student_end = Snew;
		student_end->next = nullptr;
	}
	printf("��¼�롣\n");
	system("pause");
	return student_head;
}
/*
*���ܣ�¼��ѧ�����˳ɼ�����������ʽ���档
*���أ�����ͷ
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
	printf("������������");                                             
	scanf_s("%s", &Snew->Student_Name,5);
	printf("������ѧ�ţ�");
	scanf_s("%d", &Snew->ID);
	for (int i = 0;i < 4;i++) {
		strcpy_s(Snew->S_Name[i], sourse[i].S_Name);
		printf("%s\n", &Snew->S_Name[i]);
     	printf("�����������");
	    scanf_s("%d", &Snew->Score[i]);
	}
		//����
	if (score_head == nullptr) {                                           //����������
		score_head = score_end = Snew;
	}
	else {                                                                                //�ǿ�����
		score_end->next = Snew;
		score_end = Snew;
		score_end->next = nullptr;
	}
	printf("��¼�롣\n");
	system("pause");
	return score_head;
}
/*
*���ܣ�¼��γ̱�ţ����ƣ���������ʽ�洢�������顣
*/
void input_sourse() {
	for (int i = 0;i < 4;i++) {
		printf("������γ����ƣ�");
		scanf_s("%s", &sourse[i].S_Name, 10);
		printf("������γ̱�ţ�");
        scanf_s("%d", &sourse[i].S_ID);
	}
	printf("��¼�롣\n");
	system("pause");
}
/*��Ϣͳ��*/
void statistical() {
	int statis_num;
	do {
		statistical_menu();
		printf("�������ţ�");
		scanf_s("%d", &statis_num);
		switch (statis_num) {
		case 1: {                                                                       //�γ�+������
			sourse_score();
			system("pause");
			break;
		}
		case 2: { Display_Score();break;}                              //�ܳɼ�������
		case 3: {Display_Student();break;}                            //ѧ��������Ϣ
		case 4: { Display_sourse();break; }
		case 5:break;                                                                //������һ��
		}
	} while (statis_num != 5);
}
//ͳ���Ӳ˵�
void statistical_menu() {
	system("cls");
	printf("********************************ͳ��******************************************\n");
	printf(" �ɼ�ͳ�Ʒ�ʽ��\n");
	printf(" 1.�γ�����+�����Ρ�\n");
	printf(" 2.�ܳɼ���\n");
	printf(" 3.ѧ��������Ϣ\n");
	printf(" 4.�γ��������ű�\n");
	printf(" 5.������һ��Ŀ¼\n");
	printf("******************************************************************************\n");
}
//�γ�����+������
void sourse_score() {
	Sourse* This = nullptr;
	char name[10];
	printf("������γ̣�");
	scanf_s("%s", &name, 10);                               //Ҫ��ѯ�Ŀγ���
	fflush(stdin);
	//���ҿγ�
	int i = 0;
	for (; i < 4;i++) {
		if (strcmp(sourse[i].S_Name, name) == 0)break;       //���ҿγ�λ��
	}
	if (i == 4) { printf("û�д˿γ�"); return; }                   //û�� �˳��� �� ����
	int up, down;
	printf("���������ޣ�");
	scanf_s("%d", &up);
	printf("���������ޣ�");
	scanf_s("%d", &down);
	Score* p = score_head;
	printf("\t\t����\tѧ��\t\t%s\n", &p->S_Name[i]);
	printf("\t\t------------------------------------------\n");
	while (p != nullptr) {
		if (p->Score[i] <= up && p->Score[i] >= down) {    //�γ̶�Ӧ�������ж�
			printf("\t\t%s\t%d\t%d\n", p->Student_Name, p->ID, p->Score[i]);
			printf("\t\t------------------------------------------\n");
		}
		p = p->next;
	}
}
/*
���ܣ���Ϣ��ѯ  ���˻�����Ϣ�����˳ɼ���
*/
void search() {
	int search_num;
	do {
		search_menu();                                                                     
		printf("�������ţ�");
		scanf_s("%d", &search_num);                                            
		switch(search_num) { 
		    case 1: {display_student(search_student()); break;}        
			case 2:{display_score(search_score()); break;}          
			case 3: break;                          

				}
	}while (search_num != 3);
}

//��ѯ�Ӳ˵�
void search_menu() {
	system("cls");
	printf("********************************��ѯ******************************************\n");
	printf(" 1.ѧ��������Ϣ��\n");
	printf(" 2.ѧ���ɼ���\n");
	printf(" 3.������һ��Ŀ¼\n");
	printf("******************************************************************************\n");
}
/*
���ܣ���ѯ��ʽ��ѡ���ַ� / ���֡�
*/
int Search_choose() {
	int choose=0;
	printf("��ѯ��ʽѡ��\n");
	printf("1.����/�γ���\n");
	printf("2.ѧ��/�γ̱��\n");
	printf("��ѡ��");
	scanf_s("%d", &choose);
	return choose;
}
/*
���ܣ���ѯѧ��������Ϣ����ѡ�������������ͣ��ַ� / ���֣���������ƥ��
            ƥ��ɹ������ص�ַ��ƥ�䲻�ɹ�����ʾ�û������ؿ�ָ�롣
*/
Student* search_student() {
	//��ѯ��ʽѡ�񣬲�ѯ����ʾ
    Student* This = student_head;
	//ѡ���ѯ��ʽ
	if (Search_choose() == 1) {                                            //������ѯ 
		char name[5];
		printf("������������");
		scanf_s("%s", &name,5);                                             
		fflush(stdin);                                                                  
		//����name
		while (This != nullptr) {                                               
			if (strcmp(This->Name, name) == 0)break;            
			else This = This->next;                                              
		}
		if (This == nullptr) {
			printf("ϵͳ��û�д��ˡ����������Ƿ���ȷ�����²�ѯ\n");	
			return nullptr;                                                            
		}      
		else return This;                                                           
	}
	else {                                                                                  //ѧ�Ų�ѯ
		int id;
		printf("������ѧ��(20xxxxxx)��");
		scanf_s("%d", &id);                                                     
		fflush(stdin);
		while (This != nullptr) {                                               
			if (This->ID == id) {                                            
				return This;
			}
			else This = This->next;
		}
        if (This == nullptr) {
	    	printf("ϵͳ��û�д�����Ϣ������ѧ���Ƿ���ȷ�����²�ѯ\n");
	    	return nullptr;                                                               
	    }
	}
}
//��ѯѧ���ɼ�   ���������ַ û��Ϊ��
Score* search_score() {               
	Score* This=score_head;
	//��ѯ��ʽѡ��
	if (Search_choose() == 1) {                                               //������ѯ
		char name[5];
		printf("������������");
		scanf_s("%s", &name, 5);                                       
		fflush(stdin);
		while (This != nullptr) {
			if (strcmp(This->Student_Name, name) == 0)break;
			else This = This->next;
		}
			if (This != nullptr) return This;                             
			else {
				printf("û�д�����Ϣ��\n");
				return nullptr;
			}
		
	}
	else {                                                                                 //ѧ�Ų�ѯ
		int id;
		printf("������ѧ��(20xxxxxx)��");
		scanf_s("%d", &id);                                                    
		fflush(stdin);
		while (This != nullptr) {
			if (This->ID == id) {                                               
				return This;
			}
			else This = This->next;
		}
		if (This == nullptr) {
			printf("û�д�����Ϣ��\n");
			return nullptr;
		}
	}
}
//��ѯ�γ���������     ���������ַ û��Ϊ��
/*
���ܣ���ѯ�γ���������  ���÷�ʽѡ�������ַ�  /  ���飩
*/
Sourse* search_sourse() {
	Sourse* This = nullptr;
	//��ѯ��ʽѡ��
	if (Search_choose() == 1) {                                             //�γ�����ѯ
		char name[10];
		printf("������γ̣�");
		scanf_s("%s", &name, 10);                                        //Ҫ��ѯ�Ŀγ�
		fflush(stdin);
		int i = 0;
		for (; i < 4;i++) {
			if (strcmp(sourse[i].S_Name, name) == 0)break;       //�ж�
		}
		if (i != 4) { 
            This = &sourse[i];                                                  //�ҵ�����������ĵ�ַ
			return This; }
		else {
			printf("û�д˿γ̡�\n");
		}

	}
	else {                                                                             //��Ų�ѯ
		int id;
		printf("������γ̱�ţ�");
		scanf_s("%d", &id);                                                  //��Ҫ��ѯ�ı��
		fflush(stdin);
		for (int i = 0;i < 4;i++) {
			if (sourse[i].S_ID == id) {
				return &sourse[i];                                             //�ҵ����������ַ
			}
		}
        if (This==nullptr) {                                                      //û���ҵ�
	    	printf("û�д˿γ̡�");
	} 
	}
	
	return nullptr;                                                               //���ؿ�ָ��                                                              
}
/*��ʾ*/
//ѧ��������Ϣ����
void Display_Student() {
	Student* p = student_head;
	if (p == nullptr) { 
		printf("�˱�Ϊ�ա�");
	    system("pause");
	    return; 
	}
	while(p != nullptr){
		printf("\t----------------------------\n");
    	printf("\t������%s\n", p->Name);
		printf("\tѧ�ţ�%d\n",p->ID);
		printf("\tרҵ��%s\n",p->Major);
		printf("\t�༶��%d\n",p->Class);
		p = p->next;
	}
	system("pause"); //������Ļ
}
//���˻�����Ϣ
void display_student(Student* This) {//��Ҫ��ʾ���ĵ�ַ
	if (This == nullptr) {
		system("pause");
		return;
	}
	printf("\t������%s\n", This->Name);
	printf("\tѧ�ţ�%d\n", This->ID);
	printf("\tרҵ��%s\n", This->Major);
	printf("\t�༶��%d\n", This->Class);
	system("pause");
}
//�ܳɼ�����
void Display_Score() {
	Score* p = score_head;
	if (p == nullptr) { 
		printf("�˱�Ϊ�ա�");
		system("pause");
		return; 
	}
	printf("\t\t����\tѧ��\t\t%s\t%s\t%s\t%s\n", 
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
//���˳ɼ�
void display_score(Score* This) {                            //��Ҫ��ʾ���ĵ�ַ
	if (This == nullptr) {
		system("pause");
		return;
	}
	printf("\t\t����\tѧ��\t\t%s\t%s\t%s\t%s\n",
		This->S_Name[0], This->S_Name[1], This->S_Name[2], This->S_Name[3]);
	printf("\t\t----------------------------------------------------------\n");
	printf("\t\t%s\t%d\t%d\t%d\t%d\t%d\n",
		This->Student_Name, This->ID, This->Score[0], This->Score[1], This->Score[2], This->Score[3]);
	printf("\t\t---------------------------------------------------------\n");
	system("pause");
}
//�γ�Ŀ¼����
void Display_sourse() {
	for (int i = 0;i < 4;i++) {
		printf("�γ̱�ţ�%d\n", sourse[i].S_ID);
		printf("�γ����ƣ�%s\n", &sourse[i].S_Name);
	}
	system("pause");
}
//�γ���ʾ
void display_sourse(Sourse* This) {//��Ҫ��ʾ�ĵ�ַ
	if (This == nullptr)return;
	printf("�γ̱�ţ�%d\n", This->S_ID);
	printf("�γ����ƣ�%s\n", This->S_Name);
	system("pause");
}

/*��Ϣ�޸�*/  
void modify() {
	int modify_num;                                                  //��ѡ���
	do {
		modify_menu();                                               //�޸��Ӳ˵�
		printf("��������:");
		scanf_s("%d", &modify_num);
		switch (modify_num) {
		case 1 :{                                                           //�޸ĸ��˻�����Ϣ
			Student* This = search_student();
			if (This == nullptr) {
				system("pause");
				break;
			}
			display_student(This);                                //��ѯ����ʾԭ��Ϣ
			printf("----------------\n");
			modify_student(This);                                //�޸�
			printf("----------------\n");
			printf("�޸ĺ�\n");
			display_student(This);                               //��ʾ�޸ĺ���Ϣ
			system("pause");
			break;
		}
		case 2 :{                                                          //�޸ĸ��˳ɼ�
			Score* This = search_score();
			if (This == nullptr) { 
				system("pause");
				break; }
			display_score(This);                                  //��ѯ����ʾԭ��Ϣ
			printf("----------------\n");
			modify_score(This);                                  //�޸�
			printf("----------------\n");
			printf("�޸ĺ�\n");
			display_score(This);                                  //��ʾ�޸ĺ���Ϣ
			system("pause");
			break;
		}
		case 3 :{                                                         //�޸Ŀγ����� ���
			Sourse* This = search_sourse();                
			if (This == nullptr) {
				system("pause");
				break;
			}
			display_sourse(This);                                //��ѯ����ʾԭ��Ϣ
			printf("----------------\n");
			modify_sourse(This);                                //�޸�
			printf("----------------\n");
			printf("�޸ĺ�\n");
			display_sourse(This);                               //��ʾ�޸ĺ���Ϣ
			break;
		}
		case 4:break;                                                //������һ��
		}
	} while (modify_num != 4);
}

/*�޸��Ӳ˵�*/
void modify_menu() {
	system("cls");
	printf("********************************�޸�******************************************\n");
	printf(" 1.ѧ��������Ϣ��\n");
	printf(" 2.ѧ���ɼ���\n");
	printf(" 3.�γ̱�ż�����\n");
	printf(" 4.������һ��Ŀ¼\n");
	printf("******************************************************************************\n");
}
/*�޸ĸ��˻�����Ϣ*/
Student* modify_student(Student* This) {
	printf("����������������");                                   //��Ϣ����¼�룻
	scanf_s("%s", &This->Name, 5);
	fflush(stdin);
	printf("����ѧ��Ϊ%d��\n", This->ID);
	printf("����������רҵ��");
	scanf_s("%s", &This->Major, 10);
	fflush(stdin);
	printf("����������༶(Сд)��");
	scanf_s("%d", &This->Class);
	fflush(stdin);
	return This;
}
/*�޸ĸ��˳ɼ�*/
Score* modify_score(Score*This) {
	printf("����������������");                                   //��Ϣ����¼�룻
	scanf_s("%s", &This->Student_Name, 5);
	printf("����������ѧ�ţ�");
	scanf_s("%d", &This->ID);
	for (int i = 0;i < 4;i++) {
		strcpy_s(This->S_Name[i], sourse[i].S_Name);
		printf("%s\n", &This->S_Name[i]);
		printf("���������������");
		scanf_s("%d", &This->Score[i]);
	}
	return This;
}
/*�޸Ŀγ�����*/
Sourse* modify_sourse(Sourse* This) {
	printf("����������γ����ƣ�");                            //��Ϣ����¼��
	scanf_s("%s", &This->S_Name, 10);
	printf("����������γ̱�ţ�");
	scanf_s("%d", &This->S_ID);
	return This;
}

/*��Ϣɾ��*/
void del() {
	int del_num;
	do {
		del_menu();
		printf("��ѡ���ţ�");
		scanf_s("%d", &del_num);
		switch (del_num) {
		case 1: {                                                           //ɾ�����˻�����Ϣ
			if (del_student(search_student()) == nullptr) {
				system("pause");
				break;
			}
			printf("�ɹ�ɾ����");
			system("pause");
			break;}
		case 2: {                                                           //ɾ�����˳ɼ�
			if (del_score(search_score()) == nullptr) {
				system("pause");
				break;
			}
			printf("�ɹ�ɾ����");
			system("pause");
			break;}
		case 3: {                                                          //ɾ���γ�
			if (del_sourse(search_sourse()) == nullptr) {
				system("pause");
				break;
			}
			printf("�ɹ�ɾ����");
			system("pause");
			break;}
		case 4:break;
		}
	} while (del_num != 4);
}
/*ɾ���Ӳ˵�*/
void del_menu() {
	system("cls");
	printf("********************************ɾ��******************************************\n");
	printf(" 1.ѧ��������Ϣ��\n");
	printf(" 2.ѧ���ɼ���\n");
	printf(" 3.�γ̱�ż�����\n");
	printf(" 4.������һ��Ŀ¼\n");
	printf("******************************************************************************\n");
}
/*
���ܣ�ɾ��ѧ��������Ϣ
*/
Student* del_student(Student* This) {//��������������Ҫɾ���ĵ�ַ
	if (This == nullptr)return nullptr;
	Student* p = This;
	Student_num--;
	if (student_head == student_end) {                         //ֻ��һ���ڵ�
		free(p);                                                                 //ɾ��
		student_head = student_end = nullptr;                //����
		return student_head;
	}
	if (student_head->next == student_end) {            //�����ڵ�
		if (p == student_head) {                                      //ͷ�ڵ�
			student_head = student_head->next;              //ͷ����
			free(p);                                                            //��ͷɾ��
			return student_head;
		}
		if (p == student_end) {                                      //β�ڵ�
			student_end = student_head;                         //βǰ��
			student_end->next = nullptr;               
			free(p);                                                           //��βɾ��
			return student_head;
		}
	}
	else {                                                                      //�����ڵ�����
		if (p == student_head) {                                     //ͷ�ڵ�
			student_head = student_head->next;
			free(p);
			return student_head;
		}
		Student* P = student_head;
		if (p == student_end) {                                      //β�ڵ�
			while (P->next != p) {                                   //β�ڵ��ǰһ��
				P = P->next;
			}
			student_end = P;                                            //βǰ��
			P->next = nullptr;                              
			free(p);                                                           //ɾ��
			return student_head;
		}
		else {                                                                  //�м�ڵ�
			while (P->next != p) {                                    //�ýڵ��ǰһ��           
				P = P->next;
			}
			P->next = p->next;                                          //�ýڵ�ǰһ�����ýڵ�ĺ�һ��
			free(p);                                                             //ɾ��
			return student_head;
		}
	}
}
/*
���ܣ�ɾ��ѧ���ɼ�
*/
Score* del_score(Score* This) {                               //��������������Ҫɾ���ĵ�ַ
	if (This == nullptr)return nullptr;
	Score* p = This;
	Score_num--;
	if (score_head == score_end) {                             //ֻ��һ���ڵ�
		free(p);                                                               //ɾ���ڵ�
		score_head = score_end = nullptr;                    //ͷβ����
		return score_head;
	}
	if (score_head->next == score_end) {                  //�����ڵ�
		if (p == score_head) {                                       //ͷ�ڵ�
			score_head = score_head->next;                   //ͷ����
			free(p);                                                           //ɾ��
			return score_head;
		}
		if (p == score_end) {                                         //β�ڵ�
			score_end = score_head;                               //βǰ��
			score_end->next = nullptr;                    
			free(p);                                                           //ɾ��
			return score_head;
		}
	}
	else {                                                                     //����ڵ�
		if (p == score_head) {                                       //ͷ�ڵ�
			student_head = student_head->next;             //����
			free(p);                                                           //ɾ��
			return score_head;
		}
		Score* P = score_head;
		if (p == score_end) {                                         //β�ڵ�
			while (P->next != p) {                                   //β��ǰһ��
				P = P->next;
			}
			score_end = P;                                               //βǰ��
			P->next = nullptr;                                    
			free(p);                                                           //ɾ��
			return score_head;
		}
		else {                                                                 //�м�ڵ�
			while (P->next != p) {                                   //�ýڵ��ǰһ��
				P = P->next;
			}
			P->next = p->next;                                        //ǰ������
			free(p);                                                          //ɾ��
			return score_head;
		}
	}

}
/*
���ܣ�ɾ���γ�
���������׵�ַ��������Ҫɾ���ĵ�ַ
*/
Sourse* del_sourse(Sourse* This) {
	if (This == nullptr)return nullptr;
	Sourse* p = This;
	p->S_ID = 0;                                                        //��Ÿ���
	strcpy_s(p->S_Name, "��");                                //���Ƹ���
	return sourse;
}
/*���ϵͳ*/
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
���ܣ���ȡѧ�����˻�����Ϣ�ļ�����������
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
		if (student_head == nullptr) {                                         //����������
			student_head = student_end = p;
		}
		else {                                                                               //�ǿ�����
			student_end->next = p;
			student_end = p;
			student_end->next = nullptr;
		}
	 }
	fclose(fp);
	
}
/*
���ܣ���ȡѧ���ɼ�
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
			if (score_head == nullptr) {                                           //����������
				score_head = score_end = p;
			}
			else {                                                                                //�ǿ�����
				score_end->next = p;
				score_end = p;
				score_end->next = nullptr;
			}
	}
	fclose(fp);
}
/*
���ܣ���ȡ�γ���������
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
���ܣ�����ѧ�����˻�����Ϣ
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
���ܣ�����ѧ���ɼ�
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
���ܣ�����γ���������
*/
void WriteSchool() {
	FILE* fp;
	fopen_s(&fp, "School.txt", "wb");
	for (int i = 0;i < 4;i++) {
		fprintf(fp, "%s %d", &sourse[i].S_Name, sourse[i].S_ID);
	}
	fclose(fp);
}