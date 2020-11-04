unsigned long long mypow(unsigned int x, unsigned int y)
{
        unsigned long long res=1;
        if (y==0)
                res = 1;
        else if (y==1)
                res = x;
        else
                res = x * mypow(x, y-1);
        return res;
}

