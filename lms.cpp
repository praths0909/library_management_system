/*By default , these are the registered users in Library Management System 
Students:
UserId : 0, Name : Pratham Jain , password : pratham
Professors:
UserId : 1, Name : Indranil Saha , password : cs253
Librarian:
UserId : 2, Name : XYZ , password : library

By default, these are the books present 
BookId : 1, Name : Thermodynamics ,  Author : Cengel_Boles , Owner = 0
BookId : 2, Name : Organic Chemistry , Author : Clayden , Owner = 1
BookId : 3, Name : Verilog , Author : Palnitkar , Owner = Not issued by default
BookId : 4, Name : Computer Architecture , Author : Patterson , Owner = Not issued by default


Some general Instructions
 
UserId and BookID are numeric and you should remember them to access your account.
*/
// Some git testing changes
#include<bits/stdc++.h>
using namespace std;

class book{                                //class book
    public:
    static int ID1;                        //static int to give each book a unique ID
    int bid;                               //book ID
    string title;                          //Book Name
    string author;                         //Book Author
    int available;                         // If book is available in library , available=1 ,else, available=0
    int owner;                             // = book onwer id if book issued , else = -1
    book(){                                // Constructor , ID1 increases whenever book created
        ID1++;
        bid=ID1;                           // assigning ID1 value to book ID
    }

};
int book::ID1=0;
class user{                                 // class user , will have student, professor , librarian as subclass
    public:
    static int ID2;                         //static int to give each user a unique ID
    int uid;                                //user ID
    string name;                            //User Name
    string password;                        //User Password
    int book_issued;                        // Number of book issued
    user()                                  //Constructor
    {
        uid=ID2;
        book_issued=0;
    }
};
int user::ID2=0;
class prof:public user{
    public:
    int fine;                                //fine 
    prof(){
        ID2++;
    }
    vector<book>pb;                           //vector of books of prof(pb=prof books)
    void display()                            //Display prof profile
    {
        cout<<"\nUser ID: "<<uid<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Role : Professor\n";
    }
    void display_issued_books()              //Display list of issued books with book id, book title , book author
    {
        cout<<"\nYou have issued "<<pb.size()<<" books.\n";
        for(int i=0;i<pb.size();i++)
        cout<<"Book ID : "<<pb[i].bid<<"    Book Name : "<<pb[i].title<<"    Book Author : "<<pb[i].author<<"\n";
    }
};

class student:public user{
    public:
    int fine;                                //fine 
    student(){
        ID2++;
    }
    vector<book>sb;                             //vector of books of student(sb=student books)
    void display()                              //Display student profile
    {
        cout<<"\nUser ID: "<<uid<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Role : Student\n";
    }
    void display_issued_books()                 //Display list of issued books with book id, book title , book author
    {
        cout<<"\nYou have issued "<<sb.size()<<" books.\n";
        for(int i=0;i<sb.size();i++)
        cout<<"Book ID : "<<sb[i].bid<<"    Book Name : "<<sb[i].title<<"    Book Author : "<<sb[i].author<<"\n";
    }
};
class lib:public user{
    public:
    lib(){
        ID2++;
    }
    void display()                                //Display Librarian profile
    {
        cout<<"\nUser ID: "<<uid<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Role : Librarian\n";
    }
};
class prof_database{
    public:
    vector<prof>all_prof;
    void add_prof(prof a){
        all_prof.push_back(a);
    }
    int is_prof_present(int id)            //If prof with uid id present ,return 1 else return 0
    {
        for(int i=0;i<all_prof.size();i++)
        if(all_prof[i].uid==id)
        return 1;
        return 0;
    }
    void remove_prof(int id)             //remove prof with uid "id"
    {
        if(is_prof_present(id)){
        cout<<"This professor is not present in database";
        return;}
        for(int i=0;i<all_prof.size();i++)
        {
            if(all_prof[i].uid==id){
                cout<<"Professor "<<all_prof[i].name<< " Removed\n";
                all_prof.erase(all_prof.begin()+i);
            }
        }
        
        return;
    }
 
