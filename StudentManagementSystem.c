/// Header File 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>

// Color Function to change text color. 

void red() {
  printf("\033[1;31m");
}
void yellow() {
  printf("\033[1;33m");
}
void green() {
  printf("\033[0;32m");
}
void blue() {
  printf("\033[0;34m");
}
void purple() {
  printf("\033[0;35m");
}
void cyan() {
  printf("\033[0;36m");
}
void white() {
  printf("\033[0;37m");
}
void reset () {
  printf("\033[0m");
}

// Structure of Student
struct Student{
  char name[200], ID[20],email[60], password[50];
  int semester;
  double cgpa[10];
};

// Password Checker

bool PasswordChecker(char pass[])
{
	int capital=0,small=0,digit=0,other=0	,i,len=0;
	len = strlen(pass);
	for(i=0;i<len;i++)
	{
		if(pass[i]>='A' && pass[i]<='Z')
		{
			capital++;
		}
		else if(pass[i]>='a' && pass[i]<='z')
		{
			small++;
		}
		else if(pass[i]>='0' && pass[i]<='9')
		{
			digit++;
		}
		else
		{
			other++;
		}
	}
	if(len>=8 && capital>=1 && small>=1 && other>=1)
	{
		return true;
		}
		else
		{
			return false;
		}
}

			
typedef struct Student STD;

// use your file path, where program read input data
char filePath[100] = "input.txt";

// Get All records from file ... 
int getRecords(STD stdList[])
{
  FILE *fp = fopen(filePath, "r"); 
  
  STD aStd;
  if(fp == 0) {
  	red();   // Text color 
    printf("Cannt open file\n");
    return -1;
  }
  /// Showing all records
  int i, n = 0;
  while(fgets(aStd.name, sizeof aStd.name, fp) != NULL)
  {
    fscanf(fp, "%s%s%d", aStd.ID,aStd.email, &aStd.semester);
    
    for(int i=1; i<=8; i++)
    {
      fscanf(fp,"%lf",&aStd.cgpa[i]);
    }
    fscanf(fp,"\n");
    strcpy(stdList[n].name, aStd.name);
    strcpy(stdList[n].ID, aStd.ID);
    strcpy(stdList[n].email,aStd.email);
    stdList[n].semester = aStd.semester;
    
    for(i=1; i<=8; i++)
    {
      stdList[n].cgpa[i] = aStd.cgpa[i];
    }
    n++;
  }
  fclose(fp);
  return n;
}

/////ShowRecords function to show all records from file

void showRecords()
{
  STD stdList[100];
  int i, j,n = getRecords(stdList);
  
  red();    // text color

  printf("\n\n\t\t\t===Student Record===\n\n");
  
  reset();   // text color reset

  for(i = 0; i < n; i++) {
  	
    printf("Name    : %s", stdList[i].name);
    printf("ID      : %s\n", stdList[i].ID);
    printf("E-mail  : %s\n",stdList[i].email);
    printf("Semester: %d\n",stdList[i].semester);
    printf("CGPA    : ");
    for(j=1; j<=8; j++)
    {
      printf("%.2lf ",stdList[i].cgpa[j]);
    }
    printf("\n\n");
  }
}
//=====END====///

//=====Add Record Function start===//
void addRecord()
{
	red();   // text color 
	printf("\n\t\t=====Add Record======\n\n");
	reset();   // to reset text color 
  STD stdList[100];
  int n = getRecords(stdList);
  
  FILE *fp = fopen(filePath, "a");
  
  STD add;
  int i,flag=0;
  printf("\nEnter your Id: ");
  scanf("%s",add.ID);
  
  for(i=0; i<n; i++)
  {
    if(strcmp(add.ID,stdList[i].ID)==0)
    {
      printf("Duplicate Matric Id\nEnter another info\n");
      flag=1;
    }
  }
 
  if(flag==0)
  {
    printf("\nEnter your name: ");
    scanf(" %[^\n]",add.name);
    printf("\nEnter your email:");
    scanf("%s",add.email);
    printf("\nEnter your Semester no: ");
    scanf(" %d",&add.semester);
    for(int i=1; i<add.semester; i++)
    {
      printf("\nEnter your %d semester CGPA: ",i);
      scanf("%lf",&add.cgpa[i]);
    }
    
     fprintf(fp,"\n%s\n", add.name);
     fprintf(fp,"%s\n", add.ID);
     fprintf(fp,"%s\n",add.email);
     fprintf(fp,"%d\n", add.semester);
     for(i=add.semester;i<=8;i++)
     {
     	 	add.cgpa[i]=0.00;
     }
     for(i=1; i<=8; i++)
     {
       fprintf(fp,"%.2lf ",add.cgpa[i]);
     }
     purple();
      printf("\n\n\t\t===Successfully Added===\n\n");
     reset();
  }
 
 
  fclose(fp);
}
//=====Delete Record By ID======//

