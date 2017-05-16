#include<stdio.h>
#include<string.h>
typedef struct message
{
  char c;
  int i;
  char st[10001];
}message;
int main()
{
  char str[10001];
  message msg;
  msg.i=0;
  int l, i, ch=0;
  fgets(str, 10001, stdin);
  l=strlen(str);
  for(i=0; i<l; i++)
  {
    if(str[i]=='(')
    {
      msg.i=0;
      continue;
    }
    if(str[i]==')')
      break;
    msg.st[msg.i]=str[i];
    msg.i++;
  }
  msg.st[msg.i]=0;
  puts(msg.st);
  return 0;
}
