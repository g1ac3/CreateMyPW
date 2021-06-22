#include <bits/stdc++.h>
#include "CREATEPW_F.h"
void Greeting(){
  std::string VERSION = "1.0"; //バージョン
  std::string CREATEDATE = "2021/06/22"; //プログラム作成日時
  std::cout<<"=========Ver_"<<VERSION<<"==========\n";
  std::cout<<"Author : 'g1ac3'\n";
  std::cout<<"This program was created : "<<CREATEDATE<<"\n";
  std::cout<<"Github : https://github.com/g1ac3\n\n";
  std::cout<<"G1ac3 will create your PW!!\n";
  std::cout<<"==========================\n\n";
}
bool reCheck(std::string l,bool a){
  char ta;
  if(a) std::cout<<"\nDo you want to remake PW?  Yes(1):No(0)  : ";
  else std::cout<<"your name is "<<l<<", right?  Yes(1):No(0)  : ";
  std::cin>>ta;
  std::cout<<"\n";
  int t = ta-'0';
  if(t==1) return false;
  if(t==0) return true;
  std::cout<<"error\n";
  exit(0);
}
std::string Name_Check(){
  std::ifstream fin;
  std::string line;
  fin.open("NAME.txt",std::ios::in);
  std::getline(fin,line);
  fin.close();
  if(line == "NAMENAME"||reCheck(line,false)){
    std::cout<<"Please enter your name : ";
    std::cin>>line;
    std::ofstream ofs("NAME.txt");
    ofs<<line;
    ofs.close();
  }
  std::cout<<"Hi, "<<line<<" !!\n";
  return line;
}
int Input_Info(int M,int MOD,std::string NAME,std::vector<int> &A){
  std::vector<std::string> EXPLAIN{"Service name","ID you use","Rkey1","Rkey2","Rkey3","Rkey4"};
  std::string tmp;
  int SUM = 0,sum = 0;
  int fixed_m = 2;
  time_t now = time(NULL);
  struct tm *p = localtime(&now);
  for(int j=0;j<(int)NAME.size();++j) sum += (NAME[j]-'0');
  sum %= MOD;
  A[0] = sum;
  SUM += sum;
  sum =(p->tm_mday+p->tm_hour+p->tm_min+p->tm_sec)%MOD;
  A[1] = sum;
  SUM += sum;
  for(int i=0;i<M-fixed_m;i++){
    std::cout<<EXPLAIN[i]<<" : ";
    std::cin>>tmp;
    sum = 0;
    for(int j=0;j<(int)tmp.size();++j) sum += (tmp[j]-'0');
    sum %= MOD;
    A[i+fixed_m] = sum;
    SUM += sum;
  }
  return SUM%MOD;
}
void Create_PW(int M,int SUM,int MOD,std::vector<int> A){
  const int pw_size = 16;
  char pw[pw_size];
  int tot = SUM+MOD;
  for(int i=0;i<M;i++)pw[i] = ((tot-A[i])%MOD+'0');
  for(int i=0;i<M/2;i++)pw[i+M] = ((A[i]+A[i+4])%MOD+'0');
  for(int i=0;i<M/2;i++)pw[i+M+M/2] = ((A[i]+A[i+3])%MOD+'0');
  std::cout<<"New pw here!!\n\n";
  for(char x:pw) std::cout<<x;
  std::cout<<"\n";
}
