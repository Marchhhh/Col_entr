#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std; 
//-------------------定义一个学生类----------------------------------------；

class Student{           
private:
	char name[20];
	char schoolname[20];
	char sex[10];
	char cnumber[20];
	int age;
	int chinesescore;
	int mathscore;
	int englishscore;
//	int m,n;             //选测课编号；
	char a1[10];             //选测课等级；
	char a2[10];
	int sumscore;
public:
	Student(){          // 默认构造函数；
		age=0;
	  strcpy(name," ");
	  strcpy(schoolname," ");
	   strcpy(sex," ");                 //数组之间不能直接赋值，可用字符串复制函数strcpy实现；
	   strcpy(cnumber," ");
	   chinesescore=0;
	   mathscore=0;
	   englishscore=0;
	   sumscore=mathscore+chinesescore+englishscore;
//	   m=0;
//	   n=0;
	   strcpy(a1," ");
	   strcpy(a2," ");
	}
	Student(char*name1,char*sex1,int age1,char*cnumber1,char* sname,
		int chinesescore1,int mathscore1,int englishscore1,char*a11,char*a22)//构造函数；
{
		age=age1;
		strcpy(name,name1);
		strcpy(schoolname,sname);
		strcpy(sex,sex1);
		strcpy(cnumber,cnumber1);
		chinesescore=chinesescore1;
		mathscore=mathscore1;
		englishscore=englishscore1;
		sumscore=chinesescore1+mathscore1+englishscore1;
//		m=m1;
//		n=n1;
		strcpy(a1,a11);
		strcpy(a2,a22);
	}
	int getage(){return age;}
	int getchinesescore(){return chinesescore;}
	int getmathscore(){return mathscore;}
	int getenglishscore(){return englishscore;}
	int getsumscore(){return (chinesescore+mathscore+englishscore);}
//	int getm(){return m;}
//	int getn(){return n;}
	char*getname(){return name;}
	char*getschoolname(){return schoolname;}  
	char*getsex(){return sex;}
	char*geta1(){return a1;}
	char*geta2(){return a2;}
	char *getcnumber(){return cnumber;}
	void setsumscore(){
		sumscore=chinesescore+englishscore+mathscore;
	}
	void setage(int a){
		age=a;
	}
	void setchinesescore(int b){
		chinesescore=b;}
	void setmathscore(int c){
		mathscore=c;
	}
	void setenglishscore(int d){
		englishscore=d;
	}
	void setsumscore(int a){
		sumscore=a;
	}

//	void setm(int m){
//		this->m=m;
//	}
//	void setn(int n){
//		this->n=n;
//	}
	void setname(char *n){
		strcpy(name,n);
	}
	void setsex(char *s){
		strcpy(sex,s);
	}
	void setschoolname(char *n){
		strcpy(schoolname,n);
	}
	void seta1(char *a){
		strcpy(a1,a);
	}
	void seta2(char *a){
		strcpy(a2,a);
	}
	void setcnumber(char *n){
		strcpy(cnumber,n);
	}
	~Student(){
     cout<<'\t';
	}                         //析构函数；
//friend int enter(char filename1[256],Student*t,int num);
//	friend void setmarkline1(Student*t,int num);
//	operator const int*(){                  //类型转换函数；
//		Student *s;
//		return (int*)s;
//	}   
	friend void Average(int n,Student *s,int num);
    friend void sortsum(Student *ss,int p,int num);
	friend void setmarkline1(Student*t,int num);
	friend int enter(char filename1[256],Student*t,int num);
	Student  &operator=(const Student&d){                 //赋值操作函数
		strcpy(name,d.name);
		strcpy(sex,d.sex);
		age=d.age;
		strcpy(cnumber,d.cnumber);
		strcpy(schoolname,d.schoolname);
		mathscore=d.mathscore;
		chinesescore=d.chinesescore;
		englishscore=d.englishscore;
		sumscore=d.sumscore; 
		strcpy(a1,d.a1);
		strcpy(a2,d.a2);
		return *this;
	}
	friend ostream&operator<<(ostream &os,Student &t){
		os<<t.name<<t.sex<<t.age<<t.cnumber<<t.schoolname<<t.chinesescore<<t.mathscore<<t.englishscore<<t.a1<<t.a2<<endl;
		return os;
	}
	bool operator>(const Student s)const{               //运算符>重载函数；
		Student ss;
		int sssum,ssum;
		sssum=ss.chinesescore+ss.mathscore+ss.englishscore;
           ssum=s.chinesescore+s.mathscore+s.englishscore;
		   if(sssum>ssum)
			   return true;
			   else
			   return false;
	}
};
void Average(int n,Student *s,int num){     //num为学生总数量;由n决定计算哪一门科目的平均成绩；
		float sum=0.0;
		if(n==1){
			for(int i=0;i<num;i++){
         sum+=s[i].getchinesescore();
			}
		}
		if(n==2){
			for(int i=0;i<num;i++){
				sum+=s[i].getmathscore();
         	}
		}
	    if(n==3){
			for(int i=0;i<num;i++){
				sum+=s[i].getenglishscore();
			}
		
		}
		cout<<"计算完毕!"<<endl;
		cout<<"平均值是:"<<float(sum/num)<<endl;
		char filename[256];
		cout<<"请输入保存平均值信息的文件名称："<<endl;
		cin>>filename;
		ofstream outfile(filename);
		while(!outfile){
			cout<<"不能打开此文件！"<<endl;
			cout<<"请再次输入文件名：";
			cin>>filename;
			outfile.clear();
			outfile.open(filename);
		}
		outfile<<float(sum/num);
		cout<<"信息已保存在指定文件中!"<<endl;
		outfile.close();
	}
