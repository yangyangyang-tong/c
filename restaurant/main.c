#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

char shenfen;

typedef struct MENU
{
    int code;
    int price;
    char name[50];
} menus;

menus menu[100];

void welcome(); //��ҳ ��ӭ����
void tobehuiyuan(); //�Ƿ��Ϊ��Ա
void huiyuanzhuce(); //��Աע��
void login(); //��½
void huanyinghuiyuan(); //��Ա��ӭ����
void guestmenu(); //�˿Ϳ�ѡ�˵�
void displaymenu(); //�鿴�����˵�
void gukecaozuo(); //�˿Ϳɽ��еĲ���
void order(); //��ͼӲ�
void deleteorder(); //ɾ��
void chakandiancanxinxi(); //�鿴�����Ϣ
int sum(); //�ܷ���
void managermenu(); //����Ա�˵�
void accountmanagement(); //�û��˺���Ϣ����
void deleteaccount(); //ɾ���˻���Ϣ
void changepassword(); //�޸�����
void caidanguanli(); //����Ա����˵�
void input(); //����Ա�Ӳ�
void deletemenu(); //ɾ����Ʒ
void qingkongcaidan(); //��ղ˵�

void welcome()//��ҳ ��ӭ����
{
    printf("\n                                                 ***** ��͵� *****\n\n");
    printf("                                               ***** ��ӭ���Ĺ��� *****\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
    printf("                              ***** ������������� 1.��ͨ�˿�  2.VIP�˿�  3.����Ա��¼ *****\n\n");
    printf("                                                  ��ѡ���� ");
    scanf("%c",&shenfen);
    if(shenfen=='1')
    {
        tobehuiyuan();
        login();
    }
    else if(shenfen=='2')
    {
        login();
    }
    else if(shenfen=='3')
    {
        login();
    }
    else
    {
        system("cls");
        welcome();
    }
}

void tobehuiyuan() //�Ƿ��Ϊ��Ա
{
    char a;
    printf("\n                     ***** �������Ƿ�Ҫ��Ϊ���ǵ�Ļ�Ա,�����Ա�����ܳԷ��������Ż� 1.�� 2.�� *****\n\n");
    printf("                                                  ��ѡ���� ");
    scanf(" %c",&a);
    if(a=='1')
    {
        huiyuanzhuce();
    }
    else if(a=='2')
    {
        guestmenu();
    }
}

void huiyuanzhuce()
{
    system("cls");
    char name[20];
    char password[7];
    getchar(); //�Ե��س�
    printf("\n\n\n                        ***** ע����� *****\n\n");
    FILE *fp;
    if((fp=fopen("login.txt","a"))==NULL)
    {
        printf("�ļ���ʧ��");
        exit(0);
    }
    printf("    �������˺ţ�����������ĸ���ɣ�������20λ����  ");
    gets(name);
    printf("\n");
    printf("    ���������루��λ���֣�:   ");
    gets(password);
    fputs(name,fp);
    fputs(password,fp);
    fputs("\n",fp);
    printf("ע��ɹ���");
    fclose(fp);
    shenfen='2';
}

void login()
{
    system("cls");
    fflush(stdin);
    if(shenfen=='2')
    {
        char name[30];
        char password[7];
        int ok=0;
        printf("\n\n                        ***** ��¼���� *****\n");
        printf("\n                   �������˺ţ�");
        gets(name);
        printf("\n                   ���������룺");
        gets(password);
        strcat(name,password);//�ϲ��ַ�
        strcat(name,"\n");
        int j=0;
        char n[1000][30];
        FILE *fp = fopen("login.txt","r");
        while(fgets(&n[j],30,fp) != NULL)  //���ж��ļ�ֱ���ļ�����
        {
            j++;
        }
        int k;
        for(k=0; k<j; k++)
        {
            if(strcmp(name,n[k])==0)
            {
                ok=1;
                break;
            }
        }
        if(ok)
        {
            printf("\n\n                       ��¼�ɹ�");
            Sleep(500);
            huanyinghuiyuan();
            guestmenu();
        }
        else
        {
            printf("\n\n                       ��¼ʧ��");
            Sleep(500);
            login();
        }

        fclose(fp);
    }
    else if(shenfen=='3')
    {

        char password[7];
        int ok=0,k;
        printf("\n\n                   ***** ����Ա��½���� *****\n\n");
        printf("\n                   ��������λ���룺");
        gets(password);
        strcat(password,"\n");
        int j=0;
        char n[7][10];
        FILE *fp = fopen("managelogin.txt","r");
        while(fgets(&n[j],8,fp) != NULL)  //���ж��ļ�ֱ���ļ�����
        {
            j++;
        }
        for(k=0; k<=j; k++)
        {
            if(strcmp(password,n[k])==0)
            {
                ok=1;
                break;
            }
        }
        if(ok)
        {
            printf("\n\n                       ��¼�ɹ�");
            Sleep(500);
            managermenu();
        }
        else
        {
            printf("\n\n                       ��¼ʧ��");
            Sleep(500);
            login();
        }
        fclose(fp);
    }
}

void huanyinghuiyuan()
{
    printf("\n\n                     ***** �𾴵Ļ�Ա�û�����á� *****\n\n");
    printf("                  ***** �����Ա�����ܳԷ��������Ż� *****\n\n");
    printf("                ***** ���Ǿ���Ϊ��Ա�û��Ƽ����±�����ɫ ***** \n\n");
    printf("                           ***** �������� ***** \n");
    printf("                           ***** ����ţ�� ***** \n");
    printf("                          ***** ����С��Ϻ ***** \n");
    printf("                           ***** �������� ***** \n");
    printf("                           ***** ���Ͱ�Ҷ ***** \n\n");
    printf("                         ***** ����������� ***** ");
    getch();
}

void guestmenu()
{
    int a,s;
    fflush(stdin);
    while(1)//������ѭ��ʵ�ֶ�β���������ѭ�������ĳ���
    {
        system("cls");  //����
        printf("\n          ***** ��ѡ����Ҫ���в����ı�ţ�*****\n\n");
        printf("            1.      ����˵�\n\n");
        printf("            2.      ��ͼӲͼ��ͺͲ鿴\n\n");
        printf("            3.      ���ý���\n\n");
        printf("            4.      ����������\n\n");
        printf("            5.      �˳���¼\n\n");
        printf("            ��ѡ���� ");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
            //�˵���ʾ
            displaymenu();
            break;
        case 2:
            //������ͼ������Ϣ��ѯ�ȹ���
            gukecaozuo();
            break;
        case 3:
            //�������ܼ�
            s=sum();
            if(shenfen=='1')
                printf("\n         ���ܼ������� %d Ԫ\n",s);
            else
            {
                printf("\n        �𾴵Ļ�Ա�û������Ǳ���Ļ�Ա�������ܵ�;������Ż�\n\n");
                printf("                       ���ܼ������� %.2f Ԫ\n",(float)s*0.95);
            }
            break;
        case 4:
            welcome();
            break;
        case 5:
            //�˳�����
            printf("\n    �˳��ɹ�!\n");
            exit(0);
            break;
        default:
            printf("\n    ��������ȷ�Ĵ���!\n");
            break;
        }
        printf("\n    ��������������к�������!");
        getch();
    }
}

