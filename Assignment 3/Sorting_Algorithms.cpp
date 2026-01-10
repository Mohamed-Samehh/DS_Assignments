#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    // Bubble Sort
    int nums1[] = {64, 25, 12, 22, 11};
    int len = size(nums1);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (nums1[j] > nums1[j + 1])
            {
                swap(nums1[j], nums1[j + 1]);
            }
        }
    }

    cout << "Bubble Sort:";
    for (int i = 0; i < len; i++)
    {
        cout << " " << nums1[i];
    }
    cout << endl;

    // ==========================================================

    // Selection Sort
    int nums2[] = {64, 25, 12, 22, 11};

    for (int i = 0; i < len - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < len; j++)
        {
            if (nums2[j] < nums2[minIndex])
            {
                minIndex = j;
            }
        }

        swap(nums2[i], nums2[minIndex]);
    }

    cout << "Selection Sort:";
    for (int i = 0; i < len; i++)
    {
        cout << " " << nums2[i];
    }
    cout << endl;

    // ==========================================================

    // Insertion Sort
    int nums3[] = {64, 25, 12, 22, 11};

    for (int i = 1; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (nums3[j] < nums3[j - 1])
            {
                swap(nums3[j], nums3[j - 1]);
            }
        }
    }

    cout << "Insertion Sort:";
    for (int i = 0; i < len; i++)
    {
        cout << " " << nums3[i];
    }
    cout << endl;

    // ==========================================================

    // Binary Search
    int start = 0;
    int end = len - 1;
    int midIndex;
    int target = 11;
    bool found = false;

    while (start <= end)
    {
        midIndex = (start + end) / 2;

        if (nums3[midIndex] == target)
        {
            cout << "Found!" << endl;
            found = true;
            break;
        }
        else if (nums3[midIndex] > target)
        {
            end = midIndex - 1;
        }
        else
        {
            start = midIndex + 1;
        }
    }
    if (!found)
    {
        cout << "Not found!" << endl;
    }
}
