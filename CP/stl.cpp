#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
   map<int,string> map1;
   map1.insert(pair<int,string>(1,"Rahul"));
   map1.insert(pair<int,string>(2,"Ranjan"));
   map1.insert(pair<int,string>(3,"Yadav"));
   map<int,string>::iterator itr;
   for(itr=map1.begin();itr!=map1.end();itr++)
   	cout<<itr->first<<" "<<itr->second<<endl;
   return 0;
}*/
/*
int main()
{
  string s1,s2;
  cin>>s1;
  cin>>s2;
  //cout<<s1<<endl;
  //cout<<s1[0]<<endl;
  //cout<<strcmp(s1.c_str(),s2.c_str())<<endl;
  if(s1<s2) cout<<"S1 is less than s2."<<endl;
  else if(s1>s2)cout<<"S2 is less than s1."<<endl;
  if(s1==s2) cout<<"s1 and s2 are the same."<<endl;
  string s3=s1+" "+s2;
  cout<<s3<<endl;
  s3.append(" yadav");
  cout<<s3<<endl;
  //cout<<*s3.begin()<<endl;
  s3.clear();
  //cout<<s3<<endl;
  s3="yadav "+s1+" "+s2;
  cout<<s3<<endl;
  s3.push_back(' ');
  s3.push_back('a');
  cout<<s3<<endl;
  string s4;
  s4.assign(s3);
  cout<<s4<<endl;
  s4.assign(s3,0,5);
  cout<<s4<<endl;
  s4.assign(10,'$');
  cout<<s4<<endl;
  s4.assign(s3.begin(),s3.begin()+7);
  cout<<s4<<endl;
  s4.assign("RAHUL RANJAN YADAV",2,5);
  cout<<s4<<endl;
  s4.assign("RAHUL RANJAN YADAV");
  cout<<s4<<endl;
  s4.insert(s4.length()," CODING");
  cout<<s4<<endl;
  s4.insert(18," VERY MUCH LOVES");
  cout<<s4<<endl;
  s4.erase(6);
  cout<<s4<<endl;
  s4.assign("RAHUL RANJAN");
  s4.insert(s4.length()," CODING");
  cout<<s4<<endl;
  string temp=" VERY MUCH LOVES";
  s4.insert(12,temp,10,6);
  cout<<s4<<endl;
  int pos=s4.find("RANJAN");
  cout<<pos<<endl;
  string sub=s4.substr(pos);
  cout<<sub<<endl;
  string subSub=sub.substr(0,6);
  cout<<subSub<<endl;
  s4.assign("RAHUL RANJAN YADAV LOVES CODING FROM DEEP INSIDE HIS HEART");
  cout<<s4<<endl;
  string replace;
  cin>>replace;
  s4.replace(s4.find("CODING"),strlen("CODING"),replace);
  cout<<s4<<endl;
  s4.assign("THIS HAS TO BE READ REVERSED.");
  cout<<s4<<endl;
  reverse(s4.begin(),s4.end());
  cout<<s4<<endl;
  int id=5;
  int l=5;
  while(id<s4.length())
  {
    reverse(s4.begin(),s4.begin()+id);
    cout<<s4<<endl;
    id+=l;
  }
  return 0;
}*//*
int main()
{
  string s= "My Name id Rahul Ranjan";
  cout<<s<<endl;
  s.append(" Yadav");
  cout<<s<<endl;
  s.replace(s.find("id"),strlen("id"),"is");
  cout<<s<<endl;
  s.insert(s.find("is")+2," i donn't know ");
  cout<<s<<endl;
  s.erase(s.find("i "),strlen("i donn't know "));
  cout<<s<<endl;
  return 0;
}*//*
int main()
{
  string s;
  cin>>s;
  cout<<s.length()<<endl;
  char *cstring=(char*)(s.c_str());
  cout<<strlen(cstring)<<endl;
  char cstring2[100];
  cin>>cstring2;
  cout<<strlen(cstring2)<<endl;
  string s2(cstring2);
  cout<<s2.length()<<endl;
  return 0;
}*//*
int main()
{
  string s;
  cin>>s;
  string temp="";
  int sum=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]>='0'&&s[i]<='9') temp+=s[i];
    else
    {
      sum+=atoi(temp.c_str());
      temp="";
    }
  }
  sum+=atoi(temp.c_str());
  cout<<sum<<endl;
  return 0;
}*//*
int main()
{
  string s;
  int temp=5;
  cin>>s;
  while(next_permutation(s.begin(),s.end())&&temp--)
    cout<<s<<endl;
  cout<<endl<<endl;
  temp=5;
  while(prev_permutation(s.begin(),s.end())&&temp--)
    cout<<s<<endl;
  cout<<endl<<s;
  return 0;
}*/