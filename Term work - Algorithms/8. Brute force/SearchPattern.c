//Search a string pattern in a line of strings
#include <stdio.h>
#include <string.h>
#define MAX 100
  int bruteForce(char *source, char *find, int slen, int plen)
  {
      int j,k;
        for (int i=0;i<=slen-plen;i++)
        {
            for (j=0,k=i;(source[k]==find[j])&&(j<plen);j++,k++);
                if (j==plen)
                    return i;
        }
        return -1;
  }

  int main() {
        char original[MAX], key[MAX];
        int res;
        printf("Enter Search String:");
        gets(original);
        printf("Enter Pattern String:");
        gets(key);
        res = bruteForce(original, key, strlen(original), strlen(key));
        if (res == -1) {
                printf("Search pattern is not available\n");
        } else {
                printf("Search pattern available at the location %d\n", res);
        }
        return 0;
  }