    prof search_prof(int id){              //returns prof with uid id object //called only when prof is present with this uid 
    // if(is_prof_present(id))
    // cout<<"This professor is not present in database";
    for(int i=0;i<all_prof.size();i++)
    {
        if(all_prof[i].uid==id)
        return all_prof[i];
    }
    return all_prof[0];
    }

};
class lib_database{
public:
    vector<lib>all_lib;
    int is_lib_present(int id)
    {
        for(int i=0;i<all_lib.size();i++)
        if(all_lib[i].uid==id)
        return 1;
        return 0;
    }
    lib search_lib(int id){
    for(int i=0;i<all_lib.size();i++)
        if(all_lib[i].uid==id)
        return all_lib[i];
        return all_lib[0];
    }
};
class student_database{
    public:
    vector<student>all_students;
    void add_student(student a){
        all_students.push_back(a);
    }
    int is_student_present(int id)
    {
        for(int i=0;i<all_students.size();i++)
        if(all_students[i].uid==id)
        return 1;
        return 0;
    }
    student search_student(int id){
    for(int i=0;i<all_students.size();i++)
        if(all_students[i].uid==id)
        return all_students[i];
        return all_students[0];
    }
    void remove_student(int id)
    {
        if(is_student_present(id)){
       cout<<"This Student is not present in database";
       return;}
        for(int i=0;i<all_students.size();i++)
        {
            if(all_students[i].uid==id)
            all_students.erase(all_students.begin()+i);
        }
        cout<<"Student Removed\n";
        return;
    }

};

student_database sd;
prof_database pd;
lib_database ld;

class book_database{
    public:
    vector<book>all_books;
    void add_book()
    {
        book a;
        string x;
        cout<<"\nEnter book title\n";
        //cin>>x;
        getchar();
        getline(cin,x);
        a.title=x;
        cout<<"Enter book author\n";
        //cin>>x;
        getchar();
        getline(cin,x);
        a.author=x;
        a.available=1;
        a.owner=-1;
        all_books.push_back(a);
        cout<<"Details of book added:\nTitle : "<<a.title<<"   Author : "<<a.author<<"    Book ID : "<<a.bid<<"\n";
    }
    int delete_book(int id)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==id)
            {
               //delete from owner
                if(all_books[i].available==0)
                {
                    int owner=all_books[i].owner;
                    int prof_or_stud=-1;                //0 if student,else 1
                    student curr;
                    for(int i=0;i<sd.all_students.size()&&prof_or_stud==-1;i++)
                    {
                        if(sd.all_students[i].uid==owner){
                        curr=sd.all_students[i];
                        prof_or_stud=0;
                        }
                    }
                    if(prof_or_stud==0)
                    {
                        for(int i=0;i<curr.sb.size();i++)
                        {
                            if(curr.sb[i].bid==id)
                            {
                                curr.sb.erase(curr.sb.begin()+i);
                                break;

                            }

                        }

                    }
                    prof curr1;
                    for(int i=0;i<pd.all_prof.size()&&prof_or_stud==-1;i++)
                    {
                        if(pd.all_prof[i].uid==owner){
                        curr1=pd.all_prof[i];
                        prof_or_stud=1;
                        }
                    }
                    if(prof_or_stud==1)
                    {
                       for(int i=0;i<curr1.pb.size();i++)
                        {
                            if(curr1.pb[i].bid==id)
                            {
                                curr1.pb.erase(curr1.pb.begin()+i);
                                break;
                            }

                        } 
                    }
                }
                all_books.erase(all_books.begin()+i);
                return 1;
            }
        }
        return 0;
    }
    void display()
    {
        cout<<"\n";
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].available==1)
                        cout<<"Book ID : "<<all_books[i].bid<<"      Book Name : "<<all_books[i].title<<"      Book Author : "<<all_books[i].author<<"     Book owner id: Book Not issued yet"<<"\n";
            else
            cout<<"Book ID : "<<all_books[i].bid<<"      Book Name : "<<all_books[i].title<<"      Book Author : "<<all_books[i].author<<"     Book owner id: "<<all_books[i].owner<<"\n";
        }
    }
    void display_available()
    {
        cout<<"\n";
        int count=0;
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].available==1){
            cout<<"Book ID : "<<all_books[i].bid<<"      Book Name : "<<all_books[i].title<<"      Book Author : "<<all_books[i].author<<"     Book owner id: "<<all_books[i].owner<<"\n";
            count++;
            }
            }
            if(count==0)
            cout<<"\nWe are sorry !\nNo Book is available for now.\n\n";
    }
    int issue_book(int bookid,int userid)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==bookid)
            {
                if(all_books[i].available==0)
                return 1;
                else
                {
                    all_books[i].available=0;
                    all_books[i].owner=userid;
                    return 2;
                }
            }
        }
        return 3;
    }
    int is_book_available(int bookid)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==bookid)
            {
                if(all_books[i].available==0)
                return 1;
                else
                {
                    return 2;
                }
            }
        }
        return 3;

    }
    int return_book(int bookid,int userid)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==bookid)
            {
                if(all_books[i].available==1)
                return 1;
                else
                {
                    if(all_books[i].owner!=userid)
                    return 4;
                    all_books[i].available=1;
                    all_books[i].owner=-1;
                    return 2;
                }
            }
        }
        return 3;
    }
    book search_book(int id)   //made to work only when book with this id is present
    {
        for(int i=0;i<all_books.size();i++)
        if(all_books[i].bid==id)
        return all_books[i];
        return all_books[0];//control never reaches here
    }
};
book_database bd;

