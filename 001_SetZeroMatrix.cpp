#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> v)
{
    for (auto a : v)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// optimal approach
void setZeroMatrix(vector<vector<int>> &v)
{
    // col0 variable to avoid clash of row0 and col0
    int col0 = 1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 0)
            {
                // set first of corresponding row = 0
                v[i][0] = 0;
                if (j == 0)
                {
                    // set col0 = 0
                    col0 = 0;
                }
                else
                {
                    // set first of corresponding row = 0
                    v[0][j] = 0;
                }
            }
        }
    }
    cout << "col0 = " << col0 << endl;

    cout << "Printing matrix before setting any numbers: " << endl;
    printMatrix(v);

    // setting numbers from (1,1) to (n-1,m-1)
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 1; j < v[0].size(); j++)
        {
            if (!(v[i][0] && v[0][j]))
            {
                v[i][j] = 0;
            }
        }
    }

    cout << "Printing matrix after setting numbers from (1,1) to (n-1,m-1): " << endl;
    printMatrix(v);

    // Why we are marking the 1st row first and then the 1st column:
    // We can notice that the modification of the 1st row is dependent on matrix[0][0] and the modification of the 1st column is dependent on col0 which is an independent variable.Now, if we modify the 1st column first, matrix[0][0] might be changed and this will hinder the modification of the 1st row as well.But if we simply do the opposite, the 1st row will be changed first, based on the value matrix[0][0] and then the 1st column will be changed based on the variable col0.This is why the order of change matters.

    //changing first row
    for (int i = 0; i < v[0].size(); i++)
    {
        if (!v[0][0])
        {
            v[0][i]=0;
        }        
    }

    cout << "Printing matrix after modifying the first row: " << endl;
    printMatrix(v);

    //changing first column
    for (int i = 0; i < v.size(); i++)
    {
        if (!col0)
        {
            v[i][0]=0;
        }        
    }    
}

int main()
{
    vector<vector<int>> v = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    cout << "Original Matrix: " << endl;
    printMatrix(v);
    setZeroMatrix(v);
    cout << "Modified Matrix: " << endl;
    printMatrix(v);
}