void deleteRecord()
{
	purple();
	printf("\n\t\t=====Delete Record======\n\n");
	reset();
	
  printf("\nPlease, Enter your Id: ");
  char ID[100];
  scanf("%s",ID);
  
  STD stdList[100];
  int i,j, n = getRecords(stdList);
  double max=-1;

  FILE *fp = fopen(filePath, "w");
  
  //===i. delete record ===//
    
  for(int i = 0; i < n; i++)
  {
    if(strcmp(stdList[i].ID, ID) != 0) {
      fprintf(fp, "%s%s\n%s\n%d\n", 
        stdList[i].name, stdList[i].ID, stdList[i].email, stdList[i].semester);
      for(j=1; j<=8; j++)
      {
        fprintf(fp,"%.2f ",stdList[i].cgpa[j]);
      }
      fprintf(fp,"\n");
    }
  }
  // show deleted id's highest Cgpa in which semester 
  for(i=0; i<n; i++)
  {
    if(strcmp(stdList[i].ID,ID)==0)
    {
      printf(" Name: %s\n",stdList[i].name);
     
      for(j=1; j<=8; j++)
      {
        if(max<stdList[i].cgpa[j])
        {
          max = stdList[i].cgpa[j];
        }
      }
      printf("Highest CGPA : %.2lf\n",max);
      printf("Semester     : ");
      for(j=1; j<=8; j++)
      {
        
        if(max==stdList[i].cgpa[j])
        {
          printf("%d, ",j-1);
        }
      }
      printf("\n");
    }
  }
  fclose(fp);
}

/// Update Record 
void update()
{
	purple();
	printf("\n\t\t=====Update Record======\n\n");
	reset();
	
  printf("\nPlease Enter your Id: ");
  char id[100];
  scanf("%s",id);
  STD stdList[100];
  int i,j,n=getRecords(stdList);
  /// if user write " GPA" then, update his/her cgpa  and write "EMAIL", update email address 
  double newCGPA;
  int updatesem;
  char newMail[50],ch[50];
  printf("\nEnter GPA OR EMAIL TO UPDATE: ");
  scanf("%s",ch);
  if(strcmp(ch,"EMAIL")==0)
  {
    printf("\nEnter your updated E-mail: ");
    scanf("%s",newMail);
    for(i=0; i<n; i++)
    {
      if(strcmp(stdList[i].ID,id)==0)
      {
        strcpy(stdList[i].email,newMail);
      }
    }
  }
  else
  {
    printf("\nEnter your semester to update CGPA: ");
    scanf("%d",&updatesem);
    printf("\nEnter updated CGPA: ");
    scanf("%lf",&newCGPA);
    for(i=0; i<n; i++)
    {
      if(strcmp(stdList[i].ID,id)==0)
      {
        stdList[i].cgpa[updatesem] = newCGPA;
      }
    }
  }
  FILE *fp = fopen(filePath,"w");
  for(i=0; i<n; i++)
  {
    fprintf(fp,"%s",stdList[i].name);
    fprintf(fp,"%s\n",stdList[i].ID);
    fprintf(fp,"%s\n",stdList[i].email);
    fprintf(fp,"%d\n",stdList[i].semester);
    for(j=1;j<=8; j++)
    {
      fprintf(fp,"%.2lf ",stdList[i].cgpa[j]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
}

// This function save a text file of any id 
void SaveAsTextFile()
{
	printf("Enter your id : ");
	char id	[50];
	scanf("%s",id);
	STD stdList[100];
	int i,j,flag=0,n=getRecords(stdList);
	
	char txt[100];
	strcpy(txt,id);
	strcat(txt,".txt");
	
	FILE *tx = fopen(txt,"w");
	if(tx==0){
		printf("Cann't open file\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(stdList[i].ID,id)==0)
		{
			flag=1;
			red();
			fprintf(tx, "Name         : %s",stdList[i].name);
			fprintf(tx, "ID                 : %s\n",stdList[i].ID);
			fprintf(tx, "Email          : %s\n",stdList[i].email);
			fprintf(tx, "Semester    : %d\n",stdList[i].semester);
			fprintf(tx, "CGPA           : ");
			for(j=1;j<=8;j++)
			{
				fprintf(tx, " %.2lf ",stdList[i].cgpa[j]);
			}
		}
	}
	if(flag==0) printf("Id Not Found\n");
	fclose(tx);
}
	
///Main Function  


int main()
{
	printf("\n\t ");
	system("date");  // print date & time.  
	printf("\n\n");
	red();
	printf("================================================\n");
   printf("\t\tWelcome To Student Management Solution\n");
   printf("\t\tDeveloped By: Emdadul Islam\n");
	printf("================================================\n");
	reset();
	purple();
   printf("\t\t\t--------------------\n");
   printf("\t\t\t\t\tMenu\n");
    printf("\t\t\t--------------------\n");
	reset();
	blue();
   printf("\nPlease Enter a number upto 4 to choose option\n\n ");
   int choice;
   while(1)
   {
   	red();
     printf("\t\t1. Show info.\n\t\t2. Add record\n\t\t3. Delete Record\n\t\t4. Update Record\n\t\t5. Sort Record\n\t\t6. Save As Txt file\n\t\t7. Exit\n");
     scanf("%d",&choice);
     system("cls");
     switch(choice)
     {
       case 1:
         showRecords();
         break;
       case 2:
         addRecord();
         break;
       case 3:
         deleteRecord();
         break;
       case 4:
         update();
         break;
       case 5:
         //sort();
         break;
       case 6:
          SaveAsTextFile();
          break;
       case 7:
         exit(1);
         break;
     }
   }
  return 0;
}

