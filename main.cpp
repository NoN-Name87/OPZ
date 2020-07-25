#include <iostream>
#include <cstring>
#include <stack>
#include <cctype>
using namespace std;

int Check_pr(char pr)
{
     switch(pr)
     {
            case '(':
            return 0;
            break;
            case ')':
            return 1;
            break;
            case '+':
            case '-':
            return 2;
            break;
            case '*':
            case '/':
            return 3;
            break;
            case '^':
            return 4;
            break;
     }
}

void Priority(stack<char>&st_op,char s,string &num)
{
   if(st_op.empty()||Check_pr(s)>Check_pr(st_op.top())||s=='(')
   {
     st_op.push(s);
   }

  else if(Check_pr(s)<=Check_pr(st_op.top())&&Check_pr(s)!=1&&Check_pr(s)!=0)
          {
           num+=st_op.top();
           st_op.pop();
           Priority(st_op,s,num);
          }

  else if(s==')')
  {
      while(st_op.top()!='(')
      {
          num+=st_op.top();
          st_op.pop();
      }
    st_op.pop();
  }
}

void Input_operator(stack<char>&st_op,string &s,string &num)
{
    for (auto i : s)
    {
        if(isdigit(i)||(i>='A'&&i<='F'))
        {
            num+=i;
        }
        switch(i)
        {
            case '(':
            Priority(st_op,i,num);
            break;
            case ')':
            Priority(st_op,i,num);
            break;
            case '+':
            case '-':
            Priority(st_op,i,num);
            break;
            case '*':
            case '/':
            Priority(st_op,i,num);
            break;
            case '^':
            Priority(st_op,i,num);
            break;
        }
    }
}

void Empty_stack(stack<char> &st_op,string &num)
{
    while(!st_op.empty())
    {
        num+=st_op.top();
        st_op.pop();
    }
}

int Calculation(string &num)
{
    stack<int>final_num;
    int value1,value2,res;
    for(auto i: num)
    {
        if(isdigit(i))
        {
			i -= 48;
        final_num.push(i);
        }
        else if(i>='A'&&i<='F')
        {
            i-=55;
            final_num.push(i);
        }
        else
        {
        value2=final_num.top();
        final_num.pop();
        value1=final_num.top();
        final_num.pop();
          switch(i)
          {
            case '+':
            res=value1+value2;
            break;
            case '-':
            res=value1-value2;
            break;
            case '*':
            res=value1*value2;
            break;
            case '/':
            res=value1/value2;
            break;
            case '^':
            res=value1^value2;
            break;
          }
          final_num.push(res);
        }
    }
    return final_num.top();
}

int main()
{
    stack<char>st_op;
    string s,num;
    cin>>s;
    Input_operator(st_op,s,num);
    Empty_stack(st_op,num);
    cout << num << endl;
    cout << Calculation(num);
    return 0;
}

