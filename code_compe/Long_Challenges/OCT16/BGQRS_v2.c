#include<stdio.h>
#include<malloc.h>
typedef struct Poseidon
{
    int p5;
    int p2;
    int l;
    int r;
    char ck;
}Poseidon;
int pow2(int);
int pow5(int);
int pow2_v2(int);
int pow5_v2(int);
void makeTree(Poseidon *A, Poseidon *Tree, int ini, int end, int node);
void updateType1(Poseidon *Tree, Poseidon *Lazy, Poseidon, int, int, int, int, int);
int main()
{
    int t, n, Q, i, num, type, l, r, x, k, res;
    Poseidon *A, X, *tree, *lazy;
    scanf("%d", &t);
    while(t--)
    {
        res = 0;
        scanf("%d %d", &n, &Q);
        A = (Poseidon *) malloc(sizeof(Poseidon) * n);
        tree = (Poseidon *) malloc(sizeof(Poseidon) * (2 * n - 1));
        lazy = (Poseidon *) malloc(sizeof(Poseidon) * (2 * n - 1));
        for(i = 0; i < n; i++)
        {
            scanf("%d", &num);
            A[i].p2 = A[i].p5 = 0;
            if(num % 2 == 0)
                A[i].p2 = pow2(num);
            if(num % 5 == 0)
                A[i].p5 = pow5(num);
        }
        makeTree(A, tree, 0, n - 1, 0);
        //for(i = 0; i < 2 * n - 1; i++)
            //printf("%d %d\n", tree[i].p2, tree[i].p5);
        while(Q--)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d %d %d", &l, &r, &x);
                X.p2 = X.p5 = 0;
                if(x % 2 == 0)
                    X.p2 = pow2(x);
                if(x % 5 == 0)
                    X.p5 = pow5(x);
                updateType1(tree, lazy, X, l - 1, r - 1, 0, n - 1, 0);
                //puts("Tree:");
                //for(i = 0; i < 2 * n - 1; i++)
                    //printf("%d %d\n", tree[i].p2, tree[i].p5);
                //puts("Lazy:");
                //for(i = 0; i < 2 * n - 1; i++)
                    //printf("%d %d\n", lazy[i].p2, lazy[i].p5);

            }
            else if(type == 2)
            {
                scanf("%d %d %d", &l, &r, &x);
                X.p2 = X.p5 = 0;
                if(x % 2 == 0)
                    X.p2 = pow2(x);
                if(x % 5 == 0)
                    X.p5 = pow5(x);
                updateType2(tree, lazy, X, l - 1, r - 1, 0, n - 1, 0);
                //puts("Tree:");
                //for(i = 0; i < 2 * n - 1; i++)
                    //printf("%d %d\n", tree[i].p2, tree[i].p5);
                //puts("Lazy:");
                //for(i = 0; i < 2 * n - 1; i++)
                    //printf("%d %d\n", lazy[i].p2, lazy[i].p5);
            }
            else
            {
                scanf("%d %d", &l, &r);
                X.p2 = X.p5 = 0;
                for(i = l - 1; i <= r - 1; i++)
                {
                    X.p2 += A[i].p2;
                    X.p5 += A[i].p5;
                }
                res += X.p2 > X.p5 ? X.p5 : X.p2;
            }
        }
        printf("%d\n", res);
        free(A);
        free(tree);
        free(lazy);
    }
    return 0;
}

int pow2(int n)
{
    int i, k = 1073741824, out = 0;
    for(i = 2; i <= k + 10; i *= 2)
    {
        if(n % i == 0)
            out++;
        else
        {
            return out;
        }
    }
    return out;
}

int pow5(int n)
{
    int i, k = 1220703125, out = 0;
    for(i = 5; i <= k + 10; i *= 5)
    {
        if(n % i == 0)
            out++;
        else
        {
            return out;
        }
    }
    return out;
}