//-----------------------------------------------------------------------------------------------------------------

int first_call(){
    cout<<"\n\nAre you a student, professor or librarian? \nPress 1 if you are student.\nPress 2 if you are professor.\nPress 3 if you are librarian.\nPress 4 to exit.\n\n";
    int x;
    cin>>x;
    if(x==1||x==2||x==3||x==4)
    return x;
    else{
    cout<<"Please enter valid input\n";
    return first_call();
    }   
}
int login_call()
{
    cout<<"\n\nEnter 1 to login or 2 to register.\nEnter 3 to go back\n\n";
    int x;
    cin>>x;
    if(x==1||x==2||x==3)
    return x;
    else
    {
     cout<<"Please enter valid input\n";
     return login_call();   
    }
}
int lib_login_call()
{
    cout<<"\n\nEnter 1 to login.\nEnter 2 to go back\n\n";
    int x;
    cin>>x;
    if(x==1||x==2)
    return x;
    else
    {
     cout<<"Please enter valid input\n";
     return lib_login_call();   
    }
}
int function_call()
{
    cout<<"\n\nEnter 1 to view your profile\n";
    cout<<"Enter 2 to view all books\n";
    cout<<"Enter 3 to view available books\n";
    cout<<"Enter 4 issue a book\n";
    cout<<"Enter 5 to return book\n";
    cout<<"Enter 6 to view your issued books\n";
    cout<<"Enter 7 to show current fine\n";
    cout<<"Enter 8 to clear fine\n";
    cout<<"Enter 9 to check availablabilty of particular book.\n";
    cout<<"Enter 10 to logout\n\n\n";
    int x;
    cin>>x;
    if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8||x==9||x==10)
    return x;
    else
    {
        cout<<"Please enter valid input\n";
        return function_call();
    }
}
int lib_function_call()
{
    cout<<"\n\n";
    cout<<"Enter 1 to view your profile\n";
    cout<<"Enter 2 to view all books\n";
    cout<<"Enter 3 to view available books\n";
    cout<<"Enter 4 to list all users\n";
    cout<<"Enter 5 add a book\n";
    cout<<"Enter 6 to delete a book\n";
    cout<<"Enter 7 add a student\n";
    cout<<"Enter 8 to delete a student\n";
    cout<<"Enter 9 to add a prof\n";
    cout<<"Enter 10 to delete a prof\n";
    cout<<"Enter 11 to  issued books with users\n";
    // cout<<"Enter 12 to show current status of book\n";
    // cout<<"Enter 13 to show current status of user\n";
    cout<<"Enter 12 to logout\n\n\n";
    int x;
    cin>>x;
    // if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8||x==9||x==10||x==11||x==12||x==13||x==14)
    if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8||x==9||x==10||x==11||x==12)
    return x;
    else
    {
        cout<<"Please enter valid input\n";
        return lib_function_call();
    }
}

// book remove_book_from_user(int userid,int bookid)
// {
//     cout<<"call";
//     cout<<userid<<" "<<bookid;
//     cout<<"\n"<<sd.all_students.size()<<"\n";
//     for(int i=0;i<sd.all_students.size();i++)
//     {
//         cout<<"a";
//         if(sd.all_students[i].uid==userid)
//         {
//             cout<<"found\n";
//             for(int j=0;j<sd.all_students[i].sb.size();j++)
//             {
//                 cout<<sd.all_students[i].sb.size()<<" ";
//                 if(sd.all_students[i].sb[j].bid==bookid)
//                 {
//                     cout<<"\nbook found"<<sd.all_students[i].sb[j].title<<"   ";
//                     book b=sd.all_students[i].sb[j];
                    
