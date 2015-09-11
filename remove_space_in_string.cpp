#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
char* formatString(char *sourceString)
{
	if (sourceString == NULL)
		return NULL;
	int i = 0;
	int j = 0;
	char * ret = (char *)malloc(strlen(sourceString));
	memset(ret, 0, strlen(sourceString));
	for (; sourceString[i] != '\0'; i++)

	{
		if (sourceString[i] != ' ')break;
	}
	int prevSp = 0;
	while (1)
	{
		if (sourceString[i] != ' ' && sourceString[i] != '\0')
		{
			ret[j++] = sourceString[i++];

			prevSp = 0;
		}
		else if (sourceString[i] == ' ' && prevSp == 0)
		{
			prevSp = 1;
			ret[j++] = sourceString[i++];
		}
		else if (sourceString[i] == ' ' && prevSp == 1)
		{
			i++;
		}
		else if (sourceString[i] == '\0' && prevSp == 1)
		{
			ret[j] = '\0';
			break;
		}
		else if (sourceString[i] == '\0' && prevSp == 0)
			break;
	}	
		return ret;
}

int
main()
{
 char * a = "  String aewho awehog   aewhgoe e 353!";
 char * result = formatString(a);
 printf("result:%s\n", result);
 if (result)
	 free(result);
 system("pause");
 return 0;
}
