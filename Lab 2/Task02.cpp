#include <iostream>
using namespace std;

class ndArray
{
protected:
    int *data;
    int *dim;
    int size;

public:
    ndArray(int d, int arr[])
    {
        int nd_size = 1;
        size = d;
        dim = new int[size];
        for (int i = 0; i < d; i++)
        {
            dim[i] = arr[i];
            nd_size *= arr[i];
        }
        data = new int[nd_size];
        for (int i = 0; i < nd_size; i++)
        {
            data[i] = 0;
        }
    }

    int calculateIndex(int arr[])
    {
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            int data = arr[i];
            for (int j = i + 1; j < size; j++)
            {
                data *= dim[j];
            }
            index += data;
        }
        return index;
    }

    void setValue(int arr[], int val)
    {
        int index = calculateIndex(arr);
        data[index] = val;
    }

    int getValue(int arr[])
    {
        int index = calculateIndex(arr);
        return data[index];
    }       

    bool validIndex(int arr[])
    {
        int arr_size = calculateIndex(arr);
        int dim_size = calculateIndex(dim);
        if (arr_size < 0 || arr_size >= dim_size)
            return false;
        else
            return true;
    }
};

int main()
{
    int dimsize[3] = {2, 3, 5};
    ndArray arr(3, dimsize);
    int indexset[3] = {1, 2, 4};
    int indexset2[3] = {5, 2, 4};
    cout << arr.calculateIndex(indexset) << endl;
    arr.setValue(indexset, 3);
    cout << "Value at " << arr.calculateIndex(indexset) << " is: " << arr.getValue(indexset) << endl;
    cout << "Valid Index: " << arr.validIndex(indexset) << endl;
    cout << "Valid Index: " << arr.validIndex(indexset2) << endl;
}