void displaymenu()
{
    int i,a;
    printf("\n           ��ӭ���鿴�˵�\n\n");
    printf("���          ����          �۸�\n\n");
    FILE* fp = fopen("menu.txt","r"); //�򿪲˵����ڵ��ļ�
    if(!fp)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp,"%04d            %s            %d",&menu[i].code,menu[i].name,&menu[i].price);
    }
    fclose(fp);
    a=i-1;
    for(i=0; i<a; i++)
    {
        printf("%04d            %s            %d\n",menu[i].code,menu[i].name,menu[i].price);
    }
}

void gukecaozuo()
{
    fflush(stdin);
    int a;
    while(1)
    {
        printf("\n          ***** ��ѡ����Ҫ���в����ı�ţ�*****\n\n");
        printf("            1.      ��ͻ�Ӳ�\n\n");
        printf("            2.      ɾ���ѵ��Ʒ\n\n");
        printf("            3.      �������鿴\n\n");
        printf("            4.      ������һ��\n\n");
        printf("            ��ѡ���� ");
        scanf("%d%*c",&a);
        switch(a)
        {
        case 1:
            //��ͺͼӲ�
            order();
            break;
        case 2:
            //ɾ���û��Ѿ���Ĳ�
            deleteorder();
            break;
        case 3:
            //�鿴������
            chakandiancanxinxi();
            break;
        case 4:
            guestmenu();
            break;
        default :
            printf("\n�����������������\n");
            break;
        }
    }
}