//                     // auto v=&(sd.all_students[i].sb);
//                     // cout<<((v->begin()+j).title);
//                     // v->erase(v->begin()+j);
//                     sd.all_students[i].sb.erase(sd.all_students[i].sb.begin()+j);
//                     cout<<"Boko erase\n";
//                     return b;
//                 }
//             }
//         }
//     }
//     for(int i=0;i<pd.all_prof.size();i++)
//     {
//         if(pd.all_prof[i].uid==userid)
//         {
//             for(int j=0;j<pd.all_prof[i].pb.size();j++)
//             {
//                 if(pd.all_prof[i].pb[j].bid==bookid)
//                 {
//                     book b=pd.all_prof[i].pb[j];
//                     auto v=&(pd.all_prof[i].pb);
//                     v->erase(v->begin()+j);
//                     // pd.all_prof[i].pb.erase((pd.all_prof[i].pb).begin()+j);
//                     return b;
//                 }
//             }
//         }
//     }
//     // return bd.all_books[0];
// }
int main()
{
    
    //----------------------------------------------------------------------------------------------------------------
    book b1;
    b1.title="Thermodynamics";
    b1.author="Cengel_Boles";
    b1.available=0;
    b1.owner=0;

    book b2;
    b2.title="Organic Chemistry";
    b2.author="Clayden";
    b2.available=0;
    b2.owner=1;
    
    book b3;
    // b3.bid=2;
    b3.title="Verilog";
    b3.author="Palnitkar";
    b3.available=1;
    b3.owner=-1;
    
    book b4;
    // b4.bid=3;
    b4.title="Computer Architecture";
    b4.author="Patterson";
    b4.available=1;
    b4.owner=-1;

    bd.all_books.push_back(b1);
    bd.all_books.push_back(b2);
    bd.all_books.push_back(b3);
    bd.all_books.push_back(b4);

    student s1;
    s1.uid=0;
    s1.name="Pratham Jain";
    s1.password="pratham";
    s1.fine=0;
    s1.sb.push_back(b1);

    prof p1;
    p1.uid=1;
    p1.name="Indranil Saha";
    p1.password="cs253";
    p1.fine=0;
    p1.pb.push_back(b2);

    lib l1;
    l1.uid=2;
    l1.name="XYZ";
    l1.password="library";
    ld.all_lib.push_back(l1);

    sd.all_students.push_back(s1);
    pd.all_prof.push_back(p1);
    ld.all_lib.push_back(l1);
    //------------------------------------------------------------------------------------------------
    while(1)
    {
        int x=first_call();
        if(x==4)
        return 0;
        if(x==1)
        {
            cout<<"\nWelcome,Student\n\n";
            while(1)
            {
                int flag=1;
                int y=login_call();
                if(y==3)
                break;
                else if(y==1)
                {
                    student curr;
                        cout<<"\nEnter ID : ";
                        int id;
                        cin>>id;
                        int t=sd.is_student_present(id);
                        if(t==0)
                        {
                            cout<<"This user doesn't exist.\n";
                            flag=0;

                        }
                        else
                        {
                            curr=sd.search_student(id);
                            string x;
                            cout<<"Enter password\n";
                            //cin>>x;
                            getchar();
                            getline(cin,x);
                            if(curr.password!=x)
                            {
                                cout<<"Wrong password\n";
                                flag=0;
                            }
                            else
                            cout<<"\n\nWelcome , "<<curr.name<<"\n\n";
                        }
                    if(flag==0)
                    continue;
                    while(1)
                    {
                        int z=function_call();
                        if(z==10)
                        break;
                        else if(z==1)
                        {
                            curr.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==2)
                        {
                            bd.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==3)
                        {
                            bd.display_available();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==4)
                        {
                            if(curr.book_issued>=5)
                            cout<<"\nYou have reached maximum capacity of issuing books\n";
                            else{
                            cout<<"\nEnter bookid of book to be issued\n";
                            int z;
                            cin>>z;
                            int p=bd.issue_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                book b=bd.search_book(z);
                                curr.sb.push_back(b);
                                curr.book_issued++;
                                cout<<"\nBook issued\n";
                                cout<<"\nDetails of book issued : \n";
                                cout<<"Book Title : "<<b.title<<"\n";
                                cout<<"Book Author : "<<b.author<<"\n\n\n";
                            }
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==5)
                        {
                            cout<<"\nEnter bookid of book to be returned\n";
                            int z;
                            cin>>z;
                            int p=bd.return_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook is already unissued\n";
                            else if(p==4)
                            cout<<"\nYou are not the owner of book , you can't return it\n";
                            else{
                                book b;
                                for(int i=0;i<curr.sb.size();i++)
                                {
                                    if(curr.sb[i].bid==z)
                                    {
                                        b=curr.sb[i];
                                        curr.sb.erase(curr.sb.begin()+i);
                                        break;
                                    }
                                }
                                // book b=remove_book_from_user(curr.uid,z);
                                cout<<"Book Details : \n";
                                cout<<"Book ID : "<<b.bid<<"\n"; 
                                cout<<"Book title : "<<b.title<<"\n";
                                cout<<"Book author : "<<b.author<<"\n";
                                cout<<"\nBook Returned\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==6)
                        {
                            curr.display_issued_books();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                        else if(z==7)
                        {
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                        else if(z==8)
                        {
                            curr.fine=0;
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==9)
                        {
                            cout<<"\nEnter bookid : ";
                            int z;
                            cin>>z;
                            int p=bd.is_book_available(z);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                cout<<"\nBook available\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                    }
                }
                else if(y==2)
                {
                    student newst;
                    cout<<"\nYour user id is : "<<newst.uid<<"\n";
                    newst.fine=0;
                    cout<<"\nEnter your name : ";
                    string x;
                    //cin>>x;
                    getchar();
                    getline(cin,x);
                    newst.name=x;
                    cout<<"Enter your password : ";
                    // getchar();
                    getline(cin,x);
                    newst.password=x;
                    sd.add_student(newst);
                    // cout<<"\nSuccessfully Registered     \n"<<newst.name<<"    "<<newst.password;
                    cout<<"\nStudent with 'user id' : "<<newst.uid<<", Name : "<<newst.name<<" Successfully Registered\n";
                    continue;

                }
            }

        }
        else if(x==2)
        {
            cout<<"\nWelcome,Professor\n\n";
            while(1)
            {
                int flag=1;
                int y=login_call();
                if(y==3)
                break;
                else if(y==1)
                {
                    prof curr;
                        cout<<"\nEnter ID : ";
                        int id;
                        cin>>id;
                        int t=pd.is_prof_present(id);
                        if(t==0)
                        {
                            cout<<"\nThis user doesn't exist.\n";
                            flag=0;

                        }
                        else
                        {
                            curr=pd.search_prof(id);
                            string x;
                            cout<<"Enter password\n";
                            getchar();
                            getline(cin,x);
                            if(curr.password!=x)
                            {
                                cout<<"\nWrong password\n";
                                flag=0;
                            }
                            else
                            cout<<"\n\nWelcome , "<<curr.name<<"\n\n";
                        }
                    if(flag==0)
                    continue;
                    while(1)
                    {
                        int z=function_call();
                        if(z==10)
                        break;
                        else if(z==1)
                        {
                            curr.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==2)
                        {
                            bd.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==3)
                        {
                            bd.display_available();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==4)
                        {
                            cout<<"\nEnter bookid of book to be issued\n";
                            int z;
                            cin>>z;
                            int p=bd.issue_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                // curr.pb.push_back(bd.search_book(z));
                                // curr.book_issued++;
                                // cout<<"\nBook issued\n";
                                book b=bd.search_book(z);
                                curr.pb.push_back(b);
                                curr.book_issued++;
                                cout<<"\nBook issued\n";
                                cout<<"\nDetails of book issued : \n";
                                cout<<"Book Title : "<<b.title<<"\n";
                                cout<<"Book Author : "<<b.author<<"\n\n\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==5)
                        {
                            cout<<"\nEnter bookid of book to be returned\n";
                            int z;
                            cin>>z;
                            int p=bd.return_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook is already unissued\n";
                            else if(p==4)
                            cout<<"\nYou are not the owner of book , you can't return it\n";
                            else{
                                book b;
                                for(int i=0;i<curr.pb.size();i++)
                                {
                                    if(curr.pb[i].bid==z)
                                    {
                                        b=curr.pb[i];
                                        curr.pb.erase(curr.pb.begin()+i);
                                        break;
                                    }
                                }
                                // book b=remove_book_from_user(curr.uid,z);
                                cout<<"Book Details : \n";
                                cout<<"Book ID : "<<b.bid<<"\n"; 
                                cout<<"Book title : "<<b.title<<"\n";
                                cout<<"Book author : "<<b.author<<"\n";
                                cout<<"\nBook Returned\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==6)
                        {
                            curr.display_issued_books();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==7)
                        {

                        }
                        else if(z==8)
                        {
                            curr.fine=0;
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==9)
                        {
                            cout<<"\nEnter bookid : ";
                            int z;
                            cin>>z;
                            int p=bd.is_book_available(z);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                cout<<"\nBook available\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                    }
                }
                else if(y==2)
                {
                    prof newst;
                    cout<<"\nYour user id is : "<<newst.uid<<"\n";
                    newst.fine=0;
                    cout<<"\nEnter your name : ";
                    string x;
                    //cin>>x;
                    getchar();
                    getline(cin,x);
                    newst.name=x;
                    cout<<"Enter your password : ";
                    //cin>>x;
                    // getchar();
                    getline(cin,x);
                    newst.password=x;
                    pd.add_prof(newst);
                    cout<<"\nProfessor with 'user id' : "<<newst.uid<<", Name : "<<newst.name<<" Successfully Registered\n";
                    // cout<<"\nStudent with 'user id' : "<<newst.uid<<", Name : "<<newst.name<<" Successfully Registered\n";
                    continue;
                }
            }

        }
        else if(x==3)
        {
            cout<<"\nWelcome,Librarian\n\n";
            while(1)
            {
                int flag=1;
                int y=lib_login_call();
                if(y==2)
                break;
                else if(y==1)
                {
                    lib curr;
                        cout<<"\nEnter ID : ";
                        int id;
                        cin>>id;
                        int t=ld.is_lib_present(id);
                        if(t==0)
                        {
                            cout<<"\nThis user doesn't exist.\n";
                            flag=0;

                        }
                        else
                        {
                            curr=ld.search_lib(id);
                            string x;
                            cout<<"Enter password\n";
                            getchar();
                            getline(cin,x);
                            if(curr.password!=x)
                            {
                                cout<<"\nWrong password\n";
                                flag=0;
                            }
                        }
                    if(flag==0)
                    continue;
                    while(1)
                    {
                        int z=lib_function_call();
                        if(z==12)
                        break;
                        else if(z==1)
                        {
                            curr.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==2)
                        {
                            bd.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==3)
                        {
                            bd.display_available();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==4)
                        {
                            for(int i=0;i<sd.all_students.size();i++)
                            {
                                cout<<"User id : "<<sd.all_students[i].uid<<"     Name : "<<sd.all_students[i].name<<"      Role : Student\n";
                            }
                            for(int i=0;i<pd.all_prof.size();i++)
                            {
                                cout<<"User id : "<<pd.all_prof[i].uid<<"     Name : "<<pd.all_prof[i].name<<"      Role : Professor\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==5)
                        {
                            bd.add_book();
                            cout<<"\nPress Enter to go back\n";
                            //getchar();
                            getchar();
                        }
                        else if(z==6)
                        {
                            cout<<"\nEnter book id\n";
                            int id;
                            cin>>id;
                            int p=bd.delete_book(id);
                            if(p==1)
                            cout<<"\nBook successfully deleted\n";
                            else
                            cout<<"\nInvalid book id\n";
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==7)
                        {
                            student sn;
                            cout<<"\nUserId is "<<sn.uid<<"\n";
                            string x;
                            cout<<"\nName of Student : ";
                            getchar();
                            getline(cin,x);
                            sn.name=x;
                            cout<<"Password of Student : ";
                            getchar();
                            getline(cin,x);
                            sn.password=x;
                            sn.fine=0;
                            sd.add_student(sn);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            //getchar();
                        }
                        else if(z==8)
                        {
                            cout<<"\nUser id of student : ";
                            int id;
                            cin>>id;
                            sd.remove_student(id);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==9)
                        {
                            prof sn;
                            cout<<"\nUserId is "<<sn.uid<<"\n";
                            string x;
                            cout<<"\nName of Professor : ";
                            getchar();
                            getline(cin,x);
                            sn.name=x;
                            cout<<"Password of Professor : ";
                            getchar();
                            getline(cin,x);
                            sn.password=x;
                            sn.fine=0;
                            pd.add_prof(sn);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            //getchar();

                        }
                        else if(z==10)
                        {
                            cout<<"\nUser id of Professor : ";
                            int id;
                            cin>>id;
                            pd.remove_prof(id);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==11)
                        {
                            for(int i=0;i<bd.all_books.size();i++)
                            {
                                if(bd.all_books[i].available==0)
                                cout<<"Book id : "<<bd.all_books[i].bid<<"      Name of book : "<<bd.all_books[i].title<<"      owner id : "<<bd.all_books[i].owner<<"\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                    }
                }
            }

        }
    }


    return 0;
}