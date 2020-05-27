template <class T>
void swap(T *ptr1, T *ptr2)
{
    T temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

template <class T>
void bubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

template <class T>
void quickSortMain(T arr[], int left, int right)
{
    if (left < right)
    {
        int low = left;
        int high = right;
        {
            T pivot = arr[low];
            while (left < right)
            {
                while (arr[left] < pivot)
                    left++;
                while (pivot < arr[right])
                    right--;
                swap(&arr[left], &arr[right]);
            }
            swap(&pivot, &arr[left]);
        }
        quickSortMain(arr, low, left);
        quickSortMain(arr, left + 1, right);
    }
}

template <class T>
void insertionSort(T arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i;
        for (; j > left && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

template <class T>
void hybridSortMain(T arr[], int left, int right)
{
    if (left < right)
    {
        if (right - left + 1 < 10)
        {
            insertionSort(arr, left, right);
            return;
        }
        else
        {
            int low = left;
            int high = right;
            {
                T pivot = arr[low];
                while (left < right)
                {
                    while (arr[left] < pivot)
                        left++;
                    while (pivot < arr[right])
                        right--;
                    swap(&arr[left], &arr[right]);
                }
                swap(&pivot, &arr[left]);
            }
            if(left - low < right - left)
            {
                hybridSortMain(arr, low, left);
                low = left + 1;
            }
            else
            {
                hybridSortMain(arr, left + 1, right);
                right = left;
            }
            
            
        }
    }
}

template <class T>
void hybridSort(T arr[], int size)
{
    hybridSortMain(arr, 0, size - 1);
}

template <class T>
void quickSort(T arr[], int size)
{
    quickSortMain(arr, 0, size - 1);
}
