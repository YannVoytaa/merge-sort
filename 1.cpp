#include<bits/stdc++.h>
using namespace std;
struct List{
    int val;
    List* next;
};

void add(int val, List *&start){
    //cout<<start<<'\n';
    List* el= new List;
    el->val=val;
    el->next=start;
    start=el;
}

void show(List *start){
    while(start){
        printf("%d\n",start->val);
        start=start->next;
    }
}

void msort(int*&t,int p,int k,int*&zapas,int n){
if(p>=k)return;
msort(t,p,(p+k)/2,zapas,n);
msort(t,(p+k)/2+1,k,zapas,n);
int ind1=p;
int ind2=(p+k)/2+1;
int zapasind=0;
while(zapasind<k-p+1){
    if(ind1>(p+k)/2){
        zapas[++zapasind]=t[ind2];
        ind2++;
    }
    else if(ind2>k){
        zapas[++zapasind]=t[ind1];
        ind1++;
    }
    else if(t[ind1]<t[ind2]){
        zapas[++zapasind]=t[ind1];
        ind1++;
    }
    else{
        zapas[++zapasind]=t[ind2];
        ind2++;
    }
}
//cout<<p<<' '<<k<<'\n';for(int i=0;i<n;i++)cout<<t[i]<<' ';cout<<'\n';
for(int ind=p;ind<=k;ind++){
    t[ind]=zapas[ind-p+1];
}
//for(int i=0;i<n;i++)cout<<t[i]<<' ';cout<<'\n';
}

int main(){
ios_base::sync_with_stdio(0);
cout<<"Specify an array:\n";
cout<<"Number of elements: ";
int n;
cin>>n;
int*t=(int*)(malloc(n*sizeof(int)));
system("CLS");
for(int i=1;i<=n;i++){
    cout<<"Value nr "<<i<<": ";
    cin>>t[i-1];
}
int*zapas=(int*)(malloc(n*sizeof(int)));
msort(t,0,n-1,zapas,n);
cout<<"Sorted array:\n";
for(int i=0;i<n;i++)cout<<t[i]<<' ';
}
