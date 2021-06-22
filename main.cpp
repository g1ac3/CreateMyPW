#include <bits/stdc++.h>
#include "CREATEPW_F.h"
int main(){
  const int MOD = 79;
  const int M = 8;
  std::vector<int> A(M); //キーワードを数値として記憶する配列
  Greeting(); //起動時の挨拶
  std::string NAME = Name_Check(); //このアプリを使う際の名前を確認(キーワードにも使用)
  do{
    int SUM = Input_Info(M,MOD,NAME,A);//キーワードを入力させ配列Aに数値として保存
    Create_PW(M,SUM,MOD,A); //配列Aを元にパスワード生成
  }while(!reCheck("a",true));
}
