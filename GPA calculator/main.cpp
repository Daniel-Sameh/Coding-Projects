//The GPA calculator developed by Daniel Sameh.
//@2023
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct course{
    int hour;
    string grade;
};
int main() {
//    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cout<<"Welcome to the GPA calculator!\nPlease enter the number of courses:\n";
    int n; cin>>n;
    course c[n];
    cout<<"Enter each credit hour and grade (ex: 2 A+)";
    cout<<"\n";
    for (int i = 0; i < n; ++i) {
        cout<<"C"<<i+1<<": ";
        cin>>c[i].hour>>c[i].grade;
    }
    double hours=0;
    double points = 0;

    for (auto i:c) {
        hours+=i.hour;
        int x= i.hour;
        if (i.grade=="A+")
            points+=4*x;
        else if (i.grade=="A")
            points+=3.7*x;
        else if (i.grade=="B+")
            points+=3.3*x;
        else if (i.grade=="B")
            points+=3*x;
        else if (i.grade=="C+")
            points+=2.7*x;
        else if (i.grade=="C")
            points+=2.4*x;
        else if (i.grade=="D+")
            points+=2.2*x;
        else if (i.grade=="D")
            points+=2*x;
    }
    double GPA= points/hours;
    cout<<"Your GPA= "<<GPA<<'\n';
}