void order()  //��ͻ��߼Ӳ�
{
    int diancai[30],jiacai[20],i,n,sum1,sum2;
    FILE *fp = fopen("diancai.txt","a");
    if(fp==NULL)
    {
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
    do
    {
        printf("\n          ***** ��ѡ����Ҫ���в����ı�ţ�*****\n\n");
        printf("            1.      ���\n\n");
        printf("            2.      �Ӳ�\n\n");
        printf("            ��ѡ����ȷ�ı�� ");
        scanf("%d",&n);
    }
    while(n!=1&&n!=2);
    fflush(stdin);
    int ret;
    if(n==1)
    {
        displaymenu();
        printf("\n\n������Ҫ��Ĳ˵ı�ţ��������ϣ�������������������ַ�����:\n");
        for(i=0;; i++)
        {
            ret=scanf("%d",&diancai[i]);
            getchar();
            if(diancai[i]==0||ret!=1)
                break;
        }
        sum1=i;
        for(i=0; i<sum1; i++)
        {
            fprintf(fp,"%04d",diancai[i]);
            fputs("\n",fp);
        }
        printf("\n       ��ͳɹ�\n\n");
    }
    else if(n==2)
    {
        displaymenu();
        printf("\n\n���Ѿ�����Ĳ���\n\n");
        chakandiancanxinxi();
        printf("\n\n������Ҫ�ӵĲ˵ı�ţ����Ӳ���ϣ���������:\n");
        for(i=0;; i++)
        {
            ret=scanf("%d",&jiacai[i]);
            getchar();
            if(jiacai[i]==0||ret!=1)
                break;
        }
        sum2=i;
        for(i=0; i<sum2; i++)
        {
            fprintf(fp,"%04d",jiacai[i]);
            fputs("\n",fp);
        }
        printf("\n       �Ӳͳɹ�\n\n");
    }
    fclose(fp);
}

void deleteorder()
{
    printf("\n\n���Ѿ�����Ĳ���\n\n");
    chakandiancanxinxi();
    //��ȡ��Ҫɾ���Ĳ�����Ϣ��Ȼ�������������浽һ�����ļ��У��Ƴ����ļ��������ļ������ָ�Ϊ����ļ���ͬ
    FILE* fp = fopen("diancai.txt","r");
    FILE* fp1 = fopen("diancai1.txt","w");
    char a[4],b[5],account[5];
    int x=0;
    if(!fp || !fp1)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("\n\n��������Ҫɾ���Ĳ˵ı�ţ�\n");
    scanf("%s%*c",a);
    int len;
    len=strlen(a);
    char c[5]="0000";
    if(len==1)
    {
        c[3]=a;
    }
    else if(len==2)
    {
        c[2]=a[0];
        c[3]=a[1];
    }
    while(fgets(b,5,fp))
    {
        sscanf(b,"%s",account);    //��b��������%S����ʽ�洢��account  sscanf()�Ὣ����str���ַ������ݲ���format�ַ�����ת������ʽ�����ݡ�
        if(strcmp(account,c) != 0)
            fputs(b,fp1);
        else
        {
            x++;
            if(x>1)
            {
                fputs(b,fp1);
            }
        }

    }
    printf("\nɾ���ɹ�! �����Զ����أ�\n");
    Sleep(500);
    fclose(fp),fclose(fp1);
    remove("diancai.txt");
    rename("diancai1.txt","diancai.txt");
}

void chakandiancanxinxi()
{
    int i,j,n,m,a[5];
    FILE* fp = fopen("menu.txt","r");
    if(!fp)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp,"%04d            %s            %d",&menu[i].code,menu[i].name,&menu[i].price);
    }
    n=i-1;
    fclose(fp);
    FILE* fpl = fopen("diancai.txt","r");
    if(!fpl)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }
    for(i=0; !feof(fpl); i++)
    {
        fscanf(fpl,"%04d",&a[i]);
    }
    m=i-1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[j]==menu[i].code)
                printf("%04d            %s            %d\n\n",menu[i].code,menu[i].name,menu[i].price);
        }
    }
    printf("\n       һ������ %d ����\n\n",m);
    Sleep(1000);
    fclose(fpl);
}

