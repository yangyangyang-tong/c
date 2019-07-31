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

void welcome(); //首页 欢迎界面
void tobehuiyuan(); //是否成为会员
void huiyuanzhuce(); //会员注册
void login(); //登陆
void huanyinghuiyuan(); //会员欢迎界面
void guestmenu(); //顾客可选菜单
void displaymenu(); //查看餐厅菜单
void gukecaozuo(); //顾客可进行的操作
void order(); //点餐加餐
void deleteorder(); //删菜
void chakandiancanxinxi(); //查看点餐信息
int sum(); //总费用
void managermenu(); //管理员菜单
void accountmanagement(); //用户账号信息管理
void deleteaccount(); //删除账户信息
void changepassword(); //修改密码
void caidanguanli(); //管理员管理菜单
void input(); //管理员加菜
void deletemenu(); //删除菜品
void qingkongcaidan(); //清空菜单

void welcome()//首页 欢迎界面
{
    printf("\n                                                 ***** 快餐店 *****\n\n");
    printf("                                               ***** 欢迎您的光临 *****\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
    printf("                              ***** 请输入您的身份 1.普通顾客  2.VIP顾客  3.管理员登录 *****\n\n");
    printf("                                                  请选择编号 ");
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

void tobehuiyuan() //是否成为会员
{
    char a;
    printf("\n                     ***** 请问您是否要成为我们店的会员,本店会员可享受吃饭九五折优惠 1.是 2.否 *****\n\n");
    printf("                                                  请选择编号 ");
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
    getchar(); //吃掉回车
    printf("\n\n\n                        ***** 注册界面 *****\n\n");
    FILE *fp;
    if((fp=fopen("login.txt","a"))==NULL)
    {
        printf("文件打开失败");
        exit(0);
    }
    printf("    请输入账号（文字数字字母均可，不超过20位）：  ");
    gets(name);
    printf("\n");
    printf("    请输入密码（六位数字）:   ");
    gets(password);
    fputs(name,fp);
    fputs(password,fp);
    fputs("\n",fp);
    printf("注册成功！");
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
        printf("\n\n                        ***** 登录界面 *****\n");
        printf("\n                   请输入账号：");
        gets(name);
        printf("\n                   请输入密码：");
        gets(password);
        strcat(name,password);//合并字符
        strcat(name,"\n");
        int j=0;
        char n[1000][30];
        FILE *fp = fopen("login.txt","r");
        while(fgets(&n[j],30,fp) != NULL)  //整行读文件直到文件结束
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
            printf("\n\n                       登录成功");
            Sleep(500);
            huanyinghuiyuan();
            guestmenu();
        }
        else
        {
            printf("\n\n                       登录失败");
            Sleep(500);
            login();
        }

        fclose(fp);
    }
    else if(shenfen=='3')
    {

        char password[7];
        int ok=0,k;
        printf("\n\n                   ***** 管理员登陆界面 *****\n\n");
        printf("\n                   请输入六位密码：");
        gets(password);
        strcat(password,"\n");
        int j=0;
        char n[7][10];
        FILE *fp = fopen("managelogin.txt","r");
        while(fgets(&n[j],8,fp) != NULL)  //整行读文件直到文件结束
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
            printf("\n\n                       登录成功");
            Sleep(500);
            managermenu();
        }
        else
        {
            printf("\n\n                       登录失败");
            Sleep(500);
            login();
        }
        fclose(fp);
    }
}

void huanyinghuiyuan()
{
    printf("\n\n                     ***** 尊敬的会员用户，你好。 *****\n\n");
    printf("                  ***** 本店会员可享受吃饭九五折优惠 *****\n\n");
    printf("                ***** 我们精心为会员用户推荐以下本店特色 ***** \n\n");
    printf("                           ***** 红烧鳝鱼 ***** \n");
    printf("                           ***** 麻辣牛蛙 ***** \n");
    printf("                          ***** 麻辣小龙虾 ***** \n");
    printf("                           ***** 红烧泥鳅 ***** \n");
    printf("                           ***** 红油百叶 ***** \n\n");
    printf("                         ***** 按任意键继续 ***** ");
    getch();
}

