#include <bits/stdc++.h>
using namespace std;

/*
col=0 1 2 3 4 5
row
0=> 1 1 1 0 0 0
1=> 0 1 0 0 0 0
2=> 1 1 1 0 0 0
3=> 0 0 2 4 4 0
4=> 0 0 0 2 0 0
5=> 0 0 1 2 4 0
*/

int hourglassSum(vector <vector<int> > arr) 
{

    int max=INT_MIN; //take max as MIN so later we can compare with the sum of array

    vector<vector<int> > sum (4,vector<int> (4,0));

    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {

            sum[i][j] = arr[i][j] + arr[i][j+1] + arr[i][j+2]; //row won't change only col will increase by 1

            sum[i][j] = arr[i+1][j+1] + sum[i][j]; // we are taking the middle element so i+1 and j+1 and also adding the previous value of sum

            sum[i][j] = arr[i+2][j]+ arr[i+2][j+1] + arr[i+2][j+2] + sum[i][j]; //now taking the 3rd row and adding the previous value of sum

        }
    }

    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if( sum[i][j]> max )
            {
                max = sum[i][j];  //if sum[i][j] is bigger than max then set it into max
            }
        }
    }

    return max; //returning the value of max into the main function

}


int main()
{
    vector<vector<int> > arr(6);

    for (int i=0; i<6; i++)
    {
         arr[i].resize(6);
        for(int j=0; j<6; j++)
        {
            cin>>arr[i][j];
        }
    }

    int result = hourglassSum(arr);

     //cout<< (hourglassSum(arr));
    cout << result ;


}
// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     vector<vector<int>> arr(6);
//     for (int i = 0; i < 6; i++) {
//         arr[i].resize(6);

//         for (int j = 0; j < 6; j++) {
//             cin >> arr[i][j];
//         }

//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }

//     int result = hourglassSum(arr);

//     cout << result << "\n";

//     //fout.close();

//     return 0;
// }