void sortsum(Student *ss,int p,int num){                 //计算总成绩并排序；n决定按什么方式排序；
		if(p==1){
			Student temp;
			for(int j=0;j<num;j++)
		 for(int k=0;k<num-1-j;k++)
			 if(ss[k].getchinesescore()>ss[k+1].getchinesescore()){
				 temp=ss[k];                                                     
				 ss[k]=ss[k+1];
				 ss[k+1]=temp;
			 }
	}
		if(p==2){
		Student temp;
      for(int j=0;j<num;j++)
		 for(int k=0;k<num-1-j;k++)
			 if(ss[k].getmathscore()>ss[k+1].getmathscore()){
				 temp=ss[k];                                                     
				 ss[k]=ss[k+1];
				 ss[k+1]=temp;
			 }
		}
		if(p==3){
		Student temp;
		 for(int j=0;j<num;j++)
		 for(int k=0;k<num-1-j;k++)
			 if(ss[k].getenglishscore()>ss[k+1].getenglishscore()){
				 temp=ss[k];                                                     
				 ss[k]=ss[k+1];
				 ss[k+1]=temp;
			 }
		}
		if(p==4){
      for(int i=0;i<num;i++){
    	ss[i].setsumscore();
}
     Student  temp;                                         //冒泡排序；
	 for(int j=0;j<num;j++)
		 for(int k=0;k<num-1-j;k++)
			 if(ss[k].getsumscore()>ss[k+1].getsumscore()){
				 temp=ss[k];                                                     
				 ss[k]=ss[k+1];
				 ss[k+1]=temp;
			 }
			 int lowmark,highmark;                          //按照5分一个分数段进行人数统计；
			 lowmark=ss[0].getsumscore();
			 highmark=ss[num-1].getsumscore();
			 char filename[256];
			 cout<<"请输入保存分数段人数统计信息的文件名称："<<endl;
		cin>>filename;                                        //分数段人数统计信息存入文件;
		ofstream outfile(filename);
		while(!outfile){
			cout<<"不能打开此文件!"<<endl;
			cout<<"请再次输入文件名：";
			cin>>filename;
			outfile.clear();
			outfile.open(filename);
		}
		int m=0;
			 for(int n=lowmark+5;n<highmark+5;n+=5){
				 int size=0;
			 for(;ss[m].getsumscore()<=n;m++){
				 size++;
			 }
			 outfile<<"分数范围为"<<n-5<<"~"<<n<<"的有:"<<size<<" 人"<<endl;
			 cout<<"分数范围为"<<n-5<<"~"<<n<<"的有:"<<size<<" 人"<<endl;
			 }
}
			   	char filename1[256];
		cout<<"请输入保存排序信息的文件名称："<<endl;
		cin>>filename1;                            ////排序及人数统计信息存入文件;
		ofstream outfile1(filename1);
		while(!outfile1){
			cout<<"不能打开此文件！"<<endl;
			cout<<"请再次输入文件名：";
			cin>>filename1;
			outfile1.clear();
			outfile1.open(filename1);
		}
	outfile1<<"姓名"<<" "<<"性别"<<" "<<"年龄"<<" "<<"准考证号"<<" "<<"毕业学校"<<" "<<     //文件储存-----标题栏；
		"语文"<<" "<<"数学"<<" "<<"英语"<<" "<<"选测一"<<" "<<"选测二"<<" "<<"总成绩"<<endl;
  for(int b=0;b<num;b++){
		outfile1<<ss[b].getname()<<" "<<ss[b].getsex()<<" "<<ss[b].getage()<<" "
			<<ss[b].getcnumber()<<" "<<ss[b].getschoolname()<<" "<<
			ss[b].getchinesescore()<<" "<<ss[b].getmathscore()<<" "
			<<ss[b].getenglishscore()<<" "<<ss[b].geta1()<<" "
			<<ss[b].geta2()<<" "<<ss[b].getsumscore()<<endl;
	}
  cout<<"数据保存成功!"<<endl;
  outfile1.close();
	} 
