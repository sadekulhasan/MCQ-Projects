#include<stdio.h>
int choice1,choice2;

char ans;
struct M
{
    int mark;
} QuizMark;


void projectHeader(char *message)
{
    system("cls");
    printf("\n");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t**                MCQ Quiz App               **");
    printf("\n\t\t\t**                                           **");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t***********************************************");
    printf("\n\t\t\t\t\t%s",message);
    printf("\n\t\t\t-----------------------------------------------");
}
void submittedBy()
{
    projectHeader("Submitted By Menu");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    printf("\n\t\t\t        =          Name           ID                 =");
    printf("\n\t\t\t        =********************************************=");
    printf("\n\t\t\t        =    1. Sakib Dewan      ID: 212-15-147132   =");
    printf("\n\t\t\t        =    2. Alimoon Taha     ID: 212-15-14725    =");
    printf("\n\t\t\t        =    3. Ruhul Quddus     ID: 212-15-14712    =");
    printf("\n\t\t\t        =    4. Ruksana Tabassum ID: 212-15-14728    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
void submittedTo()
{
    projectHeader("Submitted To Menu");
    printf("\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =  Dr. Sheak Rashed Haider Noori  =");
    printf("\n\t\t\t        =*********************************=");
    printf("\n\t\t\t        =    Associate Professor          =");
    printf("\n\t\t\t        =    Dept. of CSE,                =");
    printf("\n\t\t\t        =    DIU                          =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
void question1_view_from_file()
{
    FILE *fptr = fopen("question1.txt", "r");
    char i='a',ch;
    printf("\n\n\t\tWhat is our course name?\n");
    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch!=',')
            printf("%c", ch);
        else
            printf("\t%c. ",i++);
    }


    fclose(fptr);

}
void question_1()
{
    system("color 00");
    projectHeader("QUESTION 1");
    question1_view_from_file();
    printf("\n\tWhich one is the correct answer?");
    scanf(" %c",&ans);
    switch(ans)
    {
    case 'a':
        QuizMark.mark++;
        printf("\n\tSuccessfully typed correct answer. ");
        printf("\n\tYour total score = %d\n",QuizMark.mark);
        setScore(QuizMark.mark);
        printf("Press any key to continue....");
        getch();
        questionSet();
        break;
    case 'b':
    case 'c':
    case 'd':
        printf("\n\tSorry!!! Your answer is wrong. ");
        getch();
        break;
    }
}
void question2_view_from_file()
{
    system("color 00");
    FILE *fptr = fopen("question2.txt", "r");
    char i='a',ch;

    printf("\n\n\t\t\tWho is the father of Bengali Nation?\n");
    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch!=',')
            printf("%c", ch);
        else
            printf("\t%c. ",i++);
    }
    fclose(fptr);
}
void question3_view_from_file()
{
    system("color 00");
    FILE *fptr = fopen("question3.txt", "r");
    char i='a',ch;

    printf("\n\n\t\t\tWho is PM of BD?\n");
    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch!=',')
            printf("%c", ch);
        else
            printf("\t%c. ",i++);
    }
    fclose(fptr);
}
void question_2()
{
    system("color 00");
    projectHeader("QUESTION 2");
    question2_view_from_file();

    printf("\n\tWhich one is the correct answer?");
    scanf(" %c",&ans);
    switch(ans)
    {
    case 'b':
        QuizMark.mark++;
        printf("\n\tSuccessfully typed correct answer. ");
        printf("\n\tYour total score = %d\n",QuizMark.mark);
        setScore(QuizMark.mark);
        printf("Press any key to continue....");
        getch();
        questionSet();
        break;
    case 'a':
    case 'c':
    case 'd':
        printf("\n\tSorry!!! Your answer is wrong. ");
        getch();
        break;
    }
}
void question_3()
{
    system("color 00");
    projectHeader("QUESTION 3");
    question3_view_from_file();
    printf("\n\tWhich one is the correct answer?");
    scanf(" %c",&ans);
    switch(ans)
    {
    case 'd':
        QuizMark.mark++;
        printf("\n\tSuccessfully typed correct answer. ");
        printf("\n\tYour total score = %d\n",QuizMark.mark);
        setScore(QuizMark.mark);
        printf("Press any key to continue....");
        getch();
        questionSet();
        break;
    case 'a':
    case 'c':
    case 'b':
        printf("\n\tSorry!!! Your answer is wrong. ");
        getch();
        break;
    }
}
void questionSet()
{
    projectHeader("QUESTION SETS");
    printf("\n\n\n\t\t\t1.Main Menu");
    printf("\n\n\n\t\t\t2.Question 1");
    printf("\n\t\t\t3.Question 2");
    printf("\n\t\t\t4.Question 3");
    printf("\n\n\n\t\t\tEnter choice => ");
    scanf("%d",&choice1);
    switch(choice1)
    {
    case 1:
        question_1();
        break;
    case 2:
        question_2();
        break;
    case 3:
        question_3();
        break;
    default:
        printf("\n\n\n\t\t\tWRONG CHOICE !!! Try again...");
    }
}
int getScore()
{
    FILE *fptr = fopen("score.txt", "r");
    char ch;

    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch!=',') return ch;

    }
    fclose(fptr);
}
void setScore(int mark)
{

    FILE *fptr = fopen("score.txt","w");
    char comma = ',';
    if(fptr != NULL)
    {
        fprintf(fptr,"%d",QuizMark.mark);
        fprintf(fptr,"%c",comma);
        fclose(fptr);
    }
    else
    {
        printf("Error!");

    }
}
void selectOption()
{
    system("color 00");
    projectHeader("MAIN MENU");
    printf("\n\n\n\t\t\t1.Submitted By");
    printf("\n\t\t\t2.Submitted To");
    printf("\n\t\t\t3.Questions Set");
    printf("\n\t\t\t4.Total Score");
    printf("\n\n\n\t\t\tEnter choice => ");
    scanf("%d",&choice1);
    switch(choice1)
    {
    case 1:
        submittedBy();
        break;
    case 2:
        submittedTo();
        break;
    case 3:
        questionSet();
        break;
    case 4:
        printf("\n\t\tYour total score is = %d\n",QuizMark.mark);
        getch();
        break;
    default:
        printf("\n\n\n\t\t\tWRONG CHOICE !!! Try again...");
    }

}
void main()
{
    system("color 00");
    QuizMark.mark=0;
    while(1)
    {
        selectOption();

        printf("\n\t\t\t0.Exit");
        printf("\n\t\t\t1.Continue");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice2);
        if(choice2==0)
        {
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        }
        else if(choice2==1)
        {
            selectOption();
        }
    }
}

