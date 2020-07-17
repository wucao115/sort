#include<iostream> 
#include<vector>

using namespace std;

class BbbleSort {
public:
    BbbleSort(vector<int>&& nums) :m_vec(nums) {}
    BbbleSort(vector<int>& nums) :m_vec(nums) {}
    void swap(int i, int j) {
        int temp = m_vec[i];
        m_vec[i] = m_vec[j];
        m_vec[j] = temp;
    }
    vector<int>& sort() {
        int count = 0;
        bool flag = true;
        for (int i = 0; i < m_vec.size() - 1 && flag; ++i) {
            flag = false;
            for (int j = m_vec.size() - 1; j > i; --j) {
                if (m_vec[j] < m_vec[j - 1]) {
                    swap(j - 1, j);
                    flag = true;
                    count++;
                }
            }
        }
        cout << count;
        return m_vec;
    }
private:
    vector<int> m_vec;
};

int main()
{
    BbbleSort a(vector<int>{1, 4, 2, 3});
    a.sort();
}
