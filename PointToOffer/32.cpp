
long long int Count(long long int n){
	long long int count = 0;//1�ĸ���
	long long int Factor = 1;//��ǰλ
	long long int LowerNum = 0;//��λ����
	long long int CurrNum = 0;//��ǰλ����
	long long int HigherNum = 0;//��λ����
	if(n <= 0){
		return 0;
	}
	while(n / Factor != 0){
		LowerNum = n - (n / Factor) * Factor;//��λ����
		CurrNum = (n / Factor) % 10;       //��ǰλ����		
		HigherNum = n / (Factor * 10);   //��λ����
        //���Ϊ0,����1�Ĵ����ɸ�λ����
		if(CurrNum == 0){                      
			count += HigherNum * Factor;	//����λ���� * ��ǰλ��
		}
		//���Ϊ1,����1�Ĵ����ɸ�λ�͵�λ����
		else if(CurrNum == 1){
			count += HigherNum * Factor + LowerNum + 1;//��λ���� * ��ǰλ�� + ��λ���� + 1
		}
		//�������1,����1�Ĵ����ɸ�λ����
		else{		
			count += (HigherNum + 1) * Factor;  //����λ����+1��* ��ǰλ��
		}
		Factor *= 10;//ǰ��һλ
	}
	return count;
}