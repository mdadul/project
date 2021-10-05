package BookStore;

import BookStore.Book;
import java.util.Scanner;

// Book Class
public class Book {
    // member variable 
    private String Issbn;
    private String BookName;
    private String Author;
    private String Edition;
    private String publication;
    
    Book()     // Constructor function 
    {
       Issbn =" ";
       BookName = " ";
       Author = " ";
       Edition = " ";
       publication = " ";
    }
    // setters 

    public void setIssbn(String Issbn)  // set Isbn
    {
      this.Issbn = Issbn;
    }
    public void setBookName(String BookName)   // to set book name
    {
      this.BookName = BookName;
    }
    public void setAuthor(String Author)
    {
      this.Author = Author;
    }
    public void setEdition(String Edition)
    {
      this.Edition = Edition;
    }
    public void setPublication(String publication)
    {
      this.publication = publication;
    }
    
    /// Getters 
    public String getIssbn()
    {
      return Issbn;
    }
    public String getBookName()
    {
      return BookName;  
    }
    public String getAuthor()
    {
      return Author;  
    }
    public String getEdition()
    {
      return Edition; 
    }
    public String getPublication()
    {
      return publication;  
    }
     
    // Methode. 
    // Add book method 
    public void add(String Issbn,String BookName, String Author, String Edition, String publication)
    {
      this.Issbn = Issbn;
      this.BookName = BookName;
      this.Author = Author;
      this.Edition = Edition;
      this.publication = publication;
    }

    /// To display data method 
    public void Display()
    {
       System.out.println("\nBook ISSBN no : "+ Issbn);
       System.out.println("\nBook Name : "+ BookName);
       System.out.println("\nBook author name : "+ Author);
       System.out.println("\nBook edition  : "+ Edition);
       System.out.println("\nBook publication name  : "+ publication);
       
    }
}


// Main class

public class Main {
public static Scanner sc = new Scanner(System.in);
  static int n =0;   // total book no. 
  public static Book[] book = new Book[100]; 
  public static void main(String[] args) {
     Option();   // To see  Menu & option 
     
  }

  // Menu method 
  public static int Menu()
  {
    int choice;
    do{
      println("**********************************************");
      println("   Welcome To Book Store Management System    ");
      println("**********************************************");
      
      println("\n[1] Add Book");
      println("[2] Update Book");
      println("[3] Delete Book");
      println("[4] Search Book");
      println("[5] Show All Book");
      println("[6] Quite");
      
      print("\n\nEnter your choice : ");
      choice = sc.nextInt();
      if(choice <1 || choice > 6)
      {
        println("\n\tWrong.....Choice Again\n");
      }
    }
    while(choice<0 || choice >6); 
    return choice;
  }
 
  // Option methode

  public  static void Option(){
    int choice;
    do{
      choice = Menu();
      switch(choice)
      {
        case 1:
            addBook();
            break;
        case 2:
            edit();
            break;
        case 3:
            Delete();
            break;
        case 4:
            Search();
            break;
        case 5 :
             display();
             break;
        case 6:
            println("\n++++++++++++++++++++++++++");
            println("|\t\t End of operation     |");
            println("++++++++++++++++++++++++++");
            break;
        }   
      }
      while(choice!=6);
  }
  
  // To add book in object's array 
  public static void addBook()
  {
    if(n>1000)
    {
      println("\t◇◇◇Book storage full◇◇◇");
    }
    else{
      book[n] = new Book();
      
      String issbn,name,author,ed,pub;
      
      println("*****************************");
      println("\n●●●📘 Add Book 📗●●●\n");
      println("*****************************");
   
      print("Enter book isbn no : ");
      sc.nextLine();
      issbn = sc.nextLine();
      print("Enter book name : ");
      name = sc.nextLine();
    
      print("Enter Author name : ");
      author = sc.nextLine();
    
      print("Enter book edition : ");
      ed = sc.nextLine();
    
      print("Enter publication name : ");
      pub = sc.nextLine();
      
      book[n].add(issbn,name,author,ed,pub);
     
      println("\n\n\t----------------------------");
      println("\t■■■Successfully added■■■");
      println("\t-----------------------------");
     
      n++;
    }
    print("\nEnter any character to continue : ");
    sc.next();
  }
  
