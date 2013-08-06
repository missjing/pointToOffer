//第一个只出现一次的字符
char firstNotRepeatingChar(char* pString)
{
	if(pString == NULL)
		return '\0';
	int hashTable[256];
	for(int i = 0; i < 256; ++i)
		hashTable[i] = 0;
	char *hashKey = pString;
	while(*hashKey != '\0')
	{
		hashTable[*hashKey]++;
		hashKey++;
	}
	hashKey = pString;
	while(*hashKey != '\0')
	{
		if(hashTable[*hashKey] == 1)
			return *hashKey;
		hashKey++;
	}
	return '\0';
}