/*void outfile1(char*filename2,int n,Student*t,int oo){     //学生信息录入文本文件保存；
	ofstream outfile(filename2);
	if(!outfile){
	cout<<"不能打开此文件："<<filename2<<endl;
	return;
	}
	outfile<<"姓名"<<'\t'<<"性别"<<'\t'<<"年龄"<<'\t'<<"准考证号"<<'\t'<<"毕业学校"<<'\t'<<     //文件储存-----标题栏；
		"语文"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"选测一"<<'\t'<<"选测二"<<endl;

	for(int i=oo;i<n;i++){
		outfile<<t[i].getname()<<" "<<t[i].getsex()<<" "
			<<t[i].getage()<<" "<<t[i].getcnumber()<<" "<<t[i].getschoolname()<<" "<<
			t[i].getchinesescore()<<" "<<t[i].getmathscore()
			<<" "<<t[i].getenglishscore()<<" "
			<<t[i].getm<<t[i].geta1()<<t[i].getn<<" "<<t[i].geta2()<<endl;
	}
	cout<<"****信息保存完毕!***"<<endl;
} */
/*void setmarkline(Student*sss,int num){              //根据招生人数以及选测课等级来划定录取分数线；
		int wenperson,liperson;                       //根据江苏高考特点进行文理分组并统计人数；
		Student *li=sss,*wen=sss;                     //不进行初始化会给警告；
		wenperson=0;
		liperson=0;
		for(int i=0;i<num;i++){
			if(sss[i].getm()==4||sss[i].getn()==4){
				li[liperson]=sss[i];                          
				liperson++;
			}
			if(sss[i].getm()==6||sss[i].getn()==6){
				wen[wenperson]=sss[i];
				wenperson++;
			}
		}
		cout<<"理科考生共有："<<liperson<<'\t';
		cout<<"文科考生共有："<<wenperson<<endl;

		Student temp;
           for(int a=0;a<liperson-1;a++)       // 文理科生总成绩分别排序；
			   for(int j=0;j<liperson-1-a;j++)
				   if(li[j]>li[j+1]){                       //对象的比较调用了运算符重载函数;
					   temp=li[j];
li[j]=li[j+1];
li[j+1]=temp;
				   }
				   for(int k=0;k<wenperson-1;k++)       // 文理科生总成绩分别排序；
			   for(int l=0;l<wenperson-1-k;l++)
				   if(wen[l]>wen[l+1]){
					   temp=wen[l];
wen[l]=wen[l+1];
wen[l+1]=temp;
				   }
     	int licount,wencount;
		cout<<"理科录取人数为:";
		cin>>licount;
		cout<<endl;
		char filename1[256],filename2[256];
		cout<<"请输入保存录取理科考生信息的文件名称：";
	    cin>>filename1;               //录取理科考生保存到文件中;
		int o=liperson-licount+1;
		outfile1(filename1,liperson,li,o);
        cout<<"文科录取人数为:";
		cin>>wencount;
		cout<<endl;
		cout<<"请输入保存录取理科考生信息的文件名称：";          //录取文科考生保存到文件中;
	    cin>>filename2;
		int r=wenperson-wencount+1;
        outfile1(filename2,wenperson,wen,r);
	} */    
	void setmarkline1(Student*t,int num){                //根据成绩以及等级划定录取分数线； 
		char filename[256];
		cout<<"请输入保存总分排序信息的文件名称：";
		cin>>filename;
		ifstream infile(filename);
		if(!infile){
			cout<<"不能打开此文件！"<<filename;
			return;
		} 
		int markline=0;
		int count;
		cout<<"请输入需录取人数：";
		cin>>count;
		cout<<endl;
		char a[20],b[10],c[20],d[20],e[10],f[10];
		int m,n,o,p;
			//,q,r;
		int i=0;
	    char filename2[256];
	    cout<<"请输入保存录取考生信息的文件名称：";
	    cin>>filename2;
		ofstream outfile(filename2);
		 int k=0;			    
		while(i<num-1){
		infile.getline(a,20,' ');                    //文件分隔符是空格；
		infile.getline(b,10,' ');
		infile>>m;
		infile.getline(c,20,' ');
		infile>>c;
		infile.getline(d,20,' ');
		infile>>n;
		infile>>o;
		infile>>p;
		infile.getline(e,10,' ');
		infile.getline(f,10,'\n');
		t[i].setname(a);
        t[i].setsex(b);
        t[i].setage(m);
        t[i].setcnumber(c);
        t[i].setschoolname(d);
        t[i].setchinesescore(n);
        t[i].setmathscore(o);
        t[i].setenglishscore(p);
        //t[i].setm(q);
        t[i].seta1(e);
       //t[i].setn(r);
         t[i].seta2(f);
         t[i].setsumscore();
         i++;
		 
		 if(i>num-count-1){
		 	 if (k==0) {
		 	 	markline=t[i].chinesescore+t[i].mathscore+t[i].englishscore;
		 	 	 k+=1;
		 	 } 
			 if(i==num-count){
	    Student ee;                        //分数相同的考生优先录取等级高的考生；
		int mm1=(int)t[num-count].a1;
		int mm2=(int)t[num-count].a2;
		int nn1=(int)t[num-count-1].a1;
		int nn2=(int)t[num-count-1].a2;
		int mm3=mm1+mm2;
		int nn3=nn1+nn2;
		if((t[num-count].sumscore==t[num-count-1].sumscore)&&mm3>nn3){
          ee=t[num-count];
		t[num-count]=t[num-count-1];   
		t[num-count-1]=ee;
		}
			 }
        cout<<t[i].name<<" "<<t[i].sex<<" "<<t[i].age<<""<<t[i].cnumber<<" "<<t[i].schoolname
         <<" "<<t[i].chinesescore<<" "<<      
		 t[i].mathscore<<" "<<t[i].englishscore<<" "<<t[i].a1<<" "<<t[i].a2<<" "<<t[i].sumscore<<endl;
		outfile<<t[i].name<<" "<<t[i].sex<<" "<<t[i].age<<""<<t[i].cnumber<<" "<<t[i].schoolname
         <<" "<<t[i].chinesescore<<" "<<      
		 t[i].mathscore<<" "<<t[i].englishscore<<" "<<t[i].a1<<" "<<t[i].a2<<" "<<t[i].sumscore<<endl;	 
         }          
	}
	cout<<endl;
	cout<<"以上为录取考生信息(分数相同时优先录取等级较高的考生）"<<endl;
    cout<<"信息保存完毕！"<<endl;
	cout<<"录取分数线为："<<markline<<endl;
	}                                                                        