int sum()
{
    int n,m,i,j;
    chakandiancanxinxi();
    int sum=0,a[30];
    FILE* fp = fopen("menu.txt","r");
    if(!fp)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp,"%04d            %s            %d",&menu[i].code,menu[i].name,&menu[i].price);
    }
    m=i-1;
    fclose(fp);
    FILE* fp1 = fopen("diancai.txt","r");
    if(!fp1)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }
    for(i=0; !feof(fp1); i++)
    {
        fscanf(fp1,"%d",&a[i]);
    }
    n=i-1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i]==menu[j].code)
            {
                sum+=menu[j].price;
            }
        }
    }
    fclose(fp1);
    return sum;
}

void managermenu()
{
    system("cls");
    int fun_code;

    fflush(stdin);
    //������ѭ����֤�û����Զ�ν��в���
    while(1)
    {
        printf("\n          ***** ��ѡ����Ҫ���в����ı�ţ�*****\n\n");
        printf("            1.      �鿴�������û��˻���Ϣ\n\n");
        printf("            2.      ����,��ѯ������,ɾ���˵���Ϣ\n\n");
        printf("            3.      �˿͵㵥��Ϣ���\n\n");
        printf("            4.      ��չ˿��Ե�˵�\n\n");
        printf("            5.      ����������\n\n");
        printf("            6.      �˳���¼\n\n");
        printf("            ��ѡ���� ");
        scanf("%d%*c",&fun_code);
        switch(fun_code)
        {
        case 1:
            //�������û����˺�������й���
            accountmanagement();
            break;
        case 2:
            //�Բ˵��������ӣ����Һ͸����Լ�ɾ������
            caidanguanli();
            break;
        case 3:
            //����˿͵����Ϣ
            printf("\n�ͻ��㵥��Ϣ����:\n");
            chakandiancanxinxi();
            break;
        case 4:
            qingkongcaidan();
            printf("\n    ��ճɹ� \n");
            system("cls");
            managermenu();
            break;
        case 5:
            system("cls");
            welcome();
            break;
        case 6:
            printf("�˳��ɹ�!\n");
            exit(0);
        default:
            printf("��������ȷ�Ĵ���!\n");
            break;
        }
    }
}

void accountmanagement()
{
    FILE* fp = fopen("login.txt","r");
    char n[1000][30];
    int fun_code,x,j=0;
    fflush(stdin);
    //��ʾ��ǰ�����û���һ���б�
    printf("\n          *****��ǰ�û��б�*****\n\n");
    while(fgets(&n[j],30,fp) != NULL)  //���ж��ļ�ֱ���ļ�����
    {
        printf("             %s",n[j]);
        j++;
    }
    x=j;
    printf("\n          *****��ǰ�� %d ���û�*****\n",x);
    fclose(fp);
    printf("\n          ***** ��ѡ����Ҫ���в����ı�ţ�*****\n\n");
    printf("            1.      �½��û�\n\n");
    printf("            2.      ɾ���˻�\n\n");
    printf("            3.      �޸��û�����\n\n");
    printf("            4.      ������һ��\n\n");
    printf("            ��ѡ���� ");
    scanf("%d",&fun_code);
    switch(fun_code)
    {
    case 1:
        //�������û�
        huiyuanzhuce();
        break;
    case 2:
        //ɾ�����е��˻�
        deleteaccount();
        break;
    case 3:
        //�޸��û�����
        changepassword();
        break;
    case 4:
        managermenu();
        break;
    default :
        //�������������������
        printf("������Ĵ��벻��ȷ������������!");
        break;
    }
}

void deleteaccount()
{
    //��ȡ��Ҫɾ�����˺���Ϣ��Ȼ�������˺���Ϣ���浽һ�����ļ��У��Ƴ����ļ��������ļ������ָ�Ϊ����ļ���ͬ
    FILE* fp = fopen("login.txt","r");
    FILE* fp1 = fopen("login1.txt","w");
    char a[30],b[30],account[30];
    if(!fp || !fp1)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("\n  ��������Ҫɾ�����˻��������룺\n");
    scanf("%s%*c",a);
    while(fgets(b,30,fp))
    {
        sscanf(b,"%s",account);    //��b��������%S����ʽ�洢��account  sscanf()�Ὣ����str���ַ������ݲ���format�ַ�����ת������ʽ�����ݡ�
        if(strcmp(account,a) != 0)
            fputs(b,fp1);
    }
    printf("ɾ���ɹ�! �����Զ����أ�\n");
    Sleep(500);
    fclose(fp),fclose(fp1);
    remove("login.txt");
    rename("login1.txt","login.txt");
    accountmanagement();
}

