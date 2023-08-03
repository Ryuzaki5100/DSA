Insertion_Sort(array a)
{
    for (i = 1; i < a.size; i++)
    {
        j = i, key = a[i];
        while (j > 0 && a[j - 1] > key)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = key;
    }
}