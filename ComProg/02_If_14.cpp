#include<iostream>
using namespace std;

int choose = -1;

struct Student
{
    string id;
    double gpax;
    char grade_cp;
    char grade_cal1;
    char grade_cal2;
};

int main()
{
    Student x[2];
    for(int i=0;i<2;++i) cin >> x[i].id >> x[i].gpax >> x[i].grade_cp >> x[i].grade_cal1 >> x[i].grade_cal2;
    if(x[0].grade_cp == 'A' && x[1].grade_cp == 'A' && x[0].grade_cal1 <= 'C' && x[0].grade_cal2 <= 'C' && x[1].grade_cal1 <= 'C' && x[1].grade_cal2 <= 'C')
    {
        if(x[0].gpax > x[1].gpax) choose = 0;
        else if(x[0].gpax < x[1].gpax) choose = 1;
        else
        {
            if(x[0].grade_cal1 < x[1].grade_cal1) choose = 0;
            else if(x[0].grade_cal1 > x[1].grade_cal1) choose = 1;
            else
            {
                if(x[0].grade_cal2 < x[1].grade_cal2) choose = 0;
                else if(x[0].grade_cal2 > x[1].grade_cal2) choose = 1;
                else choose = 2;
            }
        }
    }
    else
    {
        if((x[0].grade_cp != 'A' || x[0].grade_cal1 > 'C' || x[0].grade_cal2 > 'C') && (x[1].grade_cp != 'A' || x[1].grade_cal1 > 'C' || x[1].grade_cal2 > 'C')) choose = -1;
        else if((x[0].grade_cp != 'A' || x[0].grade_cal1 > 'C' || x[0].grade_cal2 > 'C') && (x[1].grade_cp == 'A' || x[1].grade_cal1 <= 'C' || x[1].grade_cal2 <= 'C')) choose = 1;
        else if((x[1].grade_cp != 'A' || x[1].grade_cal1 > 'C' || x[1].grade_cal2 > 'C') && (x[0].grade_cp == 'A' || x[0].grade_cal1 <= 'C' || x[0].grade_cal2 <= 'C')) choose = 0;
    }
    if(choose == -1) cout << "None";
    else if(choose == 0) cout << x[0].id;
    else if(choose == 1) cout << x[1].id;
    else if(choose == 2) cout << "Both";
    return 0;
}