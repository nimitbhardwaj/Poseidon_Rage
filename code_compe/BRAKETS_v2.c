    #include<stdio.h>
    int main()
        {
                int t, bal, max, i;
                char c;
                scanf("%d", &t);
                c = getchar();
                while(t--)
                {
                            bal = max = 0;
                            while((c = getchar()) != '\n')
                            {
                                            if(c == '(')
                                                                    bal++;
                                                            else
                                                                                    bal--;
                                                                            max = bal > max? bal : max;
                                                                                        }
                                        for(i = 0; i < max; i++)
                                                            putchar('(');
                                                    for(i = 0; i < max; i++)
                                                                        putchar(')');
                                                                puts("");
                                                                        }
                        return 0;
                            }