int pow2_v2(int n)
{
    int i, res = 0;
    for(i = 2; ; i = 2 * i)
    {
        if(n / i == 0)
            return res;
        res += n / i;
    }
}
int pow5_v2(int n)
{
    int i, res = 0;
    for(i = 5; ; i = 5 * i)
    {
        if(n / i == 0)
            return res;
        res += n / i;
    }
}

void makeTree(Poseidon *A, Poseidon *Tree, int ini, int end, int node)
{
    if(ini == end)    
    {
        Tree[node].p2 = A[ini].p2;
        Tree[node].p5 = A[ini].p5;
        return;
    }
    else
    {
        int k = (ini + end) / 2;
        makeTree(A, Tree, ini, k, 2 * node + 1);
        makeTree(A, Tree, k + 1, end, 2 * node + 2);
        Tree[node].p2 = Tree[2 * node + 1].p2 + Tree[2 * node + 2].p2;
        Tree[node].p5 = Tree[2 * node + 1].p5 + Tree[2 * node + 2].p5;
        return;
    }
}

void updateType1(Poseidon *Tree, Poseidon *Lazy, Poseidon X, int l, int r, int st, int en, int node)
{
    if(en < l || r < st)
        return;
    else if(st >= l && en <= r)
    {
        if(st == en)
        {
            if(ck == 1)
            {
                Tree[node].p2 = pow2_v2(Lazy[node].r + 1) - pow2_v2(Lazy[node].l) + X.p2 + Lazy[node].p2;
                Tree[node].p5 = pow5_v2(Lazy[node].r + 1) - pow5_v2(Lazy[node].l) + X.p5 + Lazy[node].p5;
                Lazy[node].r = Lazy[node].l = Lazy[node].ck = Lazy[node].p2 = Lazy[node].p5 = 0;
            }
            else
            {
                Tree[node].p2 += Lazy[node].p2 + X.p2;
                Tree[node].p5 += Lazy[node].p5 + X.p5;
                Lazy[node].r = Lazy[node].l = Lazy[node].ck = Lazy[node].p2 = Lazy[node].p5 = 0;
            }
        }
        else
        {
            if(ck == 1)
            {
                Tree[node].p2 = pow2_v2(Lazy[node].r + 1) - pow2_v2(Lazy[node].l) + (en - st + 1) * Lazy[node].p2 + (en - st + 1) * X.p2;
                Tree[node].p5 = pow5_v2(Lazy[node].r + 1) - pow5_v2(Lazy[node].l) + (en - st + 1) * Lazy[node].p5 + (en - st + 1) * X.p5;
                Lazy[2 * node + 1].p2 = Lazy[node].p2;
                Lazy[2 * node + 1].p5 = Lazy[node].p5;
                Lazy[2 * node + 1].l = Lazy[node].l;
                Lazy[2 * node + 1].r = (Lazy[node].r + Lazy[node].l) / 2;
                Lazy[2 * node + 1].ck = Lazy[node].ck;
                Lazy[2 * node + 2].p2 = Lazy[node].p2;
                Lazy[2 * node + 2].p5 = Lazy[node].p5;
                Lazy[2 * node + 2].l = (Lazy[node].r + Lazy[node].l) / 2 + 1;
                Lazy[2 * node + 2].r = Lazy[node].r;
                Lazy[2 * node + 2].ck = Lazy[node].ck;
                Lazy[node].r = Lazy[node].l = Lazy[node].ck = Lazy[node].p2 = Lazy[node].p5 = 0;
            }
            else
            {
                Tree[node].p2 += (en - st + 1) * Lazy[node].p2 + (en - st + 1) * X.p2;
                Tree[node].p5 += (en - st + 1) * Lazy[node].p5 + (en - st + 1) * X.p5;
                Lazy[2 * node + 1].p2 = Lazy[node].p2;
                Lazy[2 * node + 1].p5 = Lazy[node].p5;
                Lazy[2 * node + 1].l = Lazy[node].l;
                Lazy[2 * node + 1].r = (Lazy[node].r + Lazy[node].l) / 2;
                Lazy[2 * node + 1].ck = Lazy[node].ck;
                Lazy[2 * node + 2].p2 = Lazy[node].p2;
                Lazy[2 * node + 2].p5 = Lazy[node].p5;
                Lazy[2 * node + 2].l = (Lazy[node].r + Lazy[node].l) / 2 + 1;
                Lazy[2 * node + 2].r = Lazy[node].r;
                Lazy[2 * node + 2].ck = Lazy[node].ck;
                Lazy[node].r = Lazy[node].l = Lazy[node].ck = Lazy[node].p2 = Lazy[node].p5 = 0;
            }
        }
    }
    else
    {
        int k = (l + r) / 2;
        if(ck == 1)
        {
            Tree[node].p2 = pow2_v2(Lazy[node].r + 1) - pow2_v2(Lazy[node].l) + (en - st + 1) * Lazy[node].p2 + (en - st + 1) * X.p2;
            Tree[node].p5 = pow5_v2(Lazy[node].r + 1) - pow5_v2(Lazy[node].l) + (en - st + 1) * Lazy[node].p5 + (en - st + 1) * X.p5;
            Lazy[2 * node + 1].p2 = Lazy[node].p2;
            Lazy[2 * node + 1].p5 = Lazy[node].p5;
            Lazy[2 * node + 1].l = Lazy[node].l;
            Lazy[2 * node + 1].r = (Lazy[node].r + Lazy[node].l) / 2;
            Lazy[2 * node + 1].ck = Lazy[node].ck;
            Lazy[2 * node + 2].p2 = Lazy[node].p2;
            Lazy[2 * node + 2].p5 = Lazy[node].p5;
            Lazy[2 * node + 2].l = (Lazy[node].r + Lazy[node].l) / 2 + 1;
            Lazy[2 * node + 2].r = Lazy[node].r;
            Lazy[2 * node + 2].ck = Lazy[node].ck;
            Lazy[node].r = Lazy[node].l = Lazy[node].ck = Lazy[node].p2 = Lazy[node].p5 = 0;
        }
        else
        {
            Tree[node].p2 += (en - st + 1) * Lazy[node].p2 + (en - st + 1) * X.p2;
            Tree[node].p5 += (en - st + 1) * Lazy[node].p5 + (en - st + 1) * X.p5;
            Lazy[2 * node + 1].p2 = Lazy[node].p2;
            Lazy[2 * node + 1].p5 = Lazy[node].p5;
            Lazy[2 * node + 1].l = Lazy[node].l;
            Lazy[2 * node + 1].r = (Lazy[node].r + Lazy[node].l) / 2;
            Lazy[2 * node + 1].ck = Lazy[node].ck;
            Lazy[2 * node + 2].p2 = Lazy[node].p2;
            Lazy[2 * node + 2].p5 = Lazy[node].p5;
            Lazy[2 * node + 2].l = (Lazy[node].r + Lazy[node].l) / 2 + 1;
            Lazy[2 * node + 2].r = Lazy[node].r;
            Lazy[2 * node + 2].ck = Lazy[node].ck;
            Lazy[node].r = Lazy[node].l = Lazy[node].ck = Lazy[node].p2 = Lazy[node].p5 = 0;
        }
        updateType1(Tree, Lazy, X, l, r, st, k, 2 * node + 1);
        updateType1(Tree, Lazy, X, l, r, k + 1, en, 2 * node + 2);
        Tree[node].p2 += Tree[2 * node + 1].p2;
        Tree[node].p5 += Tree[2 * node + 1].p5;
        Tree[node].p2 += Tree[2 * node + 2].p2;
        Tree[node].p5 += Tree[2 * node + 2].p5;
        return;
    }
}
