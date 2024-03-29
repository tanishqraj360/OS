#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct p
{
    int acum[100];
    int jp[100];

} st;

int main()
{
    int n, m, i, count = 0, j, pn[100], internalFragmentation = 0;
    int p[100], size[100];
    bool flag[100];
    printf("ENTER THE NO PROCESS AND MEMORY :\n ");
    scanf("%d%d", &n, &m);
    printf("ENTER THE SIZE OF PROCESS \n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("ENTER THE SIZE OF MEMORY PARTITION \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &size[i]);
        flag[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        int ic = 0, in = 0;
        for (j = 0; j < m; j++)
        {
            if (p[i] <= size[j] && flag[j] == 0)
            {
                int k;
                st.acum[in] = size[j];
                st.jp[in] = j;
                in++;
                ic++;
                for (k = ic - 1; k > 0; k--)
                {
                    if (st.acum[k] <= st.acum[k - 1])
                    {
                        int temp = st.acum[k];
                        st.acum[k] = st.acum[k - 1];
                        st.acum[k - 1] = temp;
                        temp = st.jp[k];
                        st.jp[k] = st.jp[k - 1];
                        st.jp[k - 1] = temp;
                    }
                }
            }
        }
        if (ic > 0)
        {
            j = st.jp[0];
            flag[j] = true;
            pn[j] = i;
            count++;
            internalFragmentation += (size[j] - p[i]);
        }
    }

    printf("NO OF PROCESS CAN ACCOMMODATE:%d\n\n", count);
    printf("MEMORY\tPROCESS\tINTERNAL FRAGMENTATION\n");
    for (i = 0; i < m; i++)
    {
        if (flag[i] == 1)
        {
            printf("%d <-->%d\t%d\n", size[i], p[pn[i]], size[i] - p[pn[i]]);
        }
        else
            printf("%d\tMEMORY NOT ALLOCATED\n", size[i]);
    }

    printf("Total Internal Fragmentation: %d\n", internalFragmentation);

    return 0;
}