int enter(char filename1[256],Student*t,int num){                                       //读取文件，录入学生信息；
ifstream infile(filename1);
	if(!infile){
		cout<<"不能打开此文件"<<filename1<<endl;
		cout<<"再次输入文件名：";                                //输入文件名出错时，重新输入文件名；
		cin>>filename1;
		infile.clear();
		infile.open(filename1);
	}
		int size=0;
		int i=0;
		char a[20],b[10],c[20],d[20],e[10],f[10],g;
		int m,n,o,p;
		//q,r;
		while(i<num){
		infile.getline(a,20,',');                                  //  文件分隔符是逗号；
		infile.getline(b,10,',');
		infile>>m;
		infile>>g;
		infile.getline(c,20,',');
		infile.getline(d,20,',');
		infile>>n;
		infile>>g;
		infile>>o;
		infile>>g;
		infile>>p;
		infile>>g;
		infile.getline(e,10,',');
		infile.getline(f,10,'\n');
		t[i].setname(a);
        t[i].setsex(b);
        t[i].setage(m);
         t[i].setcnumber(c);
t[i].setschoolname(d);
t[i].setchinesescore(n);
t[i].setmathscore(o);
t[i].setenglishscore(p);
//t[i].setm(q);
t[i].seta1(e);
//t[i].setn(r);
t[i].seta2(f);
t[i].setsumscore();
		 i++;
		 size++; 
          }
		cout<<endl;
		cout<<"考生信息录入完毕!"<<endl;
		cout<<"考生总人数为："<<size<<endl;
		return size;
	}
