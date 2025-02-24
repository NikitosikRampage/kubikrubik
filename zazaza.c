#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef enum
{
    FIRST = 1,
    SECOND,
    THIRD,
    FOURTH
} CourseLevel;
typedef struct
{
    char surname[51];
    char name[51];
    int date_of_birth;
    CourseLevel course;
    float average_grade;
} Student;

int latin(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int N;
    float max_grade1 = 0;
    float max_grade2 = 0;
    float max_grade3 = 0;
    float max_grade4 = 0;
    int index1 = -1;
    int index2 = -1;
    int index3 = -1;
    int index4 = -1;
    Student students[100];
    scanf("%d", &N);
    if (N < 1 || N > 100)
    {
        printf("Invalid number of students.");
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%50s", students[i].surname);
        if (!latin(students[i].surname))
        {
            printf("Invalid surname for student %d.", i + 1);
            return 0;
        }
        scanf("%50s", students[i].name);
        if (!latin(students[i].name))
        {
            printf("Invalid name for student %d.", i + 1);
            return 0;
        }
        if (!scanf("%d", &students[i].date_of_birth))
        {
            printf("Invalid birth year for student %d.", i + 1);
            return 0;
        }
        if (!scanf("%d", &students[i].course) || students[i].course < 1 || students[i].course > 4)
        {
            printf("Invalid course number for student %d.", i + 1);
            return 0;
        }
        if (!scanf("%f", &students[i].average_grade) || students[i].average_grade > 5 || students[i].average_grade < 0)
        {
            printf("Invalid average grade for student %d.", i + 1);
            return 0;
        }
        if (students[i].course == FIRST)
        {
            if (students[i].average_grade > max_grade1)
            {
                max_grade1 = students[i].average_grade;
                index1 = i;
            }
        }
        else if (students[i].course == SECOND)
        {
            if (students[i].average_grade > max_grade2)
            {
                max_grade2 = students[i].average_grade;
                index2 = i;
            }
        }
        else if (students[i].course == THIRD)
        {
            if (students[i].average_grade > max_grade3)
            {
                max_grade3 = students[i].average_grade;
                index3 = i;
            }
        }
        else
        {
            if (students[i].average_grade > max_grade4)
            {
                max_grade4 = students[i].average_grade;
                index4 = i;
            }
        }
    }
    if (index1 != -1) {
        printf("Курс: FIRST Фамилия: %s Имя: %s Год рождения: %d Средний балл: %.2f\n",
            students[index1].surname, students[index1].name, students[index1].date_of_birth, students[index1].average_grade);
    }
    else {
        printf("Курс: FIRST Нет студентов\n");
    }

    if (index2 != -1) {
        printf("Курс: SECOND Фамилия: %s Имя: %s Год рождения: %d Средний балл: %.2f\n",
            students[index2].surname, students[index2].name, students[index2].date_of_birth, students[index2].average_grade);
    }
    else {
        printf("Курс: SECOND Нет студентов\n");
    }

    if (index3 != -1) {
        printf("Курс: THIRD Фамилия: %s Имя: %s Год рождения: %d Средний балл: %.2f\n",
            students[index3].surname, students[index3].name, students[index3].date_of_birth, students[index3].average_grade);
    }
    else {
        printf("Курс: THIRD Нет студентов\n");
    }

    if (index4 != -1) {
        printf("Курс: FOURTH Фамилия: %s Имя: %s Год рождения: %d Средний балл: %.2f\n",
            students[index4].surname, students[index4].name, students[index4].date_of_birth, students[index4].average_grade);
    }
    else {
        printf("Курс: FOURTH Нет студентов\n");
    }
    return 0;
}