  // To update/edit   
  public static void edit()
  {
    String Issbn;
    print("Enter Book Issbn no : ");
    sc.nextLine();
    Issbn = sc.nextLine();
    boolean isFound = false;
    for(int i=0; i<n; i++)
    {
      String temp = book[i].getIssbn();
      if(temp.equals(Issbn))
      {
        String name,author,ed,pub;
      
      println("********************************");
      println("●●●📘   Update Book     📗●●●");
      println("********************************");
   
      print("Enter book name : ");
      name = sc.nextLine();
    
      print("Enter Author name : ");
      author = sc.nextLine();
    
      print("Enter book edition : ");
      ed = sc.nextLine();
    
      print("Enter publication name : ");
      pub = sc.nextLine();
      
      book[i].add(temp,name,author,ed,pub);
     
      println("\n\n\t----------------------------");
      println("\t■■■Successfully added■■■");
      println("\t-----------------------------");
      
        isFound = true;
        break;
      }
    }
    if(!isFound)
    {
      println("---------------------");
      println("|  Book isn’t found |");
      println("---------------------");
    }
    
    print("\nEnter any character to continue : ");
    sc.next();
  }

  // to search book 
  public static void Search()
  {
    
    println("*****************************");
    println(" 🔎🔎🔎 Search Book   📗🔍🔍🔍");
    println("*****************************");
      
      
    String ISBN;
    print("Enrer Book ISBN no : ");
    sc.nextLine();
    ISBN = sc.nextLine();
    boolean isFound = false;
    for(int i=0; i<n; i++)
    {
      String temp = book[i].getIssbn();
      if(temp.equals(ISBN))
      {
         isFound = true;
         book[i].Display();
         break;
      }
    }
    if(!isFound)
    {
      println("---------------------");
      println("|  Book isn’t found |");
      println("---------------------");
    }
    
    print("\nEnter any character to continue : ");
    sc.next();
  }
  // to delete book from array 
  public static void Delete()
  {
    String Isbn;
    print("Enter book isbn no : ");
    sc.nextLine();
    Isbn = sc.nextLine();
    int pos = -1;
    boolean isFound = false;
    
    for(int i=0; i<n; i++)
    {
      String temp = book[i].getIssbn();
      if(Isbn.equals(temp))
      {
        pos = i;
        isFound = true;
        break;
      }
    }
    if(!isFound)
    {
      println("---------------------");
      println("|  Book isn’t found |");
      println("---------------------");
    }
    else{
    for(int i=pos; i<n-1; i++)
    {
      book[i].setIssbn(book[i+1].getIssbn());
      book[i].setBookName(book[i+1].getBookName());
      book[i].setAuthor(book[i+1].getAuthor());
      book[i].setEdition(book[i+1].getEdition());
      book[i].setPublication(book[i+1].getPublication());
    }
    n--;
    
    println("\n\n----------------------------");
    println("■■■Successfully Deleted ■■■");
    println("-----------------------------");
    }
  }
  // to display all data
  public static void display()
  {
     if(n==0) {
        println("There aren’t any Book. Please Add Book first ");
        
        println("\nEnter any character to continue : ");
        sc.next();
     }
     else {
          for(int i=0; i<n; i++)
          {
            println("-----------------------");
            println("|     Book no : "+(i+1)+"    |");
            println("------------------------");
            book[i].Display();
          }
    }
  }
  
  
  static void println(Object ob)
  {
    System.out.println(ob);
  }
  static void print(Object ob)
  {
    System.out.print(ob);
  }
  
}
