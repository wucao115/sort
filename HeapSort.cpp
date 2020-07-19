#include<iostream> 
#include<vector>

using namespace std;

class HeapSort {
public:
    HeapSort(vector<int>&& nums) :m_vec(nums) {}
    HeapSort(vector<int>& nums) :m_vec(nums) {}

    void swap(int i, int j) {
        int temp = m_vec[i];
        m_vec[i] = m_vec[j];
        m_vec[j] = temp;
    }

    vector<int>& sort() {
        int i;
        int n = m_vec.size();
        for (i = n / 2 - 1; i >= 0; --i) {
            HeapAdjust(i, n);        //从左叶子节点的父节点，开始排序，每次排序排到叶子节点。
        }
        for (i = n-1 ; i > 0; --i) {
            swap(0, i);
            HeapAdjust(0,i);   //交换最大节点 后再重新排序。
        }
        return m_vec;
    }

    void HeapAdjust(int s, int n) {
        int i, temp;
        temp = m_vec[s];
        for (i = 2 * s + 1; i < n; i = i * 2+1) {
            if (i < n-1 && m_vec[i] < m_vec[i + 1]) {
                i++;
            }
            if (temp >= m_vec[i]) {
                break;
            }
            m_vec[s] = m_vec[i];
            s = i;
        }
        m_vec[s] = temp;
    }
private:
    vector<int> m_vec;
};

int main()
{
    HeapSort a(vector<int>{1, 4, 2, 3, 0});
    vector<int> b = a.sort();
}
