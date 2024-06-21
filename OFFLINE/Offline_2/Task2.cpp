#include<bits/stdc++.h>
#include"Stack.cpp"
//#include"Task1.cpp"
using namespace std;
bool is_digit(char c)
{
    if(c>='0'&& c<='9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_operator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int set_precedence(char c)
{
    if(c=='+'|| c=='-')
    {
        return 1;
    }

    if(c=='*' || c=='/')
    {
        return 2;
    }

   /* if(c=='('||c==')')
    {
        return 3;
    }*/
    else
    {
        return 0;
    }
}
double result(int v1,int v2,char op)
{
   if(op=='+')
   {
    return v1+v2;
   }
   if(op=='-')
   {
    return v1-v2;
   }
   if(op=='*')
   {
    return v1*v2;
   }
   if(op=='/')
   {
    return v1/v2;
   }
   else
   {
    return 0;
   }
}
int calculation (string s )
{
    Stack<double>value;
    Stack<char>opt;
    double val=0;
    int pos=0;
    while(pos<s.length())
    {
        char p=s[pos];
        if(is_digit(p))
        {
            val=(val*10)+(p-'0');
            //cout<<"1"<<val<<endl;
        }
        else if(is_operator(p))
        {
            if(p=='(')
            {
                opt.push(p);
                 val=0;
            }
            else if(value.isEmpty())
            {
                value.push(val);
                //cout<<"2"<<val<<endl;
                opt.push(p);
                val=0;
            }
            else if(p==')')

            {
                value.push(val);
                //cout<<"3"<<val<<endl;
                while(opt.topvalue()!='(')
                {
                    p=opt.pop();
                   // cout<<"4"<<p<<endl;
                    val=value.pop();
                    //cout<<"5"<<val<<endl;
                    double p1=value.pop();
                   // cout<<"6"<<p1<<endl;
                    val=result(p1,val,p);
                    value.push(val);
                   // cout<<"7"<<val<<endl;

                }
                opt.pop();
               // cout<<"8"<<opt.pop()<<endl;
                //value.pop();
                //cout<<"9"<<value.pop()<<endl;
            }
            else
            {
                char p1=opt.topvalue();
                //cout<<"9"<<p1<<endl;
                if(set_precedence(p)>set_precedence(p1))
                {
                    value.push(val);
                  //  cout<<"10"<<val<<endl;
                    opt.push(p);
                    //cout<<"11"<<p<<endl;
                    val=0;
                }
                else
                {
                    double prev_val=value.pop();
                    //cout<<"12"<<prev_val<<endl;
                    double prev_op=opt.pop();
                    //cout<<"13"<<prev_op<<endl;
                    prev_val=result(prev_val,val,prev_op);
                    //cout<<"14"<<prev_val<<endl;
                    value.push(prev_val);
                    opt.push(p);
                    //cout<<"15"<<p<<endl;
                    val=0;
                }

            }

        }
        pos++;
    }
    while(!opt.isEmpty())
    {
        double prev_val=value.pop();
        //cout<<"16"<<prev_val<<endl;
        char p=opt.pop();
        //cout<<"17"<<p<<endl;
        val=result(prev_val,val,p);
        //cout<<"18"<<val<<endl;

    }
    return val;
}
int validity(string s1)
{
    int opening_c = 0;
    int closing_c = 0;
    int indx = 0;
    while (indx < s1.length())
    {
        char b = s1[indx];
        if (b == '(' || b == ')')
        {
            if (b == '(')
            {
                if (indx < s1.length() - 1 && (s1[indx + 1] == ')' ))
                {
                    return -1;
                }
                opening_c++;
            }
            else if (b == ')')
            {
                if (indx > 0 && (s1[indx - 1] == '(' || is_operator(s1[indx - 1])))
                {
                    return -1;
                }
                closing_c++;
            }
        }
        else if (is_digit(b))
        {
            if (indx < s1.length() - 1 && (s1[indx + 1] == '('))
            {
                return -1;
            }
        }
        else if (is_operator(b))
        {
            if (indx == 0 || indx == s1.length() - 1 || is_operator(s1[indx + 1]) || is_operator(s1[indx - 1]))
            {
                return -1;
            }
        }
        indx++;
    }
    if (opening_c != closing_c)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}






int main()
{
    string cal;
    cin>>cal;
    double ans;
    ans=calculation(cal);
    int ans1;
    ans1=validity(cal);
    if(ans1==-1)
    {
        cout<<"Not valid"<<endl;
    }
    else
    {
      cout<<"Valid expression"<<endl;
      cout<<"Computed value:"<<" "<<ans<<endl;
    }
}