void changepassword()
{
    FILE* fp = fopen("login.txt","r");
    FILE* tmp = fopen("tmp.txt","w");
    char account1[30],account2[30],buff[30];
    if(!fp || !tmp)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("��������Ҫ�����޸�������˺��Լ�������\n\n");
    fflush(stdin);
    printf("      �˺ź;����룺");
    scanf("%s",account1);
    printf("��������Ҫ�����޸�������˺��Լ�������\n\n");
    printf("      �˺ź������룺");
    scanf("%s",account2);
    while(fgets(buff,30,fp))
    {
        char o_account[30],new_line[30];
        sscanf(buff,"%s",o_account);
        if(strcmp(o_account,account1) == 0)
        {
            sprintf(new_line,"%s\n",account2);
            fputs(new_line,tmp);
        }
        else
            fputs(buff,tmp);
    }
    printf("�����޸ĳɹ��������Զ����أ�\n");
    Sleep(500);
    fclose(fp),fclose(tmp);
    remove("login.txt");
    rename("tmp.txt","login.txt");
}

void caidanguanli()
{
    int a;
    displaymenu();

    while(1)
    {
        printf("\n          ***** ��ѡ����Ҫ���в����ı�ţ�*****\n\n");
        printf("            1.      ��Ӳ˵���Ϣ\n\n");
        printf("            2.      �鿴���º�˵���Ϣ\n\n");
        printf("            3.      ɾ���˵���Ϣ\n\n");
        printf("            4.      ������һ��\n");
        scanf("%d%*c",&a);
        switch(a)
        {
        case 1:
            input();
            break;
        case 2:
            //���²˵���������ʾ�˵��е���Ϣ
            displaymenu();
            break;
        //������һ��
        case 3:
            deletemenu();
            break;
        case 4:
            return 0;
        default :
            printf("����������!\n");
            break;
        }
    }
    return 0;
}

void input()
{
    FILE* fp=fopen("menu.txt","a");
    int n,i;
    //�ڴ��в˵���Ϣ���ļ���׷���µĲ�Ʒ��Ϣ
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }
    printf("  ����������Ҫ���Ӳ˵���������");
    scanf("%d%*c",&n);
    //�����Ʒ��Ϣ������
    printf("  ����ÿ�������ţ������ͼ۸��Կո�ֿ�:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&menu[i].code);
        scanf("%s",menu[i].name);
        scanf("%d",&menu[i].price);
        fprintf(fp,"%04d            %s            %d\n",menu[i].code,menu[i].name,menu[i].price);
    }
    fclose(fp);
    fp = NULL;
}

void deletemenu()
{
    FILE* fp = fopen("menu.txt","r");
    FILE* tmp = fopen("tmp.txt","w");
    char menu[5],buff[200];
    if(!fp || !tmp)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("��������Ҫɾ���Ĳ˵ı�ţ�\n");
    scanf("%s%*c",menu);
    int len;
    len=strlen(menu);
    char c[5]="0000";
    if(len==1)
    {
        c[3]=menu[0];
    }
    else if(len==2)
    {
        c[2]=menu[0];
        c[3]=menu[1];
    }
    int x=0;
    while(fgets(buff,200,fp))
    {
        char menu1[80];
        sscanf(buff,"%s",menu1);
        if(strcmp(menu1,c) != 0)
            fputs(buff,tmp);
        else
        {
            x++;
            if(x>1)
            {
                fputs(buff,tmp);
            }
        }
    }
    printf("�˵��޸ĳɹ�!\n");
    fclose(fp),fclose(tmp);
    remove("menu.txt");
    rename("tmp.txt","menu.txt");
}

void qingkongcaidan()
{
    FILE* fp = fopen("diancai.txt","w");
    if(!fp)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    printf("\n              ��ճɹ�\n\n");
    Sleep(500);
    fclose(fp);
}

int main()
{
    welcome();
    return 0;
}
