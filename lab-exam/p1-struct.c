#include <stdio.h>

struct student{
    char usn[11];
    char name[30];
    int age;
    float cgpa;
};

int main(){
    struct student obj[10];
    int n;
    float key_gpa;
    printf("Enter number of students - ");
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        printf("Enter usn, name, age and cgpa of student %d - ", i+1);
        scanf("%s %s %d %f",obj[i].usn, obj[i].name, &obj[i].age, &obj[i].cgpa);
    }
    printf("Enter cgpa - ");
    scanf("%f", &key_gpa);
    for(int i = 0; i<n; i++){
        if(obj[i].cgpa >= key_gpa){
            printf("Name - %s  USN - %s  CGPA - %.2f  Age - %d\n",obj[i].name, obj[i].usn, obj[i].cgpa, obj[i].age);
        }
    }
    return 0;
}