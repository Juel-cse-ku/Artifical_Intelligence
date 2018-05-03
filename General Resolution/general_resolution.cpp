#include <bits/stdc++.h>

using namespace std;
int aa = 0;
bool general_resolution(vector < vector < char > > kb)
{
    int n=0,i,j,c,p,q,r;
    vector < vector < char > > updated_kb = kb;


    int total_combination = 0;
    int number_subset = 0;
    for(i=0; i<kb.size()-1; i++)
    {
        for(j=i+1; j<kb.size(); j++)
        {
            total_combination++;
            vector < char > a;
            a = kb[i];
            a.insert(a.end(), kb[j].begin(), kb[j].end());

            while(1) //removing negation
            {
                int initial_size = a.size();
                for(p=0; p<a.size()-1 && a.size() != 0; p++)
                {
                    for(q=p+1; q<a.size(); q++)
                    {
                        if(abs(a[p] - a[q]) == 32)
                        {
                            a.erase (a.begin()+p);
                            a.erase (a.begin()+q-1);
                            //f=1;
                            break;
                        }
                        else if(abs(a[p] - a[q]) == 0)
                        {
                            a.erase (a.begin()+q-1);
                        }
                    }
                }

                if(a.size() == 0)
                    return true;

                if(initial_size == a.size())
                    break;
            } //end of removing negation

            // checking subset
            vector < char > b;
            for(p=0; p<kb.size(); p++)
            {
                b = a;
                for(q=0; q<kb[p].size(); q++)
                {
                    for(r=0; r<b.size() && b.size() != 0; r++)
                    {
                        if(b[r] == kb[p][q])
                        {
                            b.erase(b.begin()+r);
                            break;
                        }
                    }
                    if(b.size() == 0)
                        break;
                }
                if(b.size() == 0)
                    break;
            }
            updated_kb.push_back(a);

            if(b.size() == 0)
                number_subset++;

//            for(c=0; c<a.size(); c++)
//            {
//                cout << a[c];
//            }
//            cout << endl;
        }
    }
    if(number_subset == total_combination)
        return false;

    else
        general_resolution(updated_kb);
}

int main()
{
    string knowledge = "aB&AbC&c";
    //string knowledge = "ABc&b&a";
    //string knowledge = "ABc&bD&a";
    //string knowledge = "AB&AB&A";

    vector < vector < char > > kb;
    int i,j;
    char query = 'C';
    int n=0;

    while(n<knowledge.size())
    {
        vector < char > temp;
        while(knowledge[n] != '&' && n < knowledge.size())
        {
            temp.push_back(knowledge[n]);
            n++;

        }
        kb.push_back(temp);
        n++;
    }

    if(general_resolution(kb))
        cout << "TRUE";
    else
        cout << "FALSE";

    return 0;
}

