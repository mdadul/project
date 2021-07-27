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

// Gotoxy Function 
void gotoxy(int x, int y)
{
	printf("\033[%d;%dH",y,x);
}

// Drawing a line 
void drawline(int x1, int y1, int x2,int y2,char ch,char c)
{
    int i;
    if(x1==x2){
        for(i=y1;i<y2;i++){
           gotoxy(x1,i);
           printf("%c",c);
	}
    }
    else{
        for(i=x1;i<x2;i++)
	{
	   gotoxy(i,y1);
	   printf("%c",ch);
	}
   }
}

// Rectangle Drawing
void drawrect(int x1, int y1, int x2, int y2,char ch,char c)
{
	drawline(x1, y1, x2, y1,ch,c);
	drawline(x2, y1, x2, y2,ch,c);
	drawline(x1, y1, x1, y2,ch,c);
	drawline(x1, y2, x2, y2,ch,c);
	
}


// Structure of Students 

struct Student{
  char name[200], ID[20],email[60], password[50];
  int semester;
  char mobile[30];
  double cgpa[10];
};

			
typedef struct Student STD;

// use your file path, where program read input data
char filePath[100] = "input.txt";

// Get All records from file ... 

int getRecords(STD stdList[],int x)
{
	int i, n = 0;
  if(x==0){
     FILE *fp = fopen(filePath, "r"); 
       if(fp == 0) {
  	   red();
       printf("Cannt open file\n");
       return -1;
     }
       
  STD aStd;

  /// Showing all records
  
  while(fgets(aStd.name, sizeof aStd.name, fp) != NULL)
  {
    fscanf(fp, "%s%s%s%d", aStd.ID,aStd.email,aStd.mobile, &aStd.semester);
    
    for(int i=1; i<=8; i++)
    {
      fscanf(fp,"%lf",&aStd.cgpa[i]);
    }
    fscanf(fp,"\n");
    strcpy(stdList[n].name, aStd.name);
    strcpy(stdList[n].ID, aStd.ID);
    strcpy(stdList[n].email,aStd.email);
    strcpy(stdList[n].mobile,aStd.mobile);
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
  else
  {
  	FILE *fp = fopen("RecycleBin.txt","r");
  	  
  STD aStd;

  /// Showing all records
  
  while(fgets(aStd.name, sizeof aStd.name, fp) != NULL)
  {
    fscanf(fp, "%s%s%s%d", aStd.ID,aStd.email,aStd.mobile, &aStd.semester);
    
    for(int i=1; i<=8; i++)
    {
      fscanf(fp,"%lf",&aStd.cgpa[i]);
    }
    fscanf(fp,"\n");
    strcpy(stdList[n].name, aStd.name);
    strcpy(stdList[n].ID, aStd.ID);
    strcpy(stdList[n].email,aStd.email);
    strcpy(stdList[n].mobile,aStd.mobile);
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

}








//  ShowRecords function to show all records from file


void showRecords()
{
  STD stdList[100];
  int i, j,n = getRecords(stdList,0);
  if(n==0){
  	 printf("There is no record. Please, add record.\n"); 
  	 return;
  } 
  gotoxy(12, 2);
  cyan();
  printf("Student Record");
  printf("\n\n");
  reset();
  for(i = 0; i < n; i++) {
  	
  	if(i%3==0) green();
  	else if(i%3==1)cyan();
  	else white();
  	
  	
    printf("Name    : %s", stdList[i].name);
    printf("ID      : %s\n", stdList[i].ID);
    printf("E-mail  : %s\n",stdList[i].email);
    printf("Mobile  : %s\n",stdList[i].mobile);
    printf("Semester: %d\n",stdList[i].semester);
    printf("CGPA    : ");
    for(j=1; j<=8; j++)
    {
      printf("%.2lf ",stdList[i].cgpa[j]);
    }
    reset();
    printf("\n\n");
  }
}


//=====Add Record Function start===//

void addRecord()
{
  white();
  gotoxy(12, 2);
  printf("Add Record");
  printf("\n\n");
	reset();
  STD stdList[100];
  int n = getRecords(stdList,0);
  
  FILE *fp = fopen(filePath, "a");
  
  STD add;
  int i,flag=0;
  printf("\nEnter your Id: ");
  scanf("%s",add.ID);
  
  for(i=0; i<n; i++)
  {
    if(strcmp(add.ID,stdList[i].ID)==0)
    {
      printf("\n\n\tDuplicate Matric Id\nEnter another info\n");
      flag=1;
    }
  }
 
  if(flag==0)
  {
    printf("\nEnter your name: ");
    scanf(" %[^\n]",add.name);
    printf("\nEnter your email:");
    scanf("%s",add.email);
    printf("\nEnter your mobile no :");
    scanf("%s",add.mobile);
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
     fprintf(fp,"%s\n",add.mobile);
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
	white();
  gotoxy(12, 2);
  printf("Delete Record");
  printf("\n\n");
	reset();
	
  printf("\nPlease, Enter your Id: ");
  char ID[100];
  scanf("%s",ID);
  
  STD stdList[100];
  int i,j, n = getRecords(stdList,0);
  double max=-1;

  FILE *fp = fopen(filePath, "w");
  FILE *Rc = fopen("RecycleBin.txt","a");
  
  //===i. delete record ===//
    
  for(int i = 0; i < n; i++)
  {
    if(strcmp(stdList[i].ID, ID) != 0) {
      fprintf(fp, "%s%s\n%s\n%s\n%d\n", 
        stdList[i].name, stdList[i].ID, stdList[i].email,stdList[i].mobile, stdList[i].semester);
      for(j=1; j<=8; j++)
      {
        fprintf(fp,"%.2f ",stdList[i].cgpa[j]);
      }
      fprintf(fp,"\n");
    }
    else
    {
    	fprintf(Rc, "%s%s\n%s\n%s\n%d\n", stdList[i].name, stdList[i].ID, stdList[i].email,stdList[i].mobile, stdList[i].semester);
      for(j=1; j<=8; j++)
      {
        fprintf(Rc,"%.2f ",stdList[i].cgpa[j]);
      }
      fprintf(Rc,"\n");
    }
  }
  //===ii=====
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
      printf("\n\nHighest CGPA : %.2lf\n",max);
      printf("Semester     : ");
      for(j=1; j<=8; j++)
      {
        
        if(max==stdList[i].cgpa[j])
        {
          printf("%d, ",j);
        }
      }
      printf("\n");
    }
  }
  fclose(fp);
  fclose(Rc);
}



/// Update Record 

void update()
{
  white();
  gotoxy(12, 2);
  printf("Update Record");
  printf("\n\n");
	reset();
	
  printf("\nPlease Enter your Id: ");
  char id[100];
  scanf("%s",id);
  STD stdList[100];
  int i,j,n=getRecords(stdList,0);
  
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
    fprintf(fp,"%s\n",stdList[i].mobile);
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
	int i,j,flag=0,n=getRecords(stdList,0);
	
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
			fprintf(tx, "Mobile         : %s\n",stdList[i].mobile);
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
// sorting Record 

void sort()
{
	STD stds[1000];
	int n = getRecords(stds,0), i, f, j, k;
	char temp[100];
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++)
			if(strcmp(stds[i].ID, stds[j].ID) < 1) {
				strcpy(temp, stds[i].ID);
				strcpy(stds[i].ID, stds[j].ID);
				strcpy(stds[j].ID, temp);
			}
	}
	for(i = 0; i < n; i++) {
		printf("%s\n", stds[i].ID);
	}
}

// Show deleted records from recycle Bin.
void showRecycle()
{
  STD stdList[100];
  int i, j,n = getRecords(stdList,1);
  if(n==0){
  	 printf("Empty Recyle Bin \n"); 
  	 return;
  } 
  gotoxy(12, 2);
  cyan();
  printf("Recycle Bin");
  printf("\n\n");
  reset();
  for(i = 0; i < n; i++) {
  	
  	if(i%3==0) green();
  	else if(i%3==1)cyan();
  	else white();
  	
  	
    printf("Name    : %s", stdList[i].name);
    printf("ID      : %s\n", stdList[i].ID);
    printf("E-mail  : %s\n",stdList[i].email);
    printf("Mobile  : %s\n",stdList[i].mobile);
    printf("Semester: %d\n",stdList[i].semester);
    printf("CGPA    : ");
    for(j=1; j<=8; j++)
    {
      printf("%.2lf ",stdList[i].cgpa[j]);
    }
    reset();
    printf("\n\n");
  }
}

	
///Main Function  


int main()
{

  cyan();
  drawrect(1, 0, 46, 4, '~','+');
  yellow();
  gotoxy(5, 1);
  printf("Welcome To Student Management Solution");
  gotoxy(7, 2);
  printf("Developed By: Emdadul Islam");
  gotoxy(15, 5);
  yellow();
  printf("\n╭╮╭╮╭╮╱╱╭╮\n");
  printf("┃┃┃┃┃┃╱╱┃┃\n");
  printf("┃┃┃┃┃┣━━┫┃╭━━┳━━┳╮╭┳━━╮\n");
  printf("┃╰╯╰╯┃┃━┫┃┃╭━┫╭╮┃╰╯┃┃━┫\n");
  printf("╰╮╭╮╭┫┃━┫╰┫╰━┫╰╯┃┃┃┃┃━┫\n");
  printf("╱╰╯╰╯╰━━┻━┻━━┻━━┻┻┻┻━━╯\n");
	
	
  drawrect(15, 13,35,15, '+','!');
  gotoxy(23, 14);
  green();
  printf("Menu");
  gotoxy(1, 17);
  printf("Please Enter a number upto 4 to choose option\n\n\n");
  int choice;
  while(1)
  {
     cyan();
     printf("\t\t1. Show info.\n\t\t2. Add record\n\t\t3. Delete Record\n\t\t4. Update Record\n\t\t5. Sort Record\n\t\t6. Save As Txt file\n\t\t7. Recycle Bin\n\t\t8. Exit\n");
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
         sort();
         break;
       case 6:
          SaveAsTextFile();
          break;
       case 7:
       	showRecycle();
        break;
       case 8:
         exit(1);
         break;
     }
   }

  return 0;
}

