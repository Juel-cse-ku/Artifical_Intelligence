#include <bits/stdc++.h>

using namespace std;

int main() {
 freopen("text.txt", "r", stdin);

 int n,i,j;
 int e=0;
 char ch,p,q='E';
 int inferred[26] = {0};

 vector < vector < char > > left;
 vector < char > right;
 vector < int > premise_count;

 queue < char > database;
 database.push('A');
 database.push('B');

 while(cin >> ch)
 {
     if(ch=='a')
        break;
    vector < char > temp_v;
    n =0;
    while(ch != '\n')
    {
        if(ch=='>')
        {
            cin >> ch;
            right.push_back(ch);
            break;
        }

        else
        {
            n++;
            temp_v.push_back(ch);
            cin >> ch;
        }

    }
    left.push_back(temp_v);
    premise_count.push_back(n);
    cout << n << endl;
}

while (!database.empty())
{
    p =  database.front();
    database.pop();

    if(p==q)
    {
        cout << "true";
        e=1;
        break;
    }
    else
    {
        int k = p-65;
        if(inferred[k] == 0)
        {
            inferred[k] = 1;

            for(i=0;i<left.size();i++)
            {
                //cout << premise_count[i] << endl;
                for(j=0;j<left[i].size();j++)
                {
                    if(left[i][j] == p);
                    {
                        premise_count[i]--;
                    }

                }

                if(premise_count[i] == 0)
                {
                    e=0;
                    if(q == right[i])
                    {
                        cout << "true++";
                        e = 1;
                        break;
                    }
                    else
                    {
                        database.push(right[i]);
                    }
                }
            }
            if(e==1)
                break;
        }
    }
}
if(e==0)
    cout << "false";

return 0;
}