void guestmenu()
{
    int a,s;
    fflush(stdin);
    while(1)//借助死循环实现多次操作，内置循环结束的出口
    {
        system("cls");  //清屏
        printf("\n          ***** 请选择您要进行操作的编号：*****\n\n");
        printf("            1.      浏览菜单\n\n");
        printf("            2.      点餐加餐减餐和查看\n\n");
        printf("            3.      费用结算\n\n");
        printf("            4.      返回主界面\n\n");
        printf("            5.      退出登录\n\n");
        printf("            请选择编号 ");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
            //菜单显示
            displaymenu();
            break;
        case 2:
            //包含点餐及点餐信息查询等功能
            gukecaozuo();
            break;
        case 3:
            //计算点餐总价
            s=sum();
            if(shenfen=='1')
                printf("\n         你总计消费了 %d 元\n",s);
            else
            {
                printf("\n        尊敬的会员用户，您是本店的会员，可享受点餐九五折优惠\n\n");
                printf("                       你总计消费了 %.2f 元\n",(float)s*0.95);
            }
            break;
        case 4:
            welcome();
            break;
        case 5:
            //退出程序
            printf("\n    退出成功!\n");
            exit(0);
            break;
        default:
            printf("\n    请输入正确的代码!\n");
            break;
        }
        printf("\n    按任意键继续进行后续操作!");
        getch();
    }
}

void displaymenu()
{
    int i,a;
    printf("\n           欢迎您查看菜单\n\n");
    printf("编号          菜名          价格\n\n");
    FILE* fp = fopen("menu.txt","r"); //打开菜单所在的文件
    if(!fp)
    {
        printf("文件打开失败！\n");
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
        printf("\n          ***** 请选择您要进行操作的编号：*****\n\n");
        printf("            1.      点餐或加餐\n\n");
        printf("            2.      删除已点菜品\n\n");
        printf("            3.      点餐情况查看\n\n");
        printf("            4.      返回上一级\n\n");
        printf("            请选择编号 ");
        scanf("%d%*c",&a);
        switch(a)
        {
        case 1:
            //点餐和加餐
            order();
            break;
        case 2:
            //删除用户已经点的餐
            deleteorder();
            break;
        case 3:
            //查看点餐情况
            chakandiancanxinxi();
            break;
        case 4:
            guestmenu();
            break;
        default :
            printf("\n代码错误请重新输入\n");
            break;
        }
    }
}

void order()  //点餐或者加餐
{
    int diancai[30],jiacai[20],i,n,sum1,sum2;
    FILE *fp = fopen("diancai.txt","a");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    do
    {
        printf("\n          ***** 请选择您要进行操作的编号：*****\n\n");
        printf("            1.      点餐\n\n");
        printf("            2.      加餐\n\n");
        printf("            请选择正确的编号 ");
        scanf("%d",&n);
    }
    while(n!=1&&n!=2);
    fflush(stdin);
    int ret;
    if(n==1)
    {
        displaymenu();
        printf("\n\n请输入要点的菜的编号，若点餐完毕，请输入零或任意其他字符结束:\n");
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
        printf("\n       点餐成功\n\n");
    }
    else if(n==2)
    {
        displaymenu();
        printf("\n\n您已经点过的菜有\n\n");
        chakandiancanxinxi();
        printf("\n\n请输入要加的菜的编号，若加餐完毕，请输入零:\n");
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
        printf("\n       加餐成功\n\n");
    }
    fclose(fp);
}

