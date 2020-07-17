#include<iostream> 
#include<vector>

using namespace std;

class SelectSort {
public:
    SelectSort(vector<int>&& nums) :m_vec(nums) {}
    SelectSort(vector<int>& nums) :m_vec(nums) {}
    void swap(int i, int j) {
        int temp = m_vec[i];
        m_vec[i] = m_vec[j];
        m_vec[j] = temp;
    }
    vector<int>& sort() {
        
       
        for (int i = 0; i < m_vec.size() - 1; ++i) {
            int minindex = i;
            for (int j = i + 1; j < m_vec.size(); ++j) {
                if (m_vec[j] < m_vec[minindex]) {
                    minindex = j;
                }
            }
            swap(i, minindex);
        }
        return m_vec;
    }
private:
    vector<int> m_vec;
};

int main()
{
    SelectSort a(vector<int>{1, 4, 2, 3});
    a.sort();
}
