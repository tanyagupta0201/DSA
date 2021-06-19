class Vector
{
    int cs, ms, *arr;

public:
    Vector()
    {
        cs = 0;
        ms = 1;
        arr = new int[ms];
    }

    void push_back(int data)
    {
        if (cs == ms)
        {
            // Array if full
            int *oldArr = arr;
            arr = new int[2 * ms];
            ms = ms * 2;

            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldArr[i];
            }
            // Clear the old memory
            delete[] oldArr;
        }
        arr[cs] = data;
        cs++;
    }

    void pop_back()
    {
        cs--;
    }

    int front()
    {
        return arr[0];
    }

    int back()
    {
        return arr[cs - 1];
    }

    bool empty()
    {
        return cs == 0;
    }

    int capacity()
    {
        return ms;
    }

    int at(int i)
    {
        return arr[i];
    }

    int size()
    {
        return cs;
    }

    // Operator Overloading
    int operator[](int i)
    {
        return arr[i];
    }
};