void deleteorder()
{
    printf("\n\n您已经点过的菜有\n\n");
    chakandiancanxinxi();
    //读取需要删除的菜名信息，然后其他菜名储存到一个新文件中，移除旧文件，把新文件的名字改为与旧文件相同
    FILE* fp = fopen("diancai.txt","r");
    FILE* fp1 = fopen("diancai1.txt","w");
    char a[4],b[5],account[5];
    int x=0;
    if(!fp || !fp1)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    printf("\n\n请输入您要删除的菜的编号：\n");
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
        sscanf(b,"%s",account);    //将b的内容以%S的形式存储到account  sscanf()会将参数str的字符串根据参数format字符串来转换并格式化数据。
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
    printf("\n删除成功! 即将自动返回！\n");
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
        printf("文件打开失败！\n");
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
        printf("文件打开失败！\n");
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
    printf("\n       一共点了 %d 道菜\n\n",m);
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
        printf("文件打开失败！\n");
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
        printf("文件打开失败！\n");
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
    //借助死循环保证用户可以多次进行操作
    while(1)
    {
        printf("\n          ***** 请选择您要进行操作的编号：*****\n\n");
        printf("            1.      查看及更改用户账户信息\n\n");
        printf("            2.      输入,查询及更新,删除菜单信息\n\n");
        printf("            3.      顾客点单信息浏览\n\n");
        printf("            4.      清空顾客以点菜单\n\n");
        printf("            5.      返回主界面\n\n");
        printf("            6.      退出登录\n\n");
        printf("            请选择编号 ");
        scanf("%d%*c",&fun_code);
        switch(fun_code)
        {
        case 1:
            //对所有用户的账号密码进行管理
            accountmanagement();
            break;
        case 2:
            //对菜单进行增加，查找和更新以及删除操作
            caidanguanli();
            break;
        case 3:
            //浏览顾客点菜信息
            printf("\n客户点单信息总览:\n");
            chakandiancanxinxi();
            break;
        case 4:
            qingkongcaidan();
            printf("\n    清空成功 \n");
            system("cls");
            managermenu();
            break;
        case 5:
            system("cls");
            welcome();
            break;
        case 6:
            printf("退出成功!\n");
            exit(0);
        default:
            printf("请输入正确的代码!\n");
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
    //显示当前所有用户的一个列表
    printf("\n          *****当前用户列表*****\n\n");
    while(fgets(&n[j],30,fp) != NULL)  //整行读文件直到文件结束
    {
        printf("             %s",n[j]);
        j++;
    }
    x=j;
    printf("\n          *****当前有 %d 名用户*****\n",x);
    fclose(fp);
    printf("\n          ***** 请选择您要进行操作的编号：*****\n\n");
    printf("            1.      新建用户\n\n");
    printf("            2.      删除账户\n\n");
    printf("            3.      修改用户密码\n\n");
    printf("            4.      返回上一级\n\n");
    printf("            请选择编号 ");
    scanf("%d",&fun_code);
    switch(fun_code)
    {
    case 1:
        //创建新用户
        huiyuanzhuce();
        break;
    case 2:
        //删除已有的账户
        deleteaccount();
        break;
    case 3:
        //修改用户密码
        changepassword();
        break;
    case 4:
        managermenu();
        break;
    default :
        //处理代码输入错误的问题
        printf("你输入的代码不正确，请重新输入!");
        break;
    }
}

void deleteaccount()
{
    //读取需要删除的账号信息，然后其他账号信息储存到一个新文件中，移除旧文件，把新文件的名字改为与旧文件相同
    FILE* fp = fopen("login.txt","r");
    FILE* fp1 = fopen("login1.txt","w");
    char a[30],b[30],account[30];
    if(!fp || !fp1)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    printf("\n  请输入您要删除的账户名和密码：\n");
    scanf("%s%*c",a);
    while(fgets(b,30,fp))
    {
        sscanf(b,"%s",account);    //将b的内容以%S的形式存储到account  sscanf()会将参数str的字符串根据参数format字符串来转换并格式化数据。
        if(strcmp(account,a) != 0)
            fputs(b,fp1);
    }
    printf("删除成功! 即将自动返回！\n");
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
        printf("文件打开失败\n");
        exit(0);
    }
    printf("请输入您要进行修改密码的账号以及旧密码\n\n");
    fflush(stdin);
    printf("      账号和旧密码：");
    scanf("%s",account1);
    printf("请输入您要进行修改密码的账号以及新密码\n\n");
    printf("      账号和新密码：");
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
    printf("密码修改成功！即将自动返回！\n");
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
        printf("\n          ***** 请选择您要进行操作的编号：*****\n\n");
        printf("            1.      添加菜单信息\n\n");
        printf("            2.      查看更新后菜单信息\n\n");
        printf("            3.      删除菜单信息\n\n");
        printf("            4.      返回上一级\n");
        scanf("%d%*c",&a);
        switch(a)
        {
        case 1:
            input();
            break;
        case 2:
            //更新菜单后，重新显示菜单中的信息
            displaymenu();
            break;
        //返回上一级
        case 3:
            deletemenu();
            break;
        case 4:
            return 0;
        default :
            printf("请重新输入!\n");
            break;
        }
    }
    return 0;
}

void input()
{
    FILE* fp=fopen("menu.txt","a");
    int n,i;
    //在存有菜单信息的文件中追加新的菜品信息
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    printf("  请输入您需要增加菜单的数量：");
    scanf("%d%*c",&n);
    //输入菜品信息并保存
    printf("  请在每行输入编号，菜名和价格，以空格分开:\n");
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
        printf("文件打开失败\n");
        exit(0);
    }
    printf("请输入您要删除的菜的编号：\n");
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
    printf("菜单修改成功!\n");
    fclose(fp),fclose(tmp);
    remove("menu.txt");
    rename("tmp.txt","menu.txt");
}

void qingkongcaidan()
{
    FILE* fp = fopen("diancai.txt","w");
    if(!fp)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    printf("\n              清空成功\n\n");
    Sleep(500);
    fclose(fp);
}

int main()
{
    welcome();
    return 0;
}
