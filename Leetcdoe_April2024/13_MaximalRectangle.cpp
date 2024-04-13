/*
85. Maximal Rectangle
Question Link ->
https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2024-04-13
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> previousSmallerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nextSmaller;
        vector<int> previousSmaller;
        int n = heights.size();

        nextSmaller = nextSmallerElement(heights);
        previousSmaller = previousSmallerElement(heights);
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            if (nextSmaller[i] == -1)
            {
                nextSmaller[i] = n;
            }
            int width = nextSmaller[i] - previousSmaller[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v;

        // convert the matrix to int for our shortcut
        for (int i = 0; i < m; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(matrix[i][j] - '0');
            }
            v.push_back(temp);
        }

        int area = largestRectangleArea(v[0]);
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 0)
                {
                    v[i][j] = 0;
                }
                else
                {
                    v[i][j] += v[i - 1][j];
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};