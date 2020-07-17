#include<iostream> 
#include<vector>

using namespace std;

class InsertSort {
public:
    InsertSort(vector<int>&& nums) :m_vec(nums) {}
    InsertSort(vector<int>& nums) :m_vec(nums) {}
   
    vector<int>& sort() {
        for (int i = 1; i < m_vec.size(); ++i) {
            int temp = m_vec[i];
            int current = i-1;
            while (current >= 0 && m_vec[current] > temp) {
                m_vec[current+1] = m_vec[current];
                current--;
            }
            m_vec[current+1] = temp;
        }
        return m_vec;
    }
private:
    vector<int> m_vec;
};

int main()
{
    InsertSort a(vector<int>{1, 4, 2, 3});
    a.sort();
}
