//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//store in A , A has size M+N-1


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k=m+n-1;
        m--;
        n--;
        while(n>=0)
        {
            if(m >=0 && A[m] > B[n])
                A[k--] = A[m--];
            else
                A[k--] = B[n--];
        }
    }
};
