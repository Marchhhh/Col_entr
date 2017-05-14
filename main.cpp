#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std; 
//-------------------����һ��ѧ����----------------------------------------��

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
//	int m,n;             //ѡ��α�ţ�
	char a1[10];             //ѡ��εȼ���
	char a2[10];
	int sumscore;
public:
	Student(){          // Ĭ�Ϲ��캯����
		age=0;
	  strcpy(name," ");
	  strcpy(schoolname," ");
	   strcpy(sex," ");                 //����֮�䲻��ֱ�Ӹ�ֵ�������ַ������ƺ���strcpyʵ�֣�
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
		int chinesescore1,int mathscore1,int englishscore1,char*a11,char*a22)//���캯����
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
	}                         //����������
//friend int enter(char filename1[256],Student*t,int num);
//	friend void setmarkline1(Student*t,int num);
//	operator const int*(){                  //����ת��������
//		Student *s;
//		return (int*)s;
//	}   
	friend void Average(int n,Student *s,int num);
    friend void sortsum(Student *ss,int p,int num);
	friend void setmarkline1(Student*t,int num);
	friend int enter(char filename1[256],Student*t,int num);
	Student  &operator=(const Student&d){                 //��ֵ��������
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
	bool operator>(const Student s)const{               //�����>���غ�����
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
void Average(int n,Student *s,int num){     //numΪѧ��������;��n����������һ�ſ�Ŀ��ƽ���ɼ���
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
		cout<<"�������!"<<endl;
		cout<<"ƽ��ֵ��:"<<float(sum/num)<<endl;
		char filename[256];
		cout<<"�����뱣��ƽ��ֵ��Ϣ���ļ����ƣ�"<<endl;
		cin>>filename;
		ofstream outfile(filename);
		while(!outfile){
			cout<<"���ܴ򿪴��ļ���"<<endl;
			cout<<"���ٴ������ļ�����";
			cin>>filename;
			outfile.clear();
			outfile.open(filename);
		}
		outfile<<float(sum/num);
		cout<<"��Ϣ�ѱ�����ָ���ļ���!"<<endl;
		outfile.close();
	}
void sortsum(Student *ss,int p,int num){                 //�����ܳɼ�������n������ʲô��ʽ����
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
     Student  temp;                                         //ð������
	 for(int j=0;j<num;j++)
		 for(int k=0;k<num-1-j;k++)
			 if(ss[k].getsumscore()>ss[k+1].getsumscore()){
				 temp=ss[k];                                                     
				 ss[k]=ss[k+1];
				 ss[k+1]=temp;
			 }
			 int lowmark,highmark;                          //����5��һ�������ν�������ͳ�ƣ�
			 lowmark=ss[0].getsumscore();
			 highmark=ss[num-1].getsumscore();
			 char filename[256];
			 cout<<"�����뱣�����������ͳ����Ϣ���ļ����ƣ�"<<endl;
		cin>>filename;                                        //����������ͳ����Ϣ�����ļ�;
		ofstream outfile(filename);
		while(!outfile){
			cout<<"���ܴ򿪴��ļ�!"<<endl;
			cout<<"���ٴ������ļ�����";
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
			 outfile<<"������ΧΪ"<<n-5<<"~"<<n<<"����:"<<size<<" ��"<<endl;
			 cout<<"������ΧΪ"<<n-5<<"~"<<n<<"����:"<<size<<" ��"<<endl;
			 }
}
			   	char filename1[256];
		cout<<"�����뱣��������Ϣ���ļ����ƣ�"<<endl;
		cin>>filename1;                            ////��������ͳ����Ϣ�����ļ�;
		ofstream outfile1(filename1);
		while(!outfile1){
			cout<<"���ܴ򿪴��ļ���"<<endl;
			cout<<"���ٴ������ļ�����";
			cin>>filename1;
			outfile1.clear();
			outfile1.open(filename1);
		}
	outfile1<<"����"<<" "<<"�Ա�"<<" "<<"����"<<" "<<"׼��֤��"<<" "<<"��ҵѧУ"<<" "<<     //�ļ�����-----��������
		"����"<<" "<<"��ѧ"<<" "<<"Ӣ��"<<" "<<"ѡ��һ"<<" "<<"ѡ���"<<" "<<"�ܳɼ�"<<endl;
  for(int b=0;b<num;b++){
		outfile1<<ss[b].getname()<<" "<<ss[b].getsex()<<" "<<ss[b].getage()<<" "
			<<ss[b].getcnumber()<<" "<<ss[b].getschoolname()<<" "<<
			ss[b].getchinesescore()<<" "<<ss[b].getmathscore()<<" "
			<<ss[b].getenglishscore()<<" "<<ss[b].geta1()<<" "
			<<ss[b].geta2()<<" "<<ss[b].getsumscore()<<endl;
	}
  cout<<"���ݱ���ɹ�!"<<endl;
  outfile1.close();
	} 
/*void outfile1(char*filename2,int n,Student*t,int oo){     //ѧ����Ϣ¼���ı��ļ����棻
	ofstream outfile(filename2);
	if(!outfile){
	cout<<"���ܴ򿪴��ļ���"<<filename2<<endl;
	return;
	}
	outfile<<"����"<<'\t'<<"�Ա�"<<'\t'<<"����"<<'\t'<<"׼��֤��"<<'\t'<<"��ҵѧУ"<<'\t'<<     //�ļ�����-----��������
		"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"ѡ��һ"<<'\t'<<"ѡ���"<<endl;

	for(int i=oo;i<n;i++){
		outfile<<t[i].getname()<<" "<<t[i].getsex()<<" "
			<<t[i].getage()<<" "<<t[i].getcnumber()<<" "<<t[i].getschoolname()<<" "<<
			t[i].getchinesescore()<<" "<<t[i].getmathscore()
			<<" "<<t[i].getenglishscore()<<" "
			<<t[i].getm<<t[i].geta1()<<t[i].getn<<" "<<t[i].geta2()<<endl;
	}
	cout<<"****��Ϣ�������!***"<<endl;
} */
/*void setmarkline(Student*sss,int num){              //�������������Լ�ѡ��εȼ�������¼ȡ�����ߣ�
		int wenperson,liperson;                       //���ݽ��ո߿��ص����������鲢ͳ��������
		Student *li=sss,*wen=sss;                     //�����г�ʼ��������棻
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
		cout<<"��ƿ������У�"<<liperson<<'\t';
		cout<<"�Ŀƿ������У�"<<wenperson<<endl;

		Student temp;
           for(int a=0;a<liperson-1;a++)       // ��������ܳɼ��ֱ�����
			   for(int j=0;j<liperson-1-a;j++)
				   if(li[j]>li[j+1]){                       //����ıȽϵ�������������غ���;
					   temp=li[j];
li[j]=li[j+1];
li[j+1]=temp;
				   }
				   for(int k=0;k<wenperson-1;k++)       // ��������ܳɼ��ֱ�����
			   for(int l=0;l<wenperson-1-k;l++)
				   if(wen[l]>wen[l+1]){
					   temp=wen[l];
wen[l]=wen[l+1];
wen[l+1]=temp;
				   }
     	int licount,wencount;
		cout<<"���¼ȡ����Ϊ:";
		cin>>licount;
		cout<<endl;
		char filename1[256],filename2[256];
		cout<<"�����뱣��¼ȡ��ƿ�����Ϣ���ļ����ƣ�";
	    cin>>filename1;               //¼ȡ��ƿ������浽�ļ���;
		int o=liperson-licount+1;
		outfile1(filename1,liperson,li,o);
        cout<<"�Ŀ�¼ȡ����Ϊ:";
		cin>>wencount;
		cout<<endl;
		cout<<"�����뱣��¼ȡ��ƿ�����Ϣ���ļ����ƣ�";          //¼ȡ�Ŀƿ������浽�ļ���;
	    cin>>filename2;
		int r=wenperson-wencount+1;
        outfile1(filename2,wenperson,wen,r);
	} */    
	void setmarkline1(Student*t,int num){                //���ݳɼ��Լ��ȼ�����¼ȡ�����ߣ� 
		char filename[256];
		cout<<"�����뱣���ܷ�������Ϣ���ļ����ƣ�";
		cin>>filename;
		ifstream infile(filename);
		if(!infile){
			cout<<"���ܴ򿪴��ļ���"<<filename;
			return;
		} 
		int markline=0;
		int count;
		cout<<"��������¼ȡ������";
		cin>>count;
		cout<<endl;
		char a[20],b[10],c[20],d[20],e[10],f[10];
		int m,n,o,p;
			//,q,r;
		int i=0;
	    char filename2[256];
	    cout<<"�����뱣��¼ȡ������Ϣ���ļ����ƣ�";
	    cin>>filename2;
		ofstream outfile(filename2);
		 int k=0;			    
		while(i<num-1){
		infile.getline(a,20,' ');                    //�ļ��ָ����ǿո�
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
	    Student ee;                        //������ͬ�Ŀ�������¼ȡ�ȼ��ߵĿ�����
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
	cout<<"����Ϊ¼ȡ������Ϣ(������ͬʱ����¼ȡ�ȼ��ϸߵĿ�����"<<endl;
    cout<<"��Ϣ������ϣ�"<<endl;
	cout<<"¼ȡ������Ϊ��"<<markline<<endl;
	}                                                                        
int enter(char filename1[256],Student*t,int num){                                       //��ȡ�ļ���¼��ѧ����Ϣ��
ifstream infile(filename1);
	if(!infile){
		cout<<"���ܴ򿪴��ļ�"<<filename1<<endl;
		cout<<"�ٴ������ļ�����";                                //�����ļ�������ʱ�����������ļ�����
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
		infile.getline(a,20,',');                                  //  �ļ��ָ����Ƕ��ţ�
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
		cout<<"������Ϣ¼�����!"<<endl;
		cout<<"����������Ϊ��"<<size<<endl;
		return size;
	}
//};
void choose(Student*t,Student r,int num){
	cout<<"��ѡ���ܣ�"<<endl;
	cout<<"   1.����ĳ�ſ�Ŀƽ���ɼ���"<<endl;
	cout<<"   2.����"<<endl;
	cout<<"   3.���з���������ͳ�ƣ�"<<endl;
    cout<<"   4.�����߿�¼ȡ�����ߣ�"<<endl;
    cout<<"   5.����¼ȡ��"<<endl;
	cout<<endl;
	cout<<"��������Ҫʵ�ֵĹ�����ţ�";
	int p;
	cin>>p;
	cout<<endl;
	switch(p){                               //�������ʵ�ֹ���ѡ������
case 1:
	int k;
	cout<<"��������Ҫ����ƽ��ֵ�Ŀ�Ŀ�Ĵ��루ֻ�ܼ�������Ӣ��ƽ��ֵ������������μ���1����";
    cin>>k;
//	r.
		Average(k,t,num);
	cout<<endl;
	choose(t,r,num);                       //ĩβ�ú�������ʵ�ֹ��ܵ�����ʹ�ã��ݹ���ã�
	break;
case 2:
	cout<<"1.�����ĳɼ�����"<<endl;
	cout<<"2.����ѧ�ɼ�����"<<endl;
	cout<<"3.��Ӣ��ɼ�����"<<endl;
	cout<<"4.������Ӣ�����ܳɼ����򣨷���������ͳ�ư����������棩��"<<endl;
	cout<<"���û�������Ҫʵ�ֵĹ�����ţ�";
	int q;
	cin>>q;
//	r.
		sortsum(t,q,num);
	cout<<endl;
	choose(t,r,num);
	break;
case 3:
    cout<<"���������Ѿ�ʵ�ַ���������ͳ�Ʋ�����!"<<endl;
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
	cout<<"ллʹ��!"<<endl;
	break;
default:
	cout<<"Input P error!"<<endl;
		}
	}

//-----------------------------------------------������--------------------------------------------------------//
		int main(){
			int num=0;
			char filename22[256];
			system("color 3B");
			cout<<"������������ϵͳ�Ŀ����ļ����ƣ�";
			cin>>filename22;
			ifstream infile(filename22);
	while(!infile){
		cout<<"���ܴ򿪴��ļ�"<<filename22<<endl;
		cout<<"�ٴ������ļ�����";                                //�����ļ�������ʱ�����������ļ�����
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
		Student r;          //����һ��Student��������ڵ��ú�����
	cout<<"              Welcome To The System Of College Entrance!"<<endl;
	cout<<endl;
	          cout<<"��Ŀ�����1."<<endl ;                                // ��ʾ�γ̴����
			  cout<<"         1----------����"<<endl;
		      cout<<"         2----------��ѧ"<<endl;
			  cout<<"         3----------Ӣ��"<<endl;
			  cout<<"         4----------����"<<endl;
			  cout<<"         5----------��ѧ"<<endl;
			  cout<<"         6----------��ʷ"<<endl;
			  cout<<"         7----------����"<<endl;
			  cout<<"         8----------����"<<endl;
			  cout<<"         9----------����"<<endl;
    cout<<endl;
	char filename1[256];
	cout<<"��ȷ����������Ҫ�Ŀ�����Ϣ�ļ����ƣ�";
	cin>>filename1;
    // r.
    enter(filename1,t,num);
	cout<<endl;
    choose(t,r,num);
	 cout<<"----------------------------------------------------------------"<<endl;
      delete []t;
	  return 0;
		}             		               


