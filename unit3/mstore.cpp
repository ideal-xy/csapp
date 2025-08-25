int mult2(int,int);

void multistore(int x,int y,int* dest)
{
    int t = mult2(x, y);
    *dest = t;
}