//};
void choose(Student*t,Student r,int num){
	cout<<"请选择功能："<<endl;
	cout<<"   1.计算某门科目平均成绩；"<<endl;
	cout<<"   2.排序；"<<endl;
	cout<<"   3.进行分数段人数统计；"<<endl;
    cout<<"   4.划定高考录取分数线；"<<endl;
    cout<<"   5.结束录取；"<<endl;
	cout<<endl;
	cout<<"请输入需要实现的功能序号：";
	int p;
	cin>>p;
	cout<<endl;
	switch(p){                               //开关语句实现功能选择函数；
case 1:
	int k;
	cout<<"请输入所要计算平均值的科目的代码（只能计算语数英的平均值，具体代码表请参见表1）：";
    cin>>k;
//	r.
		Average(k,t,num);
	cout<<endl;
	choose(t,r,num);                       //末尾用函数调用实现功能的连续使用；递归调用；
	break;
case 2:
	cout<<"1.按语文成绩排序；"<<endl;
	cout<<"2.按数学成绩排序；"<<endl;
	cout<<"3.按英语成绩排序；"<<endl;
	cout<<"4.按语数英三门总成绩排序（分数段人数统计包含在这里面）；"<<endl;
	cout<<"请用户输入想要实现的功能序号：";
	int q;
	cin>>q;
//	r.
		sortsum(t,q,num);
	cout<<endl;
	choose(t,r,num);
	break;
case 3:
    cout<<"在排序中已经实现分数段人数统计并保存!"<<endl;
    cout<<endl;
	choose(t,r,num);
	break;
case 4:
//	r.
		setmarkline1(t,num);
	cout<<endl;
	choose(t,r,num);
	break;
case 5:
	cout<<"谢谢使用!"<<endl;
	break;
default:
	cout<<"Input P error!"<<endl;
		}
	}

//-----------------------------------------------主函数--------------------------------------------------------//
		int main(){
			int num=0;
			char filename22[256];
			system("color 3B");
			cout<<"请输入启动此系统的考生文件名称：";
			cin>>filename22;
			ifstream infile(filename22);
	while(!infile){
		cout<<"不能打开此文件"<<filename22<<endl;
		cout<<"再次输入文件名：";                                //输入文件名出错时，重新输入文件名；
		cin>>filename22;
		infile.clear();
		infile.open(filename22);
	}
			char buff[300];
		while(infile.getline(buff,300)){                 
			num++;
		}
		num=(num+1)/2;
		infile.close();
		Student*t=new Student[num];
		Student r;          //定义一个Student类变量便于调用函数；
	cout<<"              Welcome To The System Of College Entrance!"<<endl;
	cout<<endl;
	          cout<<"课目代码表1."<<endl ;                                // 显示课程代码表；
			  cout<<"         1----------语文"<<endl;
		      cout<<"         2----------数学"<<endl;
			  cout<<"         3----------英语"<<endl;
			  cout<<"         4----------物理"<<endl;
			  cout<<"         5----------化学"<<endl;
			  cout<<"         6----------历史"<<endl;
			  cout<<"         7----------地理"<<endl;
			  cout<<"         8----------政治"<<endl;
			  cout<<"         9----------生物"<<endl;
    cout<<endl;
	char filename1[256];
	cout<<"请确认输入所需要的考生信息文件名称：";
	cin>>filename1;
    // r.
    enter(filename1,t,num);
	cout<<endl;
    choose(t,r,num);
	 cout<<"----------------------------------------------------------------"<<endl;
      delete []t;
	  return 0;
		}             		               


