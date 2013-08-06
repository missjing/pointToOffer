
long long int Count(long long int n){
	long long int count = 0;//1的个数
	long long int Factor = 1;//当前位
	long long int LowerNum = 0;//低位数字
	long long int CurrNum = 0;//当前位数字
	long long int HigherNum = 0;//高位数字
	if(n <= 0){
		return 0;
	}
	while(n / Factor != 0){
		LowerNum = n - (n / Factor) * Factor;//低位数字
		CurrNum = (n / Factor) % 10;       //当前位数字		
		HigherNum = n / (Factor * 10);   //高位数字
        //如果为0,出现1的次数由高位决定
		if(CurrNum == 0){                      
			count += HigherNum * Factor;	//等于位数字 * 当前位数
		}
		//如果为1,出现1的次数由高位和低位决定
		else if(CurrNum == 1){
			count += HigherNum * Factor + LowerNum + 1;//高位数字 * 当前位数 + 低位数字 + 1
		}
		//如果大于1,出现1的次数由高位决定
		else{		
			count += (HigherNum + 1) * Factor;  //（高位数字+1）* 当前位数
		}
		Factor *= 10;//前移一位
	}
	return count;
}