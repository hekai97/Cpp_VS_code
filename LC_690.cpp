#include <bits/stdc++.h>
using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e:employees){
            if(e->id==id){
                if(e->subordinates.size()==0){
                    return e->importance;
                }
                for(int ids:e->subordinates)
                {
                    e->importance+=getImportance(employees,ids);
                }
                return e->importance;
            }
        }
        return 0;
    }
};
int main()
{
    Employee* first=new Employee();
    first->id=1;
    first->importance=5;
    first->subordinates.push_back(2);
    first->subordinates.push_back(3);

    Employee* second=new Employee();
    second->id=2;
    second->importance=3;

    Employee* third=new Employee();
    third->id=3;
    third->importance=3;


    vector<Employee*> employees;
    employees.push_back(first);
    employees.push_back(second);
    employees.push_back(third);
    Solution s;
    cout<<s.getImportance(employees,1);
    return 0;
}