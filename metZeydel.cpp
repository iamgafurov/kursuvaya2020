#include<iostream>
#include<vector>
#include<fstream>
#include<math.h>
#include<iomanip>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
double a[100][100],b[100],eps,n;
//
bool  ok(vector<long double>v1 ,vector<long double>v2 ){
  for(int i=0;i<n;i++)
    if((fabs(v2[i]) - fabs(v1[i]))>eps)return false;
return true;
}

bool correct(){
double s=0;

for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
    if (i!=j)
        s+=a[i][j];
}
if(fabs(a[i][i])<s)
    return false;
s=0;
}
return true;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    in>>n>>eps;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            in>>a[i][j];
    for(int i=0;i<n;i++)
        in>>b[i];
    int k=1;
if(correct()){
vector<long double>x;
for(int i=0;i<n;i++)
    x.push_back(a[i][i]);

    vector<long double>lx(n+1);
     vector<long double>cx(n+1);
   out<<"Қимматхои аввала: "<<endl;
    for(int i=0;i<n;i++){
        lx[i]=b[i]/a[i][i];
        cx[i]=lx[i];
        out<<lx[i]<<" ";
    }
    out<<endl;

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    if(i!=j)
    a[i][j]/=a[i][i];
while(1){
        out<<"----------------------------------------------------------------------------------------"<<endl;
    out<<" Итератсия №"<< k<<endl;
       long double s=0;

    for(int i=0;i<n;i++){
       s=0;
        out<<"x"<<i+1<<"("<<k<<") = "<<b[i]/a[i][i];
       for(int j=0;j<n;j++)
           if(i!=j){
                s+=(a[i][j] * lx[j]);
                out<<" - ("<<a[i][j]<<" * " <<lx[j]<<")";
      // cout<<a[i][j]/a[i][i] <<" * "<< lx[j]<<endl;
            }
        lx[i]=(b[i]/a[i][i])-s;

        out<<" =  "<<lx[i]<<endl;
    }
out<<"Ҷавобҳо :"<<endl;
for(int i=0;i<n;i++)
    out<<"x"<<i+1<<" = "<<lx[i]<<endl;
    out<<endl;
for(int i=0;i<n;i++)
cout<<lx[i]<<" ";
cout<<endl;

for(int i=0;i<n;i++)
cout<<cx[i]<<" ";
cout<<endl<<endl;

if(ok(lx,cx))
    break;

for(int i=0;i<n;i++)
            cx[i]=lx[i];
k++;

}}
else
    out<<"Шарти наздикшави ичро намешавад!";
}
